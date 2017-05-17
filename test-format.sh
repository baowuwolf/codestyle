#!/usr/bin/env bash
#
set -o errexit
set -o pipefail
set -o nounset

readonly script_path="${BASH_SOURCE[0]}"
readonly script_dir="$( cd "$( dirname "${script_path}" )" && pwd )"

CMD="$HOME/Library/Application Support/Developer/Shared/Xcode/Plug-ins/UncrustifyPlugin.xcplugin/Contents/Resources/uncrustify"
SOURCE="$1"
TARGET="$2"

if [[ -z $SOURCE ]]; then
    exit -1;
fi

if [[ -z $TARGET ]]; then
    TARGET="${script_dir}/Output"
fi


rm -rf "${TARGET}"
cp -rf "${SOURCE}" "${TARGET}"

FILES="$(find "${TARGET}" -name "*.[h,hpp,pch,c,cpp,m,mm]" -not -path "./3rd*" -not -path "./lib*" -not -path "./NA*" -not -path "./sharepods*" -not -path "**.framework**" -not -path "**Lib/*" -not -path "**Pods/*")"

while read -r line;do
    "$CMD" -c "${script_dir}/uncrustify_oc.cfg" -l OC --no-backup "$line"
done <<< "$FILES"