#include "Aircraft.h"
#include "Array.h"

//constructor
Aircraft::Aircraft(const string& t, const string& r) {
	type = t;
	registration = r;
	flighthours = 0;
}

//destructor
Aircraft::~Aircraft() {
	
}

ostream& operator<<(ostream& out, const Aircraft& a){
	return out << "Aircraft:      " << a.type <<"\nRegistration:  "<< a.getRegistration() <<endl;
}

//getters
const string& Aircraft::getRegistration() const {
	return registration;
}

//other
void Aircraft::install(Part* p, Date& d) {
	partArray.add(p);
	p->install(d);
}
		
void Aircraft::takeFlight(int hours) {

	flighthours += hours;
	
	for (int i = 0; i < partArray.getSize(); i++) {
		partArray[i]->addFlightHours(hours);
	}
	
}
		
void Aircraft::inspectionReport(Date& d, Array<Part*>& a) {
	
	for (int i = 0; i < partArray.getSize(); i++) {
		if (partArray[i]->inspection(d)) {
			a.add(partArray[i]);
		}
	}
	
}
