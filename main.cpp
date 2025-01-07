#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Maximum number of products
const int MAX_PRODUCTS = 100;

// Inventory data
int productIDs[MAX_PRODUCTS];
string productNames[MAX_PRODUCTS];
float productPrices[MAX_PRODUCTS];
int productQuantities[MAX_PRODUCTS];
int productCount = 0;

// Function prototypes
void initializeInventory();
void displayProducts();
void addInventory();
void updateInventory();
void deleteInventory();
void searchInventory();
void displayMenu();
void calculateTotalInventoryValue();

int main() {
    initializeInventory();

    char choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle trailing newline

        switch (toupper(choice)) {
            case 'A':
                addInventory();
                break;
            case 'U':
                updateInventory();
                break;
            case 'D':
                deleteInventory();
                break;
            case 'S':
                searchInventory();
                break;
            case 'V':
                displayProducts();
                calculateTotalInventoryValue();
                break;
            case 'Q':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (toupper(choice) != 'Q');

    return 0;
}

// Initialize inventory with given products
void initializeInventory() {
    productIDs[productCount] = 1;
    productNames[productCount] = "Pen";
    productPrices[productCount] = 15;
    productQuantities[productCount] = 10;
    productCount++;

    productIDs[productCount] = 2;
    productNames[productCount] = "Pencil";
    productPrices[productCount] = 20;
    productQuantities[productCount] = 50;
    productCount++;

    productIDs[productCount] = 3;
    productNames[productCount] = "Books";
    productPrices[productCount] = 50;
    productQuantities[productCount] = 200;
    productCount++;
}

// Display menu
void displayMenu() {
    cout << "\n=== Inventory Management System ===\n";
    cout << "Inventory Add ........... A\n";
    cout << "Inventory Update ........ U\n";
    cout << "Inventory Delete ........ D\n";
    cout << "Inventory Search ........ S\n";
    cout << "View All Products ....... V\n";
    cout << "Quit .................... Q\n";
    cout << "===================================\n";
}

// Display all products in a table
void displayProducts() {
    cout << "\n=== Product Inventory ===\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Quantity"
         << setw(15) << "Total Value" << endl;
    cout << string(65, '-') << endl;

    for (int i = 0; i < productCount; i++) {
        float totalValue = productPrices[i] * productQuantities[i];
        cout << left << setw(10) << productIDs[i]
             << setw(20) << productNames[i]
             << setw(10) << fixed << setprecision(2) << productPrices[i]
             << setw(10) << productQuantities[i]
             << setw(15) << totalValue << endl;
    }
    cout << string(65, '-') << endl;
}

// Add a new product to the inventory
void addInventory() {
    if (productCount >= MAX_PRODUCTS) {
        cout << "Inventory is full. Cannot add more products.\n";
        return;
    }

    productIDs[productCount] = productCount + 1;

    cout << "Enter product name: ";
    getline(cin, productNames[productCount]);

    cout << "Enter product price: ";
    cin >> productPrices[productCount];

    cout << "Enter product quantity: ";
    cin >> productQuantities[productCount];
    cin.ignore(); // To handle trailing newline

    productCount++;
    cout << "Product added successfully!\n";
}

// Update an existing product
void updateInventory() {
    string name;
    cout << "Enter the product name to update: ";
    getline(cin, name);

    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name) {
            cout << "Enter new price: ";
            cin >> productPrices[i];

            cout << "Enter new quantity: ";
            cin >> productQuantities[i];
            cin.ignore(); // To handle trailing newline

            cout << "Product updated successfully!\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Delete a product by ID
void deleteInventory() {
    string name;
    cout << "Enter the product name to delete: ";
    getline(cin, name);

    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name) {
            for (int j = i; j < productCount - 1; j++) {
                productNames[j] = productNames[j + 1];
                productPrices[j] = productPrices[j + 1];
                productQuantities[j] = productQuantities[j + 1];
            }
            productCount--;
            cout << "Product deleted successfully!\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Search for a product by ID
void searchInventory() {
    string name;
    cout << "Enter the product name to search: ";
    getline(cin, name);

    for (int i = 0; i < productCount; i++) {
        if (productNames[i] == name) {
            cout << "Product found:\n";
            cout << "Name: " << productNames[i] << "\n";
            cout << "Price: $" << fixed << setprecision(2) << productPrices[i] << "\n";
            cout << "Quantity: " << productQuantities[i] << "\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

// Calculate the total value of all inventory
void calculateTotalInventoryValue() {
    float totalValue = 0;

    for (int i = 0; i < productCount; i++) {
        totalValue += productPrices[i] * productQuantities[i];
    }

    cout << "Total inventory value: $" << fixed << setprecision(2) << totalValue << "\n";
}



