# Lab №5, AK-2 Fryzyuk Mykola IO-71

List of valid keys:
+ -l, --my_list, list of values;
+ -b, --my_boolean, optional flag;
+ -f, --my_file, save;
+ -h, --help, getting help;
+ -v, --verbose, enable verbose mode;

### Using the project:

`cd ~/Lab5_tmp`

`cmake ../Lab5`

### Commands usage:

`./main`

`./main --verbose=4`

`./main -v 1`

`./main --my_boolean=0`

`./main -b=1`

`./main -h`

`./main --help`

`./main --my_file="some_text"`

`./main -f "some_text"`

`./main --my_list=3,4,5,6`

`./main -l 1,2,3,4`

### If key is wrong:

`./main -u --hello`
`./main: invalid option -- 'u'`
`./main: unrecognized option '--hello'`
