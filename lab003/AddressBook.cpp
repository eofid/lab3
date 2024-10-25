#include "AddressBook.h"
#include <iostream>
#include <fstream>

// Äîáàâëåíèå íîâîãî êîíòàêòà
void AddressBook::addContact() {
    std::string name;
    std:: string phone;
    std:: string email;
    std:: string street;
    std:: string city;
    std:: string postalCode;
    std:: string companyName;
    std:: tring position;

    std::cout << "Ââåäèòå èìÿ: ";
    std::cin >> name;
    std::cout << "Ââåäèòå òåëåôîí: ";
    std::cin >> phone;
    std::cout << "Ââåäèòå email: ";
    std::cin >> email;

    std::cout << "Ââåäèòå óëèöó: ";
    std::cin.ignore(); // Èãíîðèðóåì ñèìâîë íîâîé ñòðîêè
    std::getline(std::cin, street);
    std::cout << "Ââåäèòå ãîðîä: ";
    std::getline(std::cin, city);
    std::cout << "Ââåäèòå ïî÷òîâûé èíäåêñ: ";
    std::getline(std::cin, postalCode);

    std::cout << "Ââåäèòå íàçâàíèå êîìïàíèè: ";
    std::getline(std::cin, companyName);
    std::cout << "Ââåäèòå äîëæíîñòü: ";
    std::getline(std::cin, position);

    Address address(street, city, postalCode);
    Company company(companyName, position);

    contacts.emplace_back(name, phone, email, address, company);
    std::cout << "Êîíòàêò äîáàâëåí!\n";
}

// Ðåäàêòèðîâàíèå êîíòàêòà ïî èìåíè
void AddressBook::editContact() {
    std::string name;
    std::cout << "Ââåäèòå èìÿ êîíòàêòà äëÿ ðåäàêòèðîâàíèÿ: ";
    std::cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Ðåäàêòèðîâàíèå êîíòàêòà " << contact.name << std::endl;
            std::cout << "Ââåäèòå íîâîå èìÿ: ";
            std::cin >> contact.name;
            std::cout << "Ââåäèòå íîâûé òåëåôîí: ";
            std::cin >> contact.phone;
            std::cout << "Ââåäèòå íîâûé email: ";
            std::cin >> contact.email;

            std::string street;
            std:: string city;
            std:: string postalCode;
            std:: string companyName;
            std:: string position;
            std::cout << "Ââåäèòå íîâóþ óëèöó: ";
            std::cin.ignore(); // Èãíîðèðóåì ñèìâîë íîâîé ñòðîêè
            std::getline(std::cin, street);
            std::cout << "Ââåäèòå íîâûé ãîðîä: ";
            std::getline(std::cin, city);
            std::cout << "Ââåäèòå íîâûé ïî÷òîâûé èíäåêñ: ";
            std::getline(std::cin, postalCode);
            std::cout << "Ââåäèòå íîâîå íàçâàíèå êîìïàíèè: ";
            std::getline(std::cin, companyName);
            std::cout << "Ââåäèòå íîâóþ äîëæíîñòü: ";
            std::getline(std::cin, position);

            contact.address = Address(street, city, postalCode); // Îáíîâëÿåì àäðåñ
            contact.company = Company(companyName, position); // Îáíîâëÿåì êîìïàíèþ
            std::cout << "Êîíòàêò îáíîâëåí!\n";
            return;
        }
    }
    std::cout << "Êîíòàêò íå íàéäåí!\n";
}

// Óäàëåíèå êîíòàêòà ïî èìåíè
void AddressBook::deleteContact() {
    std::string name;
    std::cout << "Ââåäèòå èìÿ êîíòàêòà äëÿ óäàëåíèÿ: ";
    std::cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "Êîíòàêò óäàëåí!\n";
            return;
        }
    }
    std::cout << "Êîíòàêò íå íàéäåí!\n";
}

// Ïîèñê êîíòàêòà ïî èìåíè
void AddressBook::searchContact() const {
    std::string name;
    std::cout << "Ââåäèòå èìÿ äëÿ ïîèñêà: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Êîíòàêò íàéäåí:\n";
            std::cout << contact;
            return;
        }
    }
    std::cout << "Êîíòàêò íå íàéäåí!\n";
}

// Îòîáðàæåíèå âñåõ êîíòàêòîâ
void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "Àäðåñíàÿ êíèãà ïóñòà.\n";
        return;
    }

    for (const auto& contact : contacts) {
        std::cout << "Èìÿ: " << contact.name << std::endl;
        std::cout << "Òåëåôîí: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "Àäðåñ: " << contact.address.getStreet() << ", "
            << contact.address.getCity() << ", "
            << contact.address.getPostalCode() << std::endl;
        std::cout << "Êîìïàíèÿ: " << contact.company.getName() << ", "
            << "Äîëæíîñòü: " << contact.company.getPosition() << std::endl;
        std::cout << "-------------------\n";
    }
}

// Ñîõðàíåíèå êîíòàêòîâ â ôàéë
void AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& contact : contacts) {
            outFile << contact;
        }
        outFile.close();
        std::cout << "Êîíòàêòû ñîõðàíåíû â ôàéë " << filename << ".\n";
    }
    else {
        std::cout << "Íå óäàëîñü îòêðûòü ôàéë äëÿ çàïèñè.\n";
    }
}

// Çàãðóçêà êîíòàêòîâ èç ôàéëà
void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        contacts.clear();
        Contact contact("", "", "", Address("", "", ""), Company("", ""));
        while (inFile >> contact) {
            contacts.push_back(contact);
        }
        inFile.close();
        std::cout << "Êîíòàêòû çàãðóæåíû èç ôàéëà " << filename << ".\n";
    }
    else {
        std::cout << "Íå óäàëîñü îòêðûòü ôàéë äëÿ ÷òåíèÿ.\n";
    }
}
