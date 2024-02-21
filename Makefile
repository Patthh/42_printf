NAME = libftprintf.a
SOURCES = ft_itoa.c ft_print_hex.c ft_print_unsigned.c ft_print_variables.c ft_printf.c ft_pointer.c
HDR = ft_printf.h
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ANSI color codes
CYAN := \033[0;36m
RED := \033[0;31m
YELLOW := \033[0;33m
GREEN := \033[0;32m
NC := \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $^
	@printf "$(GREEN)Successfully created $(NAME)$(NC)\n"

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $<
	@printf "$(CYAN)Successfully compiled $<$(NC)\n"

clean:
	rm -f $(OBJECTS)
	@printf "$(RED)Successfully removed object files$(NC)\n"

fclean: clean
	rm -f $(NAME)
	@printf "$(YELLOW)Successfully removed $(NAME)$(NC)\n"

re: fclean all

.PHONY: all clean fclean re

