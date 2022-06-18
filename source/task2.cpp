#include "task2.h"

void test::removeDumps(char *str) {
	if (!str) {
		return;
	}
	auto indexChar = 0U;
	int indexNextChar = 1U;
	auto currentChar = str[indexChar];
	while(currentChar != '\0') {
		if (currentChar != str[indexNextChar]) {
			indexChar++;
			str[indexChar] = str[indexNextChar];
			currentChar = str[indexChar];
		}
		indexNextChar++;
	}
}
