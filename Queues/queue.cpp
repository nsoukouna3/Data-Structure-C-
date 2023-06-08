#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value){
            this->value= value;
            next=nullptr;
        }
};

class Queues{

    private:
        Node* first;
        Node* last;
        int length=0;
    public:
        Queues(int value){
            Node* newNode= new Node(value);
            first= newNode;
            last= newNode;
            length=1;
        }
        void printQueue(){
            Node* currentNode= first;
            while(currentNode){
                cout<<currentNode->value<<endl;
                currentNode=currentNode->next;
            }
        }

        void enqueue(int value){
            Node* newNode= new Node(value);
            if(first==nullptr){
                first=newNode;
                last=newNode;
            }
            else{
                last->next= newNode;
                last=newNode;
            }
            length+=1;

        }

        int dequeue(){
            if(length==0){return INT_MIN;}
            Node* currentNode= first;
            int currentNodeValue= first->value;
            if(length==1){
                first=nullptr;
                last=nullptr;
            }
            else{
                first= first->next;
              
            }
            delete currentNode;
            length--;
            return currentNodeValue;
        }

};


int main(){
    Queues* myQueue= new Queues(1);
    myQueue->enqueue(2);
    myQueue-> enqueue(3);
    
    cout<<"Dequeue value: "<<myQueue->dequeue()<<endl;

    myQueue ->printQueue();
    
    return 0;
}