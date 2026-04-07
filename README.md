# 📌 Queue Management System (C++)

## 📖 Overview
This project is a **Queue Management System** built in C++ that simulates real-world service queues such as bill payment counters and subscription services.

It allows issuing tickets, managing waiting clients, and serving them in an organized FIFO manner while calculating expected waiting times dynamically.

---

## 🚀 Features
- 🎟️ Issue tickets with timestamp
- ⏳ Calculate expected service time
- 👥 Track number of waiting clients
- ✅ Serve next client and update queue
- 🔄 Display tickets in multiple formats:
  - Left to Right (LTR)
  - Right to Left (RTL)
- 📄 Print detailed ticket information

---

## 🧱 Technologies & Concepts
- **C++**
- **Object-Oriented Programming (OOP)**
- **Data Structures:**
  - Queue (FIFO)
  - Stack (for reverse display)
- **Time & Date handling**

---

## 🏗️ System Design

### 🔹 clsQueueLine
Main class responsible for managing the queue:
- Issue tickets
- Serve clients
- Track queue status

### 🔹 clsTicket (Nested Class)
Represents a single ticket:
- Ticket number
- Issue time
- Waiting clients
- Expected service time

---

## ⚙️ How It Works
1. A queue is initialized with:
   - Total tickets
   - Average service time
   - Prefix (e.g., A0, B0)

2. Tickets are issued:
   - Assigned sequential numbers
   - Timestamp recorded
   - Expected waiting time calculated

3. When a client is served:
   - The first ticket is removed
   - Remaining tickets are updated

4. Tickets can be displayed in different formats.

---

## ▶️ Example Use Case
- Bill payment queue
- Subscription service queue

Each queue operates independently with its own configuration.

---

## 📊 What I Learned
- Applying OOP principles in real scenarios
- Working with queues and stacks
- Managing time-based calculations
- Designing modular and reusable code

---

## 📌 Future Improvements
- Separate logic from UI (console output)
- Optimize queue update when serving clients
- Add GUI interface
- Support multi-threaded queue simulation

---
