#include <bits/stdc++.h>

using namespace std;

int alpha[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int len = str.length();
	deque<char> dq;

	for (auto c : str)
	{
		alpha[c - 'A']++;
	}

	int oddalpha = 0; // 홀수인 알파벳 수
	char center;
	for (int i = 0; i< 26; i++)
	{
		if (alpha[i] % 2 == 1)
		{
			center = 'A' + i;
			oddalpha += 1;
		}
		if (oddalpha > 1)
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}

	if (oddalpha == 1)
	{
		dq.push_back(center);
		alpha[center - 'A']--;
	}
	for (int i = 25; i >= 0; i--)
	{
		while (alpha[i] > 0)
		{
			dq.push_back('A' + i);
			dq.push_front('A' + i);
			alpha[i] -= 2;
		}
	}

	for (auto d : dq)
	{
		cout << d;
	}


	return 0;
}