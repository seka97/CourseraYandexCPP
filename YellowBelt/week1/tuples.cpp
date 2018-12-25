#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <map>
#include <set>

using namespace std;

class Cities
{
private:
	map<string, string> city_to_country;
	set<string> ambigious_cities;
public:
	tuple<bool, string> FindCountry(const string& city) const
	{
		if(city_to_country.count(city) == 1)
		{
			return {true, city_to_country.at(city)};
		}
		else if(ambigious_cities.count(city) == 1)
		{
			return {false, "Ambigious"};
		}
		else
		{
			return {false, "Not exist"};
		}
	}
};

int main()
{
	//tuple<int, string, bool> t(7, "C++", true);
	tuple t(7, "C++", true);
	//auto t = make_tuple(7, "C++", true);
	cout << get<1>(t) << endl;

	//pair<int, string> p(7, "C++");
	pair p(7, "C++");
	//auto p =make_pair(7, "C++");
	cout << p.first << " " << p.second << endl;

	map<int, string> digits = {{1, "first"}};
	for(const auto& item : digits)
	{
		cout << item.first << " " << item.second << endl;
	}
	for(const auto& [key, value] : digits)
	{
		cout << key << " " << value << endl;
	}

	Cities cities;
	auto country = cities.FindCountry("Kiyv");
	cout << get<1>(country) << endl;

	bool success;
	string message;
	tie(success, message) = cities.FindCountry("Kiyv");
	cout << success << " " << message << endl;

	auto [s, m] = cities.FindCountry("Kiyv");
	cout << s << " " << m << endl;


	return 0;
}
