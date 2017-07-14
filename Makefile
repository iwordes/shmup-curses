CC := clang++
CF += -Wall -Wextra -Werror -lncurses
CF += -I include -I include/entity -I include/trait

SRC := src/**.cpp

.PHONY: all
all: ft_retro

.PHONY: clean
clean:

.PHONY: fclean
fclean: clean
	rm -f ft_retro

.PHONY: re
re: fclean all

ft_retro: src/*.cpp src/*/*.cpp include/*.hpp include/*/*.hpp
	$(CC) $(CF) -o $@ src/*.cpp src/*/*.cpp
