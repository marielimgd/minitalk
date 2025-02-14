# Program Names
NAME   = minitalk
CLIENT = client
SERVER = server

# Compiler and Flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
INCLUDES = -I includes -I libft/includes

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source Files
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC_BONUS = $(SRC_DIR)/client_bonus.c
SERVER_SRC_BONUS = $(SRC_DIR)/server_bonus.c

# Object Files
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_OBJ = $(OBJ_DIR)/server.o
CLIENT_OBJ_BONUS = $(OBJ_DIR)/client_bonus.o
SERVER_OBJ_BONUS = $(OBJ_DIR)/server_bonus.o

$(NAME): all

all: $(CLIENT) $(SERVER)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

# Create Object Directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Build Client
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

# Build Server
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

# Build Client Bonus
$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

# Build Server Bonus
$(SERVER_BONUS): $(SERVER_OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

# Clean only object files
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@make -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

# Phony Targets
.PHONY: all clean fclean re