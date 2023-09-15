#include <iostream>
#include <string>
#include <deque>
#include <vector>

const int MAX_QUEUE = 5;
const int MAX_SPEC = 20;

// Enums to represent gender and urgency levels
enum class Gender {
    Male,
    Female
};

enum class Urgency {
    Regular,
    Urgent
};

class Patient {
private:
    std::string firstName;
    std::string lastName;
    int age;
    Gender gender;
    Urgency urgency;

public:
    Patient() : firstName(""), lastName(""), age(-1), gender(Gender::Male), urgency(Urgency::Regular) {}

    // Method to enter patient information
    void EnterPatientInfo() {
        std::cout << "First Name: "; std::cin >> firstName;
        std::cout << "Last Name: "; std::cin >> lastName;
        std::cout << "Age: "; std::cin >> age;

        char genderInput;
        std::cout << "Gender(M/F): "; std::cin >> genderInput;
        gender = (genderInput == 'M' || genderInput == 'm') ? Gender::Male : Gender::Female;

        std::string statusInput;
        std::cout << "Status (Urgent/Regular): "; std::cin >> statusInput;
        urgency = (statusInput == "Urgent" || statusInput == "urgent") ? Urgency::Urgent : Urgency::Regular;
    }

    // Method to get the urgency status
    Urgency GetStatus() {
        return urgency;
    }

    // Method to print patient information
    void PrintInfo() {
        std::cout << "\t" << firstName << " " << lastName << " - " << age << " years old" << std::endl;
        std::cout << "\t" << (gender == Gender::Male ? "Male" : "Female") << " - ";
        std::cout << (urgency == Urgency::Urgent ? "Urgent" : "Regular") << std::endl;
    }

    // Method to get the full name of the patient
    std::string GetFullName() {
        return firstName + " " + lastName;
    }
};

class Specialization {
private:
    std::deque<Patient> patientsDeque;
    int specNumber;
    int patientsCount;

public:
    Specialization() : specNumber(-1), patientsCount(0) {}

    Specialization(int specNum) : specNumber(specNum), patientsCount(0) {}

    // Method to add a new patient to the specialization
    void AddPatient() {
        if (patientsCount == MAX_QUEUE) {
            std::cout << "Sorry, we can't add more patients for this specialization\n";
        } else {
            Patient patient;
            patient.EnterPatientInfo();
            Urgency urgent = patient.GetStatus();
            if (urgent == Urgency::Urgent) {
                patientsDeque.push_front(patient);
            } else {
                patientsDeque.push_back(patient);
            }
            patientsCount++;
        }
    }

    // Method to print the list of patients in the specialization
    void PrintPatients() {
        if (patientsCount == 0) return;
        std::cout << "There are " << patientsCount << " patients in specialization " << specNumber + 1 << "\n\n";
        for (auto& patient : patientsDeque) {
            patient.PrintInfo();
            std::cout << "\n\t-------------\n";
        }
        std::cout << "=================\n";
    }

    // Method to get the next patient and remove them from the queue
    void GetPatient() {
        if (patientsCount == 0) {
            std::cout << "No patients at the moment. Have rest, Dr\n";
            return;
        }
        std::cout << patientsDeque.front().GetFullName() << " please go with the Dr\n";
        patientsDeque.pop_front();
        patientsCount--;
    }
};

class HospitalSystem {
private:
    std::vector<Specialization> specQueue;

public:
    HospitalSystem() {
        specQueue = std::vector<Specialization>(MAX_SPEC);
        for (int i = 0; i < MAX_SPEC; i++) {
            specQueue[i] = Specialization(i);
        }
    }

    // Method to run the hospital system
    void RunSystem() {
        while (true) {
            int choice = Menu();
            switch (choice) {
                case 1:
                    AddPatient();
                    break;
                case 2:
                    PrintAllPatients();
                    break;
                case 3:
                    GetNextPatient();
                    break;
                case 4:
                    return;
                default:
                    break;
            }
        }
    }

    // Method to display the menu and get user's choice
    int Menu() {
        int choice = -1;
        while (choice == -1) {
            std::cout << "\nEnter Your Choice: \n";
            std::cout << "\t1) Add New Patient \n";
            std::cout << "\t2) Print All Patients \n";
            std::cout << "\t3) Get Next Patient \n";
            std::cout << "\t4) Exit \n";
            std::cin >> choice;
            if (!(choice >= 1 && choice <= 4)) {
                std::cout << "Invalid choice. Try again\n";
                choice = -1;
            }
        }
        return choice;
    }

    // Method to add a patient to a specialization
    void AddPatient() {
        int specNum;
        std::cout << "Enter Specialization: ";
        std::cin >> specNum;
        if (specNum >= 1 && specNum <= MAX_SPEC) {
            specQueue[specNum - 1].AddPatient();
        } else {
            std::cout << "Invalid specialization number\n";
        }
    }

    // Method to print all patients in all specializations
    void PrintAllPatients() {
        std::cout << "\n************************************\n";
        for (auto& val : specQueue) {
            val.PrintPatients();
        }
    }

    // Method to get the next patient from a specialization
    void GetNextPatient() {
        int specNum;
        std::cout << "Enter Specialization: ";
        std::cin >> specNum;
        if (specNum >= 1 && specNum <= MAX_SPEC) {
            specQueue[specNum - 1].GetPatient();
        } else {
            std::cout << "Invalid specialization number\n";
        }
    }
};

int main() {
    HospitalSystem system;
    system.RunSystem();
    return 0;
}
