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
testDynArray.o: dynArray.h testutils.h testDynArray.c
testUtils.o: testutils.h dynArray.h testUtils.c
dynArray.o: dynArray.h dynArray.c
stduentDatabase.o: dynArray.h studentDatabase.c

# Cleanup rule
clean:
	rm -f $(OBJS) testDynArray

.PHONY: all clean