TESTS = testDvectorConstr1.o testDvectorConstr2.o testDvectorConstr3.o testDvectorConstrFile.o testDarrayConstr1.o testDarrayConstr2.o testDarrayConstr3.o testDarrayConstrFile.o testSize.o testGetData.o testIsOwner.o testDisplay.o testViewCopyFalse.o testViewCopyTrue.o testViewCountZero.o testViewDarrayVide.o testViewStartCountTropGrand.o testViewStartNegatif.o testParenthesesLecture.o testParenthesesEcriture.o testPlusDouble.o testMoinsDouble.o testMultDouble.o testDiviseDouble.o testPlusDarray.o testMoinsDarray.o testDarrayPlusDouble.o testDarrayMoinsDouble.o testDarrayMultDouble.o testDarrayDiviseDouble.o testDoublePlusDarray.o testDoubleMultDarray.o testPlusDeuxDarray.o testMoinsDeuxDarray.o testOpposeDarray.o testEgalite.o testInegaliteTaille.o testInegaliteValeur.o testAffectationMemeTaille1.o testAffectationMemeTaille2.o testAffectationMemeTaille3.o testAffectationMemeTaille4.o testAffectationMemeTaille5.o testAffectationMemeTaille6.o testAffectationTailleDifferente1.o testAffectationTailleDifferente2.o testAffectationTailleDifferente3.o testAffectationTailleDifferente4.o testProduitScalaireDvector.o testProduitScalaireDvectorErrorSize.o testProduitScalaireDvectorNullArgument.o testDmatrixConstr1.o testDmatrixConstr2.o testDmatrixConstr3.o testParenthesesDmatrixEcriture.o testParenthesesDmatrixLecture.o testLinesColumns.o testAffectationMemeTailleDmatrix.o testAffectationTailleDifferenteDmatrix.o testDmatrixMultDvector.o testDmatrixMultDvectorDmatrixNull.o testDmatrixMultDvectorDvectorNull.o testDmatrixMultDvectorErrorDimension.o testMultDeuxDmatrix.o testMultDmatrix.o testMultDmatrixErrorDimensions.o testMultDmatrixNullArgument.o testTranspose.o testTransposeDeuxFois.o testTransposeErrorDimensions.o
EXECTEST = testDvectorConstr1 testDvectorConstr2 testDvectorConstr3 testDvectorConstrFile testDarrayConstr1 testDarrayConstr2 testDarrayConstr3 testDarrayConstrFile testSize testGetData testIsOwner testDisplay testViewCopyFalse testViewCopyTrue testViewCountZero testViewDarrayVide testViewStartCountTropGrand testViewStartNegatif testParenthesesLecture testParenthesesEcriture testPlusDouble testMoinsDouble testMultDouble testDiviseDouble testPlusDarray testMoinsDarray testDarrayPlusDouble testDarrayMoinsDouble testDarrayMultDouble testDarrayDiviseDouble testDoublePlusDarray testDoubleMultDarray testPlusDeuxDarray testMoinsDeuxDarray testOpposeDarray testEgalite testInegaliteTaille testInegaliteValeur testAffectationMemeTaille1 testAffectationMemeTaille2 testAffectationMemeTaille3 testAffectationMemeTaille4 testAffectationMemeTaille5 testAffectationMemeTaille6 testAffectationTailleDifferente1 testAffectationTailleDifferente2 testAffectationTailleDifferente3 testAffectationTailleDifferente4 testProduitScalaireDvector testProduitScalaireDvectorErrorSize testProduitScalaireDvectorNullArgument testDmatrixConstr1 testDmatrixConstr2 testDmatrixConstr3 testParenthesesDmatrixLecture testParenthesesDmatrixEcriture testLinesColumns testAffectationMemeTailleDmatrix testAffectationTailleDifferenteDmatrix testDmatrixMultDvector testDmatrixMultDvectorDmatrixNull testDmatrixMultDvectorDvectorNull testDmatrixMultDvectorErrorDimension testMultDmatrix testMultDmatrixNullArgument testMultDmatrixErrorDimensions testMultDeuxDmatrix testTranspose testTransposeDeuxFois testTransposeErrorDimensions 
CXXFLAGS = -Wall -g

all : test

.o : .h .cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.cpp :	.h
	$(CXX) $(CXXFLAGS) -c $@ $< 

clean :
	rm *.o $(EXECTEST) *.txt

