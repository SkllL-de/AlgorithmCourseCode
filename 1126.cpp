#include <iostream>
using namespace std;
const long long p1=0.03*36000;
const long long p2=p1+0.10*(144000-36000);
const long long p3=p2+0.20*(300000-144000);
const long long p4=p3+0.25*(420000-300000);
const long long p5=p4+0.30*(660000-420000);
const long long p6=p5+0.35*(960000-660000);
const long long lit=60000;
void cnt(long long t, long long &sum, long long basis, double rate,  long long nextp, long long nextbasis, double nextRate, long long p) {
    long long ans=0;
    bool in = false;
    while(ans<=t){
        in = true;
        if(sum<nextbasis){
            sum++;
            ans=(sum-basis)*rate+p;
        }else{
            sum++;
            ans=(sum-nextbasis)*nextRate+nextp;
        }
    }
    if(in){sum--;}
}
int main()
{
    long long t,sum=0;
    cin>>t;
    if(t<=p1){
        sum=t*100/3;
        if(t!=p1)sum+=33;
        else sum+=9;
    }
    else if(t<=p2){
        sum=36000+(t-p1)*10;
        if(t!=p2)sum+=9;
        else sum+=4;
    }
    else if(t<=p3){
        sum=144000+(t-p2)*5;
        if(t!=p3)sum+=4;
        else sum+=3;
    }
    else if(t<=p4){
        sum=300000+(t-p3)*4;
        if(t!=p4)sum+=3;
        else sum+=3;
    }
    else if(t<=p5){
        sum=420000+(t-p4)*10/3;
        /*if(t!=p5)sum+=3;
        else sum+=2;*/
        cnt(t,sum,420000,0.3,p4,660000,0.35,p5);
    }
    else if(t<=p6){
        sum=660000+(t-p5)*20/7;
        //sum+=2;
        cnt(t,sum,660000,0.35,p5,960000,0.45,p6);
        //cnt(t,sum,660000,p5,0.35,p4,0.45);
    }
    else {
        sum=960000+(t-p6)*20/9;
        cnt(t,sum,960000,0.45,p6,960000,0.45,p6);
    }
    sum+=lit;
    cout<<sum<<'\n';
    return 0;
}