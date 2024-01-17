// 검색해서 접근방법 알아내고 풀었음.
#include <bits/stdc++.h>

using namespace std;

int board[15][15];
int psize;
vector<int> b; // x, y
vector<int> w; // x, y
bool isused1[105]; // 대각 확인
bool isused2[105]; // 대각 대칭 확인
int cnt;
int answer[2] = { INT_MIN, INT_MIN };
int n;

void func(int x, int y, int type) //시작 위치, 탐색한 칸의 수, 0 black, 1 white 라고 하고.
{
	if (x >= n)
	{
		y++; //다음 줄로
		if (y % 2 == 0) // 다음 줄이 만약 짝수줄이면 black의 x=0이어야 되고 white는 x=1이어야 함.
			x = (type % 2 == 0) ? 0 : 1;
		else // 다음줄이 홀수인 경우 서로 반대로
			x = (type % 2 == 0) ? 1 : 0;
	}
	if (y == n) // 다 탐색했으면 각 체스판의 색에 대해 최댓값 갱신해준다.
	{
		answer[type] = max(cnt, answer[type]);
		return;
	}
	if (isused1[x + y] || isused2[x - y + n - 1] || board[y][x] == 0) // 못넣는 경우는 무조건 다음칸으로 넘김
	{
		func(x + 2, y, type);// 그냥 다음칸으로
		return;
	}	
	//놓을 수 있는 경우 (놓아도 되고 안놓고 다음칸으로 가볼 수도 있다)
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			func(x + 2, y, type);// 그냥 다음칸으로
		}
		else
		{
			cnt++;
			isused1[x + y] = true;
			isused2[x - y + n - 1] = true;
			func(x + 2, y, type);
			isused1[x + y] = false;
			isused2[x - y + n - 1] = false;
			cnt--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	func(0, 0, 0);
	func(1, 0, 1);

	cout << answer[0] + answer[1];

	return 0;
}