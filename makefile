CC      = gcc
CFLAGS  = -Wall -Wextra -g

SRC_DIR = src

GEN_DIR = build

INTERPRETER  = interpret

C_SRC = \
	$(GEN_DIR)/parser.tab.c \
	$(GEN_DIR)/lex.yy.c \
	$(SRC_DIR)/ast.c \
	$(SRC_DIR)/interpret.c \
	$(SRC_DIR)/evaluate.c \
	$(SRC_DIR)/execute.c \
	$(SRC_DIR)/tools/helper.c\
	$(SRC_DIR)/tools/hash_table.c\
	$(SRC_DIR)/tools/key_generator.c\
	$(SRC_DIR)/main.c

all: $(INTERPRETER)


$(INTERPRETER): $(C_SRC)
	$(CC) $(CFLAGS) $^ -o $@

$(GEN_DIR)/parser.tab.c $(GEN_DIR)/parser.tab.h: $(SRC_DIR)/parser.y | $(GEN_DIR)
	bison -d -o $(GEN_DIR)/parser.tab.c $<

$(GEN_DIR)/lex.yy.c: $(SRC_DIR)/lex.l $(GEN_DIR)/parser.tab.h
	flex -o $@ $<

run: $(INTERPRETER)
	./$(INTERPRETER) < ./examples/calc.n

$(GEN_DIR):
	mkdir -p $(GEN_DIR)

clean:
	rm -rf $(GEN_DIR) $(INTERPRETER)

.PHONY: all clean run
