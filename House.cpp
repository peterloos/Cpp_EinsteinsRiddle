#include <iostream>
using namespace std;

#include "House.h"

char* g_Nationalities[] =
    { "Norwegian", "British", "Swedish", "Danish", "German" };
char* g_HouseColors[] =
    { "Red", "Green", "White", "Yellow", "Blue" };
char* g_Cigarettes[] =
    { "PallMall", "Marlboro", "DunHill", "Winfield", "Rothmans"  };
char* g_Drinks[] =
    { "Tea", "Coffee", "Milk", "Beer", "Water" };
char* g_Pets[] =
    { "Dog", "Bird", "Cat", "Horse", "Fish" };

ostream& operator<< (ostream& os, const House& house)
{
    os << "Nationality: " << g_Nationalities[house.GetNationality()] << endl;
    os << "    HouseColor: " << g_Nationalities[house.GetHouseColor()] << ", ";
    os << "Pet: " << g_Nationalities[house.GetPet()] << endl;
    os << "    Cigarette: " << g_Nationalities[house.GetCigarette()] << ", ";
    os << "Drink: " << g_Nationalities[house.GetDrink()] << endl;
    return os;
}
