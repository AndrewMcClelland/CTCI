#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

bool isPermutationOfPalindrome(string& my_string)
{
    // Convert to lowercase to ensure accurate letter comparisons
    transform(my_string.begin(), my_string.end(), my_string.begin(), ::tolower);

    // Remove spaces and resize string
    my_string.erase(remove_if(my_string.begin(), my_string.end(), ::isspace), my_string.end());

    //To be a palindrome:
    //  - if even length, all letters must have an even frequency
    //  - if odd length, all letters must have an even frequency except for 1 (the middle character)
    bool is_even_count = (my_string.length() % 2) == 0;
    bool found_odd = false;

    // Count frequency of each char (assume 256 ASCII)
    vector<int> char_frequency(256, 0);

    for(auto& c : my_string)
    {
        char_frequency[c]++;
    }

    // If even number of characters (no character should have odd occurence)
    if (is_even_count)
    {
        for(auto& i : char_frequency)
        {
            if((i % 2) != 0) return false;
        }
    }
    // If odd number of characters (only one character should have odd occurence)
    else
    {
        for(auto& i : char_frequency)
        {
            if((i % 2) != 0)
            {
                if(found_odd) return false; // if we already found an odd frequency character, then we know this is not palindrome
                found_odd = true;
            }
        }
    }

    return true;
}

int main()
{
    // Assume I will not be fed non-alpha characters
    string string1 = "A man a plan a cat a ham a yak a yam a hat a canal Panama";

    cout << string1 + " is a permutation of a palindrome: " + string(isPermutationOfPalindrome(string1) ? "Yes!" : "No!") << endl;
}