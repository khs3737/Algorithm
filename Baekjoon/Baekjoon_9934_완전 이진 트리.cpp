#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> node[1050];
int isVisited[1050];
int idx = 1;

void inorder(int k)
{
	if (k * 2 < pow(2, n))
		inorder(2 * k);
	if (isVisited[k] == 0)
	{
		isVisited[k] = 1;
		node[idx].first = k;
		idx++;
	}
	if (k * 2 + 1 < pow(2, n))
		inorder(2 * k + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	inorder(1);

	for (int i = 1; i < pow(2, n); i++)
		cin >> node[i].second;

	sort(node + 1, node + (int)pow(2, n));

	for (int i = 1; i < pow(2, n); i++)
	{
		cout << node[i].second << " ";
		int temp = i + 1;
		while (temp % 2 == 0)
		{
			temp /= 2;
		}
		if (temp == 1)
			cout << "\n";
	}
}
/*
	완전이진트리의 원소들이 중위순회로 방문한 순서대로 주어진다.
	주어진 완전이진트리를 낮은 레벨부터 한 줄에 한 레벨씩 출력해야한다.
	빌딩의 번호는 node[i].second에 입력받는다.
	inorder()에서 중위순회를 이용해서 node[i].first에 원소의 출력 순서를 저장한다.
	node를 출력순서로 정렬하고 출력한다.
*/