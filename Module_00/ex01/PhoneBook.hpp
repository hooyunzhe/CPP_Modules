#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class	PhoneBook {
	public:
		Contact	contacts[8];
		int		oldest_contact;

		PhoneBook() {
			oldest_contact = 0;
		}

		void	add_contact(std::string f_n, std::string l_n, std::string n_n, std::string p_n, std::string d_s) {
			contacts[oldest_contact] = Contact(f_n, l_n, n_n, p_n, d_s);
			oldest_contact = (oldest_contact + 1) % 8;
		}

		void	print_field(std::string field) {
			for (int i = field.length(); i < 10; i++) {
				std::cout << ' ';
			}
			std::cout << field.substr(0, 9);
			if (field.length() > 10)
				std::cout << '.';
		}

		void	print_contact(Contact contact) {
			print_field(contact.first_name);
			std::cout << '|';
			print_field(contact.last_name);
			std::cout << '|';
			print_field(contact.nick_name);
		}

		void	display_contacts() {
			for (int i = 0; i < 8; i++) {
				print_field(std::to_string(i));
				std::cout << '|';
				print_contact(contacts[i]);
				std::cout << '\n';
			}
		}

		void	search_contact(int index) {
			std::cout << "First name:     " << contacts[index].first_name << '\n';
			std::cout << "Last name:      " << contacts[index].last_name << '\n';
			std::cout << "Nickname:       " << contacts[index].nick_name << '\n';
			std::cout << "Phone number:   " << contacts[index].phone_number << '\n';
			std::cout << "Darkest secret: " << contacts[index].darkest_secret << '\n';
		}
};

#endif