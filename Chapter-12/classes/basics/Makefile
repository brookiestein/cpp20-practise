CC	:= g++
CFLAGS	:= -Wall -Wextra
SRC	= main.cpp Box.cpp
OBJ	= ${SRC:.cpp=.o}
RM	= rm -f
TARGET	= classes

all : ${OBJ}
	${CC} ${SRC} ${CFLAGS} -o ${TARGET}

clean :
	${RM} ${OBJ} ${TARGET}

test : all
	./${TARGET} 2.0 3.0 4.0
