<h1> Simple shell project </h1>
this project is about to create a simple shell that can execute commands and builtins similiar to the sh shell.

<h2> compilation </h2>
to compile the shell you need to use the following command:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
<h2> usage </h2>
to use the shell you need to execute the following command:

```
./hsh
```
<h2> commands </h2>
The shell can execute any command that is in the PATH variable, and also the following builtins:
<table> 
  <tr>
    <th> Command </th>
    <th> Description </th>
  </tr>
  <tr>
    <td> env </td>
    <td> prints the environment variables </td>
  </tr>
  <tr>
    <td> setenv </td>
    <td> sets a new environment variable </td>
  </tr>
  <tr>
    <td> unsetenv </td>
    <td> removes an environment variable </td>
  </tr>
  <tr>
    <td> cd </td>
    <td> changes the current directory </td>
  </tr>
  <tr>
    <td> btats </td>
    <td> prints the current working directory </td>
  </tr>
  <tr>
    <td> exit </td>
    <td> exits the shell </td>
  </tr>
</table>

the shell can execute commands with arguments.

what the shell cannot do:
* pipes
* separators
* comments
* aliases
* logical operators
* history

but i will try to implement them one by one in the future.

<h2> examples </h2>

```
$ ./hsh
$ ls
Desktop    Documents    Downloads    Music    Pictures    Public    Templates    Videos
$ cd Desktop
$ btats
/home/vagrant/Desktop
$ ls
icons
$ exit
```
