#include <iostream>
#include <string.h>

using namespace std;

void URLIfyAlg(string& my_string, int true_length)
{
    int space_count = 0;
    char character;

    // Determine number of spaces in true string
    for(int i = 0; i < true_length; i++)
    {
        if(my_string.at(i) == ' ') space_count++;
    }

    if(space_count == 0) return;

    // Start at end of string
    for(int i = true_length - 1; i >= 0; i--)
    {
        // If it's a space, add %20 and decrease space_count by 1 to minimzed index shifting
        if(my_string.at(i) == ' ')
        {
            my_string[i + (2 * space_count) - 2] = '%';
            my_string[i + (2 * space_count) - 1] = '2';
            my_string[i + (2 * space_count)] = '0';
            space_count--;
        }
        // Just move the character based on number of spaces remaining
        else
        {
            my_string[i + (2 * space_count)] = my_string.at(i);
        }
    }
}

int main()
{
    string string1 = "hello world !";
    int char_count = string1.length();

    int spaces = 0;

    for(int i = 0; i < string1.length(); i++)
    {
        if(string1.at(i) == ' ') spaces++;
    }

    cout << "Before URLify: " + string1 << endl;

    while(spaces)
    {
        string1.append("  ");
        spaces--;
    }

    URLIfyAlg(string1, char_count);
    cout << "After URLify: " + string1 << endl;

    return 0;
}