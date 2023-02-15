task = xint
opcja1 = -std=c++17 -static -O3
opcja2 = -lm

all: $(task) 

$(task): test.cpp xint.cpp xint.h
	g++ $(opcja1) -o $(task) test.cpp xint.cpp $(opcja2)

clean:
	rm -rf $(task) doc

indent:
	clang-format  -i test.cpp xint.cpp xint.h

doc: Doxyfile
	doxygen&&cd doc/latex&&make&&cp refman.pdf ../../man.pdf