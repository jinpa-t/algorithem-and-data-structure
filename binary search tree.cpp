#include <iostream>
#include <vector>
using namespace std;

struct node{
    int element;
    node* left;
    node* right;

    node(int element){
        this->element = element;
        left= right=NULL;
    }
};

node * insert(node* root, int key){
    
    if(root == nullptr)
        root = new node(key);
    else if(key < root->element)
        root->left = insert(root->left, key);
    else if(key > root->element)
        root->right = insert(root->right, key);
    else
    ;
    return root;
}

bool Bfind(node* root, int key){
    
    if(root == nullptr)
        return false;
    if(root->element == key)
        return true;
    else if(key < root->element)
        Bfind(root->left, key);
    else if(key > root->element)
        Bfind(root->right, key);
    else
        return false;
}


int main(int argc, const char * argv[]) {
    vector<int> myVec {77,200,99,57,69,45,101,67,120,132,87,157,170,12};
       
    //insert to tree
    node * root = new node(myVec[0]);
    for (int i = 1; i < myVec.size(); i++) {
        insert(root,myVec[i]);
    }
    //user input
    int userInput;
    cout << "Enter the number that you would like to find : " << endl;
    cin>> userInput;
    if (Bfind(root, userInput))
        cout << "The number " << userInput << " found" << endl;
    else
        cout << "The number " << userInput << " not found" << endl;
    
    return 0;
        
}
