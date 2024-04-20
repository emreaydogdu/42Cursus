.PHONY: all bonus clean fclean re

CLIENT = client
SERVER = server
SRC_S = server.c
SRC_C = client.c
OBJS_S = ${SRC_S:.c=.o}
OBJS_C = ${SRC_C:.c=.o}
RM = rm
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(CLIENT) $(SERVER)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(CLIENT): $(OBJS_C)
	$(CC) $(CFLAGS) $< -o $@

$(SERVER): $(OBJS_S)
	$(CC) $(CFLAGS) $< -o $@

bonus: all

clean:
	$(RM) -f ${OBJS_S} ${OBJS_C}

fclean: clean
	$(RM) -f $(SERVER) $(CLIENT)

re: fclean all