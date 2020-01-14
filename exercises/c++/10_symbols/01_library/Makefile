CXX = c++

SRC = source/hello.cc
OBJ = $(SRC:.cc=.o)

all: libhello.so

libhello.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic  -o $@ -c $< -Iinclude

src/hello.o: include/hello.h

clean:
	@rm -f *~ */*~ libhello.so source/*.o

# colors not working...
# see also https://stackoverflow.com/q/6436563
install: libhello.so
	@ TERM=xterm-256color echo $(tput setaf 2)"Installing..."$(tput sgr0)
	@ cp libhello.so /usr/local/include && echo "...done" || echo "...FAILED"


.PHONY: clean all install
