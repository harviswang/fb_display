#
# Linux Frame Buffer Device Configuration
#

#CC =		arm-iwmmxt-linux-gnueabi-gcc -Wall -O2 -I.
CC =		mips-linux-gnu-gcc -Wall -O2 
#CC =		arm-linux-gcc -Wall -O2 -I.
RM =		rm -f

All:		test

test:	fb_display.o test.o

test.o:		test.c
fb_display.o:	fb_display.c 

.PHONY:clean
clean:
		$(RM) *.o test
