#!/bin/bash

for filename in /strg/os_labs/week_10/*; do
	for entry in $(basename $filename); do
		if (( $(stat -c "%h" $entry) > 1 )); then 
			echo $entry
			set -- $(ls -i $entry) # puts file name and its inode into positional args (place 1 and 2)
			find /strg/os_labs/ -inum $1
			echo
		fi
	done
done
