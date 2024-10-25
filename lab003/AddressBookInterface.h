#ifndef ADDRESSBOOKINTERFACE_H
#define ADDRESSBOOKINTERFACE_H

#include <string>

class AddressBookInterface {
public:
    virtual ~AddressBookInterface() = default;

    virtual void addContact() = 0;
    virtual void editContact() = 0;
    virtual void deleteContact() = 0;
    virtual void viewContacts() const = 0;
    virtual void searchContacts() const = 0;
    virtual void loadContactsFromFile() = 0;
    virtual void saveContactsToFile() const = 0;
};

#endif // ADDRESSBOOKINTERFACE_H
