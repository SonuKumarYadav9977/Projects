#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Utility function to generate a unique Invoice ID
string generateInvoiceID() {
    srand(time(0));
    return "INV-" + to_string(rand() % 10000 + 1000);
}

// Class to handle Product details
class Product {
public:
    string name;
    int quantity;
    double price;

    Product(string n, int q, double p) {
        name = n;
        quantity = q;
        price = p;
    }

    double getTotalPrice() {
        return quantity * price;
    }
};

// Class to store Customer details
class Customer {
public:
    string name;
    string contact;

    void inputCustomerDetails() {
        cout << "\nEnter Customer Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Customer Contact: ";
        getline(cin, contact);
    }
};

// Class for Invoice
class Invoice {
private:
    vector<Product> products;
    Customer customer;
    double taxRate;
    double discount;
    string invoiceID;

public:
    Invoice(double tax, double disc) {
        taxRate = tax;
        discount = disc;
        invoiceID = generateInvoiceID();
    }

    void addProduct(string name, int quantity, double price) {
        products.push_back(Product(name, quantity, price));
    }

    void generateInvoice() {
        double subtotal = 0;

        cout << "\n======================================";
        cout << "\n            BUSINESS INVOICE";
        cout << "\n======================================";
        cout << "\nInvoice ID: " << invoiceID;
        cout << "\nCustomer: " << customer.name;
        cout << "\nContact: " << customer.contact;
        cout << "\n--------------------------------------";
        cout << "\nItem          Qty   Price   Total";
        cout << "\n--------------------------------------";

        for (auto &p : products) {
            double totalPrice = p.getTotalPrice();
            subtotal += totalPrice;
            cout << "\n" << setw(12) << left << p.name
                 << setw(5) << right << p.quantity
                 << setw(8) << fixed << setprecision(2) << p.price
                 << setw(8) << totalPrice;
        }

        double discountAmount = subtotal * discount / 100;
        double taxAmount = (subtotal - discountAmount) * taxRate / 100;
        double totalAmount = subtotal - discountAmount + taxAmount;

        cout << "\n--------------------------------------";
        cout << "\nSubtotal:        $" << fixed << setprecision(2) << subtotal;
        cout << "\nDiscount (" << discount << "%): -$" << discountAmount;
        cout << "\nTax (" << taxRate << "%):      $" << taxAmount;
        cout << "\nTotal:           $" << totalAmount;
        cout << "\n======================================\n";

        saveInvoiceToFile(subtotal, discountAmount, taxAmount, totalAmount);
    }

    void saveInvoiceToFile(double subtotal, double discountAmount, double taxAmount, double totalAmount) {
        ofstream file("invoice_history.txt", ios::app);
        if (!file) {
            cout << "Error saving invoice!";
            return;
        }
        file << "======================================\n";
        file << "Invoice ID: " << invoiceID << "\n";
        file << "Customer: " << customer.name << "\n";
        file << "Contact: " << customer.contact << "\n";
        file << "--------------------------------------\n";
        file << "Item          Qty   Price   Total\n";
        for (auto &p : products) {
            file << left << setw(12) << p.name
                 << setw(5) << right << p.quantity
                 << setw(8) << fixed << setprecision(2) << p.price
                 << setw(8) << p.getTotalPrice() << "\n";
        }
        file << "--------------------------------------\n";
        file << "Subtotal:        $" << fixed << setprecision(2) << subtotal << "\n";
        file << "Discount (" << discount << "%): -$" << discountAmount << "\n";
        file << "Tax (" << taxRate << "%):      $" << taxAmount << "\n";
        file << "Total:           $" << totalAmount << "\n";
        file << "======================================\n\n";
        file.close();
        cout << "Invoice saved successfully!\n";
    }

    void setCustomer(Customer c) {
        customer = c;
    }
};

int main() {
    double taxRate, discount;
    cout << "Enter tax rate (%): ";
    cin >> taxRate;
    cout << "Enter discount rate (%): ";
    cin >> discount;

    Invoice invoice(taxRate, discount);

    Customer customer;
    customer.inputCustomerDetails();
    invoice.setCustomer(customer);

    char choice;
    do {
        string name;
        int quantity;
        double price;

        cout << "\nEnter item name: ";
        cin >> name;
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price per unit: ";
        cin >> price;

        invoice.addProduct(name, quantity, price);

        cout << "Do you want to add another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    invoice.generateInvoice();

    return 0;
}
