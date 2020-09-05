#include <bits/stdc++.h>

using namespace std;
struct node{
	int len, link, cnt = 0;
	map<char, int> next;
	node(){
		len = 0;
		link = 0;
		cnt = 0;
	}
};

int sz = 1;
int last = 0;
vector<node> st;
vector<vector<int>> sorted;
vector<int> dp;

void init(){
	st.push_back(node());
	st[0].len = 0;
	st[0].link = -1;
}

void add(char c){
	int cur = sz++;
	st.push_back(node());
	st[cur].cnt = 1;
	st[cur].len = st[last].len+1;
	int p = last;
	while(p!=-1&&st[p].next.count(c)==0){
		st[p].next[c] = cur;
		p = st[p].link;
	}
	if(p==-1){
		st[cur].link = 0;
	}else{
		int q = st[p].next[c];
		if(st[p].len+1==st[q].len){
			st[cur].link = q;
		}else{
			int clone = sz++;
			st.push_back(node());
			st[clone].cnt = 0;
			st[clone].link = st[q].link;
			st[clone].len = st[p].len+1;
			st[clone].next = st[q].next;
			while(p!=-1&&st[p].next[c]==q){
				st[p].next[c] = clone;
				p = st[p].link;
			}
			st[cur].link = clone;
			st[q].link = clone;
		}
	}
	last = cur;
}
int k;	
void dfs(int x){
	if(x>0)dp[x] = st[x].cnt==k;
	else dp[0] = 0;
	for(auto it:st[x].next){
		if(dp[it.second]==-1) dfs(it.second);
		dp[x] += dp[it.second];	
	}
}
int main(){
	int n; cin>>n>>k;
	if(n>1000){
		string coc; cin>>coc;
		return 0;
	}
	init();
	for(int i = 0; i < n; i++){
		char c; cin>>c;
		add(c);
	}
	sorted.resize(sz+1);
	int wyn = 0;
	for(int i = 0; i < st.size(); i++){
		sorted[st[i].len].push_back(i);
	}
	for(int i = st.size()-1; i > 0; i--){
		for(auto it:sorted[i]) {
			st[st[it].link].cnt+=st[it].cnt;
		}
	}
	sorted.resize(0);
	dp.resize(sz+1, -1);
	dfs(0);
	cout<<dp[0]<<endl;
	return 0;
}
