#include "Person.h"

Person::Person(string name, double mass, double height, double bmi)
{
	this->name = name;
	this->mass = mass;
	this->height = height;
	this->bmi = bmi;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setMass(double mass)
{
	this->mass = mass;
}

void Person::setHeight(double height)
{
	this->height = height;
}

void Person::setBMI(double bmi)
{
	this->bmi = bmi;
}

string Person::getName()
{
	return name;
}

double Person::getMass()
{
	return mass;
}

double Person::getHeight()
{
	return height;
}

double Person::getBMI()
{
	return bmi;
}
