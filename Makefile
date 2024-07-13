all:
	make update
	make test
	make run
run:
	make compile
	./a.out
	make clean

#helpers
clean:
	rm -rf a.out
	rm -rf .vscode

compile:
	make clean
	g++ -g main.cpp -Wall -fsanitize=undefined -fsanitize=address -I ./include

compile-tests:
	make clean
	g++ -g tests/tests.cpp -Wall -fsanitize=undefined -fsanitize=address -lgtest_main  -lgtest -lpthread -I ./include


# testing related
test:
	make compile-tests
	./a.out
	make clean

setup-tests:
	bash ./scripts/install_gtest.sh
	
testfile:
	bash ./scripts/testcase.sh

# debug related
debug-init:
	make clean
	bash ./scripts/debug.sh
	code .

debug:
	make compile
	gdb a.out
	make clean

debug-tests:
	make compile-tests
	gdb a.out
	make clean

# git related

update:
	git pull https://github.com/alanngo/cpp-starter.git master