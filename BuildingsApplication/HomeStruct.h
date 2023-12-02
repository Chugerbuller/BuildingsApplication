#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;
struct Owner {

	string name;
	int part;

	void InitOwner(string name, int part) {
		this->name = name;
		this->part = part;
	}
};

struct Flat
{
	string flat_num;
	vector<Owner> owners_info;
	void AddOwner(Owner owner) {
		owners_info.push_back(owner);
	}
	void InitFlat(string flat_num) {
		this->flat_num = flat_num;
	}

	map<string, int> FlatData(){
		map<string, int> flat_data;
		for (size_t i = 0; i < this->owners_info.size(); i++)
		{
			flat_data.emplace(this->owners_info.at(i).name, this->owners_info.at(i).part);
		}
		return flat_data;
	}
};
struct Building
{
	string building_number;

	vector<Flat> rooms;
	void AddFlat(Flat flat) {
		rooms.push_back(flat);
	}

	map<string, map<string, int>> BuildingData() {
		map<string, map<string, int>> building_data;
		
		for (size_t i = 0; i < this->rooms.size(); i++)
		{
			building_data.emplace(rooms.at(i).flat_num, rooms.at(i).FlatData());
		}

		return building_data;
	}
};