#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vagons(n);
    for (int i = 0; i < n; ++i) {
        cin >> vagons[i];
    }

    vector<int> way;
    vector<int> tupik;
    int last = 1;
    vector<pair<int, int>> operations;

    while (!vagons.empty() || !tupik.empty()) {

        if (find(vagons.begin(), vagons.end(), last) != vagons.end()) {
            auto it = find(vagons.begin(), vagons.end(), last);
            int x = distance(vagons.begin(), it);

            tupik.insert(tupik.end(), vagons.begin(), vagons.begin() + x + 1);
            vagons.erase(vagons.begin(), vagons.begin() + x + 1);
            operations.push_back({ 1, x + 1 });
        }
        else {
            int i = 0;
            for (int j = tupik.size() - 1; j >= 0; --j) {
                if (last == tupik[j]) {
                    last++;
                    i++;
                }
                else {
                    break;
                }
            }
            if (i > 0) {
                operations.push_back({ 2, i });

                way.insert(way.end(), tupik.begin() + tupik.size() - i, tupik.end());
                tupik.resize(tupik.size() - i);
            }
            else {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    if (last != n + 1) {
        cout << 0 << endl;
        return 0;
    }


    cout << operations.size() << endl;
    for (const auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}