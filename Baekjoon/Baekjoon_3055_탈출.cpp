#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int a[MAX][MAX];
int visited[MAX][MAX];
int n, m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool isUpdate;
// x,y 범위 체크
bool rangeCheck(int y,int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	else
		return false;
}
// 물의 이동
void water(int y,int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (rangeCheck(ny, nx) && a[ny][nx] == 0 && visited[ny][nx] == 0)
		{
			a[ny][nx] = 1;
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
}
// 고슴도치의 이동
int move(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (rangeCheck(ny, nx) && a[ny][nx] == 4)
		{
			return visited[y][x];
		}
		else if (rangeCheck(ny, nx) && a[ny][nx] == 0 && visited[ny][nx] == 0)
		{
			isUpdate = 1;
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			if (str[j] == '.') a[i][j] = 0;
			else if (str[j] == '*') { a[i][j] = 1; visited[i][j] = 1; }
			else if (str[j] == 'X')	a[i][j] = 2;
			else if (str[j] == 'S') { a[i][j] = 0; visited[i][j] = 1; }
			else if (str[j] == 'D') a[i][j] = 4;
		}
	}
	int t = 1;
	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && visited[i][j] == t)
					water(i, j);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0 && visited[i][j] == t)
				{
					int x =move(i, j);
					if (x > 0)
					{
						cout << x;
						return 0;
					}
				}
			}
		}
		if (!isUpdate)
		{
			cout << "KAKTUS";
				return 0;
		}
		t++;
		isUpdate = 0;
	}
}
/*
	water()함수로 물의 이동, move()함수로 고슴도치의 이동을 구현했다.
	visited 배열은 고슴도치 또는 물이 언제 방문했는지 저장한다.
	isUpdate 변수로 고슴도치가 이동할 수 있는지 확인하고 이동할 수 없으면 KAKTUS를 출력한다.
*/