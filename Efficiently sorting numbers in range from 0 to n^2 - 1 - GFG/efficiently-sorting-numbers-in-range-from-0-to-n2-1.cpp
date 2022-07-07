// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    void sort(int arr[], int n){
        // your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0;i<n;i++){
            pq.push(arr[i]);
        }
        for(int i = 0;i<n;i++){
            arr[i] = pq.top();
            pq.pop();
    }
    }
};

// { Driver Code Starts.
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


// Driver program to test above functions
int main()
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		Solution ob;
		ob.sort (arr, n);
		print (arr, n);
		cout << endl;
	}
}



  // } Driver Code Ends