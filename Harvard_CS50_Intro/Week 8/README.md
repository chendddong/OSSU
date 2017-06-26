# Notes in Week 8

###  [notes](http://docs.cs50.net/2016/fall/notes/8/week8.html), [slides](http://cdn.cs50.net/2016/fall/lectures/8/week8.pdf)

In this week, we have port some codes of the previous weeks form C to python

## About Python Coding style [Link](https://www.python.org/dev/peps/pep-0008/#fn-hi)

##### hanging indent
```python

# Aligned with opening delimiter.
foo = long_function_name(var_one, var_two,
                         var_three, var_four)

# More indentation included to distinguish this from the rest.
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)

# Hanging indents should add a level.
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)

```

##### Multiple if statements

```python
# No extra indentation.
if (this_is_one_thing and
    that_is_another_thing):
    do_something()

# Add a comment, which will provide some distinction in editors
# supporting syntax highlighting.
if (this_is_one_thing and
    that_is_another_thing):
    # Since both conditions are true, we can frobnicate.
    do_something()

# Add some extra indentation on the conditional continuation line.
if (this_is_one_thing
        and that_is_another_thing):
    do_something()
```

##### The closing brace/bracket/parenthesis 

```python
my_list = [
    1, 2, 3,
    4, 5, 6,
    ]

result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
    )

#   or it may be lined up under the first character of the line that starts the multi-line construct, as in:

my_list = [
    1, 2, 3,
    4, 5, 6,
]
result = some_function_that_takes_arguments(
    'a', 'b', 'c',
    'd', 'e', 'f',
)
```

##### Backslashes for multiple WITH statements

```python
with open('/path/to/some/file/you/want/to/read') as file_1, \
     open('/path/to/some/file/being/written', 'w') as file_2:
    file_2.write(file_1.read())
```

##### A line break before the operands

```python
# Yes: easy to match operators with operands (readability)
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
```

##### A tale of blank lines

1.  Surround top-level function and class definitions with two blank lines.

2.  Method definitions inside a class are surrounded by a single blank line.

3.  Use blank lines in functions, sparingly, to indicate logical sections.

4.  Extra blank lines may be used (sparingly) to separate groups of related functions. Blank lines may be omitted between a bunch of related one-liners (e.g. a set of dummy implementations).

##### Source File Encoding

* Files using ASCII (in Python 2) or UTF-8 (in Python 3) should not have an
encoding declaration.

* Using \x , \u , \U , or \N escapes is the preferred way to include non-ASCII
data in string literals.

##### Imports

```python
# Imports should usually be on separate lines
import os
import sys

# It's okay to say this though:
from subprocess import Popen, PIPE
```

* Imports should be grouped in the following order:

    1.  standard library imports
    2.  related third party imports
    3.  local application/library specific imports

* Wildcard imports ( from \<module\> import * ) should be avoided

##### String Quotes

* When a string contains single or double quote characters, however, use the
other one to avoid backslashes in the string.

##### Space
* Always surround these binary operators with a single space on either side: assignment ( = ), augmented assignment ( += , -= etc.), comparisons ( == , < , > , != , <> , <= , >= , in , not in , is , is not ), Booleans ( and , or , not ).

* If operators with different priorities are used, consider adding whitespace
around the operators with the lowest priority(ies). Use your own judgment; however, never use more than one space, and always have the same amount of whitespace on both sides of a binary operator.

```python
i = i + 1
submitted += 1
x = x*2 - 1
hypot2 = x*x + y*y
c = (a+b) * (a-b)
```

* Don't use spaces around the = sign when used to indicate a keyword argument or a default parameter value.

```python
def complex(real, imag=0.0):
    return magic(r=real, i=imag)
```

* Function annotations should use the normal rules
```python
def munge(input: AnyStr): ...
def munge() -> AnyStr: ...
```

* When combining an argument annotation with a default value, use spaces around the = sign (but only for those arguments that have both an annotation and a default).

```python
def munge(sep: AnyStr = None): ...
def munge(input: AnyStr, sep: AnyStr = None, limit=1000): ...
```

* Compound statements (multiple statements on the same line) are generally discouraged.

```python
if foo == 'blah':
    do_blah_thing()
do_one()
do_two()
do_three()
```

### Trailing commas

Trailing commas are sometimes optional. Example:

```python

# Situation 1
FILES = ('Setup.cfg',)

# Situation 2

FILES = [
    'Setup.cfg',
    'tox.ini',
    ]

```

### Comments

* Comments should be complete sentences. If a comment is a phrase or sentence, its first word should be capitalized, unless it is an identifier that begins with a lower case letter (never alter the case of identifiers!).

* If a comment is short, the period at the end can be omitted. Block comments generally consist of one or more paragraphs built out of complete sentences, and each sentence should end in a period.

##### In-line comments

* Use the In-line comments sparingly
* It should be separated by at least two spaces


### Documentation Strings

```python
"""Return a foobang

Optional plotz says to frobnicate the bizbaz first.
"""

# For one liner docstrings, please keep the closing """ on the same line.
""" Optional docstrings """
```

### Naming Style

* b (single lowercase letter)

* B (single uppercase letter)

* lowercase

* lower_case_with_underscores

* UPPERCASE

* UPPER_CASE_WITH_UNDERSCORES

* CapitalizedWords (or CapWords, or CamelCase -- so named because of the bumpy look of its letters [4] ). This is also sometimes known as StudlyCaps.

Note: When using abbreviations in CapWords, capitalize all the letters of the abbreviation. Thus HTTPServerError is better than HttpServerError.

* mixedCase (differs from CapitalizedWords by initial lowercase character!)

* Capitalized_Words_With_Underscores (ugly!)

##### Packages and Module Names
* Modules should have short, all-lowercase names.
* Python packages should also have short, all-lowercase names, although the use of underscores is discouraged.

##### Class Names

* CapWords convention

##### Function Names

* Function names should be lowercase, with words separated by underscores as necessary to improve readability

* mixedCase is allowed only in contexts where that's already the prevailing style (e.g. threading.py), to retain backwards compatibility.


### Some Programming tips

* Don't compare boolean values to True or False using == 
```python
if greeting:
    print("Hello back")
```

* For sequences, (strings, lists, tuples), use the fact that empty sequences are false.
```python
# Yes: 
     if not seq:
     if seq:
```

* Object type comparisons should always use isinstance() instead of comparing
types directly.
```python
if isinstance(obj, int):
```

* Use ''.startswith() and ''.endswith() instead of string slicing to check for prefixes or suffixes.

startswith() and endswith() are cleaner and less error prone. For example:

```python
# Yes: 
if foo.startswith('bar'):
# No:  
if foo[:3] == 'bar':
```

* Be consistent in return statements. Either all return statements in a function should return an expression, or none of them should. If any return statement returns an expression, any return statements where no value is returned should explicitly state this as return None , and an explicit return statement should be present at the end of the function (if reachable).

```python

def foo(x):
    if x >= 0:
        return math.sqrt(x)
    else:
        return None

def bar(x):
    if x < 0:
        return None
    return math.sqrt(x)

```

* Always use a def statement instead of an assignment statement that binds a lambda expression directly to an identifier.
```python
# Yes:

def f(x): return 2*x

# No:

f = lambda x: 2*x
```