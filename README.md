# Hostel Outpass Management System

A simple **C++ command-line interface (CLI)** application designed to help hostel wardens and admins efficiently track student movements in and out of the hostel.

---

## Features

- 📋 **Register Outpass:** Add a new outpass record with student name, room number, reason for leaving, and time of exit.
- ✅ **Mark as Returned:** Update student status to mark when they have returned.
- 👀 **View Students Outside:** Display a list of all students currently outside the hostel.
- 💾 **File-based Storage:** Saves all records in a text file for easy reference and persistent data storage.
- 🖥️ **Simple and Lightweight:** No complex databases required, making it easy to run on any system with a C++ compiler.

---

## How to Use

1. Compile the code:
   ```bash
   g++ outpass.cpp -o outpass
