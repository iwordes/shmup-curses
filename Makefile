CC := clang++
CF += -Wall -Wextra -Werror -std=c++98 -I include -lncurses

SRC1 += Bomber.cpp Octo.cpp Kamikaze.cpp # Shuttlebug.cpp
SRC1 := $(addprefix Enemy/,$(SRC1))

SRC2 += PlayerBullet.cpp
SRC2 := $(addprefix Projectile/,$(SRC2))

SRC3 += spawn.cpp
SRC3 := $(addprefix World/,$(SRC3))

SRC += Enemy.cpp Player.cpp Projectile.cpp #Scenery.cpp
SRC += Entity.cpp World.cpp
SRC += main.cpp
SRC := $(addprefix src/,$(SRC) $(SRC1) $(SRC2) $(SRC3))

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
