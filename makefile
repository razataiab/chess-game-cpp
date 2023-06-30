# Compiler and linker settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -I$(INCDIR) -g
LDFLAGS = -Llib -lSDL2 -lSDL2_image -lSDL2_ttf -fsanitize=address

# Directories
SRCDIR = src
INCDIR = include
BINDIR = .

# Files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
DEPS = $(OBJS:.o=.d)
TARGET = $(BINDIR)/chess_game

# Header dependencies
DEP_HEADERS = $(SRCS:$(SRCDIR)/%.cpp=$(INCDIR)/%.h)
DEP_DEPS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.d)

# Targets
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)
-include $(DEP_DEPS)

clean:
	rm -f $(TARGET) $(OBJS) $(DEPS) $(DEP_DEPS)
