CC = gcc

CFLAGS = -Wall -Wextra 

SRC = $(wildcard *.c)
BIN = $(patsubst %.c,%,$(SRC))

all: $(BIN)

clean:
	$(RM) $(BIN)
	$(RM) a.out



