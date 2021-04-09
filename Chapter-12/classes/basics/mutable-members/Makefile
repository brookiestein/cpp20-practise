CC	:= g++
CFLAGS	:= -Wall -Wextra
SRC	= main.cpp
OBJ	= ${SRC:.cpp=.o}
RM	= rm -f
TARGET	= mutable

all : ${OBJ}
	${CC} ${SRC} ${CFLAGS} -o ${TARGET}

clean :
	${RM} ${OBJ} ${TARGET}

test : all
	./${TARGET} "Brayan" 19

.PHONY : clean test
