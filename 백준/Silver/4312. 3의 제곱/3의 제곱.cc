#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;
const ll base = 1e9;

class BigInteger
{
public:
	BigInteger() { value.push_back(0); }
	BigInteger(string s)
	{
		int blockcnt = s.size() / 9 + (s.size() % 9 != 0);
		s = string(blockcnt * 9 - s.size(), '0') + s;
		for (int i = 0; i < s.size(); i += 9)
		{
			value.push_back(stoi(s.substr(s.size() - 9 * (i + 1), 9)));
		}
	}

	BigInteger(ll n)
	{
		value.push_back(n % base);
		if (n >= base)
		{
			value.push_back(n / base);
		}
	}

	BigInteger operator+(const BigInteger& other) const
	{
		BigInteger result;
		result.value.clear();

		long long carry = 0;
		int i = 0, j = 0;

		while (i < this->value.size() || j < other.value.size() || carry)
		{
			long long sum = carry;
			if (i < this->value.size())
			{
				sum += this->value[i++];
			}
			if (j < other.value.size())
			{
				sum += other.value[j++];
			}
			result.value.push_back(sum % base);
			carry = sum / base;
		}
		return result;
	}

	BigInteger operator-(const BigInteger& other) const
	{
		if (*this < other) {
			return BigInteger();
		}

		BigInteger result;
		result.value.clear();
		ll borrow = 0;

		for (int i = 0; i < value.size(); i++)
		{
			ll diff = value[i] - borrow;
			borrow = 0;

			if (i < other.value.size())
			{
				diff -= other.value[i];
			}

			// 뺐더니 음수가 되면 윗 자릿수에서 빌려옴
			if (diff < 0) {
				diff += base; // BASE(1억)를 더해줌
				borrow = 1;   // 다음 자릿수에서 1을 빌렸다고 표시
			}
			result.value.push_back(diff);
		}

		// 결과 맨 앞에 있는 불필요한 0들을 제거
		// 예: 12345678 - 12345600 = 00000078 -> 78
		result.RemoveLeadingZero();

		return result;
	}


	BigInteger operator*(const BigInteger& other) const
	{
		BigInteger result;
		result.value.clear();
		result.value.resize(value.size() + other.value.size(), 0);
		for (int i = 0; i < value.size(); i++)
		{
			for (int j = 0; j < other.value.size(); j++)
			{
				result.value[i + j] += value[i] * other.value[j];
			}
		}

		for (int i = 0; i < result.value.size() - 1; i++)
		{
			result.value[i + 1] += result.value[i] / base;
			result.value[i] %= base;
		}

		result.RemoveLeadingZero();

		return result;
	}

	bool operator<(const BigInteger& other) const
	{
		if (value.size() == other.value.size())
		{
			for (int i = 0; i < other.value.size(); i++)
			{
				if (value[i] == other.value[i])continue;
				return value[i] < other.value[i];
			}
		}
		return value.size() < other.value.size();
	}

	bool operator>(const BigInteger& other) const { return other < *this; }
	bool operator==(const BigInteger& other) const { return value == other.value; }

	string ToString() const
	{
		if (value.empty() || (value.size() == 1 && value[0] == 0))
		{
			return "0";
		}

		stringstream ss;
		// 가장 높은 자릿수(가장 마지막 원소)는 그대로 출력
		ss << value.back();

		for (int i = value.size()-2; i >=0; i--)
		{
			ss << setw(9) << setfill('0') << value[i];
		}
		return ss.str();
	}

private:
	void RemoveLeadingZero()
	{
		while (value.size() > 1 && value.back() == 0)
		{
			value.pop_back();
		}
	}

	vector<ll> value;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ull n;
	while (cin >> n)
	{
		if (n == 0) break;
		ull tmp = n - 1;
		BigInteger exp = 1;
		vector<BigInteger> ans;
		while (tmp)
		{
			if (tmp % 2)
			{
				ans.push_back(exp);
			}
			exp = exp * BigInteger(3);
			tmp /= 2;
		}

		cout << "{";
		for (auto itr = ans.begin(); itr != ans.end(); itr++)
		{
			if (itr + 1 != ans.end())
			{
				cout << " " << (*itr).ToString() << ",";
			}
			else
			{
				cout << " " << (*itr).ToString();
			}

		}
		cout << " }\n";
	}

	return 0;
}