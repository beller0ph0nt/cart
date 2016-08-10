SERVER_OBJ = server.o \
             wrap_socket.o \
             wrap_stdlib.o

CLIENT_OBJ = client.o \
             wrap_netdb.o \
             wrap_socket.o \
             wrap_stdlib.o \
             config.o

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

.PHONY: all

all: ginisrv ginicln

ginisrv: $(SERVER_OBJ)
	$(CC) -o $@ $^ $(LIB) $(LIBPATH)
ginicln: $(CLIENT_OBJ)
	$(CC) -o $@ $^ $(LIB) $(LIBPATH)

server.o: server.c
	$(CC) -c -o $@ $^
client.o: client.c
	$(CC) -c -o $@ $^

config.o: config.c
	$(CC) -c -o $@ $^

wrap_netdb.o: wrap_netdb.c
	$(CC) -c -o $@ $^
wrap_socket.o: wrap_socket.c
	$(CC) -c -o $@ $^
wrap_stdlib.o: wrap_stdlib.c
	$(CC) -c -o $@ $^

clear:
	rm -f *.o ginisrv ginicln