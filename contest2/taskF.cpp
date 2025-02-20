#include <deque>
#include <map>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    deque<int> d;
    map<int, int> pos_by_id;
    int gone = 0;

    for (int req = 0; req < n; ++req) {
        int type;
        cin >> type;

        if (type == 1) {
            int id;
            cin >> id;
            pos_by_id[id] = d.size() + gone;
            d.push_back(id);

        }
        else if (type == 2) {
            if (!d.empty()) {
                d.pop_front();
                ++gone;
            }

        }
        else if (type == 3) {
            if (!d.empty()) {
                d.pop_back();
            }

        }
        else if (type == 4) {
            int q;
            cin >> q;
            cout << pos_by_id[q] - gone << '\n';

        }
        else if (type == 5) {
            if (!d.empty()) {
                cout << d.front() << '\n';
            }
        }
    }

    return 0;
}