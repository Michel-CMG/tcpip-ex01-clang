# tcpip-ex01-clang
### Exercise for TCPIP communication by using C language<br>
#### This is copied from tcpip-ex01-dotnetcore
Just a simple exercise for localhost communication.
  - Program "client" sends request to "server" and "server" responses.
  - Print request/response contents to console screen.
  - Request/response contents are using UTF8 for Asian text.
  - Requests are like:
  
        { id:10, content:"あいうえお" }
        { id:20, content:"かきくけこ" }
        { id:00, content:"stop the server" } // Client send this request to stop the server program.
  - Responses are like:
  
        { id:11, content:"'あいうえお' processed" }
        { id:21, content:"'かきくけこ' processed" }
        { id:00, content:"server starts to stop" } // Response and stop the server
