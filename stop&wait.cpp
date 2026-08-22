#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of frames: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "\nSender: Sending Frame " << i << endl;

        cout << "Timer started..." << endl;

        sleep(2);

        // Internally Frame 2 is lost
        if(i == 2)
        {
            cout << "Frame " << i << " is lost!" << endl;

            cout << "Timer expired!" << endl;

            cout << "Sender: Resending Frame " << i << endl;

            sleep(2);

            cout << "Receiver: Frame " << i << " received" << endl;

            cout << "Receiver: Sending ACK " << i << endl;

            cout << "Sender: ACK " << i << " received" << endl;

            cout << "Timer stopped." << endl;
        }
        else
        {
            cout << "Receiver: Frame " << i << " received" << endl;

            cout << "Receiver: Sending ACK " << i << endl;

            sleep(1);

            cout << "Sender: ACK " << i << " received" << endl;

            cout << "Timer stopped." << endl;
        }
    }

    cout << "\nAll frames transmitted successfully!" << endl;

    return 0;
}
