
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seroy <seroy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 17:07:16 by seroy             #+#    #+#              #
#    Updated: 2023/03/15 14:16:14 by seroy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library Name ----------------------------

NAME = libft.a

#Dependencies -----------------------------

#Command variables ------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
MK = mkdir -p
RM = rm -rf

#Sources directories
INCDIR = inc
SRCDIR = src
SRC = ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c\
	get_next_line.c\
	get_next_line_utils.c
		
VPATH = ${SRCDIR}

#Object directories

OBJDIR = obj

OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

${OBJDIR}/%.o : %.c
	@${CC} ${FLAGS} -I${INCDIR} -I. -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJDIR):
	$(MK) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all