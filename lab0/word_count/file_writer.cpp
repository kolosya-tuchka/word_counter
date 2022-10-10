#include "word_count.h"

word_count::file_writer::file_writer() {
	file_path = "output.csv";
}

word_count::file_writer::file_writer(string file_path) {
	this->file_path = file_path;
}

void word_count::file_writer::write_data(const statistic_collector& stats) {
	output.open(file_path);
	unsigned int words_count = stats.get_words_count();
	multimap<int, const string*, greater<int>> words = stats.get_sorted_words();

	for (const pair<const int, const string*>& word : words) {
		float freq = (float)word.first / (float)words_count;
		string str = *word.second + ";" + to_string(word.first) + ";" + to_string(freq * 100) + '%';
		output << str << endl;
	}

	output.close();
}

void word_count::file_writer::write_data(string file_path, const statistic_collector& stats) {
	this->file_path = file_path;
	write_data(stats);
}