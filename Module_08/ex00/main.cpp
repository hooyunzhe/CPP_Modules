#include "easyfind.tpp"

int main(void) {
    // Find element in different types of containers
    std::array<int, 5>  arr = {42, 4242, 42};
    std::deque<int> dq(arr.begin(), arr.end());
    std::forward_list<int> f_list(arr.begin(), arr.end());
    std::list<int> list(arr.begin(), arr.end());
    std::vector<int> vect(arr.begin(), arr.end());
    int to_find;

    // Search for the first occurrence
    to_find = 42;
    easyfind(arr, to_find);
    easyfind(dq, to_find);
    easyfind(f_list, to_find);
    easyfind(list, to_find);
    easyfind(vect, to_find);

    // If not found
    to_find = 424242;
    easyfind(arr, to_find);
    easyfind(dq, to_find);
    easyfind(f_list, to_find);
    easyfind(list, to_find);
    easyfind(vect, to_find);
}