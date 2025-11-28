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
- [ ] LIST
- [ ] RETR <filename>
- [ ] STOR <filename>
- [ ] DELE <filename>
- [ ] QUIT


### Middleware Made

- [x] Nbr of Arguments [link](sources/server/commands/Middleware.cpp#L10)
