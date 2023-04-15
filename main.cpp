#include "header.h"
int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice = 0, choiceadm = 0;
    bool user = false, admin = false;
    while (user == false && admin == false) {
        cout << "Ваш выбор?" << endl;
        cout << "1. Зарегистрироваться" << endl;
        cout << "2. Войти" << endl;
        cout << "3. Выйти из программы" << endl;
        choice = check(choice);
        switch (choice) {
        case 1: reg();
            break;
        case 2: user = login(user);
            break;
        case 3:return 0;
            break;
        case 1234:
            while (admin == false) {
                cout << "Вы хотите запустить приложение от лица администратора" << endl;
                cout << "Выберите" << endl;
                cout << "1. Зарегистрироваться" << endl;
                cout << "2. Войти" << endl;
                cout << "3. Выйти из программы" << endl;
                choiceadm = check(choiceadm);
                switch (choiceadm) {
                case 1:regadmin();
                    break;
                case 2: admin = loginadmin(admin);
                    break;
                case 3:return 0;
                    break;
                default: cout << "Вы ввели неверное значение!" << endl;
                    break;
                }
            }
            break;
        default: cout << "Вы ввели неверное значение!" << endl;
            break;
        }
    }
    if (user == true) {
        readtable();
        while (1) {
            choice = 0;
            cout << "Выберите, что хотите сделать :" << endl;
            cout << "1. Купить билет" << endl;
            cout << "2. Забронировать билет" << endl;
            cout << "3. Отменить покупку билета" << endl;
            cout << "4. Посмотреть мои купленные билеты" << endl;
            cout << "5. Отсортировать рейсы по времени отправки" << endl;
            cout << "6. Сортировать список товаров по кэшбэку" << endl;
            cout << "7. Изменить свой логин/пароль" << endl;
            cout << "8. Выйти из программы" << endl;
            choice = check(choice);
            switch (choice) {
            case 1:buy();
                break;
            case 2:break;
            case 3:break;
            case 4:showticket();
                break;
            case 5:break;
            case 6:break;
            case 7:changeuser();
                break;
            case 8:return 0;
                break;
            default: cout << "Вы ввели неверное значение!" << endl;
                break;
            }
        }
    }
    else if (admin == true) {
        while (1) {
            choiceadm = 0;
            cout << "Выберите, что хотите сделать :" << endl;
            cout << "1. Удалить пользователя" << endl;
            cout << "2. Редактировать таблицу с товарами и банками" << endl;
            cout << "3. Изменить список магазинов партнеров банка" << endl;
            cout << "4. Изменить свой логин/пароль" << endl;
            cout << "5. Выйти из программы" << endl;
            choiceadm = check(choiceadm);
            switch (choiceadm) {
            case 1:
                break;
            case 2:
                break;
            case 3:break;
            case 4:changeadmin();
                break;
            case 5: return 0;
                break;
            default: cout << "Вы ввели неверное значение!" << endl;
                break;
            }
        }
    }
    return 0;
}