#include<iostream>

using namespace std;

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int Partition(int A[],int l,int h){
    int pivot;
    int i,j;
    
    pivot=A[l];
    i=l;
    j=h;
    
    do{
        do{
            i++;
        }while(A[i]<=pivot);
    
        do{
            j--;
        }while(A[j]>pivot);
        
        if(i<j)
            swap(&A[i],&A[j]);
        
    }while(i<j);
    
    swap(&A[l],&A[j]);
    
    return j;
    
    
    
}

void QuickSort(int A[],int l,int h){
    int p;
    
    if(l<h){
        p=Partition(A,l,h);
        
        QuickSort(A,l,p-1);
        QuickSort(A,p+1,h);
        
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
    
    QuickSort(A,0,n);

    cout<<"Sorted Elements: ";
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" -> ";
    }
    cout<<endl;
    
    
    return 0;
}
