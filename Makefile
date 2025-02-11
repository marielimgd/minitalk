NAME   = minitalk
CLIENT = client
SERVER = server

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I includes -I libft/includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRCS	= $(SRC_DIR)/client.c $(SRC_DIR)/server.c $(SRC_DIR)/utils.c
OBJS	= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))


all: build

$(NAME): all

build: libft_build compile_to_o compile_server compile_client


libft_build:
	@make -C libft

obj_dir:
	@mkdir -p obj

obj/client.o:
	@$(CC) $(CFLAGS) -c src/client.c -o obj/client.o

obj/server.o:
	@$(CC) $(CFLAGS) -c src/server.c -o obj/server.o

obj/utils.o:
	@$(CC) $(CFLAGS) -c src/utils.c -o obj/utils.o

compile_server:
	$(CC) $(CFLAGS) obj/server.o $(LIBFT) -o server
compile_client:
	$(CC) $(CFLAGS) obj/utils.o obj/client.o $(LIBFT) -o client

compile_to_o: obj_dir obj/client.o obj/server.o obj/utils.o





# all: $(OBJ_DIR) obj_files libft build


# build: $(CLIENT_OBJ) $(SERVER_OBJ)
# 	@$(CC) $(CFLAGS) $(OBJ_DIR)/client.o $(OBJ_DIR)/utils.o $(LIBFT) -o $(CLIENT)
# 	@$(CC) $(CFLAGS) $(OBJ_DIR)/server.o $(OBJ_DIR)/utils.o $(LIBFT) -o $(SERVER)

# $(OBJ_DIR)/%.o $(SRC_DIR)/%.c | $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# libft:
# 	@make -C $(LIBFT_DIR)

# # $(CLIENT): $(CLIENT_OBJ) 
# # 	@$(CC) $(CFLAGS) $(DEBUG) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

# # #_____________________________
# # $(SERVER): $(SERVER_OBJ)
# # 	@$(CC) $(CFLAGS) $(DEBUG) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)




$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


clean:
	rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	rm -f $(NAME) client server
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re