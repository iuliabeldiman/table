import java.util.*;

public class Back {
	
	static final int NEGRU=2;
	static final int ALB=1;
	static int tusaalb=0,tusanegru=0,zar1,zar2;
	static int countalb=0,countnegru=0;
	static int countalb2=0,countnegru2=0;
	
	static Scanner scan = new Scanner(System.in);
	
	public static void initializare(int[][] q)
	{
		int i,j;
		
		for(i=0;i<30;i++)
			for(j=0;j<12;j++)
			{
				q[i][j]=0;
			}
		j=0;
		
		for(i=0;i<5;i++)
		{
			q[i][j]=ALB;q[29-i][j]=NEGRU;
			q[i][6]=NEGRU;q[29-i][6]=ALB;		
		}
		j=4;
		
		for(i=0;i<3;i++)
		{
			q[i][j]=NEGRU;q[29-i][j]=ALB;
		}
		j=11;
		
		for(i=0;i<2;i++)
		{
			q[i][j]=ALB;q[29-i][j]=NEGRU;
		}
	}
	
	public static void afisare(int[][] q)
	{
		for(int i=0;i<30;i++)
			{
			for(int j=0;j<12;j++)
			{
				if(q[i][j]==ALB){
				System.out.print("A" + " ");}
				else if(q[i][j]==NEGRU){System.out.print("N" + " ");}
				else System.out.print("-" + " ");
			}
			System.out.println();
			}		
	}
	
	public static boolean stare_finala(int[][] q)
	{		
		for (int i=0;i<15;i++){
			for (int j=6;j<12;j++)
			{
				if(q[i][j]==ALB){countalb++;}
				else if (q[i][j]==NEGRU){countnegru++;}
				
				if(q[29-i][j]==ALB){countalb2++;}
				else if (q[29-i][j]==NEGRU){countnegru2++;}
			}
		}
		
		if((countalb==15 && countnegru==0) || (countalb2==0 && countnegru2==15))
		{
			return true;
		}
		return false;
	}
	
	public static boolean tranzitie_valida(int[][] q,int zar3,int x,int y)
	{
		
		if (x>14)
		{
			if(q[x][y]==NEGRU)
			{
				if(q[28][y+zar3]==ALB)
				{
					return false;
				}
			}
			else if(q[x][y]==ALB)
			{
				if(y-zar3>=0)
				{
					if(q[28][y-zar3]==NEGRU)
					{
						return false;
					}
				}
				else {
					if(q[1][Math.abs(y-zar3)]==NEGRU){
						return false;
					}
				}
			}
		}
		else{
			if(q[x][y]==ALB)
			{
				if(q[1][y+zar3]==NEGRU)
				{
					return false;
				}
			}
			else if(q[x][y]==NEGRU)
			{
				if(y-zar3>=0)
				{
					if(q[1][y-zar3]==ALB)
					{
						return false;
					}
				}
				else {
					if(q[28][Math.abs(y-zar3)]==ALB){
						return false;
					}
				}
			}
		}
		return true;
	}
	
	public static void ETusa(int [][]q, int x,int y,int tusa,int culoare)
	{
		if(tusa>0)
		{
			if(culoare==1)
			{
				tusaalb-=1;
				x=28;
				y=12;
			}
			else if(culoare==2)
			{
				tusanegru-=1;
				x=1;
				y=12;
			}
		}
	}
	
	public static void muta(int[][] q,int x,int y,int zar,int culoare){
		int i,j;
		if(culoare==NEGRU)
			{
			if(x<15){	
				if(y-zar>=0)
					{
						i=0;
						j=y-zar;
						while(q[i][j]==2)
						{
							i++;
						}
						q[i][j]=2;
						q[x][y]=0;
					}
					else {
						i=29;
						j=Math.abs(y-zar);
						while(q[i][j]==2)
						{
							i--;
						}
						q[i][j]=2;
						q[x][y]=0;
					}
			
				}else {
					i=29;
					j=y+zar;
					while(q[i][j]==2)
					{
						i--;
					}
					q[i][j]=2;
					q[x][y]=0;
				}
				}
			else if(culoare==ALB){
				if(x>=15){
					if(y-zar>=0)
					{
						i=29;
						j=y-zar;
						while(q[i][j]==1)
						{
							i--;
						}
						q[i][j]=1;
						q[x][y]=0;
					}else 
					{
						i=1;
						j=Math.abs(y-zar);
						while(q[i][j]==1)
						{
							i++;
						}
						q[i][j]=1;
						q[x][y]=0;
					}
				}
				else {
					i=1;
					j=y+zar;
					while(q[i][j]==1)
					{
						i++;
					}
					q[i][j]=1;
					q[x][y]=0;
				}
		}
}
	
	public static void strategie(int[][] q)
	{
		while(!stare_finala(q)){
			zar1=1+(int)(Math.random()*6);
			zar2=1+(int)(Math.random()*6);
			System.out.println(zar1+" "+zar2);
			afisare(q);
			System.out.println("Introduceti coordonatele unde doriti sa mutati");
			int xOM=scan.nextInt();
			int yOM=scan.nextInt();
			int xAI=0;
			int yAI=0;
			while(q[xAI][yAI]!=2){
			xAI=0+(int)(Math.random()*29);
			yAI=0+(int)(Math.random()*11);}
			if(xAI<15){
				while(q[xAI+1][yAI]==2){
					xAI+=1;
				}
			}else
			{
				while(q[xAI-1][yAI]==2){
					xAI-=1;
				}
			}
			ETusa(q,xAI,yAI,tusaalb,NEGRU);
			if(tranzitie_valida(q,zar1,xAI,yAI))
			{
				muta(q,xAI,yAI,zar1,NEGRU);
			}
			else if(tranzitie_valida(q,zar2,xAI,yAI))
			{
				muta(q,xAI,yAI,zar2,NEGRU);
			}
			
		}
		
		
	}
	
	
	
	
	public static void main(String[] args)
	{
		int[][] q=new int[30][12];
		initializare(q);
		stare_finala(q);
		afisare(q);
	}
	
	
		
	}


