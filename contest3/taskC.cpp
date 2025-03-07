#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> p[i];
    }

    vector<vector<int>> paths(n);
    for (int i = 0; i < n; ++i) {
        vector<int> path;
        int current = i;
        while (true) {
            path.push_back(current);
            if (current == 0) break;
            current = p[current - 1];
        }
        reverse(path.begin(), path.end());
        paths[i] = path;
    }

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        const vector<int>& pu = paths[u];
        const vector<int>& pv = paths[v];
        int lca = -1;
        int min_len = min(pu.size(), pv.size());
        for (int i = 0; i < min_len; ++i) {
            if (pu[i] == pv[i]) {
                lca = pu[i];
            }
            else {
                break;
            }
        }
        cout << lca << '\n';
    }

    return 0;
}