#ifndef PART_H
#define PART_H

#include <iostream>
using namespace std;
#include "Date.h"

class Part {

	friend ostream& operator<<(ostream& out, const Part&);

	public:
		//constructor
		Part(const string& n);
		//destructor
		virtual ~Part();
		
		//getters
		const string& getName() const;
		
		//other
		void addFlightHours(int);
		void install(Date&);
		
		virtual bool inspection(const Date& d) const = 0;
		virtual void printPart(ostream& out) const = 0;
	
	protected:
		string name;
		Date installationDate;
		int flighthours;

};

class FH_Part: virtual public Part {

	public:
		//constructor
		FH_Part(const string& n, int fh_i);
		//destructor
		virtual ~FH_Part();
		
		//other
		virtual bool inspection(const Date& d) const;
		virtual void printPart(ostream& out) const;
	
	protected:
		int fh_inspect;

};

class IT_Part: virtual public Part {

	public:
		//constructor
		IT_Part(const string& n, int it_i);
		//destructor
		virtual ~IT_Part();
		
		//other
		virtual bool inspection(const Date& d) const;
		virtual void printPart(ostream& out) const;
	
	protected:
		int it_inspect;

};

class FHIT_Part: public IT_Part, FH_Part {

	public:
		//constructor
		FHIT_Part(const string& n, int fh_i, int it_i); 
		//destructor
		virtual ~FHIT_Part();
		
		//other
		virtual bool inspection(const Date& d) const;
		virtual void printPart(ostream& out) const;

};

#endif
