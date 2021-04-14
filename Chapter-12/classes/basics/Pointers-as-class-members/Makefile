CC	:= g++
CFLAGS	:= -std=c++2a -Wall -Wextra
SRC	= Main.cpp Box.cpp Truckload.cpp RandomBoxes.cpp
OBJ	= ${SRC:.cpp=.o}
TARGET	= truckload
RM	= rm -f

all : ${OBJ}
	${CC} ${SRC} ${CFLAGS} -o ${TARGET}

clean :
	${RM} ${OBJ} ${TARGET}

.PHONY : clean
