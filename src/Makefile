GXX = g++ -std=c++17
CHECKFLAGS = -Wall -Werror -Wextra
SRC = matrix_oop.cc
TEST_SRC = ../tests/test.cc
TEST_LIBS = -lgtest -pthread 
OBJ = $(SRC:%.cpp=%.o)

all: clean matrix_oop.a test

test: matrix_oop.a
	$(GXX)  $(TEST_SRC) $(SRC)  $(CHECKFLAGS) $(TEST_LIBS) -o test
	./test

matrix_oop.a: $(OBJ)
	ar rcs matrix_opp.a $(OBJ)

clean:
	rm -rf *.o *.a a.out *.css *.html gcov_test *.gcda *.gcno test 

gcov_report: matrix_oop.a
	$(GXX) --coverage $(TEST_SRC) $(SRC) matrix_opp.a $(TEST_LIBS) -o gcov_test $(shell pkg-config --libs --cflags check)
	./gcov_test
	gcovr -r . --html --html-details -o matrix.html
	open ./matrix.html

html:
	open ../documentation/html/annotated.html

style: 
	clang-format -style=google -i *.cc
	clang-format -style=google -i *.h

clang-format: 
	clang-format -style=google -n *.cc
	clang-format -style=google -n *.h

leaks: matrix_oop.a
	$(GXX)  $(TEST_SRC) $(SRC)  $(CHECKFLAGS) -g -fsanitize=address $(TEST_LIBS) -o test
	./test

valgrind: test
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./test