#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>

void merger(char ** finalcat,char name[150]){
  freopen(name,"w",stdout);
  printf("Merging !");
  execvp("/bin/cat",finalcat);
}

struct v {
   int i; // row
   int j; // column
};

int main(int argc, char *argv[]){

	if(argc == 5)
	{
		//printf("%s \n %s \n %s \n %s\n %s",argv[0],argv[1],argv[2],argv[3],argv[4]);

		char url[150];
		strcpy(url,argv[1]);

		int size ;
		size = atoi(argv[2]); 
		int processNummber;
		processNummber = atoi(argv[3]);
		char output[150];

		strcpy(output,argv[4]);
		 FILE *fp;
		 int count =0 ;
		char file[150];
	    char file_copy[150];
	    char file_copy2[150];
	    char file_copy3[150];
	    char file_copy4[150];
        char file_copy5[150];
		   struct stat st = {0};
		 DIR *d,*e;
		 char pwd[150];
         //strcpy(pwd,"/home/abhijeet/cloud/code/sem5/cs310/lab4/eva");
         //char cwd[1024];
        getcwd(pwd, sizeof(pwd));
        printf("%s",pwd);
        struct dirent *dir;
         strcpy(file,pwd);
         strcat(file,"/");
         strcpy(file_copy2,file);
         strcat(file_copy2,"Output");
         strcpy(file_copy4,file_copy2);
         char buffer[150];
		 char  **finalcat = (char**)malloc(sizeof(char*)*(processNummber+1));;
         for (int km = 0; km < processNummber+1; km++) {
             finalcat[km] = (char *)malloc(150*sizeof(char));
          }
         char  **finalcurl = (char**)malloc(sizeof(char*)*(6));;
         for (int km = 0; km < 6; km++) {
             finalcurl[km] = (char *)malloc(150*sizeof(char));
          }

         //printf("\n\nprocessNummber :: %d",processNummber);
       
         d = opendir(pwd);

              if(d==NULL){
                printf ("Cannot open directory '%s'\n",pwd);
                 return 1;
              }
              if (stat(file_copy2, &st) == -1)
              {
                mkdir(file_copy2, 0700);
                printf("\nMaking Output directory");
              }
              int cnt = 0;
              strcpy(finalcat[cnt],"cat");
		      cnt++;

		      int cnt1 = 0;
              strcpy(finalcurl[cnt1],"curl");
		      cnt1++;
		      strcpy(finalcurl[cnt1],"--range");
		      cnt1=cnt1+2;
		      strcpy(finalcurl[cnt1],"-o");
		      cnt1=cnt1+2;
		      strcpy(finalcurl[cnt1],url);
		      //sprintf(buffer, "%d", 0-);
 			  strcpy(finalcurl[2],"0");
 			 pthread_t *tid = (pthread_t *)malloc(processNummber*sizeof(pthread_t));
 				while(count < processNummber)
 					{
 						strcpy(file_copy4,file_copy2);
 						strcat(file_copy4,"/Result_");
 						sprintf(buffer, "%d", count);
 						strcat(file_copy4,buffer);
 						//printf("\nFILE NAME :: %s", file_copy4);
 						strcpy(finalcat[cnt],file_copy4);
 					// 	if(count==0)
						// 	strcpy(finalcurl[2],"0-19999999");
						// else
						// 	strcpy(finalcurl[2],"20000000-");
						int kuchbhi = size/processNummber;
						int kuchbhi1 = size/processNummber;
						if(count==0)
						{
							strcat(finalcurl[2],"-");
							sprintf(buffer, "%d", kuchbhi);
 							strcat(finalcurl[2],buffer);
						}	
						else if(count != processNummber-1)
						{
							strcpy(finalcurl[2],"");
							kuchbhi = (count)*kuchbhi;
							sprintf(buffer, "%d", kuchbhi+1);
 							strcat(finalcurl[2],buffer);
 							strcat(finalcurl[2],"-");
 							kuchbhi = kuchbhi + kuchbhi1;
 							sprintf(buffer, "%d", kuchbhi);
 							strcat(finalcurl[2],buffer);
 							
						}
						else
						{
							strcpy(finalcurl[2],"");
							sprintf(buffer, "%d",(processNummber-1)*kuchbhi);
 							strcat(finalcurl[2],buffer);
 							strcat(finalcurl[2],"-");
						}

						// printf("\nargument 3 for curl  :: %s",finalcurl[2]);
						strcpy(finalcurl[4],file_copy4);
		                cnt++;
 						// pid[count] =fork();
 						// //argv[]
       //                  if(pid[count] < 0)
       //                  {
       //                    printf("\nForking Failed !\n");
       //                    abort();
       //                  }
       //                  else if(pid[count]==0)
       //                   {

       //                     execvp("/usr/bin/curl",finalcurl);
       //                   }
       //                  else
       //                  {
                          
       //                  }
                        //printf("\n\n\n\n");


		                struct v *data = (struct v *) malloc(sizeof(struct v));
		                data->i = i;
                        data->j = j;

                        pthread_create(&tid[x],NULL, multiply_matrix_helper, data);
                        count++ ;
                      }
                    for (int jk = 0; jk < processNummber; jk++)
				    {
				       pthread_join(tid[jk],NULL);
				    }

                // for (int km = 0; km < processNummber + 1; km++) {
                //       printf("\n%s",finalcat[km]);
                //   }	
                 // for (int km = 0; km < 6; km++) {
                 //      printf("\n%s",finalcurl[km]);
                 //  } 
                     merger(finalcat,output);
            
	}
	else
	{
		printf("\n\nPlease Follow This instruction for usage : \n");
		printf("For EXAMPLE \n\n");
		printf("./a.out http://10.8.19.24/ProxyData/access.log-20161108.gz  1500000000 2 file3.gz\n");
		printf("\nThank you !");
	}
	return 0;
}
