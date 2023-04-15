#include "header.h"
ifstream fin;
ofstream fout;
struct journey {
    int number;
    int cost;
    struct time {
        int day;
        int month;
        int year;
        int hours;
        int minutes;
    }time;
    int freeplaces;
    string from;
    string to;
}train[80];
int tickets[80];
int koluser, koladm, koltr;
string username[80], userpass[80], admname[80], admpass[80];
string curuserlogin, curuserpass, curadmlogin, curadmpass;
extern void zapis() {
    int i = 0;
    fout.open("table.txt");
    fout << koltr << endl;
    while (i < koltr) {
        fout << train[i].number<< "\t";
        fout << train[i].from <<" "<< train[i].to<<" ";
        fout << train[i].cost<<" ";
        fout << train[i].freeplaces<<" ";
        fout << train[i].time.day << " " << train[i].time.month << " " << train[i].time.year << " " << train[i].time.hours << " " << train[i].time.hours<<endl;
        i++;
    }
    fin.close();
}
extern int check(int a) {
    while (!(cin >> a)) {
        cin.clear();
        cin.ignore(1025, '\n');
        cout << "Вы ввели неверное значение" << endl;
    }
    return a;
}
extern void reg() {
    char login[80], password[100];
    int i, j;
    cout << "Введите логин" << endl;
    cin >> login;
    cout << "Введите пароль" << endl;
    cin >> password;
    fout.open("users.txt", ofstream::app);
    fout << login << "\t";
    for (i = 0, j = 0; i < strlen(password); i++, j = j + 6) {
        if (j % 5 == 1) fout << password[i] - (char)j + (char)i;
        else fout << password[i] - (char)i + (char)j;
    }
    fout << endl;
    cout << "Вы были успешно зарегистрированы!" << endl;
    fout.close();
}
extern bool login(bool a) {
    char login[80], password[100], ch_login[80], ch_password[100];
    int found = 0, i, j;
    cout << "Введите логин" << endl;
    cin >> login;
    cout << "Введите пароль" << endl;
    cin >> password;
    fout.open("zap.txt");
    for (i = 0, j = 0; i < strlen(password); i++, j = j + 6) {
        if (j % 5 == 1) fout << password[i] - (char)j + (char)i;
        else fout << password[i] - (char)i + (char)j;
    }
    fout.close();
    fin.open("zap.txt");
    fin >> password;
    fin.close();
    curuserpass = password;
    curuserlogin = login;
    fin.open("users.txt");
    koluser = 0;
    fin.seekg(0, ios::beg);
    while (!fin.eof())
    {
        fin >> username[koluser];
        fin >> userpass[koluser];
        if (curuserpass.compare(userpass[koluser]) == 0 && curuserlogin.compare(username[koluser]) == 0) found++;
        koluser++;
    }
    koluser--;
    if (found != 0) {
        cout << "Вы вошли как : " << curuserlogin << endl;
        a = true;
    }
    else
        cout << "Вы ввели неверный логин или пароль" << endl;
    fin.close();
    return a;
}
void regadmin() {
    char login[80], password[100];
    int i, j;
    cout << "Введите логин" << endl;
    cin >> login;
    cout << "Введите пароль" << endl;
    cin >> password;
    fout.open("admins.txt", ofstream::app);
    fout << login << "\t";
    for (i = 0, j = 0; i < strlen(password); i++, j = j + 6) {
        if (j % 5 == 1) fout << password[i] - (char)j + (char)i;
        else fout << password[i] - (char)i + (char)j;
    }
    fout << endl;
    cout << "Вы были успешно зарегистрированы!" << endl;
    fout.close();
};
extern bool loginadmin(bool b) {
    char login[80], password[100], ch_login[80], ch_password[80];
    int found = 0, i, j;
    cout << "Введите логин" << endl;
    cin >> login;
    cout << "Введите пароль" << endl;
    cin >> password;
    fout.open("zap.txt");
    for (i = 0, j = 0; i < strlen(password); i++, j = j + 6) {
        if (j % 5 == 1) fout << password[i] - (char)j + (char)i;
        else fout << password[i] - (char)i + (char)j;
    }
    fout.close();
    fin.open("zap.txt");
    fin >> password;
    fin.close();
    curadmpass = password;
    curadmlogin = login;
    fin.open("admins.txt");
    fin.seekg(0, ios::beg);
    koladm = 0;
    while (!fin.eof())
    {
        fin >> admname[koladm];
        fin >> admpass[koladm];
        if (curadmpass.compare(admpass[koladm]) == 0
            && curadmlogin.compare(admname[koladm]) == 0)
        {
            found++;
        }
        koladm++;
    }
    koladm--;
    if (found != 0) {
        cout << "Вы вошли как : " << curadmlogin << endl;
        b = true;
    }
    else
        cout << "Вы ввели неверный логин или пароль" << endl;
    fin.close();
    return b;
}
extern void readtable() {
    int i = 0;
    fin.open("table.txt");
    fin >> koltr;
    while (i < koltr) {
        fin >> train[i].number;
        fin >> train[i].from >> train[i].to;
        fin >> train[i].cost;
        fin >> train[i].freeplaces;
        fin >> train[i].time.day >> train[i].time.month >> train[i].time.year >> train[i].time.hours >> train[i].time.minutes;
        i++;
    }
    fin.close();
}
extern void buy() {
    if (koltr == 0) {
        cout << "Извините на настоящий момент рейсов нет" << endl;
    }
    else {
        system("CLS");
        cout << "Выберите номер рейса который хотите приобрести" << endl;
        for (int i = 0; i < koltr; i++) {
            cout << train[i].number << "\t" << train[i].from << "-" << train[i].to << "\t" << train[i].cost << " руб." <<"\t"<< train[i].freeplaces << " мест" <<"\t"<< train[i].time.day << "." << train[i].time.month << "." << train[i].time.year << "\t" << train[i].time.hours << ":" << train[i].time.minutes << endl;
        }
        int choice = 0;
        choice = check(choice);
        cout << "Выберите количество билетов которые хотите купить" << endl;
        int kol = 0;
        kol = check(kol);
        int k=0, i = 0;
        for (i = 0; i < koltr; i++) {
            if (choice == train[i].number) {
                k++;
                train[i].freeplaces-=kol;
                break;
            }
        }
        if (k == 0) {
            cout << "Такого поезда нет" << endl;
        }
        else {
            cout << "Вы приобрели билет на поезд номер " << choice << " в количестве "<< kol << endl;
            fout.open("tickets.txt", ofstream::app);
            fout << curuserlogin << "\t" << train[i].number <<"\t"<< kol << endl;
            fout.close();
        }
    }
    zapis();
}

