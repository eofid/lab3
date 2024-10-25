#include "AddressBook.h"
#include <iostream>
#include <fstream>

// Добавление нового контакта
void AddressBook::addContact() {
    std::string name, phone, email, street, city, postalCode, companyName, position;

    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите телефон: ";
    std::cin >> phone;
    std::cout << "Введите email: ";
    std::cin >> email;

    std::cout << "Введите улицу: ";
    std::cin.ignore(); // Игнорируем символ новой строки
    std::getline(std::cin, street);
    std::cout << "Введите город: ";
    std::getline(std::cin, city);
    std::cout << "Введите почтовый индекс: ";
    std::getline(std::cin, postalCode);

    std::cout << "Введите название компании: ";
    std::getline(std::cin, companyName);
    std::cout << "Введите должность: ";
    std::getline(std::cin, position);

    Address address(street, city, postalCode);
    Company company(companyName, position);

    contacts.emplace_back(name, phone, email, address, company);
    std::cout << "Контакт добавлен!\n";
}

// Редактирование контакта по имени
void AddressBook::editContact() {
    std::string name;
    std::cout << "Введите имя контакта для редактирования: ";
    std::cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Редактирование контакта " << contact.name << std::endl;
            std::cout << "Введите новое имя: ";
            std::cin >> contact.name;
            std::cout << "Введите новый телефон: ";
            std::cin >> contact.phone;
            std::cout << "Введите новый email: ";
            std::cin >> contact.email;

            std::string street, city, postalCode, companyName, position;
            std::cout << "Введите новую улицу: ";
            std::cin.ignore(); // Игнорируем символ новой строки
            std::getline(std::cin, street);
            std::cout << "Введите новый город: ";
            std::getline(std::cin, city);
            std::cout << "Введите новый почтовый индекс: ";
            std::getline(std::cin, postalCode);
            std::cout << "Введите новое название компании: ";
            std::getline(std::cin, companyName);
            std::cout << "Введите новую должность: ";
            std::getline(std::cin, position);

            contact.address = Address(street, city, postalCode); // Обновляем адрес
            contact.company = Company(companyName, position); // Обновляем компанию
            std::cout << "Контакт обновлен!\n";
            return;
        }
    }
    std::cout << "Контакт не найден!\n";
}

// Удаление контакта по имени
void AddressBook::deleteContact() {
    std::string name;
    std::cout << "Введите имя контакта для удаления: ";
    std::cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            std::cout << "Контакт удален!\n";
            return;
        }
    }
    std::cout << "Контакт не найден!\n";
}

// Поиск контакта по имени
void AddressBook::searchContact() const {
    std::string name;
    std::cout << "Введите имя для поиска: ";
    std::cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            std::cout << "Контакт найден:\n";
            std::cout << contact;
            return;
        }
    }
    std::cout << "Контакт не найден!\n";
}

// Отображение всех контактов
void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        std::cout << "Адресная книга пуста.\n";
        return;
    }

    for (const auto& contact : contacts) {
        std::cout << "Имя: " << contact.name << std::endl;
        std::cout << "Телефон: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << "Адрес: " << contact.address.getStreet() << ", "
            << contact.address.getCity() << ", "
            << contact.address.getPostalCode() << std::endl;
        std::cout << "Компания: " << contact.company.getName() << ", "
            << "Должность: " << contact.company.getPosition() << std::endl;
        std::cout << "-------------------\n";
    }
}

// Сохранение контактов в файл
void AddressBook::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& contact : contacts) {
            outFile << contact;
        }
        outFile.close();
        std::cout << "Контакты сохранены в файл " << filename << ".\n";
    }
    else {
        std::cout << "Не удалось открыть файл для записи.\n";
    }
}

// Загрузка контактов из файла
void AddressBook::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        contacts.clear();
        Contact contact("", "", "", Address("", "", ""), Company("", ""));
        while (inFile >> contact) {
            contacts.push_back(contact);
        }
        inFile.close();
        std::cout << "Контакты загружены из файла " << filename << ".\n";
    }
    else {
        std::cout << "Не удалось открыть файл для чтения.\n";
    }
}
