#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class PhoneRecord {
protected:
    string last_name;
    string first_name;
    string middle_name;
    string address;
    string phone;

public:
    PhoneRecord(string last, string first, string middle, string addr, string ph)
        : last_name(last), first_name(first), middle_name(middle), address(addr), phone(ph) {}

    virtual ~PhoneRecord() {}

    virtual void display_info() {
        cout << "Last Name: " << last_name << endl;
        cout << "First Name: " << first_name << endl;
        cout << "Middle Name: " << middle_name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

class SpecializedRecord : public PhoneRecord {
private:
    string email;
    string profession;

public:
    SpecializedRecord(string last, string first, string middle, string addr, string ph, string em, string pro)
        : PhoneRecord(last, first, middle, addr, ph), email(em), profession(pro) {}

    void display_info() override {
        PhoneRecord::display_info();
        cout << "Email: " << email << endl;
        cout << "Profession: " << profession << endl;
    }
};

class PhoneDirectory {
private:
    vector<PhoneRecord*> records;

public:
    ~PhoneDirectory() {
        for (auto record : records) {
            delete record;
        }
    }

    void add_record(PhoneRecord* record) {
        records.push_back(record);
    }

    void remove_record(PhoneRecord* record) {
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (*it == record) {
                records.erase(it);
                delete record;
                break;
            }
        }
    }

    void display_records() {
        for (auto record : records) {
            record->display_info();
            cout << endl;
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);

    string last_name, first_name, middle_name, address, phone, email, profession;
    char choice;
    PhoneDirectory directory;

    do {
        cout << "¬вед≥ть ваше пр≥звище: ";
        getline(cin, last_name);

        cout << "¬вед≥ть ваше iм'€: ";
        getline(cin, first_name);

        cout << "¬вед≥ть ваше ≥м'€ по батьков≥: ";
        getline(cin, middle_name);

        cout << "¬вед≥ть вашу адресу: ";
        getline(cin, address);

        cout << "¬вед≥ть св≥й номер телефону: ";
        getline(cin, phone);

        cout << "¬вед≥ть ваш емейл: ";
        getline(cin, email);

        cout << "¬аша профес≥€: ";
        getline(cin, profession);

        SpecializedRecord* record = new SpecializedRecord(last_name, first_name, middle_name, address, phone, email, profession);
        directory.add_record(record);

        cout << "ѕочати ще раз?) (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (choice == 'y' || choice == 'Y');

    cout << "Phone Directory:" << endl;
    directory.display_records();

    return 0;
}
