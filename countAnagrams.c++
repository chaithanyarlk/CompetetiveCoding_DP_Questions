#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
int anagramsCount(string s,string a){
    int n = s.size(),m = a.size(),i =0 ,j;
    int distinct =0 ,count = 0;
    map<char,int>m1,m2;
    for(i = 0;i<m;i++){
        if(m1[a[i]] == 0){
            distinct++;
        }
        m1[a[i]]++;
    }
    m2 = m1;
    for(i = 0;i<m;i++){
        if(m1[s[i]]>0){
            m2[s[i]]--;
            if(!m2[s[i]])distinct --;
        }
        if(!distinct)count++;
    }
    j = 0;
    while(i<n){
        // lower bound
        if(m1[s[j]]>0){
            m2[s[j]] ++;
            if(m2[s[j]] == 1)distinct ++;
        }
        // upper bound
        if(m1[s[i]]>0){
            m2[s[i]]--;
            if(m2[s[i]]==0)distinct--;
        }
        if(!distinct)count++;
        i++;j++;
    }
    return count;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s  ="forxxorfxdofr";
    string a = "for";
    cout<<anagramsCount(s,a)<<endl;
}