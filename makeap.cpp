//Problem link - https://codeforces.com/problemset/problem/1624/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long int,
#define ld long double
#define endl "\n"
#define inf 1e18
#define mod 1000000007
#define pq priority_queue
#define ump unordered_map
#define forrev(i,a,b) for(int i = (a);i>=b;i--)
#define vi vector<ll>
#define vs vector<string>


void solve() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b, c;
        cin >> a >> b >>c;

        int d1 = b - a;
        int d2 = c - b;
        int d3 = (c - a)/2;

        if ((b + d1)% c == 0 and (b + d1)/c >= 1) {
            cout << "YES" <<endl;
        }
        else if ( (b - d2)%a == 0 and (b - d2)/a >= 1) {
            cout << "YES" <<endl;
        }
        else if((c-a)%2 == 0 and((a + d3)%b == 0 and (a + d3)/b >= 1) ) {
            cout << "YES" <<endl;
        }
        else{
            cout << "NO" <<endl;
        }
    }
}


int main(){
clock_t begin = clock();
    //Enter Your code here..
    solve();
    


// #ifndef ONLINE_JUDGE
//    clock_t end = clock();
//    cout<<"\n\nExecuted In: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms"; 
// #endif
return 0;
}