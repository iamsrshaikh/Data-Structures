#include<iostream>

using namespace std;

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void SelectionSort(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k])
                k=j;
        }
        swap(A[i],A[k]);
    }
}


int main(){
    int n;
    cout<<"Enter the size of Array: "<<endl;
    cin>>n;
    
    int A[n];
    
    cout<<"Enter the elements: "<<endl;
    
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    
    cout<<"Array Elements: ";
    for(int i=0;i<n;i++){
        cout<<A[i]<<" -> ";
    }
    cout<<endl;
    
    
    SelectionSort(A,n);
    
    cout<<"Sorted Elements: ";
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" -> ";
    }
    cout<<endl;
    
    
   
    
    return 0;
}
