# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Icommon -I.

# Raylib and math libraries
LDFLAGS = -lraylib -lm

# Paths
COMMON_SRC = $(wildcard common/*.cpp)
COMMON_OBJ = $(patsubst common/%.cpp, build/common/%.o, $(COMMON_SRC))

# Game-specific source files
SNAKE_SRC = $(wildcard games/snake/*.cpp)
SNAKE_OBJ = $(patsubst games/snake/%.cpp, build/snake/%.o, $(SNAKE_SRC))

PONG_SRC = $(wildcard games/pong/*.cpp)
PONG_OBJ = $(patsubst games/pong/%.cpp, build/pong/%.o, $(PONG_SRC))

# Targets
SNAKE_TARGET = build/snake_game
PONG_TARGET = build/pong_game

# Default target builds both
all: $(SNAKE_TARGET) $(PONG_TARGET)

# Snake build
$(SNAKE_TARGET): $(COMMON_OBJ) $(SNAKE_OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Pong build
$(PONG_TARGET): $(COMMON_OBJ) $(PONG_OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Generic rule for object file compilation
build/common/%.o: common/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/snake/%.o: games/snake/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/pong/%.o: games/pong/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean
