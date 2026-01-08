#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

string currentDateTime() {
    time_t now = time(0);
    return ctime(&now);
}

class HealthCard {
public:
    string name;
    string id;
    int age;
    string gender;
    float height;
    float weight;
    bool veg, fruit, water, protein, activity;
    string junkFood;
    int weeklyPoints = 0;
    int maxPoints = 420;
    bool checkupDone = false;
    string lastSaved;

    void input() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter ID: ";
        getline(cin, id);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Gender: ";
        cin >> gender;

        cout << "Enter Height (cm): ";
        cin >> height;

        cout << "Enter Weight (kg): ";
        cin >> weight;
    }

    void display() {
        cout << "\n=================================================\n";
        cout << "         HEALTH CARD - 2025-12-12                     \n";
        cout << "=================================================\n\n";

        cout << left << setw(15) << "Name"   << ": " << name   << endl;
        cout << left << setw(15) << "ID"     << ": " << id     << endl;
        cout << left << setw(15) << "Age"    << ": " << age << " years" << endl;
        cout << left << setw(15) << "Gender" << ": " << gender << endl;
        cout << left << setw(15) << "Height" << ": " << height << " cm" << endl;
        cout << left << setw(15) << "Weight" << ": " << weight << " kg" << endl;

        cout << "\n=================================================\n";
    }

    void inputLifestyle() {
     cin.clear();
     cin.ignore(numeric_limits<streamsize>::max(), '\n');   
    cout << "\nDaily Habit Check (6 behaviors)\n";

    cout << "Vegetables intake met (1-Yes 0-No): ";
    cin >> veg;

    cout << "Fruits intake met (1-Yes 0-No): ";
    cin >> fruit;

    cout << "Water target met (1-Yes 0-No): ";
    cin >> water;

    cout << "Protein target met (1-Yes 0-No): ";
    cin >> protein;

    cout << "Junk food avoided (Yes/Mostly/No): ";
    cin >> junkFood;

    cout << "Physical activity ≥ 30 min (1-Yes 0-No): ";
    cin >> activity;

    weeklyPoints += (veg + fruit + water + protein + activity) * 10;
}

void displayLifestyle() const {
    int score = veg + fruit + water + protein + activity;

    cout << "\n       EATING &LIFESTYLE HABITS                 \n";
    cout << "---------------------------------------------\n\n";

    cout << "Daily Habit Check (6 behaviors):\n";
    cout << " • Vegetables intake met      : " << (veg ? "Yes" : "No") << endl;
    cout << " • Fruits intake met          : " << (fruit ? "Yes" : "No") << endl;
    cout << " • Water target met           : " << (water ? "Yes" : "No") << endl;
    cout << " • Protein target met         : " << (protein ? "Yes" : "No") << endl;
    cout << " • Junk food avoided          : " << junkFood << endl;
    cout << " • Physical activity ≥ 30 min : " << (activity ? "Yes" : "No") << endl;

    cout << "\nEating Habit Score : " << score << " / 5\n";

    cout << "\nProtein Required   : " << (int)(weight * 0.8) << " g/day\n";
    cout << "Water Recommended  : 2.0 L/day\n";

    cout << "---------------------------------------------\n";
}
void displayWeeklyReport() const {
    float adherence = (weeklyPoints * 100.0) / maxPoints;

    cout << "\n        WEEKLY ADHERENCE REPORT              \n";
    cout << "---------------------------------------------\n\n";

    cout << "Adjusted Weekly Points : " << weeklyPoints << " / " << maxPoints << endl;
    cout << "Weekly Adherence       : " << (int)adherence << "%\n\n";

    // Progress bar
    cout << "Progress Bar           : [";
    int filled = adherence / 10;
    for (int i = 0; i < filled; i++) cout << "#";
    for (int i = filled; i < 10; i++) cout << "-";
    cout << "]\n\n";

    int lifestyleScore = (adherence >= 80) ? 7 : 5;

    cout << "Lifestyle Score        : " << lifestyleScore << " / 8\n";

    if (adherence >= 85)
        cout << "Lifestyle Badge        : Gold\n";
    else if (adherence >= 70)
        cout << "Lifestyle Badge        : Silver\n";
    else
        cout << "Lifestyle Badge        : Bronze\n";

    cout << "\nStatus                 : ";
    if (adherence >= 75)
        cout << "GOOD - Keep going!\n";
    else
        cout << "Needs improvement\n";

    cout << "\nCheckup Suggested      : ";
    cout << (adherence < 60 ? "Yes" : "No") << endl;

    cout << "---------------------------------------------\n";
}

void updateWeightHeight() {
    cout << "\n--- UPDATE HEIGHT / WEIGHT ---\n";

    cout << "Current Height : " << height << " cm\n";
    cout << "Current Weight : " << weight << " kg\n\n";

    cout << "Enter new height (cm): ";
    cin >> height;

    cout << "Enter new weight (kg): ";
    cin >> weight;

    cout << "\nHeight and Weight updated successfully!\n";
}
void displayHistory() const {
    cout << "\nACTIONS & HISTORY\n";
    cout << "---------------------------------------------\n";

    cout << "Last Saved          : " << lastSaved << endl;
    cout << "Latest Checkup Done : " << (checkupDone ? "Yes" : "No") << endl;

    cout << "---------------------------------------------\n";
}

