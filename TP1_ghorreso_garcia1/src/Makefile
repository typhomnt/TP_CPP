TESTS = testDisplay.o testDvectorConstrFile.o testDvectorConstr1.o testDvectorConstr2.o testDvectorConstr3.o testFillRandomly.o  testSize.o
EXECTEST = testDisplay testDvectorConstrFile testDvectorConstr1 testDvectorConstr2 testDvectorConstr3 testFillRandomly  testSize
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
	rm *.txt

exectest : test
	./testDvectorConstr1
	./testDvectorConstr2
	./testDvectorConstr3
	./testDvectorConstrFile
	./testDisplay
	./testSize     
	./testFillRandomly  

test : $(TESTS) Dvector.o
	$(CXX) $(CXXFLAGS) -o testDisplay  Dvector.o testDisplay.o 
	$(CXX) $(CXXFLAGS) -o testDvectorConstrFile Dvector.o testDvectorConstrFile.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr1 Dvector.o testDvectorConstr1.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr2 Dvector.o testDvectorConstr2.o 
	$(CXX) $(CXXFLAGS) -o testDvectorConstr3 Dvector.o testDvectorConstr3.o
	$(CXX) $(CXXFLAGS) -o testFillRandomly Dvector.o testFillRandomly.o 
	$(CXX) $(CXXFLAGS) -o testSize Dvector.o testSize.o 
