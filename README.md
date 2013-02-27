This project provides a template for getting up and running with GCC and the STM32F4Discovery kit.


It is also compatible with Eclipse. Set up Eclipse as explained here:
http://embeddedprogrammer.blogspot.com/2012/09/stm32f4discovery-development-with-gcc.html

Just disable Makefile generation in the Eclipse project (since we already have a Makefile).


To compile the project:
	make
or for parallel compilation:
	make -j4


To load the program into the STM32F4:
	make program


Debugging is accomplished with openocd, which supports the stm32f4discovery natively.
Run this to start openocd:
	openocd-0.6.1.exe -f board/stm32f4discovery.cfg

And then start GDB:
	arm-none-eabi-gdb build/main.elf

And in GDB:
	target remote :3333
	monitor halt
	load
	monitor reset init

Set some breakpoints, etc, and then run the program:
	continue




NOTE: On Windows, do not install libusb drivers for the ST-Link. Use ST's native drivers. Openocd works just fine with the native drivers.
NOTE: On Windows, run arm-none-eabi-gdb from a normal Command Prompt (not within cygwin), otherwise Ctrl+C won't work (it'll close gdb instead of sending SIGINT to the program being debugged).
