#include <iostream>
using namespace std;

#include "House.h"
#include "EinsteinRiddleSolver.h"

char EinsteinRiddleSolver::m_four_permutations[24][4]=
{
    { 'a','b','c','d' },
    { 'a','c','b','d' },
    { 'b','a','c','d' },
    { 'b','c','a','d' },
    { 'c','a','b','d' },
    { 'c','b','a','d' },
    { 'a','b','d','c' },
    { 'a','c','d','b' },
    { 'b','a','d','c' },
    { 'b','c','d','a' },
    { 'c','a','d','b' },
    { 'c','b','d','a' },
    { 'a','d','b','c' },
    { 'a','d','c','b' },
    { 'b','d','a','c' },
    { 'b','d','c','a' },
    { 'c','d','a','b' },
    { 'c','d','b','a' },
    { 'd','a','b','c' },
    { 'd','a','c','b' },
    { 'd','b','a','c' },
    { 'd','b','c','a' },
    { 'd','c','a','b' },
    { 'd','c','b','a' }
};

int EinsteinRiddleSolver::m_five_permutations[120][5] =
{
    { 0,1,2,3,4 },
    { 0,1,2,4,3 },
    { 0,1,3,2,4 },
    { 0,1,3,4,2 },
    { 0,1,4,2,3 },
    { 0,1,4,3,2 },
    { 0,2,1,3,4 },
    { 0,2,1,4,3 },
    { 0,2,3,1,4 },
    { 0,2,3,4,1 },

    { 0,2,4,1,3 },
    { 0,2,4,3,1 },
    { 0,3,1,2,4 },
    { 0,3,1,4,2 },
    { 0,3,2,1,4 },
    { 0,3,2,4,1 },
    { 0,3,4,1,2 },
    { 0,3,4,2,1 },
    { 0,4,1,2,3 },
    { 0,4,1,3,2 },

    { 0,4,2,1,3 },
    { 0,4,2,3,1 },
    { 0,4,3,1,2 },
    { 0,4,3,2,1 },
    { 1,0,2,3,4 },
    { 1,0,2,4,3 },
    { 1,0,3,2,4 },
    { 1,0,3,4,2 },
    { 1,0,4,2,3 },
    { 1,0,4,3,2 },

    { 1,2,0,3,4 },
    { 1,2,0,4,3 },
    { 1,2,3,0,4 },
    { 1,2,3,4,0 },
    { 1,2,4,0,3 },
    { 1,2,4,3,0 },
    { 1,3,0,2,4 },
    { 1,3,0,4,2 },
    { 1,3,2,0,4 },
    { 1,3,2,4,0 },

    { 1,3,4,0,2 },
    { 1,3,4,2,0 },
    { 1,4,0,2,3 },
    { 1,4,0,3,2 },
    { 1,4,2,0,3 },
    { 1,4,2,3,0 },
    { 1,4,3,0,2 },
    { 1,4,3,2,0 },
    { 2,0,1,3,4 },
    { 2,0,1,4,3 },

    { 2,0,3,1,4 },
    { 2,0,3,4,1 },
    { 2,0,4,1,3 },
    { 2,0,4,3,1 },
    { 2,1,0,3,4 },
    { 2,1,0,4,3 },
    { 2,1,3,0,4 },
    { 2,1,3,4,0 },
    { 2,1,4,0,3 },
    { 2,1,4,3,0 },

    { 2,3,0,1,4 },
    { 2,3,0,4,1 },
    { 2,3,1,0,4 },
    { 2,3,1,4,0 },
    { 2,3,4,0,1 },
    { 2,3,4,1,0 },
    { 2,4,0,1,3 },
    { 2,4,0,3,1 },
    { 2,4,1,0,3 },
    { 2,4,1,3,0 },

    { 2,4,3,0,1 },
    { 2,4,3,1,0 },
    { 3,0,1,2,4 },
    { 3,0,1,4,2 },
    { 3,0,2,1,4 },
    { 3,0,2,4,1 },
    { 3,0,4,1,2 },
    { 3,0,4,2,1 },
    { 3,1,0,2,4 },
    { 3,1,0,4,2 },

    { 3,1,2,0,4 },
    { 3,1,2,4,0 },
    { 3,1,4,0,2 },
    { 3,1,4,2,0 },
    { 3,2,0,1,4 },
    { 3,2,0,4,1 },
    { 3,2,1,0,4 },
    { 3,2,1,4,0 },
    { 3,2,4,0,1 },
    { 3,2,4,1,0 },

    { 3,4,0,1,2 },
    { 3,4,0,2,1 },
    { 3,4,1,0,2 },
    { 3,4,1,2,0 },
    { 3,4,2,0,1 },
    { 3,4,2,1,0 },
    { 4,0,1,2,3 },
    { 4,0,1,3,2 },
    { 4,0,2,1,3 },
    { 4,0,2,3,1 },

    { 4,0,3,1,2 },
    { 4,0,3,2,1 },
    { 4,1,0,2,3 },
    { 4,1,0,3,2 },
    { 4,1,2,0,3 },
    { 4,1,2,3,0 },
    { 4,1,3,0,2 },
    { 4,1,3,2,0 },
    { 4,2,0,1,3 },
    { 4,2,0,3,1 },

    { 4,2,1,0,3 },
    { 4,2,1,3,0 },
    { 4,2,3,0,1 },
    { 4,2,3,1,0 },
    { 4,3,0,1,2 },
    { 4,3,0,2,1 },
    { 4,3,1,0,2 },
    { 4,3,1,2,0 },
    { 4,3,2,0,1 },
    { 4,3,2,1,0 }
};

