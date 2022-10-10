#include "word_count.h"
#include <algorithm>

void word_count::statistic_collector::insert_data(string data) {
	stats[data]++;
	++words_count;
}

multimap<int, const string*, greater<int>> word_count::statistic_collector::get_sorted_words() const {
	multimap<int, const string*, greater<int>> multi_map;

	for (const pair<const string, int>& obj : stats)
	{
		multi_map.insert(make_pair(obj.second, &obj.first));
	}

	return multi_map;
}

unsigned int word_count::statistic_collector::get_words_count() const {
	return words_count;
}