# crud-c-mysql
Create, Read, Update and Delete data under MySQL Database

Software Info:
=>TDM-GCC 4.9.2 64-bit Release
=>Dev-C++ version 5.11
=>Windows10

Require:
=>MySQL Server
=>GCC
=>Dev-Cpp program

Development by Dev-Cpp
Step
1. Open Dev-C++
2. Open ProjectMysql.dev
3. Into menu Project->Project Options...
4. Click Directories tab
  4.1 add C:\Program Files\MySQL\MySQL Server 5.X\lib into Library Directories tab
  4.2 add C:\Program Files\MySQL\MySQL Server 5.X\include into Include Directories tab
  4.3 add C:\Program Files\MySQL\MySQL Server 5.X\include\mysql into Include Directories tab
5. Click Parameters tab
  5.1 add -lmysql into Linker: Form

# Command line for github commit #

$ git add .
# Adds the file to your local repository and stages it for commit. To unstage a file, use 'git reset HEAD YOUR-FILE'.

$ git commit -m "Add existing file"
# Commits the tracked changes and prepares them to be pushed to a remote repository. 
To remove this commit and modify the file, use 'git reset --soft HEAD~1' and commit and add the file again.

$ git push origin your-branch
# Pushes the changes in your local repository up to the remote repository you specified as the origin
# Example: git push origin master

