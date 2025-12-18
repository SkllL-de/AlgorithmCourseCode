int income_tax(int p, int d, int f) {
    int res=p-60000-d;
    int sum=0;
    if(res<=0)return 0;
    if(res>0) sum+=0.03*(res<36000?res:36000);
    if(res>36000) sum+= 0.10*((res<=144000?res:144000)-36000);
    if(res>144000)sum+= 0.20*((res<=300000?res:300000)-144000);
    if(res>300000)sum+= 0.25*((res<=420000?res:420000)-300000);
    if(res>420000)sum+= 0.30*((res<=660000?res:660000)-420000);
    if(res>660000)sum+= 0.35*((res<=960000?res:960000)-660000);
    if(res>960000)sum+= 0.45*(res-960000);
    return sum-f;
}