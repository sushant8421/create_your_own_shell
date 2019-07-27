# create_your_own_shell
# Light version of a shell you use in your Terminal 

run by : ./my_shell

# program file: 

1. When you run the program then a shell will created (cheetah@sushant>> ) and then you have to enter some command to the     Console and this command will read using readline() function.This is the parent process which will run untill either exit command is executed or 0 is returned. 

2. If you dont know about what command to type just use "help" command .

3. Whatever command is typed by the user is taken from console into a character pointer(name : input) , and this input is
   passed to get_input() function .

4. get_input(){
 
	4.1- If the input is not null then it is stored in history stack using add_history(input) function, for later
    	use(using upper arrow and lower arrow   keys). 
	
	4.2- In this function the input string is coverted into a array of string (name : command) , which is made from input 
    	string using separator as space, and this command[][] is returned to main() function. 
   } 

5. Now in main() function command[0] location is compared with all commands we have to implement.

6. When a match is found then for that particular command to be executed we will create a child , and execute that
   command by using execv() function passing two arguments namely the file path of the C FILE to be executed and argument
   list that will be required by the command .

7. After the execution of the particular command the control comes back to parent process i.e. main() fuction . Now again
   command prompt looks like(cheetah@sushant>> ) asking for another command .

8. The commands which are implemented can be accessed using "help" commmand as told earlier , u can find Description ,
   Syntax , options etc.. from there .

9. We have implemented "exit" command to smoothly come out from the shell .
