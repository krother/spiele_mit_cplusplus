//
// Textures in SDL
//
// Mehr Infos im Tutorial von LazyFoo unter:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php
//
#include <math.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>


class Schiff {
  private:
    int vecx = 1;
    int vecy = 0;
    double xpos;
    double ypos;
    int t;
  public:
    int x;
    int y;
    int winkel;
    int groesse;
    SDL_Texture* texture;  // wegen Destroy

    Schiff(int, int, int, SDL_Renderer*);
    void zeichnen(SDL_Renderer*);
    void bewegen();
};

Schiff::Schiff(int startx, int starty, int startgr, SDL_Renderer *renderer) {
    xpos = startx;
    ypos = starty;
    groesse = startgr;
    winkel = 90;
    t = 0;

    // ein Texture-Objekt erstellen
    SDL_Surface *bild = IMG_Load("ship.png");
    texture = SDL_CreateTextureFromSurface(renderer, bild);
    SDL_FreeSurface( bild );
}

void Schiff::zeichnen(SDL_Renderer *renderer) {
    // Transparenz festlegen
    Uint8 alpha = abs(360 - t) * 255 / 360; 
    SDL_SetTextureAlphaMod( texture, alpha );

    // Texture zeichnen (wie SDL_Blit)
    SDL_Rect dest = {x: x, y: y, w:groesse, h:groesse};
    SDL_RenderCopyEx( renderer, texture, NULL, &dest, winkel+90, NULL, SDL_FLIP_NONE );
    // SDL_FLIP_HORIZONTAL, SDL_FLIP_VERTICAL - bezogen auf Ursprungsbild
    // SDL_RenderCopy( gRenderer, schiff, NULL, &dest ); // Ohne Winkel - Schneller!
}

void Schiff::bewegen() {
    // Schiffskoordinaten verändern
    t += 1;
    if (t == 720) { t = 0; }
    
    if (t < 180 || t > 540) {
        winkel++;
    }
    else {
        winkel--;
    }
    double rad = winkel / 180.0 * (double) M_PI;
    double dx = cos(rad) * 2.5;
    double dy = sin(rad) * 2.5;
    

    xpos += dx;
    ypos += dy;
    x = xpos;  // automatisch abgerundet
    y = ypos;  
    groesse = 200 - abs(300 - x) / 2;
}


int main(int, char**) {

	    SDL_Init(SDL_INIT_VIDEO);
	    IMG_Init( IMG_INIT_PNG );

	    SDL_Window *win = SDL_CreateWindow("Textures", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

        // Renderer ersetzt WindowSurface
        SDL_Renderer* gRenderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED );

        // Hintergrundfarbe setzen (00 00 00 00 = schwarz)
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );

        Schiff schiff(600, 200, 100, gRenderer);

        // Hauptschleife
        bool quit = false;

        while( !quit ) {

            // Events leeren
        	SDL_Event e;
            while( SDL_PollEvent( &e ) != 0 ) { 
                if( e.type == SDL_QUIT ) { quit = true; }
            }
                        
            SDL_RenderClear( gRenderer );  // Bildschirm löschen
            schiff.bewegen();
            schiff.zeichnen(gRenderer);

            SDL_RenderPresent( gRenderer );  // äquivalent zu SDL_UpdateWindowSurface
	        SDL_Delay(20);  // 50 Hz
        }

   		// Am Ende aufräumen
   		SDL_DestroyTexture( schiff.texture ); // TODO: in den Destruktor
   		SDL_DestroyRenderer( gRenderer );
   		SDL_DestroyWindow( win );

   		IMG_Quit();
   		SDL_Quit();

  return 0;
}