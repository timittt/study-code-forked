#include "streaming_platform.hpp"

Device::Device(const std::string& name) 
	: name(name), power_status(false) {}

//virtual
Device::~Device()
{
	std::cout << "[DESTRUCTOR] Device " << this->name << " has been destroyed.\n";
}

void Device::turn_on()
{
	power_status = true;
}

void Device::turn_off()
{
	power_status = false;
}

void Device::print_info() const
{
	std::cout << "Device " << this->name << " is currently turned " << (power_status ? "on." : "off.") << std::endl;
}

std::string Device::get_name() const
{
	return name;
}

SharedDevice::SharedDevice(const std::string& name, const std::string& ip)
	: Device(name), ip_address(ip), connection_status(false) {}

SharedDevice::~SharedDevice()
{
	std::cout << "[DESTRUCTOR] Shared Device " << this->get_name() << " has been destroyed.\n";
}

void SharedDevice::connect()
{
	connection_status = true;
}

void SharedDevice::disconnect()
{
	connection_status = false;
}

void SharedDevice::print_network_info()
{
	std::cout << "Device " << this->get_name() << " has IP Address " << ip_address << " and is currently " << (connection_status ? "" : "not ") << "connected.\n";
}


Room::Room(const std::string& name)
	: name(name) { }

Room::~Room()
{
	std::cout << "[DESTRUCTOR] Room " << this->name << " has been destroyed.\n";
}

bool Room::add_device(std::unique_ptr<Device> ptr_new_device)
{
	if (ptr_new_device)
	{
		exclusive_devices.push_back(std::move(ptr_new_device));
		return true;
	}
	return false;
}

bool Room::add_shared_device(std::shared_ptr<SharedDevice> ptr_new_shared_device)
{
	if (ptr_new_shared_device)
	{
		shared_devices.push_back(ptr_new_shared_device);
		return true;
	}
	return false;
}

bool Room::remove_device_by_name(const std::string& device_name)
{
	for (auto it = exclusive_devices.begin(); it != exclusive_devices.end(); )
	{
		if ((*it)->get_name() == device_name)
		{
			it = exclusive_devices.erase(it);
			return true;
		}
		else
		{
			++it;
		}
	}
	return false;
}

void Room::print_devices() const
{
	int i = 1;
	std::cout << "Current exclusive devices in room " << name << ":\n";
	for (auto it = exclusive_devices.begin(); it != exclusive_devices.end(); ++it)
	{
		std::cout << i << ". ";
		(*it)->print_info();
		++i;
	}
}

void Room::print_shared_devices() const
{
	int i = 1;
	std::cout << "Current shared devices in room " << name << ":\n";
	for (auto it = shared_devices.begin(); it != shared_devices.end(); ++it)
	{
		std::cout << i << ". ";
		(*it)->print_info();
		(*it)->print_network_info();
		++i;
	}
}

int main()
{
	std::cout << "--- START SMART HOME SYSTEM TEST ---\n\n";

	// 1. Räume erstellen
	std::cout << "[INFO] Creating rooms...\n";
	Room livingRoom("Wohnzimmer");
	Room kitchen("Kueche");
	std::cout << "----------------------------------------\n\n";

	// 2. Geräte für das Wohnzimmer erstellen und hinzufügen
	std::cout << "[INFO] Adding exclusive_devices to Living Room...\n";

	// Wir erstellen die exclusive_devices direkt als unique_ptr via std::make_unique
	auto tv = std::make_unique<Device>("Fernseher");
	auto lamp = std::make_unique<Device>("Stehlampe");

	// Shared devices erstellen
	auto speaker = std::make_shared<SharedDevice>("Musikanlage", "168.0.1.187");
	auto nas = std::make_shared<SharedDevice>("Central Network Storage", "168.0.1.166");

	// Einige Geräte vorab einschalten, um den Power-Status zu testen
	tv->turn_on();
	speaker->turn_on();
	speaker->connect();


	// WICHTIG: Übergabe mit std::move, da unique_ptr nicht kopiert werden können!
	livingRoom.add_device(std::move(tv));
	livingRoom.add_device(std::move(lamp));

	// Shared Devices hinzufügen
	livingRoom.add_shared_device(speaker);
	kitchen.add_shared_device(speaker);
	livingRoom.add_shared_device(nas);

	// Zustand des Wohnzimmers prüfen
	livingRoom.print_devices();
	std::cout << "----------------------------------------\n\n";

	// 3. Geräte für die Küche erstellen und hinzufügen
	std::cout << "[INFO] Adding exclusive_devices to Kitchen...\n";

	auto fridge = std::make_unique<Device>("Kuehlschrank");
	auto microwave = std::make_unique<Device>("Mikrowelle");
	// fan pointer is destroyed at the end of scope
	{
		auto fan = std::make_unique<Device>("Ventilator");
	}
	fridge->turn_on(); // Der Kühlschrank sollte laufen

	kitchen.add_device(std::move(fridge));
	kitchen.add_device(std::move(microwave));

	// Zustand der Küche prüfen
	kitchen.print_devices();
	kitchen.print_shared_devices();
	std::cout << "----------------------------------------\n\n";

	// 4. Test: Gerät löschen, das existiert
	std::cout << "[INFO] Testing device removal (Success case)...\n";
	if (livingRoom.remove_device_by_name("Stehlampe"))
	{
		std::cout << "Successfully removed 'Stehlampe' from Living Room.\n";
	}
	else
	{
		std::cout << "Failed to remove 'Stehlampe'.\n";
	}
	kitchen.remove_device_by_name("Musikanlage");

	// Kontrolle, ob das Gerät wirklich weg ist (Sollte nur noch der Fernseher da sein)
	livingRoom.print_devices();
	livingRoom.print_shared_devices();
	std::cout << "----------------------------------------\n\n";

	// 5. Test: Gerät löschen, das NICHT existiert
	std::cout << "[INFO] Testing device removal (Failure case)...\n";
	if (kitchen.remove_device_by_name("Toaster"))
	{
		std::cout << "Successfully removed 'Toaster' from Kitchen.\n";
	}
	else
	{
		std::cout << "Device 'Toaster' not found in Kitchen (Correct behavior).\n";
	}
	std::cout << "----------------------------------------\n\n";

	// 6. Das große Finale: Beobachte die Destruktoren!
	std::cout << "[INFO] Leaving main function. Watch the Destructors clear the memory:\n";

	return 0;
}