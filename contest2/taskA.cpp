#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    stack<int> min_s;

    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            s.push(x);

            if (min_s.empty() || x <= min_s.top()) {
                min_s.push(x);
            }
            else {
                min_s.push(min_s.top());
            }

        }
        else if (type == 2) {
            if (!s.empty()) {
                s.pop();
                min_s.pop();
            }
        }
        else if (type == 3) {
            if (!min_s.empty()) {
                cout << min_s.top() << endl;
            }
        }
    }

    return 0;
}