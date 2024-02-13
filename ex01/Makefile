NAME			:= serialization
CPPFLAGS		:= -g -Wall -Wextra -Werror
STD				:= -std=c++98
SRCDIR			:= src/
SRCS			:= main.cpp serialize.cpp
BINDIR			:= bin/
HEADERS			:= include/
OBJS			:= $(addprefix $(BINDIR), $(SRCS:.cpp=.o))
RM				:= rm -f
CC				:= c++

all : $(NAME)

$(BINDIR)%.o : $(SRCDIR)%.cpp
	@$(CC) -c $(CPPFLAGS) $(STD) -o $@ $^ -I $(HEADERS)

$(NAME) : $(BINDIR) $(OBJS)
	@echo $(NAME): Compiling!
	@$(CC) $(CPPFLAGS) $(STD) -o $(NAME) $(OBJS)

$(BINDIR) :
	@mkdir $(BINDIR)

clean:
	@echo $(NAME): Deleting binaries.
	@rm -r $(BINDIR)

fclean: clean
	@echo $(NAME): Deleting program.
	@rm -f $(NAME)

re : fclean all