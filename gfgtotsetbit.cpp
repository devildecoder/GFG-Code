#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long countBits(long long n) {
        // code here
        long long int ans=0;
        while(n>0){
            int p;
            for(int i=1;i<64;i++){
                if(n<((1LL<<i)-1)){
                  p=i;
                  break;
                }
            }
            p=p-1;
            ans+=(p*(1LL<<(p-1)));
            int r=n-(1LL<<p);
            ans+=r+1;
            n=r;
        }
        return ans;
    }
int main(){
    cout<<countBits(5462);
    return 0;
}