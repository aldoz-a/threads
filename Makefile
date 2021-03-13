CC = gcc
CFLAGS = -I.
LDFLAGS = -lrt -pthread
OBJS = threads.o reader.o writer.o
DEPS = data.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: threads

threads: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# clean objects - $(RM) is rm -f by default
clean:
	$(RM) $(OBJS) threads
