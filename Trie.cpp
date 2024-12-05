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
ll mod       =          1000000007;    //    998244353LL
int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 0, -1, 1};
int dz[] = { -1, 1, 0, 0, 0, 0};
const int ddx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
const int ddy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

ll powmod(ll a, ll b, ll c = mod) {ll res = 1; a %= c; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % c; a = a * a % c;} return res;}
ll powb(ll a, ll b) {ll res = 1; a ; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a; a = a * a;} return res;}

const int SIZE = 100001;                              //constant SIZE here

//Can be inside Trie class too
struct TrieNode {
	char val;
	int endshere;
	int count;
	TrieNode *children[26];
};

class Trie {
	TrieNode *root;
	TrieNode* getNode(int index) {
		TrieNode* node = new TrieNode;
		node->val = 'a' + index;
		node->count = node->endshere = 0;
		for (int i = 0; i < 26; i++) node->children[i] = NULL;
		return node;
	}
public:
	Trie() {
		root = getNode('/' - 'a');
	}
	void insert(string s) {
		TrieNode *curr = root;
		for (int i = 0; i < s.size(); i++) {
			if (curr->children[s[i] - 'a'] == NULL) {
				TrieNode* node = getNode(s[i] - 'a');
				curr->children[s[i] - 'a'] = node;
			}
			curr->children[s[i] - 'a']->count++;
			curr = curr->children[s[i] - 'a'];
		}
		curr->endshere++;
	}
	bool search(string s) {
		TrieNode *curr = root;
		for (int i = 0; i < s.size(); i++) {
			if (curr->children[s[i] - 'a'] == NULL) return false;
			curr = curr->children[s[i] - 'a'];
		}
		return (curr->endshere > 0);
	}
	bool prefix(string s) {
		TrieNode *curr = root;
		for (int i = 0; i < s.size(); i++) {
			if (curr->children[s[i] - 'a'] == NULL) return false;
			curr = curr->children[s[i] - 'a'];
		}
		return true;
	}
};


signed main() {
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cerr.tie(NULL);
//For fast IO
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
	std::cout.unsetf ( std::ios::floatfield );  // floatfield not set
	std::cout.precision(6);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
// More design than code

	Trie *myTrie = new Trie();
	myTrie->insert("manvendra");
	myTrie->insert("pandey");
	myTrie->insert("man");
	myTrie->insert("pan");
	cout << myTrie->search("manvendra") << endl;
	cout << myTrie->search("manve") << endl;
	cout << myTrie->search("pan") << endl;
	cout << myTrie->prefix("pand") << endl;

#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}