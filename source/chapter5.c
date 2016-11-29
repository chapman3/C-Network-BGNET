// 5		- System calls progression 
// 5.1  	- getaddrinfo()
// 5.2	- socket()
//		- pass addrinfo to a socket constructor:
int s;
struct addrinfo hints, *res;
memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_family = AI_PASSIVE;
getaddrinfo("www.example.com", "http", &hints, &res);
s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
//		- returns a socket descriptor, or -1 in error
// 5.3	- bind(), associate addrinfo with socket descriptor
bind(s, res->ai_addr, res->ai_addrlen);
// 5.4	- connect()
connect(s, res->ai_addr, res->ai_addrlen);
//		- returns 0-1 if error
//		- don't bind when connecting though =======
// 5.5	- listen()
//		- Sequence for creating a listener::
//			-getaddrinfo() 	| attr
//			-socket() 		| create socket descriptor
//			-bind() 		| bind to port
//			-listen()		| await connection
//		- Then accept connection
// 5.6	- accept(), accepts connection, creates secondary socket
//		- descriptor so first one can continue listening for connections
accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
//		- sockfd is the listening socket
//		- *************** SEE listeningSocket.c ***************
// 5.7	- send(), recv()
//		- send() SAMPLE
char *msg = "Sent Text";
int len, bytes_sent;
len = strlen(msg);
bytes_sent = send(sockfd, msg, len, 0);
//		- if bytes_sent < len then not all data was sent
//		- if recv() returns 0, then connection has closed
// 5.8	- recvfrom(), sendto(), datagram send and receive methods
//		- same as send and receive but with information to socket addresses
//		- no stream is maintained unless you connect a datagram socket
// 5.9	- close() and shutdown()
//		- close() closes the socket immediately
//		- shutdown() takes an int arg to define close behavior
//			- 0 | Further receives are disallowed
//			- 1 | Further sends are disallowed
//			- 2 | All are disallowed, mirroring behavior of close()
//		- BUT shutdown() doesn't free a socket descriptor, 
//		- You still need to use close() to free sockfd
// 5.10 	- getpeername()
//		- tells you who is at the other end of a socket connection
// 5.11 	- gethostname()
//		- tells you the name of your own machine
// END