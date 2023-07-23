#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	
	for(int i = 0; i < n; i++) {
		int val = abs(arr[i]); 
		if(arr[val-1] < 0) 
			return val; 
		else 
			arr[val-1] = -arr[val-1]; 
	}
	return -1; 
}
