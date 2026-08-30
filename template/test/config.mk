CC=gcc
CFLAGS=-Wall -Werror -Wextra -g
TYPE ?= unit
MEMORY_CHECK ?= 0
MEMORY_LOG= memory.log

ifeq ($(shell uname),Darwin)
	MEMORY_CHECK_ARG= leaks -atExit --
else
	MEMORY_CHECK_ARG= valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=$(MEMORY_LOG)
endif

%.o:%.c 
	$(CC) -c $(CFLAGS)  $< -o $@

run:
ifeq ($(MEMORY_CHECK),1)
	$(MEMORY_CHECK_ARG) ./$(NAME)
else
	./$(NAME)
endif

clean:
	@rm -f  $(TEST_OBJS) $(MEMORY_LOG)

fclean: clean
	@rm -f $(NAME)

.PHONY: clean fclean