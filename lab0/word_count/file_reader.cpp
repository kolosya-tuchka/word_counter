#include "word_count.h"

word_count::file_reader::file_reader() {
	this->file_path = "input.txt";
}

word_count::file_reader::file_reader(string file_path) {
	this->file_path = file_path;
}

void word_count::file_reader::read_data(statistic_collector& stats, const bit_mask& mask) {
	input.open(file_path);
	while (input.good()) {
		string temp;
		getline(input, temp);

		string str;
		for (unsigned char c : temp) {
			if (mask.match(c)) {
				if (str.size() != 0) {
					stats.insert_data(move(str));
				}
			}
			else {
				str += c;
			}
		}
		if (str.size() != 0) {
			stats.insert_data(move(str));
		}
	}
	input.close();
}

void word_count::file_reader::read_data(const string& file_path, statistic_collector& stats, const bit_mask& mask) {
	this->file_path = file_path;
	read_data(stats, mask);
}