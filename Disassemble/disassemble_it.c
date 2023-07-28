#include <stdio.h>
#include <string.h>
int check_pass(char * password){
    
    char real_password [10] = "hello!";
    if (strcmp(password,real_password) == 0)
        return 1;
    else 
        return 0;

}

int main(){
    char nickname_buffer[10];
    char password_buffer[10];
    int identifier = 0;

    printf("Welcome to the authorization system please enter a username:");
    scanf("%s",&nickname_buffer); 
    printf("Password: ");
    scanf("%s",&password_buffer);

    identifier = check_pass(password_buffer);
    
    if(identifier == 1){
        printf("log in successfull \n");
        if(strlen(nickname_buffer) >= 2 && nickname_buffer[0] == '1' && nickname_buffer[1] == '0' )
            printf("Authorized User");
        else
            printf("Unauthorized User");

    }else
        printf("wrong password or username. System is shutting down..");

    
    return 0;

}