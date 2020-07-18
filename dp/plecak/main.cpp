#include <bits/stdc++.h>

using namespace std;
vector<int> graf;
vector<vector<int>> trans;
vector<bitset<1000001>> dp;
vector<unordered_set<int>> nowyGraf;
vector<int> stck;
vector<int> odw, cnt;
vector<int> waga, sccWaga, scc;
int n, p, cur = 0;

void stackDfs(int x){
    odw[x] = true;
    if(!odw[graf[x]]) stackDfs(graf[x]);
    stck.push_back(x);
}

void make_trans(){
    for(int i = 1; i <= n; i++){
        trans[graf[i]].push_back(i);
    }
}

void kosDfs(int x){
    odw[x] = true;
    scc[x] = cur;
    sccWaga[cur] += waga[x];
    cnt[cur]++;
    if(graf[x]==x)cnt[cur]=10;
    for(auto it:trans[x]){
        if(!odw[it]) kosDfs(it);
    }
}

void make_graf(){
    nowyGraf.resize(cur);
    for(int i = 1; i <= n; i++){
        if(scc[graf[i]]!=scc[i])nowyGraf[scc[graf[i]]].insert(scc[i]);
    }
}

void solve(int x, int parent){
//    cout<<x<<endl;
	dp[x] = dp[parent];
    for(auto it:nowyGraf[x]){
        solve(it, x);
    }
	dp[parent] = dp[parent]|(dp[x]<<sccWaga[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>p;
    graf.resize(n+1); trans.resize(n+1); odw.resize(n+1); waga.resize(n+1); sccWaga.resize(n+1); scc.resize(n+1); cnt.resize(n+1); 
    for(int i = 1; i <= n; i++){
        cin>>graf[i]>>waga[i];
        if(graf[i]==0)graf[i] = i;
    }
    for(int i = 1; i <= n; i++){
        if(!odw[i]) stackDfs(i);
    }
    make_trans();
    odw.resize(0); odw.resize(n+1);
    for(int i = stck.size()-1; i >= 0; i--){
        if(!odw[stck[i]]){
            kosDfs(stck[i]);
            cur++;
        }
    }
    make_graf();
	dp.resize(cur+1);
	dp[cur][0] = true;

    for(int i = 0; i < cur; i++){
        if(cnt[i]>1) solve(i, cur);
    }
	for(int i = p; i >= 0; i--) if(dp[cur][i]) {cout<<i; return 0;}
}
