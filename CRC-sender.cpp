#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator;

    cout << "Enter Data Bits: ";
    cin >> data;

    cout << "Enter Generator Bits: ";
    cin >> generator;

    int r = generator.length() - 1;

    // Append r zeros
    string temp = data;
    for (int i = 0; i < r; i++)
        temp += '0';

    // Modulo-2 division
    for (int i = 0; i <= temp.length() - generator.length(); i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generator.length(); j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Get remainder
    string remainder = temp.substr(temp.length() - r);

    // Transmitted codeword
    string codeword = data + remainder;

    cout << "\n--- Sender Side ---" << endl;
    cout << "Data Bits: " << data << endl;
    cout << "Generator Bits: " << generator << endl;
    cout << "Redundant Bits (r): " << r << endl;
    cout << "CRC Remainder: " << remainder << endl;
    cout << "Transmitted Codeword: " << codeword << endl;

    return 0;
}
