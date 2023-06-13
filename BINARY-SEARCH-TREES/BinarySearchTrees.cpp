#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value= value;
            left=nullptr;
            right=nullptr;
        }

};

class BinarySearchTrees{
    public:
        Node* root;
    
    public:
        BinarySearchTrees(){
            Node* root=nullptr;
           
        }

        bool insert(int value){
            Node* newNode= new Node(value);
            if(root==nullptr){
                root= newNode;
            }
            Node* currentNode= root;
            while(true){
                if(currentNode->value== newNode-> value){return false;}
                if(newNode->value< currentNode->value){
                    if(currentNode->left==nullptr){
                        currentNode->left=newNode;
                        return true;
                    }
                    currentNode=currentNode->left;
                }
                else{
                    if(currentNode->right==nullptr){
                        currentNode->right= newNode;
                        return true;
                    }
                    currentNode=currentNode->right;
                }
            }

        }

        bool contains(int value){
            if(root== nullptr){return false;}
            Node* currentNode= root;
            while(currentNode){
                if(currentNode->value > value){
                    currentNode= currentNode->left;
                }
                else if(currentNode->value< value){
                    currentNode= currentNode->right;
                }
                else{
                    return true;
                }
            }
            return false;
        }
        void breadthFirstSearch(){
            queue<Node*>myQueue;
            myQueue.push(root);
            while(myQueue.size()>0){
                Node* currentNode= myQueue.front();
                myQueue.pop();
                cout<<currentNode->value<<endl;
                if(currentNode->left!= nullptr){
                    myQueue.push(currentNode->left);
                }
                if(currentNode->right!= nullptr){
                    myQueue.push(currentNode->right);
                }

            }

        }
};

int main(){
    BinarySearchTrees* myBinary= new BinarySearchTrees();
    myBinary->insert(47);
    myBinary->insert(21);
    myBinary->insert(76);
    myBinary->insert(18);
    myBinary->insert(27);
    myBinary->insert(52);
    myBinary->insert(82);
    cout<<"root value: "<<myBinary->root->value<<endl;
    cout<<"left value: "<<myBinary->root->left->value<<endl;
    cout<<"right value: "<<myBinary->root->right->value<<endl;
    myBinary->breadthFirstSearch();
    return 0;
}