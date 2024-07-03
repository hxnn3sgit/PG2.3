#include <iostream>
#include <string>
#include <vector>

//using std::cout, std::endl, std::string, std::ostream;
using namespace std;

class tier {
protected:
	std::string name;
	int beine;
public:
	tier() : name(""), beine(0) {}
	tier(const std::string &name, int beine) : name(name), beine(beine) { cout << __PRETTY_FUNCTION__ << endl; }
	virtual void print_name() { cout << "'" << name << "'" << endl; }
	virtual void print_beine() { cout << beine << endl; }
	virtual ~tier() = default;
	friend std::ostream& operator<<(std::ostream &out, const tier &other) {
		return out <<"tier " << other.name << " hat " << other.beine << " Beine.";
	}
};

class säugetier : public tier {
private:
	
public:
	säugetier(const std::string &name, int beine) : tier(name, beine) { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~säugetier() = default;
	friend std::ostream& operator<<(std::ostream &out, const säugetier &other){
		return out << "säugetier " << other.name << " hat " << other.beine << " beine.";
	}
	virtual void print_name() override { cout << __PRETTY_FUNCTION__ << endl << name << endl; }
	virtual void print_beine() override { cout << __PRETTY_FUNCTION__ << endl << beine << endl; }
};

class insekt : public tier {
public:
	insekt(const string &name, int beine) : tier(name, beine) { cout << __PRETTY_FUNCTION__ << endl;}
	virtual ~insekt() = default;
	virtual void print_name() override { cout << __PRETTY_FUNCTION__ << endl << name << endl; }
	virtual void print_beine() override { cout << __PRETTY_FUNCTION__ << endl << beine << endl; }
	friend ostream& operator<<(ostream &out, const insekt &other) {
		return out << other.name << " ist insekt und hat " << other.beine << " Beine.\n";
	}
};


class pferd : public säugetier {
private:
	string pferd_rasse;
public:
	pferd(const string &name, int beine, const string& pferd_rasse) : säugetier(name, beine), pferd_rasse(pferd_rasse) { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~pferd() = default;
	void print_name() override { cout << __PRETTY_FUNCTION__ << endl << "säugetier" << name << endl; }
	void print_beine() override { cout << __PRETTY_FUNCTION__ << endl << "säugetier" << beine << endl; }
	void print_rasse() { cout << pferd_rasse << endl; }
	friend ostream& operator<<(ostream &out, const pferd &other) {
		return out << other.name << " ist Pferd von Rasse: " << other.pferd_rasse << "  und hat " << other.beine << " Beine.\n";
	}
};

class ameise : public insekt {
private:
	string ameisen_art;
public:
	ameise(const string &name, int beine, const string &ameisen_art) : insekt(name, beine), ameisen_art(ameisen_art) { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~ameise() = default;
	void print_name() override { cout << __PRETTY_FUNCTION__ << endl << "ameise heißt " << name << endl; }
	void print_beine() override { cout << __PRETTY_FUNCTION__ << endl << "säugetier hat " << beine << " Beine." << endl; }

	friend ostream &operator<<(ostream &out, const ameise &other) {
		return out << "Ameisenart: " << other.ameisen_art << ", heißt: " << other.name << " und hat " << other.beine << " Beine." << endl;
	}
};

class mensch : public säugetier {
private:
	int alter;
public:
	mensch(const string &name, int beine, int alter) : säugetier(name, beine), alter(alter) { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~mensch() = default;
	void print_name() override { cout << __PRETTY_FUNCTION__ << endl << "mensch heißt " << name << endl; }
	void print_beine() override { cout << __PRETTY_FUNCTION__ << endl << "mensch hat " << beine << " Beine." << endl; }

	friend ostream& operator<<(ostream &out, const mensch &other) {
		return out << "mensch alter: " << other.alter << ", heißt " << other.name << " und hat " << other.beine << " Beine." << endl;
	}	
};

class zootier : public tier{ //rein abstrakt -> virtual methoden = 0 only
public:
	zootier(const string &name, int beine) : tier(name, beine) {}
	virtual ~zootier() = default;
	virtual void fuettern() = 0;
};

template<typename T>
class zoo {
private:
	//todo: find right datatype
public:

};

class tierpfleger {
private:
	string name;
public:
	tierpfleger(const string &name) : name(name) {}
	void fuettern(const zootier &other) override {
		//other.fuettern(); //???
	}
;

int main() {
	tier tier1("random_tier", 3);
	cout << tier1 << endl;
	säugetier säugetier1("erwin", 4);
	cout << säugetier1 << endl;
	säugetier1.print_name();
	säugetier1.print_beine();	
	pferd pferd1("Pferd1", 4, "bulle");
	ameise ameise1("Ameise1", 8, "rote Ameise");
	mensch mensch1("Mensch1", 2, 32);

	cout << pferd1 << endl << ameise1 << endl << mensch1 << endl;

	mensch1.print_name();

	return 0;
}
