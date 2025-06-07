std ?= 17
memory = -fsanitize=undefined -fsanitize=address
googletest = -lgtest_main -lgtest -lpthread
default = -Wall -I ./include

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
	g++ -g main.cpp $(default) $(memory) -std=c++$(std)

compile-tests:
	make clean
	g++ -g tests/tests.cpp $(default) $(memory) $(googletest) -std=c++$(std)


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
predebug:
	make clean
	bash ./scripts/debug.sh

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
	code .
