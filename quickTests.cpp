#include <iostream>

using namespace std;

int main() {
    int number;
    cout << "Enter a number: "; // Using << to insert a string into the output stream
    cin >> number;               // Using >> to extract a number from the input stream
    cout << "You entered " << number << std::endl; // Using << to insert strings and number into the output stream
    return 0;
}
