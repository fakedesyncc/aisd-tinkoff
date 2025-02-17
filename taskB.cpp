#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findClosest(const vector<int>& arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    int closest = arr[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (abs(arr[mid] - x) < abs(closest - x)) {
            closest = arr[mid];
        } else if (abs(arr[mid] - x) == abs(closest - x)) {
            closest = min(closest, arr[mid]);
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return closest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        cout << findClosest(a, x) << "\n";
    }

    return 0;
}