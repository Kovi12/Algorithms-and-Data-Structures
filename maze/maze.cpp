#include <iostream>
#include <fstream>
#include "vector"
#define N 101
using namespace std;
int mat[N][N];
int answer[N];
void dfs(int start, vector<bool>& visited,int rooms)
{

    visited[start] = true;

    for (int i = 1; i <= rooms; i++) {

        if (mat[start][i] == 1 && (!visited[i])) {
            if (answer[start] == 1)
                answer[i] = 2;
            else
                answer[i] = 1;
            dfs(i, visited, rooms);
        }
    }

}
int main() {
    int rooms;
    ifstream  in("maze.in");
    ofstream  out("maze.out");
    in >> rooms;
    answer[1] = 1;
    for (int i = 0; i < rooms; i++) {
        int x,y;
        in >> x >> y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    in.close();
    vector<bool> visited(rooms + 1,false);
    dfs(1,visited,rooms);
    for (int i = 1; i <= rooms; i++)
        out << answer[i] << " ";
    out.close();
    return 0;
}
