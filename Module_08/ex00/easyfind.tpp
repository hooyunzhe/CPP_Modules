#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <class T>
int easyfind(T &container, int to_find) {
    if (std::find(container.begin(), container.end(), to_find) == container.end()) {
        cout << "Error: not found...\n";
        return (-1);
    }
    cout << to_find << " found at index " << std::distance(container.begin(), std::find(container.begin(), container.end(), to_find)) << endl;
    return (to_find);
}

#endif