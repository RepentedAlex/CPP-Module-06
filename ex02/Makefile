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
				Base

SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FIL)))
OBJ			=	$(addprefix $(BUI_DIR), $(addsuffix .o, $(SRC_FIL)))
OBJF		=	.cache_exists

# === Terminal Colors ===
NO_COLOR		:=	\033[m
ERROR_COLOR		:=	\033[0;31m
OK_COLOR		:=	\033[0;32m
LIN_COLOR		:=	\033[0;33m
COM_COLOR		:=	\033[0;34m
EXE_COLOR		:=	\033[0;35m
OBJ_COLOR		:=	\033[0;36m
WARN_COLOR		:=	\033[0;33m

# === Output Strings ===
OK_STRING		:=	[OK]
ERROR_STRING	:=	[ERROR]
WARN_STRING		:=	[WARNING]
COM_STRING		:=	Compiling
LIN_STRING		:=	Linking

# === Targets ===

.PHONY: all clean fclean re debug sanitize tags .clangd

all: $(NAME)

define link_and_test
printf "%b" "$(LIN_COLOR)$(LIN_STRING) $(EXE_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(LIN_COLOR)$(LIN_STRING)$(EXE_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(LIN_COLOR)$(LIN_STRING)$(EXE_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(LIN_COLOR)$(LIN_STRING)$(EXE_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

$(NAME): $(OBJ)
	@$(call link_and_test,$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS))

define compile_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

$(BUI_DIR)%.o: $(SRC_DIR)%.cpp | $(BUI_DIR)
	@mkdir -p $(@D)
	@$(call compile_and_test,$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@)

$(BUI_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUI_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.clangd: Makefile
	@echo "Generating .clangd config"
	@echo "CompileFlags:" > .clangd
	@echo "  Add:" >> .clangd
	@for flag in $(CXXFLAGS); do \
		echo "    - '$$flag'" >> .clangd; \
	done
	@for flag in $(CPPFLAGS); do \
		echo "    - '$$flag'" >> .clangd; \
	done
	@for dir in $(INC_DIR); do \
		abs_dir=$$(realpath $$dir) ; \
		echo "    - '-I$$abs_dir'" >> .clangd ; \
	done
	@echo "$(OK_COLOR)[.clangd generated]$(NO_COLOR)"

tags:
	@echo "Generating tags..."
	ctags -R --languages=C++ --c++-kinds=+cfpsv --fields=+iaS --extras=+q $(SRC_DIR) $(INC_DIR)
	@echo "$(OK_COLOR)[tags file generated]$(NO_COLOR)"

debug:
	@$(MAKE) MODE=debug

sanitize:
	@$(MAKE) MODE=sanitize

# === Dependency Include ===
-include $(DEP)
