#include <bits/stdc++.h>
#include "MergeSort.cpp"
#include "RadixSortB10.cpp"
#include "RadixSortBitwise.cpp"
#include "ShellSort.cpp"
#include "CountSort.cpp"
#include "QuickSort.cpp"


using namespace std;
using namespace std::chrono_literals;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::seconds;


int* principal = new int[100000000];
int* vector_to_sort = new int[100000000];

struct result{
    double time;
    bool overflow;
    bool ok;
};


void shuffle_perm_n(int n){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 1; i <= n; ++i){
        vector_to_sort[i] = i;
    }
    shuffle(vector_to_sort + 1, vector_to_sort + n + 1, rng);
    for(int i = 1; i <= n; ++i){
        principal[i] = vector_to_sort[i];
    }
}

void almost_sorted_perm(int n){
    for(int i = 1; i <= n; ++i){
        vector_to_sort[i] = i;
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_ind(1, n);
    int limit = log2(n);
    for(int k = 0; k < limit; ++k){
        int i = rand_ind(rng);
        int j = rand_ind(rng);
        swap(vector_to_sort[i], vector_to_sort[j]);
    }
    for(int i = 1; i <= n; ++i){
        principal[i] = vector_to_sort[i];
    }
}

void shuffle_vect(int n){
    random_device rd;
    mt19937 rng_nr(rd());
    uniform_int_distribution<int> rand_nr(100000000, INT_MAX);
    for(int i = 1; i <= n; ++i){
        vector_to_sort[i] = rand_nr(rng_nr);
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(vector_to_sort + 1, vector_to_sort + n + 1, rng);
    for(int i = 1; i <= n; ++i){
        principal[i] = vector_to_sort[i];
    }
}

void not_shuffled(int n){
    for(int i = 1; i <= n; ++i){
        vector_to_sort[i] = i;
        principal[i] = i;
    }
}

bool test_sort(int a[], int n){
    return is_sorted(a + 1, a + n + 1);
}

int getMax(int a[], int n){
    int maxi = 0;
    for(int i = 1; i <= n; ++i){
        maxi = max(maxi, a[i]);
    }
    return maxi;
}

result time_merge_sort(int n, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        mergeSort(vector_to_sort, 1, n);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

result time_radix_sortB2(int n, int power, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        radixSortBit(vector_to_sort, n, power);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

result time_radix_sortB10(int n, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    int maxi = getMax(vector_to_sort, n);
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        radixSortB10(vector_to_sort, n, maxi);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

result time_shell_sort(int n, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        shellSort(vector_to_sort, n);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

result time_count_sort(int n, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    int maxi = getMax(vector_to_sort, n);
    if(maxi >= 1000000000){
        result r;
        r.overflow = true;
        r.time = 0;
        r.ok = false;
        return r;
    }
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        countSort(vector_to_sort, n, maxi);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

result time_quick_sort(int n, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        quickSort(vector_to_sort, 1, n);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

result time_native_sort(int n, function<void(int)> type_of_shuffle){
    double mini = DBL_MAX;
    type_of_shuffle(n);
    for(int j = 0; j < 3; ++j){
        auto start = high_resolution_clock::now();
        sort(vector_to_sort + 1, vector_to_sort + n + 1);
        auto end = high_resolution_clock::now();
        duration<double> res = end - start; 
        if(!test_sort(vector_to_sort, n)){
            result fail;
            fail.overflow = false;
            fail.time = 0.0;
            fail.ok = false;
            return fail;
        }
        mini = min(mini, res.count());
        for(int i = 1; i <= n; ++i){
            vector_to_sort[i] = principal[i];
        }
    }
    result r;
    r.overflow = false;
    r.time = mini;
    r.ok = true;
    return r;
}

int main(){
    ///////////////////////////////////////////////////////
    ////////// TESTE CU PERMUTARI DE N ELEMENTE //////////

    ofstream file1("results_perm.txt");

    file1 << "TESTE CU PERMUTARI DE N ELEMENTE" << "\n\n";
    for(int n = 10; n <= 100000000; n *= 10){
        file1 << "N = " << n << "\n\n";
        result r;
        r = time_merge_sort(n, shuffle_perm_n);
        file1 << "Merge Sort: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_quick_sort(n, shuffle_perm_n);
        file1 << "Quick Sort: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 16, shuffle_perm_n);
        file1 << "Radix Sort Base = 2 ^ 16: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 10, shuffle_perm_n);
        file1 << "Radix Sort Base = 2 ^ 10: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 8, shuffle_perm_n);
        file1 << "Radix Sort Base = 2 ^ 8: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 4, shuffle_perm_n);
        file1 << "Radix Sort Base = 2 ^ 4: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB10(n, shuffle_perm_n);
        file1 << "Radix Sort Base = 10: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_shell_sort(n, shuffle_perm_n);
        file1 << "Shell Sort: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        r = time_count_sort(n, shuffle_perm_n);
        file1 << "Count Sort: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            if(r.overflow){
                file1 << "Nu poate sorta\n";
            }
            else{
                file1 << "Sortare esuata!" << "\n";
            }
        }

        r = time_native_sort(n, shuffle_perm_n);
        file1 << "C++ Native Sort: ";
        if(r.ok){
            file1 << r.time << "\n";
        }
        else{
            file1 << "Sortare esuata!" << "\n";
        }

        file1 << "\n\n";
    }
    ////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////
    //////////// TESTE CU NUMERE MARI RANDOM /////////////

    ofstream file2("results_rand.txt");

    file2 << "TESTE CU NUMERE MARI RANDOM" << "\n\n";
    for(int n = 10; n <= 100000000; n *= 10){
        file2 << "N = " << n << "\n\n";
        result r;
        r = time_merge_sort(n, shuffle_vect);
        file2 << "Merge Sort: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_quick_sort(n, shuffle_vect);
        file2 << "Quick Sort: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 16, shuffle_vect);
        file2 << "Radix Sort Base = 2 ^ 16: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 10, shuffle_vect);
        file2 << "Radix Sort Base = 2 ^ 10: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 8, shuffle_vect);
        file2 << "Radix Sort Base = 2 ^ 8: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 4, shuffle_vect);
        file2 << "Radix Sort Base = 2 ^ 4: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB10(n, shuffle_vect);
        file2 << "Radix Sort Base = 10: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_shell_sort(n, shuffle_vect);
        file2 << "Shell Sort: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        r = time_count_sort(n, shuffle_vect);
        file2 << "Count Sort: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            if(r.overflow){
                file2 << "Nu poate sorta\n";
            }
            else{
                file2 << "Sortare esuata!" << "\n";
            }
        }

        r = time_native_sort(n, shuffle_vect);
        file2 << "C++ Native Sort: ";
        if(r.ok){
            file2 << r.time << "\n";
        }
        else{
            file2 << "Sortare esuata!" << "\n";
        }

        file2 << "\n\n";
    }
    ////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////
    ////////// TESTE CU PERMUTARI DE N ELEMENTE APROAPE SORTATE //////////

    ofstream file3("results_perm.txt");

    file3 << "TESTE CU PERMUTARI DE N ELEMENTE APROAPE SORTATE" << "\n\n";
    for(int n = 100000000; n <= 100000000; n *= 10){
        file3 << "N = " << n << "\n\n";
        result r;
        r = time_merge_sort(n, almost_sorted_perm);
        file3 << "Merge Sort: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_quick_sort(n, almost_sorted_perm);
        file3 << "Quick Sort: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 16, almost_sorted_perm);
        file3 << "Radix Sort Base = 2 ^ 16: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 10, almost_sorted_perm);
        file3 << "Radix Sort Base = 2 ^ 10: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 8, almost_sorted_perm);
        file3 << "Radix Sort Base = 2 ^ 8: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB2(n, 4, almost_sorted_perm);
        file3 << "Radix Sort Base = 2 ^ 4: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_radix_sortB10(n, almost_sorted_perm);
        file3 << "Radix Sort Base = 10: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_shell_sort(n, almost_sorted_perm);
        file3 << "Shell Sort: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        r = time_count_sort(n, almost_sorted_perm);
        file3 << "Count Sort: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            if(r.overflow){
                file3 << "Nu poate sorta\n";
            }
            else{
                file3 << "Sortare esuata!" << "\n";
            }
        }

        r = time_native_sort(n, almost_sorted_perm);
        file3 << "C++ Native Sort: ";
        if(r.ok){
            file3 << r.time << "\n";
        }
        else{
            file3 << "Sortare esuata!" << "\n";
        }

        file3 << "\n\n";
    }
    ////////////////////////////////////////////////////

    if(principal != NULL){
        delete[] principal;
        principal = NULL;
    }
    if(vector_to_sort != NULL){
        delete[] vector_to_sort;
        vector_to_sort = NULL;
    }
    return 0;
}