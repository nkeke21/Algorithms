/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int arr[1000002];
int tmp[1000002];
const int MaxVal = 1000001;

void update(int idx ,int val){

    while (idx <= MaxVal){
        tmp[idx] = max(tmp[idx], val);
        idx += (idx & -idx);
    }
}

int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum = max(tmp[idx], sum);
        idx = idx - (idx & -idx);
    }
    return sum;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int minR = INT_MAX;
        
        for(int i = 0; i < n; i ++){
            int x; cin >> x;
            arr[i] = x+1;
        }
    	int k; cin >> k;
    	if(k > n){
    		printf("%d\n", -1);
    		continue;
    	}
    	fill(tmp, tmp + 1000002, 0);
        	for(int i = 0; i < n; i ++){
        		int count = read(arr[i] - 1);
        		update(arr[i], count + 1);
        		
        		if(tmp[arr[i]] >= k){
        			minR = min(minR, arr[i]-1);
        		}
        	}
        	if(minR == INT_MAX){
        		minR = -1;
        	}
        	
        	printf("%d\n", minR);
    }
    return 0;
}