#include <bits/stdc++.h>

using namespace std;


void interclasare(int a[], int st, int dr){
    int mij = st + (dr - st) / 2;
    int* aux = new int[100000000];
    int i = st, j = mij + 1, k = 0;
    while(i <= mij && j <= dr){
        if(a[i] <= a[j]){
            aux[++k] = a[i];
            i++;
        }
        else{
            aux[++k] = a[j];
            j++;
        }
    }
    while(i <= mij){
        aux[++k] = a[i];
        i++;
    }
    while(j <= dr){
        aux[++k] = a[j];
        j++;
    }
    k = 1;
    for(int i = st; i <= dr; ++i){
        a[i] = aux[k];
        k++;
    }
    if(aux != NULL){
        delete[] aux;
        aux = NULL;
    }
}

void mergeSort(int a[], int st, int dr){
    if(st < dr){
        int mij = st + (dr - st) / 2;
        mergeSort(a, st, mij);
        mergeSort(a, mij + 1, dr);
        interclasare(a, st, dr);
    }
}