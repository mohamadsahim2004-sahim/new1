// Voting
void vote() {
    int age;
    char nic[20];
    int candidate_no;
    int found = 0;

    printf("enter your age only eligible(18 or above 18): ");
    scanf("%d", &age);

    if (age < 18) {
        printf("You are not eligible to vote.\n");
        return;
    }

    printf("enter your 12 digit NIC no: ");
    scanf("%s", nic);

    printf("\n-------VOTE-------\n\n   Bullet____paper\n\n");

    // Array of parties
    Candidate *parties[] = {partyA, partyB, partyC, partyD, partyE};
    char partyLabels[] = {'A', 'B', 'C', 'D', 'E'};

    for (int p = 0; p < 5; p++) {
        printf("  Party %c   candidate no\n", partyLabels[p]);
        for (int i = 0; i < MAX_CANDIDATES; i++) {
            if (parties[p][i].registered) {
                printf("%d.%s \t%02d\n", i + 1, parties[p][i].name, parties[p][i].candidate_no);
            } else {
                printf("%d.candidate \t00\n", i + 1);
            }
        }
        printf("\n");
    }

    printf("choose your candidate using their candidate number(2 digit): ");
    scanf("%d", &candidate_no);

    for (int p = 0; p < 5 && !found; p++) {
        for (int i = 0; i < MAX_CANDIDATES; i++) {
            if (parties[p][i].registered && parties[p][i].candidate_no == candidate_no) {
                parties[p][i].votes++;
                found = 1;

                // Save updated votes
                switch (p) {
                    case 0: saveCandidatesToFile(partyA, PARTY_A_FILE); break;
                    case 1: saveCandidatesToFile(partyB, PARTY_B_FILE); break;
                    case 2: saveCandidatesToFile(partyC, PARTY_C_FILE); break;
                    case 3: saveCandidatesToFile(partyD, PARTY_D_FILE); break;
                    case 4: saveCandidatesToFile(partyE, PARTY_E_FILE); break;
                }
                break;
            }
        }
    }

    if (found)
        printf("your vote accepted. Thank you!\n");
    else
        printf("Invalid candidate number. Vote not counted.\n");
}

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