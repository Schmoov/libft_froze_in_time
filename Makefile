NAME := ft_ctype.a

SRC_DIR := src/
INC_DIR := include/
OBJ_DIR := bin/
TST_DIR := tests/

CC := gcc
CFLAGS := -Wall -Wextra -Werror -pedantic

SRC := $(wildcard $(SRC_DIR)**/*.c)

OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))
OBJ_PATH := $(sort $(dir $(OBJ)))

HEADER := $(wildcard $(INC_DIR)*.h)

TEST := $(wildcard $(TST_DIR)*.c)
TEST_NAME := $(basename $(notdir $(TEST)))

###############################################################################

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^ $(HEADER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

%.test: $(TST_DIR)%.test.c
	$(CC) $(CFLAGS) $< $(NAME) -lcriterion -o $@
	./$@

test: all $(TEST_NAME)

tclean:
	rm -f $(TEST_NAME)

clean: tclean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test tclean clean fclean re
