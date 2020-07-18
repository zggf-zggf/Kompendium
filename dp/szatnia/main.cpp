#include <bits/stdc++.h>

using namespace std;

struct ev{
	int x, a, c;
	bool chk;
	int id = -1;
};

bool comp(ev e1, ev e2){
	if(e1.x==e2.x) return e1.chk<e2.chk;
	else return e1.x<e2.x;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	vector<ev> inp;
	int n; cin>>n;
	for(int i =0;i < n; i++){
		int a, b, w; cin>>w>>a>>b;
		inp.push_back(ev{a, b, w, false, -1});
	}
	int p; cin>>p;
	vector<bool> wyn(p);
	for(int i = 0; i < p; i++){
		int a, b, c; cin>>a>>b>>c;
		inp.push_back(ev{a, a+c, b, true, i});
	}
	sort(inp.begin(), inp.end(), comp);
	vector<int> dp(100010, -1);
	for(int i = 0; i < inp.size(); i++){
		ev cur = inp[i];
		dp[0] = 1e9;
		if(cur.chk){
			if(dp[cur.c]>cur.a) wyn[cur.id] = true;
		}else{
			for(int j = 100004-cur.c; j >= 0; j--){
				dp[j+cur.c] = max(dp[j+cur.c], min(dp[j], cur.a));	
			}
		}
	}
	for(auto it:wyn) cout<<(it?"TAK\n":"NIE\n");
	return 0;
}
