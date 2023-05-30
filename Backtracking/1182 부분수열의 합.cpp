#include <bits/stdc++.h>

using namespace std;

int arr[30];
int n, s;
int answer;

void func(int k, int sum)
{
	if (k == n)
	{
		if (sum == s)
		{
			answer++;
		}
		return;
	}
	func(k + 1, sum);// not select
	func(k + 1, sum + arr[k]);// select arr[k];

}

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) --answer; // s=0 -> 공집합제외해야함.
	cout << answer;
	

	return 0;
}
