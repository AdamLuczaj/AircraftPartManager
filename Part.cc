#include <iostream>
using namespace std;
#include <string>

#include "Part.h"

//constructor
Part::Part(const string& n) : name(n) {
	flighthours = 0;
}

//destructor
Part::~Part() {

}

//getters
const string& Part::getName() const {
	return name;
}

//other
void Part::addFlightHours(int f) {
	flighthours += f;
}

void Part::install(Date& d) {
	installationDate = d;
}

ostream& operator<<(ostream& out, const Part& p){
	
	out << "Part:              " << p.getName() << " \nFlight hours:      " << p.flighthours << " \nInstallation Date: " << p.installationDate;
	p.printPart(out);
	
	return out;
	
}

//constructor
FH_Part::FH_Part(const string& n, int fh_i): Part(n) {
	fh_inspect = fh_i;
}

//destructor
FH_Part::~FH_Part() {

}

//other
bool FH_Part::inspection(const Date& d) const {
	if (flighthours >= fh_inspect) return true;
	return false;
}

void FH_Part::printPart(ostream& out) const {

	//Print statement for a FH_Part

	out << "Inspect Every:     " << fh_inspect << " flight hours" << endl;
}

//constructor
IT_Part::IT_Part(const string& n, int it_i): Part(n) {
	it_inspect = it_i;
}

//destructor
IT_Part::~IT_Part() {

}

//other
bool IT_Part::inspection(const Date& d) const {
	//compare the days.
	if ((d.toDays() - installationDate.toDays()) >= it_inspect) return true;
	return false;
}

void IT_Part::printPart(ostream& out) const {

	//Print statement for a IT_Part

	out << "Inspect Every:     " << it_inspect << " days installed" << endl;
}

//constructor
FHIT_Part::FHIT_Part(const string& n, int fh_i, int it_i): Part(n), FH_Part(n,fh_i), IT_Part(n,it_i) {

}

//destructor
FHIT_Part::~FHIT_Part() {

}

//other
void FHIT_Part::printPart(ostream& out) const {

	//Print statement for a FHIT_Part

	out << "Inspect Every:     " << fh_inspect << " flight hours" << "\nInspect Every:     " << it_inspect << " days installed" << endl;
}


bool FHIT_Part::inspection(const Date& d) const {
	if (FH_Part::inspection(d) == true || IT_Part::inspection(d) == true) return true;
	return false;
}