// implementation
EinsteinRiddleSolver::EinsteinRiddleSolver()
{
    // Tipp 7: "Der Mann, der im mittleren Haus wohnt, trinkt gerne Milch"
    m_houses[2].SetDrink (Milk);

    // Tipp 9: "Der Norweger wohnt im ersten Haus"
    m_houses[0].SetNationality (Norwegian);

    // Tipp 13: "Neben dem blauen Haus wohnt der Norweger"
    m_houses[1].SetHouseColor (Blue);
}

void EinsteinRiddleSolver::Solve_BruteForce_01()
{
    // iterate cigarettes
    for (int i = 0; i < NumFivePermutations; i++)
    {
        int* perm1 = m_five_permutations[i];
        m_houses[perm1[0]].SetCigarette (PallMall);
        m_houses[perm1[1]].SetCigarette (Marlboro);
        m_houses[perm1[2]].SetCigarette (DunHill);
        m_houses[perm1[3]].SetCigarette (Winfield);
        m_houses[perm1[4]].SetCigarette (Rothmans);

        // iterate pets
        for (int j = 0; j < NumFivePermutations; j++)
        {
            int* perm2 = m_five_permutations[j];
            m_houses[perm2[0]].SetPet (Bird);
            m_houses[perm2[1]].SetPet (Cat);
            m_houses[perm2[2]].SetPet (Dog);
            m_houses[perm2[3]].SetPet (Fish);
            m_houses[perm2[4]].SetPet (Horse);

            // iterate drinks
            for (int k = 0; k < NumFourPermutations; k++)
            {
                char* perm3 = m_four_permutations[k];

                int k1 =
                    (perm3[0] == 'a') ? 0 : (perm3[0] == 'b') ? 1 :
                    (perm3[0] == 'c') ? 3 : 4;
                int k2 =
                    (perm3[1] == 'a') ? 0 : (perm3[1] == 'b') ? 1 :
                    (perm3[1] == 'c') ? 3 : 4;
                int k3 =
                    (perm3[2] == 'a') ? 0 : (perm3[2] == 'b') ? 1 :
                    (perm3[2] == 'c') ? 3 : 4;
                int k4 =
                    (perm3[3] == 'a') ? 0 : (perm3[3] == 'b') ? 1 :
                    (perm3[3] == 'c') ? 3 : 4;

                m_houses[k1].SetDrink (Beer);
                m_houses[k2].SetDrink (Coffee);
                m_houses[k3].SetDrink (Tea);
                m_houses[k4].SetDrink (Water);

                // iterate colors
                for (int l = 0; l < NumFourPermutations; l++)
                {
                    char* perm4 = m_four_permutations[l];

                    int l1 =
                        (perm4[0] == 'a') ? 0 : (perm4[0] == 'b') ? 2 :
                        (perm4[0] == 'c') ? 3 : 4;
                    int l2 =
                        (perm4[1] == 'a') ? 0 : (perm4[1] == 'b') ? 2 :
                        (perm4[1] == 'c') ? 3 : 4;
                    int l3 =
                        (perm4[2] == 'a') ? 0 : (perm4[2] == 'b') ? 2 :
                        (perm4[2] == 'c') ? 3 : 4;
                    int l4 =
                        (perm4[3] == 'a') ? 0 : (perm4[3] == 'b') ? 2 :
                        (perm4[3] == 'c') ? 3 : 4;

                    m_houses[l1].SetHouseColor (Green);
                    m_houses[l2].SetHouseColor (Red);
                    m_houses[l3].SetHouseColor (White);
                    m_houses[l4].SetHouseColor (Yellow);

                    // iterate nations
                    for (int m = 0; m < NumFourPermutations; m++)
                    {
                        char* perm5 = m_four_permutations[m];

                        int m1 =
                            (perm5[0] == 'a') ? 1 : (perm5[0] == 'b') ? 2 :
                            (perm5[0] == 'c') ? 3 : 4;
                        int m2 =
                            (perm5[1] == 'a') ? 1 : (perm5[1] == 'b') ? 2 :
                            (perm5[1] == 'c') ? 3 : 4;
                        int m3 =
                            (perm5[2] == 'a') ? 1 : (perm5[2] == 'b') ? 2 :
                            (perm5[2] == 'c') ? 3 : 4;
                        int m4 =
                            (perm5[3] == 'a') ? 1 : (perm5[3] == 'b') ? 2 :
                            (perm5[3] == 'c') ? 3 : 4;

                        m_houses[m1].SetNationality (British);
                        m_houses[m2].SetNationality (Swedish);
                        m_houses[m3].SetNationality (Danish);
                        m_houses[m4].SetNationality (German);

                        // Tipp 1: "Der Brite lebt im roten Haus"
                        if (!Tip_01_Verify())
                            continue;

                        // Tipp 2: "Der Schwede hält einen Hund"
                        if (!Tip_02_Verify())
                            continue;

                        // Tipp 3: "Der Däne trinkt gerne Tee"
                        if (!Tip_03_Verify())
                            continue;

                        // Tipp 4: "Das grüne Haus steht links vom weißen Haus"
                        if (!Tip_04_Verify())
                            continue;

                        // Tipp 5: "Der Besitzer des grünen Hauses trinkt Kaffee"
                        if (!Tip_05_Verify())
                            continue;

                        // Tipp 6: "Die Person, die Pall Mall raucht, hält einen Vogel"
                        if (!Tip_06_Verify())
                            continue;

                        // Tipp 7: "Der Mann, der im mittleren Haus wohnt, trinkt gerne Milch"
                        // See C'tor

                        // Tipp 8: "Der Besitzer des gelben Hauses raucht Dunhill"
                        if (!Tip_08_Verify())
                            continue;

                        // Tipp 9: "Der Norweger wohnt im ersten Haus"
                        // See C'tor

                        // Tipp 10: "Der Marlboro-Raucher wohnt neben dem, der eine Katze hält. "
                        if (!Tip_10_Verify())
                            continue;

                        // Tipp 11: "Der Mann, der ein Pferd hält, wohnt neben dem, der Dunhill raucht"
                        if (!Tip_11_Verify())
                            continue;

                        // Tipp 12: "Der Winfield-Raucher trinkt gerne Bier."
                        if (!Tip_12_Verify())
                            continue;

                        // Tipp 13: "Neben dem blauen Haus wohnt der Norweger"
                        // See C'tor

                        // Tipp 14: "Der Deutsche raucht Rothmanns"
                        if (!Tip_14_Verify())
                            continue;

                        // Tipp 15: "Der Marlboro-Raucher hat einen Nachbarn, der Wasser trinkt"
                        if (!Tip_15_Verify())
                            continue;

                        // reached a solution
                        PrintSolution();
                    }
                }
            }
        }
    }
}

