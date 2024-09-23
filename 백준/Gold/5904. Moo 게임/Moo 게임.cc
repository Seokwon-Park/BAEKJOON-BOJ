#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int n;

//m o o m o o o m o o m  o  o  o  o  m  oomooomoo
//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15                

char S(int prevlen, int k, int len)
{
	if (n+1 > len)
	{
		return S(len, k + 1, len * 2 + k + 4);
	}
	else
	{
		n -= prevlen;
		if (n < k + 3)
		{
			if (n == 0)
				return 'm';
			else
				return 'o';
		}
		else
		{
			n -= k + 3;
			return S(0, 0, 3);
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	n--;

 	cout << S(0, 0, 3);

	return 0;
}

