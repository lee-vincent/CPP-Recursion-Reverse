//
//  main.cpp
//  lab4
//
//  Created by Vincent Lee on 10/22/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include <iostream>
#include <string>

/*Function Prototypes*/
void RecRevStr(std::string);
int RecCalcArr(int[], int);
int RecCalcTri(int);
void RecursionExamples();

int main() {
    RecursionExamples();
    return 0;
}


void RecursionExamples(){
    std::cout << std::endl;
    
    int selection;
    
    std::cout << "--OPTIONS--\n";
    std::cout << "1: Reverse String\n";
    std::cout << "2: Sum Array\n";
    std::cout << "3: Triangular Number\n";
    std::cout << "4: Quit Program\n";
    std::cout << "\nEnter Option: ";
    std::cout << std::endl;
    std::cin >> selection;
    
    if(selection == 1) {
        std::string str;
        std::cout << "Enter string to be reversed: ";
        std::cin >> str;
        std::cout << "\nResult: ";
        RecRevStr(str);
    
    } else if(selection == 2) {
        std::string numStr;
        std::cout << "Enter digits to sum (no spaces): ";
        std::cin >> numStr;
        std::cout << std::endl;
        
        int arr[numStr.length()];

        for(int i = 0; i < numStr.length(); i++) {
            arr[i] = numStr[i] - '0';
        }
        
        std::cout << "\nResult: " << RecCalcArr(arr, (int)numStr.length()) << std::endl;
    
    } else if(selection == 3) {
        int num;
        std::cout << "Enter number of rows: ";
        std::cin >> num;
        std::cout << "\nResult: " << RecCalcTri(num) << std::endl;
        
    } else if(selection == 4) {
        std::cout << "Bye, have a great day!" << std::endl;
        return;
        
    } else {
        std::cout << "\nInvalid Selection" << std::endl;
    }
    
    RecursionExamples();

}



void RecRevStr(std::string str){
    
    if(str.length() == 1) {
        std::cout << str << '\n';
    } else {
        std::cout << str[str.length()-1];
        RecRevStr(str.substr(0, str.length()-1));
    }
}

int RecCalcArr(int in[], int num){

    if(num == 1) {
        return in[0];
    } else {
        num--;
        return in[num] + RecCalcArr(in, num);
    }
}

int RecCalcTri(int base) {
    return base == 1 ? 1 : base + RecCalcTri(base - 1);
}