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
        insert(root->left, key);
    else if(key > root->element)
        insert(root->right, key);
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

void displayVector(const vector<int> & vec){
    
    for(int i=0 ; i< vec.size(); i++){
        cout <<  vec[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> & vec){

    int i, temp, j; 
   for (i = 1; i < vec.size(); i++)
   { 
       temp = vec[i];
       for (j = i; j > 0 && temp < vec[j-1]; j--) 
       { 
           vec[j] = vec[j-1];
       }
       vec[j] = temp;  
   }
}

int main(int argc, const char * argv[]) {
    vector<int> myVec {77,200,99,57,69,45,101,67,120,132,87,157,170,12};
    cout << "Unsorted array is  :"<< endl;
    displayVector(myVec);
    
    cout << "Sorted array is  :"<< endl;
    insertionSort(myVec);
    displayVector(myVec);
    
    //insert to tree
    node * root = new node(myVec[0]);
    for (int i = 1; i < myVec.size(); i++) {
        insert(root,myVec[i]);
    }
    //user input
    int userInput;
    cout << "Enter the number that you would like to find : " << endl;
    cin>> userInput;
    Bfind(root, userInput);
    
    if (Bfind(root, userInput) == 0) {
        cout << "The number " << userInput << " cannot be found!" << endl;
    }
    else 
        cout << "The number " << userInput << " found at index " << Bfind(root, userInput) << endl;
    
    return 0;
        
}
