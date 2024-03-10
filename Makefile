EXE       = serpent

CXX       = clang++
CXXFLAGS  = -Wall -Wextra

LD        = clang++
LDLIBS    = -lraylib

SRC      := $(wildcard *.cpp)
DEPS     := $(wildcard *.h)
OBJ      := $(SRC:.cpp=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(LD) $(LDLIBS) $^ -o $(EXE)

%.o: %.c $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXE)

.PHONY: $(EXE) clean install uninstall
