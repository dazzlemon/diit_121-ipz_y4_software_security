#include <stdio.h>
#include <string.h>
#define PASSWORD_SIZE 100
#define PASSWORD "myGOODpassword\n"

int main() {
	char buff[PASSWORD_SIZE];
	bool authenticated = false;
	for ( int attemptsCount = 0
	    ; attemptsCount < 3 && !authenticated
			; attemptsCount++
			) {
		printf("Enter password: ");
		fgets(&buff[0], PASSWORD_SIZE, stdin);
		if (strcmp(&buff[0], PASSWORD)) {
			printf("Wrong password\n");
		} else {
			authenticated = true;
		}
	}
	if (!authenticated) {
		return -1;
	}
	printf("Password OK\n");
	
	return 0;
}