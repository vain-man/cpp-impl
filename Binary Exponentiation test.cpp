#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define ull unsigned long long
#define vii vector <int>
#define vll vector <long long>
#define pii pair <int, int>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define endl '\n'
#define mem(a,b) memset(a, b, sizeof a)
using namespace std;
void print(vector <int> &arr){
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	
	cout<<endl;
}
ull binpow(ull a, ull b){
	if(b==0) return 1;
	ll res=binpow(a, b/2);
	if(b%2) return res*res*a;
	else return res*res;
}
ull binpowI(ull a , ull b){
	ull res=1;
	while(b>0){
		if(b&1){
			res*=a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}
int main(){
	while(true){
	ull a, b;
	cin>>a>>b;	
	
	cout<<(ull)binpowI(a,b)<<endl;
}
	return 0;			
}