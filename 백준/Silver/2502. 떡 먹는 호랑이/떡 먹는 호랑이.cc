#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

ll fibo[30];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	fibo[0] = 1;
	fibo[1] = 1;
	for(int i = 2; i<= 30; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	int d, k;
	cin >> d >> k;

	int a = 1;
	int b;
	
	while (1)
	{
		if ((k - fibo[d - 3] * a) % fibo[d - 2] == 0)
		{
			b = (k - fibo[d - 3] * a) / fibo[d - 2];
			if(a <= b)break;
		}
		a++;
	}
	cout << a << '\n' << b;
	

	return 0;
}