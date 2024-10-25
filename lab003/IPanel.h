// IPanel.h - ��������� ��� �������
#ifndef IPANEL_H
#define IPANEL_H

class IPanel {
public:
    virtual ~IPanel() = default;

    // ����������� ������� ��� ����������� ����
    virtual void displayMenu() = 0;
    virtual void loadContactsFromFile() = 0;
};

#endif // IPANEL_H
