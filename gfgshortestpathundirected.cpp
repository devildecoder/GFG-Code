#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> ele(N); ;
        for(int i=0;i<M;i++){
            ele[edges[i][0]].push_back(edges[i][1]);
            ele[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> ans(N,INT_MAX);
        queue<int> q;
        q.push(src);
        ans[src]=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto it:ele[a]){
                int s=ans[a]+1;
                if(s<ans[it]){
                    ans[it]=s;
                    q.push(it);
                }
                cout<<a<<" "<<it<<" "<<ans[it]<<endl;
            }
        }
        for(int i=0;i<N;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
int main(){
    int n=7,m=10;
    int scr=4;
    vector<vector<int>> edg={{1,5},{1,6},{2,0},{3,3},{4,0},{4,6},{5,3},{5,4},{6,5},{6,6}};
    vector<int> ans=shortestPath(edg,n,m,scr);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}