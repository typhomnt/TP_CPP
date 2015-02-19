.PHONY : doc

all : 
	cd src/ ; make ;
	cd doc/ ; make ;

check : 
	cd ../ ; ./verifier.py TP2_ghorreso_garcia1 ;

test :
	cd src/ ; make ;

doc :
	cd doc/ ; make ;

exectest: 
	cd src/ ; make exectest;

clean:	
	cd doc/ ; make clean ;
	cd src/ ; make clean ;

cleandoc:
	cd doc/ ; make clean ;

cleansource:
	cd src/ ; make clean ;
