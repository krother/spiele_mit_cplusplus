#include <SDL.h>
#include <iostream>
using namespace std;

int main(int, char **) {

	SDL_Rect a = {x: 10, y:10, w:10, h:10};
	SDL_Rect b = {x: 20, y:20, w:10, h:10};
	SDL_Rect c = {x: 15, y:15, w:10, h:10};

    if (SDL_HasIntersection(&a, &b)) {
    	cout << "BOOM A + B" << endl;
    }
    if (SDL_HasIntersection(&a, &c)) {
    	cout << "BOOM A + C" << endl;
    }
    if (SDL_HasIntersection(&b, &c)) {
    	cout << "BOOM B + C" << endl;
    }

}