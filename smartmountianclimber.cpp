//Problem link - 
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


int maxTries(int p, int q) {
    vector<vector<int>> tries(p+1, vector<int> (q+1, 0));

    for (int i = 1; i <=q; i++) {
        tries[1][i] = i;
    }
    for (int i = 1; i<=p ; i++) {
        tries[i][1] = 1;
    }
    if ( p > 1 and q > 1) {
        for (int i = 2; i <= p; i++) {
            for (int j = 2; j <= q; j++) {
                int mid = q%2?q/2:q/2+1;
                tries[i][j] = max( (1+ tries[i-1][j-mid]), (1 + tries[i][mid -1]) );
        }
    }
    }
    

    return tries[p][q];

}

void solve() {
    int p, q;
    cin >> p >> q;

    cout << maxTries(p, q) << endl;
}

int main(){
clock_t begin = clock();
    //Enter Your code here..
    solve();


#ifndef ONLINE_JUDGE
   clock_t end = clock();
   cout<<"\n\nExecuted In: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms"; 
#endif
return 0;
}