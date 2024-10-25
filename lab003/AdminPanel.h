#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <string>
#include "AddressBook.h"
#include "IPanel.h"
#include "AddressBookInterface.h"

class AdminPanel : public IPanel, public AddressBookInterface {
private:
    AddressBook& addressBook;

public:
    AdminPanel(AddressBook& addressBook);
    void displayMenu() override;
    void addContact() override;
    void editContact() override;
    void deleteContact() override;
    void viewContacts() const override;
    void searchContacts() const override;
    void saveContactsToFile() const override;
    void loadContactsFromFile() override;
};

#endif // ADMINPANEL_H
