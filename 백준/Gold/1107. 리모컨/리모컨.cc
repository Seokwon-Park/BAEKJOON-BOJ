#include <bits/stdc++.h>

using namespace std;

int n, m;
int len = 1;
string num;
vector<bool> can_use(10, true);
int min_move;

void func(int l)
{
	if (len >1 && l == len-1)
	{
		int number = stoi(num);

		int diff = 0;

		diff = abs(number - n);

		int moved = l + diff;
		if (moved < min_move)
		{
			min_move = moved;
		}
	}
	if (l == len)
	{
		int number = stoi(num);
		int diff = 0;

		diff = abs(number - n);

		int moved = l + diff;
		if (moved < min_move)
		{
			min_move = moved;
		}
	}
	if (l == len+1)
	{
		int number = stoi(num);
		int diff = 0;

		diff = abs(number - n);

		int moved = l + diff;
		if (moved < min_move)
		{
			min_move = moved;
		}
		return;
	}
	

	for (int i = 0; i < 10; i++)
	{
		if (!can_use[i]) continue;
		num.push_back(i + '0');
		func(l + 1);
		num.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	min_move = abs(n-100);

	while (m--)
	{
		int num;
		cin >> num;
		can_use[num] = false;
	}

	if (n == 100)
	{
		cout << 0;
		return 0;
	}

	int ncopy = n;

	while (ncopy >= 10)
	{
		ncopy /= 10;
		len++;
	} 
	
	func(0);

	cout << min_move;

	return 0;
}
