#include<bits/stdc++.h>
//One implementation to rule them all?
#define db              double
#define ll              long long int
#define ld              long double
//#define int           long long int
#define ull             unsigned long long
#define fi              first
#define se              second
#define rep(i,a,n)      for(int i=a;i<n;i++)
#define repr(i,n,b)     for(int i=n;i>=b;i--)
#define endl            '\n'
#define mem(a,b)        memset(a, b, sizeof a)
#define mkp             make_pair
#define pb              push_back
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define w(t)            int t; cin>>t; while(t--)
#define all(a)          a.begin(), a.end()
#define sz(a)           int((a).size())
#define dbg(x)          cerr << #x << " = " << x << endl;
#define printdb(i)      printf("%.10lf\n",i)
#define isOn(S, j)      (S & (1<<j))
#define setBit(S, j)    (S |= (1<<j))
#define clearBit(S, j)  (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S)       (S & (-S))
#define setAll(S, n)    (S = (1<<n)-1)
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
//Can use tuples in C++17
using namespace std;
typedef map < int, int > mii;
typedef vector < int > vii;
typedef vector < ll > vll;
typedef vector < vii > vvi;
typedef pair < int,int > pii;
template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
const db PI = 2*acos(0.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
db eps       =          0.000001;
ll mod       =          (1e9+7);    //998244353   
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
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

const int SIZE=100005;
bool judge(int a[], int n){
    static int used[SIZE+1];
    for(int i = 1; i <= n; i++) used[i] = 0;
    for(int i = 0; i < n; i++) used[a[i]] = 1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) return 0;
    }
    return 1;
}
int n,d;
vvi adj(1005);
bool vis[1005]={false};
int dfs(int u){
	vis[u]=true;
	int size=1;
	for(auto i:adj[u]){
		if(vis[i]==false){
			size+=dfs(i);
		}
	}
	return size;
}

int qroot(ll index, ll idx[]){
	while(index!=idx[index]){
		idx[index]=idx[idx[index]];
		index=idx[index];
	}
	return index;
}
bool qfind(int p, int q, ll idx[]){
	return qroot(p,idx)==qroot(q,idx);
}
void qunion(int p, int q, ll idx[], ll sz[]){
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
////////////////////////////////////////////////////////////////////
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
//For fast IO
///////////////////////////////////////////////////////////////////// 
// Have you thought about it enough?
/////////////////////////////////////////////////////////////////////
//  std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
//  std::cout.precision(10);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int l=0,r=-1, ans=0, c1=0,c2=0,c3=0;
	vii temp(3,0);
	while(l<n){
		while(r<n-1){
			r++;
			if(s[r]=='a') c1++;
			else if(s[r]=='b') c2++;
			else c3++;
			temp[0]=c1, temp[1]=c2, temp[2]=c3;
			sort(all(temp));
			int minm=temp[0]+temp[1];
			if(minm>k) break;
			ans=max(ans, c1+c2+c3);
		}
		if(s[l]=='a') c1--;
		else if(s[l]=='b') c2--;
		else c3--;
		l++;
	}
	cout<<ans<<endl;	
    return 0;
}