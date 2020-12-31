#pragma once
#include <string>
#include <string>

using namespace std;


class Person
{

private:
	string name;
	double mass;
	double height;
	double bmi;

public:
	Person(string name, double mass, double height, double bmi);
	void setName(string name);
	void setMass(double mass);
	void setHeight(double height);
	void setBMI(double bmi);
	string getName();
	double getMass();
	double getHeight();
	double getBMI();
};

