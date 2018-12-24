template<typename T> T Sqr(T i);
template<typename T> vector<T> Sqr(vector<T>& v);
template<typename Key, typename Value> map<Key, Value> Sqr(map<Key, Value>& m);
template<typename First, typename Second> pair<First, Second> Sqr(pair<First, Second>& p);

template <typename T>
T Sqr(T i) {
	return i*i;
}

template <typename T>
vector<T> Sqr(vector<T>& v) {
	vector<T> tmp;
	for(size_t i = 0; i < v.size(); i++) {
		tmp.push_back(Sqr(v[i]));
	}
	return tmp;
}

template <typename Key, typename Value>
map<Key, Value> Sqr(map<Key, Value>& m) {
	map<Key, Value> tmp;
	for(auto& p : m) {
		tmp[p.first] = Sqr(p.second);
	}
	return tmp;
}

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second>& p) {
	pair<First, Second> tmp;
	tmp.first = Sqr(p.first);
	tmp.second = Sqr(p.second);
	return tmp;
}