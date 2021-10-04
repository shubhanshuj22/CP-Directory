// problem URL https://codeforces.com/contest/1579/problem/E2



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define uniq(v)         (v).erase(unique(all(v)),(v).end())
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define pii             pair<int,int>
#define mem1(a)         memset(a,-1,sizeof(a))
#define mem0(a)         memset(a,0,sizeof(a))
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define rep(i,a,b)      for(int i=a;i<b;i++)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}
template<typename T>
using pbds = tree<T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>;
const int N = 1e5 + 5;

void solve() {

    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    pbds<pii>st; // policy based data structure in c++
    list<int>l; // using std :: list data structure as a container


    // find out how many elements are smaller and how many are greater in the array

    st.insert({v[0], 0});
    l.push_back(v[0]);
    int ans = 0;

    for (int i = 1; i < n; i++) {

        int lesser = st.order_of_key({v[i], -1});
        int greater = st.size() - st.order_of_key({v[i], mod});

        if (lesser >= greater) {
            ans += greater;
            l.push_back(v[i]);
        }
        else {
            ans += lesser;
            l.push_front(v[i]);
        }

        st.insert({v[i], i});


    }
    cout << ans << endl;

}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;

}