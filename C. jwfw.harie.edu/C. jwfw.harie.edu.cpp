#include <bits/stdc++.h>

using namespace std;


void make_permutations(vector<string>* permutations,int len,string str){
    if(str.length() == len){
        permutations->push_back(str);
        return;
    }
    make_permutations(permutations,len,str+'A');
    make_permutations(permutations,len,str+'B');
    make_permutations(permutations,len,str+'C');
    make_permutations(permutations,len,str+'D');
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
     vector<string> permutations;
    make_permutations(&permutations,5,"");
    for(int i = 0;i<t;i++){

        int n;
        cin>>n;
        string test[n];
        int score[n];
        int answer = 0;
        for(int j = 0; j<n;j++){
            cin>>test[j]>>score[j];
        }
        map<vector<int>,int> perm_score;
        vector<vector<int> > perm_wanted(1024);
        vector<int> scores(n);
        vector<int> wanted_scores(n);
        for(int k = 0; k<permutations.size();k++){
        fill(scores.begin(),scores.end(),0);
        fill(wanted_scores.begin(),wanted_scores.end(),0);
        string perm = permutations[k];
       for(int j = 0; j<n;j++){

        int counter = 0;
        int counter2 = 0;
            string str = test[j];
            for(int m = 0; m<perm.size();m++){
                counter+=10*(str[m]==perm[m]);
            }
            for(int m = 0; m<perm.size();m++){
                counter2+=10*(str[5+m]==perm[m]);
            }
            scores[j] = counter;
            wanted_scores[j] = score[j]-counter2;
        }
        perm_score[scores]++;
        perm_wanted[k]=wanted_scores;
    }
         for(int k = 0; k<perm_wanted.size();k++){
            answer+= perm_score[perm_wanted[k]];
         }
        cout<<answer<<"\n";
    }
    return 0;
}
