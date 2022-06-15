#include "task1.h"
#include <stdio.h>

char* test::intToBit(int value) {
	char* result;
	char zero = '0';
	char one = '1';
	char minus = '-';
	auto countCharacters = 1U;
	bool isMinus = false;
	if (value < 0) {
		countCharacters++;
		value *= -1;
		isMinus = true;
	}
	
	int bit = 1;
	while (bit < value) {
		auto nextBit = bit * 2;
		if (nextBit > value) {
			break;
		}
		bit = nextBit;
		countCharacters++;
	}
	result = new char[countCharacters + 1U];
	result[countCharacters] = '\0';
	auto indexChar = countCharacters - 1U;
	while(bit) {
		if (value >= bit) {
			result[indexChar] = one;
			value -= bit;
		}
		else {
			result[indexChar] = zero;
		}
		bit /= 2;
		indexChar--;
	}
	if (isMinus) {
		result[indexChar] = minus;
	}
	return result;
}

void test::printBit(int value) {
	auto bitValue = test::intToBit(value);
	printf("%s\n", bitValue);
	delete[] bitValue;
}
