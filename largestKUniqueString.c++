#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int longestKUnique(string str,int k){
    int first = 0,last =0,count = 0;
    map<char,int>m;
    int M = INT_MIN;
    int n = str.size();
    while(last<n){
        // adding it to the set
        if(m[str[last]] == 0){
            count++;
        }
        m[str[last]]++;
        if(count>k){
            while(count>k){
                m[str[first]]--;
                if(m[str[first]]==0)count--;
                first++;
            }
        }
        if(count == k&& M<last-first+1)M = last-first+1;
        last++;
    }
    return M == INT_MIN ?-1:M;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str = "aaaa";
    int k = 2;
    cout<<longestKUnique(str,k)<<endl;
}