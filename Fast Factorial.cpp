ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powb(ll a,ll b) {ll res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}

const int SIZE=3e5+10;                                //constant SIZE here
bool judge(int a[], int n){
    static int used[SIZE+1];
    for(int i = 1; i <= n; i++) used[i] = 0;
    for(int i = 0; i < n; i++) used[a[i]] = 1;
    for(int i = 1; i <= n; i++) {
        if(!used[i]) return 0;
    }
    return 1;
}
ll fact[SIZE], inv[SIZE];
ll ncr(ll n , ll r)
{
	if(n<r) return 0;
    return ((fact[n] * inv[n-r])%mod * inv[r])%mod;
}
void funct(){
	fact[0]=1;
	for(ll i=1;i<SIZE;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	inv[SIZE-1]=powmod(fact[SIZE-1],mod-2);
	for(ll i=SIZE-2;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}