exectest : test
	./testDarrayConstr1
	./testDarrayConstr2
	./testDarrayConstr3
	./testDarrayConstrFile
	./testSize
	./testGetData
	./testIsOwner
	./testDisplay
	./testViewCopyFalse
	./testViewCopyTrue
	./testViewCountZero
	./testViewDarrayVide
	./testViewStartCountTropGrand
	./testViewStartNegatif
	./testParenthesesLecture
	./testParenthesesEcriture
	./testPlusDouble
	./testMoinsDouble
	./testMultDouble
	./testDiviseDouble
	./testPlusDarray
	./testMoinsDarray
	./testEgalite
	./testInegaliteTaille
	./testInegaliteValeur
	./testAffectationMemeTaille1
	./testAffectationMemeTaille2
	./testAffectationMemeTaille3
	./testAffectationMemeTaille4
	./testAffectationMemeTaille5
	./testAffectationMemeTaille6
	./testAffectationTailleDifferente1
	./testAffectationTailleDifferente2
	./testAffectationTailleDifferente3
	./testAffectationTailleDifferente4
	./testDarrayPlusDouble
	./testDarrayMoinsDouble
	./testDarrayMultDouble
	./testDarrayDiviseDouble
	./testDoublePlusDarray
	./testDoublePlusDarray
	./testPlusDeuxDarray
	./testMoinsDeuxDarray
	./testOpposeDarray
	./testDvectorConstr1
	./testDvectorConstr2
	./testDvectorConstr3
	./testDvectorConstrFile
	./testProduitScalaireDvector
	./testProduitScalaireDvectorErrorSize
	./testProduitScalaireDvectorNullArgument
	./testDmatrixConstr1
	./testDmatrixConstr2
	./testDmatrixConstr3
	./testParenthesesDmatrixLecture
	./testParenthesesDmatrixEcriture
	./testLinesColumns
	./testAffectationMemeTailleDmatrix
	./testAffectationTailleDifferenteDmatrix
	./testDmatrixMultDvector
	./testDmatrixMultDvectorDmatrixNull
	./testDmatrixMultDvectorDvectorNull
	./testDmatrixMultDvectorErrorDimension
	./testTranspose
	./testTransposeDeuxFois
	./testTransposeErrorDimensions

