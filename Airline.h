#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Part.h"
#include "Aircraft.h"

using namespace std;

class Airline {

	
	public:
		//constructor
		Airline(const string& n);
		
		//destructor
		~Airline();
		
		//other
		void addAircraft(const string& t, const string& r);
		void addPart(const string& part, int fh_inspect, int it_inspect);
		void takeFlight(string reg, int hours);
		
		void printAircraft() const;
		void printParts() const;
		void print() const;
		
		void inspectionReport(string reg, Date& d);
		bool install(string aircraftRegistration, string partName, Date& d);
	
	private:
		string name;
		Array<Part*> parts;
		Array<Aircraft*> aircrafts;
		
		//getters
		bool getPart(string n, Part** p) const;
		bool getAircraft(string r, Aircraft** a) const;
		
		


};
#endif
