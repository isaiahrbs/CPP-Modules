# Nom du programme
NAME = megaphone

# Compilateur
CXX = c++

# Flags de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS = megaphone.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(NAME)

# Règle pour compiler le programme
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJS)

# Règle pour nettoyer tout
fclean: clean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Ces règles ne correspondent pas à des fichiers
.PHONY: all clean fclean re