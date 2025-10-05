// Main Menu
int main() {
    int choice;

    // Load party data from files
    loadCandidatesFromFile(partyA, PARTY_A_FILE);
    loadCandidatesFromFile(partyB, PARTY_B_FILE);
    loadCandidatesFromFile(partyC, PARTY_C_FILE);
    loadCandidatesFromFile(partyD, PARTY_D_FILE);
    loadCandidatesFromFile(partyE, PARTY_E_FILE);

    while (1) {
        printf("\n--------------------------------------------------\n");
        printf("      Welcome to the Election Voting System       \n");
        printf("--------------------------------------------------\n");
        printf("1. Voting Candidates\n");
        printf("2. Candidate Register\n");
        printf("3. Officials\n");
        printf("4. Exit\n");
        printf("--------------------------------------------------\n");
        printf("What is your purpose? Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vote();
                break;
            case 2:
                registerCandidate();
                break;
            case 3:
                viewOfficials();
                break;
            case 4:
                printf("    Exit.....\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}