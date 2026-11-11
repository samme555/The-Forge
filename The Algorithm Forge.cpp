#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
	string name;
	string type;
	int power;
	int durability;
	int rarity;
};

int main() {
	vector<Item> loot = {
		{"Ashbow", "weapon", 70, 40, 3}, //power, durability, rarity
		{"Emerald", "gem", 25, 0, 4},
		{"Emberblade", "weapon", 90, 10, 4},
		{"Stone", "material", 5, 0, 1},
		{"Warglaive", "weapon", 100, 50, 5},
		{"Ruby", "gem", 30, 0, 5},
		{"Sapphire", "gem", 20, 0, 4}
	};

	cout << "[Forge: Before]" << endl;

	for (const Item& item : loot) { //for every item inside loot
		cout << item.type << " "
			<< item.name
			<< " Power: " << item.power
			<< " Durability: " << item.durability
			<< " Rarity: " << item.rarity
			<< endl;
	}

	vector<Item> weapons;

	for (const Item& item : loot) {
		if (item.type == "weapon") {
			weapons.push_back(item);
		}
	}

	sort(weapons.begin(), weapons.end(),
		[](const Item& a, const Item& b) {
			return a.power > b.power; //sort by power
		});

	cout << endl;
	cout << "[Weapons sorted by power]" << endl;

	for (const Item& item : weapons) {
		cout << item.name
			<< " Power: " << item.power
			<< endl;
	}

	int rareGems = count_if(loot.begin(), loot.end(),
		[](const Item& item) {
			return item.type == "gem" && item.rarity >= 4; //count rare gems
		});

	cout << endl;
	cout << "Rare gems found: " << rareGems << endl;

	transform(loot.begin(), loot.end(), loot.begin(),
		[](Item item) {
			if (item.type == "weapon") {
				item.durability -= 10;

				if (item.durability < 0) {
					item.durability = 0;
				}
			}

			return item;
		});

	loot.erase(
		remove_if(loot.begin(), loot.end(),
			[](const Item& item) {
				return item.type == "weapon" && item.durability == 0;
			}),
		loot.end()
	);

	cout << endl;
	cout << "[Forge: After]" << endl;

	for (const Item& item : loot) {
		cout << item.type << " "
			<< item.name
			<< " Power: " << item.power
			<< " Durability: " << item.durability
			<< " Rarity: " << item.rarity
			<< endl;
	}

	return 0;
}
