template<typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
	if(m.find(k) == m.end()) {
		throw runtime_error("Runtime error");
	}
	return m[k];
}