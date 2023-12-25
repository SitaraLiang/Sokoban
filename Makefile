SRC_DIR := src
INCLUDE_DIR := lib
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, %.o,$(SRCS))
CC = gcc
CFLAGS = -g -Wall
DOCGEN = Doxygen
LDFLAGS = -lncurses
EXEC = main

all: $(EXEC) archive doc

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: $(SRC_DIR)/%.c 
	$(CC) -c $(CFLAGS) $< -o $@ -I$(INCLUDE_DIR) 

archive:
	tar cfJ archive.tar.xz $(SRC_DIR) $(INCLUDE_DIR) $(OBJ_DIR) Doxyfile LICENSE 

doc: 
	$(DOCGEN) 

clean :
	rm -rf *.o $(EXEC) doc *.tar.xz archive
