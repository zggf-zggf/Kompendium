#include <bits/stdc++.h>

using namespace std;

struct node{
	int link, len, cnt;
	unordered_map<char, int> next;
	node(){
		link = 0;
		len = 0;
		cnt = 0;
	}
};

vector<node> st;
int sz, last;

void init(){
	last = 0;
	sz = 1;
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
		if(st[q].len==st[p].len+1){
			st[cur].link = q;
		}else{
			int clone = sz++;
			st.push_back(node());
			st[clone].len = st[p].len+1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
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

void bfs(){
	for(int i = 0; i < st.size(); i++) st[i].len = -1;
	queue<int> q;
	q.push(0);
	st[0].len = 0;
	while(q.size()){
		int cc = q.front();
		q.pop();
		for(auto it:st[cc].next){
			if(st[it.second].len==-1){
				st[it.second].len = st[cc].len+1;
				q.push(it.second);
			}
		}
	}
}
	
deque<char> s;
int wyn = 0;
string text;
vector<bool> odw;

void solve(int x){
	int tmp = 0;
	bool pos = true;
	unordered_map<int, bool> mp;
	for(int i = 0; i <= s.size(); i++){
		if(odw[x]){
			if(mp[x]){
				break;
			}
			pos = false;
			break;
		}
		mp[x] = true;
		odw[x] = true;
		tmp+=st[x].cnt;	
		if(i<s.size()){
			if(st[x].len==s.size()){
				x=st[x].link;
			}
			if(x==-1){
				pos = false;
				break;
			}
			char c = s[i];
			if(st[x].next.count(c)==0){
				pos=false;
				break;
			}
			x=st[x].next[c];
		}
	}	
	if(pos) wyn=max(wyn, tmp);
}

void rozw(int x){
	int pt = 0;
	odw.resize(0); odw.resize(st.size());
	s.clear();
	for(int i = 0;i < x; i++){
		s.push_back(text[i]);
		pt = st[pt].next[text[i]];
	}
	for(int i = x; i <= text.size(); i++){
		if(!odw[pt]) solve(pt);	
		if(i<text.size()){
			if(st[pt].len==s.size()){
				pt=st[pt].link;
			}
			s.pop_front();
			s.push_back(text[i]);
			char c = text[i];
			pt=st[pt].next[c];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin>>n>>q;
	init();
	for(int i = 0; i < n; i++){
		char c; cin>>c;
		text.push_back(c);
		add(c);
	}
	vector<vector<int>> sorted(n+1);
	for(int i = 1; i < st.size(); i++){
		sorted[st[i].len].push_back(i);
	}
	for(int i = sorted.size()-1; i>0; i--){
		for(auto it:sorted[i]) if(st[it].link>-1) st[st[it].link].cnt += st[it].cnt;
	}
	bfs();

	for(int i = 0; i < q; i++){
		int a; cin>>a;
		wyn = 0;
		rozw(a);
		cout<<wyn<<endl;
	}
	return 0;
}
