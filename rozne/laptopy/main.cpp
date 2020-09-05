#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	long long n, m; cin>>n>>m;
	vector<long long> cost(n, (long long)-1);
	vector<vector<int>> graf(n);
	for(long long i = 0; i < m ;i++){
		long long a, b; cin>>a>>b; a--; b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}

	queue<long long> q;
	q.push(0);
	cost[0] = 0;
	while(q.size()){
		long long cur = q.front();
		q.pop();
		for(auto it:graf[cur]){
			if(cost[it]==-1){
				cost[it] = cost[cur]+1;
				q.push(it);
			}	
		}
	}
	long long t; cin>>t;
	long long wyn = 0;
	for(long long i = 0; i < t; i++){
		long long a; cin>>a;
		wyn+=2ll*cost[a-1];	
	}
	cout<<wyn;
	return 0;
}
