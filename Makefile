NAME = libft.a
			
GIT 		= https://github.com/ptruffault/libft.git

SRC = ./ft_memset.c ./ft_strncut.c ./ft_caps_lock.c ./ft_bzero.c \
./ft_memcpy.c ./ft_memmove.c ./ft_memccpy.c ./ft_strchr.c \
./ft_memchr.c ./ft_memcmp.c  ./ft_strcpy.c ./ft_strdup.c \
./ft_strlen.c ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c \
./ft_strlcat.c ./ft_strrchr.c ./ft_strstr.c  ./ft_strnstr.c \
./ft_strcmp.c  ./ft_strncmp.c ./ft_atoi.c ./ft_ismin.c \
./ft_ismaj.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c \
./ft_isascii.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c \
./ft_memalloc.c ./ft_itoa.c ./ft_memdel.c ./ft_putchar_fd.c \
./ft_putchar.c ./ft_putendl_fd.c ./ft_putendl.c ./ft_putnbr_fd.c \
./ft_putnbr.c ./ft_putstr_fd.c ./ft_putstr.c ./ft_putstr_tab.c \
./ft_strclr.c ./ft_strdel.c ./ft_strequ.c ./ft_striter.c \
./ft_striteri.c ./ft_strjoin.c ./ft_strmap.c ./ft_strmapi.c \
./ft_strnequ.c ./ft_strnew.c ./ft_strsplit.c ./ft_strsub.c \
./ft_strtrim.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c \
./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_sqrt.c \
./ft_realloc.c ./ft_get_input.c ./ft_new_path.c ./ft_get_tfile.c \
./ft_get_file_information.c ./ft_free_tfile.c ./ft_new_tfile.c \
./ft_dir_compltion.c ./ft_search_tfile.c ./ft_get_prev_path.c \
./ft_putstr_color_fd.c ./ft_sort_tfile.c ./ft_put_tfile.c ./ft_freestrarr.c \
./ft_str_startwith.c ./ft_strsplit_whitespace.c ./ft_strrev.c


OBJ = $(SRC:.c=.o)

RM = rm -f

FLAG = -Wall -Werror -Wextra

COULEUR		= \033[01;34m

SUCESS		= \033[00m[\033[1;32mOK\033[00m]

all: $(NAME)


$(NAME):
	@echo "\t \033[00;31m\033[04mMAKEFILE LIBFT\033[00m"
	@echo "$(COULEUR)\t+ build with gcc -c $(FLAG) (libft/*.c) -I .\033[00m"
	@gcc -c $(FLAG) $(SRC) -I .
	@echo "\t$(SUCESS)"
	@echo "$(COULEUR)\t+ ar rc && ranlib libft\033[00m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\t$(SUCESS)"

clean:
	@echo "$(COULEUR)\t+ Cleaning (libft/*.o)\033[00m"
	@$(RM) $(OBJ)
	@echo "\t$(SUCESS)"

fclean: clean
	@echo "$(COULEUR)\t+ Cleaning (libft/libft.a)\033[00m"
	@$(RM) $(NAME)
	@echo "\t$(SUCESS)"

save: clean fclean
	@git add *
	@git commit -m "[make save]"
	@git push
	@echo "\t$(SUCESS)"

load: clear fclean
	@echo "$(COULEUR)\t+ removing all file\033[00m"
	rm -rf *
	@echo "\t$(SUCESS)"
	@echo "$(COULEUR)\t+ download libft\033[00m"
	@git clone $(GIT) git_tmp
	@cp git_tmp/* .
	@rm git_tmp
	@echo "$(SUCESS)"

re: fclean all