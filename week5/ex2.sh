#!/bin/bash

while true; do
	if ln input input.lock; then
		read -r number < <(cat input | tail -n 1)
		echo $(($number + 1)) >> input
		rm input.lock
		sleep 1
	fi
done
