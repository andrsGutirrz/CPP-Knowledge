#include <iostream>
#include <memory>
#include <ctime>
#include "List.h"

int main() {
	
	clock_t begin = clock();
	
	int SIZE = 10000000;
	
	List * ls = new List();
		
	for(int i = 0; i<SIZE; i++){
		ls->addLast(i);
	}
	
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	cout<<"total time: " <<elapsed_secs<<endl;
	
	cin.get();
	delete ls;
	
	return 0;
}
/*
time: https://stackoverflow.com/a/2808527
*/
