#include <iostream>
#include <fstream>
#include <sstream>

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q sed-is-for-losers");
}

int main(int argc, char *argv[]) {
	if (argc < 4 || std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0) {
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string replacee(argv[2]);
	std::string replacer(argv[3]);

	std::ifstream in_file(argv[1]);
	if (!in_file.is_open()) {
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream out_file(std::string(argv[1]) + ".replace", std::ios::trunc);
	if (!in_file.is_open()) {
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return (EXIT_FAILURE);
	}

	std::stringstream ss;
	ss << in_file.rdbuf();
	std::string s = ss.str();
	in_file.close();

	std::size_t pos = 0;
	std::size_t start = 0;

	while ((pos = s.find(replacee, start)) != std::string::npos) {
		out_file << s.substr(start, pos - start) << replacer;
		start = pos + replacee.length();
	}
	out_file << s.substr(start);

	out_file.close();

	return (EXIT_SUCCESS);
}
