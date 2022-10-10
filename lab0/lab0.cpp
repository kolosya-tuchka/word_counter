#include "word_count/word_count.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	word_count* wcount;

	switch (argc) {
	case 1: {
		wcount = new word_count();
		break;
	}
	case 2: {
		wcount = new word_count(argv[1]);
		break;
	}
	case 3: {
		wcount = new word_count(argv[1], argv[2]);
		break;
	}
	default: {
		cerr << "Invalid count of arguments!";
		return -1;
	}
	}

	wcount->read_data();
	wcount->write_data();

	cout << "Success!\n";
	delete wcount;
	return 0;
}
