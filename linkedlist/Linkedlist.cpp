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

        void deleteFirst(){
            if(head==nullptr){
                return;
            }
            Node* currentNode= head;
            if(Length==1){
                head=nullptr;
                tail=nullptr;
            }
            else{
                head= head->next;   
            }
            delete currentNode;
            Length-=1;

        }
        int get(int index){
            if(index<0 || index>= Length){
                return -1;
            }
            Node* currentNode=head;
            if(index==0){
                return head->value;
            }
            else{
                for(int i=1; i<index;i++){
                    currentNode=currentNode->next;
                }
                return currentNode->value;
            }

        }

        bool set(int index, int value){
            Node* newNode= new Node(value);
            if(index<0 || index>Length){return false;}
            if(head==nullptr){
                head= newNode;
                tail=newNode;
                return true;
            }
            if(index==0){
                head->value= newNode->value;
                return true;
            }
            else{
                Node* currentNode= head;
                for(int i=0; i<index; i++){
                    currentNode=currentNode->next;
                }
                currentNode->value= newNode->value;
                return true;
            }
            

        }
        bool insert(int index, int value){
            Node* newNode= new Node(value);
            if(index<0||index>=Length){return false;}
            Node* currentNode= head;
            Node*prev=nullptr;
            if(index==0){
                newNode->next=head;
                head=newNode;
            }
            else if(index==Length){
                tail->next= newNode;
                tail= newNode;
            }
            else{
                for(int i=0; i<index; i++){
                    currentNode= currentNode->next;
                }
                newNode->next=currentNode->next;
                currentNode->next=newNode;
                
            }
            Length+=1;
            return true;

        }

    };

int main(){
    LinkedList * myLinkedlist= new LinkedList(3);
    

    myLinkedlist->Append(4);
    myLinkedlist->Append(5);
    //myLinkedlist->Append(6);
    //myLinkedlist->Append(7);
    //myLinkedlist ->Prepend(2);
    //myLinkedlist -> deleteLast();
   // myLinkedlist->deleteFirst();
   myLinkedlist-> set(0,9);
   myLinkedlist->insert(2,1);
    myLinkedlist-> printing();
    myLinkedlist->getHead();
    myLinkedlist ->getTail();
    myLinkedlist->getLength();
    
    cout<<"Index value = "<<myLinkedlist->get(0)<<endl;
   
    return 0;
}  