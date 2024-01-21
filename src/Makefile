CC ?= gcc
CFLAGS ?= -Wall
BUILD ?= compile

all: $(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o core

compile: dynArray.o testDynArray.o testUtils.o

# CFLAGS = extra rules (flags) you assign to the C compiler
# CC = what compiler to use
# n.o is made automatically from n.c with a recipe of the form
  #‘$(CC) $(CPPFLAGS) $(CFLAGS) -c’.

dynArray.o: dynArray.h
	# $(CC) $(CFLAGS) -c dynArray.c

testDynArray.o: dynArray.h testutils.h
	# $(CC) $(CFLAGS) -c testDynArray.c

testUtils.o: testutils.h dynArray.h
	# $(CC) $(CFLAGS) -c testUtils.c
