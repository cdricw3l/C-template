NAME=bin/heaplib
CC=gcc
AR= ar -rcs
CFLAGS=-Wall -Werror -Wextra -g
SRCS= 	srcs/heap_bfs_arr.c \
		srcs/heap_clear.c \
		srcs/heap_destroy.c \
		srcs/heap_display_node.c \
		srcs/heap_get_node.c \
		srcs/heap_init.c \
		srcs/heap_iter.c \
		srcs/heap_new_node.c \
		srcs/heap_swap_node.c \
		srcs/heappop.c \
		srcs/heappush.c

OBJECT_SRCS= $(:.c=.o)
MEMORY_CHECK ?=0

#### TEST VARIABLE ###
TEST_FOLDER= test
TYPE ?= unit
######################

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT_SRCS)
	$(AR) $(NAME) $(OBJECT_SRCS) 

clean:
	make -C $(TEST_FOLDER) clean
	rm -f $(OBJECT_SRCS)

fclean: clean
	make -C $(TEST_FOLDER) fclean
	rm -f $(NAME)


test:
	@make -C $(TEST_FOLDER) TYPE=$(TYPE) MEMORY_CHECK=$(MEMORY_CHECK) test


.PHONY: clean fclean test