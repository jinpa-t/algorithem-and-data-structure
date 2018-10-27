#include <iostream>
using namespace std;

void sort_array(int passed_Array[], int passed_size){
  int temp, i , j ;
  for (i = 0; i < passed_size; i++){
    for (j = 0; j < passed_size; j++) {
      if(passed_Array[i] < passed_Array[j])
      {
        temp = passed_Array[i];
        passed_Array[i] = passed_Array[j];
        passed_Array[j] = temp;
      }
      
    }
    
  }
  for(i = 0; i < passed_size; i++)
  {
      cout << passed_Array[i] << " ";
  }
  
}
int main() {
  int myArray[24] = {2,32,434,243,243,44,2,324,34,24,343,43,4,3,34,3,45,25,55,25,77,65,55,445};
  int array_size =  sizeof(myArray)/sizeof(myArray[0]);
  sort_array(myArray, array_size); //passing array to function 
  return 0;
}
