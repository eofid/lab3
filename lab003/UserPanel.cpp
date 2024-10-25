// UserPanel.cpp
#include "UserPanel.h"
#include <iostream>

// �����������
UserPanel::UserPanel(AddressBook& addressBook) : addressBook(addressBook) {}

// ������� ���� ������������
void UserPanel::displayMenu() {
    int choice;
    do {
        std::cout << "\n---- ������ ������������ ----\n";
        std::cout << "1. ����������� ��������\n";
        std::cout << "2. ����� �������\n";
        std::cout << "3. ��������� �������� �� �����\n";  // ����� ����� ����
        std::cout << "4. �����\n";
        std::cout << "������� ��� �����: ";
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
            std::cout << "����� �� ������ ������������.\n";
            break;
        default:
            std::cout << "�������� �����. ����������, ���������� �����.\n";
        }
    } while (choice != 4);
}

// ���������� �������� ��������� �� �����
void UserPanel::loadContactsFromFile() {
    std::string filename;
    std::cout << "������� ��� ����� ��� ��������: ";
    std::cin >> filename;
    addressBook.loadFromFile(filename);
    std::cout << "�������� ������� ���������.\n";
}

// �������� ���� ���������
void UserPanel::viewContacts() const {
    addressBook.displayContacts();
}

// ����� ���������
void UserPanel::searchContacts() const {
    addressBook.searchContact();
}
