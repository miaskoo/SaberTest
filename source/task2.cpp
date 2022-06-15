#include "task2.h"

void test::removeDumps(char *str) {
	if (!str) {
		return;
	}
	char endSymbol = '\0';
	
	auto indexChar = 0U;
	auto currentChar = str[indexChar];
	while(currentChar != endSymbol) {
		auto indexNextChar = indexChar + 1U;
		auto nextChar = str[indexNextChar];
		while (currentChar == nextChar) {
			int tempNumChar = indexNextChar;
			while(str[tempNumChar] != endSymbol) {
				str[tempNumChar] = str[tempNumChar + 1U];
				tempNumChar++;
			}
			nextChar = str[indexNextChar];
		}
		indexChar++;
		currentChar = str[indexChar];
	}
}
