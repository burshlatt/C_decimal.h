CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE
TEST_LIBS = -lcheck -lm -lpthread

all: test gcov_report

decimal.a: clean
	$(CC) $(CFLAGS) -c s21_*.c help_function.c
	ar rcs decimal.a *.o

test: decimal.a
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
	$(CC) unit_test.o decimal.a $(TEST_LIBS) -o decimal
	./decimal

main: decimal.a
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) main.o decimal.a $(TEST_LIBS) -o decimal
	./decimal

gcov_report: decimal.a
	$(CC) $(FLAGS) --coverage unit_test.c s21_*.c decimal.a $(TEST_LIBS) -o gcov_test
	./gcov_test
	lcov -t "decimal" -o decimal.info -c -d .
	genhtml -o report decimal.info
	open ./report/index.html

clean:
	rm -rf test main *.o *.a *.gcno *.gcda *.info report gcov_test decimal
