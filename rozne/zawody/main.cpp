#include <bits/stdc++.h>

using namespace std;
vector<unordered_set<int>> graf;
vector<int> match;
int n;

void del(int i){
	if(match[i]==-1&&graf[i].size()==1){
		int cur = *graf[i].begin();
		match[i] = cur;
		graf[i].clear();
		graf[cur].erase(i);
		match[cur] = i;
		for(auto it:graf[cur]){
			graf[it].erase(cur);
		}
		for(auto it:graf[cur]){
			del(it);
		}
		graf[cur].clear();	
	}
}

void dfs(int x){
	match[x] = 0;
	for(auto it:graf[x]){
		if(match[it]==-1){
			dfs(it);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin>>n;
	graf.resize(n*2);
	match.resize(n*2, -1);
	for(int i = 0; i < n; i++){
		char c; cin>>c;
		if(c=='N'){
			int a, b; cin>>a>>b; a--; b--;
			graf[i].insert(a+n);
			graf[i].insert(b+n);	
			graf[a+n].insert(i);
			graf[b+n].insert(i);
		}else{
			int a; cin>>a; a--;
			graf[i].insert(a+n);
			graf[a+n].insert(i);
		}
	}
	
	for(int i = 0; i < 2*n; i++){
		del(i);
	}
	bool pos = true, jedn = true;
	for(int i = 0; i < 2*n; i++){
		if(match[i]==-1) jedn = false;
		if(match[i]==-1&&graf[i].size()==0) pos = false;
	}

	if(!pos){ cout<<"NIE\n0"; return 0;}
	if(jedn){
		cout<<"TAK\n";
		for(int i = 0; i < n; i++){
			cout<<match[i]-n+1<<endl;
		}
		return 0;
	}
	
	long long wyn = 1;
	long long mod =  1e9+7;
	for(int i = 0; i < 2*n; i++){
		if(match[i]==-1){
			wyn*=2;
			wyn%=mod;	
			dfs(i);
		}
	}
	cout<<"NIE\n"<<wyn;
	return 0;
}
