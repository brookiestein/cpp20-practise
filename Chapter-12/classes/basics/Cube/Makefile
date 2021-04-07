CC	:= g++
CFLAGS	:= -Wall -Wextra
SRC	= main.cpp cube.cpp
OBJ	= ${SRC:.cpp=.o}
RM	= rm -f
TARGET	= cube

all : ${OBJ}
	${CC} ${SRC} ${CFLAGS} -o ${TARGET}

clean :
	${RM} ${OBJ} ${TARGET}

test : all
	./${TARGET} 3.0

.PHONY : clean test
