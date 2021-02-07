#include<iostream>

using namespace std;

void insert(int A[],int n){
    int i=n;
    int temp;
    temp=A[i];
    
    while(i>1 && temp<A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
    
}



int main(){
    int n;
    cout<<"Enter the size of Array: "<<endl;
    cin>>n;
    
    int A[n];
    
    cout<<"Enter the elements: "<<endl;
    
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    
    for(int i=2;i<=n;i++){
        insert(A,i);
    }
    
    cout<<"Min Heap: ";
    for(int i=1;i<=n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}
