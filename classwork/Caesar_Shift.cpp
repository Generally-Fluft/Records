//Caesar Shift: Encodes and decodes a written message.

#include <iostream>
#include <string>

/*
 * Code a message by changing each letter to a shifted alphabet
 *
 * Parameters:
 * Message: The message to be coded
 * Shift: The amount which each character should be shifted
 *
 * Return: N/A
*/
void caesar_shift(std::string& message, int shift){
    for (auto& i:message){
        if (i >= 'A' && i <= 'Z'){
            if (i + (shift % 26) > 'Z')
            i = i + (shift % 26) - 26;
            else
            i = i + (shift % 26);
        }
        else if (i >= 'a' && i <= 'z'){
            if (i + (shift % 26) > 'z')
            i = i + (shift % 26) - 26;
            else
            i = i + (shift % 26);
        }
    }
}

/*
 * Decode a message which has been caesar shifted
 *
 * Parameters:
 * Code: The message to be decoded
 * Shift: The amount which the original message has been shifted
 *
 * Return: N/A
*/
void deshift(std::string& code, int shift){
    for (auto& i:code){
        if (i >= 'A' && i <= 'Z'){
            if (i - (shift % 26) < 'A')
            i = i - (shift % 26) + 26;
            else
            i = i - (shift % 26);
        }
        else if (i >= 'a' && i <= 'z'){
            if (i - (shift % 26) < 'a')
            i = i - (shift % 26) + 26;
            else
            i = i - (shift % 26);
        }
    }
}

int main(){
    std::string message;
    const int shift = 4;

    std::cout << "Please enter a message: ";
    std:: getline(std::cin, message);
    std::cout << '\n' << message << '\n';

    caesar_shift(message, shift);
    std::cout << message << '\n';

    deshift(message, shift);
    std::cout << message << '\n';

    return 0;
}
