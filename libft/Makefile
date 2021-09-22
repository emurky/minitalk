# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 18:08:11 by emurky            #+#    #+#              #
#    Updated: 2021/09/22 05:18:01 by emurky           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_DIR		= ./ft_printf
LIST_DIR		= ./list_functions

SRCS			= \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				\
				ft_calloc.c \
				ft_strdup.c \
				\
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				\
				ft_isspace_bonus.c \
				ft_isblank_bonus.c \
				ft_putchar_bonus.c \
				ft_putstr_bonus.c \
				ft_putendl_bonus.c \
				ft_putnbr_bonus.c \
				ft_nbrlen_bonus.c \
				ft_charin_bonus.c

SRCS		+=	$(addprefix $(PRINTF_DIR)/, \
					ft_printf.c \
					parser.c \
					chars_printing.c \
					digits_printing.c \
					digits_handler.c )

SRCS		+=	$(addprefix $(LIST_DIR)/, \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c )

OBJS 			= $(SRCS:.c=.o)

DEPS			= $(SRCS:.c=.d)

NAME 			= libft.a

CC				= gcc
RM				= rm -f
AR				= ar -rcs
CFLAGS			= -Wall -Wextra -Werror -I. -g -fsanitize=address
CPPFLAGS		= -MMD

all:			$(NAME)

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

-include		$(DEPS)

bonus:			all

clean:
				$(RM) $(OBJS) $(DEPS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sc:
				rm -rf *.o *.a */*.o */*.a */*.d *.d a.out

.PHONY:			all clean fclean re

#.SILENT:
