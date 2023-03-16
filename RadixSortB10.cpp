#include <bits/stdc++.h>

using namespace std;


void countSortB10(int a[], int n, int exp){
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        mp[(a[i] / exp) % 10]++;
    }
    for(int i = 1; i < 10; ++i){
        mp[i] += mp[i - 1];
    }
    int* res = new int[100000000];
    for(int i = n; i >= 1; --i){
        res[mp[(a[i] / exp) % 10]] = a[i];
        mp[(a[i] / exp) % 10]--;
    }
    for(int i = 1; i <= n; ++i){
        a[i] = res[i];
    }
    if(res != NULL){
        delete[] res;
        res = NULL;
    }
}

void radixSortB10(int a[], int n, int maxi){
    for(int exp = 1; maxi / exp > 0; exp *= 10){
        countSortB10(a, n, exp);
    }
}