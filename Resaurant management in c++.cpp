//This is a restaurant management project.

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
 
class Restaurant {
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    float total_tax;
    int table;
    int item_quantity[12];
    int order_food_item_codes[12];
    Restaurant(int food_item_codes[], string food_item_names[], int food_item_prices[]) {
        int n = 12;
        this->total_tax = 0;
        for (int i = 0; i < n;i++) {
            this->food_item_codes[i] = food_item_codes[i];
            this->food_item_names[i] = food_item_names[i];
            this->food_item_prices[i] = food_item_prices[i];
        }
    }
 
};
 
//  Input data and create instance of Restaurant

Restaurant* storeData() {
    int n = 12;
    int food_item_codes[n], food_item_prices[n];
    string food_item_names[n];
    for (int i = 0; i < n;i++) {
        cout << "Enter Your food code : ";
        cin >> food_item_codes[i];
        cout << "Enter Your food Price : ";
        cin >> food_item_prices[i];
        cout << "Enter Your food Name : ";
        cin.ignore(); // its using for ignoring new line "\n"
        getline(cin, food_item_names[i]);
        cout << food_item_codes[i] << food_item_names[i] << food_item_prices[i] << endl;
    }
    Restaurant* restaurant = new Restaurant(food_item_codes, food_item_names, food_item_prices);
 
    return restaurant;
}
 
 
// Print Full item list

void print_data(Restaurant* myData) {
 
    cout << "\t\t\t\t\tMAKING BILL" << endl;
    cout << "\t\t\t\t\t-----------" << endl;
    cout << "Item Code" << "\t\t\t\t\tItem Name" << "\t\t\t\t\tItem Price" << endl << endl;
    for (int i = 0; i < 12;i++) {
        // cout << "My Data :" << endl;
        cout << myData->food_item_codes[i] << "\t\t\t\t\t" << myData->food_item_names[i] << "\t\t\t\t\t" << myData->food_item_prices[i] << endl;
    }
}
 

 
void print_ordered_items(Restaurant* restaurant, int items) {
    cout << "\t\t\t\t\t Bill Summery" << endl;
    cout << "\t\t\t\t\t -----------" << endl;
    cout << "Table No: " << restaurant->table << endl;
    cout << "Item Code" << "\t\tItem Name" << "\t\t\tItem Price" << "\t\tItem Quantity" << "\t\tTotal Price" << endl << endl;
    int total_amount = 0;
    float tax;
 
    for (int i = 0; i < items; i++) {
        // Searching Item
        // cout<<i<<endl;
        for (int j = 0; j < 12; j++) {
            if (restaurant->order_food_item_codes[i] == restaurant->food_item_codes[j]) {
                total_amount += restaurant->item_quantity[i] * restaurant->food_item_prices[j];
                cout << restaurant->food_item_codes[j] << "\t\t\t" << restaurant->food_item_names[j] << "\t\t" << restaurant->food_item_prices[j] << "\t\t\t" << restaurant->item_quantity[i] << "\t\t\t" << restaurant->item_quantity[i] * restaurant->food_item_prices[j] << endl;
                break;
            }
 
        }
    }
    restaurant->total_tax = float((float(total_amount) / 100) * 5);
    cout << "Tax\t\t\t\t\t\t\t\t\t\t\t\t\t" << restaurant->total_tax << endl;
    cout << "__________________________________________________________________________________________________________________" << endl;
    cout << "Net Total\t\t\t\t\t\t\t\t\t\t\t\t" << restaurant->total_tax + float(total_amount) << " Taka" << endl;
}
// Take Order From User
void take_order(Restaurant* restaurant) {
    int items;
    cout << "Enter Table  No ";
    cin >> restaurant->table;
    cout << "Enter Number of items ";
    cin >> items;
for (int i = 0; i < items; i++)
    {
        cout << "Enter Item " << i + 1 << " Code : ";
        int found_code = 0;
        cin >> restaurant->order_food_item_codes[i];
        
        for (int j = 0; j < 12; j++) {
            if (restaurant->order_food_item_codes[i] == restaurant->food_item_codes[j]) {
                found_code = 1;
            }
        }
        if (found_code == 1) {
            cout << "Enter Item " << i + 1 << " Quantity : ";
            cin >> restaurant->item_quantity[i];
        }else {
            cout<<"Your code is not valid"<<endl;
            i--;
        }
        
    }
 
    print_ordered_items(restaurant, items);
 
}
int main() {
    Restaurant* myData = storeData();
    while (true)
    {
        print_data(myData);
        take_order(myData);
    }
    return 0;
}


