#include <iostream>
#include <string>

bool phoneCheck(std::string phoneNumber);
bool areaCodeCheck(std::string areaCode);
bool exchangeCodeCheck(std::string exchangeCode);
bool additionalDigitCheck(std::string additionalDigits);
bool extensionCheck(std::string extnesion);

int main(){

    std::string input;

    input = "reads";


    std::cout << (phoneCheck(input) ? "Good" : "Bad");





    std::cout << "\nProgram Terminated";
    return 0;
}

bool phoneCheck(std::string phoneNumber){
    std::cout << "Inputted Number: " << phoneNumber << "\n";
    

    



    // exchangeCodeCheck();
    // additionalDigitCheck();
    // extensionCheck();
    

    return 1;
}
bool areaCodeCheck(std::string areaCode){

    return 0;
}
bool exchangeCodeCheck(std::string exchangeCode){

    return 0;
}
bool additionalDigitCheck(std::string additionalDigits){

    return 0;
}
bool extensionCheck(std::string extnesion){

    return 0;
}