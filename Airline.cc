#include <iostream>
using namespace std;
#include <string>

#include "Airline.h"

//constructor
Airline::Airline(const string& n) {
	name = n;
}

//destructor
Airline::~Airline() {
	
	//delete all (dynamic) parts
	for (int i = 0; i < parts.getSize(); i++) {
		delete parts[i];
	}
	
	//delete all (dynamic) aircrafts
	for (int i = 0; i < aircrafts.getSize(); i++) {
		delete aircrafts[i];
	}
	
}

//getters
bool Airline::getPart(string n, Part** p) const {

	for (int i = 0; i < parts.getSize(); i++) {
		if (parts[i]->getName() == n) {
			*p = parts[i];
			return true;
		}
	}
	
	cout << "Error: Could not get the part." << endl;
	*p = NULL;
	return false;

}

bool Airline::getAircraft(string r, Aircraft** a) const {

	for (int i = 0; i < aircrafts.getSize(); i++) {
		if (aircrafts[i]->getRegistration() == r) {
			*a = aircrafts[i];
			return true;
		}
	}
	
	cout << "Error: Could not get the aircraft." << endl;
	*a = NULL;
	return false;

}

//other
void Airline::addAircraft(const string& t, const string& r) {
	Aircraft* a = new Aircraft(t,r);
	aircrafts.add(a);
}

void Airline::addPart(const string& part, int fh_inspect, int it_inspect) {

	if (fh_inspect == 0) {
		IT_Part* p = new IT_Part(part, it_inspect);
		parts.add(p);
	}
	else if (it_inspect == 0) {
		FH_Part* p = new FH_Part(part, fh_inspect);
		parts.add(p);
	}
	else {
		FHIT_Part* p = new FHIT_Part(part, fh_inspect, it_inspect);
		parts.add(p);
	} 

}

void Airline::takeFlight(string reg, int hours) {

	Aircraft *a;

	if (getAircraft(reg, &a)) {
		a->takeFlight(hours);
	}
	else {
		cout << "Error: Could not take flight." << endl;
	}

}

void Airline::printAircraft() const {

	for (int i = 0; i < aircrafts.getSize(); i++) {
		cout << *aircrafts[i] << endl;
	}
	
}
		
void Airline::printParts() const {
	
	for (int i = 0; i < parts.getSize(); i++) {
		cout << *parts[i] << endl;
	}
	
}

void Airline::print() const {

	cout << "Airline: " << name << endl;
	
	cout << "Printing Aircrafts: " << endl;
	printAircraft();
	
	cout << "Printing Parts: " << endl;
	printParts();


}

void Airline::inspectionReport(string reg, Date& d) {
	
	Aircraft *a;

	if (getAircraft(reg, &a)) {
		cout << "The following parts from " << reg << " require inspection:" << endl; //don't need to use getRegistration here.
		Array<Part*> p;
		a->inspectionReport(d, p);
		
		for (int i = 0; i < p.getSize(); i++) {
			cout << *p[i] << endl;
		}
		
		cout << endl; //add a little more space.
		
	}
	else {
		cout << "Error: Could not take make inspection report." << endl;
	}
	
	
}
		
bool Airline::install(string aircraftRegistration, string partName, Date& d) {
	
	Aircraft *a;
	Part *p;
	
	if (getAircraft(aircraftRegistration, &a) && getPart(partName, &p)) {
		a->install(p, d);
		return true;
	}
	
	cout << "Error: Could not install part onto aircraft." << endl;
	
	return false;
}
		
