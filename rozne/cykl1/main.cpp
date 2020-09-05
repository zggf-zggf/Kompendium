#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> graf;
vector<int> color;
vector<int> stck;
bool done = false;

void dfs(int x){
	stck.push_back(x);
	for(auto it:graf[x]){
		if(color[it]==color[x]){
			cout<<"TAK ";
			while(stck.back()!=it){
				cout<<1+stck.back()<<" ";
				stck.pop_back();
			}
			cout<<it+1;
			done = true;
			return;
		}else if(color[it]==0){
			color[it] = color[x]==1?2:1;
			dfs(it);
			if(done) return;
		}
	}
	stck.pop_back();
}		
				
int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	for(int al = 0; al < t; ++al){
		graf.resize(0);
		cin>>n>>m;
		graf.resize(n);
		for(int i = 0; i < m; ++i){
			int a, b; cin>>a>>b; a--; b--;
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		color.resize(0); color.resize(n);
		done=false;
		stck.resize(0);
		for(int i = 0; i < n;++i){
			if(color[i]==0) {color[i]=1;dfs(i);}
			if(done)break;
		}
		if(!done) cout<<"NIE";
		cout<<"\n";
	}
	return 0;
}	
