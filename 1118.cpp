#include<iostream>
using namespace std;
string a,b;
int res[10005*2];
int main()
{
    cin>>a>>b;
    if(a[0]=='0'||b[0]=='0'){
        cout<<0<<'\n';
        return 0;
    }
    int len1=a.length();
    int len2=b.length();
    for(int i=len1-1;i>=0;i--){
        int n1=a[i]-'0';
        for(int j=len2-1;j>=0;j--){
            int n2=b[j]-'0';
            res[i+j+1]+=n1*n2;
            res[i+j]+=res[i+j+1]/10;
            res[i+j+1]%=10;
        }
    }
    int start=0;
    while(res[start]==0&&start<len1+len2)start++;
    for(int i=start;i<len1+len2;i++)cout<<res[i];
    cout<<'\n';
    return 0;
}