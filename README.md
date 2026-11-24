# 🎓 Student Marks Management System

![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)
![Platform](https://img.shields.io/badge/Platform-Cross--Platform-lightgrey?style=flat-square)
![License](https://img.shields.io/badge/Status-Active-brightgreen?style=flat-square)
![Contributors](https://img.shields.io/badge/Contributors-3-orange?style=flat-square)

---

## 📌 About the Project

**Student Marks Management System** is a menu-driven **Student Result and Grade Analyzer** written in C. Designed for accuracy and reliability, it automates the process of recording student marks, validating user inputs, calculating totals and percentages, assigning letter grades, determining pass/fail status, and identifying overall class performance metrics such as the class average and class topper.

---

## ✨ Features

* 👤 **Student Record Management:** Stores roll numbers, names, and marks across 5 subjects for up to **50 students**.
* 🧮 **Automated Calculations:** Computes total marks (out of 500) and overall percentage for every student.
* 🎯 **Smart Grade Assignment:** Automatically assigns letter grades (`A`, `B`, `C`, `D`, or `F`) based on percentage and subject-wise passing rules.
* ✅ **Pass / Fail Evaluation:** Evaluates overall qualification status and automatically flags a student as **FAIL** if they score below 40 in any individual subject.
* 📈 **Class Analytics:** Calculates the overall **class average** and identifies the **class topper** with the highest score.
* 🔄 **Interactive Menu Interface:** Provides a clean, loop-driven menu for entering records, viewing individual or full class reports, and checking analytics.
* 🔒 **Safe Exit Guard:** Prevents the program from exiting until at least one student record has been entered.

---

## ⚙️ How It Works

1. **Launch & Menu Navigation:** When started, the program displays an interactive menu powered by a `do-while` loop and `switch-case` control flow.
2. **Data Entry:** The user enters the number of students (1–50) along with each student's roll number, name, and marks for 5 subjects.
3. **Validation & Processing:** Every input passes through validation checks before storing. Once valid marks are received, the program computes the total, percentage, subject-wise pass check, and final grade.
4. **Report & Analytics Viewing:** Users can display formatted mark sheets for all students, view the class average, or highlight the class topper at any time.
5. **Controlled Exit:** Choosing the exit option checks whether at least one student record exists before terminating the program.

---

## 🎯 Grading System

Grades are assigned based on the student's overall percentage, subject to passing every individual subject:

| Percentage Range | Grade | Status |
| :--- | :---: | :---: |
| **90% and above** | `A` | PASS |
| **75% to below 90%** | `B` | PASS |
| **60% to below 75%** | `C` | PASS |
| **Below 60% (and ≥ 40 in all subjects)** | `D` | PASS |
| **Any individual subject mark < 40** | `F` | FAIL |

> ⚠️ **Important Rule:** Even if a student's overall percentage is 60% or higher, scoring **below 40 in any single subject** automatically results in a grade of **`F`** and a **`FAIL`** status.

---

## 🛡️ Input Validation

To prevent runtime crashes or corrupted calculations, the program enforces strict validation rules:

* **Numeric Verification:** Checks the return value of `scanf()` and clears the input buffer whenever non-numeric characters are entered.
* **Range Enforcement:** Rejects any subject mark outside the valid **`0–100`** range and prompts the user to re-enter a valid score.
* **Capacity Bounds:** Ensures student counts stay within the supported array limit (**1 to 50 students**).
* **Exit Protection:** Blocks premature program termination if zero student records have been added.

---

## 🖥️ Sample Output

```text
====================================================
        STUDENT MARKS MANAGEMENT SYSTEM
====================================================
1. Enter Student Details
2. Display All Student Results
3. Display Class Average & Topper
4. Exit
----------------------------------------------------
Enter your choice: 1

Enter number of students (1-50): 2

--- Enter Details for Student 1 ---
Roll Number: 101
Name: Aarav
Enter marks for 5 subjects (0-100): 92 88 95 90 91

--- Enter Details for Student 2 ---
Roll Number: 102
Name: Diya
Enter marks for 5 subjects (0-100): 78 82 35 80 76

====================================================
                  RESULT SUMMARY
====================================================
Roll   Name        Total   Percentage   Grade   Status
----------------------------------------------------
101    Aarav       456     91.20%       A       PASS
102    Diya        351     70.20%       F       FAIL
----------------------------------------------------
Class Average : 80.70%
Class Topper  : Aarav (Roll No: 101) - 91.20%
====================================================
