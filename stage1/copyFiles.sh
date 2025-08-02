#!/bin/bash

for i in $(seq 101 178); do
  cp /usr/local/4301/data/stage1/$i.lst .
  cp /usr/local/4301/data/stage1/$i.dat .
  cp /usr/local/4301/data/stage1/$i.asm .
done