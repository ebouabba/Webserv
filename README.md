# WEBSERV
![Screenshot](https://webserv.io/wp-content/uploads/2022/11/Social-Share.jpg)
HTTP server in C++98

socket : Socket Programming is a method to connect two nodes over a network to establish a means of communication between those two nodes. A node represents a computer or a physical device with an internet connection. A socket is the endpoint used for connecting to a node. The signals required to implement the connection between two nodes are sent and received using the sockets on each node respectively.

# Request Line
 GET /home.html HTTP/1.1 

GET: this is Method The client requests a resource on the web server
POST: The client submits data to a resource on the web server.
DELETE: The client deletes a resource on the web server. 
/home.html:  is the resource requested
HTTP 1.1: s the protocol used
HTTP methods:HTTP methods indicate the action that the client wishes to perform on the web server  

# HTTP Request Headers
There are various possibilities when including an HTTP header in the HTTP request.
A header is a case-insensitive name followed by a: and then followed by a value.
Example : 
    Host: example.com
    User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.9; rv:50.0) Gecko/20100101 Firefox/50.0
    Accept: */*
    Accept-Language: en
    Content-type: text/json

Host: header specifies the host of the server and indicates where the resource is requested from.
User-Agent: header informs the web server of the application that is making the request. It often includes.
Accept: header informs the web server what type of content the client will accept as the response.
Accept-Language: header indicates the language and optionally the locale that the client prefers.
Content-type: header indicates the type of content being transmitted in the request body.

# HTTP Request Body

