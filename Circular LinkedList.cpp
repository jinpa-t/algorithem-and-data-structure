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
            temp->next = NULL;
            tail=temp;
        }
        head = temp;
        size++;
    }
    
    void insert_end(int value){
        node *temp = new node;
        temp->data = value;
        temp->next = head; // point to head
        if (head==NULL){
            temp->next = NULL;
            head = temp;
            tail = temp;
        } else{
            tail->next  = temp;
            tail = temp;
        }
        size++;
    }
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
        if (head != NULL){
            do{
                cout << temp->data << " ";
                temp=temp->next;
            } while(temp!=head);
            cout <<endl;
        }
    }
    
    int getsize(){
        return size;
    }
    
    void delete_position(int position){
        node *cur = head;
        node *pre = new node;
        
        if (position < size) {
            if(position == 1)
            {
                tail->next = cur->next;
                head = cur->next; //new head
            } else {
                for(int i=1;i<position;i++){
                    pre = cur;
                    cur = cur->next;
                }
                pre->next=cur->next;
            }
            delete cur;
            size--;
        } else if (position==size){
            for(int i=1;i<position;i++){
                pre = cur;
                cur = cur->next;
            }
            tail= pre;
            pre->next= head; // point to head
            
            delete cur;
            size--;
        }
    }
};

int main(int argc, const char * argv[]) {
    List myList;
    
    myList.insert_start(50);
    cout << "size:" << myList.getsize() << ",";
    myList.insert_start(40);
    cout << "size:" << myList.getsize() << ",";
    myList.insert_start(30);
    cout << "size:" << myList.getsize() << ",";
    myList.insert_start(20);
    cout << "size:" << myList.getsize() << ",";
    myList.insert_end(100);
    cout << "size:" << myList.getsize() << ",";
    myList.insert_start(10);
    cout << "size:" << myList.getsize() << ",";
    myList.insert_position(25, 6);
    cout << "size:" << myList.getsize() << endl;
    myList.displayList();
    cout << "size:" << myList.getsize() << endl;
    cout << "DELETE position back" << endl;
    myList.delete_position(myList.getsize());
    myList.displayList();
    cout << "size:" << myList.getsize() << endl;
    return 0;
}
