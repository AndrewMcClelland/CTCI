#include <string.h>
#include <iostream>

#define ASCII_MAX 256

using namespace std;

bool isUnique(const string& myString)
{
    // If more than 256 characters, we know one is duplicated
    if(myString.length() > ASCII_MAX) return false;
    
    int char_array [ASCII_MAX - 1] = {}; // initialized to 0
    
    // Increment if we see the char, and at same time check if > 1 instance in string ( O(n))
    for(auto& c : myString)
    {
        char_array[(int) c]++;
        if(char_array[(int) c] > 1) return false;
    }

    return true;
}

int main()
{
    string string1 = "hello";
    string string2 = "abcdef";

    cout << "string1: " + string1 + " is unique = " + string(isUnique(string1) ? "yes!" : "no!") << endl;
    cout << "string2: " + string2 + " is unique = " + string(isUnique(string2) ? "yes!" : "no!") << endl;

    return 0;
}