LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		src/format_treatment.c \
		src/ft_flag_parser.c \
		src/ft_treat_char.c \
		src/ft_treat_hexa.c \
		src/ft_treat_percent.c \
		src/ft_treat_pointer.c \
		src/ft_treat_str.c \
		src/ft_treat_uix.c \
		src/ft_ull_base.c \
		src/printf_int_flags.c \

SRCS_DEL =  ft_printf.o \
			format_treatment.o \
			ft_flag_parser.o \
			ft_treat_char.o \
			ft_treat_hexa.o \
			ft_treat_percent.o \
			ft_treat_pointer.o \
			ft_treat_str.o \
			ft_treat_uix.o \
			ft_ull_base.o \
			printf_int_flags.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

SURPL_O = $(SRCS:.c=.o)

# .c.o:
# 	$(CC) $(FLAGS) $< -o $(<:.c=.o)

$(NAME): $(SURPL_O)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar rc $(NAME) $(SURPL_O)
	ranlib $(NAME)
	rm -rf $(SRCS_DEL)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(SURPL_O) 

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
.PHONY: all, clean, fclean, re, bonus