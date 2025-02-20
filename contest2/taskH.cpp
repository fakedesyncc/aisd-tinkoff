#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    vector<int> left(n, -1);
    stack<int> left_stack;
    for (int i = 0; i < n; ++i) {
        while (!left_stack.empty() && a[left_stack.top()] >= a[i]) {
            left_stack.pop();
        }
        if (!left_stack.empty()) {
            left[i] = left_stack.top();
        }
        left_stack.push(i);
    }

    vector<int> right(n, n);
    stack<int> right_stack;
    for (int i = n - 1; i >= 0; --i) {
        while (!right_stack.empty() && a[right_stack.top()] >= a[i]) {
            right_stack.pop();
        }
        if (!right_stack.empty()) {
            right[i] = right_stack.top();
        }
        right_stack.push(i);
    }

    long long max_result = 0;
    for (int i = 0; i < n; ++i) {
        int l = left[i] + 1;
        int r = right[i] - 1;
        long long sum = prefix_sum[r + 1] - prefix_sum[l];
        long long current = sum * a[i];
        if (current > max_result) {
            max_result = current;
        }
    }

    cout << max_result << '\n';

    return 0;
}