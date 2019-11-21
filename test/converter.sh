#!/bin/bash
MIPS_CC='mips-linux-gnu-gcc'
MIPS_OBJCOPY='mips-linux-gnu-objcopy'
MIPS_OBJDUMP='mips-linux-gnu-objdump'
MIPS_CPPFLAGS='-W -Wall -O3 -fno-builtin -march=mips1 -mfp32'
MIPS_LDFLAGS='-nostdlib -Wl,-melf32btsmip -march=mips1 -nostartfiles -mno-check-zero-division -Wl,--gpsize=0 -static -Wl,-Bstatic -Wl,--build-id=none'

FILES='test/testcases/*'

rm test/bin/*
rm test/reassembled_testcases/*

for i in $FILES
do
  VAREXT=${i##*/}
  EXT=${VAREXT#*.}

  #for .s and .c files
  if [[ "$EXT" = "s" ]] || [[ "$EXT" = "c" ]]
  then
    VAR=${VAREXT%*.?}
    #echo $VAR
    $MIPS_CC $MIPS_CPPFLAGS -c "./test/testcases/${VAREXT}" -o "./test/temp/${VAR}.mips.o" #.s -> .o
    $MIPS_CC $MIPS_CPPFLAGS $MIPS_LDFLAGS -T ./test/linker.ld "./test/temp/${VAR}.mips.o" -o "./test/temp/${VAR}.mips.elf" #.o -> .elf
    $MIPS_OBJCOPY -O binary --only-section=.text "./test/temp/${VAR}.mips.elf" "./test/bin/${VAR}.mips.bin" # .elf -> .bin

    $MIPS_OBJDUMP -j .text -D "./test/temp/${VAR}.mips.elf" > "./test/reassembled_testcases/${VAR}.mips.s"
  fi

  #for .txt files
  if [[ "$EXT" = "txt" ]]
  then
    VAR=${VAREXT%*.txt}

    perl -ne 'print pack("B32", $_)' < "./test/testcases/${VAR}.txt" > "./test/bin/${VAR}.mips.bin"
  fi

done

rm ./test/temp/*
