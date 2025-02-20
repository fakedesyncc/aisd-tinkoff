#include <iostream>
#include <vector>

using namespace std;

long long merge_sort(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += merge_sort(arr, left, mid);
        inversions += merge_sort(arr, mid + 1, right);

        vector<int> left_arr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> right_arr(arr.begin() + mid + 1, arr.begin() + right + 1);

        int i = 0, j = 0, k = left;
        while (i < left_arr.size() && j < right_arr.size()) {
            if (left_arr[i] <= right_arr[j]) {
                arr[k++] = left_arr[i++];
            } else {
                arr[k++] = right_arr[j++];
                inversions += left_arr.size() - i;
            }
        }

        while (i < left_arr.size()) {
            arr[k++] = left_arr[i++];
        }

        while (j < right_arr.size()) {
            arr[k++] = right_arr[j++];
        }
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long inversions = merge_sort(arr, 0, n - 1);

    cout << inversions << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}