/*

Description
There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. 
Each path corresponds to a 48-character description consisting of characters D (down), 
U (up), L (left) and R (right).

For example, the path
corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.
You are given a description of a path which may also contain characters ? (any direction). 
Your task is to calculate the number of paths that match the description.

Input Format
The only input line has a 48-character string of characters ?, D, U, L and R.

Output Format
Print one integer: the total number of paths.

Constraints
Sample Input 1
??????R??????U??????????????????????????LD????D?
Sample Output 1
201

*/

#include <bits/stdc++.h>
using namespace std;

string path;
bool board[7][7];
long long ans;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
map<char, int> dir;

bool IsValid(int x, int y) {
	return (x >= 0 && x < 7 && y >= 0 && y < 7 && !board[x][y]);
}

bool IsPossible(int x, int y) {
	// left-right wall
	if (!IsValid(x + 1, y) && !IsValid(x - 1, y) && IsValid(x, y + 1) && IsValid(x, y - 1)) {
		return true;
	}
	// top-bottom wall
	if (IsValid(x + 1, y) && IsValid(x - 1, y) && !IsValid(x, y + 1) && !IsValid(x, y - 1)) {
		return true;
	}
	return false;
}

void Rec(int x, int y, int index) {
	if (index == 48) {
		if (x == 6 && y == 0) {
			ans++;
		}
		return;
	}
	if ((x == 6 && y == 0) || IsPossible(x, y)) {
		return;
	}
	if (path[index] == '?') {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (IsValid(nx, ny)) {
				board[nx][ny] = 1;
				Rec(nx, ny, index + 1);
				board[nx][ny] = 0;
			}
		}
	} else {
		int nx = x + dx[dir[path[index]]];
		int ny = y + dy[dir[path[index]]];
		if (IsValid(nx, ny)) {
			board[nx][ny] = 1;
			Rec(nx, ny, index + 1);
			board[nx][ny] = 0;
		}
	}
}

void solution() {
	cin >> path;
	dir['R'] = 0; dir['D'] = 1; dir['L'] = 2; dir['U'] = 3;
	board[0][0] = true;
	Rec(0, 0, 0);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
	return 0;
}