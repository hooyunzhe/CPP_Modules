#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

using std::string;

class	PhoneBook {
	public:
		Contact	contacts[8];
		int		oldest_contact;

		PhoneBook();

		void	add_contact(string f_n, string l_n, string n_n, string p_n, string d_s);
		void	print_field(string field);
		void	print_contact(Contact contact);
		void	display_contacts();
		void	search_contact(int index);
};

#endif