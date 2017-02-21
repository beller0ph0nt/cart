CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

INCLUDE_DIR = -I$(abspath ./include)

CFLAGS =
CFLAGS += -Wall
CFLAGS += -DDEBUG
#CFLAGS += -DPROFILER
#CFLAGS += -DASSERTION

SERVER_OBJ =
SERVER_OBJ += server.o
SERVER_OBJ += time.o
SERVER_OBJ += socket.o
SERVER_OBJ += stdlib.o
SERVER_OBJ += unistd.o

CLIENT_OBJ =
CLIENT_OBJ += client.o
CLIENT_OBJ += config.o
CLIENT_OBJ += time.o
CLIENT_OBJ += stdio.o
CLIENT_OBJ += netdb.o
CLIENT_OBJ += socket.o
CLIENT_OBJ += stdlib.o
CLIENT_OBJ += unistd.o

VPATH = src/gini:src/wrap

.PHONY: all clear

all: ginisrv ginicli

ginisrv: $(SERVER_OBJ)
	$(CC) -o $@ $^ $(LIB) $(LIBPATH)
ginicli: $(CLIENT_OBJ)
	$(CC) -o $@ $^ $(LIB) $(LIBPATH)
%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) -o $@ $^
clear:
	rm -f *.o ginisrv ginicli