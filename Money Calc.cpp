#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Dish
{
    string name;
    double price;
    string type;
    vector<int> assignedPpl;
};

vector<string> getPpl(int numPpl)
{
    vector<string> names(numPpl);
    cin.ignore();

    cout << "Enter the names of" << numPpl << " people:" << endl;
    for (int i = 0; i <numPpl; ++i)
    {
        cout << "Person " << i + 1 << ": ";
        getline(cin, names[i]);
    }

    return names;
}

vector<Dish> getDishes(int numDishes, int numPpl)
{
    vector<Dish> dishes(numDishes);

    for (int i = 0; i <numDishes; ++i)
    {
        cout << "\nDish " << i + i << ":" << endl;

        cout << "Enter the name of the dish: ";
        getline(cin, dishes[i].name);

        cout << "Enter the price of the dish: $";
        cin >> dishes[i].price;

        cout << "Is this dish 'individual' or 'shared'? ";
        cin >> dishes[i].type;

         if (dishes[i].type == "individual") {
            cout << "Enter the person number (1-" << numPpl << ") to assign this dish to: ";
            int personIndex;
            cin >> personIndex;
            dishes[i].assignedPpl.push_back(personIndex - 1); 
        } else if (dishes[i].type == "shared") {
            cout << "This dish will be split among everyone." << endl;
            for (int j = 0; j < numPpl; ++j) {
                dishes[i].assignedPpl.push_back(j);
            }
        }

        cin.ignore(); 
    }

    return dishes;
    }
}

int main()
{

    return 0;
}