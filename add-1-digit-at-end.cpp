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

    node* reverse(node* head){
        node* prev = NULL;
        node* curr = head;
        while(curr){
            node* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    node* addOne(node* head){
        head = reverse(head);
        node* current = head;
        int carry = 1;
        while(current && carry){
            int sum = current->data + carry;
            current->data = sum%10;
            carry = sum/10;

            if(current->next == NULL && carry){
                current->next = new node(carry);
                carry = 0;
            }
            current = current->next;
        }
        head = reverse(head);
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
        node* node4 = new node(7);
        node* node3 = new node(5,node4);
        node* node2 = new node(1,node3);
        node* head = node2;
        cout<<"The LL is: ";
        print(head);
        head = addOne(head);
        cout<<"the LL after adding one is:";
        print(head);
        return 0;
    }