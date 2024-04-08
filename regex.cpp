#include <iostream>
#include <string>

bool phoneCheck(std::string phoneNumber);
bool areaCodeCheck(std::string areaCode, bool paranthesis);
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
    const bool PARENTHESIS = true;
    std::cout << "Inputted Number: " << phoneNumber << "\n";
    
    //Check the area code
    if(phoneNumber[0] == ')'){
        //if the area code is surrounded with parenthesis
        //it should be 5 characters: 2 parenthesis and 3 nums
        std::string input = phoneNumber.substr(0,5);
        areaCodeCheck(input, PARENTHESIS);

    } else if (isdigit(phoneNumber[0])){
        //if code does not start with parenthesis, it should be a number
        //we will check if the number is valid (2-9) in function
        //it should be 3 characters long, just numbers
        std::string input = phoneNumber.substr(0,3);
        areaCodeCheck(input, !PARENTHESIS);

    }
    else{
        //invalid area code, so invalid
        return 0;
    }    



    // exchangeCodeCheck();
    // additionalDigitCheck();
    // extensionCheck();
    

    return 1;
}
bool areaCodeCheck(std::string areaCode, bool paranthesis){

    if(paranthesis){
        //Notice we dont have to check for first parenthesis
        //bc that happened in the phone check fxn

        //first number check
        if(!(areaCode[1] >= '2' && areaCode[1] <= '2')){
            //if first digit not from 0-9, return false
            return 0;
        }

        //last 2 number check
        for(int i = 2; i < 4; i++){
            //check if last 2 numbers are digits
            if(!isdigit(areaCode[i])){  
                return false;
            }
        }
        if(areaCode[4] != ')'){
            return false;
        }
        return true; //if it made it thru all validation
    }



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