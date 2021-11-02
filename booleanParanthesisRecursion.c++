#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int booleanParanthesis(string s,int i,int j,int istrue){
    if(i>j)return 0;
    if(i == j){
        if(istrue == true){
            if(s[i]=='T')return true;
            else return false;
        }
        else{
            if(s[i]=='T')return false;
            return true;
        }
        
    }
    int ans = 0;
    for(int k = i+1;k<j;k=k+2){
        int lt,lf,rt,rf;
        lt = booleanParanthesis(s,i,k-1,true);
        lf = booleanParanthesis(s,i,k-1,false);
        rt = booleanParanthesis(s,k+1,j,true);
        rf = booleanParanthesis(s,k+1,j,false);
        if(s[k]=='&'){
            if(istrue == true){
                ans+=lt*rt;
            }
            else{
                ans+=lt*rf+rf*lf+lf*rt;
            }
        }
        else if(s[k] == '|'){
            if(istrue == true){
                ans+=lt*rt+lt*rf+rt*lf;
            }
            else{
                ans+=lf*rf;
            }
        }
        else{
            if(istrue ==true){
                ans+= lf*rt+rf*lt;
            }
            else{
                ans+= lt*rt+lf*rf;
            }
        }
    }
    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "T^F|F";
    cout<<booleanParanthesis(s,0,s.size()-1,true);
}






