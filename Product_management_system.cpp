
// Product Management System
//Developed by Sohail Ahmad

#include <iostream>
#include <string>
using namespace std;

// --- Product Class ---
class Product {
public:
    int productId;
    string productName;
    int price;

    friend istream& operator>>(istream& input, Product& product) {
        cout << "Enter Product ID: ";
        input >> product.productId;
        input.ignore();
        cout << "Enter Product Name: ";
        getline(input, product.productName);
        cout << "Enter Product Price: ";
        input >> product.price;
        return input;
    }

    friend ostream& operator<<(ostream& out, const Product& obj) {
        out << "Product ID: " << obj.productId << endl;
        out << "Product Name: " << obj.productName << endl;
        out << "Price: " << obj.price << endl;
        return out;
    }
};

// --- Global Product Data Store ---
static Product productList[1000]; 
static int CURRENT = 0;

// --- Core Functions ---
void insert(Product product) {
    productList[CURRENT++] = product;
}

void viewProducts() {
    cout << "\nProduct ID\tProduct Name\tPrice" << endl;
    for (int i = 0; i < CURRENT; i++) {
        cout << productList[i].productId << "\t\t" << productList[i].productName << "\t\t" << productList[i].price << endl;
    }
}

Product searchProduct(int productId) {
    for (int i = 0; i < CURRENT; i++) {
        if (productList[i].productId == productId) {
            return productList[i];
        }
    }
    Product notFound;
    notFound.productId = 0;
    return notFound;
}

void deleteProduct(int productId) {
    int pos = -1;
    for (int i = 0; i < CURRENT; i++) {
        if (productList[i].productId == productId) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < CURRENT - 1; i++) {
            productList[i] = productList[i + 1];
        }
        CURRENT--;
        cout << "Product deleted successfully.\n";
    } else {
        cout << "Product not found.\n";
    }
}

int updateProduct(int productId, Product product) {
    for (int i = 0; i < CURRENT; i++) {
        if (productList[i].productId == productId) {
            productList[i] = product;
            return 1;
        }
    }
    return 0;
}

// --- Main Program ---
int main() {
    int choice = 10;

    while (true) {
        while (choice == 10) {
            cout << "\t\t\t******" << endl;
            cout << "\t\t\t1 To Insert" << endl;
            cout << "\t\t\t2 To View" << endl;
            cout << "\t\t\t3 To Search" << endl;
            cout << "\t\t\t4 To Delete" << endl;
            cout << "\t\t\t5 To Update" << endl;
            cout << "\t\t\t6 To Exit" << endl;
            cout << "\t\t\t******" << endl;
            cout << "Your Choice: ";
            cin >> choice;
        }

        while (choice == 1) {
            Product product;
            cin >> product;
            insert(product);
            cout << "\t\t\t1 More Products\n\t\t\t0 Exit\n\t\t\t10 Main Menu\nYour Choice: ";
            cin >> choice;
        }

        while (choice == 2) {
            viewProducts();
            cout << "\t\t\t0 Exit\n\t\t\t10 Main Menu\nYour Choice: ";
            cin >> choice;
        }

        while (choice == 3) {
            int productId;
            cout << "Enter Product ID to search: ";
            cin >> productId;
            Product product = searchProduct(productId);
            if (product.productId > 0)
                cout << product;
            else
                cout << "No product found.\n";
            cout << "3 Search More Products\n0 Exit\n10 Main Menu\nYour Choice: ";
            cin >> choice;
        }

        while (choice == 4) {
            int productId;
            cout << "Enter Product ID to delete: ";
            cin >> productId;
            deleteProduct(productId);
            cout << "4 Delete More Products\n0 Exit\n10 Main Menu\nYour Choice: ";
            cin >> choice;
        }

        while (choice == 5) {
            int productId;
            cout << "Enter Product ID to update: ";
            cin >> productId;
            Product existing = searchProduct(productId);
            if (existing.productId > 0) {
                cout << "Current Product Info:\n" << existing;
                Product updated;
                cin >> updated;
                updateProduct(productId, updated);
                cout << "Product updated successfully.\n";
            } else {
                cout << "Product not found.\n";
            }
            cout << "5 Update More Products\n0 Exit\n10 Main Menu\nYour Choice: ";
            cin >> choice;
        }

        if (choice == 0 || choice == 6) {
            cout << "\nThank you for using the Product Management System!" << endl;
            cout << "Developed by Sohail Ahmad." << endl;
            cout << "Wishing you a productive and successful day!" << endl;

            break;
        }
    }

    return 0;
}
