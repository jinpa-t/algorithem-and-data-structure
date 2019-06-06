#include <iostream>
#include <vector>
using namespace std;

template <typename Object>
class MinHeap{
    private:
        vector<Object> heap; // heap array
        int currentSize;    // the number of element in the heap
    
    public:
    MinHeap (int capacity = 100) {
        currentSize =0;
        heap.resize(capacity);
    }
    
    void insert(Object x){
        if (currentSize ==  heap.size()-1)
            heap.resize(heap.size()*2);
        
        currentSize++;
        int i = currentSize;
        
        //percolate up
        for (; x < heap[i/2] ; i = i/2) //for ( init; condition; increment )
            heap[i] = heap[i/2];
        
        heap[i] = x;
    }
    
    int findMin(){
        return heap[1];
    }
    
    void deleteMin(){
        if (isEmpty()) throw  "Heap is Empty!!";
        heap[1] = heap[currentSize];
        currentSize--;
        percolateDown(1);
    }
    
    void percolateDown(int i){
        
        int leftchild = 2*i;
        int rightchild = 2*i+1;
        
        //if leaf node, stop
        if (leftchild > currentSize) return; //i is a leaf node
        
        int min = i;
        
        if(heap[leftchild] < heap[i])
            min = leftchild;
        
        if(heap[rightchild] < heap[min] && rightchild <= currentSize)
            min = rightchild;
            
        if(min!=i){
            swap(heap[min], heap[i]);
            percolateDown(min);
        }
        
    }
    
    bool isEmpty(){
        return currentSize==0;
    }
    
    void display() {

        for (int i=1; i<= currentSize; i++){
            cout << heap[i] << "   ";
        }
    }
    
};

int main(int argc, const char * argv[]) {
    try {
    
        MinHeap<int> myHeap;
        myHeap.insert(5);
        myHeap.insert(6);
        myHeap.insert(3);
        myHeap.insert(10);
        myHeap.insert(4);
        myHeap.deleteMin();
        myHeap.deleteMin();
        myHeap.insert(7);
        myHeap.deleteMin();
        myHeap.deleteMin();
        myHeap.deleteMin();
        myHeap.deleteMin();

        myHeap.display();
    }
    catch (const char* msg)
    {
        cout << "Error : " <<msg << endl;
    }
    
    return 0;
}
