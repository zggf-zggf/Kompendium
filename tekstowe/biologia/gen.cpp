#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
	srand(atoi(argv[1]));
	int n = atoi(argv[2]);
	cout<<n<<" "<<1<<endl;
	for(int i = 0; i < n; i++){
		cout<<(char)('a'+rand()%26);	
	}
	cout<<endl<<rand()%n+1<<endl;
	return 0;
}