void displayNotes() const {
    cout << "\nNOTES\n";
    cout << "---------------------------------------------\n";

    cout << "• Maintain balanced diet\n";
    cout << "• Drink at least 2L water daily\n";
    cout << "• Exercise minimum 30 min, 4–5 days/week\n";
    cout << "• Avoid excess junk food\n";

    if (checkupDone == false)
        cout << "• Schedule a routine health checkup\n";

    cout << "---------------------------------------------\n";
}

void exportToFile() {
    ofstream file(id + "_HealthCard.txt");

    file << "HEALTH TRACKER REPORT\n";
    file << "=====================\n\n";
    file << "Name   : " << name << endl;
    file << "Age    : " << age << endl;
    file << "Gender : " << gender << endl;
    file << "Height : " << height << " cm\n";
    file << "Weight : " << weight << " kg\n";

    file << "\nReport generated on: " << currentDateTime();
    file.close();

    lastSaved = currentDateTime();
    cout << "\nHealth Card exported successfully!\n";
}
};


void showMenu() {
    cout << "\n========================================\n";
    cout << "        HEALTH TRACKER SYSTEM\n";
    cout << "========================================\n\n";

    cout << "[1] Create New Health Card\n";
    cout << "[2] Daily Check-In (Eating + Activity)\n";
    cout << "[3] View Weekly Report\n";
    cout << "[4] View Health Card\n";
    cout << "[5] Update Weight / Height\n";
    cout << "[6] Mark Checkup as Done\n";
    cout << "[7] Export Health Card\n";
    cout << "[8] Exit\n\n";
}

float calculateBMI(float weight, float heightCm) {
    float heightM = heightCm / 100.0;
    return weight / (heightM * heightM);
}

string bmiCategory(float bmi) {
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25) return "Normal Weight";
    else if (bmi < 30) return "Overweight";
    else return "Obese";
}

float calculateBMR(string gender, float weight, float height, int age) {
    if (gender == "Male" || gender == "male") {
        return 10 * weight + 6.25 * height - 5 * age + 5;
    } else {
        return 10 * weight + 6.25 * height - 5 * age - 161;
    }
}

float dailyCalories(float bmr) {
    // Moderate activity (3–5 days/week)
    return bmr * 1.55;
}

void showMetrics(const HealthCard& h) {
    float bmi = calculateBMI(h.weight, h.height);
    float bmr = calculateBMR(h.gender, h.weight, h.height, h.age);
    float calories = dailyCalories(bmr);

    float minW = 18.5 * (h.height / 100) * (h.height / 100);
    float maxW = 24.9 * (h.height / 100) * (h.height / 100);

    cout << "\n          BODY METRICS & ANALYSIS                    \n";
    cout << "---------------------------------------------\n\n";

    cout << left << setw(25) << "BMI" << ": " << fixed << setprecision(2) << bmi << endl;
    cout << left << setw(25) << "BMI Category" << ": " << bmiCategory(bmi) << endl;

    cout << left << setw(25) << "Ideal Weight Range" << ": ";
    cout << fixed << setprecision(1) << minW << " kg - " << maxW << " kg\n\n";

    cout << left << setw(25) << "BMR (Estimated)" << ": " << (int)bmr << " kcal/day\n";
    cout << left << setw(25) << "Activity Level" << ": Moderate (3–5 days/week)\n\n";

    cout << left << setw(25) << "Daily Calorie Need" << ": " << (int)calories << " kcal/day\n";
    cout << "---------------------------------------------\n";
}


int main() {
    vector<HealthCard> users;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            HealthCard hc;
            cout << "\nCreating New Health Card\n";
            hc.input();
            users.push_back(hc);
            cout << "\nHealth Card Created Successfully!\n";
            users.back().lastSaved = currentDateTime();
        }
        else if (choice == 2) {
            if (users.empty()) {
            cout << "\nCreate Health Card first!\n";
            } else {
            users.back().inputLifestyle();
          }
        }
        else if (choice == 3) {
           if (users.empty()) {
           cout << "\nNo Health Card Found.\n";
           } else {
           users.back().displayWeeklyReport();
          }
        }
        else if (choice == 4) {
           if (users.empty()) {
           cout << "\nNo Health Card Found.\n";
           } else {
           users.back().display();
           showMetrics(users.back());
           users.back().displayLifestyle();
           users.back().displayWeeklyReport();
           users.back().displayHistory();
           users.back().displayNotes();
           }
        }
        else if (choice == 5) {
           if (users.empty()) {
           cout << "\nNo Health Card Found.\n";
           } else {
           users.back().updateWeightHeight();
          }
        }
        else if (choice == 6) {
            if (users.empty()) {
            cout << "\nNo Health Card Found.\n";
            } else {
            users.back().checkupDone = true;
            cout << "\nCheckup marked as done.\n";
          }
        }
        else if (choice == 7) {
           if (users.empty()) {
           cout << "\nNo Health Card Found.\n";
           } else {
           users.back().exportToFile();
          }
        }
        else if (choice == 8) {
            cout << "\nThank you for using Health Tracker!\n";
            break;
        }
        else {
            cout << "\nFeature coming soon...\n";
        }
    }

    return 0;
}