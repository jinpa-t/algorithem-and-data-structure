#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>&myvector, int l, int r, int x) // l = left, r = right
{ 
    if (r >= l) 
    { 
		int mid = l + (r - l)/2; 
		if (myvector[mid] == x) 
			return mid; 
		if (myvector[mid] > x) 
			return binarySearch(myvector, l, mid-1, x); 
		return binarySearch(myvector, mid+1, r, x); 
    } 
    return -1; 
} 

int main ()
{
    vector<int> myvector ={2,5,7,11,20,30,40,55,60};
	int end = myvector.size();
	
	int find =40;
    cout << "Found at index: " << binarySearch(myvector,0,end-1,find);

    return 0;
}
