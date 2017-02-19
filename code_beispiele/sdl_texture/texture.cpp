//
// Textures in SDL
//
// Mehr Infos im Tutorial von LazyFoo unter:
// http://lazyfoo.net/tutorials/SDL/07_texture_loading_and_rendering/index.php
//
#include <SDL.h>
#include <SDL_image.h>


int main(int, char**) {

	    SDL_Init(SDL_INIT_VIDEO);
	    IMG_Init( IMG_INIT_PNG );

	    SDL_Window *win = SDL_CreateWindow("Textausgabe", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

        // Renderer ersetzt WindowSurface
        SDL_Renderer* gRenderer = SDL_CreateRenderer( win, -1, SDL_RENDERER_ACCELERATED );

        // Hintergrundfarbe setzen (00 00 00 00 = schwarz)
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0x00 );

        // ein Texture-Objekt erstellen
	    SDL_Surface *bild = IMG_Load("torte.png");
        SDL_Texture* torte  = SDL_CreateTextureFromSurface( gRenderer, bild);
		SDL_FreeSurface( bild );

        // Hauptschleife
        bool quit = false;
        int tortex = 0;
        int tortey = 0;
        int tortengroesse = 0;
        int vecx = 1;
        int vecy = 0;

        while( !quit ) {
        	SDL_Event e;
            while( SDL_PollEvent( &e ) != 0 ) { 
                if( e.type == SDL_QUIT ) { quit = true; }
            }
            
            // Bildschirm löschen
            SDL_RenderClear( gRenderer );

            // Texture zeichnen
            // (geht mit 0, 1 oder 2 SDL_Rects)
            SDL_Rect dest = {x: tortex, y: tortey, w:tortengroesse, h:tortengroesse};
            SDL_RenderCopy( gRenderer, torte, NULL, &dest );

            // Bildschirm rendern - ersetzt SDL_UpdateWindowSurface
            SDL_RenderPresent( gRenderer ); 

            //
            // Tortenkoordinaten verändern
            //
            tortex += vecx;
            tortey += vecy;
            tortengroesse = tortex + tortey;
            if (tortex >= 200) {
                vecx = 0; vecy = 1;
            }
            if (tortey >= 200) {
                vecx = -1; vecy = 0;
            }
            if (tortex == 0) {
                vecx = 0;
                vecy = -1;
            }
            if (tortey == 0 && tortex == 0) {
                vecx = 1;
                vecy = 0;
            }
	        SDL_Delay(10);
        }

        //
   		// Am Ende aufräumen
   		//
   		SDL_DestroyTexture( torte );
   		torte = NULL;

   		SDL_DestroyRenderer( gRenderer );
   		SDL_DestroyWindow( win );
   		win = NULL;
   		gRenderer = NULL;

   		IMG_Quit();
   		SDL_Quit();

  return 0;
}