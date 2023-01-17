//Count and Sort: Counts the number of iterations of each letter in a sentence

#include <iostream>
#include <string>
#include <vector>
#include <utility>

/*
 * Determines if a swap should be made for an int/char pair,
 * with precedence descending magnitude > alphabetical.
 *
 * Parameters:
 * First: The leftward pair
 * Second: The rightward pair
 *
 * Return:
 * True: A swap should be made
 * False: A swap should not be made
 */
bool do_swap(std::pair<int, char> first, std::pair<int, char> second){
    if (first.first < second.first){
        return true;
    } else if (first.first == second.first){
        if (first.second > second.second){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

/*
 * Uses the bubble-sort method to sort a set of int/char pairs
 * with precedence descending magnitude > alphabetical.
 *
 * Parameters:
 * Data: The set of data which is to be sorted
 *
 * Return: N/A
 */
void bubble_sort(std::vector<std::pair<int, char>> &data){
    for (size_t d = 0; d < data.size(); d++){
        for (size_t j = 0; j < ((data.size() - 1) - d); j++){
            if (do_swap(data[j], data[j + 1]))
            data[j].swap(data[j + 1]);
        }
    }
}

int main(){
    std::string sentence;
    std::vector<std::pair<int, char>> count(26);

    for (int i = 0; i < 26; i++){
        count[i] = std::make_pair(0, ('A' + i));
    }

    std::cout << "Enter a phrase: ";
    std::getline(std::cin, sentence);

    for (auto s:sentence){
        if (s >= 65 && s <= 90)
            count[s - 65].first++;
        else if (s >= 97 && s <= 122)
            count[s - 97].first++;
    }

    bubble_sort(count);

    for (auto c:count){
        if (c.first > 0)
            std::cout << c.second << "  " << c.first << '\n';
    }

    return 0;
}
