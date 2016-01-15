#
#
# Sample Makefile for Assignment 2
#

CFLAGS = -g -Wall -Werror -O2
CC = gcc

PROGRAM = mybash
CFILES = parser.c mybash.c
HFILE = parser.h


##################################################
#
# You shouldn't need to change anything else
#
##################################################


# compute the OFILES
OFILES = ${CFILES:.cc=.o}

# all of the .o files that the program needs
OBJECTS = ${OFILES}


# How to make the whole program
${PROGRAM} : ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${PROGRAM}

#
# File dependencies
#
${OFILES}: ${HFILE} parser.h

clean:
	/bin/rm -f *.o ${PROGRAM} *~

