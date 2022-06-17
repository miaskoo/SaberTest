#include "task1.h"
#include <stdio.h>

char* test::intToBit(int value) {
	char* result;
	char zero = '0';
	char one = '1';
	char minus = '-';
	auto countCharacters = 1U;
	bool isMinus = value < 0;
	if (isMinus) {
		countCharacters++;
		value *= -1;
	}

	for (int bit = 2; bit <= value; bit *= 2) {
		countCharacters++;
	}
	
	result = new char[countCharacters + 1U];
	result[countCharacters] = '\0';
	for (int n = isMinus ? 1 : 0; n < countCharacters; n++) {
		result[n] = value % 2 ? one : zero;
		value = value >> 1;
	}
	if (isMinus) {
		result[0] = minus;
	}
	return result;
}

void test::printBit(int value) {
	auto bitValue = test::intToBit(value);
	printf("%s\n", bitValue);
	delete[] bitValue;
}
