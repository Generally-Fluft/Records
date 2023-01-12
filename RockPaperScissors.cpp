#include <iostream>
#include <random>
#include <string>

/* 
 * Generates a random integer between start and end
 * 
 * Parameters:
 * Start: The smallest int to be generated
 * End: The largest int to be generated
 * 
 * Return:
 * An integer between start and end
 */
int RandI(int start, int end) {
    static std::mt19937 prng(std::random_device{}());
    static std::uniform_int_distribution<int> dist(start, end);
    return dist(prng);
}

/*
 * Checks if a string is in a given array of strings
 * 
 * Parameters: 
 * str: The string to be matched
 * array: The array of strings to be checked
 * size: The size of the array
 *
 * Return:
 * True if str is an element of array
 * False if str is not an element of array
 */
bool isIn(const std::string& str, std::string array[], const int size) {
    for (int s = 0; s < size; s++) {
        if (array[s] == str)
            return true;
    }
    return false;
}

int main() {
    std::string input;
    int player_choice = -1;
    enum RPS {Rock, Paper, Scissors};
    std::string rock[5] = {"ROCK", "Rock", "rock", "R", "r"};
    std::string paper[5] = {"PAPER", "Paper", "paper", "P", "p"};
    std::string scissors[5] = {"SCISSORS", "Scissors", "scissors", "S", "s"};
    std::string quit[5] = {"QUIT", "Quit", "quit", "Q", "q"};

    while (true) {
        std::cout << "Rock, Paper, Scissors!?\nYour Input: ";
        std::cin >> input;

        if (isIn(input, rock, 5)) {
            player_choice = Rock;
        }
        else if (isIn(input, paper, 5)) {
            player_choice = Paper;
        }
        else if (isIn(input, scissors, 5)) {
            player_choice = Scissors;
        }
        else if (isIn(input, quit, 5)) {
            break;
        }
        else {
            std::cout << "Bad input, try again\n\n";
            continue;
        }

        int cpu_choice = RandI(0, 2);
        switch (cpu_choice) {
            case Rock:
                std::cout << "The CPU chose: Rock\n";
                break;
            case Paper:
                std::cout << "The CPU chose: Paper\n";
                break;
            case Scissors:
                std::cout << "The CPU chose: Scissors\n";
        }

        if (player_choice == cpu_choice)
            std::cout << "It's a draw!\n";
        else if (player_choice - cpu_choice == 1 || player_choice - cpu_choice == -2)
            std::cout << "You win!\n";
        else
            std::cout << "You lost...\n";

        char yn;
        std::cout << "\nWould you like to play again?(y/n) ";
        std::cin >> yn;
        if (yn == 'n' || yn == 'N')
            break;
        std::cout << std::endl;
    }
    return 0;
}
