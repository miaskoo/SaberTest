#include "task1.h"
#include <stdio.h>
#include <stddef.h>

using namespace test;

listBit::listBit() {
	head = nullptr;
	tail = nullptr;
}

listBit::~listBit() {
	while (head) {
		auto next = head->next;
		delete head;
		head = head->next;
	}
}

void listBit::pushBack(bool value) {
	if (tail) {
		tail->next = new bitNode();
		tail = tail->next;
		tail->data = value;
		tail->next = nullptr;
	}
	else {
		head = new bitNode();
		tail = head;
		tail->data = value;
		tail->next = nullptr;
	}
}

bitNode const* listBit::getHead() {
	return head;
}

listBit* test::intToBit(unsigned int value) {
	listBit* list = new listBit;
	auto startValue = value;
	do {
		list->pushBack(value & 1);
		value = value >> 1;
	}
	while (value);

	return list;
}

void test::printBit(int value) {
	bool isMinus = value < 0;
	if (isMinus) {
		value *= -1;
	}
	auto list = test::intToBit(static_cast<unsigned int>(value));
	auto bits = list->getHead();
	const char* zero = "0";
	const char* one = "1";
	const char* minus = "-";
	if (isMinus) {
		printf("%s", minus);
	}
	while (bits) {
		printf("%s", bits->data ? one : zero);
		bits = bits->next;
	}
	printf("\n");
	
	delete list;
}
