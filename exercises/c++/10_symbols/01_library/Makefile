EXE = pippo

SRC = source/hello.cc source/main.cc
OBJ = $(SRC:.cc=.o)

CXX = c++
CXXFLAGS = -I include -std=c++11
LDFLAGS = -l hello -L . -Wl,-rpath,.

all: libhello.so $(EXE)

libhello.so: source/hello.o
	$(CXX) -shared -o $@ $^ $(CXXFLAGS)

%.o:%.cc
	$(CXX) -fpic  -o $@ -c $< $(CXXFLAGS)

source/hello.o: include/hello.h
source/main.o: include/hello.h

clean:
	@rm -f *~ */*~ libhello.so source/*.o

# colors not working...
# see also https://stackoverflow.com/q/6436563
install: libhello.so
	@ TERM=xterm-256color echo $(tput setaf 2)"Installing..."$(tput sgr0)
	@ cp libhello.so /usr/local/include && echo "...done" || echo "...FAILED"

$(EXE): source/main.o libhello.so
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $(EXE)

.PHONY: clean all install
