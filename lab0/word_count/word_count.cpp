#include "word_count.h"
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

word_count::word_count() {
}

word_count::word_count(string input_file_path) {
	freader.file_path = input_file_path;
}

word_count::word_count(string input_file_path, string output_file_path) {
	freader.file_path = input_file_path;
	fwriter.file_path = output_file_path;
}

void word_count::write_data() {
	fwriter.write_data(statistics);
}

void word_count::write_data(string file_path) {
	fwriter.write_data(file_path, statistics);
}

void word_count::read_data() {
	freader.read_data(statistics, mask);
}

void word_count::read_data(string file_path) {
	freader.read_data(file_path, statistics, mask);
}

word_count::~word_count() {
}
