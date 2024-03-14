#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string v;
	cin >> v;
	bool isUB = false;
	bool isCap = false;

	if (*(v.end() - 1) == '_')
	{
		cout << "Error!";
		return 0;
	}
	else if (*v.begin() == '_')
	{
		cout << "Error!";
		return 0;
	}
	else if ('A' <= *v.begin() && 'Z' >= *v.begin())
	{
		cout << "Error!";
		return 0;
	}

	vector<string> words;
	string tmp = "";
	for (auto c : v)
	{
		if (c == '_')
		{
			if (tmp.empty())
			{
				cout << "Error!";
				return 0;
			}
			words.push_back(tmp);
			isUB = true;
			tmp = "";
		}
		else if (c >= 'A' && c <= 'Z')
		{
			words.push_back(tmp);
			isCap = true;
			tmp = c;
		}
		else
		{
			tmp += c;
		}
		if (isUB && isCap)
		{
			cout << "Error!";
			return 0;
		}
	}
	if (!tmp.empty())
	{
		words.push_back(tmp);
	}

	string ans;
	cout << words[0];
	if (isUB)
	{
		for (int i = 1; i < words.size(); i++)
		{
			words[i][0] = words[i][0] - 'a' + 'A';
			cout << words[i];
		}
	}
	else if (isCap)
	{
		for (int i = 1; i < words.size(); i++)
		{
			cout << '_';
			words[i][0] = words[i][0] - 'A' + 'a';
			cout << words[i];
		}
	}


	return 0;
}