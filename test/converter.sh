#!/bin/bash
MIPS_CC='mips-linux-gnu-gcc'
MIPS_OBJCOPY='mips-linux-gnu-objcopy'
MIPS_OBJDUMP='mips-linux-gnu-objdump'
MIPS_CPPFLAGS='-W -Wall -O3 -fno-builtin -march=mips1 -mfp32'
MIPS_LDFLAGS='-nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none'

FILES='test/testcases/*.s'

rm ./test/bin/*
rm ./test/reassembled_testcases/*

for i in $FILES
do
  VAR=${i%*.s}
  VAR=${VAR##*/}

  $MIPS_CC $MIPS_CPPFLAGS -c "./test/testcases/${VAR}.s" -o "./test/temp/${VAR}.mips.o" #.s -> .o
  $MIPS_CC $MIPS_CPPFLAGS $MIPS_LDFLAGS -T ./test/linker.ld "./test/temp/${VAR}.mips.o" -o "./test/temp/${VAR}.mips.elf" #.o -> .elf
  $MIPS_OBJCOPY -O binary --only-section=.text "./test/temp/${VAR}.mips.elf" "./test/bin/${VAR}.mips.bin" # .elf -> .bin

  $MIPS_OBJDUMP -j .text -D "./test/temp/${VAR}.mips.elf" > "./test/reassembled_testcases/${VAR}.mips.s"
done

rm ./test/temp/*
