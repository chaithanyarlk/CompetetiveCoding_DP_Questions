#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int palindromPartion (string s,int i ,int j){
    int n = s.size();
    int t[n][n];
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(i>=j)t[i][j] = 0;
        }
    }
    for(int l = 1;l<n;l++){
        for(int i = 0;i<n-l;i++){
            int j = i+l;
            string a = s.substr(i,j+1-i);
            string b = a;
            reverse(a.begin(),a.end());
            if(a.compare(b) == 0){
                t[i][j] = 0;
            }
            else{
                int M = INT_MAX;
                for(int k = i;k<j;k++){
                    int temp = t[i][k]+t[k+1][j]+1;
                    if(M>temp)M = temp;
                }
                t[i][j] = M;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return t[0][n-1];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s  ="geek";
    cout<<palindromPartion(s,0,s.size())<<endl;
}