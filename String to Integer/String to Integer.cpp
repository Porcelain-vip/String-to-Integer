#include<iostream>
#include<string>
#include<climits>

int Convert(const std::string& str)
{
	int sign = 1, i = 0, result = 0;
	const size_t SIZE = str.size();

	while (str[i] == ' ') ++i;
	if (str[i] == '+') ++i;
	else if (str[i] == '-') { sign = -1; ++i; }

	for (; i != SIZE; ++i)
	{
		if (str[i] < '0' || str[i] > '9') { std::cout << "This string has illegal characters." << std::endl; break; }
		if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			return sign == -1 ? INT_MIN : INT_MAX;
		result = result * 10 + str[i] - '0';
	}
	return sign*result;
}

int main()
{
	std::string str = "           +2147483648";
	int num = Convert(str);
	std::cout << "After converting: " << num << std::endl;
	return 0;
}