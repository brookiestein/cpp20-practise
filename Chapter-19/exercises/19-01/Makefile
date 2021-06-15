CC := g++
TARGET = ex19-01
CFLAGS := -g -o ${TARGET}
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
RM = rm -f
LETTER := M

all : ${OBJ}
	${CC} ${SRC} ${CFLAGS}

clean :
	${RM} ${OBJ} ${TARGET}

test : all
	./${TARGET} ${LETTER}
