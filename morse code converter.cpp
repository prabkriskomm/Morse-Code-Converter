/* 
Author: Prabhat Krishna Kommineni  
Description: We will be converting Morse code to English and back and running a test file from the folder that implements the code and gives an output file.
Usage: C++
*/ 

#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;

//declaring english letters and their Morse code translations and using a function to integrate uppercase and uppercase letters
const char* englishToMorse(char item){
	item=toupper(item);
    if(item=='A')
        return ".-";
        
    if(item=='B')
        return "-...";
            
    if(item=='C')
        return "-.-.";
            
    if(item=='D')
        return "-..";
            
    if(item=='E')
        return ".";
        
     if(item=='F')
        return "..-.";
        
    if(item=='G')
        return "--.";
        
    if(item=='H')
        return "....";
        
    if(item=='I')
        return "..";
        
    if(item=='J')
        return ".---";
        
    if(item=='K')
        return "-.-";
        
    if(item=='L')
        return ".-..";
        
    if(item=='M')
        return "--";
        
    if(item=='N')
        return "-.";
        
    if(item=='O')
        return "---";
        
    if(item=='P')
        return ".--.";
        
    if(item=='Q')
        return "--.-";
        
    if(item=='R')
        return ".-.";
        
    if(item=='S')
        return "...";
        
    if(item=='T')
        return "-";
        
    if(item=='U')
        return "..-";
        
    if(item=='V')
        return "...-";
        
    if(item=='W')
        return ".--";
        
    if(item=='X')
        return "-..-";
        
    if(item=='Y')
        return "-.--";
        
    if(item=='Z')
        return "--..";
            
    if(item==' ')
        return "/";
            
    if(item=='\r')
        return "\r";
            
    if(item=='\n')
        return "\n";
    return "!!!!!";
}

//Morse code to english using character variable
char MorseToEnglish (const char* token){
    char a;
    if (strcmp(token, ".-") == 0){
        a= 'A';
    } else if (strcmp(token, "-...") == 0){
        a ='B';
    } else if (strcmp(token, "-.-.") == 0){
        a= 'C';
    } else if (strcmp(token, "-..") == 0){
        a= 'D';
    } else if (strcmp(token, ".") == 0){
        a= 'E';
    } else if (strcmp(token, "..-.") == 0){
        a= 'F';
    } else if (strcmp(token, "--.") == 0){
        a= 'G';
    } else if (strcmp(token, "....") == 0){
        a= 'H';
    } else if (strcmp(token, "..") == 0){
        a= 'I';
    } else if (strcmp(token, ".---") == 0){
        a= 'J';
    } else if (strcmp(token, "-.-") == 0){
        a= 'K';
    } else if (strcmp(token, ".-..") == 0){
        a= 'L';
    } else if (strcmp(token, "--") == 0){
        a= 'M';
    } else if (strcmp(token, "-.") == 0){
        a= 'N';
    } else if (strcmp(token, "---") == 0){
        a= 'O';
    } else if (strcmp(token, ".--.") == 0){
        a= 'P';
    } else if (strcmp(token, "--.-") == 0){
        a= 'Q';
    } else if (strcmp(token, ".-.") == 0){
        a= 'R';
    } else if (strcmp(token, "...") == 0){
        a= 'S';
    } else if (strcmp(token, "-") == 0){
        a= 'T';
    } else if (strcmp(token, "..-") == 0){
        a= 'U';
    } else if (strcmp(token, "...-") == 0){
        a= 'V';
    } else if (strcmp(token, ".--") == 0){
        a= 'W';
    } else if (strcmp(token, "-..-") == 0){
        a= 'X';
    } else if (strcmp(token, "-.--") == 0){
        a= 'Y';
    } else if (strcmp(token, "--..") == 0){
        a= 'Z';
    }
    return a;
}

const char* englishToMorse(char);
char MorseToEnglish (const char*);
int main(int argc, char** argv){
    if(argv[1]==NULL || argv[2]==NULL || argv[3]==NULL || (strcmp(argv[2], "-bc")!=0 && strcmp(argv[2],"-e")!=0)){
        printf("Error -- usage: <exe> <input file> <-bc|-e> <output file>\n");
        return 0;
    }
    //check if processs in english to morse or morse to english
    if(strcmp(argv[2],"-e")==0){
        ifstream inpt;         //ifstream is inputting the test file
        inpt.open(argv[1]);
        ofstream otpt;         //ofstream is outputting the test file
        otpt.open(argv[3]);
        char parsestring[255];

        while(inpt.getline(parsestring,1530)){
            const char* tok ((const char*)strtok(parsestring,"|\r"));  //parsestring is the line of the test file provided
            while(tok!=NULL){
                otpt<<MorseToEnglish(tok);
                tok=strtok(NULL,"|\r");
            }
            otpt<<"\r";
            otpt<<"\n";
        }
        inpt.close();
        otpt.close();
        cout<<"File Completed"<<endl; //make sure cursor is in the beginning
    }
    //check if processs in english to morse or to english
    if(strcmp(argv[2], "-bc")==0){
        ifstream inpt;
        inpt.open(argv[1]);
        ofstream otpt;
        otpt.open(argv[3]);

        char parsestring[255];
        while(inpt.getline(parsestring,255)){
            int len=strlen(parsestring);
            for (int i=0;i<len;i++){
                if(i==len-1)
                    otpt<<englishToMorse(parsestring[i]);
                else
                    otpt<< ((string)englishToMorse(parsestring[i])+'|');
            
            }
            otpt<<"\n";
        }
        inpt.close();
        otpt.close();
        cout<<"File Completed"; //make sure cursor is in the beginning
    }
    return 0;
}