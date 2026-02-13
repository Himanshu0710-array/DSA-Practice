#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int start , end;
        int currSize , size;
        int * q;
    public:
        Queue(){
            start = end = -1;
            q = new int[10];
            currSize = 0;
            size = 10;
        }
        void push(int x){
            if(currSize == size){
                cout << "Queue is full\nExiting..." << endl;
                exit(1);
            }
            if(currSize == 0){
                start = 0;
                end = 0;
            }
            else{
                end = (end+1)%size;
            }
            q[end] = x;
            currSize ++;
        }
        int pop(){
            if(currSize == 0){
                cout<<"no element is present";
            }
            int el = q[start];
            if(currSize == 1){
                start = end = -1;
            }
            else{
                start = (start+1)%size;
            }
            currSize--;
            return el;
            
        }
        int top(){
            if(start == -1){
                cout<<"the queue is empty";
                return -1;
            }
            return q[start];
        }
        bool isEmpty(){
            return (currSize==0);
        }
};
int main() {
    Queue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", 
                               "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }

    return 0;
}
