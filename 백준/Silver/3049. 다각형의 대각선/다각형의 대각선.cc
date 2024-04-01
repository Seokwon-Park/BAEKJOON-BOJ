#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	// nC4 가 정답이된다.
	// n각형에서 점 4개를 골라서 사각형을 만든다고 치면 이 교점은 무조건 1개이다.
	// 조합으로 뽑아내면 고른 점 4개로 유일한 사각형을 몇개 만들 수 있는지 구할 수 있다.
	if (n == 3) cout << 0;
	else
	{
		int a = 1;
		int b = 1;
		for (int i = 0; i < 4; i++)
		{
			a *= n - i;
			b *= (i + 1);
		}
		cout << a / b;
	}

	return 0;
}