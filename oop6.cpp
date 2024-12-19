#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// Define the Person record
struct Person {
    string name;
    string birthDate; // Format: YYYY-MM-DD
    string telephoneNo;

    // For sorting based on name
    bool operator<(const Person& other) const {
        return name < other.name;
    }
};

// Define the Item record
struct Item {
    string itemCode;
    string itemName;
    int quantity;
    double cost;

    // For sorting based on item code
    bool operator<(const Item& other) const {
        return itemCode < other.itemCode;
    }
};

// Function to display person records
void displayPersons(const vector<Person>& persons) {
    cout << setw(20) << "Name" << setw(15) << "Birth Date" << setw(15) << "Telephone" << endl;
    cout << string(50, '-') << endl;
    for (const auto& person : persons) {
        cout << setw(20) << person.name
             << setw(15) << person.birthDate
             << setw(15) << person.telephoneNo << endl;
    }
}

// Function to display item records
void displayItems(const vector<Item>& items) {
    cout << setw(10) << "Code" << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Cost" << endl;
    cout << string(60, '-') << endl;
    for (const auto& item : items) {
        cout << setw(10) << item.itemCode
             << setw(20) << item.itemName
             << setw(10) << item.quantity
             << setw(10) << fixed << setprecision(2) << item.cost << endl;
    }
}

// Function to search for a person by name
void searchPerson(const vector<Person>& persons, const string& name) {
    auto it = find_if(persons.begin(), persons.end(), [&name](const Person& p) {
        return p.name == name;
    });
    if (it != persons.end()) {
        cout << "Person found: " << it->name << ", " << it->birthDate << ", " << it->telephoneNo << endl;
    } else {
        cout << "Person not found." << endl;
    }
}

// Function to search for an item by item code
void searchItem(const vector<Item>& items, const string& itemCode) {
    auto it = find_if(items.begin(), items.end(), [&itemCode](const Item& i) {
        return i.itemCode == itemCode;
    });
    if (it != items.end()) {
        cout << "Item found: " << it->itemName << ", Quantity: " << it->quantity << ", Cost: " << it->cost << endl;
    } else {
        cout << "Item not found." << endl;
    }
}

int main() {

    vector<Person> persons;
    vector<Item> items;

    // Add some sample records
    persons.push_back({"Alice Smith", "1990-05-15", "123-456-7890"});
    persons.push_back({"Bob Johnson", "1985-08-20", "234-567-8901"});
    persons.push_back({"Charlie Brown", "1992-03-30", "345-678-9012"});

    items.push_back({"A001", "Laptop", 10, 999.99});
    items.push_back({"A002", "Smartphone", 15, 599.99});
    items.push_back({"B001", "Headphones", 25, 79.99});

    // Sorting
    sort(persons.begin(), persons.end());
    sort(items.begin(), items.end());

    // Display sorted records
    cout << "Sorted Persons:" << endl;
    displayPersons(persons);
    cout << endl;

    cout << "Sorted Items:" << endl;
    displayItems(items);
    cout << endl;

    // Search for a person
    string searchName;
    cout << "Enter a name to search for a person: ";
    getline(cin, searchName);
    searchPerson(persons, searchName);
    cout << endl;

    // Search for an item
    string searchCode;
    cout << "Enter an item code to search for an item: ";
    getline(cin, searchCode);
    searchItem(items, searchCode);

    return 0;
}
