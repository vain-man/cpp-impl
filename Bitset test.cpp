#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bitset<1000000001> visited;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			visited[temp]=true;
			
		}
		cout<<visited.count()<<endl;
		
	}
}
