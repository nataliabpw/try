all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	@bin/gauss dane/A dane/b; \
	if [ $$? -eq 0 ] ; then \
		echo "Test 1 - poprawne dane 3x3: OK."; \
	else \
		echo "Test 1 - poprawne dane 3x3: BŁĄD"; \
	fi
	@bin/gauss dane/A2 dane/b2; \
	if [ $$? -eq 0 ] ; then \
		echo "Test 2 - weryfikacja selekcji elementu diagonalnego: OK."; \
	else \
		echo "Test 2 - weryfikacja selekcji elementu diagonalnego: BŁĄD"; \
	fi
	@bin/gauss dane/A3 dane/b3; \
	if [ $$? -eq 3 ] ; then \
	        echo "Test 3 - macierz osobliwa: OK."; \
	else \
	        echo "Test 3 - macierz osobliwa: BŁĄD"; \
	fi
	@bin/gauss dane/A4 dane/b4; \
	if [ $$? -eq 2 ] ; then \
		echo "Test 4 - niepoprawne dane: OK."; \
	else \
		echo "Test 4 - niepoprawne dane: BŁĄD"; \
	fi
	@bin/gauss dane/A5 dane/b5; \
	if [ $$? -eq 3 ] ; then \
		echo "Test 5 - nierozwiązywalna z zerami: OK."; \
	else \
		echo "Test 5 - nierozwiązywalna z zerami: BŁĄD."; \
	fi
