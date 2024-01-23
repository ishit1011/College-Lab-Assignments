#include<bits/stdc++.h>
using namespace std;

// To make a max heap
void heapify(vector<int>arr,int i){
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    int n = arr.size();
    if(leftChild < n && arr[largest] < arr[leftChild]){
        largest = leftChild;
    }

    if(rightChild < n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest);
    }
}

void heapSort(vector<int> &vec,int n){
    for(int i=n/2; i>0; i++){
        heapify(vec,i);
    }
    for(int i=n-1; i>0; i--){
        swap(vec[i],vec[0]);
        heapify(vec,0);
    }
}

int main()
{
    vector<int>vec;
    int num;
    vec.push_back(-1);
    for(int i=1; i<5; i++){
        cin>>num;
        vec.push_back(num);
    }
    int n = vec.size();
    heapSort(vec,n);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<endl;
    }

    return 0;
}