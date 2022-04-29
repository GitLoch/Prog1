#include <stdio.h>
#include <string.h>

void function (char* p, int x){
	printf("p is \"%s\" and x is %d\n", p, x);
}



int main(){
	printf("Hello, world!\n");
	
	char a[10] = "Hello";
	char b[10] = "World!";
	
	strcat(a, " ");
	strcat(a, b);
	printf("%s\n", a);  
	
	function("foo", 7);
	function("c nyelv", 10);
	function("szeretem nagyon", 69);
	return 0;
}
