//using stack o(n) solution


#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 

void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}


vector<int> nearest_greater_to_right(int a[], int n){
    vector<int> v;
    stack<int> s;

    for(int i = n-1; i >=0; i--){
        if(s.size()==0){
            v.push_back(-1);

        }

        else if(s.size() > 0 && a[i]<s.top()){
            v.push_back(s.top());
        }

        else if(s.size() > 0 && a[i]>=s.top()){
            while(s.size() > 0 && a[i]>=s.top())
             s.pop();

            if(s.size()==0){
                v.push_back(-1);

            }

            else {
                v.push_back(s.top());
            }
        }

        s.push(a[i]);
    }

    reverse(v.begin(), v.end());

    return v;
}

int main() 
{ 
    int price[] = { 2, 30, 15, 6 }; 
    
    int n = sizeof(price) / sizeof(price[0]); 
    printArray(price, n);
    cout << "Nearest_greater_element_right = " ;
    vector<int> v;
    v = nearest_greater_to_right(price, n); 
     
    

    for(int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
        
        		
	}

    return 0;
}