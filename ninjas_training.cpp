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

void file_i_o() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> solution(n, vector<int> (3, 0));
    for(int i = 0; i < 3; i++) {
        solution[0][i] = points[0][i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++ ){
            solution[i][j] = points[i][j] + max(solution[i-1][(j + 1)%3], solution[i-1][(j+2)%3]);
        }
    }
    
    return max(max(solution[n-1][0], solution[n-1][1]), solution[n-1][2]);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > points(n, vector<int> (3));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    cout << ninjaTraining(n, points) << endl;
}

int main(){
file_i_o();
clock_t begin = clock();
    solve();

#ifndef ONLINE_JUDGE
   clock_t end = clock();
   cout<<"\n\nExecuted In: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl; 
#endif
return 0;
}