#include <iostream>
#include <vector>

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
    return root;
}

bool Bfind(node* root, int key){
    if(root == nullptr)
        return false;
    if(root->element == key)
        return true;
    else if(key < root->element)
        return Bfind(root->left, key);
    else if(key > root->element)
        return Bfind(root->right, key);
    return false;
}
void display(node* root){
    if(root == nullptr) return;
    std::cout << root->element << " ";
    display(root->left);
    display(root->right);
}

int main(int argc, const char * argv[]) {
    std::vector<int> myVec {77,200,99,57,69,45,101,67,120,132,87,157,170,12};
       
    //insert to tree
    node * root = new node(myVec[0]);
    for (int i = 1; i < myVec.size(); i++) {
        insert(root,myVec[i]);
    }
    display(root);
    //user input
    int userInput;
    std::cout << "Enter the number that you would like to find : " << "\n";
    std::cin>> userInput;
    if (Bfind(root, userInput))
        std::cout << "The number " << userInput << " found" << "\n";
    else
        std::cout << "The number " << userInput << " not found" << "\n";
    
    return 0;
        
}
