# CS 100 Programming Project

*WINTER 2020*

*Hamza Syed 862097875*

*Smit Patel 862076143*

## INTRODUCTION
  Our assignment will be able to accomplish reading the command line and executing the appropriate commands. It will be able
  to differentiate between OR, AND, and a semicolon until an exit command is reached. Our design pattern illustrates the use
  of composite classes referenced from parent classes. The design contains classes for the command tokens, as well as classes
  for the connectors. The connector class has subclasses for each connector (AND, OR, and SEMICOLON), and there is one 
  subclass for the tokens class as well. All subclasses have a run function designed to run the command prompt in sync with 
  the connectors next to the command token.
  
  
  ## OMT DIAGRAM
  
  ![Image of OMT](https://github.com/cs100/assignment-linux_gods/blob/master/images/images.png?raw=true)
  
  
  ## CLASSES
    
   Our base class is the CMD class. This class stores the input from the command line and distribute it to the Token
   and Connector classes. The Connector class keeps track of the left hand side of the connectors and right hand side of 
   the connectors and assigns them to the subclass of Semicolon, AND, OR. The Tokens class runs the commands as needed 
   and checks if  they properly executed. The Token class has a subclass called Exit that performs all the commands 
   inorder and in accordance to the connectors.
   
   ## PROTOTYPES/RESEARCH
   fork()    - The process for creating a child process that runs alongside the parent process. Returns an integer value.
               (negative equals child process wasn't created successfully, 0 equals returning a newly created child process,
               positive equals returns to parent with the value ID of newly created child process.) The total processes
               created by fork is 2^(number of forks).
               (syntax = fork())
               
   execvp()  - Will search for a specific file on the command line, and then execute the file. Will return -1 if an 
               error has occured. 
               (syntax = int execvp(const char *file, char *const argv[]))
               
   waitpid() - Halts parent process and waits for changes in child process (specified by pid) and then obtains information
               regarding the changed child process or until the child process is terminated. Returns pid of child if the 
               child exited successfully and 0 if parent has to wait for child to terminate. 
               (syntax = pid_t waitpid(child_pid &status, options))
               
   ## DEVELOPMENT AND TESTING ROADMAP
   First we plan on creating the CMD class which will have a function that takes the command line and returns a vector with   
   the proper assignments for each token and connector.
   ([Issue #1](https://github.com/cs100/assignment-linux_gods/issues/1), 
   [Issue #15](https://github.com/cs100/assignment-linux_gods/issues/15))
   
   Then, we create the Token and Connector subclasses. 
   ([Issue #2](https://github.com/cs100/assignment-linux_gods/issues/2), 
   [Issue #4](https://github.com/cs100/assignment-linux_gods/issues/4))
   
   After those subclasses are created we will create the Exit subclass for the Token subclass and the AND, OR, and Semicolon 
   subclasses for the Connector subclass. 
   ([Issue #3](https://github.com/cs100/assignment-linux_gods/issues/3), 
   [Issue #5](https://github.com/cs100/assignment-linux_gods/issues/5), 
   [Issue #6](https://github.com/cs100/assignment-linux_gods/issues/6), 
   [Issue #7](https://github.com/cs100/assignment-linux_gods/issues/7))
   
   Then we will implement the run function which checks if the operation executed properly for each subclass (Exit, AND, OR, 
   Semicolon). 
   ([Issue #8](https://github.com/cs100/assignment-linux_gods/issues/8), 
   [Issue #9](https://github.com/cs100/assignment-linux_gods/issues/9))
   
   We will then Unit test each run function individually for any bugs.
   ([Issue #10](https://github.com/cs100/assignment-linux_gods/issues/10), 
   [Issue #11](https://github.com/cs100/assignment-linux_gods/issues/11), 
   [Issue #12](https://github.com/cs100/assignment-linux_gods/issues/12), 
   [Issue #13](https://github.com/cs100/assignment-linux_gods/issues/13))
   
   After all the Unit test are completed we will do an Intergration test to see how all the run functions interact and fix any 
   bugs if necessary. 
   ([Issue #14](https://github.com/cs100/assignment-linux_gods/issues/14))
