SOURCES= main.cpp Maillage.h Triangle.h Point.h
EXEC= main 
CXXFLAGS = -Wall -g
CXX= g++


test:
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SOURCES)

exectest: test
	./$(EXEC)
clean:
	rm *.o $(EXEC) *.dat

valgrinds: test
	valgrind ./$(EXEC)
