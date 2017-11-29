# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 17:03:31 by vartyukh          #+#    #+#              #
#    Updated: 2016/12/02 20:23:45 by vartyukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_putchar.c         \
	   ft_putchar_fd.c		\
	   ft_putstr.c          \
	   ft_putstr_fd.c		\
	   ft_putnbr.c			\
	   ft_putnbr_fd.c		\
	   ft_putendl.c			\
	   ft_putendl_fd.c		\
	   ft_strlen.c			\
	   ft_strcpy.c			\
	   ft_strcat.c			\
	   ft_strncat.c			\
	   ft_strcpy.c			\
	   ft_strncpy.c			\
	   ft_strlcat.c			\
	   ft_strchr.c			\
	   ft_strrchr.c			\
	   ft_strcmp.c			\
	   ft_strncmp.c			\
	   ft_atoi.c			\
	   ft_isdigit.c			\
	   ft_isalnum.c			\
	   ft_isalpha.c			\
	   ft_isascii.c			\
	   ft_isprint.c			\
	   ft_toupper.c			\
	   ft_tolower.c			\
	   ft_strstr.c			\
	   ft_strnstr.c			\
	   ft_strdup.c			\
	   ft_memset.c			\
	   ft_bzero.c			\
	   ft_memcpy.c			\
	   ft_memcmp.c			\
	   ft_memccpy.c			\
	   ft_memchr.c			\
	   ft_memmove.c			\
	   ft_memalloc.c		\
	   ft_memdel.c			\
	   ft_strnew.c			\
	   ft_strdel.c			\
	   ft_strclr.c			\
	   ft_striter.c			\
	   ft_striteri.c		\
	   ft_strmap.c			\
	   ft_strmapi.c			\
	   ft_strequ.c			\
	   ft_strnequ.c			\
	   ft_strsub.c			\
	   ft_strjoin.c			\
	   ft_strtrim.c			\
	   ft_itoa.c			\
	   ft_strsplit.c		\
	   ft_lstnew.c			\
	   ft_lstdelone.c		\
	   ft_lstdel.c			\
	   ft_lstadd.c			\
	   ft_lstiter.c			\
	   ft_lstmap.c			\

BINS = $(SRCS:.c=.o)

TEST = main.c

TEST_BINS = $(TEST:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	ar rc $(NAME) $(BINS)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)
	/bin/rm -f $(TEST_BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

f: all
	@echo "\033[38;5;93mLINKING:\033[0m"
	gcc -o $(NAME)_test $(TEST) $(NAME).a
	@echo "\033[38;5;93mRUNNING:\033[0m"
	./$(NAME)_test
