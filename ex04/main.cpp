#include <iostream>
#include <fstream>
#include <sstream>

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q sed-is-for-losers");
}

int main(int argc, char *argv[]) {
	atexit(&check_leaks);
	if (argc < 4 || std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0) {
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string old_text(argv[2]);
	std::string new_text(argv[3]);

	std::ifstream in_file(argv[1]);
	if (!in_file.is_open()) {
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream out_file(std::string(argv[1]) + ".replace", std::ios::trunc);
	if (!in_file.is_open()) {
		std::cout << "Error: could not create/open file " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}

	std::stringstream ss;
	ss << in_file.rdbuf();
	std::string s = ss.str();
	in_file.close();

	std::size_t pos = 0;
	std::size_t start = 0;

	while ((pos = s.find(old_text, start)) != std::string::npos) {
		out_file << s.substr(start, pos - start) << new_text;
		start = pos + old_text.length();
	}
	out_file << s.substr(start);

	out_file.close();

	return (EXIT_SUCCESS);
}
