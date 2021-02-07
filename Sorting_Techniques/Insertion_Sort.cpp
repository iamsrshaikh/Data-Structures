#include<iostream>

using namespace std;

void insert_sort(int A[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
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
    
    insert_sort(A,n);
    
    
    cout<<"Sorted Elements: ";
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" -> ";
    }
    cout<<endl;
    
    
    return 0;
}
