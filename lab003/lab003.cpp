// main.cpp
#include <iostream>
#include <memory>
#include <string>
#include "AddressBook.h"
#include "AdminPanel.h"
#include "UserPanel.h"
#include "IPanel.h"

using namespace std;

// Логин пользователя
bool login(bool& isAdmin) {
    string username, password;
    cout << "Введите имя пользователя: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;

    if (username == "admin" && password == "adminpass") {
        isAdmin = true;
        return true;
    }
    else if (username == "user" && password == "userpass") {
        isAdmin = false;
        return true;
    }
    else {
        cout << "Неверные имя пользователя или пароль. Попробуйте снова.\n";
        return false;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    AddressBook addressBook;
    bool isAdmin = false;

    // Цикл для входа в систему
    while (!login(isAdmin)) { /* Повторяем, пока не удастся войти */ }

    // Умный указатель для панели
    unique_ptr<IPanel> panel;

    // Создаем панель на основе роли пользователя
    if (isAdmin) {
        panel = make_unique<AdminPanel>(addressBook);
    }
    else {
        panel = make_unique<UserPanel>(addressBook);
    }

    // Используем полиморфизм для вызова нужного меню
    panel->displayMenu();

    return 0;
}
