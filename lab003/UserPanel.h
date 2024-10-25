#ifndef USERPANEL_H
#define USERPANEL_H

#include <string>
#include "AddressBook.h"
#include "IPanel.h"  // Предполагаем, что IPanel объявлен

class UserPanel : public IPanel {
private:
    AddressBook& addressBook;

public:
    // Конструктор UserPanel, принимающий ссылку на AddressBook
    explicit UserPanel(AddressBook& addressBook);

    // Реализация виртуального метода для отображения меню
    void displayMenu() override;

    // Метод для просмотра контактов (переопределение из IPanel)
    void viewContacts() const override;

    // Метод для поиска контактов (переопределение из IPanel)
    void searchContacts() const override;

    // Пустая реализация addContact, поскольку пользователи не могут добавлять контакты
    void addContact() override {
        // Оставлено пустым, так как пользователи не имеют прав на добавление
    }
};

#endif // USERPANEL_H
