EXE = exe

LIBDIR = ../01_library
# LFLAGS = -lblass
LFLAGS = -lhello -L $(LIBDIR)  -Wl,-rpath,$(LIBDIR)
CXX = c++
CXXFLAGS = -I include -std=c++11

SRC = src/src1.cc src/src2.cc main.cc
OBJ = $(SRC:.cc=.o)

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): $(OBJ)
	$(CXX) $^ -o $(EXE)  $(CXXFLAGS) $(LFLAGS)

main.o: src/src1.o src/src2.o include/foo.h include/utility.h

src/src1.o: include/utility.h
src/src2.o: include/utility.h

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all
