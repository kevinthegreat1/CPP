#include <iostream>

using namespace std;

int search(string board[][100], bool visited[][100], int i, int j){
    int count;
    if(board[i][j]=="L"){
        visited[i][j]==true;
        if(board[i+1][j]=="Q"){
            count+=search(board, visited, i+1, j);
        } else if(board[i-1][j]=="Q"){
            count+=search(board, visited, i-1, j);
        } else if(board[i][j+1]=="Q"){
            count+=search(board, visited, i, j+1);
        } else if(board[i][j-1]=="Q"){
            count+=search(board, visited, i, j-1);
        }
    } else if(board[i][j]=="Q"){
        if(board[i+1][j]=="B"){
            count+=search(board, visited, i+1, j);
        } else if(board[i-1][j]=="B"){
            count+=search(board, visited, i-1, j);
        } else if(board[i][j+1]=="B"){
            count+=search(board, visited, i, j+1);
        } else if(board[i][j-1]=="B"){
            count+=search(board, visited, i, j-1);
        }
    } else if(board[i][j]=="B"){
        if(board[i+1][j]=="S"){
            count+=search(board, visited, i+1, j);
        } else if(board[i-1][j]=="S"){
            count+=search(board, visited, i-1, j);
        } else if(board[i][j+1]=="S"){
            count+=search(board, visited, i, j+1);
        } else if(board[i][j-1]=="S"){
            count+=search(board, visited, i, j-1);
        }
    } else if(board[i][j]=="S"){
        if(board[i+1][j]=="L"){
            count+=search(board, visited, i+1, j);
        } else if(board[i-1][j]=="L"){
            count+=search(board, visited, i-1, j);
        } else if(board[i][j+1]=="L"){
            count+=search(board, visited, i, j+1);
        } else if(board[i][j-1]=="L"){
            count+=search(board, visited, i, j-1);
        }
    }
    return count;
}

int main(){
    int width, length, i, j;
    cin>>width>>length;
    bool visited[100][100];
    string board[100][100];
    for(i=0;i<length;i++){
        for(j=0;j<width;j++){
            cin>>board[i][j];
        }
    }
}