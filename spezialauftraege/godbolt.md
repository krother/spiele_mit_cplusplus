
# Was passiert beim Compilieren?

### 1. Godbolt

Gehe auf die Seite [https://godbolt.org/](https://godbolt.org/)

### 2. Code

Füge folgendes Programm ein:

    int count() {
        int a = 0;
        for (int i=0; i<5; i++) {
            a += i;
        }
        return a;
    }


### 3. Optimiere den Compiler

Füge die Compilieroption `-Ofast` hinzu.