void EinsteinRiddleSolver::Solve_BruteForce_02()
{
    // iterate cigarettes
    for (int i = 0; i < NumFivePermutations; i++)
    {
        int* perm1 = m_five_permutations[i];
        m_houses[perm1[0]].SetCigarette (PallMall);
        m_houses[perm1[1]].SetCigarette (Marlboro);
        m_houses[perm1[2]].SetCigarette (DunHill);
        m_houses[perm1[3]].SetCigarette (Winfield);
        m_houses[perm1[4]].SetCigarette (Rothmans);

        // iterate pets
        for (int j = 0; j < NumFivePermutations; j++)
        {
            int* perm2 = m_five_permutations[j];
            m_houses[perm2[0]].SetPet (Bird);
            m_houses[perm2[1]].SetPet (Cat);
            m_houses[perm2[2]].SetPet (Dog);
            m_houses[perm2[3]].SetPet (Fish);
            m_houses[perm2[4]].SetPet (Horse);

            // Tipp 6: "Die Person, die Pall Mall raucht, hält einen Vogel"
            if (!Tip_06_Verify())
                continue;

            // Tipp 10: "Der Marlboro-Raucher wohnt neben dem, der eine Katze hält. "
            if (!Tip_10_Verify())
                continue;

            // Tipp 11: "Der Mann, der ein Pferd hält, wohnt neben dem, der Dunhill raucht"
            if (!Tip_11_Verify())
                continue;

            // iterate drinks
            for (int k = 0; k < NumFourPermutations; k++)
            {
                char* perm3 = m_four_permutations[k];

                int k1 =
                    (perm3[0] == 'a') ? 0 : (perm3[0] == 'b') ? 1 :
                    (perm3[0] == 'c') ? 3 : 4;
                int k2 =
                    (perm3[1] == 'a') ? 0 : (perm3[1] == 'b') ? 1 :
                    (perm3[1] == 'c') ? 3 : 4;
                int k3 =
                    (perm3[2] == 'a') ? 0 : (perm3[2] == 'b') ? 1 :
                    (perm3[2] == 'c') ? 3 : 4;
                int k4 =
                    (perm3[3] == 'a') ? 0 : (perm3[3] == 'b') ? 1 :
                    (perm3[3] == 'c') ? 3 : 4;

                m_houses[k1].SetDrink (Beer);
                m_houses[k2].SetDrink (Coffee);
                m_houses[k3].SetDrink (Tea);
                m_houses[k4].SetDrink (Water);

                // Tipp 12: "Der Winfield-Raucher trinkt gerne Bier."
                if (!Tip_12_Verify())
                    continue;

                // Tipp 15: "Der Marlboro-Raucher hat einen Nachbarn, der Wasser trinkt"
                if (!Tip_15_Verify())
                    continue;

                // iterate colors
                for (int l = 0; l < NumFourPermutations; l++)
                {
                    char* perm4 = m_four_permutations[l];

                    int l1 =
                        (perm4[0] == 'a') ? 0 : (perm4[0] == 'b') ? 2 :
                        (perm4[0] == 'c') ? 3 : 4;
                    int l2 =
                        (perm4[1] == 'a') ? 0 : (perm4[1] == 'b') ? 2 :
                        (perm4[1] == 'c') ? 3 : 4;
                    int l3 =
                        (perm4[2] == 'a') ? 0 : (perm4[2] == 'b') ? 2 :
                        (perm4[2] == 'c') ? 3 : 4;
                    int l4 =
                        (perm4[3] == 'a') ? 0 : (perm4[3] == 'b') ? 2 :
                        (perm4[3] == 'c') ? 3 : 4;

                    m_houses[l1].SetHouseColor (Green);
                    m_houses[l2].SetHouseColor (Red);
                    m_houses[l3].SetHouseColor (White);
                    m_houses[l4].SetHouseColor (Yellow);

                    // Tipp 4: "Das grüne Haus steht links vom weißen Haus"
                    if (!Tip_04_Verify())
                        continue;

                    // Tipp 5: "Der Besitzer des grünen Hauses trinkt Kaffee"
                    if (!Tip_05_Verify())
                        continue;

                    // Tipp 8: "Der Besitzer des gelben Hauses raucht Dunhill"
                    if (!Tip_08_Verify())
                        continue;

                    // iterate nations
                    for (int m = 0; m < NumFourPermutations; m++)
                    {
                        char* perm5 = m_four_permutations[m];

                        int m1 =
                            (perm5[0] == 'a') ? 1 : (perm5[0] == 'b') ? 2 :
                            (perm5[0] == 'c') ? 3 : 4;
                        int m2 =
                            (perm5[1] == 'a') ? 1 : (perm5[1] == 'b') ? 2 :
                            (perm5[1] == 'c') ? 3 : 4;
                        int m3 =
                            (perm5[2] == 'a') ? 1 : (perm5[2] == 'b') ? 2 :
                            (perm5[2] == 'c') ? 3 : 4;
                        int m4 =
                            (perm5[3] == 'a') ? 1 : (perm5[3] == 'b') ? 2 :
                            (perm5[3] == 'c') ? 3 : 4;

                        m_houses[m1].SetNationality (British);
                        m_houses[m2].SetNationality (Swedish);
                        m_houses[m3].SetNationality (Danish);
                        m_houses[m4].SetNationality (German);

                        // Tipp 1: "Der Brite lebt im roten Haus"
                        if (!Tip_01_Verify())
                            continue;

                        // Tipp 2: "Der Schwede hält einen Hund"
                        if (!Tip_02_Verify())
                            continue;

                        // Tipp 3: "Der Däne trinkt gerne Tee"
                        if (!Tip_03_Verify())
                            continue;

                        // Tipp 14: "Der Deutsche raucht Rothmanns"
                        if (!Tip_14_Verify())
                            continue;

                        // reached a solution
                        PrintSolution();
                    }
                }
            }
        }
    }
}

