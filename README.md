# Hotel Management System (C++)

A simple yet functional **C++ console-based Hotel Management System** that lets hotel staff manage room bookings, customer records, and room availability using file handling. Designed with a modular code structure for learning, portfolios, and project showcases.

---

## Features

- Book a room with automatic fare calculation
- View individual customer booking record
- Modify or delete customer records
- View list of all allotted rooms
- Prevent double-booking of rooms
- Admin login system (username/password protected)
- Data persistence using a binary file (`Record.dat`)

---
## Login Credentials

Username: admin
Password: pass

---
## Tech Stack

- **C++** (Object-Oriented Programming)
- **File Handling** using binary `.dat` files
- Modular design with:
  - `main.cpp` – handles login and control flow
  - `hotel.cpp`/`hotel.h` – core logic for hotel operations
  - `utils.cpp`/`utils.h` – helper utilities (screen clearing, intro banner, etc.)

---

## Folder Structure

```bash

── main.cpp         # Entry point with login and menus
── hotel.cpp        # Hotel booking logic
── hotel.h          # Class declarations
── utils.cpp        # Utility function implementations
── utils.h          # Utility declarations
── data/            # Stores binary file Record.dat

