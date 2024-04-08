#include <iostream>
#include <string>

#define TEST_COMMENTS 0


bool phoneCheck(std::string phoneNumber); //larger function that returns if phone number is valid
bool areaCodeCheck(std::string areaCode, bool paranthesis); //checks area code
bool digitCheck(std::string expression, int ct);    //serves as exchange code, additional digits, and extension digits check

int main(){

    std::string input;
    std::cout << "Enter a phone number to test:\n";
    std::getline(std::cin, input);  // Read input into a std::string object

    std::cout << (phoneCheck(input) ? "Valid Phone Number" : "Invalid Phone Number");

    std::cout << '\n';

    std::cout << "Program Terminated";
    return 0;
}

bool phoneCheck(std::string phoneNumber){
    const bool PARENTHESIS = true;
    char seperator;

    #if TEST_COMMENTS
        std::cout << "Inputted Number: " << phoneNumber << "\n";
    #endif

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
                return false;
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
            if(!areaCodeCheck(phoneNumber, !PARENTHESIS)){
                #if TEST_COMMENTS
                std::cout << "bad area code\n";
                #endif
                return false;
            }

            phoneNumber = phoneNumber.substr(3);
        }
        else{
            #if TEST_COMMENTS
            std::cout << "BAD AREA CODE\n";
            #endif
            //invalid area code, so invalid
            return false;
        } 
    }

    //Determine seperator
    {
        //check to see what the seperator symbol is
        if(phoneNumber[0] == '.' || phoneNumber[0] == '-'){
            #if TEST_COMMENTS
            std::cout << "good first seperator\n";
            #endif
            seperator = phoneNumber[0];
        } else {
            return false;
        }
    }
    

    //make the new phone number start from the exchange number
    phoneNumber = phoneNumber.substr(1);


    //Check the exchange numbers
    {
        if(!digitCheck(phoneNumber, 3)){
            return false;
        }
        #if TEST_COMMENTS
        std::cout << "good exchange code\n";
        #endif

        //remove the exchange code from string
        phoneNumber = phoneNumber.substr(3);

    }
    //check for next seperator
    if(phoneNumber[0] != seperator){
        
        return false;
    }
    #if TEST_COMMENTS
        std::cout << "good second seperator\n";
    #endif

    //make phone number just start from the additional digits
    phoneNumber = phoneNumber.substr(1);

    //Check the additional digits
    {
        //very similar function to exchange code check
        if(!digitCheck(phoneNumber, 4)){
            return false;
        }

        #if TEST_COMMENTS
        std::cout << "good additional digits\n";
        #endif


        //remove the addition digits from string
        phoneNumber = phoneNumber.substr(4);

    }

    //Check the extension
    {
        //NOTE: If there is no extension, the phone number size should be 0
        if(phoneNumber.size() == 0){
            #if TEST_COMMENTS
            std::cout << "good, no extension found\n";
            #endif
            return true;
        }

        //if there is a space, cut it out
        if(phoneNumber[0] == ' '){
            #if TEST_COMMENTS
            std::cout << "space found\n";
            #endif
            phoneNumber = phoneNumber.substr(1);
        }

    

        if(phoneNumber[0] == 'x' || phoneNumber[0] == 'X'){
            //there is an extension
            #if TEST_COMMENTS
            std::cout << "x found\n";
            #endif

            //remove the x
            phoneNumber = phoneNumber.substr(1);

            if(!digitCheck(phoneNumber, 4)){
                return false;
            }
            #if TEST_COMMENTS
            std::cout << "good extension digits\n";
            #endif

            //remove the extension digits
            phoneNumber = phoneNumber.substr(4);

            //phone number string should now be empty
            //if its not, then there are extra characters
            if(phoneNumber.size() != 0){
                return false;
            }
            #if TEST_COMMENTS
            std::cout << "good, now empty string\n";
            #endif

        }


    }

    return true;
}
bool areaCodeCheck(std::string areaCode, bool paranthesis){

    if(paranthesis){
     
        //Notice we dont have to check for first parenthesis
        //bc that happened in the phone check fxn



        //first number check
        if(!(areaCode[1] >= '2' && areaCode[1] <= '9')){
            //if first digit not from 0-9, return false
            return false;
        }



        //last 2 number check
        std::cin.get();
        for(int i = 2; i <= 3; i++){
            //check if last 2 numbers are digits
            if(!isdigit(areaCode[i])){  
                return false;
            }
        }


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
            return false;
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


    return false;
}

bool digitCheck(std::string expression, int ct){
    for(int i = 0; i < ct; i++){
        if(!isdigit(expression[i])){
            return false;
        }
    }
    return true;
}
