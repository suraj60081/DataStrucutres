#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class maxheap
{
    vector<int> arr;
    public:
    maxheap()
    {
       
    }
    bool isEmpty()
    {
        if(arr.size()==0) return true;
        return false;
    }
    int getMin()
    {
        if(arr.size()<=0) return INT_MAX;
        return arr[0];
    }
    void extract()
    {
        if(isEmpty()) return;
        int root = arr[0];
        arr[0] = arr[arr.size()-1];
        arr.pop_back();
        int index = 0;
        int c1 = index*2+1;
        while(c1<arr.size())
        {
            int mi = index;
            int c2=index*2+2;
            if(arr[c1]>arr[mi]) mi=c1;
            if(arr[c2]>arr[mi]) mi=c2;
            if(mi==index) break;
            int temp=arr[mi];
            arr[mi]=arr[index];
            arr[index]=temp;
            index=mi;
            c1=index*2+1;
        }
    }
    
    void insert(int i)
    {
        arr.push_back(i);
        if(arr.size()==1) return;
        int index = arr.size()-1;
        int parent = (index-1)/2;
        while(parent<arr.size())
        {
            if(arr[parent]<arr[index])
            {
                int temp = arr[index];
                arr[index] = arr[parent];
                arr[parent] = temp;
                index = parent;
                parent = (index-1)/2;
            }
            else break;
        }
    }
    int getSize()
    {
        return arr.size();
    }
    
};

int main() {
	//code
	int t;
	cin>>t;
	while(t!=0)
	{
	    int n;
	    cin>>n;
	    minheap mh;
	    for(int i=0;i<k;i++)
	     {
	        int a;
	        cin>>a;
	        mh.insert(a);
	       }
	    int k;
	    cin>>k;
	    for(int i=1;i<k;i++) mh.extract();
	    cout<<mh.getMin()<<endl;
	    t--;
	}
	return 0;
}
