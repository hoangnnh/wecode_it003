#include <iostream>
#include <string>
using namespace std;

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
        }

        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int size;
    cin >> size;
    if (size <= 0) {
        cout << -1;
        return 0;
    }
    cin.ignore();

    string *arrayOfString = new string[size];

    inputArrayOfString(arrayOfString, size);

    string target;
    getline(cin, target);

    int index = stringBinarySearch(arrayOfString, size, target);

    cout << index;

    delete[] arrayOfString;

    return 0;
}