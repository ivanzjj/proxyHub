
LIB_OBJS = acceptor.o server.o socket.o

TARGET = libtcp.a

all: $(TARGET)

libtcp.a: $(LIB_OBJS)
	$(AR) $@ $^	

AR = ar cru
CC = g++
CFLAGS = -std=c++11 -Wall -D_REENTRANT -D_GNU_SOURCE -D_XOPEN_SOURCE -fPIC -m64
# make rule
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@	

%.o : %.cc
	$(CC) $(CFLAGS) -c $< -o $@	

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@	
