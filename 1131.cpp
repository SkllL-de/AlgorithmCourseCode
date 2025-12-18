#include <iostream>
using namespace std;
int n,m,root[100005];
int find(int x){
    if(root[x]==x)return x;
    return root[x]=find(root[x]);
    //return find(root[x]);
}
void unite(int a, int b){
    int rootx=find(a);
    int rooty=find(b);
    if(rootx!=rooty)
    root[rootx]=rooty;
}
void query(int a, int b){
    // int rootx=find(a);
    // int rooty=find(b);
    //cout<<rootx<<' '<<rooty<<' ';
    cout<<a<<' '<<b<<' ';
    if(find(a)==find(b)){
        cout<<'Y'<<'\n';
    }else{
        cout<<'N'<<'\n';
    }
}
int main()
{
    cin>>n>>m;
    int op,a,b;
    for(int i=1;i<=n;i++){
        root[i]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>op>>a>>b;
        if(op==1){unite(a,b);}
        else if(op==2){query(a,b);}
    }
    return 0;
}