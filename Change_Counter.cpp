//Coin Counter: Provides a cent total for a user inputted selection of coins.

#include <iostream>

int main(){

    int quarter;
    int dime;
    int nickel;
    int penny;

    std::cout << "Please enter the number of\n";

    std::cout << "\tQuarters: ";
    std::cin >> quarter;
    if (quarter < 0){
        std::cerr << "\tNegatives will be treated as zero.\n";
        quarter = 0;
    }

    std::cout << "\tDimes: ";
    std::cin >> dime;
    if (dime < 0){
        std::cerr << "\tNegatives will be treated as zero.\n";
        dime = 0;
    }

    std::cout << "\tNickels: ";
    std::cin >> nickel;
    if (nickel < 0){
        std::cerr << "\tNegatives will be treated as zero.\n";
        nickel = 0;
    }

    std::cout << "\tPennies: ";
    std::cin >> penny;
    if (penny < 0){
        std::cerr << "\tNegatives will be treated as zero.\n";
        penny = 0;
    }

    int total = (quarter*25) + (dime*10) + (nickel*5) + penny; //new int for conciseness
    std::cout << "You have " << total << " cents.\n";

}
