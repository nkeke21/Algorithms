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

struct node{
    int value;
    int parent;
    node* left;
    node* right;
};

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

//build imaginary tree
node* build(int i, int n){
    node* root = NULL; 
    if(i < n){
        root = new node;
        root->value = 0;
        root->left = NULL;
        root->right = NULL;
        
        root->left = build(2 * i + 1, n);
        root->right = build(2 * (i + 1), n);
    }
    return root;
}

//print with inorder
void printTree(node* node, int& n) {
    
    if (node == NULL) return;

    printTree(node->left, n);
    if(n != 0){
        cout <<node->parent<<' ' ;
        n-=1;
    } else {
        cout<<node->parent<<'\n';
        n-=1;
    }

    printTree(node->right, n);
}

//fill tree with nums(sorted), with inorder
void goDeep(node* node, int n, int& count) {
    if (node == NULL ) return;
            goDeep(node->left, n, count);
                node->value = arr[count]-1;
                if(node->left != NULL){
                    node->left->parent = arr[count]-1;
                }      
                if(node->right != NULL){
                    node->right->parent = arr[count]-1;
                }
                count ++;
            goDeep(node->right, n, count);
}

int main(){
    int t; cin >> t;
    for(int i = 1; i <= t; i ++){
        int n; cin >> n;
        int res = 0;
        
        for(int i = 0; i < n; i ++){
            int x; cin >> x;
            arr[i] = x+1;
        }
    
	    fill(tmp, tmp + 1000002, 0);
	
	    for(int j = 0; j < n; j ++){
    	    int count = read(arr[j] - 1);
		    update(arr[j], count + 1);
        		
            res = max(tmp[arr[j]], res);
        }
        
        cout << "Case " << i << ":"<< endl;
        cout << "Minimum Move: "<< n - res<< endl;
        
        node* root = build(0, n);
        root->parent = -1;
        sort(arr, arr+n);
        
    	int count = 0;
        goDeep(root, n, count);
        n-=1;
        printTree(root, n);
    }
    return 0;
}