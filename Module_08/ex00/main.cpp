#include "easyfind.tpp"

int main(void) {
    // std::array<int, 5>  int_arr = {0, 1, 2, 3, 4};
    std::array<char, 5>  char_arr = {'a', 'b', 'c', 'd', 'e'};
    int to_find;
    int found;

    to_find = 4;
    // found = easyfind(int_arr, to_find);
    found = easyfind(char_arr, to_find);
    if (found == -1) {
        cout << "Error: not found...\n";
    }
    else {
        cout << to_find << " found at index " << found << endl;
    }
}