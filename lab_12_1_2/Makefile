.PHONY : all dl objects libdir objdir clean

SRC_DIR := ./src
INC_DIR := ./inc
LIB_DIR := ./lib
OUT_DIR := ./out

CC := gcc
CFLAGS := -std=c99 -I$(INC_DIR)/*.h -Wall -Werror -fPIC

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

DYNAMICLIB := libiu7.so

all: objects dl

dl: objects libdir
	@$(CC) -shared -o $(LIB_DIR)/$(DYNAMICLIB) $(OUT_DIR)/*lib.o

objects: $(OBJS)

libdir:
	@mkdir -p $(LIB_DIR)

objdir:
	@mkdir -p $(OUT_DIR)

${OUT_DIR}/%.o: ${SRC_DIR}/%.c objdir
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) ${OUT_DIR}/*
	@rm -rf $(OUT_DIR) $(LIB_DIR)

