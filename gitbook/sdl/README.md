
# Beispiele zu SDL

### Box mit Nachricht anzeigen

	SDL_ShowSimpleMessageBox(0, "Hello", "Hello World", win);
    
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
             "Fenstertitel", "Hello World.", NULL);

### Kollisionserkennung

    SDL_Rect a = {x: 10, y:10, w:10, h:10};
    SDL_Rect b = {x: 20, y:20, w:10, h:10};

    if (SDL_HasIntersection(&a, &b)) {
        cout << "BOOM" << endl;
    }
