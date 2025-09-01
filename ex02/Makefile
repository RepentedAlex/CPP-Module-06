NAME		=	real_type
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS	+=	-g3
CXXFLAGS	+=	-Iinclude

BUI_DIR		=	build/
INC_DIR		=	include/
SRC_DIR		=	src/

SRC_FIL		=	\
				main \
				Base \
				A \
				B \
				C

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FIL)))
OBJ			=	$(addprefix $(BUI_DIR), $(addsuffix .o, $(SRC_FIL)))
OBJF		=	.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $@..."
	@$(CXX) $(OBJ) -o $@
	@echo "$@ executable is ready! :D"

$(BUI_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJF)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJF):
	@touch $(OBJF)

.clangd: Makefile
	@echo "Making clangd configuration file"
	@echo -n																\
	"CompileFlags:\n"														\
	"  Compiler: clang\n"													\
	"  Add:\n"																\
	"    - \"-Wall -Wextra -Werror\"\n"										\
	"    - \""$(42_FLAGS)"\"\n"	> .clangd
	@for file in $(INC_DIR); do												\
		echo "     - \"-I"$(shell pwd)"/"$$file"\"" >> .clangd;				\
	done ;
	@echo $(GREEN) "Done" $(RESET)

clean:
	@echo "Removing build files..."
	@rm -rf $(BUI_DIR) $(OBJF)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
