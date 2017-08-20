# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 13:20:16 by anazar            #+#    #+#              #
#    Updated: 2017/08/19 22:30:24 by anazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = ./libft/
PRINTF_DIR = ./printf/
INCLUDES_DIR = ./includes/
LIBFT_H = $(LIBFT_DIR)libft.h
PRINTF_H = $(INCLUDES_DIR)ft_printf.h
#LIBFT_FILES =	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
				ft_memcmp ft_strcat ft_strchr ft_strcpy ft_strdup ft_strlcat \
				ft_strlen ft_strncat ft_strncpy ft_strrchr ft_strstr ft_strnstr \
				ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum \
				ft_isascii ft_isprint ft_toupper ft_tolower ft_memalloc ft_memdel \
				ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap \
				ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strtrim ft_strsplit \
				ft_putchar ft_putstr ft_putnbr ft_putendl \
				ft_putchar_fd ft_putstr_fd ft_putnbr_fd ft_putendl_fd \
				ft_strjoin ft_strjoinfree ft_iswhitespace ft_split_by_function ft_split_by_delims \
				ft_swap ft_isupper ft_islower ft_find_and_replace ft_find \
				ft_trim_by_function ft_trim_by_delims ft_is_in ft_countif \
				ft_strfncpy ft_strrncpy ft_max ft_putstrn
LIBFT_FILES =	ft_atoi ft_countif ft_find ft_is_in ft_isdigit ft_max ft_memalloc \
				ft_memset ft_putchar ft_putstr ft_putendl ft_putnbr ft_putstrn \
				ft_strcat ft_strdel ft_strdup ft_strfncpy ft_strjoinfree ft_strlen \
				ft_strnew ft_strrncpy ft_strsub ft_tolower ft_bzero ft_isupper \
				ft_iswhitespace ft_strcpy ft_strjoin ft_strncmp ft_min
MAIN = replace is_sign is_neg zero_str
#GET = get_one_format get_formats generate_table
GET = get_f_strs get_format generate_table get_width get_sign
SET = set_char set_int set_uint set_addr set_data set_str \
	  set_tmp set_tmp_char set_tmp_int set_tmp_str set_tmp_uns \
	  set_output
CHECK = check_plus check_minus check_space handle_hash handle_zero fix_sign handle_space
PARSE = parse_flags parse_width parse_length parse_precision parse_type parse_format
CONV = 	ft_itoa ft_hhtoa ft_htoa ft_lltoa ft_ltoa ft_jtoa ft_ztoa \
		ft_utoa ft_hhutoa ft_hutoa ft_llutoa ft_lutoa ft_jutoa ft_zutoa \
		ft_ctos ft_wctos
PRINTF_FILES = ft_printf $(MAIN) $(GET) $(SET) $(PARSE) $(CONV) $(CHECK)

LIBFT_SRCS = $(addprefix $(LIBFT_DIR), $(patsubst %, %.c, $(LIBFT_FILES)))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(patsubst %, %.c, $(PRINTF_FILES)))
SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS)
OBJS = $(patsubst %, %.o, $(LIBFT_FILES)) $(patsubst %, %.o, $(PRINTF_FILES))
FLAGS = -I$(INCLUDES_DIR) -I$(LIBFT_DIR)/$(INCLUDES_DIR) -Wall -Werror -Wextra -Wno-format 

all: $(NAME)

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: all
	@gcc $(FLAGS) $(NAME) main.c -o print
	./print

tclean:
	@$(MAKE) fclean
	@rm -rf ./print
