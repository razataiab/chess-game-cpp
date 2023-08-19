# Compiler and linker settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -Iinclude -g
LDFLAGS = -Llib -lSDL2 -lSDL2_image -lSDL2_ttf -fsanitize=address

# Directories
SRCDIR = src
BINDIR = .

# Files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
DEPS = $(SRCS:.cpp=.d)
TARGET = $(BINDIR)/chess_game

# Targets
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

-include $(DEPS)

clean:
	rm -f $(TARGET)

# create-window target
create-window: $(SRCDIR)/board.cpp $(SRCDIR)/window.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $(BINDIR)/create_window
