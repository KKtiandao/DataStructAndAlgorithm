#include "array.h"
#include <iostream>
int testArray() {
	std::cout<< " testArray "<<std::endl;
	int a[10], i=0;
	for (auto &v : a) {
		v = i;
		i++;
		std::cout<< v << std::endl;
	}
	for (auto v :a) {
		std::cout<< v << std::endl;
	}
	return 0;
}
