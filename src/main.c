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

static int32_t


int
main ( int argc, char** argv )
{
	int32_t result = parseOptions ( argc, argv );

	return 0;
}
