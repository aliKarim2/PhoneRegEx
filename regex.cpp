#include <iostream>
#include <string>

#define TEST_COMMENTS 1


bool phoneCheck(std::string phoneNumber);
bool areaCodeCheck(std::string areaCode, bool paranthesis);
bool exchangeCodeCheck(std::string exchangeCode);
bool additionalDigitCheck(std::string additionalDigits);
bool extensionCheck(std::string extnesion);

int main(){

    std::string input;
    std::string smaller;
    // input = "reads";

    std::cout << "Enter a phone number to test:\n";
    std::cin >> input;

    // smaller = input.substr(3);

    // std::cout << "Input: " << input << '\n';
    // std::cout << "Smaller: " << smaller << '\n';

    std::cout << (phoneCheck(input) ? "Good" : "Bad");


    #if TEST_COMMENTS

    #endif


    std::cout << "\nProgram Terminated";
    return 0;
}

bool phoneCheck(std::string phoneNumber){
    const bool PARENTHESIS = true;
    char seperator;
    std::cout << "Inputted Number: " << phoneNumber << "\n";
    // phoneNumber = phoneNumber.substr(5);



    std::cin.ignore();
    std::cin.get();


    // std::cout << "\n\n\n";
    // std::cout << phoneNumber << '\n';
    // std::cin.get();

    //Check the area code
    {
        if(phoneNumber[0] == '('){
            // phoneNumber = phoneNumber.substr(5);

            // std::cout << focusedInput << '\n';
            // std::cin.get();

            #if TEST_COMMENTS
            std::cout << "Parenthesis in area code\n";
            #endif


            //if the area code is surrounded with parenthesis
            //it should be 5 characters: 2 parenthesis and 3 nums
            std::string input = phoneNumber.substr(0,5);
             if(!areaCodeCheck(phoneNumber, PARENTHESIS)){
                #if TEST_COMMENTS
                std::cout << "bad area code\n";
                #endif
                return 0;
             }
             phoneNumber = phoneNumber.substr(5);

        } else if (isdigit(phoneNumber[0])){
        

            #if TEST_COMMENTS
            std::cout << "No parenthesis in area code\n";
            #endif

            //if code does not start with parenthesis, it should be a number
            //we will check if the number is valid (2-9) in function
            //it should be 3 characters long, just numbers
            std::string input = phoneNumber.substr(0,3);
            if(areaCodeCheck(phoneNumber, !PARENTHESIS)){
                #if TEST_COMMENTS
                std::cout << "bad area code\n";
                #endif
                return 0;
            }

            phoneNumber = phoneNumber.substr(3);
        }
        else{
            #if TEST_COMMENTS
            std::cout << "BAD AREA CODE\n";
            #endif
            //invalid area code, so invalid
            return 0;
        } 
    }
    //Now only need to focus on "focused input"


    //check to see what the seperator symbol is
    if(phoneNumber[0] == '.' || phoneNumber[0] == '-'){
        seperator = phoneNumber[0];
    } else {
        return 0;
    }

    //make the new phone number start from the exchange number
    phoneNumber = phoneNumber.substr(1);


    //Check the exchange numbers
    {
        exchangeCodeCheck(phoneNumber);

        //remove the exchange code from string
        phoneNumber = phoneNumber.substr(3);

    }
    //check for next seperator
    if(phoneNumber[0] != seperator){
        return 0;
    }

    //make phone number just start from the additional digits
    phoneNumber = phoneNumber.substr(1);





    // additionalDigitCheck();
    // extensionCheck();
    

    return 1;
}
bool areaCodeCheck(std::string areaCode, bool paranthesis){

    if(paranthesis){
     
        //Notice we dont have to check for first parenthesis
        //bc that happened in the phone check fxn



        //first number check
        if(!(areaCode[1] >= '2' && areaCode[1] <= '9')){
            //if first digit not from 0-9, return false
            return 0;
        }



        //last 2 number check
        std::cin.get();
        for(int i = 2; i <= 3; i++){
            //check if last 2 numbers are digits
            if(!isdigit(areaCode[i])){  
                return false;
            }
        }

        std::cout << "C1\n";

        if(areaCode[4] != ')'){
            return false;
        }
        #if TEST_COMMENTS
        std::cout << "good area code\n";
        #endif

        return true; //if it made it thru all validation
    }
    else{
        //first number check
        if(!(areaCode[0] >= '2' && areaCode[0] <= '9')){
            //if first digit not from 0-9, return false
            return 0;
        }

        //last 2 number check
        for(int i = 1; i < 3; i++){
            //check if last 2 numbers are digits
            if(!isdigit(areaCode[i])){  
                return false;
            }
        }
        #if TEST_COMMENTS
        std::cout << "good area code\n";
        #endif
        return true;
    }


    return 0;
}
bool exchangeCodeCheck(std::string exchangeCode){

    //checks for 3 numbers at start of a string
    //if there are not 3 consecutive numbers, fails
    for(int i = 0; i < 3; i++){
        if(!isdigit(exchangeCode[i])){
            return 0;
        }
    }


    return 0;
}
bool additionalDigitCheck(std::string additionalDigits){

    return 0;
}
bool extensionCheck(std::string extnesion){

    return 0;
}