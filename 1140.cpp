#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int w[105],dp[100005],cnt=0,max_cnt=0;
char s;
bool hasFindKey = false;
vector<int> cnts;
void insert(){
    cnts.push_back(cnt);
    if(max_cnt<cnt)max_cnt=cnt;
    cnt=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }

    cin>>m;
    int state=0;
    for(int i=1;i<=m;i++){
        cin>>s;
        switch(state){
            case 0:
                if(s=='k')state=1;
                else{if(cnt>0)insert();}
                break;
            case 1:
                if(s=='e')state=2;
                else if(s=='k'){state=1;if(cnt>0)insert();}//每次状态不对，立刻尝试插入，并把cnt置0
                else{state=0;if(cnt>0)insert();}
                break;
            case 2:
                if(s=='y'){state=0;cnt++;}
                else if(s=='k'){state=1;if(cnt>0)insert();}//!!keykkey
                else{state=0;if(cnt>0)insert();}
                break;
        }
    }
    
    //如果s最后结尾也是key，那么不会在switch中插入，需要单独处理
    if(cnt>0)insert();

    //max_cnt可能远大于n,j是cnt内一段长度的最大值
    for(int i=1;i<=max_cnt;i++){
        int max_j=min(i,n);
        for(int j=1;j<=max_j;j++)
        dp[i]=max(dp[i],dp[i-j]+w[j]);
    }
    int sum=0;
    for(int cnt: cnts){
        sum+=dp[cnt];
    }
    cout<<sum<<'\n';
    return 0;
}