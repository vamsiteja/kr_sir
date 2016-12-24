
#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
} *LPTR;

void addend(LPTR L, int d){
    LPTR T;
    T = L;
    while(T->next != NULL){
        T = T->next;
    }
    T->next = new(struct node);
    T = T->next;
    T->data= d;
    T->next = NULL;
}

void addbeg(LPTR L, int d){
    
    LPTR T2;
    T2 = new(struct node);
    T2->data = d;
    T2->next = L;
    L = T2;
    return ;
    
}

void deletenode(LPTR L, int d){
    LPTR T;
    T = L->next;
    L->next = L->next->next;
    delete T;
    
}

void removedup(LPTR L){
    LPTR T,Q;
    T = L;
    while(T != NULL && T->next != NULL){
        Q = T;
        while(Q->next != NULL){
            if(Q->next->data == T->data){
                deletenode(Q, T->data);
            }else{
                Q = Q->next;
            }
        }
        T = T->next;
    }
    
}

int main(){
    LPTR L;
    int d;
    L = new(struct node);
    L->next = NULL;int z;
    
    cout<<"enter the number of elements"<<endl;cin>>z;
    cout<<"Enter the value of data: ";
    cin>>d;
    L->data = d;
    
    for(int y=0;y<z-1;y++)
       {
		cout<<"Enter the value of data  ";
        cin>>d;
        
            addend(L,d);
        }
    
    
    removedup(L);
    
    LPTR T = L;
    while(T != NULL){
        cout<<T->data<<" ";
        T = T->next;
    }
    
    return 0;
}
