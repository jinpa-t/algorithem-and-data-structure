#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *link;
};
Node *top = NULL;
bool isempty(){
	if(top == NULL)
	return true;
	else
	return false;
}

void push(int value){
	Node *ptr = new Node();
	ptr->data= value;
	ptr->link= top;
	top = ptr;
}

void pop(){
	if(isempty())
		cout <<"Stack is empty";
	else {
		Node *ptr = top;
		top = top->link;
		delete(ptr);
	}
}

void showTop(){
	if (isempty())
		cout << "Stack is empty";
	else 
		cout <<"Element at top is " << top->data;

}
int main(){
	push(1);
	push(2);
	pop();
  	showTop();
	return 0;
}
