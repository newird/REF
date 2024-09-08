#include <stdio.h>

int sum( int n );

int main()
{
    int n;
    scanf("%d", &n);
    printf ("%d\n", n, sum(n));

    return 0;
}

int sum( int n ){
	
	if(n > 1){
		return n + sum(n - 1);
	} else if(n <= 0){   
		return -1;
	}else {        
	 	return 1;
	}
}