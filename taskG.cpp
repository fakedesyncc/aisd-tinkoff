#include <iostream>
#include <vector>

void swap(std::vector<int>& a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

std::vector<int> antiQuickSortPermutation(int n) {
    std::vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i + 1;
    }

    for (int i = 2; i < n; ++i) {
        swap(perm, i / 2, i);
    }

    return perm;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> perm = antiQuickSortPermutation(n);

    for (int i = 0; i < n; ++i) {
        std::cout << perm[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}