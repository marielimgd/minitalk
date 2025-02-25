# Program Names
NAME   = minitalk
CLIENT = client
SERVER = server

# Compiler and Flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g 
INCLUDES = -I includes -I libft/includes

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source Files
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

# Object Files
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_OBJ = $(OBJ_DIR)/server.o

# Default Target
all: $(CLIENT) $(SERVER)

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

# Clean only object files
clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

# Full clean
fclean: clean
	rm -f $(CLIENT) $(SERVER)
	@make -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

# Phony Targets
.PHONY: all bonus clean fclean re