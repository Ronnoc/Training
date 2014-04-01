#include<stdio.h>
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int count=1;
	while(1)
	{
		int i,j;
		char map[50][50];
		int mp[50][50];
		for(i=1;i<=49;i++)for(j=1;j<=49;j++)mp[i][j]=0;
		char c;
		for(i=21;i<=28;i++)
		{
			scanf("%s",&map[i][21]);
			for(j=21;j<=28;j++)
			{
			//	scanf("%c",&map[i][j]);
				//c=getchar();
				//if(c=='\n'){j--;continue;}
				//map[i][j]=c;
				//map[i][j]=map[i][j-1];
				if(map[i][j]!='.')mp[i][j]=1;
				}
			}
		struct pst{int x;int y;}sp[100],sn[100],sb[100],sr[100],sq,sk,bp[100],bn[5100],bb[100],br[100],bq,bk;
		int bbag=0;
		int spp=1,snn=1,sbb=1,srr=1,bpp=1,bnn=1,bbb=1,brr=1;
		int f1=0,f2=0;
		for(i=21;i<=28;i++)
		{
			for(j=21;j<=28;j++)
			{
				if(map[i][j]=='p'){sp[spp].x=i;sp[spp].y=j;spp++;}
				if(map[i][j]=='n'){sn[snn].x=i;sn[snn].y=j;snn++;}
				if(map[i][j]=='b'){sb[sbb].x=i;sb[sbb].y=j;sbb++;}
				if(map[i][j]=='r'){sr[srr].x=i;sr[srr].y=j;srr++;}
				if(map[i][j]=='q'){sq.x=i;sq.y=j;f1=1;}
				if(map[i][j]=='k'){sk.x=i;sk.y=j;bbag=1;}
				if(map[i][j]=='P'){bp[bpp].x=i;bp[bpp].y=j;bpp++;}
				if(map[i][j]=='N'){bn[bnn].x=i;bn[bnn].y=j;bnn++;}
				if(map[i][j]=='B'){bb[bbb].x=i;bb[bbb].y=j;bbb++;}
				if(map[i][j]=='R'){br[brr].x=i;br[brr].y=j;brr++;}
				if(map[i][j]=='Q'){bq.x=i;bq.y=j;f2=1;}
				if(map[i][j]=='K'){bk.x=i;bk.y=j;bbag=1;}
				}
			}
		if(!bbag)break;
		int bc=0,sc=0;
		

		
		if(f1){sr[srr].x=sq.x;sr[srr].y=sq.y;srr++;}
		if(f2){br[brr].x=bq.x;br[brr].y=bq.y;brr++;}
		if(f1){sb[sbb].x=sq.x;sb[sbb].y=sq.y;sbb++;}
		if(f2){bb[bbb].x=bq.x;bb[bbb].y=bq.y;bbb++;}
		
		for(i=1;i<snn;i++)
		{
			if(sn[i].x+1==bk.x && (sn[i].y+2==bk.y || sn[i].y-2==bk.y))bc=1;
			if(sn[i].x-1==bk.x && (sn[i].y+2==bk.y || sn[i].y-2==bk.y))bc=1;
			if(sn[i].x+2==bk.x && (sn[i].y+1==bk.y || sn[i].y-1==bk.y))bc=1;
			if(sn[i].x-2==bk.x && (sn[i].y+1==bk.y || sn[i].y-1==bk.y))bc=1;
			}
		for(i=1;i<bnn;i++)
		{
			if(bn[i].x+1==sk.x && (bn[i].y+2==sk.y || bn[i].y-2==sk.y))sc=1;
			if(bn[i].x-1==sk.x && (bn[i].y+2==sk.y || bn[i].y-2==sk.y))sc=1;
			if(bn[i].x+2==sk.x && (bn[i].y+1==sk.y || bn[i].y-1==sk.y))sc=1;
			if(bn[i].x-2==sk.x && (bn[i].y+1==sk.y || bn[i].y-1==sk.y))sc=1;
			}	
		for(i=1;i<spp;i++)
		{
			if(sp[i].x+1==bk.x && (sp[i].y+1==bk.y || sp[i].y-1==bk.y))bc=1;
			}
		for(i=1;i<bpp;i++)
		{
			if(bp[i].x-1==sk.x && (bp[i].y+1==sk.y || bp[i].y-1==sk.y))sc=1;
			}
		for(i=1;i<srr;i++)
		{
			if(bk.y==sr[i].y)for(j=sr[i].x+1;j<=28;j++){if(j==bk.x)bc=1;if(mp[j][sr[i].y])break;}
			if(bk.y==sr[i].y)for(j=sr[i].x-1;j>=21;j--){if(j==bk.x)bc=1;if(mp[j][sr[i].y])break;}
			if(bk.x==sr[i].x)for(j=sr[i].y+1;j<=28;j++){if(j==bk.y)bc=1;if(mp[sr[i].x][j])break;}
			if(bk.x==sr[i].x)for(j=sr[i].y-1;j>=21;j--){if(j==bk.y)bc=1;if(mp[sr[i].x][j])break;}
			}
		for(i=1;i<brr;i++)
		{
			if(sk.y==br[i].y)for(j=br[i].x+1;j<=28;j++){if(j==sk.x)sc=1;if(mp[j][br[i].y])break;}
			if(sk.y==br[i].y)for(j=br[i].x-1;j>=21;j--){if(j==sk.x)sc=1;if(mp[j][br[i].y])break;}
			if(sk.x==br[i].x)for(j=br[i].y+1;j<=28;j++){if(j==sk.y)sc=1;if(mp[br[i].x][j])break;}
			if(sk.x==br[i].x)for(j=br[i].y-1;j>=21;j--){if(j==sk.y)sc=1;if(mp[br[i].x][j])break;}
			}		
		for(i=1;i<sbb;i++)
		{
			for(j=1;j<=8;j++){if(sb[i].x+j==bk.x && sb[i].y+j==bk.y)bc=1;if(sb[i].x+j>=29||sb[i].y+j>=29)break;if(mp[sb[i].x+j][sb[i].y+j])break;}
			for(j=1;j<=8;j++){if(sb[i].x-j==bk.x && sb[i].y+j==bk.y)bc=1;if(sb[i].x-j<=20||sb[i].y+j>=29)break;if(mp[sb[i].x-j][sb[i].y+j])break;}
			for(j=1;j<=8;j++){if(sb[i].x+j==bk.x && sb[i].y-j==bk.y)bc=1;if(sb[i].x+j>=29||sb[i].y-j<=20)break;if(mp[sb[i].x+j][sb[i].y-j])break;}
			for(j=1;j<=8;j++){if(sb[i].x-j==bk.x && sb[i].y-j==bk.y)bc=1;if(sb[i].x-j<=20||sb[i].y-j<=20)break;if(mp[sb[i].x-j][sb[i].y-j])break;}
		}
		for(i=1;i<bbb;i++)
		{
			for(j=1;j<=8;j++){if(bb[i].x+j==sk.x && bb[i].y+j==sk.y)sc=1;if(bb[i].x+j>=29||bb[i].y+j>=29)break;if(mp[bb[i].x+j][bb[i].y+j])break;}
			for(j=1;j<=8;j++){if(bb[i].x-j==sk.x && bb[i].y+j==sk.y)sc=1;if(bb[i].x-j<=20||bb[i].y+j>=29)break;if(mp[bb[i].x-j][bb[i].y+j])break;}
			for(j=1;j<=8;j++){if(bb[i].x+j==sk.x && bb[i].y-j==sk.y)sc=1;if(bb[i].x+j>=29||bb[i].y-j<=20)break;if(mp[bb[i].x+j][bb[i].y-j])break;}
			for(j=1;j<=8;j++){if(bb[i].x-j==sk.x && bb[i].y-j==sk.y)sc=1;if(bb[i].x-j<=20||bb[i].y-j<=20)break;if(mp[bb[i].x-j][bb[i].y-j])break;}
			}
		

			
		if(sc)printf("Game #%d: black king is in check.\n",count);
		else if(bc)printf("Game #%d: white king is in check.\n",count);
		else printf("Game #%d: no king is in check.\n",count);
		count++; 
		}
	return 0;
	} 
