# threads 

POSIX IPC: a simple sample program for using Message Queues in multithreading
=============================================================================

Overview
--------

POSIX IPC: a simple sample program for using UNIX Message Queues in multithreading.

1. threads.c - the main program that creates the two threads that communicate via POSIX IPC.

2. writer.c - the writer thread that writes to the reader thread.

3. reader.c - the reader thread that reads from the writer thread.

Includes a mini-benchmark for calculating performance in Linux environment.

Read the full article on artcprogramming.blogspot.com:
- https://artcprogramming.blogspot.com/2021/01/per-un-pugno-di-ipc-considerazioni.html
- https://artcprogramming.blogspot.com/2021/02/per-qualche-ipc-in-piu-considerazioni.html
- https://artcprogramming.blogspot.com/2021/03/il-buono-il-brutto-lipc-considerazioni.html

Or read on italianCoders.it:
- https://italiancoders.it/per-un-pugno-di-ipc-considerazioni-sulle-prestazioni-della-posix-ipc-pt-1/
- https://italiancoders.it/per-qualche-ipc-in-piu-considerazioni-sulle-prestazioni-della-posix-ipc-pt-2/
- https://italiancoders.it/il-buono-il-brutto-lipc-considerazioni-sulle-prestazioni-della-posix-ipc-pt-3/

Copyright © 2021 Aldo Abate <artcprogramming@gmail.com>
