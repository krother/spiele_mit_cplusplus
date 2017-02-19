#include <vector>
#include <iostream>
using namespace std;

class Tier {
  public:
    virtual void get_name() {
    	cout << "Tier" << endl;
    }
};


class Hund: public Tier {
  public:
    virtual void get_name() {
    	cout << "Hund" << endl;
    }

};

class Biene: public Tier {
  public:
    virtual void get_name() {
    	cout << "Biene" << endl;
    }

};


int main() {

	Tier *t1 = new Hund();
	Tier *t2 = new Biene();

    vector<Tier*> tiere;
    tiere.push_back(t1);
    tiere.push_back(t2);
    
    for (int i=0; i<tiere.size(); i++) {
    	tiere[i]->get_name();
    }

}
