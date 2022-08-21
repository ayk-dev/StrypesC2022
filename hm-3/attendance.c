#include <stdio.h>
#include <stdint.h>

void setBit(uint64_t* mask, unsigned bit);
void clearBit(uint64_t* mask, unsigned bit);
void flipBit(uint64_t* mask, unsigned bit);
int checkBit(uint64_t mask, unsigned bit);
void printAttendancies(uint64_t mask);

int main(){
    uint64_t attendancies = 0;
    int option;
    unsigned student;
    // TODO - add validations for invalid option or student number

    printf("1. Set attendance\n");
    printf("2. Clear attendance\n");
    printf("3. Attendance info\n");
    printf("4. Change attendance\n");
    printf("5. Exit\n");

    scanf("%d", &option);

    while (1) {
        if (option == 5)
            break;
    
        if (option == 1)
        {
            printf("Enter student number: ");
            scanf("%u", &student);
            setBit(&attendancies, student);
        }
        else if (option == 2)
        {
            printf("Enter student number: ");
            scanf("%u", &student);
            clearBit(&attendancies, student);
        }
        else if (option == 3)
        {
           printAttendancies(attendancies);
        }
        else if (option == 4)
        {
            printf("Enter student number: ");
            scanf("%u", &student);
            flipBit(&attendancies, student);
        }
        printf("Choose another option: ");
        scanf("%d", &option);
    }

    return 0;
}

void setBit(uint64_t* mask, unsigned bit) {
    *mask |= (1ULL << bit);
}

void clearBit(uint64_t* mask, unsigned bit) {
    *mask &= -(1ULL << bit);
}

void flipBit(uint64_t* mask, unsigned bit) {
    *mask ^= (1ULL << bit);
}

int checkBit(uint64_t mask, unsigned bit) {
    return !!(mask & (1ULL << bit));
}

void printAttendancies(uint64_t mask) {
    for (int i = 0; i <= 63; i++) {
        printf("Student #%d: %d\n", (i+1), checkBit(mask, i));
    }
    putchar('\n');
}