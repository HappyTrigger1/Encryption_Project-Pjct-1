#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>



//Function Prototypes For Rotation
void rotEncrypt(char arr[], int u);               

//Function Prototypes for Substitution
void subEncrypt(char *message);
void subDecrypt(char *message);                                      






//Main code command/flow control
int main(){
    FILE *input;
    //FILE *output;
    input = fopen("input.txt", "r+");
    //output = fopen("output.txt", "w");
    
 
    
    fprintf(input, "Enter 1 for rotation or 2 for substitution, then hit 'run' to start: ");
    int select = 0;
    fscanf(input, "%d", &select);
     
    switch (select) { 
       case 1:  fprintf(input, "\nRotation Cipher");
                fprintf(input, "\nKey: ");
                int u = 0;
                fscanf(input, "%d", &u);
                fprintf(input, "\nPress run after message and key entered to encrypt message. Then view the terminal for encrypted text.");
                fprintf(input, "\nType Message: "); 
                
                char c[10000];
                int i = 0;
                
                
                while(feof(input) == 0){
                    fscanf(input, "%c", &c[i]);                    //Scans words from input.txt file
                    i++;
                }

                rotEncrypt(c, u);                                     //Encrypts the words from input.txt
                    break; 


                    
       case 2:  fprintf(input, "\nSubstitution Cipher");
                fprintf(input, "\nPress run after message entered to encrypt message. Then view the terminal for encrypted text.");
                fprintf(input, "\nType Message: "); 
                
                char message[10000];
                int b = i-1;
                
                while(feof(input) == 0){
                    fscanf(input, "%c", &message[i]);                    //Scans words from input.txt file
                    i++;
                }
    
                /*f*/printf(/*output,*/ "Substitution Cipher\n");
                /*f*/printf(/*output,*/ "Encrypted (Substitution, no spaces) Text: ");
                subEncrypt(message);                           //Encrypts message
    
                for(i = 0; i < b;){
                /*f*/printf(/*output,*/ "%c", message[i]);
                i++;
                }
    
                /*f*/printf(/*output,*/ "\nDecrypted (Substitution, no spaces) Text: ");
                subDecrypt(message);
                for(i = 0; i < b;){
                /*f*/printf(/*output,*/ "%c", message[i]);
                i++;
                }
                    break; 
                    
       default: fprintf(input, "\nPlease enter an integer 1 or 2                                                                                                            "); 
                printf("No input found in 'input.txt' file... \nPlease open 'input.txt' or create a text file called 'input.txt' before using program.");    
                    break;   
     }
}








//Function Definitions for Rotation
//Function definition for encryption/decryption
void rotEncrypt(char arr[], int u){
    //FILE *output;                                     //Establishes a file output.txt
    //output = fopen("output.txt", "w");                //Sets up file output.txt for writing
    int i;
    /*f*/printf(/*output, */"Rotation Cipher");   
    /*f*/printf(/*output, */"\nKey: %d", u);
    /*f*/printf(/*output, */"\nEncrypted (Rotation, encrypted spcaes) Message: ");
    
    
    for(i = 0; i < strlen(arr); i++){
        arr[i] = arr[i] + u;                          //Shifts letters across 1 for encryption
        /*f*/printf(/*output, */"%c", arr[i]);                //Writes the encrypted word to output.txt
        }
      
    /*f*/printf(/*output, */"\nDecrypted (Rotation) Message: ");
    int k;
    
    for(k = 0; k < strlen(arr); k++){
        arr[k] = arr[k] - u;                          //shifts letters across 1 for encryption
        /*f*/printf(/*output, */"%c", arr[k]);                //Writes the decrypted word to output.txt
        }
}

  




//Function Definitions for Substitution
//Function definition for encryption
void subEncrypt(char *message){
    //FILE *output;
    //output = fopen("output.txt", "w");
    int length = strlen(message);
    int encryption_index;
    char code[26] = {'g','l','c','d','s','t','b','x','y','j','k','m','a','o','n','p','q','r','e','f','u','v','w','z','i','h'};          //Substitution "alphabet"     
    for(int i = 0; i < length; i++)
    {
        encryption_index = tolower(message[i]) - 'a';
                    
        if(encryption_index >= 0 && encryption_index < 26)
        {
            message[i] = code[encryption_index];
            /*f*/printf(/*output,*/ "%c", message[i]);
        }   
    }
}

//Function definition for decryption
void subDecrypt(char *message){
    //FILE *output;
    //output = fopen("output.txt", "w");
    int length = strlen(message);
    char code[26] = {'g','l','c','d','s','t','b','x','y','j','k','m','a','o','n','p','q','r','e','f','u','v','w','z','i','h'};
    int j = 0; 
    
    for(int i = 0; i < length; i++){
        j = 0;
        while(code[j] != message[i] && j < 26){
             j++;
        }
        if(j >= 0 && j < 26){
            message[i] = (j + 'a');
            /*f*/printf(/*output,*/ "%c", message[i]);
        }        
    }
}   
    
    



