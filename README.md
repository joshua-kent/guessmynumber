Guess My Number
===============


This is a program where you guess the computer's number!

This is a test project, and is bound to have unexpected errors
or not work how expected. In the future, it may also have a
windowed version, to test that in C++.

How to install
--------------

First, make sure you clone the repository. You can do this with
the terminal (Linux) or command line using git.

```
git clone https://github.com/joshua-kent/guessmynumber.git
```

If you cannot do this, you can either install git and try again,
or download directly from GitHub.

How to run
----------

### Linux

Go to the file it where it was installed and execute *GMN_linux*.

```bash
cd guessmynumber
./GMN_linux
```

### Windows

Go to the file it was installed and execute *GMN_win64.exe* (64-bit).

```powershell
cd guessmynumber
.\GMN_win64.exe
```

How to rebuild
--------------

If you wish to edit any of the source code, you will probably wish
to recompile it. A 'build.ps1' PowerShell file is included, which
allows you to compile source/main.cpp to *GMN_win64.exe* and
*GMN_linux*.


> Compiling only currently works from Windows

### Compile to Windows only

```powershell
.\build.ps1
```

### Compile to Windows and Linux (as WSL)

```powershell
.\build.ps1 -wsl
```

---

#### Additional options

You can also add the '-e' or '-exec' command to execute the Windows
executable after compiling.

```powershell
.\build.ps1 -wsl -e
```