void EinsteinRiddleSolver::Solve_BruteForce_03()
{
    // iterate cigarettes
    for (int i = 0; i < NumFivePermutations; i++)
    {
        int* perm1 = m_five_permutations[i];
        m_houses[perm1[0]].SetCigarette (PallMall);
        m_houses[perm1[1]].SetCigarette (Marlboro);
        m_houses[perm1[2]].SetCigarette (DunHill);
        m_houses[perm1[3]].SetCigarette (Winfield);
        m_houses[perm1[4]].SetCigarette (Rothmans);

        // iterate pets
        for (int j = 0; j < NumFivePermutations; j++)
        {
            int* perm2 = m_five_permutations[j];
            m_houses[perm2[0]].SetPet (Bird);
            m_houses[perm2[1]].SetPet (Cat);
            m_houses[perm2[2]].SetPet (Dog);
            m_houses[perm2[3]].SetPet (Fish);
            m_houses[perm2[4]].SetPet (Horse);

            // Tipp 6: "Die Person, die Pall Mall raucht, hält einen Vogel"
            if (perm1[0] != perm2[0])
                continue;

            // Tipp 10: "Der Marlboro-Raucher wohnt neben dem, der eine Katze hält. "
            if (!Tip_10_Verify(perm1[1]))
                continue;

            // Tipp 11: "Der Mann, der ein Pferd hält, wohnt neben dem, der Dunhill raucht"
            if (!Tip_11_Verify(perm2[4]))
                continue;

            // iterate drinks
            for (int k = 0; k < NumFourPermutations; k++)
            {
                char* perm3 = m_four_permutations[k];

                int k1 =
                    (perm3[0] == 'a') ? 0 : (perm3[0] == 'b') ? 1 :
                    (perm3[0] == 'c') ? 3 : 4;
                int k2 =
                    (perm3[1] == 'a') ? 0 : (perm3[1] == 'b') ? 1 :
                    (perm3[1] == 'c') ? 3 : 4;
                int k3 =
                    (perm3[2] == 'a') ? 0 : (perm3[2] == 'b') ? 1 :
                    (perm3[2] == 'c') ? 3 : 4;
                int k4 =
                    (perm3[3] == 'a') ? 0 : (perm3[3] == 'b') ? 1 :
                    (perm3[3] == 'c') ? 3 : 4;

                m_houses[k1].SetDrink (Beer);
                m_houses[k2].SetDrink (Coffee);
                m_houses[k3].SetDrink (Tea);
                m_houses[k4].SetDrink (Water);

                // Tipp 12: "Der Winfield-Raucher trinkt gerne Bier."
                if (perm1[3] != k1)
                    continue;

                // Tipp 15: "Der Marlboro-Raucher hat einen Nachbarn, der Wasser trinkt"
                if (!Tip_15_Verify(perm1[1]))
                    continue;

                // iterate colors
                for (int l = 0; l < NumFourPermutations; l++)
                {
                    char* perm4 = m_four_permutations[l];

                    int l1 =
                        (perm4[0] == 'a') ? 0 : (perm4[0] == 'b') ? 2 :
                        (perm4[0] == 'c') ? 3 : 4;
                    int l2 =
                        (perm4[1] == 'a') ? 0 : (perm4[1] == 'b') ? 2 :
                        (perm4[1] == 'c') ? 3 : 4;
                    int l3 =
                        (perm4[2] == 'a') ? 0 : (perm4[2] == 'b') ? 2 :
                        (perm4[2] == 'c') ? 3 : 4;
                    int l4 =
                        (perm4[3] == 'a') ? 0 : (perm4[3] == 'b') ? 2 :
                        (perm4[3] == 'c') ? 3 : 4;

                    m_houses[l1].SetHouseColor (Green);
                    m_houses[l2].SetHouseColor (Red);
                    m_houses[l3].SetHouseColor (White);
                    m_houses[l4].SetHouseColor (Yellow);

                    // Tipp 4: "Das grüne Haus steht links vom weißen Haus"
                    if (!Tip_04_Verify())
                        continue;

                    // Tipp 5: "Der Besitzer des grünen Hauses trinkt Kaffee"
                    if (l1 != k2)
                        continue;

                    // Tipp 8: "Der Besitzer des gelben Hauses raucht Dunhill"
                    if (l4 != perm1[2])
                        continue;

                    // iterate nations
                    for (int m = 0; m < NumFourPermutations; m++)
                    {
                        char* perm5 = m_four_permutations[m];

                        int m1 =
                            (perm5[0] == 'a') ? 1 : (perm5[0] == 'b') ? 2 :
                            (perm5[0] == 'c') ? 3 : 4;
                        int m2 =
                            (perm5[1] == 'a') ? 1 : (perm5[1] == 'b') ? 2 :
                            (perm5[1] == 'c') ? 3 : 4;
                        int m3 =
                            (perm5[2] == 'a') ? 1 : (perm5[2] == 'b') ? 2 :
                            (perm5[2] == 'c') ? 3 : 4;
                        int m4 =
                            (perm5[3] == 'a') ? 1 : (perm5[3] == 'b') ? 2 :
                            (perm5[3] == 'c') ? 3 : 4;

                        m_houses[m1].SetNationality (British);
                        m_houses[m2].SetNationality (Swedish);
                        m_houses[m3].SetNationality (Danish);
                        m_houses[m4].SetNationality (German);

                        // Tipp 1: "Der Brite lebt im roten Haus"
                        if (m1 != l2)
                            continue;

                        // Tipp 2: "Der Schwede hält einen Hund"
                        if (m2 != perm2[2])
                            continue;

                        // Tipp 3: "Der Däne trinkt gerne Tee"
                        if (m3 != k3)
                            continue;

                        // Tipp 14: "Der Deutsche raucht Rothmanns"
                        if (m4 != perm1[4])
                            continue;

                        // reached a solution
                        PrintSolution();
                    }
                }
            }
        }
    }
}

