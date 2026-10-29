include ../config.mk
NAME=unit_test

TEST_SRCS= $(wildcard *.c) $(wildcard ../../srcs/*.c)
TEST_OBJS= $(TEST_SRCS:.c=.o)

%.o:%.c 
	@$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(TEST_OBJS) -o $(NAME)



