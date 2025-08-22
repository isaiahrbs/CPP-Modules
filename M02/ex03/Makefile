# Nom du programme à créer
NAME = main

# Compilateur à utiliser
CXX = c++

# Flags de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Répertoire pour les fichiers objets
OBJ_DIR = obj

# Liste des fichiers source
SRCS = main.cpp \
       Fixed.cpp \
	   Point.cpp \
	   bsp.cpp

# Fichiers objets générés dans le dossier OBJ_DIR
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Fichiers d'en-tête
HEADERS = Fixed.hpp \
		  Point.hpp

# Règle par défaut
all: $(NAME)

# Création du répertoire pour les objets
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Règle pour compiler le programme
$(NAME): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Règle pour compiler les fichiers objets
$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Règle pour nettoyer tout
fclean: clean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

# Ces règles ne correspondent pas à des fichiers
.PHONY: all clean fclean re