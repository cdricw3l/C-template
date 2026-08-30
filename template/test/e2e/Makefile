include ../config.mk
NAME=e2e_test

TEST_SRCS= $(wildcard *.c)
TEST_OBJS= $(TEST_SRCS:.c=.o)

test: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(NAME)

