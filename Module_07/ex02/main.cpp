#include "Array.tpp"

int	main(void) {
    // Empty array
    Array<int>  empty_arr;

    try {
        cout << empty_arr[0] << endl;
    }
    catch (Array<int>::IndexOutOfRange &e) {
        cout << e.what();
    }

    // Int Array
    Array<int>  int_arr(5);

    for (int i = 0; i < int_arr.size(); i++) {
        int_arr[i] = i;
    }
    cout << int_arr;
    cout << MAGENTA "Array Size: " << int_arr.size() << endl;
    try {
        cout << int_arr[5] << endl;
    }
    catch (Array<int>::IndexOutOfRange &e) {
        cout << e.what();
    }

    // Char Array
    Array<char> char_arr(5);

    cout << char_arr;
    for (int i = 0; i < char_arr.size(); i++) {
        char_arr[i] = 'a' + i;
    }
    cout << char_arr;

    // Copy constructor
    Array<char> char_arr_copy(char_arr);

    char_arr_copy[0] = '4';
    char_arr_copy[1] = '2';
    cout << char_arr_copy;
    cout << char_arr;

    // Copy assignment operator
    Array<char> char_arr_assigned;

    char_arr_assigned = char_arr;
    char_arr_assigned[0] = '4';
    char_arr_assigned[1] = '2';
    cout << char_arr_assigned;
    cout << char_arr;

    // Copy to non-empty Array
    Array<char> char_arr_to_be_copied(5);

    for (int i = 0; i < char_arr_to_be_copied.size(); i++) {
        char_arr_to_be_copied[i] = 'f' + i;
    }
    cout << char_arr_to_be_copied;
    char_arr_to_be_copied = char_arr;
    cout << char_arr_to_be_copied;

    // Copy to smaller Array
    Array<char> char_arr_small(2);

    char_arr_small[0] = '4';
    char_arr_small[1] = '2';
    cout << char_arr_small;
    char_arr_small = char_arr;
    cout << char_arr_small;

    // Copy to bigger Array
    Array<char> char_arr_big(10);
    
    for (int i = 0; i < char_arr_big.size(); i++) {
        char_arr_big[i] = '0' + i;
    }
    cout << char_arr_big;
    char_arr_big = char_arr;
    cout << char_arr_big;
}