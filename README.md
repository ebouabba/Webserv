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
HTTP requests can optionally include a request body. A request body is often included when using the HTTP POST and PUT methods to transmit data.

    POST /users HTTP/1.1
    Host: example.com
    {
        "key1":"value1",
        "key2":"value2",
        "array1":["value3","value4"]
    }

    PUT /users/1 HTTP/1.1
    Host: example.com
    Content-type: text/json
    {
        "key1":"value1"
    }

# HTTP Responses
When the web server is finished processing the HTTP request, it will send back an HTTP response.
The first line of the response is the status line. This line shows the client if the request was successful or if an error occurred.
HTTP/1.1 200 OK 
The line begins with the HTTP protocol version, followed by the status code and a reason phrase. The reason phrase is a textual representation of the status code.

