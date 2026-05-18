<div align="center">

# 🖥️ Linux System Performance Monitoring Tool

### Lightweight Real-Time Linux Monitoring Utility Built in C

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" />
  <img src="https://img.shields.io/badge/Platform-Linux-black?style=for-the-badge&logo=linux" />
  <img src="https://img.shields.io/badge/Status-Active-success?style=for-the-badge" />
  <img src="https://img.shields.io/badge/System-Programming-orange?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Open%20Source-Yes-brightgreen?style=for-the-badge" />
</p>

<p align="center">
  <b>A lightweight and modular Linux system monitoring tool developed in C for tracking real-time system performance metrics.</b>
</p>

</div>

---

# 📌 Overview

The **Linux System Performance Monitoring Tool** is a low-level system utility designed for Linux environments that provides real-time monitoring of important system metrics such as:

- CPU Usage
- Memory Consumption
- Running Processes
- System Uptime

This project demonstrates practical implementation of:

- Linux System Programming
- Efficient Resource Handling
- `/proc` Filesystem Parsing
- Modular C Programming
- Performance Monitoring Concepts

---

# ⚠️ Disclaimer

> ## 🚨 This project works **ONLY in Linux environments**
>
> The tool relies on Linux-specific system files and the `/proc` filesystem.  
> It will **not function correctly on Windows or macOS** systems.

---

# ✨ Features

✔️ Real-time CPU usage monitoring  
✔️ Memory utilization tracking  
✔️ Running process statistics  
✔️ Lightweight terminal-based interface  
✔️ Modular and scalable code structure  
✔️ Efficient use of Linux system calls  
✔️ Low resource consumption  
✔️ Clean and maintainable C implementation  

---

# 🛠️ Tech Stack

<div align="center">

| Technology | Usage |
|------------|-------|
| **C** | Core Development Language |
| **Linux** | Operating Environment |
| **/proc Filesystem** | System Metrics Collection |
| **GCC** | Compilation |
| **Make** | Build Automation |

</div>

---

# 📂 Project Structure

```bash
linux-system-monitor-c/
│
├── src/                # Source files
├── include/            # Header files
├── Makefile            # Build configuration
├── README.md           # Documentation
└── monitor             # Compiled executable
```

---

# ⚙️ How It Works

The monitoring tool collects system statistics directly from Linux system files located inside the `/proc` directory.

It continuously reads and processes information related to:

- CPU utilization
- Memory allocation
- Active processes
- System uptime

The processed data is displayed in a clean terminal interface for real-time monitoring and analysis.

---

# 🚀 Installation

## 1️⃣ Clone the Repository

```bash
git clone https://github.com/mayankkmk77/linux-system-monitor-c.git
```

---

## 2️⃣ Navigate to the Project Directory

```bash
cd linux-system-monitor-c
```

---

## 3️⃣ Build the Project

```bash
make
```

---

## 4️⃣ Run the Program

```bash
./monitor
```

---

# 📋 Requirements

- Linux-based Operating System
- GCC Compiler
- Make Utility

### Install Required Dependencies (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential
```

---

# 🖥️ Sample Output

```bash
CPU Usage    : 34%
Memory Usage : 52%
Processes    : 214
System Uptime: 5h 42m
```

---

# 📚 Learning Outcomes

This project helped in gaining practical experience with:

✅ Linux internals and monitoring systems  
✅ Low-level programming in C  
✅ Parsing data from `/proc` filesystem  
✅ Efficient memory and resource management  
✅ Real-time system performance analysis  
✅ Writing modular and maintainable code  

---

# 🔮 Future Improvements

- Interactive UI using `ncurses`
- Disk usage monitoring
- Network statistics tracking
- Process-specific analytics
- Multi-threaded monitoring
- Hardware temperature monitoring
- Export logs to files

---

# 💡 Inspiration

This project is inspired by popular Linux monitoring utilities such as:

- `top`
- `htop`
- `sysstat`

These tools commonly utilize lightweight system-level programming techniques and Linux internals for performance monitoring.

---

# 🤝 Contributing

Contributions are welcome and appreciated.

## Steps to Contribute

### 1️⃣ Fork the Repository

### 2️⃣ Create a Feature Branch

```bash
git checkout -b feature-name
```

### 3️⃣ Commit Your Changes

```bash
git commit -m "Added new feature"
```

### 4️⃣ Push to GitHub

```bash
git push origin feature-name
```

### 5️⃣ Open a Pull Request

---

# 📜 License

This project is licensed under the **MIT License**.

---

# 👨‍💻 Author

<div align="center">

## **Mayank Mihir**

<p>
  <a href="https://github.com/mayankkmk77">
    <img src="https://img.shields.io/badge/GitHub-mayankkmk77-black?style=for-the-badge&logo=github" />
  </a>

  <a href="https://www.linkedin.com/">
    <img src="https://img.shields.io/badge/LinkedIn-Mayank%20Mihir-blue?style=for-the-badge&logo=linkedin" />
  </a>
</p>

</div>

---

# 🔗 Repository Link

<div align="center">

### ⭐ If you found this project useful, consider giving it a star ⭐

👉 **Repository:**  
https://github.com/mayankkmk77/linux-system-monitor-c

</div>
