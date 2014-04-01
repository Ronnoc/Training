#include<stdio.h>
#include<string.h>
int main()
{
	//freopen("out.txt","w",stdout);
	int z;
	while(scanf("%d",&z)==1)
	{
		if(z==-1)break;
		char word[200],guess[200];
		bool a_word[27],a_guess[27];
		int i;
		for(i=1;i<=26;i++){a_word[i]=0;a_guess[i]=0;}
		scanf("%s%s",word,guess);
		int lenw=strlen(word);
		for(i=0;i<lenw;i++)a_word[word[i]-'a'+1]=1;
		int cuo=0;
		int lenq=strlen(guess);
		char cai;i=0;
		int sumw=0,k;
		//for(i=1;i<=26;i++)printf("%c的a_word是%d\n",'a'+i-1,a_word[i]);
	//		for(k=1;k<=26;k++)printf("%c的w是%d ",'a'+k-1,a_word[k]);printf("\n\n");
	//		for(k=1;k<=26;k++)printf("%c的g是%d ",'a'+k-1,a_guess[k]);printf("\n\n");		
		while(cuo<7 && i!=lenq)
		{
			cai=guess[i++];
			if(a_guess[cai-'a'+1])continue;
			else
			{
				a_guess[cai-'a'+1]=1;
				if(a_word[cai-'a'+1])a_word[cai-'a'+1]=0;
				else cuo++;
				}
			sumw=0;
			for(k=0;k<lenw;k++)sumw+=a_word[word[k]-'a'+1];
			if(sumw==0)break;
	//		for(k=1;k<=26;k++)printf("%c的w是%d ",'a'+k-1,a_word[k]);printf("\n\n");
	//		for(k=1;k<=26;k++)printf("%c的g是%d ",'a'+k-1,a_guess[k]);printf("\n\n");
			}
		sumw=0;
		for(i=0;i<lenw;i++)sumw+=a_word[word[i]-'a'+1];
		printf("Round %d\n",z);
		if(cuo>=7)printf("You lose.\n");
		else if(sumw==0)printf("You win.\n");
		else printf("You chickened out.\n");
		}
	return 0;
	}
