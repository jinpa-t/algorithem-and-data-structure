
#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    
};

class List{
private:
    int size;
    node *head;
    node *tail;
public:
    List(){
        head = NULL; //The constructer will make them NULL to avoid any garbage value.
        tail = NULL;
        size=0;
    }
    
    void insert_start(int value){
        node *temp = new node();
        temp->data = value;
        temp->next = head;
        if (head==NULL){
            tail=temp;
        }
        head = temp;
        
        size++;
    }
    
    void insert_end(int value){
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head==NULL){
            head = temp;
            tail = temp;
            temp=NULL;
        } else{
            tail->next  = temp;
            tail = temp;
        }
        size++;
        
    }
    //Solution for Ex#3
    void insert_position(int value, int position){
        if (position < size) {
            node *cur = head;
            node *temp = new node();
            node *pre = new node();
            for(int i=1; i<=position; i++){
                pre=cur;
                cur=cur->next;
            }
            pre->next=temp;
            temp->data=value;
            temp->next=cur;
            size++;
            
            
        } else if(position == size){
            insert_end(value);
        }
    }
    
    void displayList (){
        
        node *temp = new node;
        temp =head;
        while(temp!=NULL){
            cout << temp->data << endl;
            temp=temp->next;
        }
        
    }
    int getsize(){
        return size;
    }
    
    //Solution for Ex#3
    void delete_position(int position){
        node *cur = head;
        node *pre = new node;
        
        if (position < size) {
            for(int i=1;i<position;i++){
                pre=cur;
                cur=cur->next;
            }
            pre->next=cur->next;
            cur=NULL;
            
            size--;
        } else if (position==size){
            for(int i=1;i<position;i++){
                pre=cur;
                cur=cur->next;
            }
            tail=pre;
            pre->next=NULL;
            
            delete cur;
            
            
            size--;
        }
    }
    
    bool isEmpty(){
        //returns true if the list is empty; it returns false otherwise.
        
        if(size == 0) return true;
        return false;
    }
    
    int front(){
        //returns the data of the first element, if the list is empty return 0.
        
        if(isEmpty()) {
            return 0;
        }
        //first element
        struct node *temp = new node;
        temp = head;
        return temp->data;
    }
    
    int back(){
        //returns the data of the last element, if the list is empty return 0.
        
        if(isEmpty()){
            return 0;
        }
        //last element
        return tail->data;
    }
    
    int findKth(int pos) {
        //returns the element at position pos. If the position pos is greater than the size of the list, return 0.
       
        if(pos > size) return 0;
        else {
            //find by position
            if (pos < size) {
            node *cur = head;
            node *pre = new node();
            for(int i=1; i<=pos; i++){
                pre=cur;
                cur=cur->next;
                if(i == pos) {
                    return cur->data;
                }
            }
  
        } else if(pos == size){
            return back();
        }
           
        }
         
    }   //end of find position
    
    int find(int value) {
        //returns the position of the first occurrence of value, if the element cannot be found, return 0.
        //INSERT CODE HERE!!!
        node *temp = new node;
        temp =head;
        int holder;
        int tracker = 0;
        while(temp!=NULL){
            tracker++;
            holder = temp->data;
            
            if(value == holder) {
                return tracker;
            }
            
            temp=temp->next;
        }
        return 0;
    }
};


int main(int argc, const char * argv[]) {
    
    //DO NOT MODIFY THE FOLLOWING CODE
    List myList;
    
    //Check if myList is empty
    cout << "myList is empty? " << (myList.isEmpty()? "true": "false") << endl;
    cout << "Size is :" << myList.getsize() << endl;
    
    //Print out the FIRST element in the list
    cout << "First element is :" << myList.front() << endl;
    
    //Print out the LAST element in the list
    cout << "Last element is :" << myList.back() << endl;
    
    
    cout << endl << "=======================" << endl << endl;
    
    //Insert 50, 40, 30, 20, 10 to the list
    myList.insert_start(50);
    myList.insert_start(40);
    myList.insert_start(30);
    myList.insert_start(20);
    myList.insert_start(10);
    //List now becomes 10 -> 20 -> 30 -> 40 -> 50
    
    //Check again if myList is empty
    cout << "myList is empty? " << (myList.isEmpty()? "true": "false") << endl;
    cout << "Size is :" << myList.getsize() << endl;
    
    //Print out the first element in the list
    cout << "First element is :" << myList.front() << endl;
    
    //Print out the LAST element in the list
    cout << "Last element is :" << myList.back() << endl;
    
    cout << endl << "=======================" << endl << endl;
    
    //Insert 5 more numbers onto the list
    myList.insert_end(60);
    myList.insert_end(70);
    myList.insert_end(80);
    myList.insert_end(90);
    myList.insert_end(100);
    
    //Check again if myList is empty
    cout << "myList is empty? " << (myList.isEmpty()? "true": "false") << endl;
    cout << "Size is :" << myList.getsize() << endl;
    
    //Print out the first element in the list
    cout << "First element is :" << myList.front() << endl;
    
    //Print out the LAST element in the list
    cout << "Last element is :" << myList.back() << endl;
    
    cout << endl << "=======================" << endl << endl;
    
    cout << "100 is at position :" << myList.find(100) << endl;
    cout << "10 is at position :" << myList.find(10) << endl;
    cout << "60 is at position :" << myList.find(60) << endl;
    cout << "120 is at position :" << myList.find(120) << endl;
    
    cout << endl << "=======================" << endl << endl;

    cout << "Data at position 2 is :" << myList.findKth(2) << endl;
    cout << "Data at position 10 is :" << myList.findKth(10) << endl;
    cout << "Data at position 5 is :" << myList.findKth(5) << endl;
    cout << "Data at position 8 is :" << myList.findKth(8) << endl;

    cout << endl << "=======================" << endl << endl;
    cout << "Display List" << endl;
    myList.displayList();


    return 0;
}
