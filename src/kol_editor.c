#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void usage(void) __dead;

int
main(int argc, char *argv[])
{
        extern int optind;
        int ch, debugflag;

        setprogname(argv[0]);

        debugflag = 0;
        while ((ch = getopt(argc, argv, "dh")) != -1) {
                switch (ch) {
                case 'd':
                        debugflag = 1;
                        break;
                case '?':
                case 'h':
                default:
                        usage();
                        /* NOTREACHED */
                }
        }
        argc -= optind;


        return EXIT_SUCCESS;
}

/*
 * Print out usage information and exit the program.
 */
static void
usage(void)
{
        (void)fprintf(stderr, "usage: %s [-dh]\n", getprogname());
        (void)fflush(stdout);
        exit(EXIT_FAILURE);
        /* NOTREACHED */
}
