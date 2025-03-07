#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(const vector<int>& stalls, int distance, int cows) {
    int count = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPosition >= distance) {
            count++;
            lastPosition = stalls[i];
            if (count == cows) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> stalls(N);

    for (int i = 0; i < N; ++i) {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());

    int left = 1;
    int right = stalls[N - 1] - stalls[0];
    int bestDistance = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, mid, K)) {
            bestDistance = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << bestDistance << '\n';
    return 0;
}