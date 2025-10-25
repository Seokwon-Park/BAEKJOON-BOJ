#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

char b[3][3];
vector<char> moved;
bool isGFind = false;
int n = 0;
int x = 0;
int y = 0;
int gx = 0;
int gy = 0;

void input()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cin >> b[r][c];
		}
	}
}

void move(char dir)
{
	cout << "? " << dir << endl;
	moved.push_back(dir);
	switch (dir)
	{
	case 'R':
		x++;
		break;
	case 'L':
		x--;
		break;
	case 'U':
		y--;
		break;
	case 'D':
		y++;
		break;
	}
}

bool checkG()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (b[r][c] == 'G') // G가 3x3안에 있는 경우
			{
				isGFind = true;
				gx = c - 1;
				gy = r - 1;
				return isGFind;
			}
		}
	}
	return isGFind;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	input(); // 초기 상태 받고

	while (true) // 일단 일자로 가면서 G를 찾거나 R을 찾아서 N값을 구하기
	{
		checkG();
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				if (x > 0 && b[1][1] == 'R') // 움직여서 제자리로 돌아왔는데 R인 경우 N의 길이를 파악할 수 있음
				{
					n = x;
				}
			}
		}
		if (isGFind || n != 0) break;
		move('R');
		input();
	}

	if (!isGFind) // 아직도 G를 못찾았어 그럼 한바퀴 돌아서 R에 왓다는 뜻
	{
		for (int i = 0; i < n / 3 + (n % 3 != 0); i++)
		{
			move('D');
			input();
			move('D');
			input();
			move('D');
			input();
			checkG();
			if (isGFind)break;
			for (int j = 0; j < n / 3 + (n % 3 != 0); j++)
			{
				move('R');
				input();
				move('R');
				input();
				move('R');
				input();
				checkG();
				if (isGFind)break;
			}
			if (isGFind)break;
		}
	}

	if (gx == -1)
	{
		move('L');
		input();
	}
	else if (gx == 1)
	{
		move('R');
		input();
	}
	if (gy == -1)
	{
		move('U');
		input();
	}
	else if (gy == 1)
	{
		move('D');
		input();
	}

	while(!moved.empty())
	{
		char c = moved.back();
		moved.pop_back();
		if (c == 'L')
		{
			cout << "? R" << endl;
			input();
		}
		if (c == 'R')
		{
			cout << "? L" << endl;
			input();
		}
		if (c == 'U')
		{
			cout << "? D" << endl;
			input();
		}
		if (c == 'D')
		{
			cout << "? U" << endl;
			input();
		}
	}
	cout << "!" << endl;

	return 0;
}
