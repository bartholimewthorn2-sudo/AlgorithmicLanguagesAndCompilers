#!/bin/bash

for i in $(seq 1 9); do
  ./stage1 10${i}.dat my10${i}.lst my10${i}.asm
done
 for i in $(seq 10 78); do
  ./stage1 1${i}.dat my1${i}.lst my1${i}.asm.
done