#!/bin/bash

for i in $(seq 101 178); do
  rm -f my$i.asm.  # Delete the .asm file if it exists
  rm -f my$i.lst  # Delete the .lst file if it exists
  rm -f $i.lst
  rm -f $i.asm
  rm -f $i.dat
done