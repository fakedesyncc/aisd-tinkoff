#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    vector<int> prefix_xor(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
        prefix_xor[i] = prefix_xor[i - 1] ^ a[i - 1];
    }

    int m;
    cin >> m;
    while (m--) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            cout << prefix_sum[r] - prefix_sum[l - 1] << '\n';
        }
        else {
            cout << (prefix_xor[r] ^ prefix_xor[l - 1]) << '\n';
        }
    }

    return 0;
}