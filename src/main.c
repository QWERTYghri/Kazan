/*
 * Main Program File for Kazan
 *
 * I feel like this is more complicated than it needs to be
 */
 
/* LIB C */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <fts.h>

/* POSIX */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <regex.h>

/* Local */
#include "./define.h"

/* Initialize Program as Daemon */
static void
createDaemon ( void )
{
	/* Define pid and then fork from parent process */
	pid_t pid = fork ();
	
	/* Exit with EXIT_FAILURE if PID returns less than 0 */
	if ( pid < 0 )
		exit ( EXIT_FAILURE );
	
	/* Exit with EXIT_SUCCESS if PID returns greater than 0 */
	if ( pid > 0 )
		exit ( EXIT_SUCCESS );
		
	/* Create new session and exit if fails */
	if ( setsid () < 0 )
		exit ( EXIT_FAILURE );
		
	/* Signal Handle */
	signal ( SIGCHLD, SIG_IGN );
	signal ( SIGHUP, SIG_IGN );
	
	pid = fork ();
	
	/* Exit with EXIT_FAILURE if PID returns less than 0 */
	if ( pid < 0 )
		exit ( EXIT_FAILURE );
	
	/* Exit with EXIT_SUCCESS if PID returns greater than 0 */
	if ( pid > 0 )
		exit ( EXIT_SUCCESS );
	
	/* Set file node mask and changing working directory to root */
	umask ( 0 );
	chdir ( "/" );
    
    	for ( int32_t i = sysconf ( _SC_OPEN_MAX ); i >= 0; i-- )
    		close ( i );
}

/* Clean Kazan Function */
static void
cleanKazan ( void )
{
	/* Find PID */
	FTS* processes = fts_open ( PROC, 
}

/* Wallpaper function, creates daemon and plays video on loop */
static void
wallpaper ( char* fileName, int32_t loop )
{
	createDaemon ();
	
	while ( loop )
	{
		sleep ( 20 );
	}
}

/* Play all videos in a directory */
static void
folder ( char* fileName )
{
	
}

/* Parse Options Functions */
static int32_t
parseOptions ( int32_t argc, char** argv )
{
	/* Long Argument List */
	struct option commandOptions[] =
	{
		{ "clean",	no_argument,	   NULL, 'c' },
		{ "add",	required_argument, NULL, 'a' },
		{ "folder",	required_argument, NULL, 'f' },
		{ NULL,		0,		   NULL, 0 }
	};
	
	/* Parse arguments and return argument code */
	int32_t character;
	int optionIndex = 0;
	while ( ( character = getopt_long ( argc, argv, "ca:", commandOptions, &optionIndex ) ) != -1 )
	{
		switch ( character )
		{
			case 'c':
				/* Clean all instances of kazan */
				cleanKazan ();
				break;
			case 'a':
				/* Start playing a file on loop */
				wallpaper ( optarg );
				break;
			case 'f':
				/* Loop through entire directory and fade transition between each wallpaper */
				folder ( optarg );
				break;
			default:
				fprintf ( stderr, GET_OPT_ERROR, character );
				
				/* Return failure */
				return -1;
		}
	}

	/* Arguments Check */	
	if ( optind < argc )
	{
		/* List that the options are invalid */
		fprintf ( stderr, ERROR_NO_OPTIONS );
		
		/* List invalid commands written */
		while ( optind < argc )
			fprintf ( stderr, INVALID_COMMAND, argv[optind++] );
		
		/* Return failure */
		return -1;
	}
	
	/* Return success */
	return 0;
}

/* Start Point */
int
main ( int argc, char** argv )
{
	if ( parseOptions ( argc, argv ) )
		exit ( EXIT_FAILURE );
	
	return 0;
}
