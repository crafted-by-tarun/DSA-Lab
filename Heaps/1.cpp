#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i, bool isMax) {
    int extreme = i; 
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(isMax) {
        if(left < n && a[left] > a[extreme]) extreme = left;
        if(right < n && a[right] > a[extreme]) extreme = right;
    } else { 
        if(left < n && a[left] < a[extreme]) extreme = left;
        if(right < n && a[right] < a[extreme]) extreme = right;
    }

    if(extreme != i) {
        swap(a[i], a[extreme]);
        heapify(a, n, extreme, isMax);
    }
}

void heapSort(vector<int> &a, bool increasing = true) {
    int n = a.size();

    // Build heap (max or min)
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, increasing);

    // Extract elements
    for(int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, increasing);
    }
}
