// IPanel.h - интерфейс для панелей
#ifndef IPANEL_H
#define IPANEL_H

class IPanel {
public:
    virtual ~IPanel() = default;

    // Виртуальные функции для отображения меню
    virtual void displayMenu() = 0;
    virtual void loadContactsFromFile() = 0;
};

#endif // IPANEL_H
