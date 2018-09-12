#!/bin/bash
# This script helps to follow changes in the process tree
# Precautions: make sure that no a.out process is running
# Usage: bash ex2.sh
gcc ex2.c
./a.out &
cat /dev/null > out 
watch -n 0.4 cat out &
for i in {3..0}; do
	pstree | grep a.out | grep -v grep | cut -f3- -d"|" > out
	echo -en "\n\n\n\n" >> out
	ps -ef | grep a.out | grep -v grep >> out 
	sleep 5
done
rm out
pkill watch
