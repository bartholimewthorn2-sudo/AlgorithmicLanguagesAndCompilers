#!/bin/bash

for i in $(seq 101 178); do
  if [ -f $i.asm ]; then  # Check if the .asm file exists
    diff $i.asm my$i.asm 
	echo "------------------------------------------------------"
  fi
done

for i in $(seq 101 178); do
  if [ -f $i.lst ]; then  # Check if the .asm file exists
    diff $i.lst my$i.lst 
	echo "-"
	echo "------------------------------------------------------"
	echo "-"
  fi
done