CFLAGS = -I./inc -Wall -g

# Directories
SRC_DIR = ./src
INC_DIR = ./inc
BUILD_DIR = ./build

# Files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/cb_lib.c
HEADERS = $(INC_DIR)/main.h $(INC_DIR)/cb_lib.h

EXE = $(BUILD_DIR)/main.exe
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/cb_lib.o

# Default target
all: $(EXE)

$(EXE): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $@

# Compile each .c to .o and generate .lst
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$*.lst

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean