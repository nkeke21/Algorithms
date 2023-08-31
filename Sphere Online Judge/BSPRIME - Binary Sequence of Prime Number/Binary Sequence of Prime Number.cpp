#include<bits/stdc++.h>
using namespace std;
 
int num[105000000], pnum[6040000], size[6040000], ones[6040000];
const int n = 105000000;
 
int main(){
 
	int k = 0, n, j, i;
	pnum[0] = 2; size[0] = 2; ones[0] = 1;
	n = 105000000;
	k = 1;
	for(i = 3; i < n; i += 2){	
 
	if(num[i] == 0){
 
		num[i] = i;
		pnum[k] = i;
		size[k] = log2(i) + 1 + size[k-1];
		ones[k] = __builtin_popcount(i) + ones[k-1];
		k ++;
	}
 
	for(j = 0; ; j++){
 
		if ( (j==k) || ((i*pnum[j])>n) || (pnum[j]>num[i]) ) break;
		
			num[i*pnum[j]] = pnum[j];
 
		}
 
	}	
	
	int q; cin >>q;
	while(q--){
		int inp; cin >> inp;
		auto low = lower_bound(size,size+k,inp);
		int ind = low - size;
		if(inp == 1){
			printf("%d\n", 1);
		} else {
			int value = ones[ind];
			int currElem = pnum[ind];
			for(int i = size[ind]; i > inp; i --){
				
				if(currElem & 1){
					value -= 1;
				}
				currElem = currElem>> 1;
			}
			printf("%d\n", value);
		}
	}
	return 0;
} 