#include <iostream>
#include <string>

using namespace std;


void mergeString(string *str, int low, int mid, int high, const int size) {
    int i = low;
    int j = mid + 1;
    int k = low;

    string temp[size];

    while (i <= mid && j <= high) {
        if (str[i] < str[j]) {
            temp[k].assign(str[i]);
            i++;
        } else {
            temp[k].assign(str[j]);
            j++;
        }
        k++;
    }

    if (i > mid) {
        for (int h = j; h <= high; h++) {
            temp[k].assign(str[h]);
            k++;
        }
    } else
        for (int h = i; h <= mid; h++) {
            temp[k].assign(str[h]);
            k++;
        }
    for (int i = low; i <= high; i++) {
        str[i].assign(temp[i]);
    }
}

void stringMergeSort(string *str, int low, int high, const int size) {
    int mid = 0;
    if (low < high) {
        mid = ((low + high) / 2);
        stringMergeSort(str, low, mid, size);
        stringMergeSort(str, mid + 1, high, size);
        mergeString(str, low, mid, high, size);
    }
}

void inputArrayOfString(string *arrayOfString, int size) {
    for (int i = 0; i < size; i++) {
        getline(cin, arrayOfString[i]);
    }
}

void printStrings(string *arrayOfString, int size) {
    for (int i = 0; i < size; i++) {
        cout << arrayOfString[i] << endl;
    }
}

int stringBinarySearch(string *arrayOfString, int size, string target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arrayOfString[mid].compare(target) == 0) {
            return mid;
        }

        if (arrayOfString[mid].compare(target) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int size;
    cin >> size;
    cin.ignore();

    string filenames[size];
    string copiedFilenames[size];

    inputArrayOfString(filenames, size);
    for (int i = 0; i < size; i++) {
        copiedFilenames[i] = filenames[i];
    }

    stringMergeSort(filenames, 0, size - 1, size);

    string target;
    getline(cin, target);

    int index = stringBinarySearch(filenames, size, target);

    // Get original index
    int result = -1;
    for (int i = 0; i < size; i++) {
        if (filenames[index].compare(copiedFilenames[i]) == 0) {
            result = i;
            break;
        }
    }

    cout << result;

    return 0;
}

