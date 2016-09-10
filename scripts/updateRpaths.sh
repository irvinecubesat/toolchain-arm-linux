#!/bin/bash
#
# update the Rpaths to use $ORIGIN/../lib instead of an absolute path
#
for file in *; do
  rpathVal=$(objdump -p $file |grep RPATH)
  if [ -n "$rpathVal" ]; then
      echo $file:  $rpathVal
      chrpath -r "\$ORIGIN/../lib" $file
  fi
done
