#include <iostream>
#include <queue>
using namespace std;

int main()
{
  queue<int> myqueue;
  	
 	int vals[] = {5,6,7,10,3,2,0,9, 15, 23}; // vlaues
 	int size = sizeof(vals) / sizeof(vals[0]);
  for(int i = 0; i < size ;i++ ) {
     myqueue.push(vals[i]);
  }
  	
	cout << "Size of myQueue is : " << myqueue.size();
	cout << endl;
	cout << "Front Element: " << myqueue.front();
	cout << endl;
	cout << "Back Element: " << myqueue.back();

	cout << endl;
	while (!myqueue.empty())
  	{
	    cout<< myqueue.front() << " ";
	    myqueue.pop();
  	}
	return 0;
}
