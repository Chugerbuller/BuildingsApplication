#pragma once
#include <iostream>
#include "HomeStruct.h"

Owner InputOwner() {
	Owner owner;
	string part;
	bool flag = true;
	cout << "\nEnter owner name: "; cin >> owner.name;
	do {
		cout << "Enter " << owner.name << " part: "; cin >> part;
		for (char sym : part) {
			if (isdigit(sym) == 0) {
				cout << "Incorrect input, try again\n";
				break;
			}
			else {
				flag = false;
			}
		}
	} while (flag);

	owner.part = stoi(part);

	return owner;
}
Flat InputFlat() {
	Flat flat;
	vector<Owner> room_owners;

	cout << "\nEnter room number: "; cin >> flat.flat_num;

	bool exit = true;
	int part_check = 0;
	do
	{
		Owner owner;
		int input;

		cout << "\nOwners\n1)Add owner\n2)Exit\nEnter mode: "; cin >> input;
		switch (input)
		{
		case 1:
			owner = InputOwner();
			part_check += owner.part;
			room_owners.push_back(owner);

			break;
		case 2:
			if (part_check == 100) exit = false;
			else {
				room_owners.clear();
				room_owners.shrink_to_fit();
				part_check = 0;
				cout << "Incorrect input of owners, try again(\n";
			}
			break;
		default:
			cout << "Incorrect input\n";
			break;
		}

	} while (exit);

	for (Owner item : room_owners)
	{
		flat.AddOwner(item);
	}

	return flat;
}
Building InputBuilding() {
	Building build;
	bool exit = true;
	cout << "\nEnter number of house: "; cin >> build.building_number;
	cout << "\n\tHouse num." << build.building_number;

	do {
		int input;

		cout << "\nRooms\n1)Add room\n2)Exit\nEnter mode: "; cin >> input;
		Flat flat;
		switch (input)
		{
		case 1:
			flat = InputFlat();
			build.AddFlat(flat);
			break;
		case 2:
			exit = false;
			break;
		default:
			cout << "Incorrect input\n";
			break;
		}
	} while (exit);

	return build;
}
void OuputBuildData(Building build) {

	map<string, map<string, int>> building_data = build.BuildingData();

	for (auto it : building_data) {

		string room_name = it.first;
		auto owners_info = it.second;

		cout << "\n\t" << room_name << endl;

		for (auto it2 : owners_info) {

			auto owner_name = it2.first;
			auto owner_part = it2.second;

			cout << owner_name << ", part = " << owner_part << "%" << endl;
		}
	}
}
void ShowInfoAbHouses(vector<Building> houses) {
	bool exit_infhouse = true;
	int input_house;

	cout << "\n\tHouses list\n\n";
	for (size_t i = 0; i < houses.size(); i++)
	{
		cout << i + 1 << ")House num." << houses.at(i).building_number << endl;
	}
	cout << "\nEnter number of house: "; cin >> input_house;
	do {
		if (input_house <= houses.size())
		{
			cout << "\tHouse num." << input_house << endl;
			OuputBuildData(houses.at(input_house - 1));
			exit_infhouse = false;

		}
		else {

			cout << "Incorrect input, try again\n";

		}
	} while (exit_infhouse);
}
void SaveHousesData(vector<Building>* houses_origin, vector<Building>* houses_data) {
	for (size_t i = 0; i < houses_origin->size(); i++)
	{
		houses_data->push_back(houses_origin->at(i));
	}
}
void BuildingsApp(vector<Building>* houses_data) {
	int input;
	bool exit = true;
	map<string, map<string, int>> building_data;
	vector<Building> houses;

	cout << "\n\tHouse application\n";
	do {
		cout << "\n1)Add house\n2)Show information about house\n3)Save in vec\n4)Exit\nEnter mode: "; cin >> input;

		switch (input)
		{
		case 1:

			houses.push_back(InputBuilding());
			break;

		case 2:
			ShowInfoAbHouses(houses);
			break;

		case 3:

			SaveHousesData(&houses, houses_data);
			break;

		case 4:

			exit = false;
			break;

		default:
			cout << "Incorrect input\n";
			break;
		}
	} while (exit);

}
