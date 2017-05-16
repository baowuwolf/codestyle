#!/usr/bin/env bash
#
set -o errexit
set -o pipefail
set -o nounset

readonly script_path="${BASH_SOURCE[0]}"
readonly script_dir="$( cd "$( dirname "${script_path}" )" && pwd )"

rm -rf "${script_dir}/Output"
cp -rf "${script_dir}/Input" "${script_dir}/Output"


CMD="/Users/wangchao9/Library/Application Support/Developer/Shared/Xcode/Plug-ins/UncrustifyPlugin.xcplugin/Contents/Resources/uncrustify"
# -c "./uncrustify.cfg" --no-backup "$1"

# Files=$(find "${script_dir}/Output" -name "*.[h,m.mm,c,cpp]")
CFGFILE="${script_dir}/uncrustify_rebase.cfg"

FILE="${script_dir}/CodeStyleDemo/CodeStyleDemo/test.c"
echo -n > "$FILE"
while read -r line;do
    echo -e "\n" >> "$FILE"
    echo "// ${line##/*Output/}" >> "$FILE"
    cat "${line}" >> "$FILE"
done <<< "$(find "${script_dir}/Output/c" -name "*.[h,m.mm,c,cpp]")"
"$CMD" -c "$CFGFILE" -l C --no-backup "$FILE"

FILE="${script_dir}/CodeStyleDemo/CodeStyleDemo/test.cpp"
echo -n > "$FILE"
while read -r line;do
    echo -e "\n" >> "$FILE"
    echo "// ${line##/*Output/}" >> "$FILE"
    cat "${line}" >> "$FILE"
done <<< "$(find "${script_dir}/Output/cpp" -name "*.[h,m.mm,c,cpp]")"
"$CMD" -c "$CFGFILE" -l CPP --no-backup "$FILE"

FILE="${script_dir}/CodeStyleDemo/CodeStyleDemo/test.m"
echo -n > "$FILE"
while read -r line;do
    echo -e "\n" >> "$FILE"
    echo "// ${line##/*Output/}" >> "$FILE"
    cat "${line}" >> "$FILE"
done <<< "$(find "${script_dir}/Output/oc" -name "*.[h,m.mm,c,cpp]")"
"$CMD" -c "$CFGFILE" -l OC --no-backup "$FILE"
