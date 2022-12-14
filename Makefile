CFLAGS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
LIBFT_DIR = Libft
LIBFT = libft.a
INCLUDES = includes
SOURCES_SERVER = srcs/server.c
SOURCES_CLIENT = srcs/client.c
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)
BONUS_SOURCES_SERVER = srcs_bonus/server_bonus.c
BONUS_SOURCES_CLIENT = srcs_bonus/client_bonus.c
BONUS_OBJECTS_SERVER = $(BONUS_SOURCES_SERVER:.c=.o)
BONUS_OBJECTS_CLIENT = $(BONUS_SOURCES_CLIENT:.c=.o)
BONUS_CHECK = bonus_check

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJECTS_SERVER)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@ -I $(INCLUDES)

$(CLIENT) : $(OBJECTS_CLIENT)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@ -I $(INCLUDES)

bonus : $(BONUS_CHECK)

$(BONUS_CHECK) : $(BONUS_OBJECTS_SERVER) $(BONUS_OBJECTS_CLIENT)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $(BONUS_OBJECTS_SERVER) $(LIBFT_DIR)/$(LIBFT) -o $(SERVER) -I $(INCLUDES)
	cc $(CFLAGS) $(BONUS_OBJECTS_CLIENT) $(LIBFT_DIR)/$(LIBFT) -o $(CLIENT) -I $(INCLUDES)
	touch $@

%.o : %.c
	cc $(CFLAGS) -c $^ -o $@ -I $(INCLUDES)

clean :
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJECTS_SERVER) $(OBJECTS_CLIENT) $(BONUS_OBJECTS_SERVER) $(BONUS_OBJECTS_CLIENT)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(SERVER) $(CLIENT) $(BONUS_CHECK)

re : fclean all

.PHONY : all bonus clean fclean re