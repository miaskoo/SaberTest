#include "task3.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace test;

int List::size() {
	return count;
}

void List::setRandList(int source, int target) {
	if (source < 0 || target < 0) {
		return;
	}
	if (source > count || target > count) {
		return;
	}
	ListNode* sourceNode = head;
	ListNode* targetNode = head;
	while (source > 0) {
		sourceNode = sourceNode->next;
		source--;
	}
	while (target > 0) {
		targetNode = targetNode->next;
		target--;
	}
	sourceNode->rand = targetNode;
}

void List::Serialize(FILE *file) {
	if (!head || !tail || !file) {
		return;
	}
	char endLine = '\n';
	
	auto currentNode = head;
	unsigned int numElement = 0;
	fputs(std::to_string(count).c_str(), file);
	fputc(endLine, file);
	while(currentNode) {
		fputs(currentNode->data.c_str(), file);
		fputc(endLine, file);
		if (currentNode->prev) {
			*reinterpret_cast<int*>(&currentNode->prev) = numElement;
		}
		numElement++;
		currentNode = currentNode->next;
	}
	currentNode = head;
	while(currentNode) {
		if (currentNode->rand) {
			if (currentNode->rand->prev) {
				fputs(std::to_string(*reinterpret_cast<int*>(&currentNode->rand->prev)).c_str(), file);
			}
			else {
				fputs("0", file);
			}
		}
		fputc(endLine, file);
		currentNode = currentNode->next;
	}
	currentNode = head;
	while(currentNode) {
		if (currentNode->next) {
			currentNode->next->prev = currentNode;
		}
		currentNode = currentNode->next;
	}
}

void List::readLine(FILE* file, std::string &buff) {
	char oneChar;
	char endLine = '\n';
	while ((oneChar = fgetc(file)) != EOF) {
		if (oneChar == endLine) {
				break;
		}
		buff += oneChar;
	}
}

void List::Deserialize(FILE* file) {
	if (!file) {
		return;
	}
	clear();
	
	std::string buff;
	
	unsigned int countNodes = 0;
	std::vector<ListNode*> nodes;
	
	readLine(file, buff);
	if (!buff.empty()) {
		countNodes = std::stoi(buff);
	}
	nodes.reserve(countNodes);
	buff.clear();
	
	for (int n = 0; n < countNodes; n++) {
		readLine(file, buff);
		if (buff.empty()) {
			continue;
		}
		ListNode* node = new ListNode();
		node->data = buff;
		pushBack(node);
		nodes.push_back(node);
		buff.clear();
	}
	
	for (int n = 0; n < countNodes; n++) {
		readLine(file, buff);
		if (buff.empty()) {
			continue;
		}
		int targetRand = std::stoi(buff);
		if (targetRand < nodes.size()) {
			nodes[n]->rand = nodes[targetRand];
		}
		buff.clear();
	}
}

List::List() {
	head = nullptr;
	tail = nullptr;
	count = 0;
}

test::List::~List() {
	clear();
}

void List::clear() {
	auto currentNode = head;
	while(currentNode) {
		auto nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	count = 0;
}

void List::pushBack(ListNode *node) {
	if (!node) {
		return;
	}
	if (head) {
		auto needNode = head;
		while (needNode->next) {
			needNode = needNode->next;
		}
		needNode->next = node;
		node->prev = needNode;
		node->next = nullptr;
		node->rand = nullptr;
	}
	else {
		head = node;
		node->prev = nullptr;
		node->next = nullptr;
		node->rand = nullptr;
	}
	tail = node;
	count++;
}

ListNode const* List::getNode(int index) {
	if (index < 0 || index > count) {
		return nullptr;
	}
	ListNode* node = head;
	while (index > 0) {
		node = node->next;
		index--;
	}
	return node;
}