/*
 * helper methods - brute-force
 */

// Tipp 1: "Der Brite lebt im roten Haus"
bool EinsteinRiddleSolver::Tip_01_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetNationality() == British)
        {
            if (m_houses[i].GetHouseColor() == Red)
            {
                tip = true;
            }
            break;
        }
    }
    return tip;
}

// Tipp 2: "Der Schwede hält einen Hund"
bool EinsteinRiddleSolver::Tip_02_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetNationality() == Swedish)
        {
            if (m_houses[i].GetPet() == Dog)
            {
                tip = true;
            } 
            break;
        }
    }
    return tip;
}

// Tipp 3: "Der Däne trinkt gerne Tee"
bool EinsteinRiddleSolver::Tip_03_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetNationality() == Danish)
        {
            if (m_houses[i].GetDrink() == Tea)
            {
                tip = true;
            }
            break;
        }
    }
    return tip;
}

// Tipp 4: "Das grüne Haus steht direkt links vom weißen Haus"
bool EinsteinRiddleSolver::Tip_04_Verify()
{
    if ((m_houses[2].GetHouseColor() == Green &&
            m_houses[3].GetHouseColor() == White) ||
        (m_houses[3].GetHouseColor() == Green &&
            m_houses[4].GetHouseColor() == White))
    {
        return true;
    }
    else
        return false;
}

