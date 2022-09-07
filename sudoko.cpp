#include <iostream>
#include <vector>
using namespace std;
#define print(x)     for(auto i:x) {cout << i<< " ";} cout << '\n';
#define print2d(x)   for(auto i:x) {print(i);} cout << "\n\n";
#define vint         vector<int>
#define vvint        vector<vector<int>>


const int n = 9;
/* function to check if putting a certain value in a certain square is valid or not */
bool valid(vvint grid, int row , int col , int val){

// check for any val in the same col or row
for(int i =0 ;i<n; i++){
if (grid[i][col] == val) return false;

}


// check for the same val in the same row
for(int i =0 ;i<n; i++){
if (grid[row][i] == val) return false;
}

// check if the same val in the same 3x3 board
int r = row/3*3, c = col/3*3;
for(int i =r; i<r+3; i++){
    for(int j = c; j<c+3; j++){
        if (grid[i][j] == val) return false;
    }
}

return true; // return true if no condition of the above is satisfied 
}

void solve(vvint grid, int row = 0, int col = 0){
if (row == n-1 and col == n){ // Base Case (found a solution)
    print2d(grid);
    return;
}
if (col == n){ // if reached the end of a column, start over from the first col in the next row
    col = 0;
    row++;
}
if (grid[row][col] != 0){ // if already filled, go to the next column
    return solve(grid,row,col+1);
}
for(int val = 1; val<10; val++)
{
    if (valid(grid,row,col,val)){
        grid[row][col] = val; // Do
        solve(grid,row,col+1); // Backtrack
        grid[row][col] = 0; // Undo
    }
}

}
int main () {
   freopen("in.in", "r",stdin);    // 9x9 input board
   freopen("out.out", "w",stdout); // 9x9 output board (if empty means there is no solution)
    vvint grid(9,vint(9,0));
    
    // read input from the user
    for(int i =0; i<9; i++){
    for(int j =0; j<9;j++){
    cin >> grid[i][j];}}

    solve(grid);
}