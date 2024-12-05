#include<bits/stdc++.h>
//One implementation to rule them all?
#define db              double
#define ll              long long int
#define ld              long long double
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
typedef pair < int, int > pii;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T> >;
template <class T> using max_heap = priority_queue<T>;
const db PI = 2 * acos(0.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
db eps       =          0.000001;
ll mod       =          (1e9 + 7);  //998244353
void print(vector <int> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;
}
void printll(vector <ll> &arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    cout << endl;
}

ll ncr(ll n, ll r)
{
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
const int SIZE = 10000010;
bool judge(int a[], int n) {
    static int used[SIZE + 1];
    for (int i = 1; i <= n; i++) used[i] = 0;
    for (int i = 0; i < n; i++) used[a[i]] = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) return 0;
    }
    return 1;
}
vector <bool> prime(SIZE + 1, true);
vii primes;
vii spf(SIZE);
void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= SIZE; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= SIZE; j += i) prime[j] = false;
        }
    }
}
void sievespf()
{
    rep(i, 1, SIZE) spf[i] = i;
    for (int i = 4; i < SIZE; i += 2)
        spf[i] = 2;
    for (int i = 3; i * i < SIZE; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < SIZE; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
vector<bool> segment(ll L, ll R) {
    ll lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vll primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
vll cnt(SIZE);
void get()
{
    //Gets number of different prime divisors for numbers, used in CF EDU 106 D
    for (int i = 2; i < SIZE; ++i) {
        int j = i / spf[i];
        cnt[i] = cnt[j] + (spf[i] != spf[j]);
    }
}

void get(int x)
{
    int temp = x;
    mii mp;
    while (x != 1)
    {
        mp[spf[x]]++;
        x = x / spf[x];
    }
    ll tot = 1;
    for (auto i : mp) {
        tot *= (i.se + 1);
    }
    cnt[temp] = tot;
}

int main() {
//CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
//////////////////////////////////////////////////////////////////////
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
    sievespf();
    rep(i, 1, SIZE) get(i);
    vvi arr(11, vii (SIZE, 0));
    rep(i, 1, SIZE) {
        cnt[i] = i * cnt[i] + cnt[i - 1];
    }
    int n;
    cin >> n;
    cout << cnt[n] << endl;
    return 0;
}