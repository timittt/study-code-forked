#include "game_characters.hpp"

int Character::character_count = 0;

Character::Character(std::string name, int hp, int level)
	: name(name), hp(hp), level(level)
{
	character_count++;
}

Character::~Character()
{
	p_weapon = nullptr;
	character_count--;
	std::cout << "Destroyed Character " << name << std::endl;
}

int Character::getCharacterCount() const
{
	return character_count;
}

std::string Character::getName() const
{
	return name;
}

int Character::getHP() const
{
	return hp;
}

int Character::getLevel() const
{
	return level;
}

void Character::equipWeapon(Weapon* p_newWeapon)
{
	 p_weapon = p_newWeapon;
}

Weapon* Character::getCurrentWeapon() const
{
	return p_weapon;
}

Inventory& Character::getInventory()
{
	return inventory;
}

void Character::displayStatus() const
{
	std::cout << "--- CHARACTER INFORMATION ---" << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Health: " << hp << std::endl;
	std::cout << "Level: " << level << std::endl;
	std::cout << "Inventory: " << this->inventory.getItemCount() << "out of " << Inventory::MAX_SLOTS << std::endl;
	std::cout << "Weapon: " << (p_weapon ? p_weapon->getName() : "None") << std::endl;
}

void Character::lvlUp()
{
	level++;
}

std::string Warrior::getType() const
{
	return "Warrior";
}

int Warrior::getSP() const
{
	return skill_pts;
}

Thief& Thief::steal(Character& Target)
{
	if (Target.getInventory().isEmpty() || Target.getInventory().isFull())
	{
		std::cout << "Stealing failed\n";
	}
	else
	{
		std::string stolen_item;
		Target.getInventory().removeLastItem(stolen_item);
		this->getInventory().addItem(stolen_item);
		std::cout << "Thief " << this->getName() << "stole " << stolen_item << "from " << Target.getName() << std::endl;
	}
	return *this;
}

std::string Mage::getType() const
{
	return "Mage";
}

int Mage::getSP() const
{
	return mana_pts;
}

Healer& Healer::heal(Character& Target)
{
	Target.hp += 10;
	return *this;
}

Inventory::Inventory() : itemCount(0) {
	// Array zero-initialisieren
}

bool Inventory::isEmpty() const {
	return itemCount == 0;
}

bool Inventory::isFull() const {
	return itemCount >= 10;
}

int Inventory::getItemCount() const {
	return itemCount;
}

bool Inventory::addItem(const std::string& item) 
{
	if (isFull())
	{
		return false;
	}

	items[itemCount] = item;
	itemCount++;       
	return true;
}

bool Inventory::removeLastItem(std::string& item) {
	if (isEmpty()) 
	{
		return false;
	}

	itemCount--;
	item = items[itemCount];
	items[itemCount] = "";		// leerer String an der Stelle

	return true;
}