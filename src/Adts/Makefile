CC = gcc
CFLAGS = -Wall
LDFLAGS =

# List of object files
OBJS = dynArray.o testDynArray.o testUtils.o

# The main target
all: testDynArray

# Rule to build the executable
testDynArray: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependencies
testDynArray.o: dynarray.h Adts/testutils.h Adts/testdynarray.c
testUtils.o: testutils.h Adts/dynarray.h Adts/testutils.c
dynArray.o: dynarray.h Adts/dynarray.c
stduentDatabase.o: dynarray.h Adts/studentDatabase.c

# Cleanup rule
clean:
	rm -f $(OBJS) testDynArray

.PHONY: all clean