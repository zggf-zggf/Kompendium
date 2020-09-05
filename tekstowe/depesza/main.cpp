#include <bits/stdc++.h>

using namespace std;

struct node{
	int len, link;
	vector<int> next;
	node(){
		this->next.resize(26, 0);
	}
};
vector<node> st;
vector<long long> dp;
int last, sz;

void init(){
	st.push_back(node());
	last = 0;
	sz = 1;
	st[0].len = 0;	
	st[0].link = -1;
}

void add(char c){
	int cur = sz++;
	st.push_back(node());
	st[cur].len = st[last].len+1;
	int p = last;
	while(st[p].next[c-'a']==0){
		st[p].next[c-'a'] = cur;
		p = st[p].link;
		if(p==-1) break;
	}
	if(p==-1) st[cur].link = 0;
	else{
		int q = st[p].next[c-'a'];	
		if(st[p].len+1==st[q].len){
			st[cur].link = q;
		}else{
			int clone = sz++;
			st.push_back(node());
			st[clone].link = st[q].link;
			st[clone].len = st[p].len+1;
			st[clone].next = st[q].next;
			st[q].link = clone;
			st[cur].link = clone;
			while(st[p].next[c-'a']==q){
				st[p].next[c-'a'] = clone;
				p = st[p].link;
				if(p==-1) break;
			}
		}
	}
	last = cur;
}

void dfs(int x){
	dp[x] = 1;
	for(auto it:st[x].next){
		if(it!=0){
			if(dp[it]==0) dfs(it);
			dp[x]+=dp[it];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin>>n;
	init();
	for(int i = 0; i < n; i++){
		char c; cin>>c;
		add(c);
	}
	dp.resize(sz+2);
	dfs(0);
	cout<<dp[0]-1;
	return 0;
}
