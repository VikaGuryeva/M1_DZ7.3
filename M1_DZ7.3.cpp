#include <iostream>

using namespace std;

// �������� �������� ���� �� �������� ������� � �����
int getBit(long long num, int pos) {
    return (num >> pos) & 1;
}

// ����������� ������� ��� ���������� MSD
void msdSort(long long* arr, int left, int right, int bit) {
    if (left >= right || bit < 0) return;

    int i = left, j = right;
    while (i <= j) {
        while (i <= right && getBit(arr[i], bit) == 0) i++;
        while (j >= left && getBit(arr[j], bit) == 1) j--;

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    msdSort(arr, left, j, bit - 1);
    msdSort(arr, i, right, bit - 1);
}

// ������� ��� ������ ������� ���������� MSD
void msdSortWrapper(long long* arr, int size) {
    int maxBit = 63; // ��������� ����� 64-���������
    msdSort(arr, 0, size - 1, maxBit);
}

// ������� ��� ������ ������� �� �����
void printArray(long long* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    long long* arr = new long long[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // ���������� ������� MSD �� �����
    msdSortWrapper(arr, n);

    // ����� ���������������� �������
    printArray(arr, n);

    // ����������� ���������� ������
    delete[] arr;

    return 0;
}
