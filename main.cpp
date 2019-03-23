#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int END = 0;
const int SEEN = -1;

int length(int n)
{
	for (int i = 0; ; i++)
	{
		int r = n / pow(10, i);
		if (r == 0)
			return i;
	}
}

vector<int> split_number_to_digits(int number)
{
	vector<int> result;
	while (number)
	{
		result.push_back(number % 10);
		number /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

bool has_invalid_digits(vector<int> number_digits)
{
	if (number_digits.size() > 9)
		return true;
	for (int i = 0; i < number_digits.size(); i++)
		if (!number_digits[i])
			return true;
	return false;
}

bool is_circular(int number)
{
	vector<int> number_digits = split_number_to_digits(number);
	if (has_invalid_digits(number_digits))
		return false;

	int cu = number_digits[0];
	number_digits[0] = END;
	int i = 1;
	int len = length(number);
	int t = len;
	while (t != 0)
	{
		i = (cu + i) % len;
		if (i == 0)
			i = len;
		cu = number_digits[i - 1];
		if (cu == SEEN)
			break;
		number_digits[i - 1] = SEEN;
		t--;
	}
	return cu == END;
}

void print_result(int case_number, bool result)
{
	cout << "Case " << case_number << ": ";
	if (result)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}

int main()
{
	for (int case_number = 1; ; case_number++)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		bool result = is_circular(n);
		print_result(case_number, result);
	}
	return 0;
}
