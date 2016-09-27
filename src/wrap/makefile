OBJ = netdb.o
OBJ += socket.o
OBJ += stdio.o
OBJ += stdlib.o
OBJ += time.o
OBJ += unistd.o

.PHONY: all clear

all: $(OBJ)
	
%.o: %.c
	$(CC) -c $(INCLUDE_DIR) -o $@ $<
clear:
	rm -f *.o