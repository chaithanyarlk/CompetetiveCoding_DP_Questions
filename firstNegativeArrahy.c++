#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
void firstNegative(vector<int>arr,int n,int k){
    queue<int>q;
    int i,j;
    for(i = 0;i<k;i++){
        if(arr[i]<0)
        q.push(arr[i]);
    } i--;
    for(j=0;i<n;j++){
        if(arr[i]<0)
        q.push(arr[i]);
        if(q.empty()){
            cout<<"0"<<endl;
        }
        else {
            if((q.front()) == arr[j]){
                cout<<arr[j]<<endl;
                q.pop();
            }
            else{
                cout<<q.front()<<endl;
            }
        }
        i++;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr {-8, 2, 3, -6, 10};
    firstNegative(arr,arr.size(),2);
}