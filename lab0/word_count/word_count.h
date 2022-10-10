#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

class word_count {
public:
	word_count();

	word_count(string input_file_path);

	word_count(string input_file_path, string output_file_path);

	void write_data();

	void write_data(string file_path);

	void read_data();

	void read_data(string file_path);

	~word_count();
private:
	class statistic_collector {
	public:
		void insert_data(string data);

		multimap<int, const string*, greater<int>> get_sorted_words() const;

		unsigned int get_words_count() const;
	private:
		map<string, int> stats;
		unsigned int words_count{ 0 };
	};

	class bit_mask {
	public:
		bit_mask();

		bool match(unsigned int degree) const;
	private:
		const unsigned int base{ 64 };
		vector<unsigned long long> mask;
	};

	class file_reader {
	public:
		string file_path;

		file_reader();

		file_reader(string file_path);

		void read_data(statistic_collector& stats, const bit_mask& mask);

		void read_data(const string& file_path, statistic_collector& stats, const bit_mask& mask);
	private:
		ifstream input;
	};

	class file_writer {
	public:
		string file_path;

		file_writer();

		file_writer(string file_path);

		void write_data(const statistic_collector& stats);

		void write_data(string file_path, const statistic_collector& stats);
	private:
		ofstream output;
	};

	statistic_collector statistics;
	file_reader freader;
	file_writer fwriter;
	bit_mask mask;
};
