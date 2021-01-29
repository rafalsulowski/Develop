#include <stdio.h>
#include <stdlib.h>

double absolut( double x )
{
	if( x < 0 )
		return -x;
	return x;
}



int main(int argc, char* argv[])
{
	double guess = 1;
	double n = argc > 1 ? atof( argv[1] ) : -1;
	double eps = argc > 2 ? atof( argv[2] ) : 0.001;

	if( n <= 0 )
	{
		printf( "Zly argument wywoalnia, wprowadz jeszcze raz:\n" );
		scanf( "%lf", &n );

		if( n <= 0 )
		{
			printf("Zly arg wywolania, koniec programu");
			return 1;
		}
	}
	
	//algorytm liczacy pierwaistek
	//Metoda Newtona-Raphsona
	while( absolut( guess * guess  - n ) >= eps )
		guess = ( n / guess + guess ) / 2.0;

	
	printf( "Watosc przyblizona pierwiastka wynosi: %lf\n", guess ); 

	return 0;
}
