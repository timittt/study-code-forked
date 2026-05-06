#ifndef GAME_CHARACTERS_HPP
#define GAME_CHARACTERS_HPP

#include <iostream>
#include <string>

class Character
{
public:
	Character(std::string name, int hp, int level);
	~Character();
	int getCharacterCount() const;
	std::string getName() const;
	int getHP() const;
	int getLevel() const;
	virtual std::string getType() const;
	virtual int getSP() const;		// get Class-Specific points
	void equipWeapon(Weapon* newWeapon);
	Weapon& getCurrentWeapon() const;
	void displayStatus() const;
	Inventory& getInventory();
	void lvlUp();
	friend Healer;

private:
	static int character_count;
	std::string name;
	int hp;
	int level;
	Inventory inventory;
	Weapon* weapon;
};

class Warrior : public Character
{
public:
	Warrior();
	~Warrior();
	std::string getType();
	int getSP() const;

private:
	int skill_pts;
};

class Thief : public Warrior
{
public:
	Thief();
	~Thief();
	Thief& steal(Character& Target);
};

class Mage : public Character
{
public:
	Mage();
	~Mage();
	std::string getType();
	int getSP() const;

private:
	int mana_pts;
};

class Healer : public Mage
{
public:
	Healer();
	~Healer();
	Healer& heal(Character& Target);
};

class Weapon
{
public:
	Weapon();
	~Weapon();
	std::string getName() const;
	int getDmg() const;

private:
	std::string name;
	int damage;
};

class Inventory
{
public:
	Inventory();
	~Inventory();
	bool isEmpty();
	bool isFull();
	bool addItem(const std::string& item);
	bool removeLastItem(const std::string& item);

private:
	std::string items[10];
};

#endif // !GAME_CHARACTERS_HPP