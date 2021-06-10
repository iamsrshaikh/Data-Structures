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
        void InsertinSorted(int x);
        bool Issorted();
        void RemovingDupicates();
        void Reverse();
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

void SinglyLinked::InsertinSorted(int x){
    Node *q=NULL;
    Node *p=Head;
    Node *t;
    
     while(p && p->data < x){
                q=p;
                p=p->next;
            }
    t=new Node;
    t->data=x;
    t->next=q->next;
    q->next=t;
}


bool SinglyLinked::Issorted(){
    int x=-32786;
    
    Node *p=Head;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next;
    }
    
    return true;
}

void SinglyLinked::RemovingDupicates(){
    Node *p=Head,*q=Head->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
    
}

void SinglyLinked::Reverse(){
    Node *q=NULL,*r=NULL;
    Node *p=Head;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    Head=q;
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
    bool sort;
    do{
        
        cout<<"***********Operation Available************"<<endl<<endl;
        cout<<"1. Display"<<endl;
        cout<<"2. Insert"<<endl;
        cout<<"3. Delete"<<endl;
        cout<<"4. Length"<<endl;
        cout<<"5. Insert in Sorted"<<endl;
        cout<<"6. Is Sorted"<<endl;
        cout<<"7. Remove Duplicates"<<endl;
        cout<<"8. Reverse List"<<endl;
        cout<<"9. Quit"<<endl;
        
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
            cout<<"Enter the element to insert: ";
            cin>>x;
            L.InsertinSorted(x);
            break;
            
            case 6:
            sort=L.Issorted();
            if(sort==true){
                cout<<"List is sorted"<<endl;
            }
            else{
                cout<<"List is Unsorted"<<endl;
            }
            
            break;
            
            case 7:
            L.RemovingDupicates();
            cout<<"Duplicates Removed!"<<endl;
            break;
            
            case 8:
            L.Reverse();
            cout<<"List Reversed"<<endl;
            break;
            
            case 9:
            break;
            
            default:
            cout<<"Enter the valid Choice: "<<endl;
            break;
            
        }
    }while(ch!=9);
    
    
}
