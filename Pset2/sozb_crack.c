//SAIDOU OUSSEINI ZIKA BINTA

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>\


int main (int argc, char* argv[])
{
    // check if the computer is taking the 1 argc
    while (argc !=2 )
    {
         printf("Error,you have to try again: \n");
         return 1;
    }

    //get a password that is alphabet
    char* password=get_string(" ");
    password= "ABCDEFGHIJKLMNOPQRXTUVWXYZabcdefghijklmnopqrstuvwxyz";


    //the second argumeent is the hashed password
   char* hashpass=argv[1];

   //salt: the two first charaters of the hashed password are numbers and salt[2] is to show the end.
    char salt[3];
    /*salt[0] = hashpass[0];
    salt[1] = hashpass[1];
    salt[2] = 0;*/

    //memeoiry for the copy
    memcpy(salt, hashpass , 2);

        //iteration of the digits 4
    for (int x = 0; x<strlen(password);x++)
    {
            //iteration of the digits 3
        for (int y = 0; y<strlen(password);y++)
        {
                //iteration of the digits 2
            for (int z =0; z <strlen(password);z++ )
            {
                    //iteration of the digits 1
                for (int i = 0; i <strlen(password); i++)
                    {
                        char pass[5];
                        pass[0] = password[i];
                        pass[1]=password[z];
                        pass[2]=password[y];
                        pass[3]=password[x];
                            // for the aka null
                        pass[4]='\0';


                        // Get the encrypted password using crypt function and the output
                        if (strcmp(crypt(pass, salt),hashpass))
                            {
                                printf("%s",pass);
                            }
                    }
            }

        }
    }
      printf("\n");
      return 0;
}


