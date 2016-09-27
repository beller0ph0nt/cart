CC = $(CROSS_COMPILER)gcc

INCLUDE_DIR = -I$(abspath ./include)

export CC
export INCLUDE_DIR

.PHONY: all clear

all:
	$(MAKE) -C src
clear:
	$(MAKE) -C src clear