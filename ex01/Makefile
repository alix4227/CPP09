# compiler
CC			= c++

# flags
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

# artifacts
NAME		= whatever

# source files
SRCS	= main.cpp

# object files
OBJS	= ${SRCS:.cpp=.o}

# rules
all: ${NAME}

${NAME}		: ${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo "✅ Build complete: ${NAME}"

%.o 		: %.cpp
			${CC} ${CFLAGS} -c $< -o $@ 

clean		:
			rm -rf ${OBJS}

fclean		: clean
			rm -rf ${NAME}

re			: fclean all

val			:${NAME}
			valgrind \
			--leak-check=full --tool=memcheck \
			--show-reachable=yes \
			--track-fds=yes \
			--errors-for-leak-kinds=all \
			--show-leak-kinds=all ./${NAME}

.PHONY: all clean fclean re