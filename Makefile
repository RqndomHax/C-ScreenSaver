CFLAGS 		= -W -Wall -Wextra

# CFLAGS 		+= -g -g3

SFMLFLAGS 	+= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC		= gcc

SRC		= $(wildcard src/*.c)

OBJ		= $(SRC:.c=.o)

LIBOBJ 	= $(LIBSRC:.c=.o)

BIN		= screensaver

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(SFMLFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(BIN)

re: fclean all
