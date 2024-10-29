CC = zig cc
BIN = bin
LDFLAGS = -lraylib

all:${BIN}

build:
	${CC} -g ./src/game/*.c -o ./Laputa.yay ${LDFLAGS}

clean:
	rm -f ./Laputa.yay *~ core

bin: build
	./Laputa.yay


