#include <iostream>
#define SIZE 10

using namespace std;

template <class T>
void Print(T& vec, int n, string s) {
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++) {
        cout << vec[i] << flush;
        if (i < n - 1) {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Hash(int key) {
    return key % SIZE;
}

int LinearProbe(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != 0) {
        i++;
    }
    return (idx + i) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key);

    if (H[idx] != 0) {
        idx = LinearProbe(H, key);
    }
    H[idx] = key;
}

int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i) % SIZE] != key) {
        i++;
        if (H[(idx + i) % SIZE] == 0) {
            return -1;
        }
    }
    return (idx + i) % SIZE;
}