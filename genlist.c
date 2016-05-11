#include <stdio.h>
#include <string.h>

void delspace(char * p) { //actually, this function also delete the \n ,^^
	int i,j=0;
	for ( i = 0; p[i]!='\0'; i ++ ) {
		if(p[i] != ' ' && p[i] != '\n')
			p[j++] = p[i];
	}
	p[j] = '\0';
}

int main() {
	FILE * fa, * fb;
	char strtmp[100];
	int len = 0;

	fa = fopen("list.txt", "r");
	fb = fopen("list.js", "w");
	
	fprintf(fb, "var ary = new Array(\n");

	while(fgets(strtmp, 100, fa) != NULL) {
		delspace(strtmp);
		len = strlen(strtmp);

		if (len !=0){
			fprintf(fb, "\"%s\",\n", strtmp);
		}

	}
	
	fprintf(fb, "\"todel\"\n");
	fprintf(fb, ")\n");
	fprintf(fb, "ary.splice(ary.length-1, 1)\n");


	fclose(fa);
	fclose(fb);

	return 0;
}






