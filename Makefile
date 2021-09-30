SERVER = server

CLIENT = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

SRC_SER =	error.c		\
			server.c	\
			string.c 	

SRC_CL = 	error.c		\
			client.c    \
			string.c 

SRC_SER_BONUS = server_bonus.c	\
				error.c	\
				string.c 

SRC_CL_BONUS =	client_bonus.c	\
				error.c	\
				string.c 

OBJ_SER = $(SRC_SER:.c=.o)

OBJ_CL = $(SRC_CL:.c=.o)

OBJ_SER_BONUS = $(SRC_SER_BONUS:.c=.o)

OBJ_CL_BONUS = $(SRC_CL_BONUS:.c=.o)

CC = gcc

RM = rm -f

INCL = minitalk.h

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

%.o : %.c $(INCL) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(SERVER): $(OBJ_SER)
	$(CC) $(FLAGS) $(OBJ_SER) -o $(SERVER)

$(CLIENT): $(OBJ_CL)
	$(CC) $(FLAGS) $(OBJ_CL) -o $(CLIENT)

$(SERVER_BONUS): $(OBJ_SER_BONUS)
	$(CC) $(FLAGS) $(OBJ_SER_BONUS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CL_BONUS)
	$(CC) $(FLAGS) $(OBJ_CL_BONUS) -o $(CLIENT_BONUS)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	$(RM) $(OBJ_SER) $(OBJ_CL) $(OBJ_SER_BONUS) $(OBJ_CL_BONUS) 

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) 

re: fclean all

.PHONY : all clean fclean re bonus