# myftp

# Command-Line FTP

## Client Side

- [ ] USER <username>
- [ ] PASS <password>
- [ ] CWD <directory>
- [ ] LIST
- [ ] RETR <filename>
- [ ] STOR <filename>
- [ ] DELE <filename>
- [ ] QUIT


## Server Side

- [x] USER <username>   Only anonymous user is allowed
- [x] PASS <password>   Any password is accepted for anonymous user
- [x] CWD <directory>
- [X] LIST
- [ ] RETR <filename>
- [X] STOR <filename>
- [ ] DELE <filename>
- [ ] QUIT
- [X] PASV
- [X] PORT <host-port> (host-port: h1,h2,h3,h4,p1,p2)
- [ ] HELP


### Middleware Made

- [x] Nbr of Arguments [link](sources/server/commands/Middleware.cpp#L10)
