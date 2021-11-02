#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int t[1000][1000];
ll mcm (vector<ll>&matrix,int i, int j){
    if(i>=j){
        t[i][j] = 0;
        return t[i][j];
    }
    else if(t[i][j]!=-1) return t[i][j];
    else{
        int M = INT_MAX;
        for(int k = i;k<j;k++){
            ll temp = mcm(matrix,i,k)+mcm(matrix,k+1,j)+matrix[i-1]*matrix[k]*matrix[j];
            if(M>temp){
                M = temp;
            }
        }
        t[i][j] = M;
        return t[i][j];
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    vector<ll>matrix = {40, 20, 30, 10, 30};
    cout<<mcm(matrix,1,matrix.size()-1)<<endl;
}