#include <iostream>

using namespace std;

long long count_less_equal(long long n, long long x) {
    long long count = 0;
    for (long long i = 1; i <= n; ++i) {
        count += min(n, x / i);
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    long long left = 1, right = n * n;
    long long ans = -1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long count = count_less_equal(n, mid);

        if (count >= k) {
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