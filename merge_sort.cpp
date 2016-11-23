#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void mergeSort(int data[], int low, int high);
void merge(int data[],int low, int mid, int high);
void printData(int data [], int size);
int main()
{
    int data [100];
    int size_data = sizeof(data)/sizeof(data[0]);
    srand(time(0));

    for(int i = 0; i < 100; i++){
        data[i] = rand() % 100;
    }
    printData(data, size_data);
    cout << "\n" << endl;

    mergeSort(data, 0, size_data);

    printData(data, size_data);
    cout << endl;
    return 0;

}

void mergeSort(int data [], int low, int high)
{
    if (low < high){
        int mid = (low+high-1)/2;

        /*Recursive divide*/
        mergeSort(data, low, mid);
        mergeSort(data, mid+1, high);

        /*Begin Merge*/
        merge(data,low, mid, high);
    }
}

void merge(int data [], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    /*Temp array creation*/
    int left [n1];
    int right [n2];

    for(int i = 0; i < n1; ++i){
        left[i] = data[low+i];
    }
    for(int j = 0; j < n2; ++j){
        right[j] = data[mid+1+j];
    }

    /*Merge temp arrays into original*/
    int i = 0;
    int j = 0;
    int k = low;

    while(i < n1 && j <n2){
        if (left[i] <= right[j]){
            data[k] = left[i];
            ++i;
        }
        else{
            data[k] = right[j];
            ++j;
        }
        ++k;
    }

    /*Merge any elements left in temporary arrays*/
    while(i < n1) {
        data[k] = left[i];
        ++i;
        ++k;
    }
    while(j < n2){
        data[k] = right[j];
        ++j;
        ++k;
    }
}

void printData(int data [], int size){
    for(int i = 0; i < size; i++){
        cout << data[i] << " ";
    }
}
