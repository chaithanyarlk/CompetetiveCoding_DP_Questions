#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
ll mcm (vector<ll>&matrix,int i, int j){
    if(i>=j)return 0;
    else{
        int M = INT_MAX;
        for(int k = i;k<j;k++){
            ll temp = mcm(matrix,i,k)+mcm(matrix,k+1,j)+matrix[i-1]*matrix[k]*matrix[j];
            if(M>temp){
                M = temp;
            }
        }
        return M;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<ll>matrix = {40, 20, 30, 10, 30};
    cout<<mcm(matrix,1,matrix.size()-1)<<endl;
}