NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror 

OBJ_DIR := .bin/

SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c
SRCS_BONUS := $(wildcard *_bonus.c)

INCS := libft.h

OBJS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))
OBJS_BONUS := $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS_BONUS))

###############################################################################

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^ $(INCS)

$(OBJ_DIR)%.o: %.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^ $(INCS)

print-%  : ; @echo $* = $($*)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re rebonus
