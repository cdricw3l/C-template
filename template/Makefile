NAME=template
CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
SRCS= srcs/main.c 
OBJECT_SRCS= $(SRCS:.c=.o)
MEMORY_CHECK ?=0

#### TEST VARIABLE ###
TEST_FOLDER= test
TYPE ?= unit
######################

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT_SRCS)
	$(CC) $(CFLAGS) $(OBJECT_SRCS) -o $(NAME)

clean:
	make -C $(TEST_FOLDER) clean
	rm -f $(OBJECT_SRCS)

fclean: clean
	make -C $(TEST_FOLDER) fclean
	rm -f $(NAME)


test:
	make -C $(TEST_FOLDER) TYPE=$(TYPE) MEMORY_CHECK=$(MEMORY_CHECK) test


.PHONY: clean fclean test