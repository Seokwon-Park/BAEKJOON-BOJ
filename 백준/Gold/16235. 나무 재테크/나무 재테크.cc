#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int n, m, k;
int b[15][15]; // 현재 있는 양분
int a[15][15]; // 기계가 추가하는 양분
int summeradd[15][15]; // 여름에 뒤진 넘들이 추가하는 양분
bool useBuffer = false;
vector<tiii> vec1;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };


void spring()
{
	vector<tiii> vec2;
	int sz = vec1.size();
	for (int i = 0; i <sz; i++)
	{
		int age, x, y;
		tie(age, x, y) = vec1[i];
		if (age == 0)continue;
		if (b[y][x] >= age)
		{
			b[y][x] -= age;
			age++;
			vec1[i] = { age,x,y };
			if (age % 5 == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					int tx = x + dx[i];
					int ty = y + dy[i];
					if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
					vec2.push_back({ 1, tx, ty });
				}
			}
		}
		else
		{
			summeradd[y][x] += age / 2;
			vec1[i] = { 0, y, x };
		}
	}
	for (int i = 0; i < sz; i++)
	{
		int age, x, y;
		tie(age, x, y) = vec1[i];
		if (age != 0)
		{
			vec2.push_back(tie(age, x, y));
		}
	}
	vec1.swap(vec2);
}
//void summer()
//{
//
//}
//void fall()
//{
//
//}
void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] += a[i][j];
			b[i][j] += summeradd[i][j];
			summeradd[i][j] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = 5; // 처음에 양분은 5만큼 들었다.
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int y, x, age;
		cin >> y >> x >> age;
		x--;
		y--;
		vec1.push_back(tie(age, x, y));
	}

	sort(vec1.begin(), vec1.end());
	for (int i = 0; i < k; i++)
	{
		spring();
		//summer();
		//fall();
		winter();
	}


	cout << vec1.size();


	return 0;
}