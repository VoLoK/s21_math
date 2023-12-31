CC=gcc

TARGET?=s21_math.a
TEST_TARGET?=test_s21_math.a
TEST_EXE?=test_s21_math
GCOV_REPORT?=gcov_report

SRC_DIR?=./math
INC_DIR?=./math/includes
OBJ_DIR?=./math/obj

TEST_SRC_DIR?=./mathTests
TEST_INC_DIR?=./mathTests/includes
TEST_OBJ_DIR?=./mathTests/obj

INC:=$(shell find $(INC_DIR) -name "s21_*.h")
SRC:=$(shell find $(SRC_DIR) -name "s21_*.c")
OBJ:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

TEST_INC:=$(shell find $(TEST_INC_DIR) -name "s21_*.h")
TEST_SRC:=$(shell find $(TEST_SRC_DIR) -name "s21_*.c")
TEST_OBJ:=$(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

AR:= ar rc
RAN:= ranlib
MK:= mkdir -p
RM:= rm -f

CFLAGS= -Wall -Wextra -Werror -std=c11
TEST_CFLAGS= -g $(CFLAGS) $(shell pkg-config --cflags --libs check) -lm

all: $(TARGET)

$(TARGET): $(OBJ)
	@$(AR) $(TARGET) $(OBJ)
	@$(RAN) $(TARGET)
	@echo "\033[22;90m$(TARGET) has been changed and recompiled.\033[0m"

$(TEST_TARGET): $(TEST_OBJ)
	@$(AR) $(TEST_TARGET) $(TEST_OBJ)
	@$(RAN) $(TEST_TARGET)
	@echo "\033[22;90m$(TEST_TARGET) has been changed and recompiled.\033[0m"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	@$(MK) $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(TEST_OBJ): $(TEST_OBJ_DIR)%.o: $(TEST_SRC_DIR)%.c $(TEST_INC)
	@$(MK) $(TEST_OBJ_DIR)
	@$(CC) -c $(CFLAGS) -o $@ -c $< -I $(TEST_INC_DIR) -I $(INC_DIR)

test: $(TARGET) $(TEST_TARGET)
	@$(CC) $(TEST_OBJ) $(TEST_TARGET) -o $(TEST_EXE) $(TEST_CFLAGS) -L. $(TARGET)
	@./$(TEST_EXE)
	
add-coverage: 
	$(eval CFLAGS += --coverage)

gcov_report: clean add-coverage test
	@gcovr -o gcov_report.html --html --html-self-contained

clang:
	@cp ../materials/linters/.clang-format ./.clang-format
	@clang-format -n --style=file $(SRC) $(INC) $(TEST_SRC) $(TEST_INC)
	@$(RM) .clang-format

clang-fix:
	@cp ../materials/linters/.clang-format ./.clang-format
	@clang-format -i --style=file $(SRC) $(INC) $(TEST_SRC) $(TEST_INC)
	@$(RM) .clang-format

clean:
	@$(RM) $(OBJ)
	@$(RM) -r $(OBJ_DIR)
	@$(RM) -r $(TEST_OBJ_DIR)
	@$(RM) $(TARGET)
	@$(RM) $(TEST_TARGET)
	@$(RM) $(TEST_EXE)
	@$(RM) gcov*
	@echo "\033[1;31mAll objects have been removed.\033[0m"

re: clean all
