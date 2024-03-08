#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	long long dec = 1;
	long long range = 0;
	long long pow = 1;
	while (n >= dec * 10 - 1)
	{
		range += (dec * 10 - dec)*pow;
		dec *= 10;
		pow++;
	}
	range += (n - dec + 1) * pow;
	
	if (range < k)
	{
		cout << -1;
		return 0;
	}
	
	int nine = 9;
	int sum = 9;
	int tmp = k;
	pow = 1;
	while (k > sum)
	{
		tmp -= nine * pow;
		pow++;
		nine = nine* 10;
		sum = sum + nine * pow;
	}
	long long order = (tmp-1) / pow;
	long long st = 1;


	for (int i = 0; i < pow-1; i++)
		st *= 10;
	for (int i = 0; i < order; i++)
	{
		st++;
	}
	
	//cout << st<< '\n';
	cout << to_string(st)[(tmp - 1) % pow];


	return 0;
}