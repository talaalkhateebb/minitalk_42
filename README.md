*This project has been created as part of the 42 curriculum by talkhati*

Description
Minitalk is a small client-server communication program developed in C, using UNIX signals only.  
The goal of this project is to send a string from a client process to a server process, bit by bit, using `SIGUSR1` and `SIGUSR2`.

This project is part of the 42 curriculum and focuses on:
- Inter-process communication
- Signal handling
- Bitwise operations
- Low-level system programming

Technologies
- Language: C
- Signals: `SIGUSR1`, `SIGUSR2`
- System calls: `signal`, `sigaction`, `kill`, `getpid`, `pause`, `usleep`, `malloc`, `free`

Project Structure
├── client.c
├── server_bonus.c
├── client_bonus.c
├── server.c
├── minitalk.h
├── Makefile
└── README.md
├── units.c
└── units_bonus.c

Compilation
Compile the project using:
```bash
make

Usage
1️⃣ Start the server
./server

The server will display its PID:

Server PID: 12345

2️⃣ Send a message from the client
./client <SERVER_PID> "Your message here"


Example:

./client 12345 "Hello Minitalk!"


The server will immediately display:

Hello Minitalk!

-Mandatory Features

*Server prints its PID on launch

*Client sends a string to the server

*Communication uses only UNIX signals

*Only SIGUSR1 and SIGUSR2 are used

*Server can receive multiple messages without restarting

*No memory leaks

*No unexpected crashes (segfaults, double free, etc.)

- Bonus Features (if implemented)

*Server sends an acknowledgment signal to the client after receiving a message

*Unicode (UTF-8) character support

- Implementation Details

*Each character is sent bit by bit

*SIGUSR1 represents 0

*SIGUSR2 represents 1

*The server reconstructs characters after receiving 8 bits

*Signal handling is done using sigaction

- Testing

You can test multiple clients by running:

./client <PID> "First message"
./client <PID> "Second message"


The server should correctly display both messages sequentially.

- Notes

*Linux does not queue signals, so timing (usleep) is important

*One global variable per program is used and justified

*Project follows 42 Norm


