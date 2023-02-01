//Bingo: Prints the lyrics to the hit single "Bingo Was His Name-o"

#include <iostream>
#include <cctype>

/*
 * Prints Bingo, replacing letters with stars when specified
 *
 * Parameters:
 * NumLetters: The number of letters from the right to print,
 *             all other letters are replaced with stars
 *
 * Return:
 * None
 */
void print_bingo(int NumLetters){
    const int arrsize = 5;
    const char dog[arrsize] = {'B','I','N','G','O'};

    for (int letter = 0; letter < 5; letter++){
        if (NumLetters > arrsize && letter > 0){
            std::cout << static_cast<char>(tolower(dog[letter]));
        }
        else{
            if (letter < 5 - NumLetters)
            std::cout << '*';
            else
            std::cout << dog[letter];
        }
    }
}

/*
 * Prints a single verse of Bingo was his name-o
 *
 * Parameters:
 * Rondo: Directly corresponds to the number of letters in BINGO that will be visible
 *
 * Return: 
 * None
 */
void print_verse(int Rondo){

    std::cout << "There was a farmer had a dog and ";
    print_bingo(6);
    std::cout << " was his name-o\n";

    for (int j = 0; j < 3; j++){
        print_bingo(Rondo);
        std::cout << '\n';
    }

    std::cout << "and ";
    print_bingo(6);
    std::cout << " was his name-o\n\n";
}

int main(){
    for (int rondo = 5; rondo >= 0; rondo--){
        print_verse(rondo);
    }

    return 0;
}
