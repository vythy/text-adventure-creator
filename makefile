# TODO: remove relative paths for linking headers
text-adv: main.o node.o parse.o
	g++ -std=c++11 -static-libstdc++ main.o node.o parse.o -o text-adv

main.o: ./src/main.cpp
	g++ -std=c++11 -static-libstdc++ -c ./src/main.cpp

node.o: ./src/node.cpp ./include/node.hpp
	g++ -std=c++11 -static-libstdc++ -c ./src/node.cpp

parse.o: ./src/parse.cpp ./include/parse.hpp
	g++ -std=c++11 -static-libstdc++ -c ./src/parse.cpp

clean: 
	del *.o text-adv.exe
