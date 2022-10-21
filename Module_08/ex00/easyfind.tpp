#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"

template <typename T>
int easyfind(T container, int to_find) {
    for (int i = 0; i < static_cast<int>(container.size()); i++) {
        if (container[i] == to_find) {
            return (i);
        }
    }
    return (-1);
}

#endif