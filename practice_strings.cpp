// C++ Code to demostrate various functions available in
// String class

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Creating and initializing strings
    string greeting = "Hello, World!";
    cout << greeting << endl;
    string name;

    // Input from the user
    cout << "Enter your name: ";
    cin >> name;
    cout << name << endl;

    // String length
    int length = greeting.length();
    cout << length << endl;

    // Accessing characters
    char firstChar = greeting[0];
    char secondChar = greeting.at(1);
    cout << firstChar << " " << secondChar << endl;

    // Appending and concatenating strings
    string firstName = "Geek";
    string lastName = "Geeks";
    string fullName = firstName + " " + lastName;
    cout << fullName << endl;
    string base = "Hello";
    cout << base << endl;
    base.append(" World!");
    cout << base << endl;

    // String comparison
    string str1 = "apple";
    string str2 = "banana";
    if (str1 == str2) {
        cout << "Strings are equal" << endl;
    }
    else {
        cout << "Strings are not equal" << endl;
    }

    int result = str1.compare(str2);
    if (result == 0) {
        cout << "Strings are equal" << endl;
    }
    else if (result < 0) {
        cout << "str1 comes before str2" << endl;
    }
    else {
        cout << "str1 comes after str2" << endl;
    }

    // Substrings
    string text = "Hello, World!";
    cout << text << endl;
    string sub = text.substr(7, 5);
    cout << sub << endl;

    // Searching
    string searchIn = "C++ Programming";
    size_t position = searchIn.find("Programming");
    if (position != string::npos) {
        cout << "Found at position " << position << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // Modifying strings
    string modify = "I like dogs.";
    modify.replace(7, 4, "cats");
    cout << modify << endl;
    modify.insert(6, " black");
    cout << modify << endl;
    modify.erase(6, 6);
    cout << modify << endl;

    // Conversion
    string str = "C++";
    const char* cstr = str.c_str();
    cout << cstr << endl;

    return 0;
}