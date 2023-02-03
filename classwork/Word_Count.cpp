//Words Words Words: Reads a file and outputs various word statistics

#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct LengthStats{
    double avgLength;
    std::string longestWord;
};

struct FileStats{
    std::string fileName;
    int wordCount;
    LengthStats ls;
};

double average(std::vector<double> numbers);
std::vector<std::string> parse_words(std::string str);
LengthStats length_stats(std::vector<std::string> words);
FileStats file_stats(const char* file_name);

int main(int argc, char* argv[]){
    for (int i = 1; i <= argc - 1; i++){
        FileStats fs = file_stats(argv[i]);

        std::cout.setf(std::ios::fixed);
        std::cout.precision(1);

        if (argc > 2)
            std::cout << "File: " << fs.fileName << '\n';

        std::cout << "There " << ((fs.wordCount == 1)? "was " : "were ")
                  << fs.wordCount << ((fs.wordCount == 1)? " word " : " words ") << "read.\n"
                  << "The longest word is: \"" << fs.ls.longestWord << "\".\n"
                  << "The average word length is: " << fs.ls.avgLength << " letters.\n";

        if (i != argc - 1)
            std::cout << '\n';
    }

    return 0;
}

/*
 * Finds the average value of all elements of a vector
 *
 * Parameters:
 * Numbers: The set of numbers to be averaged.
 *
 * Return: N/A
 */
double average(std::vector<double> numbers){
    if (numbers.size() == 0)
        return 0;
    double sum = 0;
    for (auto n:numbers){
        sum += n;
    }
    return sum/static_cast<double>(numbers.size());
}

/*
 * Distinguishes words seperated by the characters {!?.,}
 * and places them into individual elements of a vector
 *
 * Parameters:
 * Str: The string of words to be parsed
 *
 * Return: A vector of strings with each word in its own element
 */
std::vector<std::string> parse_words(std::string str){
    int num = 0;
    std::vector<std::string> words;

    bool nflag = false;
    bool cflag = true;
    bool aflag = false;
    for (unsigned i = 0; i < str.size(); i++){
        if (std::isdigit(str[i])){
            nflag = true;
        }
        else if (isalpha(str[i])){
            if (cflag){
                num++;
                words.push_back("");
                aflag = true;
            }
            cflag = false;
            words[num - 1].push_back(str[i]);
        }
        else if (ispunct(str[i])){
            if (str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == ','){
                if (aflag && nflag){
                    num--;
                    words.pop_back();
                }
                cflag = true;
                nflag = false;
                aflag = false;
            }
            else{
                if (i == str.size() - 1 || cflag || ispunct(str[i + 1])){
                    if (aflag && nflag){
                        num--;
                        words.pop_back();
                    }
                    cflag = true;
                    nflag = false;
                    aflag = false;
                }
                else{
                    words[num - 1].push_back(str[i]);
                }
            }
        }
    }
    if (nflag && aflag)
        words.pop_back();
    return words;
}

/*
 * Builds a LengthStats object, consisting of an average length
 * for all elements, and the longest string within the set
 *
 * Parameters:
 * Words: The set of words to be compiled
 *
 * Return: A LengthStats object with structure:
 * double avgLength: The average length of all elements within the set
 * std::string longestWord: The longest string in the set
 */
LengthStats length_stats(std::vector<std::string> words){
    std::vector<double> length;
    std::string longestWord;

    for (auto w:words){
        length.push_back(static_cast<double>(w.size()));
        if (w.size() > longestWord.size())
            longestWord = w;
    }

    return {average(length), longestWord};
}

/*
 * Builds a FileStats object from a given file
 *
 * Parameters:
 * file_name: The name of the file to be scrunged
 *
 * Return: A FileStats object of structure:
 * std::string fileName: The name of the associated file
 * int wordCount: The number of words, not including those containing numbers
 * LengthStats ls: A LengthStats object for the entirety of the file.
 */
FileStats file_stats(const char* file_name){
    std::ifstream in;

    in.open(file_name);
    if (!in){
        std::cerr << "Error opening file: " << file_name << "exiting...\n";
        exit(1);
    }

    std::vector<std::string> text;

    do{
        std::string word;
        in >> word;
        std::vector<std::string> words = parse_words(word);

        for (auto w:words){
            text.push_back(w);
        }

    } while (!in.eof());

    in.close();

    return {file_name, static_cast<int>(text.size()), length_stats(text)};
}
