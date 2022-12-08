CFLAGS=-Wall -Wextra -Werror
SERVER_SRC= server.c
UTILS_SRC= utils.c
CLIENT_SRC= client.c
CLIENT_OBJ= client.o 
SERVER_OBJ= server.o
UTILS_OBJ = utils.o
NAME= server client

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

server:$(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o server
client:$(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o client

clean:
	rm -fr *.o 
fclean:clean
	rm -fr server client 
re:fclean all