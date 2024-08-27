// #include <iostream>
// #include <vector>
// using namespace std;
// void reachEnd(int i, int j, int n, int m){
//     if(i > n || j > m){
//         return;
//     }
//     if(i == n && j == m){
//         cout << i << " -> " << j << endl;
//         return;
//     }

//     cout << i << " -> " << j << " : ";
//     reachEnd(i+1, j, n, m);
//     reachEnd(i, j+1, n, m);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;

//     reachEnd(0, 0, n, m);
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int reachEnd(vector< vector<char> > mat, int i, int j, int n, int m){
//     if(i >= n || j >= m){
//         return 0;
//     }
//     if(i == n-1 && j == m-1){
//         return mat[i][j] - '0';
//     }

//     int path1 = reachEnd(mat, i+1, j, n, m);
//     int path2 = reachEnd(mat, i, j+1, n, m);

//     return (mat[i][j] - '0') + max(path1, path2);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;

//     vector< vector<char> > mat;
//     for(int i = 0; i<n; i++){
//         vector<char> temp(m);
//         for(int j = 0; j<m; j++){
//             cin >> temp[j];
//         }
//         mat.push_back(temp);
//     }

//     cout << reachEnd(mat, 0, 0, n, m) << endl;
//     return 0;
// }


// way - 1
// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;
// int reachEnd(vector< vector<char> > mat, int i, int j, int n, int m){
//     if(i >= n || j >= m){
//         return INT_MAX;
//     }
//     if(i == n-1 && j == m-1){
//         return mat[i][j] - '0';
//     }

//     int path1 = reachEnd(mat, i+1, j, n, m);
//     int path2 = reachEnd(mat, i, j+1, n, m);

//     return (mat[i][j] - '0') + min(path1, path2);
// }
// int main(){
//     int n,m;
//     cin>>n>>m;

//     vector< vector<char> > mat;
//     for(int i = 0; i<n; i++){
//         vector<char> temp(m);
//         for(int j = 0; j<m; j++){
//             cin >> temp[j];
//         }
//         mat.push_back(temp);
//     }

//     cout << reachEnd(mat, 0, 0, n, m) << endl;
//     return 0;
// }

// way - 2
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
bool isValid(int i , int j, int n, int m){
    if(i >=n || j >= m){
        return false;
    }
    return true;
}
int reachEnd(vector< vector<char> > mat, int i, int j, int n, int m){
    if(i == n-1 && j == m-1){
        return mat[i][j] - '0';
    }

    bool choice1 = isValid(i+1, j, n, m);
    bool choice2 = isValid(i, j+1, n, m);

    if(choice1 && choice2){
        int path1 = reachEnd(mat, i+1, j, n, m);
        int path2 = reachEnd(mat, i, j+1, n, m);
        return min(path1, path2) + (mat[i][j] - '0');
    }
    else if(choice1){
        int path1 = reachEnd(mat, i+1, j, n, m);
        return path1 + (mat[i][j] - '0');
    }

    return reachEnd(mat, i, j+1, n, m) + (mat[i][j] - '0');
}
int main(){
    int n,m;
    cin>>n>>m;

    vector< vector<char> > mat;
    for(int i = 0; i<n; i++){
        vector<char> temp(m);
        for(int j = 0; j<m; j++){
            cin >> temp[j];
        }
        mat.push_back(temp);
    }

    cout << reachEnd(mat, 0, 0, n, m) << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <limits.h>
// using namespace std;
// int solve(vector< vector<char> > &mat, int n, int m, vector< vector<int> >& dp) {
//     if (n < 0 || m < 0 || mat[n][m] == '*') {
//         return INT_MIN;
//     }
    
//     if (n == 0 && m == 0) {
//         return (mat[n][m] - '0');
//     }
    
//     if (dp[n][m] != -1) {
//         return dp[n][m];
//     }

//     int path1 = INT_MIN;
//     if(n > 0){
//         path1 = solve(mat, n-1, m, dp);
//     }
//     int path2 = INT_MIN;
//     if(m > 0){
//         path2 = solve(mat, n, m-1, dp);
//     }
    
//     int maxPath = max(path1, path2);
//     if (maxPath == INT_MIN) {
//         dp[n][m] = INT_MIN;
//     } else {
//         dp[n][m] = (mat[n][m] - '0') + maxPath;
//     }

//     return dp[n][m];
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector< vector<char> > mat(n, vector<char>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> mat[i][j];
//         }
//     }

//     vector< vector<int> > dp(n, vector<int>(m, -1));

//     int result = solve(mat, n - 1, m - 1, dp);
    
//     if (result == INT_MIN) {
//         cout << "-1" << endl;
//     } else {
//         cout << result << endl;
//     }

//     return 0;
// }
