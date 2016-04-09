#include<stdio.h>
#include"BMP1.0.3.h"
#include<math.h>

const char* HEAD = "<!DOCTYPE html><html lang=\"ja\"><head><meta charset=\"utf-8\"><title>HTML_ALICE</title></head><body>\n";
const char* PIXEL = "<div style=\"position:absolute; top:%dpx; left:%dpx; width:1px; height:1px; background-color:#%.2X%.2X%.2X;\"></div>\n";
const char* FOOT = "</body></html>\n";


int main(void){
	RGB* rgb;
	int W,H;

	int PW = 480;
	int PH = 270;
	rgb = (RGB*)malloc(PW*PH*3);
	BmpIn("Alice_480.bmp",&W,&H,rgb);
	
	unsigned int or=0;
	unsigned int og=0;
	unsigned int ob=0;
	
	FILE *F = fopen("HTML_ALICE_480.html","w");
	
	fprintf(F,HEAD);
	
	
	for(int x=0;x<=PW;x++){
		for(int y=0;y<=PH;y++){
			RGB grgb = getColor(rgb,PW,x,y);
			or = grgb.R;
			og = grgb.G;
			ob = grgb.B;
			
			printf("%d %d %d\n",or,og,ob);
			fprintf(F,PIXEL,x,y,or,og,ob);
		}
	}
	
	fprintf(F,FOOT);
	free(rgb);
	fclose(F);
	return 0;
}