test : $(TESTS) Dvector.o Darray.o Dmatrix.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr1 Dvector.o Darray.o testDvectorConstr1.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr2 Dvector.o Darray.o testDvectorConstr2.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstr3 Dvector.o Darray.o testDvectorConstr3.o
	$(CXX) $(CXXFLAGS) -o testDvectorConstrFile Dvector.o Darray.o testDvectorConstrFile.o
	$(CXX) $(CXXFLAGS) -o testDarrayConstr1 Darray.o testDarrayConstr1.o
	$(CXX) $(CXXFLAGS) -o testDarrayConstr2 Darray.o testDarrayConstr2.o
	$(CXX) $(CXXFLAGS) -o testDarrayConstr3 Darray.o testDarrayConstr3.o
	$(CXX) $(CXXFLAGS) -o testDarrayConstrFile Darray.o testDarrayConstrFile.o
	$(CXX) $(CXXFLAGS) -o testSize Darray.o testSize.o
	$(CXX) $(CXXFLAGS) -o testGetData Darray.o testGetData.o
	$(CXX) $(CXXFLAGS) -o testIsOwner Darray.o testIsOwner.o
	$(CXX) $(CXXFLAGS) -o testDisplay Darray.o testDisplay.o
	$(CXX) $(CXXFLAGS) -o testViewCopyFalse Darray.o testViewCopyFalse.o
	$(CXX) $(CXXFLAGS) -o testViewCopyTrue Darray.o testViewCopyTrue.o
	$(CXX) $(CXXFLAGS) -o testViewCountZero Darray.o testViewCountZero.o
	$(CXX) $(CXXFLAGS) -o testViewDarrayVide Darray.o testViewDarrayVide.o
	$(CXX) $(CXXFLAGS) -o testViewStartCountTropGrand Darray.o testViewStartCountTropGrand.o
	$(CXX) $(CXXFLAGS) -o testViewStartNegatif Darray.o testViewStartNegatif.o
	$(CXX) $(CXXFLAGS) -o testParenthesesLecture Darray.o testParenthesesLecture.o
	$(CXX) $(CXXFLAGS) -o testParenthesesEcriture Darray.o testParenthesesEcriture.o
	$(CXX) $(CXXFLAGS) -o testPlusDouble Darray.o testPlusDouble.o
	$(CXX) $(CXXFLAGS) -o testMoinsDouble Darray.o testMoinsDouble.o
	$(CXX) $(CXXFLAGS) -o testMultDouble Darray.o testMultDouble.o
	$(CXX) $(CXXFLAGS) -o testDiviseDouble Darray.o testDiviseDouble.o
	$(CXX) $(CXXFLAGS) -o testPlusDarray Darray.o testPlusDarray.o
	$(CXX) $(CXXFLAGS) -o testMoinsDarray Darray.o testMoinsDarray.o
	$(CXX) $(CXXFLAGS) -o testDarrayPlusDouble Darray.o testDarrayPlusDouble.o
	$(CXX) $(CXXFLAGS) -o testDarrayMoinsDouble Darray.o testDarrayMoinsDouble.o
	$(CXX) $(CXXFLAGS) -o testDarrayMultDouble Darray.o testDarrayMultDouble.o
	$(CXX) $(CXXFLAGS) -o testDarrayDiviseDouble Darray.o testDarrayDiviseDouble.o
	$(CXX) $(CXXFLAGS) -o testDoublePlusDarray Darray.o testDoublePlusDarray.o
	$(CXX) $(CXXFLAGS) -o testDoubleMultDarray Darray.o testDoubleMultDarray.o
	$(CXX) $(CXXFLAGS) -o testPlusDeuxDarray Darray.o testPlusDeuxDarray.o
	$(CXX) $(CXXFLAGS) -o testMoinsDeuxDarray Darray.o testMoinsDeuxDarray.o
	$(CXX) $(CXXFLAGS) -o testOpposeDarray Darray.o testOpposeDarray.o
	$(CXX) $(CXXFLAGS) -o testEgalite Darray.o testEgalite.o
	$(CXX) $(CXXFLAGS) -o testInegaliteTaille Darray.o testInegaliteTaille.o
	$(CXX) $(CXXFLAGS) -o testInegaliteValeur Darray.o testInegaliteValeur.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille1 Darray.o testAffectationMemeTaille1.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille2 Darray.o testAffectationMemeTaille2.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille3 Darray.o testAffectationMemeTaille3.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille4 Darray.o testAffectationMemeTaille4.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille5 Darray.o testAffectationMemeTaille5.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTaille6 Darray.o testAffectationMemeTaille6.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferente1 Darray.o testAffectationTailleDifferente1.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferente2 Darray.o testAffectationTailleDifferente2.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferente3 Darray.o testAffectationTailleDifferente3.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferente4 Darray.o testAffectationTailleDifferente4.o
	$(CXX) $(CXXFLAGS) -o testProduitScalaireDvector Dvector.o Darray.o testProduitScalaireDvector.o
	$(CXX) $(CXXFLAGS) -o testProduitScalaireDvectorErrorSize Dvector.o Darray.o testProduitScalaireDvectorErrorSize.o
	$(CXX) $(CXXFLAGS) -o testProduitScalaireDvectorNullArgument Dvector.o Darray.o testProduitScalaireDvectorNullArgument.o
	$(CXX) $(CXXFLAGS) -o testDmatrixConstr1 Dvector.o Dmatrix.o Darray.o testDmatrixConstr1.o
	$(CXX) $(CXXFLAGS) -o testDmatrixConstr2 Dvector.o Dmatrix.o Darray.o testDmatrixConstr2.o
	$(CXX) $(CXXFLAGS) -o testDmatrixConstr3 Dvector.o Dmatrix.o Darray.o testDmatrixConstr3.o
	$(CXX) $(CXXFLAGS) -o testParenthesesDmatrixLecture Dvector.o Dmatrix.o Darray.o testParenthesesDmatrixLecture.o
	$(CXX) $(CXXFLAGS) -o testParenthesesDmatrixEcriture Dvector.o Dmatrix.o Darray.o testParenthesesDmatrixEcriture.o
	$(CXX) $(CXXFLAGS) -o testLinesColumns Dvector.o Dmatrix.o Darray.o testLinesColumns.o
	$(CXX) $(CXXFLAGS) -o testAffectationMemeTailleDmatrix Dvector.o Dmatrix.o Darray.o testAffectationMemeTailleDmatrix.o
	$(CXX) $(CXXFLAGS) -o testAffectationTailleDifferenteDmatrix Dvector.o Dmatrix.o Darray.o testAffectationTailleDifferenteDmatrix.o
	$(CXX) $(CXXFLAGS) -o testDmatrixMultDvector Dvector.o Dmatrix.o Darray.o testDmatrixMultDvector.o
	$(CXX) $(CXXFLAGS) -o testDmatrixMultDvectorDmatrixNull Dvector.o Dmatrix.o Darray.o testDmatrixMultDvectorDmatrixNull.o
	$(CXX) $(CXXFLAGS) -o testDmatrixMultDvectorDvectorNull Dvector.o Dmatrix.o Darray.o testDmatrixMultDvectorDvectorNull.o
	$(CXX) $(CXXFLAGS) -o testDmatrixMultDvectorErrorDimension Dvector.o Dmatrix.o Darray.o testDmatrixMultDvectorErrorDimension.o
	$(CXX) $(CXXFLAGS) -o testMultDmatrix Dvector.o Dmatrix.o Darray.o testMultDmatrix.o
	$(CXX) $(CXXFLAGS) -o testMultDmatrixNullArgument Dvector.o Dmatrix.o Darray.o testMultDmatrixNullArgument.o
	$(CXX) $(CXXFLAGS) -o testMultDmatrixErrorDimensions Dvector.o Dmatrix.o Darray.o testMultDmatrixErrorDimensions.o
	$(CXX) $(CXXFLAGS) -o testMultDeuxDmatrix Dvector.o Dmatrix.o Darray.o testMultDeuxDmatrix.o
	$(CXX) $(CXXFLAGS) -o testTranspose Dvector.o Dmatrix.o Darray.o testTranspose.o
	$(CXX) $(CXXFLAGS) -o testTransposeDeuxFois Dvector.o Dmatrix.o Darray.o testTransposeDeuxFois.o
	$(CXX) $(CXXFLAGS) -o testTransposeErrorDimensions Dvector.o Dmatrix.o Darray.o testTransposeErrorDimensions.o
	
valgrinds: test

