#include <iostream>
using namespace std;

int main() {
    int code[20];
    int n, r = 0;
    int syndrome = 0;

    cout << "Enter number of bits: ";
    cin >> n;

    cout << "Enter received Hamming code: ";

    // Code is entered in the same order as sender output
    // Sender displays from n to 1, so store it in reverse
    for (int i = n; i >= 1; i--)
        cin >> code[i];

    // Calculate number of parity bits
    while ((1 << r) < (n + 1))
        r++;

    // Calculate syndrome
    for (int i = 0; i < r; i++) {
        int p = (1 << i);
        int parity = 0;

        for (int j = 1; j <= n; j++) {
            if (j & p)
                parity ^= code[j];
        }

        if (parity)
            syndrome += p;
    }

    cout << "\nSyndrome = " << syndrome << endl;

    if (syndrome == 0) {
        cout << "No error detected." << endl;
    }
    else {
        cout << "Error detected at position: " << syndrome << endl;

        // Correct the error
        code[syndrome] ^= 1;

        cout << "Error corrected." << endl;
    }

    cout << "Corrected Hamming Code: ";
    for (int i = n; i >= 1; i--)
        cout << code[i];

    cout << endl;

    return 0;
}
