#include <bits/stdc++.h>

using namespace std;

void countSort(int a[], int n, int maxi){
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        mp[a[i]]++;
    }
    for(int i = 1; i <= maxi; ++i){
        mp[i] += mp[i - 1];
    }
    int* res = new int[100000000];
    for(int i = n; i >= 1; --i){
        res[mp[a[i]]] = a[i];
        mp[a[i]]--;
    }
    for(int i = 1; i <= n; ++i){
        a[i] = res[i];
    }
    if(res != NULL){
        delete[] res;
        res = NULL;
    }
}