#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n,int m, vector<vector<int>>& edg){
        // code here
        vector<vector<pair<int,int>>> ele(n);
        for(auto it:edg){
            pair<int,int> p;
            p.first=it[1];
            p.second=it[2];
            ele[it[0]].push_back(p);
        }
        vector<int> vis(n,0);
        vector<int> ans(n,INT_MAX);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        ans[0]=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto it:ele[a]){
                int s=ans[a]+it.second;
                if(s<ans[it.first]) ans[it.first]=s;
                if(vis[it.first]==0){
                    q.push(it.first);
                    vis[it.first]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
int main(){
    int n=6;
    int m=7;
    vector<vector<int>> edge={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    vector<int> ans=shortestPath(n,m,edge);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}