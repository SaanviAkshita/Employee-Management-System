 Employee Management System
A simple Employee Management System in C that allows administrators to manage employee records with functions to add, delete, modify, display, and search employee information. This project demonstrates basic file handling in C, where employee records are stored in a binary file for persistent storage.

## Features

- **Add Employee**: Register a new employee by entering details such as ID, name, designation, gender, branch, salary, address, phone number, and email.
- **Delete Employee**: Remove an employee's record from the file by specifying their ID.
- **Modify Employee**: Update an existing employee's information.
- **Display Employee List**: View the list of all employees with their details.
- **Search Employee**: Search for an employee's record by ID.

## Project Structure

- **File Handling**: All employee data is stored in a file (`employeeInfo.txt`) for persistence.
- **Authentication**: Basic login system with a hardcoded username (`admin`) and password (`pass`).
- **Error Handling**: Includes error handling for file operations to ensure smooth functionality.

## Getting Started

### Prerequisites

- A C compiler (such as GCC)
- Dev C++ or another C IDE (if preferred)

### Running the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/employee-management-system.git
   ```

2. Compile the code using a C compiler:

   ```bash
   gcc EmployeeManagementSystem.c -o EmployeeManagementSystem
   ```

3. Run the executable:

   ```bash
   ./EmployeeManagementSystem
   ```

4. Log in with the following credentials:
   - **Username**: `admin`
   - **Password**: `pass`

5. Use the menu options to add, delete, modify, display, or search employee records.

## Code Overview

- **main()**: Initializes the file, handles user login, and displays the main menu.
- **add()**: Adds a new employee record.
- **del()**: Deletes an employee record by ID.
- **modify()**: Modifies existing employee details.
- **displayList()**: Displays a list of all employees.
- **searchRecord()**: Searches for a specific employee by ID.
- **Helper Functions**: Includes utility functions for printing headers and formatted output.

## Future Enhancements

- **Dynamic Login System**: Allow dynamic creation of usernames and passwords for multiple users.
- **Improved Security**: Store hashed passwords instead of plain text.
- **Database Integration**: Replace file handling with a database for larger data handling.
- **Enhanced UI**: Implement a graphical interface for better user experience.

## License

This project is open-source and free to use. You may modify and distribute it as per your requirements.

---

Feel free to adjust the project description based on any additional features you may add or specific goals of your implementation!# Employee-Management-System
