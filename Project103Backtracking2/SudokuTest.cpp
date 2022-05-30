//
// Created by Kevin Yang on 3/20/21.
//

//5 3 0 0 7 0 0 0 0
//6 0 0 1 9 5 0 0 0
//0 9 8 0 0 0 0 6 0
//8 0 0 0 6 0 0 0 3
//4 0 0 8 0 3 0 0 1
//7 0 0 0 2 0 0 0 6
//0 6 0 0 0 0 2 8 0
//0 0 0 4 1 9 0 0 5
//0 0 0 0 8 0 0 7 9

#include <iostream>
#include <vector>

using namespace std;

bool valid(int row, int col, vector<vector<int>>& board){
    int i, j;
    for(i=0;i<9;i++){
        if(board[i][col]==board[row][col] && i!=row){
            return false;
        }
    }
    for(i=0;i<9;i++){
        if(board[row][i]==board[row][col] && i!=col){
            return false;
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
//            i=(row/3)*3+i;
//            j=(col/3)*3+j;
            if(board[(row/3)*3+i][(col/3)*3+j]==board[row][col] && (row/3)*3+i!=row && (col/3)*3+j!=col){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int i, j, t1;
    vector<int> t2;
    vector<vector<int>> board;
    for (i = 0; i < 9; i++) {
        for (j = 0, t2.clear(); j < 9; j++) {
            cin >> t1;
            t2.push_back(t1);
        }
        board.push_back(t2);
    }
    board[0][0]=9;
    valid(0,0,board);
}