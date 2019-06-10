#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h> //user ID of file
#include <grp.h> //group ID of file
#include <time.h>
#include <stdbool.h>

#define RESET       "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */


/*
* @Andres Gutierrez Arcia
* @ 402310453
*/

int main (int argc, char *argv[]) {
    char date[36];
    struct stat fileStat;
    struct dirent **pDirent;
    struct passwd *pwd;
    struct group *grp;

    int i =0;
    int n;
    bool conL = false;
    int k = 1; //bandera

    if (argc < 2) {
        argv[k] = ".";
    }
	
    conL = strcmp(argv[1],"-l") == 0;// viene con el parametro -l

    if(argc == 2){ //por si viene el -l
	k = 2;
	argv[k] = ".";
     }
	
    n = scandir(argv[k], &pDirent, 0, alphasort);
    if (n < 0) {
       perror("scandir");
       return 1;
    }

    while (i < n) {

        if(strcmp(pDirent[i]->d_name, ".") == 0
        ||strcmp(pDirent[i]->d_name, "..") == 0) {
            i++;
            continue;
        }          

        stat(pDirent[i]->d_name, &fileStat); //Obtiene información del archivo
		if(conL){
			printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
			printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
			printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
			printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
			printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
			printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
			printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
			printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
			printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
			printf(" %jd ", fileStat.st_nlink);
			printf(" %s ",getpwuid(fileStat.st_uid)->pw_name);
			printf(" %s ",getgrgid(fileStat.st_gid)->gr_name);
			printf(" %5ld ",fileStat.st_size);
			//size_t strftime(char *str, size_t maxsize, const char *format, const struct tm *timeptr)
			strftime(date,sizeof(date)," %b %d %Y %H:%M", localtime(&fileStat.st_mtime));
			printf(" %s ", date);
			//printf("Modify:   %s", (char *)asctime(localtime(&fileStat.st_mtime)));
			
			
			
			//colores
			if(S_ISDIR(fileStat.st_mode)){
				printf (BOLDBLUE "  %s\t\n" RESET, pDirent[i]->d_name);
			}else if(fileStat.st_mode & S_IXUSR){
				printf (BOLDGREEN "  %s\t\n" RESET, pDirent[i]->d_name);
			}else{
				printf ("  %s\t\n", pDirent[i]->d_name);
			}
		}else{ // ls solo, sin el parametro -l
			argv[2]=".";
		if(S_ISDIR(fileStat.st_mode)){
			printf (BOLDBLUE "  %s\t" RESET, pDirent[i]->d_name);
		}else if(fileStat.st_mode & S_IXUSR){
			printf (BOLDGREEN "  %s\t" RESET, pDirent[i]->d_name);
		}else{
			printf ("  %s\t", pDirent[i]->d_name);
		}
		
		}	
        free(pDirent[n]);
        i++;
    }
    printf("\n");
    free(pDirent);
    return 0;
}
