task = xint
opcja1 = -std=c++17 -static -O3
opcja2 = -lm

all: $(task) 

$(task): test.cpp
	g++ $(opcja1) -o $(task) test.cpp $(opcja2)

clean:
	rm $(task) test

indent:
	clang-format  -i test.cpp xint.cpp xint.h