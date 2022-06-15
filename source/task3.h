#ifndef task3_h
#define task3_h
#include <stdio.h>
#include <string>

namespace test {
	struct ListNode {
		ListNode* prev;
		ListNode* next;
		ListNode* rand; // указатель на произвольный элемент данного списка, либо NULL
		std::string data;
	};

	class List {
	public:
		List();
		~List();
		void Serialize(FILE* file); // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
		void Deserialize(FILE* file); // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
		void pushBack(ListNode* node);
		void clear();
		void setRandList(int source, int target);
		int size();
		ListNode const* getNode(int index);
	private:
		void readLine(FILE* file, std::string& buff);
		ListNode* head;
		ListNode* tail;
		int count;
	};
}

#endif
