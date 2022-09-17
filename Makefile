CPP=g++ --std=c++17
#CPP += -O3
CPP += -g


all: bin/hw1/task1 bin/hw1/task2 bin/hw1/task3 bin/hw1/task4 bin/hw1/task5 bin/hw1/task6

bin:
	mkdir -p "bin" "bin/hw1"

bin/hw1/task1: bin src/hw1/task1.cpp
	$(CPP) -o bin/hw1/task1 src/hw1/task1.cpp

bin/hw1/task2: bin src/hw1/task2.cpp
	$(CPP) -o bin/hw1/task2 src/hw1/task2.cpp

bin/hw1/task3: bin src/hw1/task3.cpp
	$(CPP) -o bin/hw1/task3 src/hw1/task3.cpp

bin/hw1/task4: bin src/hw1/task4.cpp
	$(CPP) -o bin/hw1/task4 src/hw1/task4.cpp

bin/hw1/task5: bin src/hw1/task5.cpp
	$(CPP) -o bin/hw1/task5 src/hw1/task5.cpp

bin/hw1/task6: bin src/hw1/task6.cpp
	$(CPP) -o bin/hw1/task6 src/hw1/task6.cpp

clean:
	rm -rf bin/*
