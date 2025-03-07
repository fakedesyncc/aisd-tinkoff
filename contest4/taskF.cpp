#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector<pair<long long, long long>> merged_segments;
    sort(segments.begin(), segments.end());

    if (n > 0) {
        merged_segments.push_back(segments[0]);
    }

    for (int i = 1; i < n; ++i) {
        if (segments[i].first <= merged_segments.back().second) {
            merged_segments.back().second = max(merged_segments.back().second, segments[i].second);
        }
        else {
            merged_segments.push_back(segments[i]);
        }
    }

    long long total_length = 0;
    for (const auto& seg : merged_segments) {
        total_length += seg.second - seg.first;
    }

    cout << total_length << endl;

    return 0;
}