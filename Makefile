# 'make'        build executable file 'exe'
# 'make clean'  removes all .o and executable files
#

USE_C = 0

ifeq ($(USE_C), 1)
CC = gcc-12
SRCS = $(wildcard ./sources/*.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -O3 -fPIC -g
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
else
CC = g++-12
SRCS = $(wildcard ./sources/*.cpp)
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Werror -O3 -fPIC -std=c++20 -g
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
endif
# define any directories containing header files other than /usr/include
#
INCLUDES = -I./headers

LFLAGS := -L./libs

# This should generate a shared object
# Uncomment -shared for shared libraries
LDFLAGS := #-shared

LIBS := -lsqlite3

# define the executable file
MAIN := db_manager

.PHONY: depend clean clean_all

all:    $(MAIN)
	@echo $(MAIN) has been compiled

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

clean:
	$(RM) ./sources/*.o *~ $(MAIN)


