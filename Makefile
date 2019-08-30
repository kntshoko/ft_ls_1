# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kntshoko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 15:04:01 by kntshoko          #+#    #+#              #
#    Updated: 2019/08/30 15:06:45 by kntshoko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls.a
CC = gcc
FLAG = -Wall -Werror -Wextra
ARC = ar rc
SRC = ft_impliment.c ft_recurse.c ft_join.c ft_sort.c ft_checkpath.c ft_l.c ft_sortascii.c ft_cmp.c ft_listdir.c ft_sorttime.c ft_countcontent.c ft_countdir.c ft_ls.c main.c ft_directories.c  ft_flagcheck.c ft_print.c
OBJ = ft_impliment.o ft_recurse.o ft_join.o ft_sort.o ft_checkpath.o ft_l.o ft_sortascii.o ft_cmp.o ft_listdir.o ft_sorttime.o ft_countcontent.o ft_countdir.o ft_ls.o main.o ft_directories.o  ft_flagcheck.o ft_print.o
# all: ${NAME}
${NAME}:
   @echo "Creating objects.."
   @${CC} ${FLAG} -c ${SRC}
   @echo "Creating LS library.."
   @${ARC} ${NAME} ${OBJ}
   @echo "Indexing library.."
   @ranlib ${NAME}
   @echo "Compiling executable 'ft_ls'.."
   @${CC} ${FLAG} ls_main.c libft/libft.a ft_ls.a -o ft_ls
all: ${NAME}
clean:
   @echo "cleaning *.o .."
   @rm -f *.o
fclean: clean
   @echo "Snapping the stones.."
   @rm -f ${NAME} ft_ls
re: fclean all
