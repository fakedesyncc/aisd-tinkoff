#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> numbers(N);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    deque<int> dq;

    for (int i = 0; i < N; ++i) {
        if (!dq.empty() && dq.front() < i - K + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && numbers[dq.back()] > numbers[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= K - 1) {
            cout << numbers[dq.front()] << " ";
        }
    }

    cout << endl;
    return 0;
}