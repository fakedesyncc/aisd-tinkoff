#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int value;
    int left;
    int right;
};

pair<int, bool> dfs(int v, const vector<Node>& tree, int min_val, int max_val) {
    if (v == -1) {
        return { 0, true };
    }

    if (tree[v].value <= min_val || tree[v].value >= max_val) return { 0, false };

    pair<int, bool> left_subtree = dfs(tree[v].left, tree, min_val, tree[v].value);
    pair<int, bool> right_subtree = dfs(tree[v].right, tree, tree[v].value, max_val);

    if (!left_subtree.second || !right_subtree.second) {
        return { 0, false };
    }

    int left_height = left_subtree.first;
    int right_height = right_subtree.first;

    if (abs(left_height - right_height) > 1) {
        return { 0, false };
    }

    return { max(left_height, right_height) + 1, true };
}

int main() {
    int n, root;
    cin >> n >> root;

    vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i].left >> tree[i].right;
        tree[i].value = i;
    }

    pair<int, bool> result = dfs(root, tree, -1, n);
    cout << (result.second ? 1 : 0) << endl;

    return 0;
}