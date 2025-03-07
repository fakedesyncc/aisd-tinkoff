#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    long long s;
    long long t;
    long long end;
    int id;
};

bool compareTasks(const Task& a, const Task& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    cin >> n >> c;

    vector<Task> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].s >> tasks[i].t;
        tasks[i].end = tasks[i].s + tasks[i].t;
        tasks[i].id = i + 1;
    }

    sort(tasks.begin(), tasks.end(), compareTasks);

    vector<int> selected;
    long long current_end = 0;

    for (const auto& task : tasks) {
        if (task.s >= current_end) {
            selected.push_back(task.id);
            current_end = task.end;
        }
    }

    cout << selected.size() * c << '\n';
    cout << selected.size() << '\n';
    for (size_t i = 0; i < selected.size(); ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << selected[i];
    }
    cout << '\n';

    return 0;
}