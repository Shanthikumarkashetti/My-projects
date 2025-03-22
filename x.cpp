#include <iostream>
#include <ctime>

using namespace std;

// Function to calculate age
void calculate_age(int birth_year, int birth_month, int birth_day) {
    // Get the current date
    time_t now = time(0);
    struct tm *newtime = localtime(&now);  // Get the current time

    // Calculate the difference in years
    int age_years = newtime->tm_year + 1900 - birth_year;

    // Adjust if birthday hasn't occurred yet this year
    if (newtime->tm_mon + 1 < birth_month || (newtime->tm_mon + 1 == birth_month && newtime->tm_mday < birth_day)) {
        age_years--;
    }

    // Output the result
    cout << "Your age is approximately " << age_years << " years." << endl;
}

int main() {
    int birth_year, birth_month, birth_day;

    // Taking input from the user
    cout << "Enter your birth year: ";
    cin >> birth_year;
    cout << "Enter your birth month: ";
    cin >> birth_month;
    cout << "Enter your birth day: ";
    cin >> birth_day;

    // Calculate and display age
    calculate_age(birth_year, birth_month, birth_day);

    return 0;
}
