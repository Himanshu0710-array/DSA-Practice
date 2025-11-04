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


node* removeMiddle(node* head){
    node* slow = head;
    node* fast = head->next->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
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
    cout<<"the LL before the deletion of the node: ";
    print(head);
    cout<<"the seggregated LL is: ";
    head = removeMiddle(head);
    print(head);
    return 0;
}



