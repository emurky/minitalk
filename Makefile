SRCSDIR				= ./sources
OBJSDIR				= ./objs
DEPSDIR				= ./deps

# SRCS				= $(addprefix $(SRCSDIR)/, 

SERVER				= server
S_SRCS				= server.c
S_OBJS				= $(S_SRCS:.c=.o)
S_DEPS				= $(S_SRCS:.c=.d)

CLIENT				= client
C_SRCS				= client.c
C_OBJS				= $(C_SRCS:.c=.o)
C_DEPS				= $(C_SRCS:.c=.d)

NAME				= minitalk

CC 					= gcc
RM 					= rm -f
CFLAGS				= -Wall -Wextra -Werror -g -fsanitize=address
CPPFLAGS			= -MMD -I. -I./libft
LIBS				= -L./libft -lft


all:				$(NAME)

$(SERVER):			$(S_OBJS)
					$(MAKE) -C ./libft -j4
					$(CC) $(CFLAGS) $(S_OBJS) $(LIBS) -o $(SERVER)

$(CLIENT):			$(C_OBJS)
					$(MAKE) -C ./libft -j4
					$(CC) $(CFLAGS) $(C_OBJS) $(LIBS) -o $(CLIENT)

$(NAME):			$(SERVER) $(CLIENT)

bonus:				all

-include			$(S_DEPS) $(C_DEPS)

clean:
					$(MAKE) clean -C ./libft
					$(RM) $(S_OBJS) $(S_DEPS) $(C_OBJS) $(C_DEPS)

fclean:				clean
					$(RM) ./libft/libft.a
					$(RM) $(SERVER) $(CLIENT)

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
	rm -rf *.o *.a */*.o */*.a */*/*.o */*/*.a */*.d *.d */*.d */*/*.d 'server '* 'client '* server client

.PHONY:				all clean fclean re bonus \
					libft libft_clean libft_fclean libft_re \
					sc

#.SILENT:
# gcc -Wall -Wextra -Werror -L./libft -g sources/*.c -o 
# leaks --atExit -- ./
