#include <bits/stdc++.h>

using namespace std;

struct node{
	vector<node*> nxt;
	bool terminal = false;
	int skip = -1;
	node(){
		this->nxt.resize(26, nullptr);
		this->terminal = false;
		skip = -1;
	}
};
int n;
node *root;
int longest = 0;
string wyn;

void add(string &t){
	node *rt = root;

	for(auto c:t){
		if(rt->nxt[c-'a']==nullptr)rt->nxt[c-'a']=new node();
		rt = rt->nxt[c-'a'];
	}
	rt->terminal = true;
}

void dfs(node *rt){
	if(rt->terminal){
		wyn.push_back('P');
		n--;
		if(n==0) return;
	}
	for(int i = 0; i < 26; i++){
		if(i!=rt->skip){
			if(rt->nxt[i]!=nullptr){
				wyn.push_back((char)('a'+i));
				dfs(rt->nxt[i]);
			}
		}
	}	
	if(rt->skip>-1){ 
		wyn.push_back((char)('a'+rt->skip));	
		dfs(rt->nxt[rt->skip]);
	}
	if(n)wyn.push_back('-');
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	root = new node();
	cin>>n;
	string lll;
	for(int i = 0; i < n; i++){
		string s; cin>>s;
		if(s.size()>longest){
			longest=s.size();
			lll=s;
		}
		add(s);
	}
	node *rt = root;

	for(auto c:lll){
		rt->skip = c-'a';
		rt = rt->nxt[c-'a'];
	}
	dfs(root);
	cout<<wyn.size()<<'\n';
	for(auto it:wyn) cout<<it<<'\n';
	return 0;
}
