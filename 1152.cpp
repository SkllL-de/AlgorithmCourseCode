#include<iostream>
#include<queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>> q;
int main()
{
    long long n,sum=0,t;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>t;
        q.push(t);
    }
    while(q.size()>1){
        long long a=q.top();q.pop();
        long long b=q.top();q.pop();
        int x=a+b;
        sum+=x;
        q.push(x);
    }
    cout<<sum<<'\n';
    return 0;
}

//先创建数组arr[1e5+5]的错误点：
/*在小根堆插入后，arr的元素的顺序没变，但小根堆的元素的顺序变了
也就是说，数组元素的未用到的最前一位，不一定是下一次要入堆的元素
*/
//正确做法：直接对小根堆进行操作