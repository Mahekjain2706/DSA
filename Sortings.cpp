#include<bits/stdc++.h>
using namespace std;

// Selection Sort
void selectionSort(vector<int> &arr){
    int n = arr.size();

    
    for(int i=0;i<n;i++){
        int x=0;int mini = INT_MAX;
        for(int j=i;j<n;j++){
            if(arr[j]<mini){
                mini = arr[j];
                x = j;
            }
        }
        swap(arr[i],arr[x]);
    } 
}

// bubble Sort
void bubbleSort(vector<int> &arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}

// Insertion Sort
void insertSort(vector<int> &arr){
    int j;
    for(int i=0;i<arr.size();i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}


// Merge Sort
void merge(vector<int> &arr,int l,int mid,int r){
    int n = arr.size();
    int k = 0,i=l,j=mid+1;
    vector<int> temp(n,0);

    while(i<=mid && j<=r){
        if(arr[j]>=arr[i]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];

    for(int i=l;i<=r;i++){
        arr[i] = temp[i-l];
    }
}
void mergeSort(vector<int> &arr,int l ,int r){
    if(l>=r) return ;
    if(l<r){
        int mid = ( l + r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

// Quick Sort
int partition(vector<int> &arr,int l,int r){
    int pi = arr[l];
    int i = l,j=r;

    while(i<j){
        while(arr[i]<=pi && i<r){
            i++;
        }
        while(arr[j]>pi && j>=l){
            j--;
        }
        if(i<j) swap(arr[j],arr[i]);
    }
    swap(arr[j],arr[pi]);
    return j;
}
void quickSort(vector<int> &arr,int l,int r){
    if(l<=r){
        int pivot = partition(arr,l,r);
        quickSort(arr,l,pivot-1);
        quickSort(arr,pivot+1,r);
    }
}

int main(){
    int n ; cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        arr.push_back(a);
    }

    // insertSort(arr);
    // bubbleSort(arr);
    selectionSort(arr);
    // mergeSort(arr,0,n-1);
    // quickSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i] << " ";

    return 0;
}