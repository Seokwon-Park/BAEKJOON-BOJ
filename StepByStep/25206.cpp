#include <bits/stdc++.h>

using namespace std;

double gradeToNum(string grade)
{
	double ret = 0.0;
	for (auto ch : grade)
	{
		switch (ch)
		{
		case 'A':
			ret = 4.0;
			break;
		case 'B':
			ret = 3.0;
			break;
		case 'C':
			ret = 2.0;
			break;
		case'D':
			ret = 1.0;
			break;
		case 'F':
			ret = 0.0;
			break;
		case '+':
			ret += 0.5;
			break;
		default:
			break;		
		}		
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string subject;
	double score;
	string grade;

	double sum1 = 0;
	double sum2 = 0;

	for (int i = 0; i < 20; i++)
	{
		cin >> subject >> score >> grade;
		if (grade == "P") continue;
		else
		{
			sum1 += score * gradeToNum(grade);
			sum2 += score;			
		}
	}

	cout << sum1 / sum2;

	return 0;
}
