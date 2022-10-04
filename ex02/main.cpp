#include <iostream>

int main() {
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
