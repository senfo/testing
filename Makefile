target = main
sources = main.c math2.c
test_sources = test_math2.c math2.c
CC = gcc
CFLAGS = -Wall -g

# C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for linking the object files into the executable file.
$(target): $(sources:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@

test: $(test_sources:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@ -g3 -lcunit
	./test

debug:
	$(MAKE) CFLAGS="$(CFLAGS) -g3"

clean:
	rm -f *.o $(target)

# The default target is to compile the executable file.
all: $(target)

