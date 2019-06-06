
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> vec(5,200);
    vector<int>::iterator itr;
    
    cout << "Vector size: " << vec.size() << endl; // There are 5 elements
    
    cout << "Is empty? " << vec.empty() << endl; // 0 because false
    
    cout << "First element: " << vec.at(0) << endl; // 200
    
    cout << "Also first element: " << vec.front() << endl;
    
    cout << "Last element: " << vec.back() << endl;
    
    
    vec.clear();
    cout << endl << "'Vector cleared!'" << endl;
    cout << "Vector size: " << vec.size() << endl; // There are 0 element
    cout << "Is empty? " << vec.empty() << endl; // 1 because true
    
    vec.push_back(500);
    cout << endl << "'Pushed 500'" << endl;
    cout << "Vector size: " << vec.size() << endl; // There are 5 elements
    cout << "First element: " << vec.at(0) << endl; // 200
    cout << "Last element: " << vec.back() << endl;
    
    
    vec.push_back(600);
    vec.push_back(700);
    
    
    //Any insertion or removal of an element not at the end of the vector needs elements between the insertion position and the end of the vector to be copied.

    vec.insert(vec.begin()+1,180);
    cout << "Vector size: " << vec.size() << endl; // There are 5 elements
    cout << "First element: " << vec.at(0) << endl; // 200
    cout << "Last element: " << vec.back() << endl;
    
    cout << "2nd element: " << vec.at(1) << endl; // 200
    cout << "My vector contains: ";
    for (itr=vec.begin(); itr!=vec.end() ; ++itr){
        cout << ' ' << *itr ;
    }
    cout << endl;
    return 0;
}
