//Problem link - UBER coding 300 point question
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


int max_score = INT_MIN;

int finalfour(const vector<int> &arr) {
    int sum = (arr[0]*arr[1]*arr[2]*arr[3] + arr[0]*arr[3])%mod;
    return sum;
}

void maximum_score(vector<int> &arr, int cur_score){ 
    if (arr.size() == 4) {
        cur_score = (cur_score + finalfour(arr))%mod;
        if (cur_score > max_score) {
            max_score = cur_score;
        }
    }
    vector<int> :: iterator it;
    for (int i = 1; i < arr.size() - 3; i++) {
        int a = arr[i];
        int b = arr[i+1];
        int temp = cur_score;

        cur_score = (cur_score + arr[i-1]*arr[i]*arr[i+1]*arr[i+2])%mod;
        it = arr.begin() + i;
        arr.erase(it);
        arr.erase(it);
        maximum_score(arr, cur_score);
        arr.insert(it, b);
        arr.insert(it, a);
        cur_score = temp;
    }
}
void solve() {
    int n; 
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++ )
        cin >> array[i];
    int cur_score = 0;
    maximum_score(array, cur_score);
    cout << max_score << endl;
}

int main(){
clock_t begin = clock();
    solve();

#ifndef ONLINE_JUDGE
   clock_t end = clock();
   cout<<"\n\nExecuted In: "<<double(end-begin) / CLOCKS_PER_SEC*1000<<" ms"; 
#endif
return 0;
}