// Tipp 5: "Der Besitzer des grünen Hauses trinkt gerne Kaffee"
bool EinsteinRiddleSolver::Tip_05_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetHouseColor() == Green)
        {
            if (m_houses[i].GetDrink() == Coffee)
            {
                tip = true;
            }
            break;
        }
    }
    return tip;
}

// Tipp 6: "Die Person, die Pall Mall raucht, hält einen Vogel"
bool EinsteinRiddleSolver::Tip_06_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetCigarette() == PallMall)
        {
            if (m_houses[i].GetPet() == Bird)
            {
                tip = true;
            }
            break;
        }
    }
    return tip;
}

// Tipp 7: "Der Mann, der im mittleren Haus wohnt, trinkt gerne Milch"
// See C'tor

// Tipp 8: "Der Besitzer des gelben Hauses raucht Dunhill"
bool EinsteinRiddleSolver::Tip_08_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetHouseColor() == Yellow)
        {
            if (m_houses[i].GetCigarette() == DunHill)
            {
                tip = true;
            }
            break;
        }
    }
    return tip;
}

// Tipp 9: "Der Norweger wohnt im ersten Haus"
// See C'tor

// Tipp 10: "Der Marlboro-Raucher wohnt neben dem, der eine Katze hält"
bool EinsteinRiddleSolver::Tip_10_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetCigarette() == Marlboro)
        {
            if (i == 0)
            {
                if (m_houses[1].GetPet() == Cat)
                    tip = true;
            }
            else if (i == 4)
            {
                if (m_houses[3].GetPet() == Cat)
                    tip = true;
            }
            else if (m_houses[i - 1].GetPet() == Cat ||
                m_houses[i + 1].GetPet() == Cat)
                    tip = true;

            break;
        }
    }

    return tip;
}

