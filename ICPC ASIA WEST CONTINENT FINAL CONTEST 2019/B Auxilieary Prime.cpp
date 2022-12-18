#include<bits/stdc++.h>
using namespace std;

struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10); } } ___;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define LL long long
#define LD long double
#define asort(ar,n) sort(ar,ar+n)
#define vsort(vc) sort(vc.begin(),vc.end())
#define vrsort(vc) sort(vc.rbegin(),vc.rend())
#define srev(st) reverse(st.rbegin(),st.rend())
#define psum(vc,sm) partial_sum(vc.begin(),vc.end(),sm.begin()+1)
#define pxor(vc,sm) partial_sum(vc.begin(),vc.end(),sm.begin()+1,[](LL x, LL y){return x^y;})
#define pgcdLeft(vc,sm) partial_sum(vc.begin(),vc.end(),sm.begin()+1,[](LL x, LL y){return __gcd(x,y);})
#define pgcdRight(vc,sm) partial_sum(vc.rbegin(),vc.rend(),sm.begin()+1,[](LL x, LL y){return __gcd(x,y);})

const LL maxN=1e7+5;
bool isPrime[maxN];

void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<maxN; i++) isPrime[i]=true;

    for(int i=2; i*i<maxN; i++)
        if(isPrime[i])
            for(int j=i*i; j<maxN; j+=i)
                isPrime[j]=false;
}

bool call(LL num)
{
    string str=to_string(num);
    if(isPrime[num]) return true;

    for(LL i=1; i<10; i++)
    {
        str[0]=i+48;
        if(isPrime[stoll(str)]) return true;
    }

    for(LL i=1; str[i]; i++)
    {
        str=to_string(num);
        for(LL j=0; j<10; j++)
        {
            str[i]=j+48;
            if(isPrime[stoll(str)]) return true;
        }
    }

    return false;
}

int main()
{
    FastIO;
    sieve();

    LL t=1,n; cin>>t;
    while(t--)
    {
        cin>>n;
        if(call(n)) cout<<"yes\n";
        else cout<<"no\n";
    }

    return 0;
}
