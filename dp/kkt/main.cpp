#include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long d, k;
	cin>>d>>k;
	queue<long long> q;
	for(int i = 0; i < k-1;  i++) q.push(1);
	unsigned long long sum = k-1;
	long long wyn = k-1;
	while(sum<=d){
		wyn++;
		q.push(sum);
		sum+=sum;
		sum-=q.front();
		q.pop();
	}
	cout<<wyn;	
	return 0;
}
