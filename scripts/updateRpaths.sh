#!/bin/bash
#
# update the Rpaths to use $ORIGIN/../lib instead of an absolute path
#

directory="."
rpath="../lib"

usage()
{
    cat <<EOF
$0 [options]

-p {rpath}     Relative path to set RPATH (default:  $rpath)
-d {directory} Directory where the binaries are located (default: $directory)

-h             This message

Updates the RPATH of the binaries with the given relative path
EOF

exit 1
}

while getopts "d:p:h" arg; do
    case $arg in
	d)
	    directory=$OPTARG
	    ;;
	p)
	    rpath=$OPTARG
	    ;;
	h)
	    usage
	;;
	*)
	    usage
	    ;;
    esac
done

for file in "$directory"/*; do
  rpathVal=$(objdump -p "$file" |grep RPATH)
  if [ -n "$rpathVal" ]; then
      echo "$file:  $rpathVal"
      chrpath -r "\$ORIGIN/$rpath" "$file"
  fi
done
