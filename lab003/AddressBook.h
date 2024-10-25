#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include <string>
#include "Contact.h"

class AddressBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact();
    void editContact();
    void deleteContact();
    void searchContact() const;
    void displayContacts() const;

    // Новые методы для работы с файлами
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // ADDRESSBOOK_H
