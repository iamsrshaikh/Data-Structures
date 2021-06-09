#include<iostream>


using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class SinglyLinked{
    private:
        Node *Head;
    public:
        SinglyLinked(){
            Head=NULL;
        }
        
        SinglyLinked(int A[],int n);
        
        void Display();
        void Insert(int index,int x);
        int Delete(int index);
        int Length();
};

SinglyLinked::SinglyLinked(int A[],int n){
    Node *temp,*tail;
    int i=0;
    Head=new Node;
    Head->data=A[0];
    Head->next=NULL;
    tail=Head;
    
    
    for(i=1;i<n;i++){
        temp=new Node;
        temp->data=A[i];
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
    
}

int SinglyLinked::Length(){
    int c=0;
    Node *p=Head;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void SinglyLinked::Display(){
    Node *p=Head;
    while(p!=NULL){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<endl;
}

void SinglyLinked::Insert(int index,int x){
    Node *temp,*p=Head;
    if(index<0 || index>Length())
        return;
    
    temp=new Node;
    temp->data=x;
    temp->next=NULL;
    if(index==0){
        temp->next=Head;
        Head=temp;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}

int SinglyLinked::Delete(int index){
    int x=-1;
    Node *p,*q=NULL;
    
    if(index<0 || index>Length())
        return -1;
    if(index==0){
        p=Head;
        Head=p->next;
        x=p->data;
        delete p;
    }
    
    else{
        p=Head;
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    
    return x;
}

int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int A[n];
    cout<<"Enter the data"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    SinglyLinked L(A,n);
    int ch,len,x,index,res;
    do{
        
        cout<<"***********Operation Available************"<<endl;
        cout<<"1. Display"<<endl;
        cout<<"2. Insert"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Length"<<endl;
        cout<<"5. Quit"<<endl;
        
        cout<<"Enter the choice: ";
        cin>>ch;
        
        switch(ch){
            case 1: 
            L.Display();
            break;
            
            case 2:
            cout<<"Enter the element to insert: ";
            cin>>x;
            cout<<"Enter the index: ";
            cin>>index;
            L.Insert(index,x);
            break;
            
            
            case 3: 
            cout<<"Enter the index: "<<endl;
            cin>>index;
            res=L.Delete(index);
            cout<<"Deleted element: "<<res<<endl;
            
            break;
            
            
            
            case 4:
            len=L.Length();
            cout<<"Length of List: "<<len<<endl;
            break;
            
            case 5:
            break;
            
            default:
            cout<<"Enter the valid Choice: "<<endl;
            break;
            
        }
    }while(ch!=5);
    
    
}
