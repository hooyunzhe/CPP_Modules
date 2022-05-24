#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact {
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		long		phone_number;
		std::string	darkest_secret;

		Contact() {
			first_name = "";
			last_name = "";
			nick_name = "";
			phone_number = 0;
			darkest_secret = "";
		}

		Contact(std::string f_n, std::string l_n, std::string n_n, long p_n, std::string d_s) {
			first_name = f_n;
			last_name = l_n;
			nick_name = n_n;
			phone_number= p_n;
			darkest_secret = d_s;
		}
};

#endif