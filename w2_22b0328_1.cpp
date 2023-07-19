#include<iostream>
#include<algorithm>
using namespace std;

void merge(long long int arr[], long long int left[], long long int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(long long int arr[], int size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    long long int left[mid];
    long long int right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(arr, left, right, mid, size - mid);
}

void checkmintime(long long int* a, int n, long int t){
    if(t==1) { cout<<a[0]; return; }
    if(n==1) { long long int mintime = a[0]*t; cout<<mintime; return;}
    
    long long int low = 0;
    long long int high = a[n-1]*t;

    while (low <= high) {
        long long int mid = (low + high) / 2;
        long long int products = 0;

        for (int i = 0; i < n; i++)
            products += min(mid / a[i], static_cast<long long int>(t)); // Calculate the number of products produced within time `mid`

        if (products >= t) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout<<low;
    
}
int main(){
    int n;
    long int t;
    cin>>n>>t;
    long long int a[n];
    for(int i=0; i<n; i++)
    cin>>a[i];    //time needed to make a product for ith machine
 
    mergeSort(a,n);

    checkmintime(a,n,t);
}
