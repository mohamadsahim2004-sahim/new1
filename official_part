// Officials View
void viewOfficials() {
    char password[20];

    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(password, PASSWORD) != 0) {
        printf("Incorrect password. Access denied.\n");
        return;
    }

    printf("\n------OFFICIALS--------\n\n");
    printf("   MATARA DISTRICT VOTE COUNTS\n\n");

    Candidate *parties[] = {partyA, partyB, partyC, partyD, partyE};
    char partyLabels[] = {'A', 'B', 'C', 'D', 'E'};

    for (int p = 0; p < 5; p++) {
        printf("  Party %c   Candidate_No  Votes\n\n", partyLabels[p]);
        for (int i = 0; i < MAX_CANDIDATES; i++) {
            if (parties[p][i].registered) {
                printf("%d.%s \t%02d         %02d\n", i + 1, parties[p][i].name,
                       parties[p][i].candidate_no, parties[p][i].votes);
            } else {
                printf("%d.candidate\t00         00\n", i + 1);
            }
        }
        printf("\n");
    }
} 
