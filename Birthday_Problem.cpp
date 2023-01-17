//Birthday Problem: Simulates the probability of various
//                  group sizes having matching birthdays.

#include <iostream>
#include <iomanip>
#include <random>

double birthday_prob(int grpSize, const int numTrials);

int main(){
    for (int i = 2; i <= 50; i++){
        const int trials = 10000;
        std::cout << "Group size: " << std::setw(2) << i << ", matching birthdays found: "
                  << std::setw(5) << birthday_prob(i, trials) << "% of the time.\n";
    }
}

/* Determines the probability that two people in a random group have the same birthday.
 *
 * Parameters:
 * grpSize: The amount of people in the group.
 * numTrials: The amount of trials to be performed, i.e. the precision.
 *
 * Return:
 * Percentage of trials where two or more people shared birthdays.
 */
double birthday_prob(int grpSize, const int numTrials){
    static std::mt19937 prng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(1,365);

    int tally = 0;
    for (int t = 0; t < numTrials; t++){
        int birthdays[365] = {0};
        for (int g = 0; g < grpSize; g++){
            birthdays[dist(prng)]++;
        }

        for (auto k : birthdays){
            if (k > 1){
                tally++;
                break;
            }
        }
    }

    return static_cast<double>(tally*100)/static_cast<double>(numTrials);
}
