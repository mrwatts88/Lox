CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

main: main.o Scanner.o Token.o
	$(CXX) $(CXXFLAGS) -o main ../obj/main.o ../obj/Scanner.o ../obj/Token.o

main.o: Scanner.h Token.h TokenType.h
	$(CXX) $(CXXFLAGS) -c -o ../obj/main.o main.cpp

Scanner.o: Scanner.h TokenType.h
	$(CXX) $(CXXFLAGS) -c -o ../obj/Scanner.o Scanner.cpp

Token.o: Token.h TokenType.h
	$(CXX) $(CXXFLAGS) -c -o ../obj/Token.o Token.cpp

clean:
	rm ../obj/*.o
