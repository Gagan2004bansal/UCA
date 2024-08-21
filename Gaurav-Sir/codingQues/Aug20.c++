// #include <iostream>
// #include <vector>
// using namespace std;
// void change0to1(vector<vector<int>> &matrix){
//     int m = matrix.size();
//     int n = matrix[0].size();
// }
// void print(vector<vector<int>> &matrix){
//     int m = matrix.size();
//     int n = matrix[0].size();

//     for(int i = 0; i<m; i++){
//         for(int j = 0; j<n; j++){
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// int main(){
//     int m,n;
//     cin >> m >> n;

//     vector<vector<int>> matrix;
//     for(int i = 0; i<m; i++){
//         vector<int> temp;
//         for(int j = 0; j<n; j++){
//             int input;
//             cin >> input;
//             temp.push_back(input);
//         }
//         matrix.push_back(temp);
//     }

//     changeOto1(matrix);
//     print(matrix);

//     return 0;
// }

#include <iostream>
#include <vector>
#include <map>
using namespace std;
void compare(string card1, string card1Val, string card2, string card2Val, int opr){
    vector<string> suits = {"Heart", "Diamond", "Club", "Spades"};
    map<string, int> values = {{"2", 2}, {"3", 3}, {"4", 4},{"5", 5},{"6", 6},{"7", 7},{"8", 8},{"9", 9},{"10", 10},{"Jack", 11}, {"Queen", 12},  {"King", 13},  {"Ace", 14}};

    if(opr == 1){
        if(values[card1Val] == values[card2Val]){
            cout << "Both Card have the same value" << endl;
        }
        else if(values[card1Val] < values[card2Val]){
            if(card2Val == "Ace"){
                cout << "Ace of " << card2 << " has higher value" << endl;
            }
            else{
                cout << values[card2Val] << " of " << card2 << " has higher value" << endl;   
            }
        }
        else if(values[card1Val] > values[card2Val]){
            if(card1Val == "Ace"){
                cout << "Ace of " << card2 << " has higher value" << endl;
            }
            else{
                cout << values[card1Val] << " of " << card2 << " has higher value" << endl;   
            }
        }
    }
    else if(opr == 2){
        if (card1 == card2)
        {
            cout << "Same Card" << endl;
        }
        else{
            cout << "No Same Card" << endl;
        }
    }

}
int main(){ 
    string card1, card1Val, card2, card2Val;
    cin >> card1 >> card1Val >> card2 >> card2Val;

    compare(card1, card1Val, card2, card2Val, 1);
    return 0;
}