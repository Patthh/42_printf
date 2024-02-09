# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loswaans <swaanslouis@163.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 14:52:12 by loswaans          #+#    #+#              #
#    Updated: 2024/02/09 17:20:02 by loswaans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR   = includes
SRCDIR   = srcs
OBJDIR   = objs

SRCS     = $(wildcard $(SRCDIR)/*.c)
OBJS     = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME     = libftprintf.a
CC       = cc
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
AR       = ar rcs

DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf library has been successfully compiled$(DEFCOLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling: $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJDIR)
	@echo "$(BLUE)ft_printf object files and objs folder cleaned!$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)ft_printf library has been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re

