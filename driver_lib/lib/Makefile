
#This is the Makefile for parse.

RM = rm -f
CCFLAGS = -c
ARFLAG = -rc
CC = gcc
AR = ar
CCFLAGS+=-mcmodel=kernel

lib_OBJECTS = myalib.o
lib_SOURCE = myalib.c
LIB = libtest.a

libtest.a:$(lib_OBJECTS)
	$(AR) $(ARFLAG) -o $@ $^

$(lib_OBJECTS): $(lib_SOURCE)
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	$(RM) $(lib_OBJECTS)
	$(RM) $(LIB)



