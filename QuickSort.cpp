#include <bits/stdc++.h>

using namespace std;

void median_of_three(int a[], int st, int dr){
    int mij = st + (dr - st) / 2;
    if(a[st] > a[mij]){
        swap(a[st], a[mij]);
    }
    if(a[st] > a[dr]){
        swap(a[st], a[dr]);
    }
    if(a[mij] > a[dr]){
        swap(a[mij], a[dr]);
    }
    swap(a[mij], a[dr - 1]);
}

int partition_vec(int a[], int st, int dr){
    median_of_three(a, st, dr);
    int pivot = a[dr];
    int i = st - 1;
    for(int j = st; j <= dr; ++j){
        if(a[j] < pivot){
            swap(a[++i], a[j]);
        }
    }
    swap(a[i + 1], a[dr]);
    return (i + 1);
}

void quickSort(int a[], int st, int dr){
    if(st < dr){
        int pi = partition_vec(a, st, dr);
        quickSort(a, st, pi - 1);
        quickSort(a, pi + 1, dr);
    }
}