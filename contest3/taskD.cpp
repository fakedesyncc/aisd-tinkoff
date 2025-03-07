#include <iostream>
#include <vector>

using namespace std;

void heapifyUp(vector<long long>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

void heapifyDown(vector<long long>& heap, int index, int size) {
    while (true) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest == index) {
            break;
        }

        swap(heap[index], heap[largest]);
        index = largest;
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> heap;

    for (int i = 0; i < n; ++i) {
        int command;
        cin >> command;

        if (command == 0) {
            long long num;
            cin >> num;
            heap.push_back(num);
            heapifyUp(heap, heap.size() - 1);
        }
        else {
            cout << heap[0] << endl;
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(heap, 0, heap.size());
        }
    }

    return 0;
}