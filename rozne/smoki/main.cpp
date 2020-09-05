#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin>>n>>m;
	int x1, y1, x2, y2; cin>>y1>>x1>>y2>>x2;	
	x1--; y1--; x2--; y2--;

	vector<vector<pair<int, int>>> telep(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
	vector<vector<bool>> tab(n, vector<bool>(m));;
	vector<vector<int>> cost(n, vector<int>(m, -1));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin>>c;
			tab[i][j] = (c=='S');
		}
	}
	int t; cin>>t;
	for(int i = 0; i < t; i++){
		int a, b, c, d; cin>>b>>a>>d>>c; a--; b--; c--; d--;
		telep[a][b] = make_pair(c, d);
	}	

	queue<pair<int, int>> q;
	q.push(make_pair(x1, y1));
	cost[x1][y1] = 0;

	while(q.size()){
		int i = q.front().first;	
		int j = q.front().second;
		if(i==x2&&j==y2) {cout<<cost[i][j]; return 0;}
		int g = cost[i][j];
		q.pop();
		if(tab[i][j]) continue;
		bool ruch = false;
		if(telep[i][j].first!=-1){
			pair<int, int> tmp = telep[i][j];
			if(!tab[tmp.first][tmp.second]&&cost[tmp.first][tmp.second]==-1){
				cost[tmp.first][tmp.second] = g+1;
				q.push(tmp);	
			}
			continue;
		}
		
		if(i>0) if(cost[i-1][j]==-1&&!tab[i-1][j]) {cost[i-1][j] = cost[i][j]+1; q.push(make_pair(i-1, j));} 
		if(j>0) if(cost[i][j-1]==-1&&!tab[i][j-1]) {cost[i][j-1] = cost[i][j]+1; q.push(make_pair(i, j-1));} 
		if(i<n-1) if(cost[i+1][j]==-1&&!tab[i+1][j]) {cost[i+1][j] = cost[i][j]+1; q.push(make_pair(i+1, j));} 
		if(j<m-1) if(cost[i][j+1]==-1&&!tab[i][j+1]) {cost[i][j+1] = cost[i][j]+1; q.push(make_pair(i, j+1));} 
	}
	cout<<-1;
	return 0;
}
	
