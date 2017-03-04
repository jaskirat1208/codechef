#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int k,n;
	scanf("%d",&n);
	char* str=(char*)calloc(n+1,sizeof(int));
	scanf("%s",str);
	scanf("%d",&k);
///	printf("%s",str);
	for(int i=0;i<strlen(str);i++)
	{
		if((str[i]>='0' && str[i]<='9') || (str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
			if(str[i]<='Z'){
				str[i]=(str[i]-'A'+k)%26 + 'A';
			}
			else if(str[i]>='a'){
				str[i]=(str[i]-'a'+k)%26 + 'a';
			}
		}
		//else  if(str[i]>='1' && str[i])
		// else{
		// 	str[i]=str[i]+1;
		// }
	}
	printf("%s\n",str);
	return 0;
}