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
#define rall(x) 			x.rbegin(), x.rend()
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
#define mod 			1000000007LL
#define mod2 			1000000009LL
#define mod3 			998244353LL
#define eb 				emplace_back
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
db eps       =          1e-7;
// const int dx[] = {0, 0, -1, 1, 0, 0};
// const int dy[] = {0, 0, 0, 0, -1, 1};
const int dx[] = { -1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

// const int dz[] = { -1, 1, 0, 0, 0, 0};
const int ddx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
const int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 300010;        //constant SIZE here
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
	for (i = 0; i < r; i++) {
		ans = (ans * A[i] % mod);    //with mod
		// ans = (ans * A[i]);				//without mod
	}
	return ans;
}

//Basic SegTree
//Min, Max, Sum, GCD/LCM, Number of Zeros/Index of K-th 0,
//Maximum with frequency of maximum, Finding subsegments with the maximal sum (VVIP)
// https://ideone.com/2myOOp - Code to lazy Prop implementation
// ll st[4 * SIZE], lazy[4 * SIZE];
// char w[200];

// void build(int arr[], int tl, int tr, int v) {
// 	if (tl == tr) {
// 		st[v] = arr[tl];
// 		return;
// 	}
// 	int tm = (tl + tr) >> 1;

// 	build(arr, tl, tm, 2 * v);
// 	build(arr, tm + 1, tr, 2 * v + 1);

// 	st[v] = min(st[2 * v] , st[2 * v + 1]);
// }

// void update(int val, int l, int r, int tl, int tr, int v) {
// 	if (lazy[v] != 0) {
// 		st[v] += lazy[v];

// 		if (tl != tr) {
// 			lazy[2 * v] += lazy[v];
// 			lazy[2 * v + 1] += lazy[v];
// 		}

// 		lazy[v] = 0;
// 	}
// 	if (tl > r || tr < l) {
// 		return;
// 	}

// 	if (tl >= l && tr <= r) {
// 		st[v] +=  val;

// 		if (tl != tr) {
// 			lazy[2 * v] += val;
// 			lazy[2 * v + 1] += val;
// 		}

// 		return;
// 	}

// 	int tm = (tl + tr) >> 1;
// 	update(val, l, r, tl, tm, 2 * v);
// 	update(val, l, r, tm + 1, tr, 2 * v + 1);

// 	st[v] = min(st[2 * v] , st[2 * v + 1]);
// }

// ll query(int l, int r, int tl, int tr, int v) {
// 	if (lazy[v] != 0) {
// 		st[v] += lazy[v];

// 		if (tl != tr) {
// 			lazy[2 * v] += lazy[v];
// 			lazy[2 * v + 1] += lazy[v];
// 		}

// 		lazy[v] = 0;
// 	}

// 	if (tl > r || tr < l) {
// 		return LLONG_MAX;
// 	}

// 	if (tl >= l && tr <= r) {
// 		return st[v];
// 	}

// 	int tm = (tl + tr) >> 1;
// 	ll lmin = query(l, r, tl, tm, 2 * v), rmin = query(l, r, tm + 1, tr, 2 * v + 1);
// 	return min(lmin, rmin);

// }

//int st[SIZE];
//void buildTree(int arr[], int v, int start, int end) {
//	if (start == end) {
//		st[v] = (arr[start]==0);
//		return;
//	}
//	int mid = start + (end - start) / 2;
//
//	buildTree(arr, 2 * v, start, mid);
//	buildTree(arr, 2 * v + 1, mid + 1, end);
//
//	st[v] = st[2 * v] + st[2 * v + 1];
//}
//
//int answerQuery(int l, int r, int ss, int se, int v) {
//	if (ss > r || se < l) {
//		return 0;
//	}
//	if (ss >= l && se <= r) {
//		return st[v];
//	}
//	int mid = ss + (se - ss) / 2;
//
//	int lans = answerQuery(l, r, ss, mid, 2 * v);
//	int rans = answerQuery(l, r, mid + 1, se, 2 * v + 1);
//
//	return lans + rans;
//}
//
//void pointUpdate(int val, int idx, int ss, int se, int v){
//	if(ss==se){
//		st[v]=(val==0);
//		return;
//	}
//
//	int mid=ss+(se-ss)/2;
//
//	if(idx<=mid){
//		pointUpdate(val,idx,ss,mid,2*v);
//	}
//	else pointUpdate(val,idx,mid+1,se,2*v+1);
//	st[v]=st[2*v]+st[2*v+1];
//}
//
//int find_kth(int v, int tl, int tr, int k){
//	if(k>st[v]) return -1;
//	if(tl==tr) return tl;
//	int tm=(tl+tr)/2;
//	if(st[2*v]>=k){
//		return find_kth(2*v,tl,tm,k);
//	}
//	else{
//		return find_kth(2*v+1,tm+1,tr,k-st[2*v]);
//	}
//}
vll f(1001);
void fact()
{
	f[0] = 1, f[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		f[i] = f[i - 1] * i;
	}
}


void solve()
{
	fact();
	string s;
	int n;
	cin >> s >> n;
	int len = sz(s);
	vii freq(26);
	for (auto i : s)
	{
		freq[i - 'a']++;
	}
	int k = 0, sum = 0;
	string out = "";
	while (sum != n)
	{
		sum = 0;
		rep(i, 0, 26)
		{
			if (freq[i] == 0) continue;
			freq[i]--;
			int xsum = f[len - 1 - k];
			rep(j, 0, 26)
			{
				xsum /= f[freq[j]];
			}
			sum += xsum;
			if (sum >= n)
			{
				n -= (sum - xsum);
				out += char('a' + i);
				k++;
				break;
			}
			if (sum < n)
			{
				freq[i]++;
			}
		}
	}
	for (int i = 25; k < len && i >= 0; i--)
		if (freq[i]) {
			k++;
			out += char('a' + i);
			freq[i++]--;
		}

	cout << out << endl;
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