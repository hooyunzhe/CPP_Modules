#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T> void	iter(T arr[], int len, void (*func) (T &elem)) {
	for (int i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif