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
class himanshu{
    public:
        node* reverse(node* head){
            node* prev = NULL;
            node* curr = head;
            node* next = NULL;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
        bool palindrome(node* head){
            if (head == NULL || head->next == NULL) {
                return true; 
            }
            node* slow = head;
            node* fast = head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            node* newHead = reverse(slow->next);

            node* first = head;
            node* second = newHead;

            while(second){
                if(first->data != second->data){
                    reverse(newHead);  
                    return false;
                }
                first = first->next;
                second = second->next;
            }
            reverse(newHead);  
            return true;
        }
        void print(node* head){
            node* temp = head;
            while(temp){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"nullptr"<<endl;
        }
};
int main(){
    himanshu hi;
    node* head = new node(1);
    head->next = new node(5);
    head->next->next = new node(2);
    head->next->next->next = new node(5);
    head->next->next->next->next = new node(1);
    cout<<"The LL is: ";
    hi.print(head);
    if(hi.palindrome(head)){
        cout<<"the LL is palindrome";
    }
    else{
        cout<<"The LL is not palindrome";
    }
    return 0;
}