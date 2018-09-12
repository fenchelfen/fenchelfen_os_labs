#!/bin/bash
# Run with bash, not sh
gcc ex1.c
for i in {10..1}; do 
	./a.out      
	sleep 1 
done

