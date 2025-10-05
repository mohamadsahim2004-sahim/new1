// Candidate Registration
void registerCandidate() {
    Candidate newCandidate;
    printf("\n------CANDIDATE REGISTER------\n\n");

    printf("enter your username: ");
    scanf("%s", newCandidate.username);

    printf("enter your name: ");
    scanf("%s", newCandidate.name);

    printf("enter your candidate number: ");
    scanf("%d", &newCandidate.candidate_no);

    printf("choose your party(A,B,C,D,E): ");
    scanf(" %c", &newCandidate.party);

    newCandidate.votes = 0;
    newCandidate.registered = 1;

    Candidate *partyList = NULL;

    switch (newCandidate.party) {
        case 'A': case 'a':
            partyList = partyA;
            break;
        case 'B': case 'b':
            partyList = partyB;
            break;
        case 'C': case 'c':
            partyList = partyC;
            break;
        case 'D': case 'd':
            partyList = partyD;
            break;
        case 'E': case 'e':
            partyList = partyE;
            break;
        default:
            printf("Invalid party.\n");
            return;
    }

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (!partyList[i].registered) {
            partyList[i] = newCandidate;
            printf("\nYou are successfully registered....\n");

            // Save updated party list
            switch (newCandidate.party) {
                case 'A': case 'a': saveCandidatesToFile(partyA, PARTY_A_FILE); break;
                case 'B': case 'b': saveCandidatesToFile(partyB, PARTY_B_FILE); break;
                case 'C': case 'c': saveCandidatesToFile(partyC, PARTY_C_FILE); break;
                case 'D': case 'd': saveCandidatesToFile(partyD, PARTY_D_FILE); break;
                case 'E': case 'e': saveCandidatesToFile(partyE, PARTY_E_FILE); break;
            }
            return;
        }
    }

    printf("\nRegistration failed. Max candidates reached for Party %c.\n", newCandidate.party);
}

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