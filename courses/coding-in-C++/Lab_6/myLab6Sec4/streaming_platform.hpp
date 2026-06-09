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
	virtual ~Device();
	void turn_on();
	void turn_off();
	void print_info() const;
	std::string get_name() const;
private:
	std::string name;
	std::string type;
	bool power_status;
};

class SharedDevice : public Device
{
private:
	std::string ip_address;
	bool connection_status;
public:
	SharedDevice(const std::string& name, const std::string& ip);
	~SharedDevice();
	void connect();
	void disconnect();
	void print_network_info();
};

class Room
{
public:
	Room(const std::string& name);
	~Room();
	bool add_device(std::unique_ptr<Device> ptr_new_device);
	bool remove_device_by_name(const std::string& device_name);
	void print_devices() const;
	void print_shared_devices() const;
	bool add_shared_device(std::shared_ptr<SharedDevice> ptr_new_shared_device);
private:
	std::string name;
	std::list<std::unique_ptr<Device>> exclusive_devices;
	std::list<std::shared_ptr<SharedDevice>> shared_devices;
};