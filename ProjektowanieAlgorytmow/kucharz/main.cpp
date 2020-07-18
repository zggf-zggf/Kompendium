#include <bits/stdc++.h>
#include "ckuclib.h"

using namespace std;
long long inf = 1e9;

struct node{
	node *pt;
	int val;
	vector<vector<int>> dp;
	void nxt(){
		vector<int> tmp;
		tmp.resize(22, inf);
		if(this->val==0) this->pt = new node();
		this->val++;
		int hlf = (this->val+1)/2;
		if(this->val>1)if(this->pt->val<hlf) this->pt->nxt();
		for(int i = 0; i < 22; i++){
			tmp[i] = min(tmp[i], this->dp[1][min(i+1, 21)]+jedno(this->val));
			if(this->val>1) tmp[i] = min(tmp[i], this->dp[0][i]+dwa(this->val));
			if(this->val>1&&i>0) tmp[i] = min(tmp[i], this->pt->dp[1][i-1]+polowa(this->val));
		}
		this->dp[0].swap(this->dp[1]);
		this->dp[1].swap(tmp);
	}
	node(){
		this->pt=nullptr;
		this->val = 0;	
		this->dp.resize(2, vector<int>(22));
		for(int i = 0; i < 22; i++) this->dp[1][i] = 0;
	}
};
			
			
int main(){

	int n; n = dajn();
	int e = daje();
	node *root = new node();
	while(root->val<n) root->nxt();
	if(e>21) odpowiedz(root->dp[1][21]);
	else odpowiedz(root->dp[1][e]);	
	
	return 0;
}