// Tipp 11: "Der Mann, der ein Pferd hält, wohnt neben dem, der Dunhill raucht"
bool EinsteinRiddleSolver::Tip_11_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetPet() == Horse)
        {
            if (i == 0)
            {
                if (m_houses[1].GetCigarette() == DunHill)
                    tip = true;
            }
            else if (i == 4)
            {
                if (m_houses[3].GetCigarette() == DunHill)
                    tip = true;
            }
            else if (m_houses[i - 1].GetCigarette() == DunHill ||
                        m_houses[i + 1].GetCigarette() == DunHill)
                    tip = true;
            
            break;
        }
    }
    return tip;
}

// Tipp 12: "Der Winfield-Raucher trinkt gerne Bier"
bool EinsteinRiddleSolver::Tip_12_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetCigarette() == Winfield)
        {
            if (m_houses[i].GetDrink() == Beer)
                tip = true;

            break;
        }
    }
    return tip;
}

// Tipp 13: "Neben dem blauen Haus wohnt der Norweger"
// See C'tor

// Tipp 14: "Der Deutsche raucht Rothmanns"
bool EinsteinRiddleSolver::Tip_14_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetNationality() == German)
        {
            if (m_houses[i].GetCigarette() == Rothmans)
                tip = true;

            break;
        }
    }
    return tip;
}

