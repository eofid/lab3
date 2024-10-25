#include "AdminPanel.h"
#include <iostream>

// �����������
AdminPanel::AdminPanel(AddressBook& addressBook) : addressBook(addressBook) {}

// ������� ���� ��������������
void AdminPanel::displayMenu() {
    int choice;
    do {
        std::cout << "\n---- ������ �������������� ----\n";
        std::cout << "1. �������� �������\n";
        std::cout << "2. ������������� �������\n";
        std::cout << "3. ������� �������\n";
        std::cout << "4. ����������� ��� ��������\n";
        std::cout << "5. ����� �������\n";
        std::cout << "6. ��������� �������� � ����\n";
        std::cout << "7. ��������� �������� �� �����\n";
        std::cout << "8. �����\n";
        std::cout << "������� ��� �����: ";
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
            std::cout << "����� �� ������ ��������������.\n";
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
        }
    } while (choice != 8);
}

// ���������� ��������
void AdminPanel::addContact() {
    addressBook.addContact();
}

// �������������� ��������
void AdminPanel::editContact() {
    addressBook.editContact();
}

// �������� ��������
void AdminPanel::deleteContact() {
    addressBook.deleteContact();
}

// �������� ���� ���������
void AdminPanel::viewContacts() const {
    addressBook.displayContacts();
}

// ����� ���������
void AdminPanel::searchContacts() const {
    addressBook.searchContact();
}

// ���������� ��������� � ����
void AdminPanel::saveContactsToFile() const {
    std::string filename;
    std::cout << "������� ��� ����� ��� ����������: ";
    std::cin >> filename;
    addressBook.saveToFile(filename);
}

// �������� ��������� �� �����
void AdminPanel::loadContactsFromFile() {
    std::string filename;
    std::cout << "������� ��� ����� ��� ��������: ";
    std::cin >> filename;
    addressBook.loadFromFile(filename);
}
