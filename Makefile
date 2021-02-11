# Reference: https://makefiletutorial.com

CPP=g++ --std=c++11

all: fibonacci-recursive fibonacci-iterative selection_sort

fibonacci-recursive: fibonacci-recursive.cpp
	$(CPP) fibonacci-recursive.cpp -o fibonacci-recursive

fibonacci-iterative: fibonacci-iterative.cpp
	$(CPP) fibonacci-iterative.cpp -o fibonacci-iterative

selection_sort: selection_sort.cpp
	$(CPP) selection_sort.cpp -o selection_sort
