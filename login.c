#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100

struct User {
    char username[50];
    char password[50];
};

struct User users[MAX_USERS];
int num_users = 0;

bool check_username_exist(const char *username) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return true;
        }
    }
    return false;
}

void save_credentials(const char *username, const char *password) {
    if (num_users >= MAX_USERS) {
        printf("Maximum number of users reached. Cannot add more users.\n");
        return;
    }

    strcpy(users[num_users].username, username);
    strcpy(users[num_users].password, password);
    num_users++;
}

bool authenticate(const char *username, const char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    char username[50];
    char password[50];

    while (1) {
        printf("1. Register\n2. Login\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);

                if (check_username_exist(username)) {
                    printf("Username already exists. Please try again.\n");
                    break;
                }

                printf("Enter password: ");
                scanf("%s", password);

                save_credentials(username, password);
                printf("Registration successful.\n\n");
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);

                if (!check_username_exist(username)) {
                    printf("Username not found. Please register first.\n\n");
                    break;
                }

                printf("Enter password: ");
                scanf("%s", password);

                if (authenticate(username, password)) {
                    printf("Login successful.\n\n");
                } else {
                    printf("Invalid password. Please try again.\n\n");
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}

