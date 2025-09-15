# Queue Management System in C++

A console-based **Queue Management System** built with C++.  
This project allows managing service queues with features such as issuing tickets, tracking waiting clients, serving clients, and displaying ticket details.

Tickets include a unique code, timestamp, and estimated serving time.

---

## Features
-  **Show Queue Info** → Display total tickets, served clients, and waiting clients.  
-  **Issue Ticket** → Create a new ticket for the queue.  
-  **Serve Next Client** → Remove the next client from the queue.  
-  **Print Tickets** → Display tickets RTL (newest → oldest) or LTR (oldest → newest).  
-  **Optional Persistence** → Integrate with timestamp logging (requires `clsDate.h`).

---

## Project Structure
- `main.cpp` → Full application source code demonstrating queues.  
- `clsQueueLine.h` → Class definitions for queue and tickets.  
- `clsDate.h` → Utility for system date and time (needed for ticket timestamps).
