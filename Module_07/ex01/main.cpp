#include "iter.hpp"

template <typename T> void	increment(T &elem) {
	elem += 1;
}

int	main(void) {
	// Testing int array
	{
		int	arr_i[5];

		for (int i = 0; i < 5; i++) {
			arr_i[i] = i;
		}

		for (int i = 0; i < 5; i++) {
			cout << arr_i[i] << endl;
		}

		::iter(arr_i, 5, increment);
		cout << endl;

		for (int i = 0; i < 5; i++) {
			cout << arr_i[i] << endl;
		}
	}
	// Testing char array
	{
		char	arr_i[5];

		for (int i = 0; i < 5; i++) {
			arr_i[i] = 'a' + i;
		}

		for (int i = 0; i < 5; i++) {
			cout << arr_i[i] << endl;
		}

		::iter(arr_i, 5, increment);
		cout << endl;

		for (int i = 0; i < 5; i++) {
			cout << arr_i[i] << endl;
		}
	}
}