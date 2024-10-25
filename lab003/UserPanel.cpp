// UserPanel.cpp
#include "UserPanel.h"
#include <iostream>

// Конструктор
UserPanel::UserPanel(AddressBook& addressBook) : addressBook(addressBook) {}

// Главное меню пользователя
void UserPanel::displayMenu() {
    int choice;
    do {
        std::cout << "\n---- Панель пользователя ----\n";
        std::cout << "1. Просмотреть контакты\n";
        std::cout << "2. Найти контакт\n";
        std::cout << "3. Загрузить контакты из файла\n";  // Новый пункт меню
        std::cout << "4. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            viewContacts();
            break;
        case 2:
            searchContacts();
            break;
        case 3:
            loadContactsFromFile();
            break;
        case 4:
            std::cout << "Выход из панели пользователя.\n";
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 4);
}

// Реализация загрузки контактов из файла
void UserPanel::loadContactsFromFile() {
    std::string filename;
    std::cout << "Введите имя файла для загрузки: ";
    std::cin >> filename;
    addressBook.loadFromFile(filename);
    std::cout << "Контакты успешно загружены.\n";
}

// Просмотр всех контактов
void UserPanel::viewContacts() const {
    addressBook.displayContacts();
}

// Поиск контактов
void UserPanel::searchContacts() const {
    addressBook.searchContact();
}
