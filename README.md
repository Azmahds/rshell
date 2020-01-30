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
    
   Our base class is the CMD class. This class has no other use except that it will be a pure virtual function.
   The inheritance classes from the base class will be the Connector and Token subclass. Both of these classes will 
   contain virtual functions as well as a string variable to keep track of what token or connector is inside of 
   their respective class. The connector class will have aditional pointers to its left and right hand connectors.
   Inheriting from the token class will be the Exit subclass. This subclass will contain a run function that executes 
   the commands from the tokens class, and will also exit the program once all commands are finished executing. Lastly 
   there will be three inheritance classes for the connector class. The first one is the AND subclass, which will have 
   a run funtion that compares the left command and right command to see which command should be run in which order. The 
   second one is the OR subclass, which will have a run function that compares the left and right commands to see which
   command should be executed. Finally, there is the SEMICOLON subclass. This subclass will just execute every command after
   itself, using its own run function.
   
   ## PROTOTYPES/RESEARCH
   `fork()`    - The process for creating a child process that runs alongside the parent process. Returns an integer value.
               (negative equals child process wasn't created successfully, 0 equals returning a newly created child process,
               positive equals returns to parent with the value ID of newly created child process.) The total processes
               created by fork is 2^(number of forks).
               (syntax = `fork()`)
               
   `execvp()`  - Will search for a specific file on the command line, and then execute the file. Will return -1 if an 
               error has occured. 
               (syntax = `int execvp(const char *file, char *const argv[])`)
               
   `waitpid()` - Halts parent process and waits for changes in child process (specified by pid) and then obtains information
               regarding the changed child process or until the child process is terminated. Returns pid of child if the 
               child exited successfully and 0 if parent has to wait for child to terminate. 
               (syntax = `pid_t waitpid(child_pid &status, options)`)
               
   One of the ways we tested connectors was by inputing only one command and adding a `||` or a `&& `but with no input after. This resulted 
   in the terminal asking for another command to be inserted before it actually ran the input. We also tried inputing `echo Hello && 
   World` which we wanted to output "Hello && World" but instead outputted "Hello" and then an error message saying that the World 
   command was not found. To get the result that we wanted we needed to do `echo "Hello && World"`
               
   ## DEVELOPMENT AND TESTING ROADMAP
   First we plan on creating the CMD class which will be our pure virtual base class.
   ([Issue #1](https://github.com/cs100/assignment-linux_gods/issues/1)) 
   
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
