#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int palindromPartion (string s,int i ,int j){
    if(i>=j)return 0;
    string r = s.substr(i,(j-i));
    string t = r;
    reverse(t.begin(),t.end());
    if(r.compare(t) == 0)return 0;
    else{
        int M = INT_MAX;
        for(int k = i+1;k<j;k++){
            int temp = palindromPartion(s,i,k)+palindromPartion(s,k,j)+1;
            if(M>temp)M = temp;
        }
        return M;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s  ="abcde";
    cout<<palindromPartion(s,0,s.size())<<endl;
}