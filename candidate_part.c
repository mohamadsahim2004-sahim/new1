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
