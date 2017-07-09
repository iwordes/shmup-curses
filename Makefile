CC := clang++
CF += -Wall -Wextra -Werror -std=c++98 -I include -lncurses

SRC += Entity.cpp Player.cpp Projectile.cpp World.cpp
SRC := $(addprefix class/,$(SRC))
SRC += main.cpp
SRC := $(addprefix src/,$(SRC))

.PHONY: all
all: ft_retro

.PHONY: clean
clean:

.PHONY: fclean
fclean: clean
	rm -f ft_retro

.PHONY: re
re: fclean all

ft_retro: $(SRC)
	$(CC) $(CF) -o $@ $(SRC)
