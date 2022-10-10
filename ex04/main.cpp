#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	if (std::strlen(argv[1]) == 0) {
		std::cout << "Filename cannot be empty" << std::endl;
		return (EXIT_FAILURE);
	}
	if (std::strlen(argv[2]) == 0) {
		std::cout << "Text to be replaced cannot be empty" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string old_text(argv[2]);
	std::string new_text(argv[3]);

	std::ifstream infile(argv[1]);
	if (infile.fail()) {
		std::cout << "Error: could not open file: `" << argv[1] << "`" << std::endl;
		return (EXIT_FAILURE);
	}
	std::ofstream outfile((std::string(argv[1]) + ".replace").c_str(), std::ios::trunc);
	if (outfile.fail()) {
		std::cout << "Error: could not create/open file: `" << argv[1] << ".replace" << "`" << std::endl;
		return (EXIT_FAILURE);
	}

	std::stringstream ss;
	ss << infile.rdbuf();
	infile.close();
	std::string infile_text = ss.str();

	std::size_t pos = 0;
	std::size_t start = 0;

	while ((pos = infile_text.find(old_text, start)) != std::string::npos) {
		outfile << infile_text.substr(start, pos - start) << new_text;
		start = pos + old_text.length();
	}
	outfile << infile_text.substr(start);
	outfile.close();

	return (EXIT_SUCCESS);
}
