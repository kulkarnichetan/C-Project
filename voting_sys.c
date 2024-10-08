#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CANDIDATE_COUNT 4
#define CANDIDATE1 "Jhonny"
#define CANDIDATE2 "Rose"
#define CANDIDATE3 "George"
#define CANDIDATE4 "William"
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define VOTING_ID_DIGITS 4

int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, spoiledtvotes = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void castVote() {
    int age, choice, enteredVotingID;

    // Age verification
    printf("\n\n ### Age Verification ###\n");
    printf("Enter your age: ");
    scanf("%d", &age);

    if (age < 18) {
        printf("Sorry, you are not eligible to vote!\n");
        return;
    }

    // Generate a random 4-digit voting ID
    srand((unsigned int)time(NULL));
    int votingID = rand() % (int)(pow(10, VOTING_ID_DIGITS));

    printf("Your Voting ID: %04d\n", votingID);
    printf("Enter your Voting ID to cast your vote: ");
    scanf("%d", &enteredVotingID);

    if (votingID != enteredVotingID) {
        printf("Invalid Voting ID. Please try again.\n");
        return;
    }

    // Voting process
    printf("\n\n ### Please choose your Candidate ####\n\n");
    printf(" 1. %s\n", CANDIDATE1);
    printf(" 2. %s\n", CANDIDATE2);
    printf(" 3. %s\n", CANDIDATE3);
    printf(" 4. %s\n", CANDIDATE4);
    printf(" 5. Spoiled Vote\n");

    printf("\n Input your choice (1 - 5) : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: votesCount1++; break;
        case 2: votesCount2++; break;
        case 3: votesCount3++; break;
        case 4: votesCount4++; break;
        case 5: spoiledtvotes++; break;
        default: printf("\n Error: Wrong Choice !! Please retry");
                 getchar(); //hold the screen
    }
    printf("\n Thanks for voting!\n");
clearScreen();
    
}



void votesCount() {
    printf("\n\n ##### Voting Statistics ####");
    printf("\n %s - %d\n", CANDIDATE1, votesCount1);
    printf(" %s - %d\n", CANDIDATE2, votesCount2);
    printf(" %s - %d\n", CANDIDATE3, votesCount3);
    printf(" %s - %d\n", CANDIDATE4, votesCount4);
    printf(" %s - %d\n", "Spoiled Votes", spoiledtvotes);
}

void getLeadingCandidate() {
    printf("\n\n  #### Leading Candidate ####\n\n");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("[%s]\n", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("[%s]\n", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("[%s]\n", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("[%s]\n", CANDIDATE4);
    else
        printf("----- Warning !!! No-win situation----\n");
}
void adminlogin()
{
int validateLogin(const char *username, const char *password)

{
    const char *correctUsername = "admin";
    const char *correctPassword = "voting123";
     if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        return 1; // Return 1 if the login is successful
    } else {
        return 0; // Return 0 if the login fails
    }
}
char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    // Prompt the user to enter a username
    printf("Enter username: ");
    scanf("%s", username);

    // Prompt the user to enter a password
    printf("Enter password: ");
    scanf("%s", password);

    // Validate the entered username and password
    if (validateLogin(username, password)) {int n;
        printf("Login successful. Welcome, %s!\n", username);
        printf("\n1. Total votes");
        printf("\n2. Leading Party");
        printf("\nEnter your choice:-");
        scanf("%d",&n);
        switch(n){
            case 2:
                {printf("\n\n  #### Leading Candidate ####\n\n");
    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)
        printf("[%s]\n", CANDIDATE1);
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)
        printf("[%s]\n", CANDIDATE2);
    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)
        printf("[%s]\n", CANDIDATE3);
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)
        printf("[%s]\n", CANDIDATE4);
    else
        printf("----- Warning !!! No-win situation----\n"); break;}
            case 1: {
                printf("\n\n ##### Voting Statistics ####");
                printf("\n %s - %d\n", CANDIDATE1, votesCount1);
                printf(" %s - %d\n", CANDIDATE2, votesCount2);
                printf(" %s - %d\n", CANDIDATE3, votesCount3);
                printf(" %s - %d\n", CANDIDATE4, votesCount4);
                printf(" %s - %d\n", "Spoiled Votes", spoiledtvotes);
                break; }

}}
        else
        printf("Login failed. Incorrect username or password.\n");



}
void printInstructions() {
    printf("\n\n ###### Instructions for Using the Voting System #####\n");
    printf("\n 1. To cast your vote, choose option 1 and follow the prompts.");
    printf("\n 2. If you're an admin, choose option 2 to log in and view voting statistics.");
    printf("\n 3. Choose option 0 to exit the program.");
}


int main() {
    int choice;

    do {
        printf("\n\t\t\t\t\t ###### Welcome to Election #####");
        printf("\n\n 1. Cast the Vote");
        printf("\n 2. Admin login");
        printf("\n 3. Help");
        printf("\n 0. Exit");

        printf("\n\n Please enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: castVote(); break;
            case 2: adminlogin(); break;
            case 3: printInstructions(); break; 
            case 0: printf("\n Exiting the program. Goodbye!\n"); break;
            default: printf("\n Error: Invalid Choice\n");
        }
    } while (choice != 0);

    return 0;
}
