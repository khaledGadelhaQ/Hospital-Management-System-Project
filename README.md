# Hospital Management System

A simple hospital management system written in C++ to manage patients in different specializations. This program allows you to add new patients, print patient lists, and get the next patient in line for each specialization.

## Table of Contents

- [Features](#features)
- [Demo](#Demo)
- [Prerequisites](#prerequisites)
- [Documentation](#documentation)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Modular Design**: The code is organized into classes, making it easy to understand and maintain.
- **Object-Oriented**: Utilizes object-oriented principles for patient management and specialization.
- **User-Friendly Interface**: Offers a menu-driven interface for interacting with the system.
- **Input Validation**: Includes basic input validation to handle invalid user inputs.
- **STL Usage**: Utilizes the Standard Template Library (STL) for data structures like `deque` and `vector`, enhancing code efficiency.
- **Enums**: Uses enums for gender and urgency levels to enhance code readability.

## Demo

![1](https://github.com/khaledGadelhaQ/Hospital-Management-System-Project/assets/120754711/7ffcf65f-c827-4053-9027-3fc6cc9dfd1f) ![2](https://github.com/khaledGadelhaQ/Hospital-Management-System-Project/assets/120754711/af63d027-c671-4fed-b949-10ff58b3489b) ![3](https://github.com/khaledGadelhaQ/Hospital-Management-System-Project/assets/120754711/6c2c6edc-0ab8-4471-9e18-c9ae5acab8ca)
![4](https://github.com/khaledGadelhaQ/Hospital-Management-System-Project/assets/120754711/395b6540-db4b-4ab9-b308-5f1fa236e559) ![5](https://github.com/khaledGadelhaQ/Hospital-Management-System-Project/assets/120754711/4006f22b-70fc-4ee7-8563-98c583ecc29e)


## Prerequisites

- C++ compiler (e.g., g++)
- Command-line interface

## Documentation

### Patient Class

- **EnterPatientInfo()**: Method to enter patient information, including name, age, gender, and urgency status.
- **GetStatus()**: Method to get the urgency status of the patient.
- **PrintInfo()**: Method to print patient information.
- **GetFullName()**: Method to get the full name of the patient.

### Specialization Class

- **AddPatient()**: Method to add a new patient to the specialization.
- **PrintPatients()**: Method to print the list of patients in the specialization.
- **GetPatient()**: Method to get the next patient and remove them from the queue.

### HospitalSystem Class

- **RunSystem()**: Method to run the hospital management system.
- **Menu()**: Method to display the menu and get the user's choice.
- **AddPatient()**: Method to add a patient to a specialization.
- **PrintAllPatients()**: Method to print all patients in all specializations.
- **GetNextPatient()**: Method to get the next patient from a specialization.

## Contributing

Contributions are welcome! If you have any suggestions, bug reports, or improvements, please create an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
