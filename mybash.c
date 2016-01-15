/*
 * Headstart for Assignment 2
 * CS 4420
 * SS 2014/15
 *
 * Student Name:  Pinfang Ding
 * Student Name:  Chong Liu
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

extern char *env_name[10];	//shell's process environment 
extern char *env_para[10];

int main(int argc, char *argv[])
{	
	int i;
	for(i=0; i<10; ++i)
	{
		env_name[i]="NULL";
		env_para[i]="NULL";
	}
	env_name[0]="PATH";
	env_para[0]=getenv("PATH");
	env_name[1]="HOME";
	env_para[1]=getenv("HOME");
	env_name[2]="DEBUG";
	env_para[2]="NO";

	char line[100000];
	int temp = 0;
	do
	{		
		char *cwd;
        if ((cwd = getcwd(NULL, 64)) == NULL) {
        	perror("pwd");
            exit(2);
        }
    	printf("\n\n%s> ", cwd);
    	free(cwd);
		fgets(line, 100000, stdin);
		
		struct CommandData data;
		temp = ParseCommandLine(line, &data);
		if(temp != 0)
		{
			//assign value
			if(data.isassign == 1)
			{
				int i=0;
				printf("here:\n");


				while((strcmp(env_name[i],data.TheCommands[0].command)!=0) && (strcmp(env_name[i],"NULL")!=0))
					++i;
				
				if(strcmp(env_name[i], data.TheCommands[0].command)==0)
				{
					env_para[i] = data.value;
					printf("%s = %s",env_name[i],env_para[i]);
				}
				else
					printf("Error, invaild variable %s\n",data.TheCommands[0].command);


				data.isassign = 0;
				data.value = NULL;
			}
			//debug mode
			else if(strcmp(env_para[2],"NO")!=0)
			{
				Debugging(line, &data);
			}
			//export variable
			else if(strcmp(data.TheCommands[0].command,"export")==0)
			{
				int i=0;
				while(strcmp(env_name[i],"NULL")!=0)
					++i;
				if(data.TheCommands[0].numargs == 1)
				{
					env_name[i] = data.TheCommands[0].args[0];
					printf("variable %s is exported successful.",env_name[i]);
				}
				else
					printf("Error, one variable can be export at one time");
			}
			else
			{
				Execute(&data);
			}
		}

	}while(strstr(line,"exit")==NULL);
    
    exit(0);
}




