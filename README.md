# 🏦 Bank Management System

A robust, console-based banking application written in C++. This project demonstrates core Object-Oriented Programming (OOP) concepts, the use of Standard Template Library (STL) data structures, and persistent data storage using File I/O.

## ✨ Features

*   **Account Creation:** Generate a new bank account with a unique, auto-incrementing Account Number.
*   **Account Management:** View account details or update the account holder's name and phone number.
*   **Financial Transactions:** 
    *   Deposit money into an account.
    *   Withdraw money (includes insufficient balance validation).
    *   Check current account balance.
*   **Data Persistence:** Automatically saves all account data to a local `bank_data.txt` file and loads it upon startup, ensuring no data is lost between sessions.

## 🛠️ Technologies Used

*   **Language:** C++
*   **Data Structures:** `std::map` (for fast account retrieval using the Account Number as the key)
*   **Concepts:** Object-Oriented Programming (Classes, Constructors, Static variables), File Handling (`ifstream`, `ofstream`), String Manipulation.

## 🚀 How to Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YourUsername/YourRepositoryName.git](https://github.com/YourUsername/YourRepositoryName.git)
   Navigate to the directory:
*firstly,
Bash
cd YourRepositoryName
Compile the code:
*secondly,
Bash
g++ main.cpp -o bank_system
Run the application:
*thirdly,
Bash
./bank_system
(Note: If you are using Windows, the executable will be bank_system.exe)
