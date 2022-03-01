#include <iostream>
#include <vector>

using namespace std;

bool worthyObstacle(int row, int column, int queenRow, int queenColumn) {
    if (row == queenRow || column == queenColumn)
        return true;

    if (abs(row - queenRow) == abs(column - queenColumn)) {
        return true;
    }
    return false;
}

bool isValidPosition(int row, int col, int n) {
    if (row > 0 && row <= n && col > 0 && col <=n) return true;
    return false;
}

int main(){
    int n, obstacleCount;
    cin >> n >> obstacleCount;
    int queenRow,queenCol;
    cin >> queenRow >> queenCol;
    
    vector<vector<int>> obstacles;
    
    for (int i = 0; i < obstacleCount; ++i) {
        int row, column;
        cin >> row >> column;
        
        // non-worthy obstacles are ignored;
        if (worthyObstacle(row, column, queenRow, queenCol)) {
            obstacles.push_back(vector<int> { row, column });
        }
    }
    
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    int freeSquares = 0;
    
    for (int i = 0; i < 8; ++i) {
        int delX = dx[i];
        int delY = dy[i];
        
        int newQueenRow = queenRow+delX;
        int newQueenCol = queenCol+delY;
        
        while (true) {
            if (!isValidPosition(newQueenRow, newQueenCol, n)) {
                break;
            }
            bool hasObstacleHere = false;
            for (int j = 0; j < obstacles.size(); ++j) {
                if (obstacles[j][0] == newQueenRow && obstacles[j][1]==newQueenCol) {
                    hasObstacleHere = true;
                    break;
                }
            }
            if (hasObstacleHere) break;
            
            ++freeSquares;
            newQueenRow += delX;
            newQueenCol += delY;
        }
    }
    
    cout << freeSquares << endl;
}