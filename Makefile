# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vartyukh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/23 17:33:34 by vartyukh          #+#    #+#              #
#    Updated: 2017/03/16 19:54:02 by vartyukh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

LIB = libft/libft.a

SRCS = 	main.c					\
		input.c					\
		read.c					\
		set_info.c				\
		set_info2.c				\
		set_info3.c				\
		set_info4.c				\
		sort.c					\
		write.c					\
		write2.c				\
		ft_itoa_base.c			\

all: $(NAME)

BINS = $(SRCS:.c=.o)

$(NAME): $(BINS)
	make -C libft/
	gcc -o $(NAME) $(BINS) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make clean -C libft/
	/bin/rm -f $(BINS)

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all
