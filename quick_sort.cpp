#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int> & vec){
    
    for(int i=0 ; i< vec.size(); i++){
        cout <<  vec[i] << " ";
    }
    cout << endl;
}

int partition(vector<int> & vec, int left, int right){

    int i , j, pivot ;
    i = left;
    j = right-1;
    pivot = vec[right];
    while (i <= j){
        while ( vec[i] < pivot) {
            
            i++;
        }
        while ( vec[j] > pivot) {
            
            j--;
        }
        if (i < j){
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i], vec[right]);
    return i;
}

void quicksort(vector<int> & vec, int left, int right){
    int index;
    
    if (right>left){
        //insert code here!!!
         index = partition(vec , left, right);
         quicksort(vec, left, index - 1);  // Before pi
         quicksort(vec, index + 1, right);
    }
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> myVec {45, 23, 12, 68, 84, 52, 25, 77, 92, 50};
    cout << "My vector is : "<< endl;
    displayVector(myVec);
    cout << endl;
    quicksort(myVec, 0, (int)myVec.size()-1);
    cout << "After Quicksort. My sorted vector is : "<< endl;
    displayVector(myVec);
    return 0;
}

