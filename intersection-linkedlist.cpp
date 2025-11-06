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

    // node* intersection(node* head1,node* head2){
    //     while(head2){
    //         node* temp = head1;
    //         while(temp){
    //             if(head2 == temp){
    //                 return head2;
    //             }
    //             temp = temp->next;
    //         }
    //         head2 = head2->next;
    //     }
    //     return NULL;
    // }
    // node* intersection(node* head1,node* head2){
    //     unordered_set<node*> st;
    //     node* temp = head1;
    //     while(temp){
    //         st.insert(temp);
    //         temp = temp->next;
    //     }
    //     temp = head2;
    //     while(temp){
    //         if(st.find(temp) != st.end()){
    //             return temp;
    //         }
    //         temp = temp->next;
    //     }
    //     return NULL;

    // }
    int getDiff(node* head1 , node* head2){
        int len1 = 0 , len2 = 0;
        while(head1 || head2){
            if(head1 != NULL){
                len1++;
                head1 = head1->next;
            }
            if(head2 != NULL){
                len2++;
                head2 = head2->next;
            }
            return len1 - len2;
        }
    }
    node* intersection(node* head1 , node* head2){
        int diff = getDiff(head1,head2);
        if(diff < 0){
            while(diff++ != 0){
                head2 = head2->next;
            }
        }
        else{
            while(diff-- != 0){
                head1 = head1->next;
            }
        }
        while(head1){
            if(head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return NULL;
    }
    void print1(node* head1){
        node* temp = head1;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }
    void print2(node* head2){
        node* temp = head2;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"nullptr"<<endl;
    }
    int main(){
        node* node4 = new node(4);
        node* node3 = new node(3,node4);
        node* node2 = new node(2,node3);
        node* node1 = new node(1,node2);
        node* node5 = new node(5,node2);
        node* head1 = node1;
        node* head2 = node5;
        cout<<"THe first LL is: ";
        print1(head1);
        cout<<endl;
        cout<<"The second LL is:";
        print2(head2);
        cout<<"the intersection between them is:";
        node* ans = intersection(head1,head2);
        cout<<ans->data;
        return 0;
    }