#include<cstdio>

void sr(unsigned char out[16])
{
		
	unsigned int i,k,s,tmp;
	
	for (i=1; i<4; i++) {
		s=0;
		
		while(s<i) {
			tmp=out[i];
			for(k=0; k<3; k++) {
				out[k*4+i]=out[k*4+i+4];
			}
			out[i+12]=tmp;
			s++;
		}
	}
}

int main(){
    char *ary= {00 , 04 , 08 , 12 ,01 , 05 , 09 , 13 ,02 , 06 , 10 , 14 ,03 , 07 , 11 , 15}
}