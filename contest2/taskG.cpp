#include <iostream>
#include <deque>

using namespace std;

void equalize(deque<int>& left_part, deque<int>& right_part) {
    while (left_part.size() < right_part.size()) {
        left_part.push_back(right_part.front());
        right_part.pop_front();
    }
  
    while (left_part.size() > right_part.size() + 1) {
        right_part.push_front(left_part.back());
        left_part.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> left_part, right_part;

    for (int req = 0; req < n; ++req) {
        char type;
        cin >> type;
        if (type == '+') {
            int x;
            cin >> x;
            right_part.push_back(x);
        }
        else if (type == '*') {
            int x;
            cin >> x;
            left_part.push_back(x);
        }
        else {
            cout << left_part.front() << endl;
            left_part.pop_front();
        }
        equalize(left_part, right_part);
    }

    return 0;
}