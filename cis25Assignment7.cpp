#include <iostream>
#include <string>
using namespace std;

class Item {
public:
	string name;
	int quantity;

	Item(string n, int q) {
		name = n;
		quantity = q;
	}
	virtual void Display() = 0;
};

class Perishable : public Item {
public:
	Perishable(string n, int q) : Item(n, q) {}

	void Display() override {
		cout << name << "(Perishable), QTY: " << quantity << endl;
	}
};

class NonPerishable : public Item {
public:
	NonPerishable(string n, int q) : Item(n, q) {}

	void Display() override {
		cout << name << "(Non-Perishable), QTY: " << quantity << endl;
	}
};


int main() {
	Item* item1 = new Perishable("Grapes", 10);
	Item* item2 = new NonPerishable("Twinkies", 45);

	item1->Display();
	item2->Display();

	delete item1;
	delete item2;

	return 0;
}