EXE       = serpent

CXX       = g++
CXXFLAGS  = -Wall -Wextra

LD        = g++

SRC      := $(wildcard *.cpp)
DEPS     := $(wildcard *.hpp)
OBJ      := $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(LD) $^ -o $(EXE)

%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXE)

.PHONY: $(EXE) clean install uninstall
