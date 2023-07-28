# RPC - Sun Implementation

## Description

This RPC project uses the Sun Implementation to create a concurrent server that serves the following methods - calculations:

- Dot product (X * Y)
- mean values Ex and Ey
- The product r * (X + Y)

Main project files:

- RPC server (ask1_server.c)
- RPC client / Socket server (ask1_client.c)
- Socket client (client.c)

A user (socket client) connects to the socket server using TCP AF_INET socket. The user enters which method to use (1, 2 or 3), and the necessary data. X and Y are vectors, and r is a real (float) number.  
The RPC client receives this data and sends it to the RPC server, which implements the above methods.  

*This project was made during my Distributed Systems course in University.*

**Tested using WSL 2.0, Windows 11.**

## How to run

1. ```sudo apt-get install rpcbind```
2. ```sudo rpcbind```
3. ```rpcgen –C –a ask1.x```
4. ```make``` ```//will probably need to rename makefile to Makefile.```
5. ```gcc client.c –o client```
6. ```./ask1_server```
7. ```./ask1_client localhost <port>```
8. ```./client localhost <port>```
