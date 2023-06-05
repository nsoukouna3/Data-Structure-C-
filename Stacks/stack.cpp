#include <iostream>
using namespace std;

class Node{

    public:
        int value;
        Node* next;
    public:
        Node(int value){
            this ->value= value;
            next=nullptr;
        }

};

class Stack{

    public:
        Node* top;
        Node* bottom;
        int height=0;

        Stack(int value){
            Node* newNode= new Node(value);
            top= newNode;
            bottom= newNode;
            height=1;
        }

        void getHeight(){
            cout<<"Height is = "<< height<<endl;
        }

        void getTop(){
            cout<<"Top is = "<<top->value<<endl;
        }

        void printStack(){
            Node* currentNode= top;
            while(currentNode){
                cout<<currentNode->value<<endl;
                currentNode= currentNode->next;
            }
        }

        void push(int value){
            Node* newNode= new Node(value);
            if(height==0){
                bottom= newNode;
                top= newNode;
            }
            else{
                newNode->next= top;
                top= newNode;
            }
            height++;

        }

        int popStack(){
            if(height==0){return -1;}
            Node* currentNode= top;
            int poppedValue= top->value;
            if(height==1){
                top= nullptr;
                delete top;
            }
            else{
                currentNode= top;
                top= top->next;
                delete currentNode;

            }
            
            height--;
            return poppedValue;
        }

};

int main(){
    Stack* myStack= new Stack(1);
    myStack->push(2);
    myStack->push(3);
    cout<<"Pop value is: "<<myStack->popStack() <<endl;;
    myStack->getHeight();
    myStack->getTop();
    myStack->printStack();

    

    return 0;

}
