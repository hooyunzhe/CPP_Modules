#include "PhoneBook.hpp"

int	main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	Contact c1("John", "Doe", "Jo", 1234567890, "Loves Pipeapple on Pizza");

	std::cout << c1.first_name << '\n';
	std::cout << c1.last_name << '\n';
	std::cout << c1.nick_name << '\n';
	std::cout << c1.phone_number << '\n';
	std::cout << c1.darkest_secret << '\n';

	PhoneBook pb;

	pb.add_contact("Jane", "Doe", "Janny", 987654321, "Hates Pipeapple on Pizza");
	std::cout << pb.contacts[0].first_name << '\n';
	std::cout << pb.contacts[0].last_name << '\n';
	std::cout << pb.contacts[0].nick_name << '\n';
	std::cout << pb.contacts[0].phone_number << '\n';
	std::cout << pb.contacts[0].darkest_secret << '\n';
}