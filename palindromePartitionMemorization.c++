#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

int t[1000][1000];
int palindromPartion (string s,int i ,int j){
    if(i>=j)return 0;
    string r = s.substr(i,(j-i));
    string p = r;
    reverse(p.begin(),p.end());
    if(r.compare(p) == 0)return 0;
    if(t[i][j]!=-1)return t[i][j];
    else{
        int M = INT_MAX;
        for(int k = i+1;k<j;k++){
            int temp = palindromPartion(s,i,k)+palindromPartion(s,k,j)+1;
            if(M>temp)M = temp;
        }
        t[i][j] = M;
        return M;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill(&t[0][0],&t[0][0]+(1000*1000),-1);
    string s  ="abcde";
    cout<<palindromPartion(s,0,s.size())<<endl;
}