extern void showticket() {

}
extern void changeadmin() {
    string newlog;
    char newpass[80];
    cout << "Введите новый логин и пароль" << endl;
    cin >> newlog >> newpass;
    fout.open("zap.txt");
    for (int i = 0, j = 0; i < strlen(newpass); i++, j = j + 6) {
        if (j % 5 == 1) fout << newpass[i] - (char)j + (char)i;
        else fout << newpass[i] - (char)i + (char)j;
    }
    fout.close();
    fin.open("zap.txt");
    fin >> newpass;
    fin.close();
    string newpassword = newpass;
    for (int i = 0; i < koladm; i++) {
        if (curadmpass.compare(admpass[i]) == 0
            && curadmlogin.compare(admname[i]) == 0) {
            admpass[i] = newpassword;
            admname[i] = newlog;
            break;
        }
    }
    fout.open("admins.txt");
    for (int i = 0; i < koladm; i++) {
        fout << admname[i] << "\t" << admpass[i] << endl;
    }
    fout.close();
    cout << "Данные об аккаунте были изменены!" << endl;
}
extern void changeuser() {
    string newlog;
    char newpass[80];
    cout << "Введите новый логин и пароль" << endl;
    cin >> newlog >> newpass;
    fout.open("zap.txt");
    for (int i = 0, j = 0; i < strlen(newpass); i++, j = j + 6) {
        if (j % 5 == 1) fout << newpass[i] - (char)j + (char)i;
        else fout << newpass[i] - (char)i + (char)j;
    }
    fout.close();
    fin.open("zap.txt");
    fin >> newpass;
    fin.close();
    string newpassword = newpass;
    for (int i = 0; i < koluser; i++) {
        if (curuserpass.compare(userpass[i]) == 0
            && curuserlogin.compare(username[i]) == 0) {
            userpass[i] = newpassword;
            username[i] = newlog;
            break;
        }
    }
    fout.open("users.txt");
    for (int i = 0; i < koluser; i++) {
        fout << username[i] << "\t" << userpass[i] << endl;
    }
    fout.close();
    cout << "Данные об аккаунте были изменены!" << endl;
}