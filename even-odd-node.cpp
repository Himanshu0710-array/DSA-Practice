#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data1,node* next1){
        data = data1;
        next = next1;
    }
    node(int data1){
        data = data1;
        next = nullptr;
    }
};


node* seperate(node* head){
    node* oddHead = head;
    node* evenHead = head->next;
    node* odd = oddHead;
    node* even = evenHead;

    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return oddHead;
}
void print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"nullptr"<<endl;
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    cout<<"the LL is: ";
    print(head);
    cout<<"the seggregated LL is: ";
    head = seperate(head);
    print(head);
    return 0;
}