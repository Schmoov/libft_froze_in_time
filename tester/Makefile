CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := src/
SRCS := $(wildcard $(SRC_DIR)*.c)

BIN_DIR := .bin/
OBJS := $(patsubst $(SRC_DIR)%.c, $(BIN_DIR)%.o, $(SRCS))

TSTS := $(patsubst $(BIN_DIR)%.o, %, $(OBJS))

CRIT := ~/lib/Criterion/libcriterion.so
CRIT_ENV := LD_LIBRARY_PATH=~/lib/Criterion

ASAN := -fsanitize=address
ASAN_ENV := ASAN_OPTIONS=log_path=bintest/log:abort_on_error=1:allocator_may_return_null=1

###############################################################################

all: test

test: $(TSTS) 

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

%.test: $(BIN_DIR)%.test.o
	$(CC) $(CFLAGS) $< libft.a -lbsd $(CRIT) -o $@
	$(CRIT_ENV) ./$@

%.memtest: $(BIN_DIR)%.memtest.o
	$(CC) $(CFLAGS) $< $(NAME) libft.a -lbsd $(CRIT) -fsanitize=address -o $@
	$(ASAN_ENV) $(CRIT_ENV) ./$@

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(BIN_DIR)

fclean: clean
	rm *.test
	rm *.memtest

re: fclean all

.PHONY: all test clean fclean re
