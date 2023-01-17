//Rollin' Rollin' Rollin': Rolls an arbitrary die any number of times.

#include <iostream>
#include <random>
#include <cstdlib>

/* Simulates rolling a die with an arbitrary number of sides
 *
 * Parameters:
 * Sides: Number of sides
 *
 * Return: int
 */
int roll_die(int sides){
    static std::mt19937 prng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(1,sides);
    return dist(prng);
}

/* Displays a tally of a specific roll, where each star represents 1% of the total
 *
 * Parameters:
 * val: The value which is to be tallied
 * numValRows: The amount of rolls of that number
 * totalNumRolls: The total number of rolls
 *
 * Return: N/A
 */
void print_table_row(int val, int numValRows, int totalNumRolls){
    std::cout << val << ": ";
    for (int i = 0; i < 100*numValRows/totalNumRolls; i++){
        std::cout << '*';
    }
    std::cout << '\n';
}

int main(){
    size_t sides = 6;
    int total = 500000;

 /* USER INPUT MODE:
  *
  * std::cout << "How many sides is your die? ";
  * std::cin >> sides;
  * std::cout << "How many times would you like to roll? ";
  * std::cin >> total;
  */

    int tally[sides];

    std::cout << "\nDistribution of Dice Rolls (* = 1%)\n"
              << "==========================\n";

    for (size_t t = 0; t < sides; t++){
        tally[t] = 0;
    }
    for (int r = 0; r < total; r++){
        tally[roll_die(sides)-1]++;
    }
    for (size_t p = 0; p < sides; p++){
        print_table_row(p+1, tally[p], total);
    }

    return 0;
}
