#!/bin/bash

for filename in /strg/os_labs/week_10/*; do
	for entry in $(basename $filename); do
		if (( $(stat -c "%h" $entry) > 1 )); then 
			echo $entry
			read hanoi <<< $(cut -f1 -d' ' <<< $(ls -i $entry))
			find /strg/os_labs/ -inum $hanoi
			echo
		fi
	done
done
