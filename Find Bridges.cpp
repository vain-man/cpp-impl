// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define db              double
#define ll              long long int
#define ld              long double
//#define int           long long int
#define ull             unsigned long long
#define fi              first
#define se              second
#define rep(i,a,n)      for(int i=a;i<n;i++)
#define repr(i,n,b)     for(int i=n;i>b;i--)
#define endl            '\n'
#define mem(a,b)        memset(a, b, sizeof a)
#define mkp             make_pair
#define pb              push_back
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define w(t)            int t; cin>>t; while(t--)
#define all(a)          a.begin(), a.end()
#define sz(a)           int((a).size())
#define debug           cerr << " Here. " << endl;
#define dbg(x)          cerr << #x << " = " << x << endl;
#define dbgp(x)         cerr<<"[ "<<#x<<".fi : "<<x.first<<", "<<#x<<".se : "<<x.second<<" ]"<<endl
#define dbgs(x)         cerr<<"[ "; for(auto i:x) cerr<<i<<" "; cerr<<" ]"<<endl;
#define dbgm(x)         cerr<<"----------"<<endl; for(auto i:x) cerr<<i.fi<<":"<<i.se<<endl; cerr<<"----------";
#define printdb(i)      printf("%.12lf\n",i)
#define isOn(S, j)      (S & (1<<j))
#define setBit(S, j)    (S |= (1<<j))
#define clearBit(S, j)  (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S)       (S & (-S))
#define setAll(S, n)    (S = (1<<n)-1)
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define display(a)      for(auto x: a) cerr<<x<<" "; cerr<<"\n";
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef map < int, int > mii;
typedef vector < int > vii;
typedef vector < ll > vll;
typedef vector < vii > vvi;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <class T> using max_heap = priority_queue<T>;
const db PI =           acos(-1);
const int INF =         0x3f3f3f3f;
const ll LINF =         (ll)2e18;
db eps       =          1e-5;
ll mod       =          1000000007; //     998244353
// const int dx[] = {0, 0, -1, 1, 0, 0};
// const int dy[] = {0, 0, 0, 0, -1, 1};
const int dx[] = { -1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// const int dz[] = { -1, 1, 0, 0, 0, 0};
const int ddx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
const int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 1e5 + 10; //constant SIZE here
bool judge(int a[], int n) {
	static int used[SIZE + 1];
	for (int i = 1; i <= n; i++) used[i] = 0;
	for (int i = 0; i < n; i++) used[a[i]] = 1;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) return 0;
	}
	return 1;
}


ll ncr(ll n, ll r) {
	r = min(r, n - r);
	ll A[r], i, j, B[r];
	iota(A, A + r, n - r + 1);
	iota(B, B + r, 1);

	ll g;
	for (i = 0; i < r; i++)
		for (j = 0; j < r; j++)
		{
			if (B[i] == 1)
				break;
			g = __gcd(B[i], A[j] );
			A[j] /= g;
			B[i] /= g;
		}
	ll ans = 1;
	for (i = 0; i < r; i++)
		ans = (ans * A[i] % mod);
	return ans;
}
vii adj(SIZE);
vii tin(SIZE), tout(SIZE), low(SIZE);
vii vis(SIZE);
int timer = 0;
void DFS(int u, int p) {
	tin[u] = low[u] = timer;
	timer++;
	vis[u] = 1;
	for (auto i : adj[u]) {
		if (i == p) continue;
		if (vis[i]) {
			low[u] = min(low[u], tin[i]);
		}
		else {
			DFS(i, u);
			if (low[i] > tin[u]) {
				cout << u << " -- > " << v << " : Bridge" << endl;
			}
			low[u] = min(low[u], low[v]);
		}
	}
}
void solve() {
	int n, m, u, v;
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i, 0, n) {
		if (!vis[i]) {
			DFS(i, i);
		}
	}
	return;
}

signed main() {
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr.tie(NULL);
//For fast IO
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
	// std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
	// std::cout.precision(15);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
// More design than code
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}