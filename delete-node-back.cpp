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


node* remove(node* head,int k){
    node* dummy = new node(0,head);
    node* slow = dummy;
    node* fast = dummy;
    for(int i=0;i<=k;i++){
        fast = fast->next;
    }
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
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
    int k = 2;
    cout<<"the LL before the deletion of the node: ";
    print(head);
    cout<<"the seggregated LL is: ";
    head = remove(head,k);
    print(head);
    return 0;
}