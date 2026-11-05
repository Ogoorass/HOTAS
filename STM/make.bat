arm-none-eabi-objcopy.exe -O binary .\Debug\HOTAS.elf .\Debug\HOTAS.bin
st-flash write .\Debug\HOTAS.bin 0x08000000
