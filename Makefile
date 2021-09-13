SRCSDIR				= ./sources
OBJSDIR				= ./objs
DEPSDIR				= ./deps

# SRCS				= $(addprefix $(SRCSDIR)/, 
SRCS				= $(client.c \
						server.c )
OBJS				= $(SRCS:.c=.o)
DEPS				= $(SRCS:.c=.d)

NAME				= test

CC 					= gcc
RM 					= rm -f
CFLAGS				= -Wall -Wextra -Werror -O2 #-g -fsanitize=address
CPPFLAGS			= -MMD -I. -I./includes

LIBS				= \
						-L./libft -lft

all:				$(NAME)

$(NAME):			$(OBJS)
					$(MAKE) -C ./libft -j4
#					$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

bonus:				all

-include			$(DEPS)

clean:
					$(MAKE) clean -C ./libft
					$(RM) $(OBJS) $(DEPS)

fclean:				clean
					$(RM) ./libft/libft.a
					$(RM) $(NAME)

re:					fclean all


# *************** libft rules *************** #
libft:
					$(MAKE) -C ./libft

libft_clean:
					$(MAKE) clean -C ./libft

libft_fclean:
					$(MAKE) fclean -C ./libft

libft_re:
					$(MAKE) re -C ./libft
# ******************************************** #

sc:
					rm -rf *.o *.a */*.o */*.a */*.d *.d 

.PHONY:				all clean fclean re bonus \
					libft libft_clean libft_fclean libft_re \
					sc

#.SILENT:
# gcc -Wall -Wextra -Werror -L./libft -g sources/*.c -o 
# leaks --atExit -- ./
