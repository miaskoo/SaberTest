#include "task2.h"

void test::removeDumps(char *str) {
	if (!str) {
		return;
	}
	char endSymbol = '\0';
	
	auto indexChar = 0U;
	auto currentChar = str[indexChar];
	int indexNextChar = 1U;
	while(currentChar != endSymbol) {
		while (currentChar == str[indexNextChar]) {
			indexNextChar++;
		}
		indexChar++;
		str[indexChar] = str[indexNextChar];
		currentChar = str[indexChar];
	}
}
