#include "header.h"
int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice = 0, choiceadm = 0;
    bool user = false, admin = false;
    while (user == false && admin == false) {
        cout << "��� �����?" << endl;
        cout << "1. ������������������" << endl;
        cout << "2. �����" << endl;
        cout << "3. ����� �� ���������" << endl;
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
                cout << "�� ������ ��������� ���������� �� ���� ��������������" << endl;
                cout << "��������" << endl;
                cout << "1. ������������������" << endl;
                cout << "2. �����" << endl;
                cout << "3. ����� �� ���������" << endl;
                choiceadm = check(choiceadm);
                switch (choiceadm) {
                case 1:regadmin();
                    break;
                case 2: admin = loginadmin(admin);
                    break;
                case 3:return 0;
                    break;
                default: cout << "�� ����� �������� ��������!" << endl;
                    break;
                }
            }
            break;
        default: cout << "�� ����� �������� ��������!" << endl;
            break;
        }
    }
    if (user == true) {
        readtable();
        while (1) {
            choice = 0;
            cout << "��������, ��� ������ ������� :" << endl;
            cout << "1. ������ �����" << endl;
            cout << "2. ������������� �����" << endl;
            cout << "3. �������� ������� ������" << endl;
            cout << "4. ���������� ��� ��������� ������" << endl;
            cout << "5. ������������� ����� �� ������� ��������" << endl;
            cout << "6. ����������� ������ ������� �� �������" << endl;
            cout << "7. �������� ���� �����/������" << endl;
            cout << "8. ����� �� ���������" << endl;
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
            default: cout << "�� ����� �������� ��������!" << endl;
                break;
            }
        }
    }
    else if (admin == true) {
        while (1) {
            choiceadm = 0;
            cout << "��������, ��� ������ ������� :" << endl;
            cout << "1. ������� ������������" << endl;
            cout << "2. ������������� ������� � �������� � �������" << endl;
            cout << "3. �������� ������ ��������� ��������� �����" << endl;
            cout << "4. �������� ���� �����/������" << endl;
            cout << "5. ����� �� ���������" << endl;
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
            default: cout << "�� ����� �������� ��������!" << endl;
                break;
            }
        }
    }
    return 0;
}