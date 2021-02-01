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
	��������Ʈ���� ���ҵ��� ������ȸ�� �湮�� ������� �־�����.
	�־��� ��������Ʈ���� ���� �������� �� �ٿ� �� ������ ����ؾ��Ѵ�.
	������ ��ȣ�� node[i].second�� �Է¹޴´�.
	inorder()���� ������ȸ�� �̿��ؼ� node[i].first�� ������ ��� ������ �����Ѵ�.
	node�� ��¼����� �����ϰ� ����Ѵ�.
*/