CC := clang++
CF += -Wall -Wextra -Werror -I include -lncurses

.PHONY: all
all: ft_retro

.PHONY: clean
clean:

.PHONY: fclean
fclean: clean
	rm -f ft_retro

.PHONY: re
re: fclean all

ft_retro: src/* include/*
	$(CC) $(CF) -o $@ src/*
