#include <iostream>
#include <string>

using namespace std;

string stringCompression (const string& my_string)
{
    int char_count = 1;
    char prev_char;
    char curr_char = my_string.at(1);
    bool compressable = false;

    string compressed_string = "";

    for(int i = 1; i < my_string.length(); i++)
    {
        prev_char = my_string.at(i - 1);
        curr_char = my_string.at(i);

        if(curr_char == prev_char)
        {
            char_count++;
            compressable = true;
        }
        else
        {
            compressed_string += prev_char + to_string(char_count);
            char_count = 1;
        }
    }

    // to catch last characters because curr_char will extend past end of string so we will never concatenate string
    compressed_string += prev_char + to_string(char_count);

    if(compressable) return compressed_string;
    else return my_string;
}

int main()
{
    string string1 = "aaabbbccccccaaaBBBzzzz";
    string string2 = "abcdefgh";

    cout << string1 + " compressed is: " + stringCompression(string1) << endl;
    cout << string2 + " compressed is: " + stringCompression(string2) << endl;
}