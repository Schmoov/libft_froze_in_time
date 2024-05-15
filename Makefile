NAME := my_libft.a

SRC_DIR := src/
INC_DIR := include/
OBJ_DIR := bin/
TST_DIR := tests/
TST_BIN := bintest/

CRIT := libcriterion.so
CRIT_ENV := LD_LIBRARY_PATH=~/lib/

CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic
ASAN := -fsanitize=address
ASAN_ENV := ASAN_OPTIONS=log_path=bintest/log:abort_on_error=1:allocator_may_return_null=1

SRC := $(wildcard $(SRC_DIR)*/*.c)

OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
OBJ_PATH := $(sort $(dir $(OBJ)))

HEADER := $(wildcard $(INC_DIR)*.h)

TEST := $(wildcard $(TST_DIR)*/*.test.c)
MTEST := $(wildcard $(TST_DIR)*/*.memtest.c)
TEST_NAME := $(patsubst $(TST_DIR)%.test.c, $(TST_BIN)%.test, $(TEST))
MTEST_NAME := $(patsubst $(TST_DIR)%.memtest.c, $(TST_BIN)%.memtest, $(MTEST))

###############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^ $(HEADER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(TST_BIN)%.test: $(TST_DIR)%.test.c
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< $(NAME) -lbsd $(CRIT) -o $@
	$(CRIT_ENV) ./$@

$(TST_BIN)%.memtest: $(TST_DIR)%.memtest.c
	@ mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< $(NAME) -lbsd $(CRIT) -fsanitize=address -o $@
	$(ASAN_ENV) $(CRIT_ENV) ./$@

test: all $(TEST_NAME) $(MTEST_NAME)

print-%  : ; @echo $* = $($*)

tclean:
	rm -rf $(TST_BIN)

clean: tclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test tclean clean fclean re
