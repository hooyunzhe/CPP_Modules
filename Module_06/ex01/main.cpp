#include "Data.hpp"
#include "Serialization.hpp"

// Testing if serialization and deserialization functions preserves the pointer
int	main(void) {
	Data	*data;
	Data	*s_data;

	data = new Data("Some Data");
	s_data = deserialize(serialize(data));
	cout << YELLOW "Original\nData: " << data << "\nData._var: " << data->getVar() << RESET << endl << endl;
	cout << CYAN "Post serialization/deserialization\nData: " << s_data << "\nData._var: " << s_data->getVar() << RESET << endl << endl;
	cout << MAGENTA "Comparison data == s_data: " RESET << ((data == s_data) ? GREEN "TRUE" : RED "FALSE") << RESET << endl;
	delete data;
}