/*
Rotation and Substitution Cipher

This code will allow a user to select the use of either rotation cipher or a substitution cipher to encrypt and decrypt text of their choosing. 
The code operates by using various functions that are used for each method of encryption and decryption. For the rotation cipher, one function is used for 
both encryption and decryption, whereas for the substitution cipher two functions are used, one for encryption and one for decryption. 
This program will take ALL input from a input file called 'input.txt', once the program is run initially, some instructions will appear inside he input.txt
file OR on the terminal, prompting the user on how to use the program. The program uses switch case statements in order to destinguish between the use of a
rotation cipher or the use of the substitution cipher. If the correct operation integer is entered, the program jumps to the corresponding case and runs
that code. Code for the different cipher is placed inside tow separate cases. A defult case is used should the user enter the wrong initial input data. 

USE: 
It is advised that any user BEFORE using this program has a file called 'input.txt' already avaliable with NOTHING inside it. All the user does now is
hit run, and the program will guide them through the process of how to use the code. Again, ALL input is taken from the input.txt file. And ALL output is
displayed within the terminal for ease of use. 

Note: 
This program was originally written to have both input and output going to files. Input coming from input.txt and output going to output.txt. The 
program has been modified to have input from input.txt and output to stdout. To change the program back to the original state, check ALL commented fprintf statements
and uncomment the commented out 'f' in fprintf and uncomment the 'output' in fprintf(output, "example"). ALSO be sure to uncomment the 'FILE *output;' and 
output = fopen("output.txt", "w");. After this, the program will no longer send output to the terminal, instead sending ALL output to output.txt. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


//Function Prototypes For Rotation
void rotEncrypt(char arr[], int u);               
//Function Prototypes for Substitution
void subEncrypt(char *message);
void subDecrypt(char *message);                                      


//Main code/control centre 
int main(){
    FILE *input;                                                //Establishes input.txt file. 
    //FILE *output;
    input = fopen("input.txt", "r+");                           //Opens file input.txt for reading and writing. 
    //output = fopen("output.txt", "w");
         
    fprintf(input, "Enter 1 for rotation or 2 for substitution, then hit 'run' to start: ");
    int select = 0;                                             //Initialising the select variable to 0. 
    fscanf(input, "%d", &select);                               //Scans for the integer that will start the program that is stored in 'select'. 
     
    //Switch case statements, used to switch between whicever program the user wants to use. 
    switch (select) {
       //Case for the rotation cipher to run
       case 1:  fprintf(input, "\nRotation Cipher");
                fprintf(input, "\nEnter a key between 1 and 11: ");
                int u = 0;                                      //u is the cipher key
                fscanf(input, "%d", &u);
                fprintf(input, "\nPress run after message and key entered to encrypt message. Then view the terminal for encrypted text.");
                fprintf(input, "\nType Message: "); 
                
                char c[10000];                                  //Setting array size of c to be 10000 characters long. 
                int i = 0;
                                
                while(feof(input) == 0){
                    fscanf(input, "%c", &c[i]);                 //Scans words from input.txt file character by character and stores in message[i]
                    i++;
                }

                rotEncrypt(c, u);                               //Encrypts the words from input.txt in rotEncrypt function. 
                    break; 
       //Case for the substitution cipher to run             
       case 2:  fprintf(input, "\nSubstitution Cipher");
                fprintf(input, "\nPress run after message entered to encrypt message. Then view the terminal for encrypted text.");
                fprintf(input, "\nType Message: "); 
                char message[10000];                            //Setting array size of message to be 10000 characters long.
                int b = i-1;
                while(feof(input) == 0){
                    fscanf(input, "%c", &message[i]);           //Scans words from input.txt file character by character and stores in message[i]
                    i++;        
                }
                fprintf(input, "\n                                                                   ");                                            
    
                /*f*/printf(/*output,*/ "Substitution Cipher\n");
                /*f*/printf(/*output,*/ "Encrypted (Substitution, no spaces) Text: ");
                subEncrypt(message);                            //Encrypts message using encrypt function. 
    
                for(i = 0; i < b;){
                    i++;
                }
    
                /*f*/printf(/*output,*/ "\nDecrypted (Substitution, no spaces) Text: ");
                subDecrypt(message);                            //Decrypts message using decrypt function. 
                for(i = 0; i < b;){
                   /*f*/printf(/*output,*/ "%c", message[i]);
                   i++;
                }
                    break; 
       //Print this if either nothing is entered in input.txt OR an invalid integer is entered.              
       default: fprintf(input, "\nPlease enter an integer 1 or 2                                                                                                            ");
                printf("No input found in 'input.txt' file... \nPlease open 'input.txt' or create a text file called 'input.txt' before using program.");    
                    break;   
     }
}




