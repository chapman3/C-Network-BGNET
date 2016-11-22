//2.1 	- Look up Raw Sockets later
//		- Makes sense to use TCP when all packets matter,
//		- UDP if some dont.

//3.1	- 
//3.2	- Endian Converting Functions
//			-htons()	| Host to Network Short
//			-htonl()	| Host to Network Long
//			-ntohs()	| Network to Host Short
//			-nothl()	| Network to Host Long
//3.3	- Structs and ops
//3.4	- IP Addresses
//3.4.1 - 

//4		- Deals with IPv6 conversion

//5		- System calls progression 
//5.1  	- getaddrinfo()
//5.2	- socket()
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
//5.3	- bind(), associate addrinfo with socket descriptor
bind(s, res->ai_addr, res->ai_addrlen);
//5.4	- connect()
connect(s, res->ai_addr, res->ai_addrlen);
//		- returns 0-1 if error
//		- don't bind when connecting though =======
//5.5	- listen()
//		- Sequence for creating a listener::
//			-getaddrinfo() 	| attr
//			-socket() 		| create socket descriptor
//			-bind() 		| bind to port
//			-listen()		| await connection
//		- Then accept connection
//5.6	- accept(), accepts connection, creates secondary socket
//		- descriptor so first one can continue listening for connections
accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
//		- sockfd is the listening socket
//		- *************** SEE listeningSocket.c ***************
//5.7	- send(), recv()
//		



//Left off page 23