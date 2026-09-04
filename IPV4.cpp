#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string ip;
    int a, b, c, d;
    char dot;

    cout << "Enter IP Address: ";
    cin >> ip;

    // String to integer
    stringstream s(ip);
    s >> a >> dot >> b >> dot >> c >> dot >> d;

    // Valid IP
    if(a < 0 || a > 255 || b < 0 || b > 255 ||
       c < 0 || c > 255 || d < 0 || d > 255)
    {
        cout << "Invalid IP Address";
        return 0;
    }

    cout << "Valid IP Address" << endl;

    // Class A
    if(a >= 1 && a <= 126)
    {
        cout << "Class: A" << endl;
        cout << "Subnet Mask: 255.0.0.0" << endl;
        cout << "Network ID: " << a << ".0.0.0" << endl;
        cout << "Host ID: 0." << b << "." << c << "." << d;
    }

    // Class B
    else if(a >= 128 && a <= 191)
    {
        cout << "Class: B" << endl;
        cout << "Subnet Mask: 255.255.0.0" << endl;
        cout << "Network ID: " << a << "." << b << ".0.0" << endl;
        cout << "Host ID: 0.0." << c << "." << d;
    }

    // Class C
    else if(a >= 192 && a <= 223)
    {
        cout << "Class: C" << endl;
        cout << "Subnet Mask: 255.255.255.0" << endl;
        cout << "Network ID: " << a << "." << b << "." << c << ".0" << endl;
        cout << "Host ID: 0.0.0." << d;
    }

    else if(a >= 224 && a <= 239)
        cout << "Class: D";

    else if(a >= 240 && a <= 255)
        cout << "Class: E";

    else
        cout << "Invalid IP Address";

    return 0;
}

// @sonalpatil0502-art ➜ /workspaces/CN-CPP-Program (main) $ g++ IPV4.cpp
// @sonalpatil0502-art ➜ /workspaces/CN-CPP-Program (main) $ ./a.out
// Enter IP Address: 192.168.1.10
// Valid IP Address
// Class: C
// Subnet Mask: 255.255.255.0
// Network ID: 192.168.1.0
// Host ID: 0.0.0.10@sonalpatil0502-art ➜ /workspaces/CN-CPP-Program (main) $ 