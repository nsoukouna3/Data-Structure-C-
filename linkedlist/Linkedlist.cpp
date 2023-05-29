#include<iostream>
using namespace std;
//Node class
class Node{

    public:
        // data variable 
        int value;
        Node* next;
    // constructor
        Node(int value){
            this -> value= value;
            next= nullptr;
        }
};
// linkedlist class
class LinkedList{

    private:
        Node*head;
        Node* tail;
        int Length=0;
    public:
         //Constructor 
        LinkedList(int value){
            Node* newNode= new Node(value);
            head= newNode;
            tail=newNode;
            Length=1;
        }
        //Destructor
        ~LinkedList(){
            Node* currentNode= head;
            while(head){
                head= head->next;
                delete currentNode;
                currentNode= head;
            }
        }
        // Prinitng the from the linkedlist
        void printing(){
            Node* currentNode=head;
            while(currentNode){
                cout<<currentNode-> value<<endl;
                currentNode= currentNode->next;
            }
        }
        // get the head value
        void getHead(){
            if(head== nullptr){
                cout<<"Head is empty"<<endl;
            }   
            else{
                cout<<"Head is = "<<head->value<<endl;
            }
        }
        // get the taill value
        void getTail(){
            if(tail==nullptr){
                cout<<"Tail is empty."<<endl;
            }
            else{
                cout<<"Tail is = "<<tail->value<<endl;
            }
        }
        // get the length of the linkedlist
        void getLength(){
            cout<<"Length is = "<< Length<<endl;
        }


        void Append(int value){
            Node* newNode= new Node(value);
            if(head==nullptr){
                head= newNode;
                tail=newNode;
            }
            else{
                tail->next= newNode;
                tail= newNode;
            }
            Length+=1;
        }
        void Prepend(int value){
            Node* newNode= new Node(value);
            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }
            else{
                newNode-> next= head;
                head= newNode;
            }
            Length+=1;

        }
        void deleteLast(){
            if(head==nullptr){
                return;
            }
            Node* currentNode= head;
            if(Length==1){
                head=nullptr;
                tail=nullptr;
            }
            else{
    
                Node* prev= head;
                while(currentNode->next!= nullptr){
                    prev= currentNode;
                    currentNode= currentNode->next;
                }
                tail= prev;
                tail->next= nullptr;
            }

            delete currentNode;
            Length-=1;

        }

    };

int main(){
    LinkedList * myLinkedlist= new LinkedList(3);
    

    myLinkedlist->Append(4);
    myLinkedlist->Append(5);
    myLinkedlist->Append(6);
    myLinkedlist->Append(7);
    myLinkedlist ->Prepend(2);
    myLinkedlist->deleteLast();
    myLinkedlist-> printing();
    myLinkedlist->getHead();
    myLinkedlist ->getTail();
    myLinkedlist->getLength();
   
    return 0;
}  