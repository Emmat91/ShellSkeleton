/*
 * Headstart for Assignment 2
 * CS 4420/5420
 * SS 2014/15
 * 
 * Student Name: Pinfang Ding
 * 
 * Student Name: Chong Liu
 * 
 * 
 * 
 * 
 */

/* the states */
#define COMMAND 1
#define ARG 2
#define INFILE 3
#define OUTFILE 4
#define UNDEF 5
#define ASSIGN 6

struct Command {
  char *command;
  char *args[11];
  int numargs;
};

struct CommandData {
  struct Command TheCommands[20];  /* the commands to be
          executed.  TheCommands[0] is the first command
          to be executed.  Its output is piped to
          TheCommands[1], etc. */
  int numcommands; /* the number of commands in the above array */
  char *infile;   /* the file for input redirection, NULL if none */
  char *outfile;  /* the file for output redirection, NULL if none */
  int  background;  /* 0 if process is to run in foreground, 1 if in background */
  int incommand;  //0 if the command is not build-in, 1 if is build-in
  int isassign; // 0 if the value is not assigned, 1 if is assigned
  char *value; // the value from assignment
};


extern int ParseCommandLine(char *, struct CommandData *);
extern void Debugging(char *, struct CommandData *);
extern void Execute(struct CommandData *);

