*This project has been created as part
of the 42 curriculum by gviniciu.*

# GET-NEXT-LINE

## Description
The get_next_line project consists of a function that reads a single line from a file descriptor.  

The project is divided into three files:
```c
get_next_line.c
get_next_line.h
get_next_line_utils.c
```

## Instructions
-> First, create a ".txt" file to read.

To use the function to read a single line, create a **main.c** file like the one below: 

```c
int	main(void)
{
	int	fd;

	fd = open("sample.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
```
If you want to read the whole file, create a **main.c** like the one below: 

```c
int	main(void)
{
	int	fd;
	char 	*line;

	fd = open("sample.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	return (0);
}
```

Compile the project with the flag **BUFFER_SIZE**, to define the size of the buffer you want to use:

```c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n *.c
```
Run the executable:

```c
./a.out
```

## Resources

- **man read** / https://man7.org/linux/man-pages/man2/read.2.html: linux manual for the read() function. 
-  Use examples of read function: https://www.educative.io/answers/read-data-from-a-file-using-read-in-c

### How AI was used

- Used to better understand the read() function. 

## Selected Algorithm

This solution is pretty straightforward. The read function is called, and as it reads the file, it also writes the content inside the buffer. 

The content is copied into a another string called **"stash"**, and the code searches for a **'\n'** or end of file, in order to determine if it's necessary to call read() again. 

When it finds a **'\n'**, the **get_line()** function is called, and it allocates another string to copy stash up to the **'\n'**. 

The stash is then processed with the **process_stash()** function, because it needs to let go of the line that is going to be returned. As stash is a static variable, its state "survives" until the end of the program, allowing the file to read usig a loop. 

Finally, the line is returned.

