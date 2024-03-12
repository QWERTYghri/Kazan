/*
 * Main Program File for Kazan
 *
 */
 
/* LIB C */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* POSIX */
#include <unistd.h>
#include <getopt.h>

/* Local */
#include "./define.h"

/* Parse Options Functions */
static int32_t
parseOptions ( int32_t argc, char** argv )
{
	/* Long Argument List */
	struct option commandOptions[] =
	{
		{ "clean",	no_argument,	   NULL, 'c' },
		{ "add",	required_argument, NULL, 'a' },
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
				return 1;
			case 'a':
				return 2;
			default:
				fprintf ( stderr, GET_OPT_ERROR, character );
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
	}
	
	return -1;
}

/* Start Point */
int
main ( int argc, char** argv )
{
	int32_t result = parseOptions ( argc, argv );
	printf ( "%d\n", result );

	return 0;
}
