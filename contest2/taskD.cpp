#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }

    int destroyed_count = 0;
    bool destroyed = true;

    while (destroyed) {
        destroyed = false;
        int start = 0;
        while (start < balls.size()) {
            int end = start;
            while (end < balls.size() && balls[end] == balls[start]) {
                ++end;
            }

            if (end - start >= 3) {
                destroyed_count += (end - start);
                balls.erase(balls.begin() + start, balls.begin() + end);
                destroyed = true;
                break;
            }
            else {
                start = end;
            }
        }
    }

    cout << destroyed_count << endl;

    return 0;
}