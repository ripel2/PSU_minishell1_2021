##
## EPITECH PROJECT, 2021
## my
## File description:
## Makefile for the my library
##

SRC = my_getnbr.c \
	my_is_letter.c \
	my_is_nbr.c \
	my_isneg.c \
	my_is_prime.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_putstr_err.c \
	my_revstr.c \
	my_showmem.c \
	my_showstr.c \
	my_show_word_array.c \
	my_sort_int_array.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isupper.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	my_printf/my_printf.c \
	my_printf/my_printf_core.c \
	my_printf/octal.c \
	my_printf/print_numbers.c \
	my_printf/print_percent.c \
	my_printf/print_pointer.c \
	my_printf/parsing.c \
	my_printf/long.c \
	my_printf/long_long.c \
	my_printf/putchar_pf.c \
	my_printf/putnbr_pf.c \
	my_printf/putstr_pf.c \
	my_printf/str_utils.c \
	my_printf/result_handler.c \
	my_printf/utils.c


OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: build copy_lib copy_header

build: $(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

copy_lib:
	cp $(NAME) ../$(NAME)

copy_header:
	mkdir -p ../../include
	cp my.h ../../include/my.h

.PHONY: all build clean fclean
