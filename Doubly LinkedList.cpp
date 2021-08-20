#include <iostream>
using namespace std;
struct node{
    int data;
    node *pre;
    node *next;
};
class List{
    private:
        int size;
        node *head;
        node *tail;
    public:
        List()
        {
            head = tail = NULL;
            size = 0;
        }
        void insert_start(int value){
            node *temp = new node();
            temp->data = value;
            temp->pre = temp->next = NULL;
            if(head != NULL)
            {
                head->pre = temp; // point to new head
                temp->next = head;
                head = temp; // set new head
            } else {
                head = tail = temp;
            }
            size++;
        }
        void insert_end(int value){
            node *temp = new node();
            temp->data = value;
            temp->next = temp->pre = NULL;
            if(tail != NULL) // attach the node
            {
                tail->next = temp;
                temp->pre = tail;
                tail = temp;
            }else {
                tail = head = temp; // first node
            }
            size++;
        }
        void insert_pos(int position, int value) // can't insert at end
        {
            node *temp = new node();
            temp->data = value;
            if(position == 1){
                temp->pre = NULL;
                temp->next = head;
                head->pre = temp;
                head = temp;
                size++;
            } else if(position < size){
                node *cur = head;
                node *pre = new node();
                for (int i = 2; i <= position; i++) {
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = temp;
                temp->pre = pre;
                temp->next = cur;
                cur->pre = temp;
                size++;
            }
        }
        void delete_position(int position)
        {
            node *cur = head;
            node *pre = new node();
            if(position == 1){
                cur->next->pre = NULL;
                head = cur->next;
                cur->next = NULL;
                delete cur;
                size--;
            } else if(position < size){
                for (int i = 1; i < position; i++) {
                    pre = cur;
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur->next->pre = pre;
                delete cur; //= NULL;
                size--;
            } else if(position == size)
            {
                for (int i = 1; i < position; i++) {
                    pre = cur;
                    cur = cur->next;
                }
                tail = pre;
                pre->next = NULL;
                size--;
                delete cur;
            }
        }
        int list_size(){
            return size;
        }
        void print_list(){
            node *temp = head;
            while(temp != NULL)
            {
                std::cout << temp->data;
                if(temp != tail)
                    std::cout<< "->";
                temp = temp->next;
            }
            std::cout <<"\n";
        }
        bool isEmpty()
        {
            if(size== 0)
                return true;
            return false;
        }
        int front(){
            if(isEmpty()){
                return 0;
            }
            return head->data;
        }
        int back(){
            if(isEmpty()){
                return 0;
            }
            return tail->data;
        }
        int findKthItem(int pos)
        {
            if(pos == 1)
            {
                return front();
            }
            if(pos > size){
                return 0;
            } else {
                if( pos < size)
                {
                    node *cur = head;
                    node *pre = new node();
                    for (int i = 2; i <= pos; i++) {
                        pre = cur;
                        cur = cur->next;
                        if(i == pos){
                            return cur->data;
                        }
                    }
                }
                else if(pos == size)
                {
                    return back();
                }
            }
        }
        int find(int value){
            node *temp = head;
            int tracker= 0;
            while(temp!= NULL)
            {
                tracker++;
                if(value == temp->data)
                {
                    return tracker;
                }
                temp = temp->next;
            }
            return -1;
        }
};
int main()
{
    List ll;
    ll.insert_end(6);
    ll.insert_start(10);
    ll.insert_start(21);
    ll.insert_pos(1,4);
    ll.insert_pos(3,8);
    ll.print_list();
    ll.delete_position(1);
    ll.print_list();
    std::cout <<"List Size:" << ll.list_size() << std::endl;
    std::cout <<"Empty: " << (ll.isEmpty()? "Yes":"No") << std::endl;
    std::cout <<"Front: " << ll.front()<< std::endl;
    std::cout <<"Back: " << ll.back() << std::endl;
    std::cout <<"1st: " << ll.findKthItem(1) << std::endl;
    std::cout <<"3rd: " << ll.findKthItem(3) << std::endl;
    std::cout <<"4th: " << ll.findKthItem(4) << std::endl;
    std::cout <<"10 found at index: " << ll.find(10) << std::endl;
    return 0;
}
