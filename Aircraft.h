#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Part.h"
#include "Array.h"

using namespace std;

class Aircraft {

	friend ostream& operator<<(ostream& out, const Aircraft&);

	public:
	
		//constructor
		Aircraft(const string& t, const string& r);
		
		//destructor
		~Aircraft();
		
		//getters
		const string& getRegistration() const;
		
		//other
		void install(Part* p, Date& d);
		void takeFlight(int hours);
		void inspectionReport(Date& d, Array<Part*>& a);
	
	
	private:
		string type;
		string registration;
		int flighthours;
		Array<Part*> partArray;


};
#endif
