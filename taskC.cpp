#include <iostream>
using namespace std;

int main() {
    int low = 1, high;
    cin >> high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        cout.flush();

        string response;
        cin >> response;

        if (response == "<") {
            high = mid - 1;
        } else if (response == ">=") {
            low = mid + 1;
        }
    }

    cout << "! " << high << endl;
    cout.flush();
    return 0;
}