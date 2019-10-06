#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
/*cp org dst */
	if(argc!=3){
		printf("Usage :%s <org file> <dst file> \n", argv[0]);
		exit(0);
	}

	int fd_org, fd_dst;
	char *buf;	
	if((fd_org=open(argv[1],O_RDONLY))!=-1){
		if((fd_dst = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC))!=-1){
			int cnt;
			buf = malloc(4096);
			do{
				cnt = 0;
				cnt = read(fd_org, buf,4096);
				if(cnt = write(fd_dst, buf, cnt)){
					continue;
				}
			}while(cnt!=0);
		}
	
		else {
			printf("Failed to open %s \n", argv[2]);
			close(fd_org);
			return -1;
		}


	close(fd_dst);
	close(fd_org);
	free(buf);

	}
	else {
		printf("Failed to open %s \n", argv[1]);
		return -1;
	}
	return 0;
}



