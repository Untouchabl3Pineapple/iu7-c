.PHONY : all sl dl slrun dlurun dlirun objects libdir objdir clean

SRC_DIR := ./src
INC_DIR := ./inc
LIB_DIR := ./lib
OUT_DIR := ./out
UTESTS_DIR := ./unit_tests
FTESTS_DIR := ./func_tests

CC := gcc
CFLAGS := -std=c99 -I$(INC_DIR)/*.h -Wall -Werror

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

U_CFLAGS := -lcheck -lpthread
U_SRCS := $(wildcard $(UTESTS_DIR)/*.c)
U_OBJS := $(U_SRCS:$(UTESTS_DIR)/%.c=$(OUT_DIR)/%.o)

STEXEC := st_app.exe
DLUEXEC := dl_unit_tests.exe
DLIEXEC := dli_app.exe

STATICLIB := libiu7.a
DYNAMICLIB := libiu7.so

all: slrun dlurun dlirun

sl: objects libdir
	@ar cr $(LIB_DIR)/$(STATICLIB) $(OUT_DIR)/*_lib.o

slrun: sl
	@$(CC) $(CFLAGS) $(OUT_DIR)/main.o $(LIB_DIR)/*.a -o $(STEXEC)

dl:	objects libdir
	@$(CC) -shared -o $(LIB_DIR)/$(DYNAMICLIB) $(OUT_DIR)/*_lib.o

dlurun: uobjects dl
	@$(CC) $(CFLAGS) $(U_CFLAGS) $(OUT_DIR)/check_*.o $(LIB_DIR)/*.so -o $(DLUEXEC)

dlirun: dl
	@$(CC) $(CFLAGS) $(OUT_DIR)/dyn_ins_main.o $(OUT_DIR)/load_dynlib.o -ldl -o $(DLIEXEC)

objects: $(OBJS)

uobjects: $(U_OBJS)

libdir:
	@mkdir -p $(LIB_DIR)

objdir:
	@mkdir -p $(OUT_DIR)

${OUT_DIR}/%.o: ${SRC_DIR}/%.c objdir
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OUT_DIR)/check_%.o : $(UTESTS_DIR)/check_%.c objdir
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(STEXEC) $(DLUEXEC) $(DLIEXEC) ${OUT_DIR}/*
	@rm -rf $(OUT_DIR) $(LIB_DIR)

