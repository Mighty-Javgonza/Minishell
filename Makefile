NAME = minishell

SOURCE_PREF =source/
BUILD_PREF =build/
TEST_PREF = tests/

SOURCE_DIRS = $(shell find source -type d)
SOURCE_FILES = $(foreach dir, $(SOURCE_DIRS), $(wildcard $(dir)/*.c))

BUILD_DIRS= $(subst $(SOURCE_PREF), $(BUILD_PREF), $(SOURCE_DIRS))
OBJ_FILES = $(subst $(SOURCE_PREF), $(BUILD_PREF), $(SOURCE_FILES:.c=.o))

TEST_DIRS = $(subst $(SOURCE_PREF), $(TEST_PREF), $(SOURCE_DIRS))
TEST_FILES = $(foreach dir, $(TEST_DIRS), $(wildcard $(dir)/*.c))
TEST_OBJS = $(TEST_FILES:.c=.test)

RETEST_FOLDER =
RETEST_FOLDER_FILES = $(foreach dir, $(RETEST_FOLDER), $(wildcard $(dir)/*.c))
RETEST_FOLDER_OBJS = $(RETEST_FOLDER_FILES:.c=.test)

MAIN=main.c

PROJECT_ADVISOR = "Bonsai	|" 
ECHO = echo $(PROJECT_ADVISOR)

#Delete this if libft is not going to be used
LIBFT = libft/libft.a

CC = gcc
COMP_FLAGS = -Wall -Wextra -Werror
COMPILER = $(CC) $(COMP_FLAGS) -D PROJECT_DIR=\"$(PWD)\"

.PHONY: all clean fclean re dirs cleantests test_folder retest_folder update_tags assemble_tests

$(BUILD_PREF)%.o:$(SOURCE_PREF)%.c
	@$(ECHO) Building $@
	@$(COMPILER) -c -o $@ $<

$(TEST_PREF)%.test:$(TEST_PREF)%.c
	@$(ECHO) Building $<
	@$(COMPILER) -o $@ $< $(OBJ_FILES) $(LIBFT) -lreadline

%:
	@$(ECHO) Creating Directory $@
	@mkdir -p $@


all: dirs $(NAME)

dirs: $(BUILD_DIRS)

$(NAME): $(LIBFT) $(OBJ_FILES) $(MAIN)
	@$(ECHO) Compiling main
	@$(COMPILER) $(MAIN) -o $(NAME) $(OBJ_FILES) $(LIBFT) -lreadline -L $(HOME)/.brew/opt/readline/lib
	@$(ECHO) Compilation Succesful

$(LIBFT):
	cd libft && make

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

assemble_tests: $(TEST_OBJS)

retest: cleantests assemble_tests
	
retest_folder: cleantests $(RETEST_FOLDER_OBJS) 

test_folder: retest_folder
	bash run_folder_tests.sh $(FOLDER_TEST)

cleantests:
	@$(ECHO) removing test files
	@rm -rf $(TEST_OBJS)

update_tags:
	ctags $(SOURCE_FILES) $(foreach dir, $(SOURCE_DIRS), $(wildcard $(dir)/.*h))
