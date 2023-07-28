# Reversed_Engineering_On_A_C_File
This module will demonstrate how to expose a compiled program using reverse engineering on it.
We're gonna use IDAFree during the process. First of all, you will need to compile the given c file. After that, you need to upload the compiled file into IDAFree. Then you can start analyzing to assembly code of the compiled file. 

![Screenshot1](https://github.com/RoterHerzog/Reversed_Engineering_On_A_C_File/assets/82552351/af223361-ef54-4be7-a2d0-f3ec6e56a2ff)


At the first screenshot you should be able to spot the main call. Until main call there is nothing important to consider. Usually you should be aware of the function calls and register movements. When you look at the first screenshot, declarations of variables and called functions can be easily spotted. Especially can be seen that the check_pass function is getting rax register as a parameter that has already been set as the password from password_buffer.

Then you can double-click to the check_pass function. In that case, you should be able to see that screenshot;

![Screenshot2](https://github.com/RoterHerzog/Reversed_Engineering_On_A_C_File/assets/82552351/e879b5c7-7301-46e3-819d-5dad3ebe7a6d)

In that screenshot firstly, the password which has been used as a parameter to the check_pass function is copied to the rcx register for comparing. Then, 2126F6C6C6568h binary value is setting as rax register for comparing .Then real_password pointer is setting as rax and of course that represents us the value of real_password pointer is actually 2126F6C6C6568h. when we convert 216F6C6C6568 hexadecimal value into text, we will be getting !olleh which is the reflection of hello! (we are getting password reverse due to stack architecture) and that is what we were looking for.


![Screenshot3](https://github.com/RoterHerzog/Reversed_Engineering_On_A_C_File/assets/82552351/727f2daa-0af1-4309-afb2-a25e3f0d80df)

Last but not least when we get back to the main assembly code we can identify the requirements for being an Authorized User. Likely in this screenshot, we can distinguish the rules from cmp functions and jnz functions. In this example for being an Authorized User you have to ensure these requirements down below:

->Length of usernames must be longer than one character
->First character should be 1 
->Second character should be 0

When you fulfill that tasks then you can be treated as an Authorized User.
