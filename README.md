# 🎮 OpenGL (FreeGLUT) Environment Setup in VS Code

This guide explains how to install and configure **OpenGL (FreeGLUT)** with **VS Code** on **Windows**, using **MSYS2 (MinGW)**.  
Follow the steps carefully to set up a complete graphics development environment.

---

## 🖥 Operating System
- Windows (64-bit)

---

## 🛠 Required Software & Tools

Download and install the following tools:

1. **Visual Studio Code**  
   👉 https://code.visualstudio.com/download

2. **MSYS2**  
   👉 https://www.msys2.org/

3. **GLAD (OpenGL Loader Generator)**  
   👉 https://glad.dav1d.de/  
   - API: OpenGL  
   - Version: **4.6 (Latest)**  
   - Language: C/C++

---

## 🚀 Installation Steps (Windows)

### 1️⃣ Install VS Code
- Download and install VS Code normally.
- Restart your system if needed.

---

### 2️⃣ Install MSYS2
- Download MSYS2 installer and complete setup.
- After installation, open **MSYS2 MINGW64** terminal.

---

### 3️⃣ Update MSYS2 & Install Required Packages

Run the following commands **one by one**:

```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc
gcc --version
pacman -S mingw-w64-x86_64-glew
pacman -S mingw-w64-x86_64-glfw
```
Optional: 
```bash
pacman -S mingw-w64-x86_64-freeglut
pacman -S mingw-w64-x86_64-toolchain
```
---

### 4️⃣ Setup Environment Variables
Add System Variable
- Variable Name: `MSYS2`
- Variable Value:
```bash
C:\msys64
```
### Update PATH Variable
Add this path:
```bash
C:\msys64\mingw64\bin
```
> 📌 Restart your system after updating environment variables.

---

### 5️⃣ Generate & Add GLAD
- Generate GLAD files from the website.
- Copy the generated include and src files.
- Paste them inside:
```bash
C:\msys64\mingw64\
```
---

### 6️⃣ Configure VS Code
Install VS Code Extensions
- C/C++
- Run++
- Code Runner

Add Include Path
1. Open *VS Code Settings*
2. Search for `includepath`
3. Add:
```bash
${env:MSYS2}/mingw64/include/
```
---

## 📂 Project Setup
- Download the project ZIP from this repository
- Extract it
- Open the folder in *VS Code*
- Start coding 🎨✨

---

## ✅ Final Check
- `gcc --version` works
- OpenGL headers are detected
- FreeGLUT programs compile without errors

---

## 📌 Notes
- Always run OpenGL-related commands using MSYS2 MINGW64
- Restart VS Code after configuration changes

---
