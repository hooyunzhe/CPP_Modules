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

		void	add_contact(std::string f_n, std::string l_n, std::string n_n, long p_n, std::string d_s) {
			contacts[oldest_contact] = Contact(f_n, l_n, n_n, p_n, d_s);
			oldest_contact = (oldest_contact + 1) % 8;
		}
};

#endif