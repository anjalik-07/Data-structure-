#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Holder {
    char name[50];
    struct Date dob;
    char address[100];
    char nationality[30];
};

struct Passport {
    int passport_number;
    struct Date issue_date;
    struct Date expiry_date;
    char issuing_country[30];
    struct Holder holder;
};

int main() {

    struct Passport p;

    printf("Enter passport number: ");
    scanf("%d", &p.passport_number);

    printf("Enter issue date (dd mm yyyy): ");
    scanf("%d %d %d", &p.issue_date.day, &p.issue_date.month, &p.issue_date.year);

    printf("Enter expiry date (dd mm yyyy): ");
    scanf("%d %d %d", &p.expiry_date.day, &p.expiry_date.month, &p.expiry_date.year);

    printf("Enter issuing country: ");
    scanf("%s", p.issuing_country);

    printf("Enter holder name: ");
    scanf("%s", p.holder.name);

    printf("Enter date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &p.holder.dob.day, &p.holder.dob.month, &p.holder.dob.year);

    printf("Enter address: ");
    scanf("%s", p.holder.address);

    printf("Enter nationality: ");
    scanf("%s", p.holder.nationality);

    printf("\nPassport Details\n");
    printf("Passport Number: %d\n", p.passport_number);
    printf("Issuing Country: %s\n", p.issuing_country);
    printf("Issue Date: %d%d%d\n", p.issue_date.day, p.issue_date.month, p.issue_date.year);
    printf("Expiry Date: %d%d%d\n", p.expiry_date.day, p.expiry_date.month, p.expiry_date.year);

    printf("\n Holder Details\n");
    printf("Name: %s\n", p.holder.name);
    printf("Date of Birth: %d%d%d\n", p.holder.dob.day, p.holder.dob.month, p.holder.dob.year);
    printf("Address: %s\n", p.holder.address);
    printf("Nationality: %s\n", p.holder.nationality);

    return 0;
}
