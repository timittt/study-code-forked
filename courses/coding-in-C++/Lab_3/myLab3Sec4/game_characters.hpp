#ifndef GAME_CHARACTERS_HPP
#define GAME_CHARACTERS_HPP

#include <iostream>
#include <string>

// forward declarations
class Weapon;
class Healer;

class Inventory
{
public:
	Inventory();
	~Inventory();
	bool isEmpty() const;
	bool isFull() const;
	bool addItem(const std::string& item);
	bool removeLastItem(std::string& item);
	int getItemCount() const;
	static constexpr int MAX_SLOTS = 10;
private:
	std::string items[MAX_SLOTS];
	int itemCount;
};

class Character // abstract class
{
public:
	Character(std::string name, int hp, int level);
	virtual ~Character();
	int getCharacterCount() const;
	std::string getName() const;
	int getHP() const;
	int getLevel() const;
	virtual std::string getType() const;
	virtual int getSP() const = 0;		// get Class-Specific points
	void equipWeapon(Weapon* p_newWeapon);
	Weapon* getCurrentWeapon() const;
	void displayStatus() const;
	Inventory& getInventory();
	void lvlUp();
	friend Healer;

protected:
	static int character_count;
	std::string name;
	int hp;
	int level;
	Inventory inventory;
	Weapon* p_weapon;
};

class Warrior : public Character
{
public:
	Warrior(std::string name, int hp, int level, int skill_pts) : Character(name, hp, level), skill_pts(skill_pts) {};
	~Warrior() {};
	std::string getType() const override;
	int getSP() const override;

private:
	int skill_pts;
};

class Thief : public Warrior
{
public:
	Thief(std::string name, int hp, int level, int skill_pts) : Warrior(name, hp, level, skill_pts) {};
	~Thief() {};
	Thief& steal(Character& Target);
};

class Mage : public Character
{
public:
	Mage(std::string name, int hp, int level, int mana_pts) : Character(name, hp, level), mana_pts(mana_pts) {};
	~Mage() {};
	std::string getType() const override;
	int getSP() const override;

private:
	int mana_pts;
};

class Healer : public Mage
{
public:
	Healer(std::string name, int hp, int level, int mana_pts) : Mage(name, hp, level, mana_pts) {};
	~Healer() {};
	Healer& heal(Character& Target);
};

class Weapon
{
public:
	Weapon();
	~Weapon() {};
	std::string getName() const;
	int getDmg() const;

private:
	std::string name;
	int damage;
};



#endif // !GAME_CHARACTERS_HPP