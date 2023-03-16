#include <bits/stdc++.h>

using namespace std;


void countSortB2(int a[], int n, int power, int exp){
    int BASE = (1 << power);
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        mp[(a[i] >> exp) & (BASE - 1)]++;
    }
    for(int i = 1; i < BASE; ++i){
        mp[i] += mp[i - 1];
    }
    int* res = new int[100000000];
    for(int i = n; i >= 1; --i){
        res[mp[(a[i] >> exp) & (BASE - 1)]] = a[i];
        mp[(a[i] >> exp) & (BASE - 1)]--;
    }
    for(int i = 1; i <= n; ++i){
        a[i] = res[i];
    }
    if(res != NULL){
        delete[] res;
        res = NULL;
    }
}

void radixSortBit(int a[], int n, int power){
    for(int exp = 0; exp < 32; exp += power){
        countSortB2(a, n, power, exp);
    }
}
