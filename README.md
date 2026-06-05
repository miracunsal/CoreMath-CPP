# CoreMath-CPP 🧮⚡
**A High-Performance C++ Linear Algebra Engine from Scratch**

[![Language](https://img.shields.io/badge/Language-C++11-00599C?style=for-the-badge&logo=c%2B%2B)](https://isocpp.org/)
[![Focus](https://img.shields.io/badge/Focus-Linear_Algebra_%7C_AI_Core-8b5cf6?style=for-the-badge)](#)

While modern Machine Learning heavily relies on high-level Python libraries like `NumPy` and `TensorFlow`, the actual heavy lifting is done by low-level C/C++ backends. As a Computer Engineering student bridging the gap between hardware architecture and Artificial Intelligence, I developed **CoreMath-CPP** to build the foundational mathematical operations of AI models directly from scratch.

This project demonstrates how data structures, object-oriented programming (OOP), and memory management come together to create a robust mathematical engine.

## 🚀 Engine Features
* **Dynamic Memory Management:** Utilizes standard `std::vector` structures to safely allocate and manage matrix memory without memory leaks.
* **Core Neural Network Math:** * **Matrix Addition (`add`):** Essential for bias addition in neural layers.
  * **Matrix Multiplication / Dot Product (`multiply`):** The core calculation engine for neuron weight propagation.
  * **Matrix Transposition (`transpose`):** Critical for data reshaping and backpropagation algorithms.
* **Robust Exception Handling:** Built-in safeguards (`std::invalid_argument`, `std::out_of_range`) to prevent mathematical impossibilities, such as multiplying matrices with incompatible dimensions.

## 🛠️ Technical Architecture
* **Paradigm:** Object-Oriented Programming (Encapsulation, Constructor design)
* **Error Handling:** Standard C++ Exception classes
* **I/O Formatting:** `iomanip` for clean, structured console outputs

## 💻 Quick Start & Compilation

1. Clone this repository to your local machine:
```bash
git clone [https://github.com/miracunsal/CoreMath-CPP.git](https://github.com/miracunsal/CoreMath-CPP.git)
