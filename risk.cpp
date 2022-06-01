//Problem link - https://www.codechef.com/LP3TO401/submit/RISK
/* Harshit Narayana */
#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
#define inf 1e18
#define mod 1000000007
#define pq priority_queue
#define ump unordered_map
#define vi vector<int>
#define vs vector<string>

int m, n;
bool isValid(int i, int j) {
    if(i>=0 and i <= m-1 and j>=0 and j <= n-1)
        return true;
    else
        return false;
}

void neighbours(vector<string> &map, vector<vector<bool>> &visited,queue<pair<int, int>> &Q, int i, int j) {
    if(isValid(i-1, j)) {
        if(map[i-1][j] == '1' and !visited[i-1][j]) {
            Q.push(make_pair(i-1, j));
            visited[i-1][j] = true;
        }
            
    }
    if(isValid(i+1, j)) {
        if(map[i+1][j] == '1' and !visited[i+1][j]){
            Q.push(make_pair(i+1, j));
            visited[i+1][j] = true;
    }}
    if(isValid(i, j-1)) {
        if(map[i][j-1] == '1' and !visited[i][j-1]){
            Q.push(make_pair(i, j-1));
            visited[i][j-1] = true;
    }}
    if(isValid(i, j+1)) {
        if(map[i][j+1] == '1' and !visited[i][j+1]){
            Q.push(make_pair(i, j+1));
            visited[i][j+1] = true;
    }}
}
int bfs(vector<string> &map, vector<vector<bool>> &visited, int i, int j) {
    queue<pair<int, int>> Q;
    int count = 1;
    visited[i][j] = true;
    neighbours(map, visited, Q, i, j);
    while(!Q.empty()) {
        pair<int, int> a = Q.front();
        count++;
        //cout << a.first << " " << a.second << endl;
        //visited[a.first][a.second] = true;
        neighbours(map, visited, Q, a.first, a.second);
        Q.pop();
    }
    
    return count;
}

int main(){
    //Enter Your code here..
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        vector<string> map(m);
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i <m; i++) {
            cin >> map[i];
        }
        vector<int> land;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == '1' and !visited[i][j]) {
                    int area = bfs(map, visited, i, j);
                    //cout << area << endl;
                    land.push_back(area);
                }
            }
        }
        sort(land.begin(), land.end(), greater<int>());
        int chef = 0;
        // for(int i = 0; i < land.size(); i++)
        //     cout << land[i] << " ";
        if(land.size() == 1){
            cout << chef << endl;
            continue;
        }
        for(int i = 1; i < land.size(); i+=2)
            chef += land[i];
        
        cout << chef << endl;
        
    }
    
    return 0;
}
