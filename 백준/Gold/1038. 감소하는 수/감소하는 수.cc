#include<bits/stdc++.h>
using namespace std;

vector<long long> arr;
int n;


void func(long long cur, int target, long long num)
{
	if (cur == target)
	{

		arr.push_back(num);
		return;
	}

	if (cur == 0)
	{
		for (int i = 1; i < 10; i++)
		{
			num = i;
			func(cur + 1, target, num);
		}
	}
	else
	{
		int prev = num % 10;
		for (int i = 0; i < prev; i++)
		{
			num *= 10;
			num += i;
			func(cur + 1, target, num);
			num -= i;
			num /= 10;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	if (n < 10)
	{
		cout << n;
		return 0;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			arr.push_back(i);
		}
		for (int i = 2; i < 11; i++)
		{

			func(0, i, 0);
		}
	}
	if (n > arr.size()-1)
	{
		cout << -1;
	}
	else
	{
		cout << arr[n];
	}


	return 0;
}