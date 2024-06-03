all:
	make test
	make run
run:
	make clean
	g++ -g main.cpp -Wall -fsanitize=undefined -fsanitize=address -I ./include
	./a.out
	make clean

clean:
	rm -rf a.out
	rm -rf .vscode


# testing related
test:
	g++ -g tests/tests.cpp -Wall -fsanitize=undefined -fsanitize=address -lgtest_main  -lgtest -lpthread -I ./include
	./a.out
	make clean

testcase:
	bash ./scripts/testcase.sh

# debug related
debug-start:
	bash ./scripts/debug.sh

ENTRY_POINT=tests/tests
debug:
	g++ -g $(ENTRY_POINT).cpp -Wall -fsanitize=undefined -fsanitize=address -lgtest_main  -lgtest -lpthread -I ./include
	gdb a.out