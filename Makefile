EXE       = serpent

CXX       = clang++
CXXFLAGS  = -Wall -Wextra -Iinclude

LD        = clang++
LDLIBS    = -lraylib

SRC      := $(wildcard src/*.cpp)
DEPS     := $(wildcard include/*.h)
OBJ      := $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(LD) $(LDLIBS) $^ -o $(EXE)

src/%.o: src/%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXE)

.PHONY: $(EXE) clean install uninstall
