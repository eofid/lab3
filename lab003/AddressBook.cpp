#include "AddressBook.h"
#include <iostream>
#include <fstream>

// ���������� ������ ��������
void AddressBook::addContact() {
    std::string name, phone, email, street, city, postalCode, companyName, position;

    std::cout << "������� ���: ";
    std::cin >> name;
    std::cout << "������� �������: ";
    std::cin >> phone;
    std::cout << "������� email: ";
    std::cin >> email;

    std::cout << "������� �����: ";
    std::cin.ignore(); // ���������� ������ ����� ������
    std::getline(std::cin, street);
    std::cout << "������� �����: ";
    std::getline(std::cin, city);
    std::cout << "������� �������� ������: ";
    std::getline(std::cin, postalCode);

    std::cout << "������� �������� ��������: ";
    std::getline(std::cin, companyName);
    std::cout << "������� ���������: ";
    std::getline(std::cin, position);

    Address address(street, city, postalCode);
    Company company(companyName, position);

    contacts.emplace_back(name, phone, email, address, company);
    std::cout << "������� ��������!\n";
}

// �������������� �������� �� �����
void AddressBook::editContact() {
    std::string name;
    std::cout << "������� ��� �������� ��� ��������������: ";
    std::cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "�������������� �������� " << contact.name << std::endl;
            std::cout << "������� ����� ���: ";
            std::cin >> contact.name;
            std::cout << "������� ����� �������: ";
            std::cin >> contact.phone;
            std::cout << "������� ����� email: ";
            std::cin >> contact.email;

            std::string street, city, postalCode, companyName, position;
            std::cout << "������� ����� �����: ";
            std::cin.ignore(); // ���������� ������ ����� ������
            std::getline(std::cin, street);
            std::cout << "������� ����� �����: ";
            std::getline(std::cin, city);
            std::cout << "������� ����� �������� ������: ";
            std::getline(std::cin, postalCode);
            std::cout << "������� ����� �������� ��������: ";
            std::getline(std::cin, companyName);
            std::cout << "������� ����� ���������: ";
            std::getline(std::cin, position);

            contact.address = Address(street, city, postalCode); // ��������� �����
            contact.company = Company(companyName, position); // ��������� ��������
            std::cout << "������� ��������!\n";
            return;
        }
    }
    std::cout << "������� �� ������!\n";
}

// �������� �������� �� �����
void AddressBook::deleteContact() {
    std::string name;
    std::cout << "������� ��� �������� ��� ��������: ";
    std::cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "������� ������!\n";
            return;
        }
    }
    std::cout << "������� �� ������!\n";
}

// ����� �������� �� �����
void AddressBook::searchContact() const {
    std::string name;
    std::cout << "������� ��� ��� ������: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "������� ������:\n";
            std::cout << contact;
            return;
        }
    }
    std::cout << "������� �� ������!\n";
}

// ����������� ���� ���������
void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "�������� ����� �����.\n";
        return;
    }

    for (const auto& contact : contacts) {
        std::cout << "���: " << contact.name << std::endl;
        std::cout << "�������: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "�����: " << contact.address.getStreet() << ", "
            << contact.address.getCity() << ", "
            << contact.address.getPostalCode() << std::endl;
        std::cout << "��������: " << contact.company.getName() << ", "
            << "���������: " << contact.company.getPosition() << std::endl;
        std::cout << "-------------------\n";
    }
}

// ���������� ��������� � ����
void AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& contact : contacts) {
            outFile << contact;
        }
        outFile.close();
        std::cout << "�������� ��������� � ���� " << filename << ".\n";
    }
    else {
        std::cout << "�� ������� ������� ���� ��� ������.\n";
    }
}

// �������� ��������� �� �����
void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        contacts.clear();
        Contact contact("", "", "", Address("", "", ""), Company("", ""));
        while (inFile >> contact) {
            contacts.push_back(contact);
        }
        inFile.close();
        std::cout << "�������� ��������� �� ����� " << filename << ".\n";
    }
    else {
        std::cout << "�� ������� ������� ���� ��� ������.\n";
    }
}
