#include "PhoneBook.hpp"

std::string	get_ordinal_num(int i) {
	std::string	ord_nums[8] = {"first", "second", "third", "forth", "fifth", "sixth", "seventh", "eighth"};
	return (ord_nums[i]);
}

void	add_contact(PhoneBook &pb) {
	std::string	fields[5];
	std::string	prompts[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};

	for (int i = 0; fields[i].empty(); i++) {
		while (fields[i].empty()) {
			std::cout << prompts[i];
			getline(std::cin, fields[i]);
		}
	}
	pb.add_contact(fields[0], fields[1], fields[2], fields[3], fields[4]);
}

void	search_contact(PhoneBook pb) {
	std::string	input;

	while (input.empty()) {
		std::cout << "Index of contact to display: ";
		getline(std::cin, input);
	}
	if (input.find_first_not_of("0123456789") != std::string::npos) {
		std::cout << "PhoneBook: invalid index: " << input << '\n';
	}
	else if (std::stoi(input) < 0 || std::stoi(input) > 7){
		std::cout << "PhoneBook: index out of range: " << input << '\n';
	}
	else if (pb.contacts[std::stoi(input)].first_name.empty()) {
		std::cout << "PhoneBook: the " << get_ordinal_num(std::stoi(input)) << " contact is empty\n";
	}
	else {
		pb.search_contact(std::stoi(input));
	}
}

int	main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	std::string	input;
	PhoneBook 	pb;

	input = "";
	while (input.compare("EXIT")) {
		std::cout << "PhoneBook % ";
		if (!getline(std::cin, input)) {
			std::cout << "\n";
			break;
		}
		if (input.compare("ADD") == 0) {
			add_contact(pb);
		}
		else if (input.compare("SEARCH") == 0) {
			pb.display_contacts();
			search_contact(pb);
		}
	}
	std::cout << "Thank you for using PhoneBook!\n";
}