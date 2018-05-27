#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool isPermutation(string& string1, string& string2)
{
    if(string1.length() != string2.length()) return false;

    sort(string1.begin(), string1.end());
    sort(string2.begin(), string2.end());

    return string1 == string2;

}

int main() {
    string string1 = "abcde";
    string string2 = "abcde";

    string string3 = "abcde";
    string string4 = "abcdee";

    cout << string1 + " and " + string2 + " are anagrams: " + string(isPermutation(string1, string2) ? "Yes!" : "No!") << endl;
    cout << string3 + " and " + string4 + " are anagrams: " + string(isPermutation(string3, string4) ? "Yes!" : "No!") << endl;

    return 0;
}