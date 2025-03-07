#include <bits/stdc++.h>
using namespace std;

struct Event {
    int time;
    int delta;
    Event(int t, int d) : time(t), delta(d) {}
    bool operator<(const Event& other) const {
        if (time != other.time) return time < other.time;
        return delta < other.delta;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Event> events;
    const int SEC_IN_DAY = 24 * 3600;

    for (int i = 0; i < N; ++i) {
        int s_h, s_m, s_s, e_h, e_m, e_s;
        cin >> s_h >> s_m >> s_s >> e_h >> e_m >> e_s;

        int start = s_h * 3600 + s_m * 60 + s_s;
        int end = e_h * 3600 + e_m * 60 + e_s;

        if (start < end) {
            events.emplace_back(start, 1);
            events.emplace_back(end, -1);
        }
        else if (start > end) {
            events.emplace_back(start, 1);
            events.emplace_back(SEC_IN_DAY, -1);
            events.emplace_back(0, 1);
            events.emplace_back(end, -1);
        }
        else {
            events.emplace_back(0, 1);
            events.emplace_back(SEC_IN_DAY, -1);
        }
    }

    sort(events.begin(), events.end());

    int current_active = 0, answer = 0, last_time = 0;
    for (const auto& event : events) {
        if (current_active == N) {
            answer += event.time - last_time;
        }
        current_active += event.delta;
        last_time = event.time;
    }

    cout << answer << '\n';

    return 0;
}