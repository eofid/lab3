#ifndef USERPANEL_H
#define USERPANEL_H

#include <string>
#include "AddressBook.h"
#include "IPanel.h"
#include "AddressBookInterface.h"

class UserPanel : public IPanel, public AddressBookInterface {
private:
    AddressBook& addressBook;

public:
    UserPanel(AddressBook& addressBook);
    void displayMenu() override;
    void viewContacts() const override;
    void searchContacts() const override;
    void loadContactsFromFile() override;

    // Пустые реализации для методов, которые не нужны пользователю
    void addContact() override {}
    void editContact() override {}
    void deleteContact() override {}
    void saveContactsToFile() const override {}
};

#endif // USERPANEL_H
