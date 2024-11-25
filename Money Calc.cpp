#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

    void displaySummary(const vector<string>& people, const vector<Dish>& dishes) {
    cout << "\nSummary:" << endl;
    vector<double> totalCosts(people.size(), 0.0);

    for (const auto& dish : dishes) {
        if (dish.type == "individual") {
            int personIndex = dish.assignedPpl[0];
            totalCosts[personIndex] += dish.price;
            cout << dish.name << " ($" << fixed << setprecision(2) << dish.price << ") is assigned to " << people[personIndex] << "." << endl;
        } else if (dish.type == "shared") {
            double splitPrice = dish.price / dish.assignedPpl.size();
            for (int personIndex : dish.assignedPpl) {
                totalCosts[personIndex] += splitPrice;
            }
            cout << dish.name << " ($" << fixed << setprecision(2) << dish.price 
                 << ") is shared among everyone ($" << splitPrice << " each)." << endl;
        }
    }

    cout << "\nTotal cost per person:" << endl;
    for (size_t i = 0; i < people.size(); ++i) {
        cout << people[i] << ": $" << fixed << setprecision(2) << totalCosts[i] << endl;
    }
}

int main()
{
    int numPpl, numDishes;

    cout << "Enter the number of people: ";
    cin >> numPpl;
    vector<string> people = getPpl(numPpl);

    cout << "\nEnter the number of dishes: ";
    cin >> numDishes;
    cin.ignore();
    vector<Dish> dishes = getDishes(numDishes, numPpl);

    displaySummary(people, dishes);
    
    return 0;
}