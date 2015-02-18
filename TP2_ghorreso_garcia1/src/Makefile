TESTS = testDvectorConstrFile.o testDvectorConstr1.o testDvectorConstr2.o testDvectorConstr3.o testFluxEntrant.o testAffectationMemeTaille1.o testAffectationMemeTaille2.o testAffectationMemeTaille3.o testAffectationMemeTaille4.o testAffectationMemeTaille5.o testAffectationMemeTaille6.o testAffectationTailleDifferente1.o testAffectationTailleDifferente2.o testDiviseDouble.o testEgalite.o testFluxSortant.o testInegaliteTaille.o testInegaliteValeur.o testMoinsDeuxDvector.o testMoinsDouble.o testMoinsDvector.o testMultDouble.o testOpposeDvector.o testParentheses.o testPlusDeuxDvector.o  testPlusDouble.o testPlusDvector.o testViewCopyFalse.o testViewCopyTrue.o
EXECTEST = testDvectorConstrFile testDvectorConstr1 testDvectorConstr2 testDvectorConstr3 testFluxEntrant testAffectationMemeTaille1 testAffectationMemeTaille2 testAffectationMemeTaille3 testAffectationMemeTaille4 testAffectationMemeTaille5 testAffectationMemeTaille6 testAffectationTailleDifferente1 testAffectationTailleDifferente2 testDiviseDouble testEgalite testFluxSortant testInegaliteTaille testInegaliteValeur testMoinsDeuxDvector testMoinsDouble testMoinsDvector testMultDouble testOpposeDvector testParentheses testPlusDeuxDvector  testPlusDouble testPlusDvector testViewCopyFalse testViewCopyTrue
CXX = g++
CXXFLAGS = -Wall -g

all : test

.o : .h .cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.cpp :	.h
	$(CXX) $(CXXFLAGS) -c $@ $< 

clean :
	rm *.o
	rm $(EXECTEST)

exectest : test
	./testDvectorConstr1
	./testDvectorConstr2
	./testDvectorConstr3
	./testDvectorConstrFile
	./testFluxEntrant
	./testAffectationMemeTaille1 
	./testAffectationMemeTaille2 
	./testAffectationMemeTaille3 
	./testAffectationMemeTaille4 
	./testAffectationMemeTaille5 
	./testAffectationMemeTaille6 
	./testAffectationTailleDifferente1
	./testAffectationTailleDifferente2 
	./testDiviseDouble 
	./testEgalite 
	./testFluxSortant 
	./testInegaliteTaille 
	./testInegaliteValeur 
	./testMoinsDeuxDvector 
	./testMoinsDouble 
	./testMoinsDvector 
	./testMultDouble 
	./testOpposeDvector 
	./testParentheses 
	./testPlusDeuxDvector  
	./testPlusDouble 
	./testPlusDvector
	./testViewCopyFalse
	./testViewCopyTrue

test : $(TESTS) Dvector.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstrFile Dvector.o testDvectorConstrFile.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr1 Dvector.o testDvectorConstr1.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr2 Dvector.o testDvectorConstr2.o 
	$(CXX) $(CXXFLAGS) -o testDvectorConstr3 Dvector.o testDvectorConstr3.o
	$(CXX) $(CXXFLAGS) -o testFluxEntrant Dvector.o testFluxEntrant.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille1 Dvector.o testAffectationMemeTaille1.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille2 Dvector.o testAffectationMemeTaille2.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille3 Dvector.o testAffectationMemeTaille3.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille4 Dvector.o testAffectationMemeTaille4.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille5 Dvector.o testAffectationMemeTaille5.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille6 Dvector.o testAffectationMemeTaille6.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferente1 Dvector.o testAffectationTailleDifferente1.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferente2 Dvector.o testAffectationTailleDifferente2.o
	$(CXX) $(CXXFLAGS) -o testDiviseDouble Dvector.o testDiviseDouble.o
	$(CXX) $(CXXFLAGS) -o testEgalite Dvector.o testEgalite.o
	$(CXX) $(CXXFLAGS) -o testFluxSortant Dvector.o testFluxSortant.o
	$(CXX) $(CXXFLAGS) -o testInegaliteTaille Dvector.o testInegaliteTaille.o
	$(CXX) $(CXXFLAGS) -o testInegaliteValeur Dvector.o testInegaliteValeur.o
	$(CXX) $(CXXFLAGS) -o testMoinsDeuxDvector Dvector.o testMoinsDeuxDvector.o
	$(CXX) $(CXXFLAGS) -o testMoinsDouble Dvector.o testMoinsDouble.o
	$(CXX) $(CXXFLAGS) -o testMoinsDvector Dvector.o testMoinsDvector.o
	$(CXX) $(CXXFLAGS) -o testMultDouble Dvector.o testMultDouble.o
	$(CXX) $(CXXFLAGS) -o testOpposeDvector Dvector.o testOpposeDvector.o
	$(CXX) $(CXXFLAGS) -o testParentheses Dvector.o testParentheses.o
	$(CXX) $(CXXFLAGS) -o testPlusDeuxDvector Dvector.o testPlusDeuxDvector.o
	$(CXX) $(CXXFLAGS) -o testPlusDouble Dvector.o testPlusDouble.o
	$(CXX) $(CXXFLAGS) -o testPlusDvector Dvector.o testPlusDvector.o
	$(CXX) $(CXXFLAGS) -o testViewCopyFalse Dvector.o testViewCopyFalse.o	
	$(CXX) $(CXXFLAGS) -o testViewCopyTrue Dvector.o testViewCopyTrue.o
