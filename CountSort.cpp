#include <bits/stdc++.h>

using namespace std;


void countSort(int a[], int n, int maxi){
    int* mp = new int[100000000];
    int cnt = 1;
    memset(mp, 0, sizeof(mp));
    for(int i = 1; i <= n; ++i){
        mp[a[i]]++;
    }
    for(int i = 0; i <= maxi; ++i){
        if(mp[i]){
            for(int j = 1; j <= mp[i]; ++j){
                a[cnt++] = i;
            }
        }
    }
    if(mp != NULL){
        delete[] mp;
        mp = NULL;
    }
}