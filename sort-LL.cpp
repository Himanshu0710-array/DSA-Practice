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


node* merge(node* list1 , node* list2){
    node* dummy = new node(-1);
    node* temp = dummy;
    while(list1 && list2){
        if(list1->data <= list2->data){
            temp->next = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1 != NULL){
        temp->next = list1;

    }
    else if(list2 != NULL){
        temp->next = list2;
    }
    return dummy->next;
}
node* findMiddle(node*head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;

}
node* sortLL(node* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    node* middle = findMiddle(head);
    node* right = middle->next;
    middle->next = nullptr;
    node* left = head;

    left = sortLL(left);
    right = sortLL(right);
    return merge(left,right);
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
    node* head = new node(3);
    head->next = new node(1);
    head->next->next = new node(2);
    head->next->next->next = new node(5);
    head->next->next->next->next = new node(4);
    cout<<"the LL before sorting: ";
    print(head);
    cout<<"the sorted LL is: ";
    head = sortLL(head);
    print(head);
    return 0;
}



