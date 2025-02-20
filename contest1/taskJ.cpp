#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using int128 = __int128_t;

struct Answer {
    char type;
    ll x;
    int128 diff;
};

int128 compute_vert(int128 k, int128 n, int128 m) {
    return (k * n * (m * (n - 1) + k + 1)) / 2;
}

int128 compute_hor(int128 l, int128 m) {
    int128 ml = m * l;
    return (ml * (ml + 1)) / 2;
}

Answer find_best_vert(int128 n, int128 m, int128 S_half) {
    int128 low = 0, high = m - 1;
    int128 best_k = 0;
    while (low <= high) {
        int128 mid = (low + high) / 2;
        int128 current = compute_vert(mid, n, m);
        if (current <= S_half) {
            best_k = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int128 candidate1 = best_k;
    int128 candidate2 = best_k + 1;
    bool valid2 = (candidate2 < m);
    
    int128 sum1 = compute_vert(candidate1, n, m);
    int128 sum2 = valid2 ? compute_vert(candidate2, n, m) : -1;
    
    int128 diff1 = S_half - sum1;
    int128 diff2 = valid2 ? (sum2 - S_half) : -1;
    
    int128 best_diff;
    int128 best_k_final;
    
    if (!valid2) {
        best_diff = diff1;
        best_k_final = candidate1;
    } else {
        if (diff1 <= diff2) {
            best_diff = diff1;
            best_k_final = candidate1;
        } else {
            best_diff = diff2;
            best_k_final = candidate2;
        }
    }
    
    return {'V', static_cast<ll>(best_k_final + 1), best_diff};
}

Answer find_best_hor(int128 n, int128 m, int128 S_half) {
    int128 low = 0, high = n - 1;
    int128 best_l = 0;
    while (low <= high) {
        int128 mid = (low + high) / 2;
        int128 current = compute_hor(mid, m);
        if (current <= S_half) {
            best_l = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int128 candidate1 = best_l;
    int128 candidate2 = best_l + 1;
    bool valid2 = (candidate2 < n);
    
    int128 sum1 = compute_hor(candidate1, m);
    int128 sum2 = valid2 ? compute_hor(candidate2, m) : -1;
    
    int128 diff1 = S_half - sum1;
    int128 diff2 = valid2 ? (sum2 - S_half) : -1;
    
    int128 best_diff;
    int128 best_l_final;
    
    if (!valid2) {
        best_diff = diff1;
        best_l_final = candidate1;
    } else {
        if (diff1 <= diff2) {
            best_diff = diff1;
            best_l_final = candidate1;
        } else {
            best_diff = diff2;
            best_l_final = candidate2;
        }
    }
    
    return {'H', static_cast<ll>(best_l_final + 1), best_diff};
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        int128 nm = static_cast<int128>(n) * m;
        int128 S = nm * (nm + 1) / 2;
        int128 S_half = S / 2;
        
        Answer vert = find_best_vert(n, m, S_half);
        Answer hor = find_best_hor(n, m, S_half);
        
        Answer best;
        if (vert.diff < hor.diff) {
            best = vert;
        } else if (hor.diff < vert.diff) {
            best = hor;
        } else {
            best = vert;
        }
        
        cout << best.type << " " << best.x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}