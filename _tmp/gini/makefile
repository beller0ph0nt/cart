SERVER_OBJ = server.o \
             wrap_time.o \
             wrap_socket.o \
             wrap_stdlib.o \
             wrap_unistd.o

CLIENT_OBJ = client.o \
             config.o \
             wrap_time.o \
             wrap_stdio.o \
             wrap_netdb.o \
             wrap_socket.o \
             wrap_stdlib.o \
             wrap_unistd.o

CFLAGS = -Wall \
         -DDEBUG \
         -DPROFILER \
         -DASSERTION

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

.PHONY: all

all: ginisrv ginicli

ginisrv: $(SERVER_OBJ)
	$(CC) -o $@ $^ $(LIB) $(LIBPATH)
ginicli: $(CLIENT_OBJ)
	$(CC) -o $@ $^ $(LIB) $(LIBPATH)

server.o: server.c
	$(CC) -c $(CFLAGS) -o $@ $^
client.o: client.c
	$(CC) -c $(CFLAGS) -o $@ $^

config.o: config.c
	$(CC) -c $(CFLAGS) -o $@ $^

wrap_time.o: wrap_time.c
	$(CC) -c $(CFLAGS) -o $@ $^
wrap_stdio.o: wrap_stdio.c
	$(CC) -c $(CFLAGS) -o $@ $^
wrap_netdb.o: wrap_netdb.c
	$(CC) -c $(CFLAGS) -o $@ $^
wrap_socket.o: wrap_socket.c
	$(CC) -c $(CFLAGS) -o $@ $^
wrap_stdlib.o: wrap_stdlib.c
	$(CC) -c $(CFLAGS) -o $@ $^
wrap_unistd.o: wrap_unistd.c
	$(CC) -c $(CFLAGS) -o $@ $^

clear:
	rm -f *.o ginisrv ginicli