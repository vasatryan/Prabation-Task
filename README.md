# Probation-Task

This is a simple password generator and comparison tool implemented in C, C++, and Python. The project consists of the following files:

- `commonPassword.txt`: A list of common passwords for reference.
- `comparator.sh`: A shell script to compare generated passwords with common passwords.
- `generatedPassword.txt`: A file to store generated passwords.
- `task.c`: C implementation of the password generator.
- `task.cpp`: C++ implementation of the password generator.
- `task.py`: Python implementation of the password generator.

## Usage

```bash
git clone https://github.com/vasatryan/Prabation-Task.git
cd Probation-Task
```

### C Implementation

To compile and run the C version of the password generator, use the following commands:

```bash
gcc task.c -o password_generator_c
./password_generator_c
```

## C++ Implementation

To compile and run the C++ version of the password generator, use the following commands:

```bash
g++ task.c -o password_generator_c++
./password_generator_c++
```

### Python Implementation

To run the Python version of the password generator, use the following command:

```bash
python task.py
```

### Compare commonPassword and generatedPassword

```bash
chmod +x comparator.sh
bash comparator.sh commonPassword.txt generatedPassword.txt
