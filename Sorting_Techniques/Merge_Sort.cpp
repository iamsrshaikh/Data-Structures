#include<iostream>

using namespace std;

void Merge(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=l;
    int B[h+1];
    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
            
    }
    
    for(;i<=mid;i++)
        B[k++]=A[i];
        
    for(;j<=h;j++)
        B[k++]=A[j];
        
    for(i=l;i<=h;i++)
        A[i]=B[i];
    
    
}

//Iterative Merge Sort Function

void IterativeMerge(int A[],int n){
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<n;i=i+p){
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,(p/2)-1,n-1);
}

void RecursiveMerge(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        RecursiveMerge(A,l,mid);
        RecursiveMerge(A,mid+1,h);
        Merge(A,l,mid,h);
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
    
 //   IterativeMerge(A,n);
    
    RecursiveMerge(A,0,n-1);

    cout<<"Sorted Elements: ";
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" -> ";
    }
    cout<<endl;
    
    
    return 0;
    
    return 0;
}
