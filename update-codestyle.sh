#!/usr/bin/env bash
# update-codestyle folder
set -o errexit
set -o pipefail
set -o nounset

readonly script_path="${BASH_SOURCE[0]}"
readonly script_dir="$( cd "$( dirname "${script_path}" )" && pwd )"

CMD="$HOME/Library/Application Support/Developer/Shared/Xcode/Plug-ins/UncrustifyPlugin.xcplugin/Contents/Resources/uncrustify"
SOURCE="$1"
TARGET="$SOURCE"

if [[ -z $SOURCE ]]; then
    exit -1;
fi
#    -name "*.[h,hpp,pch,c,cpp,m,mm]" \
FILES="$(find "${TARGET}" \
    \(  -name "*.h" \
    -or -name "*.hpp" \
    -or -name "*.pch" \
    -or -name "*.c" \
    -or -name "*.cpp"\
    -or -name "*.m"\
    -or -name "*.mm"\
    \) \
    -not -path "./3rd*" \
    -not -path "./lib*" \
    -not -path "./NA*" \
    -not -path "./sharepods*" \
    -not -path "**.framework**" \
    -not -path "**Lib/*" \
    -not -path "**Pods/*" \
    -not -path "*/**/Vendors/*"\
    -not -path "*/**/Vendor/*" \
    -not -path "*/**/ImagePicker/*"\
    )"

while read -r line;do
    "$CMD" -c "${script_dir}/uncrustify.cfg" -l OC --no-backup "$line"
done <<< "$FILES"