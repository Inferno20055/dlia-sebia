#include <iostream>
#include <string>
#include <memory>
#include<algorithm>
#include <vector>
using namespace std;

#pragma once
class Fruit
{
private:
	string name;
	double price;
	double weight;

public:
	Fruit(const string& name,double price,double weight):name(name),price(price),weight(weight) {}
	~Fruit() {

	}
	double getPrice()const {
		return price;
	}
	string getName()const {
		return name;
	}
	double getWeight()const {
		return weight;
	}
	double setPrice(double pric) {
		price = pric;
	}
	double setWeight(double weig) {
		weight = weig;
	}
	string setName(string nam) {
		name = nam;
	}
};

