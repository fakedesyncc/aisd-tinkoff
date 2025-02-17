#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct SegmentTree {
    struct Node {
        int l, r;
        int max_val;
        int add;
        int count;
        Node *left, *right;
        
        Node(int l_, int r_) : 
            l(l_), r(r_), 
            max_val(0), 
            add(0), 
            count(r_ - l_ + 1), 
            left(nullptr), 
            right(nullptr) 
        {}
    };

    Node* root;

    SegmentTree(int n) {
        root = build(0, n - 1);
    }

    Node* build(int l, int r) {
        Node* node = new Node(l, r);
        if (l == r) {
            node->max_val = 0;
            node->count = 1;
        } else {
            int mid = (l + r) / 2;
            node->left = build(l, mid);
            node->right = build(mid + 1, r);
            node->max_val = max(node->left->max_val, node->right->max_val);
            node->count = node->left->count + node->right->count;
        }
        return node;
    }

    void push(Node* node) {
        if (node->add != 0 && node->left != nullptr) {
            if (node->left->count > 0) {
                node->left->max_val += node->add;
                node->left->add += node->add;
            }
            if (node->right->count > 0) {
                node->right->max_val += node->add;
                node->right->add += node->add;
            }
            node->add = 0;
        }
    }

    void range_add(Node* node, int l, int r, int delta) {
        if (node->r < l || node->l > r || node->count == 0) return;
        if (l <= node->l && node->r <= r) {
            node->max_val += delta;
            node->add += delta;
            return;
        }
        push(node);
        range_add(node->left, l, r, delta);
        range_add(node->right, l, r, delta);
        node->max_val = max(node->left->max_val, node->right->max_val);
    }

    void deactivate(Node* node, int pos) {
        if (node->l == node->r) {
            node->count = 0;
            node->max_val = INT_MIN;
            return;
        }
        push(node);
        if (pos <= node->left->r) {
            deactivate(node->left, pos);
        } else {
            deactivate(node->right, pos);
        }
        node->max_val = max(node->left->max_val, node->right->max_val);
        node->count = node->left->count + node->right->count;
    }

    int get_max() {
        return root->count > 0 ? root->max_val : -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }

    SegmentTree st(n);
    vector<int> res;
    res.push_back(1); // a0 is 1 iteration (all zeros)

    for (int i = 0; i < n; ++i) {
        int pos = p[i];
        if (pos + 1 <= n - 1) {
            st.range_add(st.root, pos + 1, n - 1, 1);
        }
        st.deactivate(st.root, pos);
        int current_max = st.get_max();
        res.push_back(current_max == -1 ? 1 : current_max + 1);
    }

    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
    }

    return 0;
}