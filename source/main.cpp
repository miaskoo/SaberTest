#include <stdio.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

namespace test {
	void sampleTask1();
	void sampleTask2();
	void sampleTask3();
}

int main(int argc, const char * argv[]) {
	//test::sampleTask1();
	//test::sampleTask2();
	//test::sampleTask3();
	return 0;
}

void test::sampleTask1() {
	test::printBit(4);
}

void test::sampleTask2() {
	char data[] = "AAA     BBB      aavvasa     CCCcc";
	test::removeDumps(data);
	printf("%s\n", data);
}

void test::sampleTask3() {
	test::List lists;
	auto nameFile = "somefile.txt";
	
	for (int n = 0; n < 10; n++) {
		test::ListNode* node = new test::ListNode();
		node->data = std::to_string(rand());
		lists.pushBack(node);
	}
	for (int n = 0; n < lists.size(); n++) {
		lists.setRandList(rand() % lists.size(), rand() % lists.size());
	}
	
	auto someFile = fopen(nameFile, "wb");
	lists.Serialize(someFile);
	fclose(someFile);
	
	printf("%s\n", "Before Deserialize");
	for (int n = 0; n < lists.size(); n++) {
		if (auto node = lists.getNode(n)) {
			if (node->rand) {
				printf("%s %s\n", node->data.c_str(), node->rand->data.c_str());
			}
			else {
				printf("%s\n", node->data.c_str());
			}
		}
	}
	
	someFile = fopen(nameFile, "rb");
	lists.Deserialize(someFile);
	fclose(someFile);
	
	printf("%s\n", "After Deserialize");
	for (int n = 0; n < lists.size(); n++) {
		if (auto node = lists.getNode(n)) {
			if (node->rand) {
				printf("%s %s\n", node->data.c_str(), node->rand->data.c_str());
			}
			else {
				printf("%s\n", node->data.c_str());
			}
		}
	}
}
