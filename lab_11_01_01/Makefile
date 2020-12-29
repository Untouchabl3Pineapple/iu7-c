.PHONY : all unit run clean objdir

SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out
UTESTS_DIR := ./unit_tests
FTESTS_DIR := ./func_tests

CC := gcc
CFLAGS := -std=c99 -I$(INC_DIR) -Wall -Werror -pedantic

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

U_CFLAGS := -lcheck -lpthread -lm -lrt
U_SRCS := $(wildcard $(UTESTS_DIR)/*.c)
U_OBJS := $(U_SRCS:$(UTESTS_DIR)/%.c=$(OUT_DIR)/%.o)

EXEC := app.exe
UEXEC := unit_tests.exe

all: $(EXEC) $(UEXEC)

unit: $(UEXEC)

$(EXEC): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(UEXEC) : $(U_OBJS) $(filter-out $(OUT_DIR)/main.o, $(OBJS))
	@$(CC) $(CFLAGS) -o $@ $^ $(U_CFLAGS)

objdir:
	@mkdir -p $(OUT_DIR)

${OUT_DIR}/%.o : ${SRC_DIR}/%.c objdir
	@$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/check_%.o : $(UTESTS_DIR)/check_%.c objdir
	@$(CC) $(CFLAGS) -o $@ -c $<

$(INC_DIR)/%.h:

clean:
	@$(RM) $(EXEC) $(UEXEC) ${OUT_DIR}/*
	@rm -rf $(OUT_DIR)
