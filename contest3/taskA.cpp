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

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int child = i + 1;
        int parent = p[i];
        adj[parent].push_back(child);
        adj[child].push_back(parent);
    }


    vector<int> depth(n, 0);
    for (int i = 1; i < n; ++i) {
        depth[i] = depth[p[i - 1]] + 1;
    }
    int height = *max_element(depth.begin(), depth.end());

    int diameter = 0;
    vector<int> max1(n, 0), max2(n, 0);
    stack<pair<int, int>> st;
    vector<bool> visited(n, false);

    st.push({ 0, -1 });

    while (!st.empty()) {
        auto [u, parent] = st.top();
        st.pop();

        if (visited[u]) {
            for (int v : adj[u]) {
                if (v == parent) continue;
                int current = max1[v] + 1;
                if (current > max1[u]) {
                    max2[u] = max1[u];
                    max1[u] = current;
                }
                else if (current > max2[u]) {
                    max2[u] = current;
                }
            }
            diameter = max(diameter, max1[u] + max2[u]);
        }
        else {
            visited[u] = true;
            st.push({ u, parent });
            reverse(adj[u].begin(), adj[u].end());
            for (int v : adj[u]) {
                if (v != parent) {
                    st.push({ v, u });
                }
            }
        }
    }

    cout << height << " " << diameter << "\n";
    for (int d : depth) {
        cout << d << " ";
    }
    cout << "\n";

    return 0;
}