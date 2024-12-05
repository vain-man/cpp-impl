#include<bits/stdc++.h>
//In wrong answers we believe//
#define db 				double
#define ll 				long long int
#define ld				long long double
//#define int 			long long int
#define ull 			unsigned long long
#define fi 				first
#define se 				second
#define rep(i,a,n)      for(int i=a;i<n;i++)
#define endl 			'\n'
#define mem(a,b) 		memset(a, b, sizeof a)
#define mkp 			make_pair
#define pb 				push_back
#define max3(a,b,c) 	max(a,max(b,c))
#define min3(a,b,c) 	min(a,min(b,c))
#define w(t)            int t; cin>>t; while(t--)
#define all(a)			a.begin(), a.end()
#define sz(a) int((a).size())
#define tr(container, it) \
for(auto it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector < int > vii;
typedef vector < ll > vll;
typedef vector < vii > vvi;
typedef pair < int,int > pii;
db pi		 =			2*acos(0.0);
db eps       =			0.000001;
ll mod       =			(1e9+7);   //998244353
const ll INF =			1000000000000000LL;
void print(vector <int> &arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}
void printll(vector <ll> &arr){
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}

ll ncr(ll n, ll r)
{
    r=min(r,n-r);
    ll A[r],i,j,B[r];
    iota(A,A+r,n-r+1);  
    iota(B,B+r,1);     

    ll g;
    for(i=0;i<r;i++)
    for(j=0;j<r;j++)
    {
        if(B[i]==1)
            break;
        g=__gcd(B[i], A[j] );
        A[j]/=g;
        B[i]/=g;
    }
    ll ans=1;
    for(i=0;i<r;i++)
        ans=(ans*A[i]%mod);
    return ans;
}
const int SIZE=100001;
bool judgePermutation(int a[], int n){
    static int used[SIZE+1];
    for(int i = 1; i <= n; i++) used[i] = 0;
    for(int i = 0; i < n; i++) used[a[i]] = 1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) return 0;
    }
    return 1;
}
//DSU Implementation
void qinit(int idx[], int sz[], int n){
	rep(i,0,n) idx[i]=i, sz[i]=1;
}
int qroot(int index, int idx[]){
	while(index!=idx[index]){
		idx[index]=idx[idx[index]];
		index=idx[index];
	}
	return index;
}
bool qfind(int p, int q, int idx[]){
	return qroot(p,idx)==qroot(q,idx);
}
void qunion(int p, int q, int idx[], int sz[]){
	int rootp=qroot(p,idx), rootq=qroot(q,idx);
	if(rootp==rootq) return;
	if(sz[rootp]>=sz[rootq]){
		idx[rootq]=idx[rootp];
		sz[rootp]+=sz[rootq];
	}
	else{
		idx[rootp]=idx[rootq];
		sz[rootq]+=sz[rootp];
	}
}

int main(){	
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////////
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
//  cerr.tie(NULL);
//For fast IO
///////////////////////////////////////////////////////////////////// 
//  std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
//  std::cout.precision(10);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	
    return 0;
    }