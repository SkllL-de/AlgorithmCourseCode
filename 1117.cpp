#include <iostream>
#include <deque>
using namespace std;
const int N = 1e6+5;
int arr[N],res[N],k,n;
deque<int> q;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        while(!q.empty()&&arr[i]>arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        while(q.front()<i-k+1){
            q.pop_front();
        }
        if(i>=k)res[i-k+1]=arr[q.front()];
    }
    for(int i=1;i<=n-k+1;i++){
        cout<<res[i]<<'\n';
    }
    return 0;
}