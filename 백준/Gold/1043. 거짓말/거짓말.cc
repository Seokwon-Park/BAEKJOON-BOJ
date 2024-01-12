#include <bits/stdc++.h>

using namespace std;

vector<int> p(55, -1);
//진실을 알고 있는 사람 i에 대해 p[i] = -2로 한다.
// 그러면 모르는 사람이 진실을 알고 있는 사람과 union 될때 무조건 find시 -2가 나오게 될것.

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void union_(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b) return;
	if (p[a] < p[b]) p[b] = a;
	else p[a] = b;
}

bool is_know(int x)
{
	x = find(x);
	if (p[x] == -2) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int h;
	cin >> h;
	vector<int> tru(h);
	for (int i = 0; i < h; i++)
	{
		cin >> tru[i];
		p[tru[i]] = -2;
	}

	vector<vector<int>> partyrec(m); // 일단 union을 구성하고 다시 거짓말 할수 있는 파티를 가려내기 위해서
	for (int i = 0; i < m; i++)
	{
		int party;
		cin >> party; // 파티에 오는 인원수

		int prev; 
		for (int j = 0; j < party; j++)
		{
			int tmp;
			cin >> tmp;
			partyrec[i].push_back(tmp);
			if (j > 0)
			{
				union_(prev, tmp); // 이전 번호 사람과 현재 번호 사람은 같은 파티에 있으므로 같은 집합으로 만들어준다.
			}
			prev = tmp;
		}
	}
	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		bool can_lie = true;
		for (int j = 0; j < partyrec[i].size(); j++)
		{
			if (is_know(partyrec[i][j])) //만약 진실을 알고 있는 사람과 같은 집합에 속한 사람이 있으면 그 파티에서는 거짓말을 하면 안된다.
			{
				can_lie = false; break;
			}
		}
		if (can_lie) answer++;
	}
	cout << answer;

	return 0;
}