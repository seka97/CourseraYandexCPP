#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string query;
	cin >> query;
	if (query == "NEW_BUS") {
		cin >> q.bus;
		q.type = QueryType::NewBus;
		int stop_count;
		cin >> stop_count;
		q.stops.resize(static_cast<unsigned>(stop_count));
		for (int i = 0; i < stop_count; i++) {
			cin >> q.stops[i];
		}
	} else if(query == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		cin >> q.stop;
	} else if(query == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		cin >> q.bus;
	} else if(query == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}

	return is;
}

struct BusesForStopResponse {
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses.size() == 0) {
		cout << "No stop";
	} else {
		for (const string& bus : r.buses) {
			cout << bus << " ";
		}
	}
	cout << endl;
	return os;
}

struct StopsForBusResponse {
	map<string, vector<string>> stops_to_buses;

};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if(r.stops_to_buses.size() == 0) {
		cout << "No bus" << endl;
	} else {
		for(const auto& stop_item : r.stops_to_buses) {
			cout << "Stop " << stop_item.first << ": ";
			if(stop_item.second.size() == 0) {
				cout << "no interchange";
			} else {
				for (const string& other_bus : stop_item.second) {
					cout << other_bus << " ";
				}
			}
			cout << endl;
		}
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if(r.buses_to_stops.size() == 0) {
		cout << "No buses";
	} else {
		for (const auto& bus_item : r.buses_to_stops) {
			cout << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				cout << stop << " ";
			}
		}
	}
	cout << endl;
	return os;
}
class BusManager {
private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;

		for (const auto& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse r;
		r.buses.resize(0);
		if(stops_to_buses.count(stop) != 0) {
			r.buses = stops_to_buses.at(stop);
		}
		return r;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse r;
		r.stops_to_buses = stops_to_buses;
		return r;
	}

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse r;
		r.buses_to_stops = buses_to_stops;
		return r;
	}
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
		case QueryType::NewBus:
			bm.AddBus(q.bus, q.stops);
			break;
		case QueryType::BusesForStop:
			cout << bm.GetBusesForStop(q.stop) << endl;
			break;
		case QueryType::StopsForBus:
			cout << bm.GetStopsForBus(q.bus) << endl;
			break;
		case QueryType::AllBuses:
			cout << bm.GetAllBuses() << endl;
			break;
		}
	}

	return 0;
}
