arm-none-eabi-objcopy.exe -O binary .\Debug\Throttle.elf .\Debug\Throttle.bin
st-flash write .\Debug\Throttle.bin 0x08000000
