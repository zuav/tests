#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/* Flag set by `--verbose'. */
static int verbose_flag;

int main(int argc, char *argv[])
{
    int c;

    while (1)
    {
        static struct option long_options[] = {
            /* These options don't set a flag.
               We distinguish them by their indices. */
            {"add",     required_argument, 0, 'a'},
            {"append",  required_argument, 0, 'b'},
            {"delete",  required_argument, 0, 'd'},
            {"create",  required_argument, 0, 'c'},
            {"file",    required_argument, 0, 'f'},
            {0, 0, 0, 0}
        };
        /* `getopt_long' stores the option index here. */
        int option_index = 0;

        c = getopt_long(argc, argv, "a:b:c:d:f:", long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
        {
        case 'a':
            printf ("option -a with value `%s'\n", optarg);
            break;

        case 'b':
            printf ("option -b with value `%s'\n", optarg);
            break;

        case 'c':
            printf ("option -c with value `%s'\n", optarg);
            break;

        case 'd':
            printf ("option -d with value `%s'\n", optarg);
            break;

        case 'f':
            printf ("option -f with value `%s'\n", optarg);
            break;

        case '?':
            /* `getopt_long' already printed an error message. */
            break;

        default:
            abort ();
        }
    }

    /* Instead of reporting `--verbose'
       and `--brief' as they are encountered,
       we report the final status resulting from them. */
    if (verbose_flag)
        puts ("verbose flag is set");

    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
    }

    exit (0);
}