// Tipp 15: "Der Marlboro-Raucher hat einen Nachbarn, der Wasser trinkt"
bool EinsteinRiddleSolver::Tip_15_Verify()
{
    bool tip = false;
    for (int i = 0; i < 5; i++)
    {
        if (m_houses[i].GetCigarette() == Marlboro)
        {
            if (i == 0)
            {
                if (m_houses[1].GetDrink() == Water)
                    tip = true;
            }
            else if (i == 4)
            {
                if (m_houses[3].GetDrink() == Water)
                    tip = true;
            }
            else if (m_houses[i - 1].GetDrink() == Water ||
                m_houses[i + 1].GetDrink() == Water)
                    tip = true;

            break;
        }
    }
    return tip;
}

/*
 * helper methods - less brute-force
 */

// Tipp 10: "Der Marlboro-Raucher wohnt neben dem, der eine Katze hält"
bool EinsteinRiddleSolver::Tip_10_Verify (int houseMarlboro)
{
    bool tip = false;
    if (houseMarlboro == 0)
    {
        if (m_houses[1].GetPet() == Cat)
            tip = true;
    }
    else if (houseMarlboro == 4)
    {
        if (m_houses[3].GetPet() == Cat)
            tip = true;
    }
    else
        if (m_houses[houseMarlboro - 1].GetPet() == Cat ||
            m_houses[houseMarlboro + 1].GetPet() == Cat)
                tip = true;

    return tip;
}

// Tipp 11: "Der Mann, der ein Pferd hält, wohnt neben dem, der Dunhill raucht"
bool EinsteinRiddleSolver::Tip_11_Verify (int houseHorse)
{
    bool tip = false;

    if (houseHorse == 0)
    {
        if (m_houses[1].GetCigarette() == DunHill)
            tip = true;
    }
    else if (houseHorse == 4)
    {
        if (m_houses[3].GetCigarette() == DunHill)
            tip = true;
    }
    else
        if (m_houses[houseHorse - 1].GetCigarette() == DunHill ||
            m_houses[houseHorse + 1].GetCigarette() == DunHill)
                tip = true;

    return tip;
}

// Tipp 15: "Der Marlboro-Raucher hat einen Nachbarn, der Wasser trinkt"
bool EinsteinRiddleSolver::Tip_15_Verify(int houseMarlboro)
{
    bool tip = false;

    if (houseMarlboro == 0)
    {
        if (m_houses[1].GetDrink() == Water)
            tip = true;
    }
    else if (houseMarlboro == 4)
    {
        if (m_houses[3].GetDrink() == Water)
            tip = true;
    }
    else
        if (m_houses[houseMarlboro - 1].GetDrink() == Water ||
            m_houses[houseMarlboro + 1].GetDrink() == Water)
                tip = true;

    return tip;
}

void EinsteinRiddleSolver::PrintSolution()
{
    for (int n = 0; n < 5; n++)
    {
        if (m_houses[n].GetPet() == Fish)
        {
            Nationality nationality = m_houses[n].GetNationality();
            cout << "The " << g_Nationalities[nationality] <<
                " is the owner of the Fish." << endl;
        }
    }
}
