// Write a program to return the sum of all even numbers in the Fibonacci series till a given number n.
// Ex: for n = 100, fib series till 100 is [1,1,2,3,5,8,21,34,55,89]. 
// Return sum of even numbers in it : 2+8+34 = 44

// #include <iostream>
// using namespace std;
// int main(){
//     int a1 = 1;
//     int a2 = 1;
//     int sum = 0;
//     int n;
//     cin>>n;
//     while(true){
//         int c1 = a1 + a2;
//         a2 = a1;
//         a1 = c1;
//         if(c1 >= n){
//             break;
//         }
//         if(c1 % 2 == 0){
//             sum += c1;
//         }
//     }

//     cout << sum << endl;
//     return 0;
// }


// Implement the Tower of Hanoi.

// #include<iostream>
// using namespace std;
// void solve(int n, int from, int to, int aux, int &count){
//     // Base Case
//     count++;
//     if(n == 1){
//          cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
//         return;
//     }

//     solve(n-1, from, aux, to, count);
//      cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
//     solve(n-1, aux, to, from, count);
// }
// int main(){
//     int n;
//     cin >> n;
//     int from = 1, to = 3, aux = 2, count = 0;
//     solve(n, from, to, aux, count);
//     cout << "Total Movement : " << count << endl;
//     return 0;
// }



// Maximal Rectangle 
// link : https://leetcode.com/problems/maximal-rectangle/

// class Solution {
// private:
//     void FindPrevSmall(int n, vector<int>& heights, vector<int>& prevSmall) {
//         stack<int> st;
//         st.push(-1);  
//         for (int i = 0; i < n; i++) {
//             while (st.top() != -1 && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//             prevSmall[i] = st.top();
//             st.push(i);
//         }
//     }

//     void FindNextSmall(int n, vector<int>& heights, vector<int>& nextSmall) {
//         stack<int> st;
//         st.push(-1); 
//         for (int i = n - 1; i >= 0; i--) {
//             while (st.top() != -1 && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }
//             nextSmall[i] = st.top();
//             st.push(i);
//         }
//     }

// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if (matrix.empty() || matrix[0].empty()) return 0;
        
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int maxi = 0;
        
//         vector<int> heights(m, 0);
        
//         for (int i = 0; i < n; i++) {
//             vector<int> prevSmall(m);
//             vector<int> nextSmall(m);
            
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == '1') {
//                     heights[j]++;
//                 } else {
//                     heights[j] = 0;
//                 }
//             }
            
//             FindPrevSmall(m, heights, prevSmall);
//             FindNextSmall(m, heights, nextSmall);
            
//             for (int j = 0; j < m; j++) {
//                 if (nextSmall[j] == -1){
//                     nextSmall[j] = m; 
//                 }
//                 int width = nextSmall[j] - prevSmall[j] - 1;
//                 int area = heights[j] * width;
//                 maxi = max(maxi, area);
//             }
//         }
//         return maxi;
//     }
// };
