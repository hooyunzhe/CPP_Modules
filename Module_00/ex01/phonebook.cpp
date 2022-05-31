#include "PhoneBook.hpp"
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;

Contact::Contact() {
	first_name = "";
	last_name = "";
	nick_name = "";
	phone_number = "";
	darkest_secret = "";
}

Contact::Contact(string f_n, string l_n, string n_n, string p_n, string d_s) {
	first_name = f_n;
	last_name = l_n;
	nick_name = n_n;
	phone_number = p_n;
	darkest_secret = d_s;
}

PhoneBook::PhoneBook() {
	oldest_contact = 0;
}

void	PhoneBook::add_contact(string f_n, string l_n, string n_n, string p_n, string d_s) {
	contacts[oldest_contact] = Contact(f_n, l_n, n_n, p_n, d_s);
	oldest_contact = (oldest_contact + 1) % 8;
}

void	PhoneBook::print_field(string field) {
	for (int i = field.length(); i < 10; i++) {
		cout << ' ';
	}
	cout << field.substr(0, 9);
	if (field.length() > 10)
		cout << '.';
}

void	PhoneBook::print_contact(Contact contact) {
	print_field(contact.first_name);
	cout << '|';
	print_field(contact.last_name);
	cout << '|';
	print_field(contact.nick_name);
}

void	PhoneBook::display_contacts() {
	cout << "     Index First Name  Last Name   Nickname" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < 8; i++) {
		print_field(std::to_string(i));
		cout << '|';
		print_contact(contacts[i]);
		cout << endl;
	}
}

void	PhoneBook::search_contact(int index) {
	cout << "First name:     " << contacts[index].first_name << endl;
	cout << "Last name:      " << contacts[index].last_name << endl;
	cout << "Nickname:       " << contacts[index].nick_name << endl;
	cout << "Phone number:   " << contacts[index].phone_number << endl;
	cout << "Darkest secret: " << contacts[index].darkest_secret << endl;
}

string	get_ordinal_num(int i) {
	string	ord_nums[8] = {"first", "second", "third", "forth", "fifth", "sixth", "seventh", "eighth"};
	return (ord_nums[i]);
}

void	add_contact(PhoneBook &pb) {
	string	fields[5];
	string	prompts[5] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};

	for (int i = 0; fields[i].empty(); i++) {
		while (fields[i].empty()) {
			cout << prompts[i];
			if (!getline(cin, fields[i])) {
				cout << endl;
				return ;
			}
		}
	}
	pb.add_contact(fields[0], fields[1], fields[2], fields[3], fields[4]);
}

void	search_contact(PhoneBook pb) {
	string	input;

	while (input.empty()) {
		cout << "Index of contact to display: ";
		if (!getline(cin, input)) {
			cout << endl;
			return ;
		}
	}
	if (input.find_first_not_of("0123456789") != string::npos) {
		cout << "PhoneBook: invalid index: " << input << endl;
	}
	else if (stoi(input) < 0 || stoi(input) > 7){
		cout << "PhoneBook: index out of range: " << input << endl;
	}
	else if (pb.contacts[stoi(input)].first_name.empty()) {
		cout << "PhoneBook: the " << get_ordinal_num(stoi(input)) << " contact is empty\n";
	}
	else {
		pb.search_contact(stoi(input));
	}
}

int	main(void) {
	string	input;
	PhoneBook 	pb;

	input = "";
	while (input.compare("EXIT")) {
		cout << "PhoneBook % ";
		if (!getline(cin, input)) {
			cout << endl;
			break;
		}
		if (input.compare("ADD") == 0) {
			add_contact(pb);
		}
		else if (input.compare("SEARCH") == 0) {
			pb.display_contacts();
			search_contact(pb);
		}
		else if (input.compare("EXIT") > 0 && input.empty() == 0) {
			cout << "PhoneBook: invalid command: " << input << endl;
			cout << "PhoneBook: usage: ADD, SEARCH, EXIT\n";
		}
	}
	cout << "Thank you for using PhoneBook!\n";
}