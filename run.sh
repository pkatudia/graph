#!/bin/bash

make cleanall;
make;
chmod 777 *.o;


for f in *.o; do
  echo "***************** Running $f *****************";
  bash -c "$f"
  echo ""
done



if ls ./core.* 1> /dev/null 2>&1; then
  echo "------------- FAIL ----------------"
else
  echo "------------- ALL PASS ---------------"
  make clean;
fi

echo "Total Line of source code" 
find . -name '*.c' | xargs wc -l

echo "Total Line of headerfile code"
find . -name '*.h' | xargs wc -l

exit 0
