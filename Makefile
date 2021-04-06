# Reference: https://makefiletutorial.com

CPP=g++ --std=c++11
CC=gcc --std=c11

all: fibonacci-recursive fibonacci-iterative fibonacci-iterative-ans selection_sort merge_sort quick_sort graph_main

clean:
	rm -f *.o fibonacci-recursive fibonacci-iterative fibonacci-iterative-ans selection_sort merge_sort quick_sort graph_main *.o

fibonacci-recursive: fibonacci-recursive.cpp
	$(CPP) fibonacci-recursive.cpp -o fibonacci-recursive

fibonacci-iterative: fibonacci-iterative.cpp
	$(CPP) fibonacci-iterative.cpp -o fibonacci-iterative

fibonacci-iterative-ans: fibonacci-iterative-ans.cpp
	$(CPP) fibonacci-iterative-ans.cpp -o fibonacci-iterative-ans

selection_sort: selection_sort.cpp
	$(CPP) selection_sort.cpp -o selection_sort

merge_sort: merge_sort.cpp
	$(CPP) merge_sort.cpp -o merge_sort

quick_sort: quick_sort.cpp
	$(CPP) quick_sort.cpp -o quick_sort

graph.o: graph.h graph.c
	$(CC) graph.c -o graph.o
graph_main: graph_main.c graph.o graph.h
	$(CC) graph_main.c graph.o -o graph_main
