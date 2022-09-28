#include <iostream>
#include <cstdlib>

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q hi-this-is-brain");
}

int main() {
	atexit(&check_leaks);
	std::string msg("HI THIS IS BRAIN");
	std::string *msg_ptr = &msg;
	std::string &msg_ref = msg;

	std::cout << &msg << std::endl;
	std::cout << msg_ptr << std::endl;
	std::cout << &msg_ref << std::endl;

	std::cout << std::endl;

	std::cout << msg << std::endl;
	std::cout << *msg_ptr << std::endl;
	std::cout << msg_ref << std::endl;

	return (0);
}
