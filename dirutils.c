#include <pwd.h>
#include <dirent.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define max_cwd 256

void current_working_directory()
{
	char cwd[max_cwd] = {'\0'};
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		fprintf(stdout, "Current working dir: %s\n", cwd);
	else
		perror("getcwd() error");
}

void change_directory(char *buffer)
{
	char delimiter[] = " ";
	char *path;
	char *inptcpy;
	int inptlen;    

	/* Copy buffer for parsing */
	inptlen = strlen(buffer);
	inptcpy = (char*) calloc(inptlen + 1, sizeof(char));
	strncpy(inptcpy, buffer, inptlen);
	/* Get second word (path) */
	strtok (inptcpy, delimiter);
	path = strtok (NULL, delimiter);

	if (strcmp(buffer,"cd ..") == 0)
		chdir("../");
	else if (strcmp(buffer,"cd") == 0 || strcmp(buffer,"cd ~") == 0)
		chdir(getenv("HOME"));
	else
		chdir(path);

	if (inptcpy)
		free(inptcpy);
}
/*
void list_directory()
{
	DIR  *d;
	struct dirent *dir;

	d = opendir(".");
	if (d) {
	while ((dir = readdir(d)) != NULL)      
		printf("%s\n", dir->d_name);
	
	closedir(d);
	}
}
*/