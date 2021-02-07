#include<iostream>

using namespace std;

void insert(int A[],int n){
    int i=n;
    int temp;
    temp=A[i];
    
    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
    
}

int Delete(int A[],int n){
    int i,x,val,j;
    int temp;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;
    j=i*2;
    
    while(j<n-1){
        if(A[j+1]>A[j])
            j=j+1;
        
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
            
    }
    
    return val;
    
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
    
    for(int i=n;i>1;i--)
        Delete(A,i);
    
    cout<<"Sorted Elements: ";
    for(int i=1;i<=n;i++)
        cout<<A[i]<<" ";
    
    cout<<endl;
   
    
    return 0;
}
