#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <iterator>

class Device
{
public:
	Device(const std::string& name);
	~Device();
	void turn_on();
	void turn_off();
	void print_info() const;
	std::string get_name() const;
private:
	std::string name;
	std::string type;
	bool power_status;
};

class Room
{
public:
	Room(const std::string& name);
	~Room();
	bool add_device(std::unique_ptr<Device> ptr_new_device);
	bool remove_device_by_name(const std::string& device_name);
	void print_devices() const;
private:
	std::string name;
	std::list<std::unique_ptr<Device>> devices;
};