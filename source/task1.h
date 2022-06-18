#ifndef task1_h
#define task1_h

namespace test {

	struct bitNode {
		bool data;
		bitNode* next;
	};

	class listBit {
		public:
			listBit();
			~listBit();
			void pushBack(bool value);
			bitNode const* getHead();
		private:
			bitNode* head;
			bitNode* tail;
	};

	listBit* intToBit(unsigned int value);
	void printBit(int value);
}

#endif
