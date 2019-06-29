#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

//function returns true if a keyword listed is found
int keywordChecker(char keyBuffer[]){

    char listKeywords[50][20] = {"auto","begin","break","case","char","const","continue","default",

        "define","display","do","double","else","endif","endfun","enum","extern","float","for","function","goto",

        "if","implementations","import","input","int","is","long","main","not","of","pointer","register",

	"return","set","short","signed",

        "sizeof","static","struct","switch","type","typedef","union",

        "unsigned","void","variable","variables","volatile","while" };
    //initializes scan flag, acts as a flagger for execution
    int i, scanFlag = 0;
    //here we compare 2 strings, looping through all keywords for 1 of them
    //sets scan flag to 1 after succesful comparison finding
    for(i = 0; i < 50; ++i){
        if(strcmp(listKeywords[i], keyBuffer) == 0){
            scanFlag = 1;
            break;
        }
    }
    return scanFlag;
}
int main(){
	cout << "\n\nTo change the name of the file to scan, you must change it, on the 3rd line in main(). It is currently scl.h " << endl;
	cout << "\n\nTo change the name of the output file for the scanner, you must change it from line 47 in main(). It is currently scannerOutput.txt " << endl;
 
	string toContinueString;
	cout << "\nTo continue, type any characters and then press enter:\n" << endl;
	cin >> toContinueString;

    char scanChar, keyBuffer[15], operators[] = "\"+-*/%=";//initializing
    ifstream scannerFileIn("scl.h");//looks for a file called scannerinput.txt
    int i,j=0;
//error handling, if unable to open
    if(!scannerFileIn.is_open()){
        cout<<"error  opening the file \n";
        exit(0);
    }
    //while  program  is not at end of file(EOF) get the characters in it
    std::ofstream outputFile ("scannerOutput.txt");

    outputFile << "Below is the output from the scanner program:" << std::endl;

    while(!scannerFileIn.eof()){
        scanChar = scannerFileIn.get();
       //loop checks if the string has an operator, will print the operator value and write to an output file as well
        for(i = 0; i < 6; ++i){
            if(scanChar == operators[i]) {
                cout << scanChar << " is an operator \n";
                outputFile << scanChar << " is an operator \n";
            }
        }
        //i check to see if char is alphanumeric (isalnum)
        if(isalnum(scanChar)){
            keyBuffer[j++] = scanChar;
        }
        // if scanChar is equal to '' or \n and j is not zero then execute with keyBuffer for key word check
        //if the keyBuffer of the keyword is set to 1, it identifies as a key word
        //if it does not meet any, than it is an identifier
        else if((scanChar == ' ' || scanChar == '\n') && (j != 0)){
            keyBuffer[j] = '\0';
            j = 0;
            if(keywordChecker(keyBuffer) == 1) {
                cout << keyBuffer << " is a keyword \n";
                outputFile << keyBuffer << " is a keyword \n";
            }
            else {
                cout << keyBuffer << " is an indentifier \n";
                outputFile << keyBuffer << " is an indentifier \n";
            }
        }
    }

    outputFile.close();
    //close file and exit program
    scannerFileIn.close();


    return 0;
}

