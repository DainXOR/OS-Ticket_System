CC = gcc
CFLAGS = -std=c11

SRC_DIR = src
OBJ_DIR = build
TARGET = ticket_system

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/ticket/ticket.c \
	$(SRC_DIR)/utils/utils.c \

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean
