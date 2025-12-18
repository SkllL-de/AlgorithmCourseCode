#include<iostream>
using namespace std;
int stk[100005],res[100005],arr[100005];
int main()
{
    int n,top=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        while(top && arr[stk[top]]<arr[i]){
            res[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<res[i]<<'\n';
    }
    return 0;
}