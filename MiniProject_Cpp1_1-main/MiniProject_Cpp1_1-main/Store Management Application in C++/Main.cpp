#include "Store.h"

std::map<std::string, long long int> discountPercentage, MembershipPrice;

void init() {
	discountPercentage["CLASSIC"] = 5;
	discountPercentage["GOLD"] = 10;
	discountPercentage["PREMIUM"] = 15;
	discountPercentage["NONE"] = 0;

	MembershipPrice["CLASSIC"] = 2000;
	MembershipPrice["GOLD"] = 5000;
	MembershipPrice["PREMIUM"] = 10000;
	MembershipPrice["NONE"] = 0;
}

int main() {
	init();
	Store store;
	store.launch();
	return 0;
}