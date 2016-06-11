enum Nationality { Norwegian, British, Swedish, Danish, German };
enum HouseColor { Red, Green, White, Yellow, Blue };
enum Cigarette { PallMall, Marlboro, DunHill, Winfield, Rothmans };
enum Drink { Tea, Coffee, Milk, Beer, Water };
enum Pet { Dog, Bird, Cat, Horse, Fish };

extern char* g_Nationalities[];
extern char* g_HouseColors[];
extern char* g_Cigarettes[];
extern char* g_Drinks[];
extern char* g_Pets[];

struct House
{
private:
    Nationality m_Nationality;
    HouseColor  m_HouseColor;
    Cigarette   m_Cigarette;
    Drink       m_Drink;
    Pet         m_Pet;

public:
    // getter / setter
    void SetNationality (Nationality nationality) { m_Nationality = nationality; }
    Nationality GetNationality () const { return m_Nationality; }

    void SetHouseColor (HouseColor houseColor) { m_HouseColor = houseColor; }
    HouseColor GetHouseColor () const { return m_HouseColor; }

    void SetCigarette (Cigarette cigarette) { m_Cigarette = cigarette; }
    Cigarette GetCigarette () const { return m_Cigarette; }

    void SetDrink (Drink drink) { m_Drink = drink; }
    Drink GetDrink () const { return m_Drink; }

    void SetPet (Pet pet) { m_Pet = pet; }
    Pet GetPet () const { return m_Pet; }

    friend ostream& operator<< (ostream&, const House&);
};