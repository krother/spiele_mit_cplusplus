
# First Steps in C++

## 1. Writing a Hello World program

Here is the code:

    // 'Hello World!' program 
    #include <iostream>
    using namespace std;

    int main()
    {
      cout << "Hello World!" << endl;
      return 0;
    }


## 2. How to compile it on Ubuntu:

    
`Ctrl-B` in **Sublime** works as well.

Add to Sublime builder configuration:

{
    "cmd": ["g++ -Wall ${file} -lSDL2_mixer -lSDL2 -o ./${file_base_name} -I${file_path}/lib && ./${file_base_name}"],
    "selector": "source.c++",
    "working_dir": "${file_path}",
    "shell": true,


    "variants": [
        {
            "name": "Run",
            "cmd": ["g++ -Wall ${file} -lSDL2 -o ./${file_base_name} -I${file_path}/lib && open ./${file_base_name}"],
            "working_dir": "${file_path}",
            "shell": true

        }
     ]

}

## 3. Linting in Sublime 3

Install the cpplint package from the shell:

    sudo pip install cpplint

Install the sublime package via **Package Control**:

* `SublimeLinter 3`
* `SublimeLinter-cpplint`

You may have to restart Sublime.

## 4. Adding input

    string name;
    cout << "Please enter your name: ";
    cin >> name;
   
