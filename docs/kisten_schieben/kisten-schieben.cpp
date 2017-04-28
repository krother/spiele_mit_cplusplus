#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cstddef>
#include <SDL.h>
#include <SDL_image.h>
#include <levels.hpp>
#include <string>



using namespace std;

//Hier werden die Spielfelder festgelegt

Spielfeld_Vektor leveleins = {{
			{{ 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B' }},
			{{ 'A', 'A', 'A', 'X', 'B', 'B', 'A', 'A' }},
			{{ 'B', 'B', 'B', 'K', 'B', 'A', 'B', 'A' }},
			{{ 'B', 'B', 'B', 'F', 'F', 'K', 'X', 'B' }},
			{{ 'A', 'X', 'K', 'F', 'F', 'A', 'B', 'B' }},
			{{ 'A', 'A', 'B', 'B', 'K', 'B', 'B', 'B' }},
			{{ 'B', 'B', 'B', 'A', 'X', 'A', 'B', 'A' }},
			{{ 'A', 'A', 'A', 'B', 'B', 'B', 'A', 'A' }},
	}};
	
Spielfeld_Vektor levelzwei = {{ 
			{{ 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B' }},
		    {{ 'A', 'B', 'F', 'F', 'B', 'A', 'X', 'A' }},
		    {{ 'B', 'F', 'K', 'F', 'A', 'B', 'F', 'A' }},
		    {{ 'B', 'F', 'B', 'F', 'A', 'B', 'F', 'B' }},
		    {{ 'A', 'F', 'A', 'F', 'B', 'A', 'F', 'B' }},
		    {{ 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'B' }},
		    {{ 'B', 'B', 'A', 'A', 'A', 'F', 'F', 'A' }},
		    {{ 'A', 'A', 'A', 'B', 'B', 'B', 'A', 'A' }}
   }}; 
   
Spielfeld_Vektor leveldrei = {{ 
			{{ 'A', 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B' }},
		    {{ 'B', 'A', 'F', 'F', 'F', 'F', 'F', 'B', 'A' }},
		    {{ 'A', 'B', 'K', 'A', 'B', 'B', 'K', 'A', 'A' }},
		    {{ 'A', 'B', 'F', 'B', 'F', 'K', 'F', 'F', 'B' }},
		    {{ 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B' }},
		    {{ 'A', 'F', 'X', 'X', 'A', 'K', 'F', 'B', 'B' }},
		    {{ 'A', 'B', 'X', 'X', 'B', 'F', 'F', 'A', 'A' }},
		    {{ 'B', 'A', 'A', 'A', 'B', 'B', 'B', 'A', 'A' }}
   }}; 
   
   
Spielfeld_Vektor levelvier = {{
			{{ 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B', 'B', 'B', 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B', 'B', 'B' }},
		    {{ 'A', 'X', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B' }},
		    {{ 'B', 'X', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'F', 'A' }}, 
		    {{ 'B', 'F', 'A', 'F', 'F', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'F', 'B' }},
		    {{ 'A', 'F', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'F', 'F', 'B' }},
		    {{ 'A', 'F', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'F', 'A' }},
		    {{ 'B', 'F', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'F', 'A' }},
			{{ 'B', 'F', 'A', 'F', 'F', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B', 'F', 'B' }},
			{{ 'B', 'F', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'F', 'B' }},
		    {{ 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'B', 'X', 'B' }},
			{{ 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'X', 'B' }},
			{{ 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B', 'B', 'B', 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B', 'B', 'B' }}
			
   }}; 
   
   
Spielfeld_Vektor levelfuenf = {{
			{{ 'A', 'B', 'B', 'A', 'B', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'B', 'B', 'A', 'B' }},
			{{ 'A', 'X', 'F', 'F', 'F', 'F', 'F', 'F', 'B', 'F', 'F', 'F', 'F', 'F', 'X', 'B' }},
			{{ 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B',	'F', 'F', 'A', 'A', 'A', 'A', 'B' }},
			{{ 'A', 'B', 'B', 'F', 'B', 'A', 'K', 'K', 'A', 'B', 'F', 'F', 'F', 'F', 'F', 'B' }},
			{{ 'A', 'F', 'F', 'F', 'F', 'F', 'K', 'X', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A' }},
			{{ 'A',	'A', 'A', 'F', 'F', 'A', 'K', 'K', 'B',	'F', 'F', 'F', 'F', 'F', 'F', 'A' }},
			{{ 'B',	'F', 'F', 'F', 'F', 'B', 'F', 'F', 'A', 'F', 'F', 'B', 'F', 'B', 'B', 'B' }},
			{{ 'A',	'X', 'F', 'F', 'F', 'B', 'A', 'F', 'F',	'F', 'F', 'F', 'F', 'F', 'X', 'B' }},
			{{ 'A', 'A', 'B', 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B', 'A', 'B', 'B', 'A', 'A' }}
}};

Spielfeld_Vektor levelsechs = {{
			{{ 'B', 'A', 'A', 'B', 'B', 'A', 'B', 'A' }},
			{{ 'B', 'F', 'F', 'F', 'B', 'F', 'F', 'B' }},
			{{ 'A', 'F', 'B', 'F', 'B', 'K', 'X', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'F', 'K', 'X', 'B' }},
			{{ 'B', 'F', 'A', 'F', 'F', 'K', 'X', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'B', 'F', 'F', 'A' }},
			{{ 'A', 'B', 'B', 'B', 'A', 'F', 'F', 'A' }},
			{{ 'A', 'B', 'B', 'A', 'B', 'A', 'A', 'B' }}
}};

Spielfeld_Vektor levelsieben = {{
			{{ 'A', 'B', 'B', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A', 'B', 'A' }},
			{{ 'A', 'X', 'A', 'A', 'F', 'F', 'B', 'B', 'A', 'B', 'F', 'B', 'A' }},
			{{ 'A', 'F', 'A', 'B', 'F', 'F', 'F', 'F', 'F', 'B', 'K', 'A', 'A' }},
			{{ 'B', 'F', 'B', 'A', 'F', 'F', 'B', 'F', 'F', 'A', 'F', 'F', 'B' }},
			{{ 'B', 'F', 'F', 'F', 'F', 'F', 'B', 'F', 'F', 'F', 'F', 'F', 'B' }},
			{{ 'A', 'F', 'F', 'A', 'A', 'A', 'A', 'F', 'F', 'B', 'F', 'A', 'A' }},
			{{ 'B', 'B', 'A', 'A', 'B', 'B', 'A', 'A', 'A', 'A', 'B', 'B', 'B' }}
}};	

Spielfeld_Vektor levelacht = {{
			{{ 'B', 'A', 'B', 'A', 'A', 'A', 'B', 'B' }},
			{{ 'A', 'X', 'X', 'F', 'F', 'F', 'A', 'A' }},
			{{ 'A', 'X', 'X', 'F', 'F', 'F', 'B', 'B' }},
			{{ 'A', 'B', 'B', 'F', 'K', 'K', 'F', 'B' }},
			{{ 'B', 'F', 'K', 'F', 'F', 'F', 'F', 'A' }},
			{{ 'B', 'F', 'K', 'F', 'F', 'A', 'B', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'B', 'B', 'B', 'A' }},
			{{ 'B', 'A', 'A', 'B', 'B', 'A', 'B', 'B' }}

}};	

Spielfeld_Vektor levelneun = {{
			{{ 'A', 'B', 'B', 'A', 'B', 'B', 'A' }},
			{{ 'A', 'F', 'X', 'F', 'X', 'F', 'B' }},
			{{ 'B', 'F', 'X', 'X', 'X', 'F', 'A' }},
			{{ 'A', 'F', 'X', 'F', 'X', 'F', 'A' }},
			{{ 'B', 'F', 'F', 'F', 'F', 'F', 'B' }},
			{{ 'B', 'B', 'F', 'F', 'F', 'B', 'A' }},
			{{ 'A', 'A', 'A', 'F', 'A', 'A', 'A' }},
			{{ 'A', 'F', 'K', 'F', 'K', 'F', 'B' }},
			{{ 'B', 'F', 'K', 'K', 'K', 'F', 'B' }},
			{{ 'A', 'F', 'K', 'F', 'K', 'F', 'A' }},
			{{ 'B', 'F', 'F', 'F', 'F', 'F', 'A' }},
			{{ 'A', 'B', 'B', 'A', 'A', 'B', 'A' }}
	
}};


Spielfeld_Vektor levelzehn = {{
			{{ 'B', 'A', 'B', 'A', 'A', 'B', 'B', 'B' }},
			{{ 'A', 'X', 'F', 'F', 'F', 'B', 'X', 'A' }},
			{{ 'A', 'F', 'B', 'F', 'F', 'A', 'F', 'B' }},
			{{ 'A', 'F', 'F', 'F', 'K', 'F', 'F', 'A' }},
			{{ 'B', 'B', 'F', 'K', 'K', 'F', 'F', 'B' }},
			{{ 'A', 'F', 'A', 'F', 'F', 'B', 'F', 'A' }},
			{{ 'B', 'X', 'F', 'F', 'F', 'F', 'F', 'A' }},
			{{ 'B', 'A', 'A', 'B', 'B', 'A', 'B', 'B' }}
}};

Spielfeld_Vektor levelelf = {{

			{{ 'B', 'A', 'B', 'A', 'A', 'B', 'B', 'B', 'B', 'B', 'A', 'B', 'B', 'A', 'B', 'A' }},
			{{ 'A', 'B', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'X', 'F', 'B', 'A', 'A' }},
			{{ 'A', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'B', 'B' }},
			{{ 'A', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'B', 'A', 'B', 'A', 'F', 'F', 'X', 'B' }},
			{{ 'B', 'F', 'K', 'F', 'K', 'F', 'F', 'B', 'A', 'F', 'F', 'F', 'F', 'F', 'X', 'A' }},
			{{ 'A', 'F', 'A', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'A' }},
			{{ 'B', 'F', 'X', 'F', 'F', 'F', 'F', 'F', 'F', 'K', 'X', 'F', 'F', 'A', 'B', 'B' }},
			{{ 'B', 'A', 'A', 'B', 'B', 'A', 'B', 'A', 'B', 'B', 'B', 'A', 'B', 'B', 'A', 'B' }}
}};

Spielfeld_Vektor levelzwoelf = {{
			{{ 'A', 'B', 'B', 'A', 'B', 'B', 'A', 'B', 'A', 'A', 'A', 'B', 'A', 'B', 'A', 'B', 'A', 'B', 'A', 'A' }},
			{{ 'A', 'F', 'F', 'B', 'F', 'F', 'F', 'F', 'A', 'F', 'F', 'F', 'A', 'A', 'B', 'F', 'F', 'K', 'X', 'A' }},
			{{ 'B', 'F', 'F', 'B', 'F', 'F', 'F', 'F', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'X', 'X', 'X', 'B' }},
			{{ 'B', 'F', 'K', 'A', 'F', 'F', 'F', 'F', 'F', 'K', 'F', 'B', 'B', 'A', 'B', 'A', 'X', 'X', 'X', 'B' }},
			{{ 'B', 'F', 'F', 'A', 'F', 'F', 'A', 'B', 'A', 'K', 'F', 'F', 'A', 'F', 'F', 'B', 'A', 'B', 'B', 'A' }},
			{{ 'A', 'F', 'K', 'B', 'B', 'F', 'B', 'A', 'B', 'F', 'K', 'F', 'B', 'F', 'K', 'F', 'X', 'A', 'A', 'B' }},
			{{ 'A', 'F', 'F', 'F', 'A', 'F', 'A', 'B', 'B', 'K', 'F', 'F', 'F', 'F', 'F', 'X', 'B', 'B', 'A', 'A' }},
			{{ 'A', 'K', 'F', 'K', 'B', 'F', 'A', 'A', 'B', 'F', 'K', 'F', 'A', 'F', 'X', 'A', 'A', 'B', 'A', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'F', 'F', 'B', 'B', 'B', 'K', 'F', 'F', 'F', 'X', 'B', 'A', 'B', 'A', 'B', 'B' }},
			{{ 'B', 'X', 'K', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'A', 'B', 'A', 'A', 'A', 'B', 'B' }},
			{{ 'B', 'F', 'X', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A', 'B', 'A', 'A', 'B', 'B', 'A', 'A' }},
			{{ 'A', 'B', 'B', 'A', 'B', 'B', 'A', 'B', 'B', 'A', 'A', 'A', 'B', 'A', 'B', 'B', 'A', 'A', 'B', 'A' }}
}};

Spielfeld_Vektor leveldreizehn = {{
			{{ 'B', 'B', 'A', 'A', 'B', 'B', 'A', 'A', 'B' }},
			{{ 'B', 'F', 'F', 'F', 'B', 'A', 'A', 'B', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'B', 'B', 'B', 'X', 'A' }},
			{{ 'A', 'F', 'K', 'F', 'A', 'B', 'A', 'X', 'B' }},
			{{ 'B', 'B', 'B', 'F', 'F', 'F', 'F', 'X', 'B' }},
			{{ 'B', 'B', 'A', 'F', 'F', 'A', 'F', 'F', 'A' }},
			{{ 'A', 'A', 'F', 'K', 'K', 'A', 'F', 'F', 'A' }},
			{{ 'A', 'B', 'F', 'F', 'F', 'B', 'A', 'B', 'B' }},
			{{ 'B', 'A', 'A', 'A', 'B', 'B', 'B', 'A', 'B' }}
}};

Spielfeld_Vektor levelvierzehn = {{
			{{ 'B', 'A', 'A', 'B', 'B', 'A', 'B', 'B', 'B', 'B', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'B' }},
			{{ 'A', 'B', 'A', 'F', 'F', 'F', 'F', 'A', 'F', 'F', 'B', 'F', 'F', 'X', 'B', 'B', 'X', 'B' }},
			{{ 'B', 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B', 'F', 'B', 'F', 'A', 'X', 'F', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'F', 'A', 'F', 'B', 'K', 'F', 'F', 'F', 'K', 'K', 'F', 'F', 'F', 'A' }},
			{{ 'A', 'F', 'F', 'B', 'B', 'A', 'K', 'B', 'X', 'F', 'F', 'F', 'F', 'K', 'F', 'F', 'X', 'A' }},
			{{ 'B', 'F', 'F', 'F', 'A', 'B', 'F', 'F', 'F', 'K', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'A' }},
			{{ 'B', 'F', 'X', 'F', 'B', 'B', 'K', 'A', 'B', 'B', 'F', 'A', 'A', 'F', 'F', 'F', 'F', 'B' }},
			{{ 'A', 'F', 'X', 'F', 'A', 'A', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B', 'K', 'A', 'B' }},
			{{ 'B', 'F', 'F', 'F', 'B', 'A', 'F', 'A', 'F', 'K', 'X', 'X', 'F', 'F', 'B', 'F', 'F', 'A' }},
			{{ 'B', 'B', 'A', 'A', 'B', 'B', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'A', 'B', 'B', 'A', 'B' }}
}};

Spielfeld_Vektor levelfuenfzehn = {{
			{{ 'A', 'B', 'A', 'A', 'A', 'B', 'A', 'B', 'A', 'B', 'B', 'A' }},
			{{ 'B', 'B', 'F', 'F', 'F', 'B', 'F', 'F', 'F', 'F', 'B', 'B' }},
			{{ 'A', 'F', 'F', 'K', 'X', 'X', 'X', 'X', 'K', 'F', 'F', 'B' }},
			{{ 'B', 'F', 'K', 'K', 'B', 'B', 'A', 'A', 'F', 'F', 'F', 'B' }},
			{{ 'A', 'F', 'F', 'F', 'B', 'A', 'A', 'B', 'F', 'F', 'A', 'A' }},
			{{ 'A', 'B', 'B', 'A', 'B', 'B', 'A', 'A', 'A', 'A', 'B', 'A' }}
}};

Spielfeld_Vektor levelsechzehn = {{
			{{ 'A', 'A', 'B', 'B', 'A', 'B', 'B', 'B', 'B', 'A', 'B' }},
			{{ 'B', 'B', 'A', 'B', 'A', 'B', 'B', 'X', 'F', 'F', 'B' }},
			{{ 'B', 'B', 'B', 'B', 'A', 'A', 'A', 'X', 'A', 'F', 'A' }},
			{{ 'A', 'A', 'B', 'A', 'B', 'B', 'B', 'X', 'A', 'F', 'A' }},
			{{ 'A', 'F', 'F', 'F', 'K', 'F', 'K', 'F', 'K', 'F', 'A' }},
			{{ 'B', 'F', 'B', 'F', 'B', 'F', 'A', 'F', 'B', 'A', 'B' }},
			{{ 'B', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'B', 'A', 'B' }},
			{{ 'A', 'B', 'B', 'B', 'A', 'B', 'A', 'A', 'B', 'B', 'A' }}
}};

 //Das letzte "Level" ist eigentlich kein Level, sondern nur ein Abschlussbild  
   Spielfeld_Vektor schluss = {{
			{{ 'A', 'B', 'A', 'A', 'A', 'B', 'B', 'A', 'B', 'B', 'A', 'B', 'A', 'A', 'B', 'A', 'B', 'B', 'B', 'A' }},
			{{ 'A', 'K', 'K', 'K', 'A', 'K', 'K', 'B', 'A', 'K', 'B', 'K', 'K', 'B', 'A', 'B', 'K', 'K', 'K', 'B' }},
			{{ 'B',	'K', 'B', 'B', 'B',	'K', 'B', 'K', 'A',	'K', 'A', 'K', 'B',	'K', 'B', 'B', 'K',	'B', 'B', 'A' }}, 
			{{ 'B',	'K', 'A', 'A', 'B',	'K', 'A', 'K', 'A',	'K', 'B', 'K', 'A', 'B', 'K', 'A', 'K', 'A', 'A', 'A' }},
			{{ 'B',	'K', 'B', 'B', 'A',	'K', 'B', 'K', 'B',	'K', 'A', 'K', 'B',	'A', 'K', 'B', 'K',	'A', 'B', 'B' }},
			{{ 'A',	'K', 'K', 'B', 'A',	'K', 'A', 'K', 'A',	'K', 'X', 'K', 'A',	'B', 'K', 'A', 'K',	'K', 'B', 'A' }},
			{{ 'B',	'K', 'B', 'A', 'A',	'K', 'B', 'K', 'B',	'K', 'B', 'K', 'A',	'B', 'K', 'A', 'K',	'A', 'A', 'B' }},
			{{ 'B',	'K', 'A', 'B', 'B',	'K', 'A', 'K', 'A',	'K', 'A', 'K', 'A',	'A', 'K', 'A', 'K',	'B', 'A', 'A' }},
			{{ 'B',	'K', 'B', 'A', 'A',	'K', 'A', 'K', 'B',	'K', 'B', 'K', 'B',	'B', 'K', 'B', 'K',	'A', 'A', 'B' }},
			{{ 'A',	'K', 'A', 'B', 'B',	'K', 'B', 'K', 'B',	'K', 'A', 'K', 'B',	'K', 'B', 'A', 'K',	'B', 'B', 'A' }},
			{{ 'A',	'K', 'K', 'K', 'B',	'K', 'A', 'K', 'K',	'B', 'A', 'K', 'K',	'B', 'A', 'A', 'K',	'K', 'K', 'B' }},
			{{ 'A',	'B', 'A', 'B', 'B',	'A', 'A', 'A', 'B',	'A', 'A', 'B', 'B',	'A', 'A', 'B', 'B',	'A', 'A', 'A' }}
   }};
   



   
   
int main(int argc, char* args[])
{
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Init(SDL_INIT_VIDEO);

		SDL_Window *win = SDL_CreateWindow("Kisten schieben", 400, 200, 860, 516, SDL_WINDOW_SHOWN); //posx und y auf bildschirm; länge, höhe des fensters
		SDL_Surface *surf = SDL_GetWindowSurface(win);


		SDL_Init(IMG_INIT_PNG);
		
		SDL_Surface *icon = IMG_Load("kiste.ico");
		SDL_Surface *hintergrund = IMG_Load("hintergrund.png");
		SDL_Surface *felder = IMG_Load("felder.png");
		SDL_Surface *schilder = IMG_Load("schilder.png");
		SDL_Surface *schrift = IMG_Load("buchstaben.png");
		
		//Icon, das in der Taskleiste und im Fenster oben links angezeigt wird
		SDL_SetWindowIcon(win,icon);

       
		SDL_Rect source;
		SDL_Rect dest;

		int taste;
		SDL_Event e;
		
		int schritte_gesamt = 0;

		bool programm = true;

		//main while schleife um alles anfang
		while (programm) {
		bool ende = false;
		
		
		
			//Menü
			menue_auswaehlen(felder, surf, win);
		
			//Switch-Case-Befehl, damit das nächste Level nur dann geladen wird, wenn das vorherige geschafft wurde
		
			//Level 1
					spielfeld_zeichnen(leveleins, mitte_x, mitte_y, felder, hintergrund, surf);
					schild_zeichnen(START_LEVEL, "Level 1", schilder, schrift, surf, win);
			switch	(Level_spielen(leveleins, 3, 4, mitte_x, mitte_y, "Level 1", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 2
			case true: spielfeld_zeichnen(levelzwei, mitte_x, mitte_y, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 2", schilder, schrift, surf, win);
			switch	   (Level_spielen(levelzwei, 6, 3, mitte_x, mitte_y, "Level 2", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
						
				
			//Level 3
			case true: spielfeld_zeichnen(leveldrei, mitte_x, mitte_y, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 3", schilder, schrift, surf, win);
			switch   (Level_spielen(leveldrei, 2, 1, mitte_x, mitte_y, "Level 3", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 4
			case true: spielfeld_zeichnen(levelvier,0,0, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 4", schilder, schrift, surf, win);
			switch    (Level_spielen(levelvier, 9, 5, 0, 0, "Level 4", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 5
			case true: spielfeld_zeichnen(levelfuenf,2*43, 70, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 5", schilder, schrift, surf, win);
			switch    (Level_spielen(levelfuenf, 11, 4, 2*43, 70, "Level 5", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 6
			case true: spielfeld_zeichnen(levelsechs,mitte_x, mitte_y, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 6", schilder, schrift, surf, win);
			switch    (Level_spielen(levelsechs, 5, 6, mitte_x, mitte_y, "Level 6", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 7
			case true: spielfeld_zeichnen(levelsieben, 4*43, 2*43, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 7", schilder, schrift, surf, win);
			switch    (Level_spielen(levelsieben, 10, 1, 4*43, 2*43, "Level 7", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 8
			case true: spielfeld_zeichnen(levelacht, mitte_x, mitte_y, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 8", schilder, schrift, surf, win);
			switch    (Level_spielen(levelacht, 1, 6, mitte_x, mitte_y, "Level 8", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 9
			case true: spielfeld_zeichnen(levelneun,6*43, 0, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 9", schilder, schrift, surf, win);
			switch    (Level_spielen(levelneun, 1, 10, 6*43, 0, "Level 9", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 10
			case true: spielfeld_zeichnen(levelzehn,5*43, 2*43, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 10", schilder, schrift, surf, win);
			switch    (Level_spielen(levelzehn, 6, 6, 5*43, 2*43, "Level 10", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 11
			case true: spielfeld_zeichnen(levelelf, 2*43, 2*43, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 11", schilder, schrift, surf, win);
			switch    (Level_spielen(levelelf, 1, 6, 2*43, 2*43, "Level 11", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 12
			case true: spielfeld_zeichnen(levelzwoelf,0, 0, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 12", schilder, schrift, surf, win);
			switch    (Level_spielen(levelzwoelf, 11, 4, 0, 0, "Level 12", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 13
			case true: spielfeld_zeichnen(leveldreizehn, mitte_x, mitte_y, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 13", schilder, schrift, surf, win);
			switch    (Level_spielen(leveldreizehn, 2, 7, mitte_x, mitte_y, "Level 13", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 14
			case true: spielfeld_zeichnen(levelvierzehn, 43, 43, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 14", schilder, schrift, surf, win);
			switch    (Level_spielen(levelvierzehn, 16, 8, 43, 43, "Level 14", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 15
			case true: spielfeld_zeichnen(levelfuenfzehn, 4*43, 3*43, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 15", schilder, schrift, surf, win);
			switch    (Level_spielen(levelfuenfzehn, 10, 3, 4*43, 3*43, "Level 15", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
			
			//Level 16
			case true: spielfeld_zeichnen(levelsechzehn, 4*43, 2*43, felder, hintergrund, surf);
					   schild_zeichnen(START_LEVEL, "Level 16", schilder, schrift, surf, win);
			switch    (Level_spielen(levelsechzehn, 1, 6, 4*43, 2*43, "Level 16", hintergrund, felder, schilder, schrift, surf, win)){
			case false: break;
	
			
			//Ende
			case true: spielfeld_zeichnen(schluss,0,0, felder, hintergrund, surf);
					   schild_zeichnen(DURCHGESPIELT, " ", schilder, schrift, surf, win);
					   Level_spielen(schluss, 10, 5, 0, 0, "Ende", hintergrund, felder, schilder, schrift, surf, win);
			} 
			} 
			} 
			} 
			} 
			} 
			} 
			} 
			} 
			}  
			} 
			} 
			} 
			} 
			} 
			} 
			
	
	}

	return 0;

} //Ende Main