class EinsteinRiddleSolver
{
private:
    static const int NumHouses = 5;
    static const int NumFourPermutations = 24;
    static const int NumFivePermutations = 120;

private:
    House m_houses[NumHouses];

private:
    // helper arrays with permutations
    static char m_four_permutations[NumFourPermutations][4];
    static int  m_five_permutations[NumFivePermutations][5];

public:
    // c'tor
    EinsteinRiddleSolver();

    // public interface
    void Solve_BruteForce_01();
    void Solve_BruteForce_02();
    void Solve_BruteForce_03();
    void PrintSolution();

private:
    // helper methods - brute-force
    bool Tip_01_Verify();
    bool Tip_02_Verify();
    bool Tip_03_Verify();
    bool Tip_04_Verify();
    bool Tip_05_Verify();
    bool Tip_06_Verify();
    bool Tip_07_Verify();
    bool Tip_08_Verify();
    bool Tip_09_Verify();
    bool Tip_10_Verify();
    bool Tip_11_Verify();
    bool Tip_12_Verify();
    bool Tip_13_Verify();
    bool Tip_14_Verify();
    bool Tip_15_Verify();

    // helper methods - less brute-force
    bool Tip_10_Verify(int houseMarlboro);
    bool Tip_11_Verify(int houseHorse);
    bool Tip_15_Verify(int houseMarlboro);
};