//Function Definition for Rotation
/*
Inputs: char of the array 'arr[]' and an integer u 'int u'. Where arr[] contains the message information in form of string and 
int u contains the key for the cipher as in integer.  

Return value: This is a void function and doesn't actually 'return' anything to main BUT, it does print out each encrypted and 
decrypted letter of text individually with a printf in a for loop.. 

Functionality: Initially some printf statements are used in order to give the user some feedback from the terminal. This function 
will for encryption; take an array of type char, each character is given with position 'i', then that position is shifted by a key 
'u', and then printed out. 
This is in a for loop and will continue to occure until all characters have been shifted. 
For decryption, EXACTLY the same process at encryption occurs HOWEVER instead of adding the value of the key 'u' to each indexed 
character, it is subtracted to revert the shift. 
Again this decryption occures individually for each letter and letters are printed to the terminal.

Restrictions: The amount of characters that this program can handle is limited to 10000, anything over this and the function will 
not be able to process them (encryption just stops after 10000). 
Unfortunately, this program also does encrypt white space, not sure how to fix this. 
The key entered can ONLY be between 1 and 11, in order for the function to spit out actual english letters. If 'u' is more than 11, 
strange symbols are printed. 
For 'u' and 'arr[]', 'u' can ONLY be an integer betweeb 1 and 11. And 'arr[]' can ONLY be text. Lowcase and uppercase are accepted. 
*/
void rotEncrypt(char arr[], int u){
    //FILE *output;                                             //Establishes a file output.txt
    //output = fopen("output.txt", "w");                        //Sets up file output.txt for writing
    int i;
    /*f*/printf(/*output, */"Rotation Cipher");   
    /*f*/printf(/*output, */"\nKey: %d", u);
    /*f*/printf(/*output, */"\nEncrypted (Rotation, encrypted spcaes) Message: ");
    
    
    for(i = 0; i < strlen(arr); i++){
        arr[i] = arr[i] + u;                                    //Shifts letters across 'u' for encryption
        /*f*/printf(/*output, */"%c", arr[i]);                  //Writes the encrypted word to terminal OR output.txt
        }
      
    /*f*/printf(/*output, */"\nDecrypted (Rotation) Message: ");
    int k;
    
    for(k = 0; k < strlen(arr); k++){
        arr[k] = arr[k] - u;                                    //shifts letters back 'u' for decryption
        /*f*/printf(/*output, */"%c", arr[k]);                  //Writes the decrypted word to terminal OR output.txt
        }
}

  

//Function Definitions for Substitution
//Function definition for encryption
/*
Inputs: This function takes in a char of a pointer to a message which is a char limited to 10000 characters in size. 

Return Value: This is a void function and doesn't actually 'return' anything to main BUT, it does print out each encrypted 
letter of text individually with a printf in an if loop. 

Functionality: This function takes in a char 'message', then gets the length of the string using the predefined function 'strlen' and stores this 
inside integer 'length'. A cipher alphabet is made as a char array. Then, in a for loop, encryption of the message is done. First, all of the message, character by character
is made lower case by the predefined function 'tolower', and each character has the ASCII value of 'a'(97) subtracted from it and then this is stored in
encryption_index. 
Within a nested if loop, if this new integer in encryption index is between 0 and 26, then, encryption_index is passed into the 'code' array which is the
cipher alphabet to encrypt the intagers. This is stored within message[i] again, character by character. Then message[i] is printed to the terminal. 

Restrictions: This function ignored ALL white space during encryption, this makes it somewhat confusing to look at. Because it takes away white space
in encryption, then the decrypted text has also got no white space. 
Also *message is limited to 10000 characters in length. Anything over this will not be encrypted. 

*/
void subEncrypt(char *message){
    //FILE *output;
    //output = fopen("output.txt", "w");
    int length = strlen(message);                               //Gets length of string. 
    int encryption_index;
    char code[26] = {'g','l','c','d','s','t','b','x','y','j','k','m','a','o','n','p','q','r','e','f','u','v','w','z','i','h'};          //Substitution "alphabet"     
    for(int i = 0; i < length; i++){
        encryption_index = tolower(message[i]) - 'a';           //Does the encryption by subtracting ASCII of 'a' from each letter of the message. 
                    
        if(encryption_index >= 0 && encryption_index < 26){     
            message[i] = code[encryption_index];
            /*f*/printf(/*output,*/ "%c", message[i]);          //Prints encrypted message to the terminal OR output.txt
        }   
    }
}

//Function definition for decryption
/*
Inputs: This function takes in a char of a pointer to a message which is a char limited to 10000 characters in size. This message that is collected in
this function has ALREADY BEEN ENCRYPTED. 

Return Value: This is a void function and doesn't actually 'return' anything to main BUT, it does print out each decrypted 
letter of text individually with a printf in an if loop. 

Functionality: This function takes in a char 'message' which has already been encrypted, then gets the length of the string using the predefined 
function 'strlen' and stores this inside integer 'length'. A cipher alphabet is made as a char array. Then in a for loop that allows for each characted to 
be decrypted individually, an integer j is created. Within a nested while loop, the 'code[]' index of j is measured to not between int value of message
and 26, then j index continues through. Outside the nested while loop, the value of j is now used to define how message[i] is decrypted. Basically, how each
character gets decrypted letter by letter. instead of subtracting 'a', 'a' is added to j and then this value is stored in message[i]. message[i] is then 
printed to the terminal. This prints each decrypted letter one at a time. 
 

Restrictions: This function ignored ALL white space during encryption, this makes it somewhat confusing to look at. Because it takes away white space
in encryption, then the decrypted text has also got no white space. 
Also *message is limited to 10000 characters in length. Anything over this will not be encrypted. 

*/
void subDecrypt(char *message){
    //FILE *output;
    //output = fopen("output.txt", "w");
    int length = strlen(message);
    char code[26] = {'g','l','c','d','s','t','b','x','y','j','k','m','a','o','n','p','q','r','e','f','u','v','w','z','i','h'};          //Substitution "alphabet"     
    int j = 0; 
    
    for(int i = 0; i < length; i++){
        j = 0;
        while(code[j] != message[i] && j < 26){
             j++;
        }
        if(j >= 0 && j < 26){
            message[i] = (j + 'a');
            /*f*/printf(/*output,*/ "%c", message[i]);          //Prints decrypted message to the terminal OR output.txt
        }        
    }
}   