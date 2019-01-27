NAME = evaluate
FILES = ft_btree ft_eval ft_math ft_parser ft_tokenizer ft_queue

SRC = $(addprefix srcs/,$(addsuffix .c, $(FILES)))

HEADER_PATH = includes
FLAGS = -Wall -Wextra -Werror

all:
	gcc -o $(NAME) $(FLAGS) $(SRC) main.c -I$(HEADER_PATH) -L. -lft

token:
	gcc -o $(NAME) $(FLAGS) $(SRC) test_tokenizer.c -I$(HEADER_PATH) -L. -lft

parse:
	gcc -o $(NAME) $(FLAGS) $(SRC) test_parser.c -I$(HEADER_PATH) -L. -lft

clean:
	/bin/rm -f $(NAME)
