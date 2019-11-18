#include <iostream>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct globalArgs_t {
    int verbose;
    int my_list[4];
    int my_boolean;
    string my_file;
} global_args;

static const char *optString = "v:l:b:f:h?";

static const struct option __GETOPT_LONG_H__ = {
        { "verbose", required_argument, nullptr, 'v'},
        { "help", no_argument, nullptr, 'h'},
        { "my_list", optional_argument, nullptr, 'l'},
        { "my_boolean", optional_argument, nullptr, 'b'},
		{ "my_file", optional_argument, nullptr, 'f'},
        {nullptr, no_argument, nullptr, 0}
};

void display_usage()
{
    puts("List of valid keys: "
            "\nArguments:"
	    	"\nverbose - enable verbose mode of program;"
            "\nhelp - display help. Yeah, cap."
	    	"\nmy_list - list of values "
            "\nmy_boolean - optional flag "
	    	"\nmy_file - file to save the result");
    exit ( EXIT_FAILURE );
}


void display_args()
{
    cout << "global_args.verbose = "    << global_args.verbose << endl;
    cout << "global_args.my_list = "    << global_args.my_list[0] << ", " <<
                                      	   global_args.my_list[1] << ", " <<
                                      	   global_args.my_list[2] << ", " <<
                                           global_args.my_list[3] << "." << endl;
    cout << "global_args.my_boolean = " << global_args.my_boolean << endl;
    cout << "global_args.my_file = "    << global_args.my_file << endl;
}


int main( int argc, char *argv[] )
{
    int opt = 0;
    int longIndex = 0;
    global_args.verbose = 2;
    global_args.my_list[0] = 1;
    global_args.my_list[1] = 2;
    global_args.my_list[2] = 3;
    global_args.my_list[3] = 4;
    global_args.my_boolean = 1;
    global_args.my_file = "text.txt";
    int counter = 0;
    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );

    while( opt != -1 ) {
        switch( opt ) {
            case 'v':
                global_args.verbose = atoi(optarg);
                break;
            case 'l':
				global_args.my_list[0] = optarg[0] - '0';
                global_args.my_list[1] = optarg[2] - '0';
                global_args.my_list[2] = optarg[4] - '0';
                global_args.my_list[3] = optarg[6] - '0';
                break;
            case 'b':
                global_args.my_boolean = atoi(optarg);
                break;
            case 'f':
                global_args.my_file = optarg;
                break;
	    	case 'h':
                display_usage();
                break;
            case '?':
                break;
            default:
                break;
        }
        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }
    if ( global_args.verbose <= 1 or global_args.verbose >= 5 ){
        cout << "Hehe boi, verbose is out of range" << endl;
        return EXIT_FAILURE;
    }

    display_args();

    return EXIT_SUCCESS;
}