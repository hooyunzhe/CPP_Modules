#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

using std::string;

class	Contact {
	public:
		string	first_name;
		string	last_name;
		string	nick_name;
		string	phone_number;
		string	darkest_secret;

		Contact();
		Contact(string f_n, string l_n, string n_n, string p_n, string d_s);
};

#endif