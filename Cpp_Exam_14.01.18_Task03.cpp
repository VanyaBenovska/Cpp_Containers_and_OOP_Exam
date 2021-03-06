// Cpp_Exam_14.01.18_Task03.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

class Object
{
private:
	string name;
	int age;
	int weight;
	string place;
public:
	Object(string name = string(), int age = 0, int weight = 0, string place = "") :
		name(name), age(age), weight(weight), place(place) {}
	Object() { name = "", age = 0, weight = 0, place = ""; }

	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	int getWeight() {
		return this->weight;
	}
	string getPlace() {
		return this->place;
	}
	string getANameInfo() {
		ostringstream info;
		info << this->name;
		return info.str();
	}
	string getWeightInfo() {
		ostringstream info;
		info << this->weight;
		return info.str();
	}
	string getPlaceInfo() {
		ostringstream info;
		info << this->age;
		return info.str();
	}
	string getObjectInfo() {
		ostringstream info;
		info << "OBJECT NAME: " << this->name << ", OBJECT AGE: " << this->age << ", OBJECT WEIGHT: " << this->weight << ", OBJECT PLACE: " << this->place;
		return info.str();
	}
};


int main()
{
	cin.sync_with_stdio(false);

	vector<Object> dataObjests;

	vector<string> dataNames;
	vector<int> dataAges;
	vector<int> dataWeights;
	vector<string> dataPlaces;

	string line;
	getline(cin, line);
	string nextName, nextPlace, strNextAge, strNextWeight;
	int nextAge = 0, nextWeight = 0;
	int nameCounter = 0, ageCounter = 0, placeCounter = 0, weightCounter = 0;
	while (line != "[queries]")
	{
		//bool nameNotEntered = true, ageNotEnteres = true, placeNotEntered = true;		
		
		istringstream iss(line);
		while (iss)
		{
			string propertyName;
			iss >> propertyName;
			if (propertyName == "name")
			{
				string name;
				iss >> name;
				cout << "String NAME SIZE= " << name.size() << endl;
				if (name.size() > 0)  // HAVE to be if (name.size() > 0)
				{
					//nameNotEntered = false;
					
					nextName = name;
					dataNames.push_back(nextName);
					nameCounter++;
				}
				else                           //ИЗОБЩО НЕ ВЛИЗА В СКОУБА !!! 
				{
					//dataNames.push_back("");
					//dataNames.push_back(string());
					//dataNames.push_back("NULL");
					dataNames.push_back("*");
				}
			}
			else if (propertyName == "age")
			{
				iss >> strNextAge;
				cout << "String AGE SIZE= " << strNextAge.size() << endl;
				if (strNextAge.size() > 0)
				{
					//ageNotEnteres = false;
					
					nextAge = atoi(strNextAge.c_str());
					dataAges.push_back(nextAge);
					ageCounter++;
				}
				else
				{
					//dataAges.push_back(0);   //РАБОТИ !!!!
				}
				
			}
			else if (propertyName == "weight")
			{				
				iss >> strNextWeight;
				cout << "String WEIGHT SIZE= " << strNextWeight.size() << endl;
				if (strNextWeight.size() > 0)
				{
					//ageNotEnteres = false;

					nextWeight = atoi(strNextWeight.c_str());
					dataWeights.push_back(nextWeight);
					weightCounter++;
				}
				else
				{
					//dataAges.push_back(0);   //РАБОТИ !!!!
				}

			}
			else if (propertyName == "place")
			{
				string place;
				iss >> place;
				cout << "String PLACE SIZE= " << place.size() << endl;
				if (place.size() > 0)      
				{
					//placeNotEntered = false;
					nextPlace = place;
					dataPlaces.push_back(nextPlace);
					placeCounter++;
				}
				else                           //ИЗОБЩО НЕ ВЛИЗА В СКОУБА !!! 
				{
					//dataPlaces.push_back("");
					//dataPlaces.push_back(string());
					//dataPlaces.push_back("NULL");
					dataPlaces.push_back("*");
				}
			}			
		}
		if (nameCounter == 0)
		{
			dataNames.push_back("*");
			nextName = "";
		}
		if (ageCounter == 0)
		{
			dataAges.push_back(0);
			nextAge = 0;
			
		}
		if (weightCounter == 0)
		{
			dataWeights.push_back(0);
			nextWeight = 0;

		}
		if (placeCounter == 0)
		{
			dataPlaces.push_back("*");
			nextPlace = "";
			
		}

		Object object{ nextName, nextAge, nextWeight, nextPlace };
		dataObjests.push_back(object);

		getline(cin, line);
		nameCounter = 0;
		ageCounter = 0;
		weightCounter = 0;
		placeCounter = 0;
	}


	//CHECK OBJECTS
	cout << "----------OBJECTS: -----------" << endl;
	for (auto item : dataObjests)
	{
		cout << item.getObjectInfo() << endl;
	}
	cout << endl;
	//CHECK Names
	cout << "************   Names   ************" << endl;
	for (auto item : dataNames)
	{
		cout << item << ", ";
	}
	cout << " SIZE= " << dataNames.size() << endl;
	cout << endl;
	//CHECK Ages
	cout << "************   Ages   ************" << endl;
	for (auto item : dataAges)
	{
		cout << item << ", ";
	}
	cout << " SIZE= " << dataAges.size() << endl;
	cout << endl;
	//CHECK Weights
	cout << "************   Weights   ************" << endl;
	for (auto item : dataWeights)
	{
		cout << item << ", ";
	}
	cout << " SIZE= " << dataWeights.size() << endl;
	cout << endl;
	//CHECK Places
	cout << "************   Places   ************" << endl;
	for (auto item : dataPlaces)
	{
		cout << item << ", ";
	}
	cout << " SIZE= " << dataPlaces.size() << endl;
	cout << endl;
	cout << "------------------------------------- " << endl;

	string line2;	
	getline(cin, line2);
	while (line2 != "end")
	{
		istringstream iss2(line2);
		int quieryAge;
		string quieryField;
		iss2 >> quieryAge >> quieryField;
		int counterA = 0, counterB = 0, counterC = 0;
		for (int i = 0; i < dataAges.size(); i++)
		{
			if (dataAges[i] == quieryAge)
			{
				if (quieryField == "name")
				{
					if (dataNames[i] != "*")
					{
						cout << dataNames[i] << " ";
						counterA++;
					}
				}
				else if (quieryField == "weight") 
				{
					if (dataWeights[i] != 0)   
					{
						cout << dataWeights[i] << " ";
						counterB++;
					}
				}
				else if (quieryField == "place")
				{
					if (dataPlaces[i] != "*")
					{
						cout << dataPlaces[i] << " ";
						counterC++;
					}
				}
			}
		}
		if ( (quieryField == "name" && counterA == 0) ||
			(quieryField == "weight" && counterB == 0) ||
			(quieryField == "place" && counterC == 0) )
		{
			cout << "not found";
		}
		
		cout << endl;
		counterA = 0;
		counterB = 0;
		counterC = 0;
		getline(cin, line2);
	}
	return 0;
}

