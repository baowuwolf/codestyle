#!/usr/bin/env bash
#
set -o errexit
set -o pipefail
set -o nounset

readonly script_path="${BASH_SOURCE[0]}"
readonly script_dir="$( cd "$( dirname "${script_path}" )" && pwd )"

CMD="/Users/wangchao9/Library/Application Support/Developer/Shared/Xcode/Plug-ins/UncrustifyPlugin.xcplugin/Contents/Resources/uncrustify"

rm -rf "${script_dir}/Output"
cp -rf "${1}" "${script_dir}/Output"

FILES="$(find "${script_dir}/Output" -name "*.[h,hpp,pch,c,cpp,m,mm]" -not -path "./3rd*" -not -path "./lib*" -not -path "./NA*" -not -path "./sharepods*" -not -path "**.framework**" -not -path "**Lib/*" -not -path "**Pods/*")"

while read -r line;do
    "$CMD" -c "${script_dir}/uncrustify_rebase.cfg" -l OC --no-backup "$line"
done <<< "$FILES"