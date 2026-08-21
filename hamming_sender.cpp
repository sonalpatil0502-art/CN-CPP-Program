#include <iostream>
using namespace std;

int main() {
    int data[20], code[20];
    int m = 7;
    int r = 4;
    int n = m + r;

    cout << "Enter 7 data bits: ";
    for (int i = 1; i <= m; i++)
        cin >> data[i];

    cout << "\nr = " << r << endl;
    cout << "n = " << n << endl;

    // Place data bits
    int j = 1;

    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == 2 || i == 4 || i == 8)
            code[i] = 0;   // Parity positions
        else {
            code[i] = data[j];
            j++;
        }
    }

    // Calculate R1, R2, R4, R8
    for (int i = 0; i < r; i++) {
        int p = 1 << i;
        int parity = 0;

        for (int j = 1; j <= n; j++) {
            if (j & p)
                parity ^= code[j];
        }

        code[p] = parity;
    }

    cout << "R1 = " << code[1] << endl;
    cout << "R2 = " << code[2] << endl;
    cout << "R4 = " << code[4] << endl;
    cout << "R8 = " << code[8] << endl;

    cout << "Hamming Code: ";

    for (int i = n; i >= 1; i--)
        cout << code[i];

    cout << endl;

    return 0;
}
