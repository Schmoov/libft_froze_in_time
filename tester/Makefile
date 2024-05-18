CC := gcc
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := src/
SRCS := $(wildcard $(SRC_DIR)*.c)

BIN_DIR := .bin/
OBJS := $(patsubst $(SRC_DIR)%.c, $(BIN_DIR)%.o, $(SRCS))

TSTS := $(patsubst $(BIN_DIR)%.o, %, $(OBJS))
TST_DIR := tests/

CRIT := -L criterion -lcriterion
CRIT_ENV := LD_LIBRARY_PATH=criterion

ASAN := -fsanitize=address
LOG_DIR := .logs/
ASAN_ENV := ASAN_OPTIONS=log_path=$(LOG_DIR):abort_on_error=1:allocator_may_return_null=1

###############################################################################

all: test

test: $(OBJS) $(TSTS)

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

%.test: $(BIN_DIR)%.test.o
	@ mkdir -p $(TST_DIR)
	@ mkdir -p $(LOG_DIR)
	$(CC) $(CFLAGS) $< libft.a $(CRIT) -lbsd -o $(TST_DIR)$@
	$(CRIT_ENV) ./$(TST_DIR)$@

%.memtest: $(BIN_DIR)%.memtest.o
	$(CC) $(CFLAGS) $(ASAN) $< libft.a $(CRIT) -lbsd -o $(TST_DIR)$@
	$(ASAN_ENV) $(CRIT_ENV) ./$(TST_DIR)$@

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(LOG_DIR)

fclean: clean
	rm -rf $(TST_DIR)

re: fclean all

.PHONY: all test clean fclean re
