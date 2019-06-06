#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int> & vec){
    
    for(int i=0 ; i< vec.size(); i++){
        cout <<  vec[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> & vec, vector<int> & temp, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;

    
    while (i <= mid && j <= right) {
        if (vec[i] < vec[j]){
            temp[k] = vec[i];
            i++;
            k++;
        } else {
            temp[k] = vec[j];
            j++;
            k++;
            
        }
        
    }
    
    while (i<=mid){
        temp[k] = vec[i];
        i++;
        k++;
    }
    while (j<=right){
        temp[k] = vec[j];
        j++;
        k++;
    }


    //copy from temp back to the original vector
    for (; left <= right; left++){
        vec[left] = temp[left];
    }
    
    
    
}

void mergesort(vector<int> & vec, vector<int> & temp, int left, int right){
    int mid;
    mid = left + (right-left)/2;
    
    if (right>left){
        

        mergesort(vec, temp, left, mid);
        mergesort(vec,temp, mid+1, right);
        merge(vec, temp, left,mid, right);
    }
    
}

void mergesort(vector<int> & vec){
    
    vector<int> temp(vec.size());
    mergesort(vec, temp, 0, vec.size()-1); // pass to second function
    
}

int main(int argc, const char * argv[]) {

    vector<int> myVec {3,2, 5, 9, 4, 7, 8, 10, 17, 11, 1, 13, 34, 100, 32, 27, 29, 55, 68, 43, 31};
    cout << "My vector is : "<< endl;
    displayVector(myVec);
    mergesort(myVec);
    cout << "After Mergesort. My sorted vector is : "<< endl;
    displayVector(myVec);
    return 0;
}

