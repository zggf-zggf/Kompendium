#include <bits/stdc++.h>

using namespace std;

long long p1 = 503017, p2 = 500887, mod2 = 1e9+7, mod1 = 1e9+696969;

vector<long long> pref[500009], pref2[500009];
vector<int> wys[500009];
void update(int rt, int i, long long v, long long v2){
	if(pref[rt].size()>0) v=(pref[rt].back()+v)%mod1;	
	if(pref[rt].size()>0) v2=(pref2[rt].back()+v2)%mod2;	
	pref[rt].push_back(v);
	pref2[rt].push_back(v2);
	wys[rt].push_back(i);
}

long long qur(long long a, long long v){
	int pt = lower_bound(wys[v].begin(), wys[v].end(), a+1)-wys[v].begin();
	pt--;
	if(pt<0) return 0;
	else return pref[v][pt];
}

long long qur2(long long a, long long v){
	int pt = lower_bound(wys[v].begin(), wys[v].end(), a+1)-wys[v].begin();
	pt--;
	if(pt<0) return 0;
	else return pref2[v][pt];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	long long n; cin>>n;
	vector<long long> pot(5e5+10), pot2(5e5+10);
	vector<int> ciag1, ciag2;
	pot[0] = 1;
	pot2[0] = 1;
	for(long long i = 1; i < pot.size(); i++){
		pot[i] = (pot[i-1]*p1)%mod1;
		pot2[i] = (pot2[i-1]*p2)%mod2;
	}	
	vector<long long> hasze1(n+1), hasze1b(n+1);
	for(long long i = 0; i < n; i++){
		long long a; cin>>a;
		ciag1.push_back(a);
		hasze1[i] = (a*pot[i])%mod1;
		hasze1b[i] = (a*pot2[i])%mod2;
		if(i>0) hasze1[i]=(hasze1[i]+hasze1[i-1])%mod1;	
		if(i>0) hasze1b[i]=(hasze1b[i]+hasze1b[i-1])%mod2;	
		update(a, i, pot[i], pot2[i]);
	}
	long long m; cin>>m;
	vector<long long> hasze2(m+1), hasze2b(m+1);
	for(long long i = 0; i< m; i++){
		long long a; cin>>a;
		ciag2.push_back(a);	
		hasze2[i] = (a*pot[i])%mod1;
		hasze2b[i] = (a*pot2[i])%mod2;
		if(i>0) hasze2[i] = (hasze2[i]+hasze2[i-1])%mod1;
		if(i>0) hasze2b[i] = (hasze2b[i]+hasze2b[i-1])%mod2;
	}
	long long q; cin>>q;
	for(long long i = 0; i < q; i++){
		long long a, b, r; cin>>a>>b>>r;
		a--; b--;
		int kon = r, pocz =0;
		while(pocz<kon){
			int mid = 1+(kon+pocz)/2;
			long long h1 = hasze1[a+mid-1];
			long long h2 = hasze2[b+mid-1];
			if(a>0) h1 = (h1-hasze1[a-1]+mod1)%mod1;
			if(b>0) h2 = (h2-hasze2[b-1]+mod1)%mod1;
			long long h1b = hasze1b[a+mid-1];
			long long h2b = hasze2b[b+mid-1];
			if(a>0) h1b = (h1b-hasze1b[a-1]+mod2)%mod2;
			if(b>0) h2b = (h2b-hasze2b[b-1]+mod2)%mod2;
			mid--;
			if((h1*pot[b])%mod1==(h2*pot[a])%mod1&&(h1b*pot2[b])%mod2==(h2b*pot2[a])%mod2) pocz = mid+1;
			else kon = mid;
		}	
		if(pocz==r){cout<<"TAK\n"; continue;}
		long long coc1 = ciag1[a+pocz], coc2 = ciag2[b+pocz];
		long long h1 = hasze1[a+r-1];
		long long h2 = hasze2[b+r-1];
		if(a>0) h1 = (h1-hasze1[a-1]+mod1)%mod1;
		if(b>0) h2 = (h2-hasze2[b-1]+mod1)%mod1;
		long long h1b = hasze1b[a+r-1];
		long long h2b = hasze2b[b+r-1];
		if(a>0) h1b = (h1b-hasze1b[a-1]+mod2)%mod2;
		if(b>0) h2b = (h2b-hasze2b[b-1]+mod2)%mod2;

		long long tmp = (qur(a+r-1, ciag1[a+pocz]));
		if(a>0) tmp=(mod1+tmp-qur(a-1, ciag1[a+pocz]))%mod1;
		h1=(mod1+h1-(tmp*coc1)%mod1)%mod1;
		h1=(h1+tmp*coc2)%mod1;

		long long tmp2 = (qur2(a+r-1, ciag1[a+pocz]));
		if(a>0) tmp2=(mod2+tmp2-qur2(a-1, ciag1[a+pocz]))%mod2;
		h1b=(mod2+h1b-(tmp2*coc1)%mod2)%mod2;
		h1b=(h1b+tmp2*coc2)%mod2;
		if((h1*pot[b])%mod1==(h2*pot[a])%mod1&&(h1b*pot2[b])%mod2==(h2b*pot2[a])%mod2) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	return 0;
}
