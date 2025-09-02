
# Nom du programme à créer
NAME = main

# Compilateur à utiliser
CXX = c++

# Flags de compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Liste des fichiers source
SRCS = main.cpp \
		 AMateria.cpp \
		 Ice.cpp \
		 Cure.cpp \
		 Character.cpp \
		 MateriaSource.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Fichiers d'en-tête
HEADERS = AMateria.hpp \
			 Ice.hpp \
			 Cure.hpp \
			 Character.hpp \
			 ICharacter.hpp \
			 MateriaSource.hpp \
			 IMateriaSource.hpp

# Règle par défaut
all: $(NAME)

# Règle pour compiler le programme
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Règle pour compiler les fichiers objets
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	rm -f *.o

# Règle pour nettoyer tout
fclean: clean
	rm -f $(NAME)

# Règle pour recompiler
re: fclean all

.PHONY: all clean fclean re