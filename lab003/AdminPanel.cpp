#include "AdminPanel.h"
#include <iostream>

// Конструктор
AdminPanel::AdminPanel(AddressBook& addressBook) : addressBook(addressBook) {}

// Главное меню администратора
void AdminPanel::displayMenu() {
    int choice;
    do {
        std::cout << "\n---- Панель администратора ----\n";
        std::cout << "1. Добавить контакт\n";
        std::cout << "2. Редактировать контакт\n";
        std::cout << "3. Удалить контакт\n";
        std::cout << "4. Просмотреть все контакты\n";
        std::cout << "5. Найти контакт\n";
        std::cout << "6. Сохранить контакты в файл\n";
        std::cout << "7. Загрузить контакты из файла\n";
        std::cout << "8. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addContact();
            break;
        case 2:
            editContact();
            break;
        case 3:
            deleteContact();
            break;
        case 4:
            viewContacts();
            break;
        case 5:
            searchContacts();
            break;
        case 6:
            saveContactsToFile();
            break;
        case 7:
            loadContactsFromFile();
            break;
        case 8:
            std::cout << "Выход из панели администратора.\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 8);
}

// Добавление контакта
void AdminPanel::addContact() {
    addressBook.addContact();
}

// Редактирование контакта
void AdminPanel::editContact() {
    addressBook.editContact();
}

// Удаление контакта
void AdminPanel::deleteContact() {
    addressBook.deleteContact();
}

// Просмотр всех контактов
void AdminPanel::viewContacts() const {
    addressBook.displayContacts();
}

// Поиск контактов
void AdminPanel::searchContacts() const {
    addressBook.searchContact();
}

// Сохранение контактов в файл
void AdminPanel::saveContactsToFile() const {
    std::string filename;
    std::cout << "Введите имя файла для сохранения: ";
    std::cin >> filename;
    addressBook.saveToFile(filename);
}

// Загрузка контактов из файла
void AdminPanel::loadContactsFromFile() {
    std::string filename;
    std::cout << "Введите имя файла для загрузки: ";
    std::cin >> filename;
    addressBook.loadFromFile(filename);
}
