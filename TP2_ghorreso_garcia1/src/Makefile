TESTS = testDvectorConstrFile.o testDvectorConstr1.o testDvectorConstr2.o testDvectorConstr3.o testFluxEntrant.o
EXECTEST = testDvectorConstrFile testDvectorConstr1 testDvectorConstr2 testDvectorConstr3 testFluxEntrant
CXX = g++
CXXFLAGS = -Wall -g

all : test

.o : .h .cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.cpp :	.h
	$(CXX) $(CXXFLAGS) -c $@ $< 

clean :
	rm $(EXECTEST)
	rm *.o

exectest : test
	./testDvectorConstr1
	./testDvectorConstr2
	./testDvectorConstr3
	./testDvectorConstrFile
	./testFluxEntrant 

test : $(TESTS) Dvector.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstrFile Dvector.o testDvectorConstrFile.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr1 Dvector.o testDvectorConstr1.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr2 Dvector.o testDvectorConstr2.o 
	$(CXX) $(CXXFLAGS) -o testDvectorConstr3 Dvector.o testDvectorConstr3.o
	$(CXX) $(CXXFLAGS) -o testFluxEntrant Dvector.o testFluxEntrant.o
