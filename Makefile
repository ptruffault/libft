NAME		=	libft.a

GIT 		= https://github.com/ptruffault/libft.git

SRC 		= 	SRCS/ALLOC/*.c \
				SRCS/CONVERTION/*.c \
				SRCS/GET/*.c \
				SRCS/INT/*.c \
				SRCS/IS/*.c \
				SRCS/LS_NEED/*.c \
				SRCS/LST/*.c \
				SRCS/MAP/*.c \
				SRCS/MEM/*.c \
				SRCS/PUT/*.c \
				SRCS/STR/*.c

NAME = libft.a
			
GIT 		= https://github.com/ptruffault/libft.git

OBJ = *.o

FLAG = -Wall -Werror -Wextra

COULEUR		= \033[01;34m

SUCESS		= \033[00m[\033[1;32mOK\033[00m]

all: $(NAME)


$(NAME):
	@echo "\t \033[00;31m\033[04mMAKEFILE LIBFT\033[00m"
	@echo "$(COULEUR)\t+ build with gcc -c $(FLAG) (libft/*.c) -I .\033[00m"
	@gcc -c $(FLAG) $(SRC) -I .includes/
	@echo "\t$(SUCESS)"
	@echo "$(COULEUR)\t+ ar rc && ranlib libft\033[00m"
	@ar rc $(NAME) $(OBJ)
	@mv $(OBJ) BIN/
	@ranlib $(NAME)
	@echo "\t$(SUCESS)"

clean:
	@echo "$(COULEUR)\t+ Cleaning (libft/*.o)\033[00m"
	@$(RM) $(OBJ)
	@echo "\t$(SUCESS)"

fclean: clean
	@echo "$(COULEUR)\t+ Cleaning (libft/libft.a)\033[00m"
	@rm -rf $(NAME)
	@echo "\t$(SUCESS)"

save: clean fclean
	@git add *
	@git add $(SRCS)
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





































