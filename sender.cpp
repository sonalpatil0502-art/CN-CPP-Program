#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input, output = "";
    int count = 0;

    cout << "Enter the binary data: ";
    cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        output += input[i];

        if (input[i] == '1')
        {
            count++;
            if (count == 5)
            {
                output += '0';   // Insert stuffed 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    cout << "Bit Stuffed Data: " << output << endl;

    return 0;
}

/*Enter the binary data: 11111011111
Bit Stuffed Data: 1111100111110*/
