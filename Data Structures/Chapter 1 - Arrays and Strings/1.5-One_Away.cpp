#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool isOneAway(string& my_string1, string& my_string2)
{
    // If strings are more than one character different in length, not possible to be one away
    if( abs(my_string1.length() - my_string2.length()) > 1) return false;
    
    int difference = 0;
    vector<int> char_frequency_diff(256, 0);

    // Increment frequency for first string
    for(auto& c : my_string1) char_frequency_diff[c]++;
    // Decrement frequency for second string
    for(auto& c : my_string2) char_frequency_diff[c]--;

    // If absolute sum of frequency > 1, then we know that more than one difference
    for(auto& i : char_frequency_diff)
    {
        // Can cut loop short if 'difference' ever goes above 2 (for a switchout, there can be a +1 and a -1 making difference = 2)
        if(difference > 2) return false;
        difference += abs(i);
    }
    return true;
}

int main() {
    string string1 = "pale";
    string string2 = "ple";

    cout << string1 + " and " + string2 + " are one away of each other: " + string(isOneAway(string1, string2) ? "Yes!" : "No!") << endl;

    string string3 = "pales";
    string string4 = "pale";

    cout << string3 + " and " + string4 + " are one away of each other: " + string(isOneAway(string3, string4) ? "Yes!" : "No!") << endl;

    string string5 = "pale";
    string string6 = "bale";

    cout << string5 + " and " + string6 + " are one away of each other: " + string(isOneAway(string5, string6) ? "Yes!" : "No!") << endl;

    string string7 = "pale";
    string string8 = "bake";

    cout << string7 + " and " + string8 + " are one away of each other: " + string(isOneAway(string7, string8) ? "Yes!" : "No!") << endl;
}