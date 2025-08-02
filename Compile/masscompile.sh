for i in $(seq 1 9); do
  ./stage0 00${i}.dat my00${i}.lst my00${i}.asm
done
 for i in $(seq 10 52); do
  ./stage0 0${i}.dat my0${i}.lst my0${i}.asm
done