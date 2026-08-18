# Event Management System (C Program)

A simple console-based Event Management System written in C. This program allows users to create, manage, view, and cancel events, storing the record persistently in a local text file (`event_records.txt`).

---

## 📌 Features

* **Add Event**: Input event details including Event ID, Name, Date (`DD-MM-YYYY`), and Time (`HH:MM`).
* **Display Upcoming Events**: View all active (non-cancelled) events saved in the record file.
* **Cancel Event**: Cancel an active event using its unique Event ID and update the status in the data file.
* **View Past / Cancelled Events**: View a list of all events marked as cancelled.
* **File Persistence**: Automatically saves and reads event data from `event_records.txt`.

---

## 🛠️ Data Structure

The program uses an `Event` struct to represent each event:

```c
struct Event {
    int eventID;
    char eventName[100];
    char date[20];
    char time[20];
    int isCancelled; // 0 for active, 1 for cancelled
};

```

Maximum capacity supported in memory: **200 events** (`MAX_EVENTS`).

---

## 🚀 How to Build and Run

### Prerequisites

* A C compiler such as `GCC` or `Clang`.

### Compilation

Open a terminal in the project directory and run:

```bash
gcc main.c -o event_management

```

### Execution

Run the compiled binary:

* **Linux / macOS:**
```bash
./event_management

```


* **Windows (Command Prompt / PowerShell):**
```cmd
event_management.exe

```



---

## 🖥️ Usage Menu

When you run the application, an interactive menu will be presented:

```text
1. Add Event
2. Display Upcoming Events
3. Cancel Event
4. View Past Events
5. Exit
Enter an option (1-5):

```

---

## 📄 Storage File Format (`event_records.txt`)

Events are saved line-by-line using pipe (`|`) delimiters:

```text
101 | Tech_Conference | 25-12-2026 | 10:00 | 0
102 | Team_Meeting | 30-12-2026 | 14:30 | 1

```

* Field 1: Event ID
* Field 2: Event Name
* Field 3: Date
* Field 4: Time
* Field 5: Cancellation Status (`0` = Active, `1` = Cancelled)

---

## 📝 Notes & Limitations

* Event names should not contain spaces when entered via `scanf`.
* Events are stored in memory up to 200 items before requiring application restart or re-loading.
"""

with open("README.md", "w") as f:
f.write(readme_content)

print("README.md created successfully")

```

```text?code_stdout&code_event_index=1
README.md created successfully


```

Your README MD file is ready


Here is the markdown content for your `README.md` file based on the C source code provided:

```markdown
# Event Management System (C Program)

A simple console-based Event Management System written in C. This program allows users to create, manage, view, and cancel events, storing the record persistently in a local text file (`event_records.txt`).

---

## 📌 Features

* **Add Event**: Input event details including Event ID, Name, Date (`DD-MM-YYYY`), and Time (`HH:MM`).
* **Display Upcoming Events**: View all active (non-cancelled) events saved in the record file.
* **Cancel Event**: Cancel an active event using its unique Event ID and update the status in the data file.
* **View Past / Cancelled Events**: View a list of all events marked as cancelled.
* **File Persistence**: Automatically saves and reads event data from `event_records.txt`.

---

## 🛠️ Data Structure

The program uses an `Event` struct to represent each event:

```c
struct Event {
    int eventID;
    char eventName[100];
    char date[20];
    char time[20];
    int isCancelled; // 0 for active, 1 for cancelled
};

```

Maximum capacity supported in memory: **200 events** (`MAX_EVENTS`).

---

## 🚀 How to Build and Run

### Prerequisites

* A C compiler such as `GCC` or `Clang`.

### Compilation

Open a terminal in the project directory and run:

```bash
gcc main.c -o event_management

```

### Execution

Run the compiled binary:

* **Linux / macOS:**
```bash
./event_management

```


* **Windows (Command Prompt / PowerShell):**
```cmd
event_management.exe

```



---

## 🖥️ Usage Menu

When you run the application, an interactive menu will be presented:

```text
1. Add Event
2. Display Upcoming Events
3. Cancel Event
4. View Past Events
5. Exit
Enter an option (1-5):

```

---

## 📄 Storage File Format (`event_records.txt`)

Events are saved line-by-line using pipe (`|`) delimiters:

```text
101 | Tech_Conference | 25-12-2026 | 10:00 | 0
102 | Team_Meeting | 30-12-2026 | 14:30 | 1

```

* Field 1: Event ID
* Field 2: Event Name
* Field 3: Date
* Field 4: Time
* Field 5: Cancellation Status (`0` = Active, `1` = Cancelled)

---

## 📝 Notes & Limitations

* Event names should not contain spaces when entered via `scanf`.
* Events are stored in memory up to 200 items before requiring application restart or re-loading.

```

```
