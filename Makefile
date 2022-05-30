NAME := pipex
NAME_B := pipex_bonus
LIBFT_NAME = libft.a

SRCS =  ./sources/pipex.c  \
		./sources/utils.c

SRCS_B = ./sources/pipex_bonus.c  \
		./sources/utils_bonus.c	\
		./sources/process_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./headers/
EXE_DIR = ./

CC := cc
GCC := gcc
CFLAGS := -Wall -Werror -Wextra
MV := mv -f
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(CC) -o $(NAME)  $^ -I $(INC_DIR)
	$(RM) $(NAME_B)

bonus: $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS_B)
	$(CC) -o $(NAME_B)  $^ -I $(INC_DIR)
	$(RM) $(NAME)

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME_B)

re: clean all

.PHONY: all clean fclean re bonus
