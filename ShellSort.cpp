#include <bits/stdc++.h>

using namespace std;

void shellSort(int a[], int n){
    for(int interval = n / 2; interval > 0; interval /= 2){
        for(int i = interval; i <= n; ++i){
            int temp = a[i];
            int j = i;
            while(j >= interval && a[j - interval] > temp){
                a[j] = a[j - interval];
                j = j - interval;
            }
            a[j] = temp;
        }
    }
}