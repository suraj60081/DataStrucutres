/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
void bubbleSort(int arr[], int n) 
{ 
    if (n == 1) 
        return; 
  
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
  
    bubbleSort(arr, n-1); 
} 

int main()
{    
    int a[]={11,-8,5,6};
    int n =4;
    bubbleSort(a,n);
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    

    return 0;
}
