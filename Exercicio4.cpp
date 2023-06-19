#include <iostream>
#include <vector>
#include <algorithm>

int countSwaps = 0;

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            countSwaps += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int loops;
    std::cin >> loops;

    while (loops--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++)
            std::cin >> arr[i];

        countSwaps = 0;
        mergeSort(arr, 0, n - 1);

        std::cout << "Optimal train swapping takes " << countSwaps << " swaps." << std::endl;
    }

    return 0;
}
