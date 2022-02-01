/**
*File: 01-hw-invoice
*Author: Mila Gmerek
*Date: 1/26/2022
*Brief: Program that processes computer monitor orders for homework #1
*
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()

{
    cout << fixed << setprecision(2);
    cout << "Enter monitor type, s or v, followed by quantity: ";
    string monitor;
    int quantity;
    cin >> monitor >> quantity;

    double monitor_price;
    if (monitor == "s")
    {
        monitor_price = 190;
    }
    else if (monitor == "v")
    {
        monitor_price = 170;
    }

    double final_price;
    final_price = monitor_price * quantity; // calculates price before taxes and/or discounts 

    double discount_price;
    discount_price = final_price - (final_price * 0.05); // discount_price is the total after discount has been subtracted 
    double total_price;

    cout << "Do you live in Ohio? (yes or no): " << endl;
    string resident;
    cin >> resident;
    double tax_price;
    const double OHIO_TAX = 0.07; 
    tax_price = (monitor_price * quantity * OHIO_TAX); // calculates the added tax
    double discounted_final_price;

    if (quantity >= 3)
    {
        if (resident == "yes")
        {
            discounted_final_price = discount_price + tax_price; // if discount and tax are applicable 
        }
        if (resident == "no")
        {
            discounted_final_price = discount_price; // only discount is applicable 
        }
    }

    if (quantity < 3)
    {
        if (resident == "no")
        {
            total_price = final_price; // no tax or discount applicable 
        }
        if (resident == "yes") // tax, but no discount
        {
            total_price = final_price + tax_price;
        }
    }

    cout << "-------------------------" << endl;
    cout << "Monitor type: " << monitor << endl;
    cout << "Quantity in order: " << quantity << endl;
    cout << "Price per monitor: $" << monitor_price << endl;
    cout << "Ohio Resident? " << resident << endl;
    if (quantity >= 3)
    {
        cout << "Discount: $" << (monitor_price * quantity) * (.05) << endl; // calculating prices with necessary information
    }
    else
    {
        cout << "Discount: $0.00" << endl;
    }
    if (resident == "yes")  // displays resident status based on user input 
    {
        cout << "Tax amount: $" << tax_price << endl;
    }
    if (resident == "no")
    {
        cout << "Tax amount: $0.00" << endl;
    }
    cout << "---------------------------" << endl;

    if (quantity >= 3)
    {
        if (resident == "yes")
        {
            cout << "Total: $" << discount_price + tax_price << endl; // displays subtotal based on taxes or discounts if applicable
        }

        if (resident == "no")
        {
            cout << "Total: $" << discounted_final_price << endl ;
        }
    }
    if (quantity < 3)
    {
        if (resident == "no")
        {
            cout << "Total: $" << final_price << endl;
        }
        if (resident == "yes")
        {
            cout << "Total: $" << total_price << endl;
        }
    }
    return 0;
}