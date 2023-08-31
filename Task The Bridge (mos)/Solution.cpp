/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int arr[1000005];
int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        int x; cin >> x;
        arr[i] = x;
    }
    int r = n-1;
    int result = 0;
    while(r >= 3){
        result += min(2*arr[1] + arr[0] + arr[r], 2*arr[0] + arr[r-1] + arr[r]);
        r-=2;
    }
    if(r == 1){
        result += arr[1];
    } else if(r == 2){
        result += arr[0] + arr[1] + arr[2];
    } else {
        result += arr[0];
    }
    printf("%d", result);
    return 0;
}
