#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *link = nullptr;
};
class Queue{
    private:
	int size = 0;
    Node *front = NULL;
    Node *back = NULL;
    
    public:
    bool isempty(){
    	if(front == NULL)
    	return true;
    	else
    	return false;
    }
    int get_front(){
        if(isempty())
            return front->data;
        return -999;
    }
    //insert at the back of the link
    void enqueue(int value){ 
    	if(size == 0){
    	    Node *ptr = new Node();
        	ptr->data= value;
        	ptr->link= front;
        	front = ptr;
        	back = ptr;
    	} else {
    	    Node *ptr = new Node();
    	    ptr->data= value;
    	    if (back != NULL){
    	        back->link = ptr;
    	        ptr->link= NULL;
    	        back = ptr;
    	    }
    	}
    	size++;
    }
    //remove at the front of the link
    void dequeue(){
    	if(isempty())
    		cout <<"Queue is empty\n";
    	else {
    		Node *ptr = front;
    		cout << "Dequeued: "<< ptr->data << "\n";
    		front = front->link;
    		delete(ptr);
    		size--;
    	}
    }
    void showFront(){
    	if (isempty())
    		cout << "Queue is empty";
    	else
    		cout <<"Element at the Front: " << front->data << "\n";
    }
};

int main(){
    int vals[] = {5,6,7,10,3,2,0,9,15,23};
    int size = sizeof(vals) / sizeof(vals[0]);
    Queue myQueue;
    for(int i = 0; i < size ;i++ ) {
        myQueue.enqueue(vals[i]);
    }
    // remove two element
	myQueue.dequeue();
	myQueue.dequeue();
  	myQueue.showFront();
	return 0;
}
