#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data1){
        data = data1;
    }
    // Node(int data1 , Node* next1){
    //     data = data1;
    //     next = next1;
    // }
};
class Queue{
    private:
        Node* start;
        Node* end;
        int size;
        
        
    public:
        Queue(){
            size = 0;
            start = end = NULL;
        }
        void push(int x){
            Node* ele = new Node(x);
            if(start == NULL && end == NULL){
                start = end = ele;
            }
            else{
                end->next = ele;
                end = ele;
            }
            size++;
        }
        int pop(){
            if(start == NULL){
                return -1;
            }
            int val = start->data;
            Node* temp = start;
            start = start->next;
            delete temp;
            size--;
            return val;
        }
        int top(){
            if(start == NULL){
                return -1;
            }
            return start->data;
        }
        bool isEmpty(){
            return (size==0);
        }
};
int main() {
    // Creating a queue
    Queue q;

    // List of commands
    vector<string> commands = {"LinkedListQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {3}, {7}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "LinkedListQueue") {
            cout << "null ";
        }
    }

    return 0;
}