#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool check(long long mid, const vector<long long>& a, int k) {
    int count = 1;
    long long current_sum = 0;
    for (long long x : a) {
        if (x > mid) return false;
        if (current_sum + x <= mid) {
            current_sum += x;
        }
        else {
            count++;
            current_sum = x;
        }
    }
    return count <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long left = 1, right = accumulate(a.begin(), a.end(), 0LL);
    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, a, k)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}