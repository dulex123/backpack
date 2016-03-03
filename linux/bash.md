# Bash cheatsheet

## Variables

```sh
$ variable1=value                       # Spaces around = are not allowed
$ variable2="value with spaces"         # Quotation marks are needed for space-separated values
$ variable3=String\ with\ escaped\ spaces\ is\ also\ valid
```

## Accessing variables

```sh
$ echo $variable1                       # Prints the content of variable1
$ echo "Something: ${variable1}ASDF"    # Accessing variable within {} avoids ambiguity
$ variable1=$(date)                     # Output of date command is saved inside variable1
$ variable2=`date`                      # Same as above
```

## Script arguments

Arguments within script are accessed with:
* `$0` - path
* `$#` - argument number
* `$@` - list of arguments (with spaces)

```sh
$ ./script.sh arg1 arg2 arg3 arg4       # Passing 4 arguments to script.sh
```

## Arrays

Arrays can take multiple values under the same index. Index starts from 0.

```sh
$ array1=(1 2 blah "I love bash!")      # Array initialization
$ $(#array1[@])                         # Num of initialized elements
$ array1[4]="the fifth element"         # We can set any index
$ echo ${array1[5]}                     # We can access any index
```

## String manipulation

```sh
$ echo ${#stringVar}                    # String length
$ echo ${stringVar:$pos:$len}           # Extracts part of stringVar from pos to pos+len (or the ond of the string if len not specified)
$ ${stringVar[@]/ps1/ps2}               # Replaces the first appearance of ps1 within stringVar with ps2
$ ${stringvar[@]//ps1/ps2}              # Replaces every appearance of ps1 with ps2
$ ${stringVar[@]/#ps1/ps2}              # Replaces if stringVar begins with ps1
$ ${string[@]/%ps1/ps2}                 # Replaces if ps1 at the end of string
```

## Conditions

```sh
if [condition]; then
    echo "Yes"
elif [condition]; then
    echo "Maybe"
else
    echo "No"
fi
```

## Boolean

Logical operators: 
* `!` (not) 
* `&&` (and) 
* `||` (or)

Numerical comparisons: 
* `-lt` (<)
* `-gt` (>)
* `-le` (<=)
* `-ge` (>=)
* `-eq` (==)
* `-ne` (!=)

String comparisons: 
* `=`,`==` (equal) 
* `!=` (not equal) 
* `-z` (empty string, unary operator)


```sh
if[ stringVariable ]                    # Empty string, only spaces, or undefined variable return false
```