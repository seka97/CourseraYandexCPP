#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
using namespace std;

//int Sqr(int x) {
//	return x*x;
//}
//
//double Sqr(double x) {
//	return x*x;
//}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second> p1, const pair<First, Second> p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return make_pair(f,s);
}

template <typename T>
T Sqr(T x) {
	return x*x;
}

//ostream& operator<<(ostream& out, const vector<int>& v) {
//	for(const auto& i : v) {
//		out << i << " ";
//	}
//	return out;
//}


template <typename Collection>
string Join(Collection c, char d) {
	stringstream ss;
	bool first = true;
	for(const auto& i : c) {
		if(!first) {
			ss << d;
		}
		first = false;
		ss << i;
	}
	return ss.str();
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	//	for(const auto& i : v) {
	//		out << i << " ";
	//	}
	//	return out
	return out << "[" << Join(v, ',') << "]";
}

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) {
	//	for(const auto& i : v) {
	//		out << i;
	//	}
	//	return out;

	return out << "{" << Join(m, ',') << "}";
}

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
	return out<< "(" << p.first << ", " << p.second<< ")";
}

//template <typename T>
//T Max(T a, T b) {
//	if(b< a) {
//		return a;
//	}
//	return b;
//}

int main() {
	cout << Sqr(2) << endl;

	auto p = make_pair(2.5, 3);
	auto res = Sqr(p);
	cout << res.first << " " << res.second << endl;

	vector<double> v = {2,3,4};
	cout << v << endl;

	map<int, int> m = {{1, 2}, {3, 4}};
	cout << m << endl;

	vector<vector<int>> vv = {{5, 6}, {3, 4}};
	cout << vv << endl;

	//	cout << Max<double>(2, 3.5) << endl;
	//	cout << Max<int>(2, 3.5) << endl;
	cout << max<double>(2, 3.5) << endl;
	cout << max<int>(2, 3.5) << endl;
	return 0;
}
