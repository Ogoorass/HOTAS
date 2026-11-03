arm-none-eabi-objcopy.exe -O binary .\Debug\Joystick.elf .\Debug\Joystick.bin
st-flash write .\Debug\Joystick.bin 0x08000000
