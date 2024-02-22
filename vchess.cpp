#include<iostream>//not important now
#include<stdlib.h>//not important now
#include<time.h>//for randomize
#include <GL/glut.h>// main fun of glut
#include<cmath>//for circle
using namespace std ;//no important now
static int g=0;//focpu
float x00[9]={0};//for plac change
float y00[9]={0};//
float x11[16]={0};//manfiha makos moratab mishavand baray formol harekat vahed
float y11[16]={0};//manfiha makos moratab mishavand baray formol harekat vahed
int flag=2;//for click &nobatdehi
int NOBAT=1;//no used
int T[30]={0};//no used for cpu inteligence
int c=0;//counter for cpu inteligence
int p1=-1,p2=-1,p3=-1,p4=-1;//for hitt animated
float p5=-1;//for begin hit animated
float v[3]={1,1,1};//for color of main shaps 1,.9,.011
float V[83][3]={1.00,.900,.011,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,1.00,.900,.011,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,	
			  .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,1.00,.900,.011,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,1.00,.900,.011,.685,.400,.018,.685,.400,.018,.685,.400,.018,.685,.400,.018,
	          .685,.400,.018,.685,.400,.018,.685,.400,.018,1.00,.900,.011,.870,.80,.49,.870,.80,.49};//for changes color of main shaps(quads)
int M[9][9]={10,0,0,-5,-6,-7,0,0,10,
			 0,0,0,0,-8,0,0,0,0,
			 0,0,0,0,3,0,0,0,0,
			 -3,0,0,0,4,0,0,0,-9,
			-2,-4,1,2,9,6,5,-12,-10,
			 -1,0,0,0,8,0,0,0,-11,
			 0,0,0,0,7,0,0,0,0,
			 0,0,0,0,-16,0,0,0,0,
			 10,0,0,-15,-14,-13,0,0,10};
int LM[9][9]={10,0,0,-5,-6,-7,0,0,10,
			 0,0,0,0,-8,0,0,0,0,
			 0,0,0,0,3,0,0,0,0,
			 -3,0,0,0,4,0,0,0,-9,
			-2,-4,1,2,9,6,5,-12,-10,
			 -1,0,0,0,8,0,0,0,-11,
			 0,0,0,0,7,0,0,0,0,
			 0,0,0,0,-16,0,0,0,0,
			 10,0,0,-15,-14,-13,0,0,10};
int LM2[9][9];
void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer,iUnused);
}
void uncolor(int i){
glutPostRedisplay();
V[i][0]=.685;
V[i][1]=.400;
V[i][2]=.018;
}							
int m_number(int a,int b){//for color 0 to 80  V[81]
	int k=0;
	for(int i=0;i<=8;i++)
		for(int j=0;j<=8;j++){
			if(i==a&&j==b)
				return k;
			k++;
		}
}
bool zs(int a,int b,int x,int y){
	int j=0;
	if((a-x)==0){
		if(b>y){
		for(int i=b;i>=y;i--)
		if(M[a][i]==0)
			j++;
		if(j==(b-y+1))
			return 1;
			return 0;
		}
		else{
		for(int i=y;i>=b;i--)
		if(M[a][i]==0)
			j++;
		if(j==(y-b+1))
			return 1;
			return 0;
		}
	}
	else if(b-y==0){
	if(a>x){
		for(int i=a;i>=x;i--)
		if(M[i][b]==0)
			j++;
		if(j==(a-x+1))
			return 1;
			return 0;
		}
		else{
		for(int i=x;i>=a;i--)
		if(M[i][b]==0)
			j++;
		if(j==(x-a+1))
			return 1;
			return 0;
		}
	
	}

}
bool ns(int a,int b,int x,int y){
	if(M[a][b]==0){
	if(a==x){
		if(b<y){
		for(int i=b+1;i!=-1&&i<=y;i++){//right search
			  if(M[a][i]<0){
			  M[a][b]=M[a][i];
			  x11[(M[a][i]+16)]-=(i-b)*1.9;
			  M[a][i]=0;
			  flag=0;
			  cout<<"\nMB negative from M["<<x<<"]["<<i<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[a][i]>0){
				  i=-2;
			cout<<"\nMB cant get negative from M["<<x<<"]"<<"["<<i<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
		else{
		for(int i=b-1;i!=-1&&i>=y;i--){//left search
			  if(M[a][i]<0){
			  M[a][b]=M[a][i];
			  x11[(M[a][i]+16)]+=(b-i)*1.9;
			  M[a][i]=0;
			  flag=0;
			  cout<<"\nMB negative from M["<<x<<"]["<<i<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[a][i]>0){
				  i=-2;
			  cout<<"\nMB cant get negative from M["<<x<<"]"<<"["<<i<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
	}
	else if(b==y){
		if(a<x){
		for(int i=a+1;i!=-1&&i<=x;i++){//down search
			  if(M[i][b]<0){
			  M[a][b]=M[i][b];
			  y11[(M[i][b]+16)]+=(i-a)*1.9;
			  M[i][b]=0;
			  flag=0;
			  cout<<"\nMB negative from M["<<i<<"]["<<b<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[i][b]>0){	
			  cout<<"\nMB cant get negative from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  i=-2;
			  }
			  }
		return 0;
		}
		else{
		for(int i=a-1;i!=-1&&i>=x;i--){//up search
			  if(M[i][b]<0){
			  M[a][b]=M[i][b];
			  y11[(M[i][b]+16)]-=(a-i)*1.9;
			  M[i][b]=0;
			  flag=0;
			  cout<<"\nMB negative from M["<<i<<"]["<<b<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[i][b]>0){
			  cout<<"\nMB cant get negative from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  i=-2;
			  }
			  }
		return 0;
		}
	
	}
	}
	return 0;
}

bool ms(int a,int b,int x,int y,int z){
	if(a==x){
		if(b<y){
		for(int i=b+1;i!=-1&&i<=y;i++){//right search
			  if(M[a][i]==z){
			 
			  cout<<"\nMB "<<z<<" from M["<<x<<"]["<<i<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[a][i]!=0){
				  i=-2;
			cout<<"\nMB cant get "<<z <<"from M["<<x<<"]"<<"["<<y<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
		else{
		for(int i=b-1;i!=-1&&i>=y;i--){//left search
			  if(M[a][i]==z){		  
			   cout<<"\nMB "<<z<<" from M["<<x<<"]["<<i<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[a][i]!=0){
				  i=-2;
			  cout<<"\nMB cant get "<<z <<"from M["<<x<<"]"<<"["<<y<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
	}
	else if(b==y){
		if(a<x){
		for(int i=a+1;i!=-1&&i<=x;i++){//down search
			  if(M[i][b]==z){
			  cout<<"\nMB "<<z<<" from M["<<i<<"]["<<b<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[i][b]!=0){	
			  cout<<"\nMB cant get "<<z <<"from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  i=-2;
			  }
			  }
		return 0;
		}
		else{
		for(int i=a-1;i!=-1&&i>=x;i--){//up search
			  if(M[i][b]==z){
			  cout<<"\nMB "<<z<<" from M["<<i<<"]["<<b<<"] to M["<<a<<"]["<<b<<"]  \n";
			  return 1;
			  }
			  else if(M[i][b]!=0){
			  cout<<"\nMB cant get "<<z <<"from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  i=-2;
			  }
			  }
		return 0;
		}
	
	}
}

bool ps(int a,int b,int x,int y){
	if(a==x){
		if(b<y){
		for(int i=b+1;i!=-1&&i<=y;i++){//right search
			  if(M[a][i]>0){
			  M[a][b]=M[a][i];
			  return 1;
			  }
			  else if(M[a][i]<0){
				  i=-2;
			cout<<"\nMBT cant get posetive from M["<<x<<"]"<<"["<<y<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
		else{
		for(int i=b-1;i!=-1&&i>=y;i--){//left search
			  if(M[a][i]>0){
			 
			  return 1;
			  }
			  else if(M[a][i]<0){
				  i=-2;
			cout<<"\nMBT cant get posetive from M["<<x<<"]"<<"["<<y<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
	}
	else if(b==y){
		if(a<x){
		for(int i=a+1;i!=-1&&i<=x;i++){//down search
			  if(M[i][b]<0){
			  
			  return 1;
			  }
			  else if(M[i][b]<0){
				  i=-2;
			cout<<"\nMBT cant get posetive from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
		else{
		for(int i=a-1;i!=-1&&i>=x;i--){//up search
			  if(M[i][b]>0){
			  return 1;
			  }
			  else if(M[i][b]<0){
				  i=-2;
			cout<<"\nMBT cant get posetive from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
	
	}
}



bool nst(int a,int b,int x,int y,int &c,int &d){
	if(a==x){
		if(b<y){
		for(int i=b+1;i!=-1&&i<=y;i++){//right search
			  if(M[a][i]<0){
			  c=a;
			  d=i;
			  return 1;
			  }
			  else if(M[a][i]>0){
				  i=-2;
			cout<<"\nMBT cant get negative from M["<<x<<"]"<<"["<<y<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
		else{
		for(int i=b-1;i!=-1&&i>=y;i--){//left search
			  if(M[a][i]<0){
			  c=a;
			  d=i;
			  return 1;
			  }
			  else if(M[a][i]>0){
				  i=-2;
			cout<<"\nMBT cant get negative from M["<<x<<"]"<<"["<<y<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
	}
	else if(b==y){
		if(a<x){
		for(int i=a+1;i!=-1&&i<=x;i++){//down search
			  if(M[i][b]<0){
			  c=i;
			  d=b;
			  return 1;
			  }
			  else if(M[i][b]>0){
				  i=-2;
			cout<<"\nMBT cant get negative from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
		else{
		for(int i=a-1;i!=-1&&i>=x;i--){//up search
			  if(M[i][b]<0){
			  c=i;
			  d=b;
			  return 1;
			  }
			  else if(M[i][b]>0){
				  i=-2;
			cout<<"\nMBT cant get negative from M["<<i<<"]"<<"["<<b<<"] to M["<<a<<"]"<<"["<<b<<"]\n";
			  }
			  }
		return 0;
		}
	
	}
}
int ds(int a,int b,int x,int y){
	//if((a==x&&b==y))
	//	return 0;
	if(a==x){
		if(b>y){
		return (b-y-1);
		}
		else{
		return (y-b-1);
		}
	}
	else if(b==y){
		if(a>x){
		return (a-x-1);
		}
		else{
		return (x-a-1);
		}
	}

}
int minimum(int a,int b,int c,int d,int e, int f){
int min=1000;
if(a<min)
	min=a;
if(b<min)
	min=b;
if(c<min)
	min=c;
if(d<min)
	min=d;
if(e<min)
	min=e;
if(f<min)
	min=f;
return min;
}
bool TB(){//teror the boss
	if(M[4][4]==9){
		if(M[4][4+1]<0 && M[4][4-1]==0){
			for(int i=2;i!=-1;i++){//left search
			  if(M[4][4-i]<0&&(4-i)>=0){
			  M[4][4-1]=M[4][4-i];
			  x11[(M[4][4-i]+16)]+=(i-1)*1.9;
			  M[4][4-i]=0;
			  flag=4;
			  cout<<"TB M[4][4] ";
			  return 1;
			  
			  }
			  else if(M[4][4-i]>0||(4-i)<0){
				 i=-2; 
			cout<<"TB M[4][4] 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][4-1]<0&&(4-i)>=0){
			 M[4][4-1]=M[4-i][4-1];
			 y11[(M[4-i][4-1]+16)]-=i*1.9;
			 M[4-i][4-1]=0;
			 flag=4;
			 cout<<"TB M[4][4] 2";
			 return 1;
			 }
			 else if(M[4-i][4-1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4][4] 3";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][4-1]<0&&(4+i)<=8){
			 M[4][4-1]=M[4+i][4-1];
			 y11[(M[4+i][4-1]+16)]+=i*1.9;
			 M[4+i][4-1]=0;
			 
			 flag=4;
			 cout<<"TB M[4][4] 4";
			 return 1;
			 }
			 else if(M[4+i][4-1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4][4] 5";
			 }
		}
		}//end of M[4][4+1]<0 && M[4][4-1]==0
		else if(M[4][4-1]<0 && M[4][4+1]==0){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[4][4+i]<0&&(4+i)<=8){
			  M[4][4+1]=M[4][4+i];
			  x11[(M[4][4+i]+16)]-=(i-1)*1.9;
			  M[4][4+i]=0;
			  flag=4;
			  cout<<"TB M[4][4] 6";
			  return 1;
			  }
			  else if(M[4][4+i]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4][4] 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][4+1]<0&&(4-i)>=0){
			 M[4][4+1]=M[4-i][4+1];
			 y11[(M[4-i][4+1]+16)]-=i*1.9;
			 M[4-i][4+1]=0;
			 flag=4;
			 cout<<"TB M[4][4] 8";
			 return 1;
			 }
			 else if(M[4-i][4+1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4][4] 9";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][4+1]<0&&(4+i)<=8){
			 M[4][4+1]=M[4+i][4+1];
			 y11[(M[4+i][4+1]+16)]+=i*1.9;
			 M[4+i][4+1]=0;
			 flag=4;
			 cout<<"TB M[4][4] 10";
			 return 1;
			 }
			 else if(M[4+i][4+1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4][4] 11";
		    }
		}
		}//end of M[4][4-1]<0 && M[4][4+1]==0
			//--------------------------------up and down
		if(M[4+1][4]<0 && M[4-1][4]==0){
			for(int i=2;i!=-1;i++){//up search
			  if(M[4-i][4]<0&&(4-i)>=0){
			  M[4-1][4]=M[4-i][4];
			  y11[(M[4-i][4])+16]-=(i-1)*1.9;
			  M[4-i][4]=0;
			  flag=4;
			  cout<<"TB M[4][4] 12";
			  return 1;
			  }
			  else if(M[4-i][4]>0||(4-i)<0){
				  i=-2;
			 cout<<"TB M[4][4] 13";
			  }
			}
			for(int i=1;i!=-1;i++){//left search
			 if(M[4-1][4-i]<0&&(4-i)>=0){
			 M[4-1][4]=M[4-1][4-i];
			 x11[(M[4-1][4-i]+16)]+=i*1.9;
			 M[4-1][4-i]=0;
			 flag=4;
			 cout<<"TB M[4][4] 14";
			 return 1;
			 }
			 else if(M[4-1][4-i]>0||(4-i)<0){
				  i=-2;
			 cout<<"TB M[4][4] 15";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4-1][4+i]<0&&(4+i)<=8){
			 M[4-1][4]=M[4-1][4+i];
			 x11[(M[4-1][4+i]+16)]-=i*1.9;
			 M[4-1][4+i]=0;
			 flag=4;
			 cout<<"TB M[4][4] 16";
			 return 1;
			 }
			 else if(M[4-1][4+i]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4][4] 17";
			 }
		}
		}//M[4+1][4]<0 && M[4-1][4]==0
		else if(M[4-1][4]<0 && M[4+1][4]==0){//----up else
			  for(int i=2;i!=-1;i++)//down search
			  if(M[4+i][4]<0&&(4+i)<=8){
			  M[4+1][4]=M[4+i][4];
			  y11[(M[4+i][4]+16)]+=(i-1)*1.9;
			  M[4+i][4]=0;
			  flag=4;
			  cout<<"TB M[4][4] 18";
			  return 1;
			  }
			  else if(M[4+i][4]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4][4] 19";
			  }
			for(int i=1;i!=-1;i++){//left search
			 if(M[4+1][4-i]<0&&(4-i)>=0){
			 M[4+1][4]=M[4+1][4-i];
			 x11[(M[4+1][4-i]+16)]+=i*1.9;
			 M[4+1][4-i]=0;
			 flag=4;
			 cout<<"TB M[4][4] 20";
			 return 1;
			 }
			 else if(M[4+1][4-i]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4][4] 21";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4+1][4+i]<0&&(4+i)<=8){
			 M[4+1][4]=M[4+1][4+i];
			 x11[(M[4+1][4+i]+16)]-=i*1.9;
			 M[4+1][4+i]=0;
			 flag=4;
			 cout<<"TB M[4][4] 22";
			 return 1;
			 }
			 else if(M[4+1][4+i]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4][4] 23";
			 }
			}
	/**/}
	//else//kole safheh
		return 0;
	}//end of M[4][4]==9
	for(int j=1;j<=4;j++){
		if(M[4][4-j]==9){
		if(M[4][(4-j)+1]<0 && M[4][(4-j)-1]==0&&((4-j)-1)>=0 &&(4-j)+1!=4){
			for(int i=2;i!=-1;i++){//left search
			  if(M[4][(4-j)-i]<0&&(4-j)-i>=0){
			  M[4][(4-j)-1]=M[4][(4-j)-i];
			  x11[(M[4][(4-j)-i]+16)]+=(i-1)*1.9;
			  M[4][(4-j)-i]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4-j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[4][(4-j)-i]>0||((4-j)-i)<0){
				 i=-2; 
			cout<<"TB M[4]["<<4-j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][(4-j)-1]<0&&(4-i)>=0){
			 M[4][(4-j)-1]=M[4-i][(4-j)-1];
			 y11[(M[4-i][(4-j)-1]+16)]-=i*1.9;
			 M[4-i][(4-j)-1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 2";
			 return 1;
			 }
			 else if(M[4-i][(4-j)-1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 3";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][(4-j)-1]<0&&(4+i)<=8){
			 M[4][(4-j)-1]=M[4+i][(4-j)-1];
			 y11[(M[4+i][(4-j)-1]+16)]+=i*1.9;
			 M[4+i][(4-j)-1]=0;
			 
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[4+i][(4-j)-1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 5";
			 }
		}
		}
		else if(M[4][((4-j)-1)]<0 && M[4][(4-j)+1]==0&&((4-j)-1)>=0&&((4-j)+1)<4){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[4][(4-j)+i]<0&&((4-j)+i)<=8){
			  M[4][(4-j)+1]=M[4][(4-j)+i];
			  x11[(M[4][(4-j)+i]+16)]-=(i-1)*1.9;
			  M[4][(4-j)+i]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4-j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[4][(4-j)+i]>0||((4-j)+i)>8){
				  i=-2;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][(4-j)+1]<0&&(4-i)>=0){
			 M[4][(4-j)+1]=M[4-i][(4-j)+1];
			 y11[(M[4-i][(4-j)+1]+16)]-=i*1.9;
			 M[4-i][(4-j)+1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 8";
			 return 1;
			 }
			 else if(M[4-i][(4-j)+1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 9";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][(4-j)+1]<0&&(4+i)<=8){
			 M[4][(4-j)+1]=M[4+i][(4-j)+1];
			 y11[(M[4+i][(4-j)+1]+16)]+=i*1.9;
			 M[4+i][(4-j)+1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[4+i][(4-j)+1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		if(M[4+1][(4-j)]<0 && M[4-1][(4-j)]==0){
			for(int i=2;i!=-1;i++){//up search
			  if(M[4-i][(4-j)]<0&&(4-i)>=0){
			  M[4-1][(4-j)]=M[4-i][(4-j)];
			  y11[(M[4-i][(4-j)])+16]-=(i-1)*1.9;
			  M[4-i][(4-j)]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4-j<<"]"<<" 12";
			  return 1;
			  }
			  else if(M[4-i][(4-j)]>0||(4-i)<0){
				  i=-2;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 13";
			  }
			}
			for(int i=1;i!=-1;i++){//left search
			 if(M[4-1][(4-j)-i]<0&&((4-j)-i)>=0){
			 M[4-1][(4-j)]=M[4-1][(4-j)-i];
			 x11[(M[4-1][(4-j)-i]+16)]+=i*1.9;
			 M[4-1][(4-j)-i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 14";
			 return 1;
			 }
			 else if(M[4-1][(4-j)-i]>0||((4-j)-i)<0){
				  i=-2;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 15";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4-1][(4-j)+i]<0&&((4-j)+i)<=8){
			 M[4-1][(4-j)]=M[4-1][(4-j)+i];
			 x11[(M[4-1][(4-j)+i]+16)]-=i*1.9;
			 M[4-1][(4-j)+i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 16";
			 return 1;
			 }
			 else if(M[4-1][(4-j)+i]>0||((4-j)+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 17";
			 }
		}
		}
		else if(M[4-1][4-j]<0 && M[4+1][4-j]==0){//----up else
			  for(int i=2;i!=-1;i++)//down search
			  if(M[4+i][(4-j)]<0&&(4+i)<=8){
			  M[4+1][(4-j)]=M[4+i][(4-j)];
			  y11[(M[4+i][(4-j)]+16)]+=(i-1)*1.9;
			  M[4+i][4-j]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4-j<<"]"<<" 18";
			  return 1;
			  }
			  else if(M[4+i][(4-j)]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 19";
			  }
			for(int i=1;i!=-1;i++){//left search
			 if(M[4+1][(4-j)-i]<0&&((4-j)-i)>=0){
			 M[4+1][(4-j)]=M[4+1][(4-j)-i];
			 x11[(M[4+1][(4-j)-i]+16)]+=i*1.9;
			 M[4+1][(4-j)-i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 20";
			 return 1;
			 }
			 else if(M[4+1][(4-j)-i]>0||((4-j)-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 21";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4+1][(4-j)+i]<0&&((4-j)+i)<=8){
			 M[4+1][(4-j)]=M[4+1][(4-j)+i];
			 x11[(M[4+1][(4-j)+i]+16)]-=i*1.9;
			 M[4+1][(4-j)+i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4-j<<"]"<<" 22";
			 return 1;
			 }
			 else if(M[4+1][(4-j)+i]>0||((4-j)+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4-j<<"]"<<" 23";
			 }
			}
	/**/}
	//else//kole safheh
		return 0;
	}//end of M[4][4-j]==9
	
	}//end of for
	for(int j=1;j<=4;j++){
		if(M[4][4+j]==9){
		if(M[4][(4+j)+1]<0 && M[4][(4+j)-1]==0&&((4+j)-1)>=5&&((4+j)+1)<=8){
			for(int i=2;i!=-1;i++){//left search
			  if(M[4][(4+j)-i]<0&&(4+j)-i>=0){
			  M[4][(4+j)-1]=M[4][(4+j)-i];
			  x11[(M[4][(4+j)-i]+16)]+=(i-1)*1.9;
			  M[4][(4+j)-i]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" ";
			  return 1;

			  }
			  else if(M[4][(4+j)-i]>0||((4+j)-i)<0){
				 i=-2; 
			cout<<"TB M[4]["<<4+j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][(4+j)-1]<0&&(4-i)>=0){
			 M[4][(4+j)-1]=M[4-i][(4+j)-1];
			 y11[(M[4-i][(4+j)-1]+16)]-=i*1.9;
			 M[4-i][(4+j)-1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 2";
			 return 1;
			 }
			 else if(M[4-i][(4+j)-1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 3";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][(4+j)-1]<0&&(4+i)<=8){
			 M[4][(4+j)-1]=M[4+i][(4+j)-1];
			 y11[(M[4+i][(4+j)-1]+16)]+=i*1.9;
			 M[4+i][(4+j)-1]=0;
			 
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[4+i][(4+j)-1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 5";
			 }
		}
		}
		else if(M[4][((4+j)-1)]<0 && M[4][(4+j)+1]==0&&((4+j)+1)<8&&(4+j)-1!=4 ){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[4][(4+j)+i]<0&&((4+j)+i)<=8){
			  M[4][(4+j)+1]=M[4][(4+j)+i];
			  x11[(M[4][(4+j)+i]+16)]-=(i-1)*1.9;
			  M[4][(4+j)+i]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[4][(4+j)+i]>0||((4+j)+i)>8){
				  i=-2;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][(4+j)+1]<0&&(4-i)>=0){
			 M[4][(4+j)+1]=M[4-i][(4+j)+1];
			 y11[(M[4-i][(4+j)+1]+16)]-=i*1.9;
			 M[4-i][(4+j)+1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 8";
			 return 1;
			 }
			 else if(M[4-i][(4+j)+1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 9";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][(4+j)+1]<0&&(4+i)<=8){
			 M[4][(4+j)+1]=M[4+i][(4+j)+1];
			 y11[(M[4+i][(4+j)+1]+16)]+=i*1.9;
			 M[4+i][(4+j)+1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[4+i][(4+j)+1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		if(M[4+1][(4+j)]<0 && M[4-1][(4+j)]==0){
			for(int i=2;i!=-1;i++){//up search
			  if(M[4-i][(4+j)]<0&&4-i>=0){
			  M[4-1][(4+j)]=M[4-i][(4+j)];
			  y11[(M[4-i][(4+j)])+16]-=(i-1)*1.9;
			  M[4-i][(4+j)]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" 12";
			  return 1;
			  }
			  else if(M[4-i][(4+j)]>0||(4-i)<0){
				  i=-2;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 13";
			  }
			}
			for(int i=1;i!=-1;i++){//left search
			 if(M[4-1][(4+j)-i]<0&&((4+j)-i)>=0){
			 M[4-1][(4+j)]=M[4-1][(4+j)-i];
			 x11[(M[4-1][(4+j)-i]+16)]+=i*1.9;
			 M[4-1][(4+j)-i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 14";
			 return 1;
			 }
			 else if(M[4-1][(4+j)-i]>0||((4+j)-i)<0){
				  i=-2;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 15";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4-1][(4+j)+i]<0&&((4+j)+i)<=8){
			 M[4-1][(4+j)]=M[4-1][(4+j)+i];
			 x11[(M[4-1][(4+j)+i]+16)]-=i*1.9;
			 M[4-1][(4+j)+i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 16";
			 return 1;
			 }
			 else if(M[4-1][(4+j)+i]>0||((4+j)+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 17";
			 }
		}
		}
		else if(M[4-1][4+j]<0 && M[4+1][4+j]==0){//----up else
			  for(int i=2;i!=-1;i++)//down search
			  if(M[4+i][(4+j)]<0&&(4+i)<=8){
			  M[4+1][(4+j)]=M[4+i][(4+j)];
			  y11[(M[4+i][(4+j)]+16)]+=(i-1)*1.9;
			  M[4+i][4+j]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" 18";
			  return 1;
			  }
			  else if(M[4+i][(4+j)]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 19";
			  }
			for(int i=1;i!=-1;i++){//left search
			 if(M[4+1][(4+j)-i]<0&&((4+j)-i)>=0){
			 M[4+1][(4+j)]=M[4+1][(4+j)-i];
			 x11[(M[4+1][(4+j)-i]+16)]+=i*1.9;
			 M[4+1][(4+j)-i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 20";
			 return 1;
			 }
			 else if(M[4+1][(4+j)-i]>0||((4+j)-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 21";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4+1][(4+j)+i]<0&&((4+j)+i)<=8){
			 M[4+1][(4+j)]=M[4+1][(4+j)+i];
			 x11[(M[4+1][(4+j)+i]+16)]-=i*1.9;
			 M[4+1][(4+j)+i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 22";
			 return 1;
			 }
			 else if(M[4+1][(4+j)+i]>0||((4+j)+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 23";
			 }
			}
	/**/}
	//else//kole safheh
		return 0;
	}//end of M[4][4+j]==9
	
	}//end of for
	//------------------------4 first
	for(int k=0;k<=3;k++)
	for(int j=0;j<=8;j++){
		if(M[k][j]==9){
		if(k==0){
		if(M[k][(j)+1]<0 && M[k][(j)-1]==0&&((j)+1)<8&&((j)-1)>0){//------------------------------------->>>>>>>>countinu
			for(int i=2;i!=-1;i++){//left search
			  if(M[0][(j)-i]<0&&((j)-i)>=0){
			  M[0][(j)-1]=M[0][(j)-i];
			  x11[(M[0][(j)-i]+16)]+=(i-1)*1.9;
			  M[0][(j)-i]=0;
			  flag=4;
			  cout<<"TB M[0]["<<j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[0][(j)-i]>0||((j)-i)<0){
				 i=-2; 
			cout<<"TB M[0]["<<j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			//for(int i=1;i!=-1;i++){//up search
			 //if(M[4-i][(4+j)-1]<0&&(4-i)>=0){
			 //M[4][(4+j)-1]=M[4-i][(4+j)-1];
			 //y11[(M[4-i][(4+j)-1]+16)]-=i*1.9;
			 //M[4-i][(4+j)-1]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 2";
			 //return 1;
			 //}
			 //else if(M[4-i][(4+j)-1]>0||(4-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 3";
			// //}
			//}
			for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][(j)-1]<0&&(0+i)<=8){
			 M[0][(j)-1]=M[0+i][(j)-1];
			 y11[(M[0+i][(j)-1]+16)]+=i*1.9;
			 M[0+i][(j)-1]=0;
			 
			 flag=4;
			 cout<<"TB M[0]["<<j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[0+i][(j)-1]>0||(0+i)>8){
				  i=-2;
			cout<<"TB M[0]["<<j<<"]"<<" 5";
			 }
		}
		}
		else if(M[0][((j)-1)]<0 && M[0][(j)+1]==0&&((j)+1)<8&&(j-1)>0){//----left else M[0][((j)-1)]<0 && M[4][(j)+1]==0&&((j)+1)<8&&(j-1)>0
			  for(int i=2;i!=-1;i++){//right search
			  if(M[0][(j)+i]<0&&((j)+i)<=8){
			  M[0][(j)+1]=M[0][(j)+i];
			  x11[(M[0][(j)+i]+16)]-=(i-1)*1.9;
			  M[0][(j)+i]=0;
			  flag=4;
			  cout<<"TB M[0]["<<j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[0][(j)+i]>0||((j)+i)>8){
				  i=-2;
			 cout<<"TB M[0]["<<j<<"]"<<" 7";
			  }
			  }
			//for(int i=1;i!=-1;i++){//up search
			 //if(M[0-i][(j)+1]<0&&(4-i)>=0){
			 //M[4][(4+j)+1]=M[4-i][(4+j)+1];
			 //y11[(M[4-i][(4+j)+1]+16)]-=i*1.9;
			 //M[4-i][(4+j)+1]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 8";
			 //return 1;
			 //}
			 //else if(M[4-i][(4+j)+1]>0||(4-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 9";
			 //}
			//}
			for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][(j)+1]<0&&(0+i)<=8){
			 M[0][(j)+1]=M[0+i][(j)+1];
			 y11[(M[0+i][(j)+1]+16)]+=i*1.9;
			 M[0+i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M[0]["<<j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[0+i][(j)+1]>0||(0+i)>8){
				  i=-2;
			cout<<"TB M[0]["<<j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		//if(M[0+1][(j)]<0 && M[0-1][(4+j)]==0){
			//for(int i=2;i!=-1;i++){//up search
			  //if(M[4-i][(4+j)]<0&&4-i>=0){
			 // M[4-1][(4+j)]=M[4-i][(4+j)];
			  //y11[(M[4-i][(4+j)])+16]-=(i-1)*1.9;
			  //M[4-i][(4+j)]=0;
			  //flag=4;
			  //cout<<"TB M[4]["<<4+j<<"]"<<" 12";
			  //return 1;
			  //}
			  //else if(M[4-i][(4+j)]>0||(4-i)<0){
			//	  i=-2;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 13";
			  //}
			//}
			//for(int i=1;i!=-1;i++){//left search
	//		 if(M[4-1][(4+j)-i]<0&&((4+j)-i)>=0){
		//	 M[4-1][(4+j)]=M[4-1][(4+j)-i];
			// x11[(M[4-1][(4+j)-i]+16)]+=i*1.9;
			 //M[4-1][(4+j)-i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 14";
			 //return 1;
			 //}
			// else if(M[4-1][(4+j)-i]>0||((4+j)-i)<0){
			//	  i=-2;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 15";
			 //}
			//}
			//for(int i=1;i!=-1;i++){//right search
			 // if(M[4-1][(4+j)+i]<0&&((4+j)+i)<=8){
			 //M[4-1][(4+j)]=M[4-1][(4+j)+i];
			 //x11[(M[4-1][(4+j)+i]+16)]-=i*1.9;
			 //M[4-1][(4+j)+i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 16";
			 //return 1;
			 //}
			 //else if(M[4-1][(4+j)+i]>0||((4+j)+i)>8){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 17";
			 //}
	//	}
		//}
		//else if(M[4-1][4+j]<0 && M[4+1][4+j]==0){//----up else
		//	  for(int i=2;i!=-1;i++)//down search
			//  if(M[4+i][(4+j)]<0&&(4+i)<=8){
			  //M[4+1][(4+j)]=M[4+i][(4+j)];
			  //y11[(M[4+i][(4+j)]+16)]+=(i-1)*1.9;
			  //M[4+i][((4+j)-j)]=0;
			  //flag=4;
			  //cout<<"TB M[4]["<<4+j<<"]"<<" 18";
			  //return 1;
			  //}
			 // else if(M[4+i][(4+j)]>0||(4+i)>8){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 19";
			 // }
			//for(int i=1;i!=-1;i++){//left search
			 //if(M[4+1][(4+j)-i]<0&&((4+j)-i)>=0){
			 //M[4+1][(4+j)]=M[4+1][(4+j)-i];
			 //x11[(M[4+1][(4+j)-i]+16)]+=i*1.9;
			 //M[4+1][(4+j)-i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 20";
			 //return 1;
			 //}
			 //else if(M[4+1][(4+j)-i]>0||((4+j)-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 21";
			 //}
		//	}
			//for(int i=1;i!=-1;i++){//right search
			  //if(M[4+1][(4+j)+i]<0&&((4+-j)+i)<=8){
			 //M[4+1][(4+j)]=M[4+1][(4+j)+i];
			 //x11[(M[4+1][(4+j)+i]+16)]-=i*1.9;
			 //M[4+1][(4+j)+i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 22";
			 //return 1;
			 //}
			 //else if(M[4+1][(4+j)+i]>0||((4+j)+i)>8){
			///	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 23";
			// }
			//}
	/**///}
	//else//kole safheh
		}//end of if k==0
		else {
			if(M[k][(j)+1]<0 && M[k][(j)-1]==0&&((j)+1)<=8&&(j-1)>=0){
			for(int i=2;i!=-1;i++){//left search
			  if(M[k][(j)-i]<0&&(j)-i>=0){
			  M[k][(j)-1]=M[k][(j)-i];
			  x11[(M[k][(j)-i]+16)]+=(i-1)*1.9;
			  M[k][(j)-i]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[k][(j)-i]>0||((j)-i)<0){
				 i=-2; 
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[k-i][(j)-1]<0&&(k-i)>=0){
			 M[k][(j)-1]=M[k-i][(j)-1];
			 y11[(M[k-i][(j)-1]+16)]-=i*1.9;
			 M[k-i][(j)-1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 2";
			 return 1;
			 }
			 else if(M[k-i][(j)-1]>0||(k-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 3";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[k+i][(j)-1]<0&&(k+i)<=8){
			 M[k][(j)-1]=M[k+i][(j)-1];
			 y11[(M[k+i][(j)-1]+16)]+=i*1.9;
			 M[k+i][(j)-1]=0; 
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[k+i][(j)-1]>0||(k+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 5";
			 }
		}
		}
		else if(M[k][((j)-1)]<0 && M[k][(j)+1]==0&&((j)+1)<=8&&((j)-1)>=0){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[k][(j)+i]<0&&((j)+i)<=8){
			  M[k][(j)+1]=M[k][(j)+i];
			  x11[(M[k][(j)+i]+16)]-=(i-1)*1.9;
			  M[k][(j)+i]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[k][(j)+i]>0||((j)+i)>8){
				  i=-2;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[k-i][(j)+1]<0&&(k-i)>=0){
			 M[k][(j)+1]=M[k-i][(j)+1];
			 y11[(M[k-i][(j)+1]+16)]-=i*1.9;
			 M[k-i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 8";
			 return 1;
			 }
			 else if(M[k-i][(j)+1]>0||(k-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 9";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[k+i][(j)+1]<0&&(k+i)<=8){
			 M[k][(j)+1]=M[k+i][(j)+1];
			 y11[(M[k+i][(j)+1]+16)]+=i*1.9;
			 M[k+i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[k+i][(j)+1]>0||(k+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		if(M[k+1][(j)]<0 && M[k-1][(j)]==0&&!(k==3&&j==4)){
			for(int i=2;i!=-1;i++){//up search
			  if(M[k-i][(j)]<0&&k-i>=0){
			  M[k-1][(j)]=M[k-i][(j)];
			  y11[(M[k-i][(j)])+16]-=(i-1)*1.9;
			  M[k-i][(j)]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" 12";
			  return 1;
			  }
			  else if(M[k-i][(j)]>0||(k-i)<0){
				  i=-2;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 13";
			  }
			}
			for(int i=1;i!=-1;i++){//left search
			 if(M[k-1][(j)-i]<0&&((j)-i)>=0){
			 M[k-1][(j)]=M[k-1][(j)-i];
			 x11[(M[k-1][(j)-i]+16)]+=i*1.9;
			 M[k-1][(j)-i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 14";
			 return 1;
			 }
			 else if(M[k-1][(j)-i]>0||((j)-i)<0){
				  i=-2;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 15";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[k-1][(j)+i]<0&&((j)+i)<=8){
			 M[k-1][(j)]=M[k-1][(j)+i];
			 x11[(M[k-1][(j)+i]+16)]-=i*1.9;
			 M[k-1][(j)+i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 16";
			 return 1;
			 }
			 else if(M[k-1][(j)+i]>0||((j)+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 17";
			 }
		}
		}
		else if(M[k-1][j]<0 && M[k+1][j]==0&&(!((k+1)==4&&j==4))){//----up else
			  for(int i=2;i!=-1;i++)//down search
			  if(M[k+i][(j)]<0&&(k+i)<=8){
			  M[k+1][(j)]=M[k+i][(j)];
			  y11[(M[k+i][(j)]+16)]+=(i-1)*1.9;
			  M[k+i][j]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" 18";
			  return 1;
			  }
			  else if(M[k+i][(j)]>0||(k+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 19";
			  }
			for(int i=1;i!=-1;i++){//left search
			 if(M[k+1][(j)-i]<0&&((j)-i)>=0){
			 M[k+1][(j)]=M[k+1][(j)-i];
			 x11[(M[k+1][(j)-i]+16)]+=i*1.9;
			 M[k+1][(j)-i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 20";
			 return 1;
			 }
			 else if(M[k+1][(j)-i]>0||((j)-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 21";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[k+1][(j)+i]<0&&((j)+i)<=8){
			 M[k+1][(j)]=M[k+1][(j)+i];
			 x11[(M[k+1][(j)+i]+16)]-=i*1.9;
			 M[k+1][(j)+i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 22";
			 return 1;
			 }
			 else if(M[k+1][(j)+i]>0||((j)+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 23";
			 }
			}
	/**/}
		
		}//end of if k===0
		return 0;
	}//end of if M[k][j]==9
	
	}//end of for

	/*for(int k=0;k<=3;k++)
	for(int j=0;j<=8;j++){
		if(M[k][j]==9){
		if(k==0){
		if(M[k][(j)+1]<0 && M[k][(j)-1]==0&&((j)+1)<8&&((j)-1)>0){
			for(int i=2;i!=-1;i++){//left search
			  if(M[0][(j)-i]<0&&((j)-i)>=0){
			  M[0][(j)-1]=M[0][(j)-i];
			  x11[(M[0][(j)-i]+16)]+=(i-1)*1.9;
			  M[0][(j)-i]=0;
			  flag=4;
			  cout<<"TB M[0]["<<j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[0][(j)-i]>0||((j)-i)<0){
				 i=-2; 
			cout<<"TB M[0]["<<j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			//for(int i=1;i!=-1;i++){//up search
			 //if(M[4-i][(4+j)-1]<0&&(4-i)>=0){
			 //M[4][(4+j)-1]=M[4-i][(4+j)-1];
			 //y11[(M[4-i][(4+j)-1]+16)]-=i*1.9;
			 //M[4-i][(4+j)-1]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 2";
			 //return 1;
			 //}
			 //else if(M[4-i][(4+j)-1]>0||(4-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 3";
			// //}
			//}
			for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][(j)-1]<0&&(0+i)<=8){
			 M[0][(j)-1]=M[0+i][(j)-1];
			 y11[(M[0+i][(j)-1]+16)]+=i*1.9;
			 M[0+i][(j)-1]=0;
			 
			 flag=4;
			 cout<<"TB M[0]["<<j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[0+i][(j)-1]>0||(0+i)>8){
				  i=-2;
			cout<<"TB M[0]["<<j<<"]"<<" 5";
			 }
		}
		}
		else if(M[0][((j)-1)]<0 && M[4][(j)+1]==0&&((j)+1)<8&&(j-1)>0){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[0][(j)+i]<0&&((j)+i)<=8){
			  M[0][(j)+1]=M[0][(j)+i];
			  x11[(M[0][(j)+i]+16)]-=(i-1)*1.9;
			  M[0][(j)+i]=0;
			  flag=4;
			  cout<<"TB M[0]["<<j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[0][(j)+i]>0||((j)+i)>8){
				  i=-2;
			 cout<<"TB M[0]["<<j<<"]"<<" 7";
			  }
			  }
			//for(int i=1;i!=-1;i++){//up search
			 //if(M[0-i][(j)+1]<0&&(4-i)>=0){
			 //M[4][(4+j)+1]=M[4-i][(4+j)+1];
			 //y11[(M[4-i][(4+j)+1]+16)]-=i*1.9;
			 //M[4-i][(4+j)+1]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 8";
			 //return 1;
			 //}
			 //else if(M[4-i][(4+j)+1]>0||(4-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 9";
			 //}
			//}
			for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][(j)+1]<0&&(0+i)<=8){
			 M[0][(j)+1]=M[0+i][(j)+1];
			 y11[(M[0+i][(j)+1]+16)]+=i*1.9;
			 M[0+i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M[0]["<<j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[0+i][(j)+1]>0||(0+i)>8){
				  i=-2;
			cout<<"TB M[0]["<<j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		//if(M[0+1][(j)]<0 && M[0-1][(4+j)]==0){
			//for(int i=2;i!=-1;i++){//up search
			  //if(M[4-i][(4+j)]<0&&4-i>=0){
			 // M[4-1][(4+j)]=M[4-i][(4+j)];
			  //y11[(M[4-i][(4+j)])+16]-=(i-1)*1.9;
			  //M[4-i][(4+j)]=0;
			  //flag=4;
			  //cout<<"TB M[4]["<<4+j<<"]"<<" 12";
			  //return 1;
			  //}
			  //else if(M[4-i][(4+j)]>0||(4-i)<0){
			//	  i=-2;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 13";
			  //}
			//}
			//for(int i=1;i!=-1;i++){//left search
	//		 if(M[4-1][(4+j)-i]<0&&((4+j)-i)>=0){
		//	 M[4-1][(4+j)]=M[4-1][(4+j)-i];
			// x11[(M[4-1][(4+j)-i]+16)]+=i*1.9;
			 //M[4-1][(4+j)-i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 14";
			 //return 1;
			 //}
			// else if(M[4-1][(4+j)-i]>0||((4+j)-i)<0){
			//	  i=-2;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 15";
			 //}
			//}
			//for(int i=1;i!=-1;i++){//right search
			 // if(M[4-1][(4+j)+i]<0&&((4+j)+i)<=8){
			 //M[4-1][(4+j)]=M[4-1][(4+j)+i];
			 //x11[(M[4-1][(4+j)+i]+16)]-=i*1.9;
			 //M[4-1][(4+j)+i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 16";
			 //return 1;
			 //}
			 //else if(M[4-1][(4+j)+i]>0||((4+j)+i)>8){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 17";
			 //}
	//	}
		//}
		//else if(M[4-1][4+j]<0 && M[4+1][4+j]==0){//----up else
		//	  for(int i=2;i!=-1;i++)//down search
			//  if(M[4+i][(4+j)]<0&&(4+i)<=8){
			  //M[4+1][(4+j)]=M[4+i][(4+j)];
			  //y11[(M[4+i][(4+j)]+16)]+=(i-1)*1.9;
			  //M[4+i][((4+j)-j)]=0;
			  //flag=4;
			  //cout<<"TB M[4]["<<4+j<<"]"<<" 18";
			  //return 1;
			  //}
			 // else if(M[4+i][(4+j)]>0||(4+i)>8){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 19";
			 // }
			//for(int i=1;i!=-1;i++){//left search
			 //if(M[4+1][(4+j)-i]<0&&((4+j)-i)>=0){
			 //M[4+1][(4+j)]=M[4+1][(4+j)-i];
			 //x11[(M[4+1][(4+j)-i]+16)]+=i*1.9;
			 //M[4+1][(4+j)-i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 20";
			 //return 1;
			 //}
			 //else if(M[4+1][(4+j)-i]>0||((4+j)-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 21";
			 //}
		//	}
			//for(int i=1;i!=-1;i++){//right search
			  //if(M[4+1][(4+j)+i]<0&&((4+-j)+i)<=8){
			 //M[4+1][(4+j)]=M[4+1][(4+j)+i];
			 //x11[(M[4+1][(4+j)+i]+16)]-=i*1.9;
			 //M[4+1][(4+j)+i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 22";
			 //return 1;
			 //}
			 //else if(M[4+1][(4+j)+i]>0||((4+j)+i)>8){
			///	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 23";
			// }
			//}
	/**///}
	//else//kole safheh
	/*	}
		else {
			if(M[k][(j)+1]<0 && M[k][(j)-1]==0&&((j)+1)<=8&&(j-1)>=0){
			for(int i=2;i!=-1;i++){//left search
			  if(M[k][(j)-i]<0&&(j)-i>=0){
			  M[k][(j)-1]=M[k][(j)-i];
			  x11[(M[k][(j)-i]+16)]+=(i-1)*1.9;
			  M[k][(j)-i]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[k][(j)-i]>0||((j)-i)<0){
				 i=-2; 
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[k-i][(j)-1]<0&&(k-i)>=0){
			 M[k][(j)-1]=M[k-i][(j)-1];
			 y11[(M[k-i][(j)-1]+16)]-=i*1.9;
			 M[k-i][(j)-1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 2";
			 return 1;
			 }
			 else if(M[k-i][(4+j)-1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 3";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][(4+j)-1]<0&&(4+i)<=8){
			 M[4][(4+j)-1]=M[4+i][(4+j)-1];
			 y11[(M[4+i][(4+j)-1]+16)]+=i*1.9;
			 M[4+i][(4+j)-1]=0;
			 
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[4+i][(4+j)-1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 5";
			 }
		}
		}
		else if(M[4][((4+j)-1)]<0 && M[4][(4+j)+1]==0&&((4+j)+1)<8){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[4][(4+j)+i]<0&&((4+j)+i)<=8){
			  M[4][(4+j)+1]=M[4][(4+j)+i];
			  x11[(M[4][(4+j)+i]+16)]-=(i-1)*1.9;
			  M[4][(4+j)+i]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[4][(4+j)+i]>0||((4+j)+i)>8){
				  i=-2;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[4-i][(4+j)+1]<0&&(4-i)>=0){
			 M[4][(4+j)+1]=M[4-i][(4+j)+1];
			 y11[(M[4-i][(4+j)+1]+16)]-=i*1.9;
			 M[4-i][(4+j)+1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 8";
			 return 1;
			 }
			 else if(M[4-i][(4+j)+1]>0||(4-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 9";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[4+i][(4+j)+1]<0&&(4+i)<=8){
			 M[4][(4+j)+1]=M[4+i][(4+j)+1];
			 y11[(M[4+i][(4+j)+1]+16)]+=i*1.9;
			 M[4+i][(4+j)+1]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[4+i][(4+j)+1]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		if(M[4+1][(4+j)]<0 && M[4-1][(4+j)]==0){
			for(int i=2;i!=-1;i++){//up search
			  if(M[4-i][(4+j)]<0&&4-i>=0){
			  M[4-1][(4+j)]=M[4-i][(4+j)];
			  y11[(M[4-i][(4+j)])+16]-=(i-1)*1.9;
			  M[4-i][(4+j)]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" 12";
			  return 1;
			  }
			  else if(M[4-i][(4+j)]>0||(4-i)<0){
				  i=-2;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 13";
			  }
			}
			for(int i=1;i!=-1;i++){//left search
			 if(M[4-1][(4+j)-i]<0&&((4+j)-i)>=0){
			 M[4-1][(4+j)]=M[4-1][(4+j)-i];
			 x11[(M[4-1][(4+j)-i]+16)]+=i*1.9;
			 M[4-1][(4+j)-i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 14";
			 return 1;
			 }
			 else if(M[4-1][(4+j)-i]>0||((4+j)-i)<0){
				  i=-2;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 15";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[4-1][(4+j)+i]<0&&((4+j)+i)<=8){
			 M[4-1][(4+j)]=M[4-1][(4+j)+i];
			 x11[(M[4-1][(4+j)+i]+16)]-=i*1.9;
			 M[4-1][(4+j)+i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 16";
			 return 1;
			 }
			 else if(M[4-1][(4+j)+i]>0||((4+j)+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 17";
			 }
		}
		}
		else if(M[k-1][j]<0 && M[k+1][j]==0&&(!((k+1)==4&&j==4))){//----up else
			  for(int i=2;i!=-1;i++)//down search
			  if(M[4+i][(4+j)]<0&&(4+i)<=8){
			  M[4+1][(4+j)]=M[4+i][(4+j)];
			  y11[(M[4+i][(4+j)]+16)]+=(i-1)*1.9;
			  M[4+i][((4+j)-j)]=0;
			  flag=4;
			  cout<<"TB M[4]["<<4+j<<"]"<<" 18";
			  return 1;
			  }
			  else if(M[4+i][(4+j)]>0||(4+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 19";
			  }
			for(int i=1;i!=-1;i++){//left search
			 if(M[4+1][(4+j)-i]<0&&((4+j)-i)>=0){
			 M[4+1][(4+j)]=M[4+1][(4+j)-i];
			 x11[(M[4+1][(4+j)-i]+16)]+=i*1.9;
			 M[4+1][(4+j)-i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 20";
			 return 1;
			 }
			 else if(M[4+1][(4+j)-i]>0||((4+j)-i)<0){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 21";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[k+1][(j)+i]<0&&((j)+i)<=8){
			 M[k+1][(j)]=M[k+1][(j)+i];
			 x11[(M[k+1][(j)+i]+16)]-=i*1.9;
			 M[k+1][(j)+i]=0;
			 flag=4;
			 cout<<"TB M[4]["<<4+j<<"]"<<" 22";
			 return 1;
			 }
			 else if(M[4+1][(4+j)+i]>0||((4+j)+i)>8){
				  i=-2;
			cout<<"TB M[4]["<<4+j<<"]"<<" 23";
			 }
			}
	///**///}
		
	//	}
	//	return 0;
//	}<--------------delet
			//4 raw second
for(int k=5;k<=8;k++)
	for(int j=0;j<=8;j++){
		if(M[k][j]==9){
		if(k==8){
		if(M[k][(j)+1]<0 && M[k][(j)-1]==0&&((j)+1)<8&&((j)-1)>0){
			for(int i=2;i!=-1;i++){//left search
			  if(M[8][(j)-i]<0&&((j)-i)>=0){
			  M[8][(j)-1]=M[8][(j)-i];
			  x11[(M[8][(j)-i]+16)]+=(i-1)*1.9;
			  M[8][(j)-i]=0;
			  flag=4;
			  cout<<"TB M[8]["<<j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[8][(j)-i]>0||((j)-i)<0){
				 i=-2; 
			cout<<"TB M[8]["<<j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[8-i][(j)-1]<0&&(8-i)>=0){
			 M[8][(j)-1]=M[8-i][(j)-1];
			 y11[(M[8-i][(j)-1]+16)]-=i*1.9;
			 M[8-i][(j)-1]=0;
			 flag=4;
			 cout<<"TB M[8]["<<j<<"]"<<" 2";
			 return 1;
			 }
			 else if(M[8-i][(j)-1]>0||(8-i)<0){
				  i=-2;
			cout<<"TB M[8]["<<j<<"]"<<" 3";
			 }
			}
			//for(int i=1;i!=-1;i++){//down search
			//  if(M[0+i][(j)-1]<0&&(0+i)<=8){
			// M[0][(j)-1]=M[0+i][(j)-1];
			// y11[(M[0+i][(j)-1]+16)]+=i*1.9;
			// M[0+i][(j)-1]=0;
			 
			// flag=4;
			// cout<<"TB M[0]["<<j<<"]"<<" 4";
			// return 1;
			// }
			// else if(M[0+i][(j)-1]>0||(0+i)>8){
			//	  i=-2;
			//cout<<"TB M[0]["<<j<<"]"<<" 5";
			// }
		//}
		}
		else if(M[8][((j)-1)]<0 && M[8][(j)+1]==0&&((j)+1)<8&&(j-1)>0){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[8][(j)+i]<0&&((j)+i)<=8){
			  M[8][(j)+1]=M[8][(j)+i];
			  x11[(M[8][(j)+i]+16)]-=(i-1)*1.9;
			  M[8][(j)+i]=0;
			  flag=4;
			  cout<<"TB M[8]["<<j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[8][(j)+i]>0||((j)+i)>8){
				  i=-2;
			 cout<<"TB M[8]["<<j<<"]"<<" 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[8-i][(j)+1]<0&&(8-i)>=0){
			 M[8][(j)+1]=M[8-i][(j)+1];
			 y11[(M[8-i][(j)+1]+16)]-=i*1.9;
			 M[8-i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M[8]["<<j<<"]"<<" 8";
			 return 1;
			 }
			 else if(M[8-i][(j)+1]>0||(8-i)<0){
				  i=-2;
			cout<<"TB M[8]["<<j<<"]"<<" 9";
			 }
			}
			//for(int i=1;i!=-1;i++){//down search
			//  if(M[0+i][(j)+1]<0&&(0+i)<=8){
			// M[0][(j)+1]=M[0+i][(j)+1];
			// y11[(M[0+i][(j)+1]+16)]+=i*1.9;
			// M[0+i][(j)+1]=0;
			// flag=4;
			 //cout<<"TB M[0]["<<j<<"]"<<" 10";
			 //return 1;
			// }
			// else if(M[0+i][(j)+1]>0||(0+i)>8){
			//	  i=-2;
			//cout<<"TB M[0]["<<j<<"]"<<" 11";
		   // }
		//}
		}
			//--------------------------------up and down
		//if(M[0+1][(j)]<0 && M[0-1][(4+j)]==0){
			//for(int i=2;i!=-1;i++){//up search
			  //if(M[4-i][(4+j)]<0&&4-i>=0){
			 // M[4-1][(4+j)]=M[4-i][(4+j)];
			  //y11[(M[4-i][(4+j)])+16]-=(i-1)*1.9;
			  //M[4-i][(4+j)]=0;
			  //flag=4;
			  //cout<<"TB M[4]["<<4+j<<"]"<<" 12";
			  //return 1;
			  //}
			  //else if(M[4-i][(4+j)]>0||(4-i)<0){
			//	  i=-2;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 13";
			  //}
			//}
			//for(int i=1;i!=-1;i++){//left search
	//		 if(M[4-1][(4+j)-i]<0&&((4+j)-i)>=0){
		//	 M[4-1][(4+j)]=M[4-1][(4+j)-i];
			// x11[(M[4-1][(4+j)-i]+16)]+=i*1.9;
			 //M[4-1][(4+j)-i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 14";
			 //return 1;
			 //}
			// else if(M[4-1][(4+j)-i]>0||((4+j)-i)<0){
			//	  i=-2;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 15";
			 //}
			//}
			//for(int i=1;i!=-1;i++){//right search
			 // if(M[4-1][(4+j)+i]<0&&((4+j)+i)<=8){
			 //M[4-1][(4+j)]=M[4-1][(4+j)+i];
			 //x11[(M[4-1][(4+j)+i]+16)]-=i*1.9;
			 //M[4-1][(4+j)+i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 16";
			 //return 1;
			 //}
			 //else if(M[4-1][(4+j)+i]>0||((4+j)+i)>8){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 17";
			 //}
	//	}
		//}
		//else if(M[4-1][4+j]<0 && M[4+1][4+j]==0){//----up else
		//	  for(int i=2;i!=-1;i++)//down search
			//  if(M[4+i][(4+j)]<0&&(4+i)<=8){
			  //M[4+1][(4+j)]=M[4+i][(4+j)];
			  //y11[(M[4+i][(4+j)]+16)]+=(i-1)*1.9;
			  //M[4+i][((4+j)-j)]=0;
			  //flag=4;
			  //cout<<"TB M[4]["<<4+j<<"]"<<" 18";
			  //return 1;
			  //}
			 // else if(M[4+i][(4+j)]>0||(4+i)>8){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 19";
			 // }
			//for(int i=1;i!=-1;i++){//left search
			 //if(M[4+1][(4+j)-i]<0&&((4+j)-i)>=0){
			 //M[4+1][(4+j)]=M[4+1][(4+j)-i];
			 //x11[(M[4+1][(4+j)-i]+16)]+=i*1.9;
			 //M[4+1][(4+j)-i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 20";
			 //return 1;
			 //}
			 //else if(M[4+1][(4+j)-i]>0||((4+j)-i)<0){
			//	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 21";
			 //}
		//	}
			//for(int i=1;i!=-1;i++){//right search
			  //if(M[4+1][(4+j)+i]<0&&((4+-j)+i)<=8){
			 //M[4+1][(4+j)]=M[4+1][(4+j)+i];
			 //x11[(M[4+1][(4+j)+i]+16)]-=i*1.9;
			 //M[4+1][(4+j)+i]=0;
			 //flag=4;
			 //cout<<"TB M[4]["<<4+j<<"]"<<" 22";
			 //return 1;
			 //}
			 //else if(M[4+1][(4+j)+i]>0||((4+j)+i)>8){
			///	  i=-2;
			//cout<<"TB M[4]["<<4+j<<"]"<<" 23";
			// }
			//}
	/**///}
	//else//kole safheh
		}//if k==8
		else {
			if(M[k][(j)+1]<0 && M[k][(j)-1]==0&&((j)+1)<=8&&(j-1)>=0){
			for(int i=2;i!=-1;i++){//left search
			  if(M[k][(j)-i]<0&&(j)-i>=0){
			  M[k][(j)-1]=M[k][(j)-i];
			  x11[(M[k][(j)-i]+16)]+=(i-1)*1.9;
			  M[k][(j)-i]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" ";
			  return 1;
			  
			  }
			  else if(M[k][(j)-i]>0||((j)-i)<0){
				 i=-2; 
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 1";
			  }
			}
		
			//i=0;
			for(int i=1;i!=-1;i++){//up search
			 if(M[k-i][(j)-1]<0&&(k-i)>=0){
			 M[k][(j)-1]=M[k-i][(j)-1];
			 y11[(M[k-i][(j)-1]+16)]-=i*1.9;
			 M[k-i][(j)-1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 2";
			 return 1;
			 }
			 else if(M[k-i][(j)-1]>0||(k-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 3";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[k+i][(j)-1]<0&&(k+i)<=8){
			 M[k][(j)-1]=M[k+i][(j)-1];
			 y11[(M[k+i][(j)-1]+16)]+=i*1.9;
			 M[k+i][(j)-1]=0; 
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 4";
			 return 1;
			 }
			 else if(M[k+i][(j)-1]>0||(k+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 5";
			 }
		}
		}
		else if(M[k][((j)-1)]<0 && M[k][(j)+1]==0&&((j)+1)<=8&&((j)-1)>=0){//----left else
			  for(int i=2;i!=-1;i++){//right search
			  if(M[k][(j)+i]<0&&((j)+i)<=8){
			  M[k][(j)+1]=M[k][(j)+i];
			  x11[(M[k][(j)+i]+16)]-=(i-1)*1.9;
			  M[k][(j)+i]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" 6";
			  return 1;
			  }
			  else if(M[k][(j)+i]>0||((j)+i)>8){
				  i=-2;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 7";
			  }
			  }
			for(int i=1;i!=-1;i++){//up search
			 if(M[k-i][(j)+1]<0&&(k-i)>=0){
			 M[k][(j)+1]=M[k-i][(j)+1];
			 y11[(M[k-i][(j)+1]+16)]-=i*1.9;
			 M[k-i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 8";
			 return 1;
			 }
			 else if(M[k-i][(j)+1]>0||(k-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 9";
			 }
			}
			for(int i=1;i!=-1;i++){//down search
			  if(M[k+i][(j)+1]<0&&(k+i)<=8){
			 M[k][(j)+1]=M[k+i][(j)+1];
			 y11[(M[k+i][(j)+1]+16)]+=i*1.9;
			 M[k+i][(j)+1]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 10";
			 return 1;
			 }
			 else if(M[k+i][(j)+1]>0||(k+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 11";
		    }
		}
		}
			//--------------------------------up and down
		if(M[k+1][(j)]<0 && M[k-1][(j)]==0&&(!((k-1)==4&&j==4))){
			for(int i=2;i!=-1;i++){//up search
			  if(M[k-i][(j)]<0&&k-i>=0){
			  M[k-1][(j)]=M[k-i][(j)];
			  y11[(M[k-i][(j)])+16]-=(i-1)*1.9;
			  M[k-i][(j)]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" 12";
			  return 1;
			  }
			  else if(M[k-i][(j)]>0||(k-i)<0){
				  i=-2;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 13";
			  }
			}
			for(int i=1;i!=-1;i++){//left search
			 if(M[k-1][(j)-i]<0&&((j)-i)>=0){
			 M[k-1][(j)]=M[k-1][(j)-i];
			 x11[(M[k-1][(j)-i]+16)]+=i*1.9;
			 M[k-1][(j)-i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 14";
			 return 1;
			 }
			 else if(M[k-1][(j)-i]>0||((j)-i)<0){
				  i=-2;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 15";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[k-1][(j)+i]<0&&((j)+i)<=8){
			 M[k-1][(j)]=M[k-1][(j)+i];
			 x11[(M[k-1][(j)+i]+16)]-=i*1.9;
			 M[k-1][(j)+i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 16";
			 return 1;
			 }
			 else if(M[k-1][(j)+i]>0||((j)+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 17";
			 }
		}
		}
		else if(M[k-1][j]<0 && M[k+1][j]==0&&!(k==5&&j==4)){//----up else
			  for(int i=2;i!=-1;i++)//down search
			  if(M[k+i][(j)]<0&&(k+i)<=8){
			  M[k+1][(j)]=M[k+i][(j)];
			  y11[(M[k+i][(j)]+16)]+=(i-1)*1.9;
			  M[k+i][j]=0;
			  flag=4;
			  cout<<"TB M["<<k<<"]["<<j<<"]"<<" 18";
			  return 1;
			  }
			  else if(M[k+i][(j)]>0||(k+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 19";
			  }
			for(int i=1;i!=-1;i++){//left search
			 if(M[k+1][(j)-i]<0&&((j)-i)>=0){
			 M[k+1][(j)]=M[k+1][(j)-i];
			 x11[(M[k+1][(j)-i]+16)]+=i*1.9;
			 M[k+1][(j)-i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 20";
			 return 1;
			 }
			 else if(M[k+1][(j)-i]>0||((j)-i)<0){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 21";
			 }
			}
			for(int i=1;i!=-1;i++){//right search
			  if(M[k+1][(j)+i]<0&&((j)+i)<=8){
			 M[k+1][(j)]=M[k+1][(j)+i];
			 x11[(M[k+1][(j)+i]+16)]-=i*1.9;
			 M[k+1][(j)+i]=0;
			 flag=4;
			 cout<<"TB M["<<k<<"]["<<j<<"]"<<" 22";
			 return 1;
			 }
			 else if(M[k+1][(j)+i]>0||((j)+i)>8){
				  i=-2;
			cout<<"TB M["<<k<<"]["<<j<<"]"<<" 23";
			 }
			}
	/**/}
		
		}//else of if k==8
		return 0;
	}//end of M[k][j]==9
	
	}//----------------- end of 4 row second
//return 0;
}

bool TD(){//tasavi distance
srand(time(0));
int a2=20,b2=20,c2=20,d2=20,a3=20,b3=20,c3=20,d3=20,min=0,x=0,y=0,j=0,k=-1,r=0;
int b[4]={0};
bool a[8]={0};

	if(M[4][4]!=9){
	for(int i=0;i<=8;i++)
		for(int j=0;j<=8;j++)
			if(M[i][j]==9){
			x=i;
			y=j;
			}

	if(LM2[x][y]==0&&LM[x][y]==9&&x!=0&&x!=8&&y!=0&&y!=8&&!(x==1&&y==1)&&!(x==1&&y==7)&&!(x==7&&y==1)&&!(x==7&&y==7)){
		
		if(zs(x-1,y,0,y)){//up
		if(zs(0,y,0,1)){
		a[1]=1;
		a2=ds(0,y,0,0);
		cout<<a2;
		cout<<"a1"<<a[1];
		}
		if(zs(0,y,0,7)){
		a[2]=1;
		cout<<"HHHHHHHHHHHHHHHHHHHHH";
		b2=ds(0,y,0,8);
		}
		}
		//-----------------
		if(zs(x,y+1,x,8)){//right
		if(zs(x,8,1,8)){
			if(a[2]==0&&a[3]==0){
			a[3]=1;
			b2=ds(x,8,0,8);
			}
			else if((ds(x,8,0,8))<b2){
			a[2]=0;
			a[3]=1;
			b2=ds(x,8,0,8);
			}
		}
		if(zs(x,8,7,8)){
		a[4]=1;
		c2=ds(x,8,8,8);
		}
		}
		//-----------------
		if(zs(x+1,y,8,y)){//down
		if(zs(8,y,8,7)){
			if(a[4]==0&&a[5]==0){
			a[5]=1;
			c2=ds(8,y,8,8);
			}
			else if((ds(8,y,8,8))<c2){
			a[4]=0;
			a[5]=1;
			c2=ds(8,y,8,8);
			}
		}
		if(zs(8,y,8,1)){
		a[6]=1;
		d2=ds(8,y,8,0);
		cout<<d2;
		cout<<"a6:"<<a[6];
		}
		}
		//----------------
		if(zs(x,y-1,x,0)){//left
		if(zs(x,0,1,0)){
			if(a[0]==0&&a[1]==0){
			a[0]=1;
			a2=ds(x,0,0,8);
			}
			else if((ds(x,0,0,8))<a2){
			a[1]=0;
			a[0]=1;
			a2=ds(x,0,0,8);
			}
		}
		if(zs(x,0,7,0)){//-->>>
		if(a[6]==0&&a[7]==0){
			a[7]=1;
			d2=ds(x,0,8,0);
			}
			else if((ds(x,8,0,8))<d2){
			a[6]=0;
			a[7]=1;
			d2=ds(x,8,0,8);
			}
		}
		}
		//-----------------
	    min=minimum(a2,b2,c2,d2,20,20);
		cout<<"MIIIIIIIIIIIIIIIIIIIIIN:"<<min<<"    tiy        ";
		if(min==0||min==20)
			return 0;
		if(a2==min){
		b[0]=1;
		cout<<b[0];
		j++;
		}
		if(b2==min){
		b[1]=1;
		cout<<b[1];
		j++;
		}
		if(c2==min){
		b[2]=1;
		j++;
		}
		if(d2==min){
		b[3]=1;
		cout<<b[3];
		j++;
		}
		if(j>1){
			cout<<j;
			for(int i=0;i<=3&&j!=0;i++){
				if(b[i]==1){
					j--;
					if(i==0){
					a3=0;
					if(M[2][0]<0)
						a3++;
					if(M[1][1]<0)
						a3++;
					if(M[0][2]<0)
						a3++;
					cout<<"a3:"<<a3;
					}
					if(i==1){
					b3=0;
					if(M[0][6]<0)
						b3++;
					if(M[1][7]<0)
						b3++;
					if(M[2][8]<0)
						b3++;
					cout<<"b3:"<<b3;
					}
					if(i==2){
					c3=0;
					if(M[6][8]<0)
						c3++;
					if(M[7][7]<0)
						c3++;
					if(M[8][6]<0)
						c3++;
					cout<<"c3:"<<c3;
					}
					if(i==3){
					d3=0;
					if(M[8][2]<0)
						d3++;
					if(M[7][1]<0)
						d3++;
					if(M[6][0]<0)
						d3++;
					cout<<"d3:"<<d3;
					}
					cout<<"J:"<<j;
				}
			}

		min=minimum(a3,b3,c3,d3,20,20);
		cout<<"min:"<<min;
		for(int i=0;i<=3;i++)
			b[i]=0;
		if(a3==min){
		k++;
		b[k]=1;
		cout<<"k1:"<<k;
		cout<<"b[k]:"<<b[k];
		}
		if(b3==min){
		k++;
		b[k]=2;
		cout<<"k2:"<<k;
		cout<<"b[k]:"<<b[k];
		}
		if(c3==min){
		k++;
		b[k]=3;
		cout<<"k3:"<<k;
		cout<<"b[k]:"<<b[k];
		}
		if(d3==min){
		k++;
		b[k]=4;
		cout<<"k4:"<<k;
		cout<<"b[k]:"<<b[k];
		}
		if(k>0){
		r=rand()%(k+1);
		if(b[r]==1){
			if(a[0]==1){
				if(ns(2,0,1,0))
					return 1;
				if(ns(2,0,5,0))
					return 1;
				if(ns(2,0,2,7))
					return 1;
						}
			if(a[1]==1){
				if(ns(0,2,0,1))
					return 1;
				if(ns(0,2,0,5))
					return 1;
				if(ns(0,2,7,2))
					return 1;
						}

		}
		//--------------------
		if(b[r]==2){
			if(a[2]==1){
				if(ns(0,6,0,7))
					return 1;
				if(ns(0,6,0,3))
					return 1;
				if(ns(0,6,7,6))
					return 1;
						}
			if(a[3]==1){
				if(ns(2,8,1,8))
					return 1;
				if(ns(2,8,5,8))
					return 1;
				if(ns(2,8,2,1))
					return 1;
						}
		}
		//--------------------------
			if(b[r]==3){
			if(a[4]==1){
				if(ns(6,8,7,8))
					return 1;
				if(ns(6,8,3,8))
					return 1;
				if(ns(6,8,6,1))
					return 1;
						}
				if(a[5]==1){
					if(ns(8,6,8,7))
						return 1;
					if(ns(8,6,8,3))
						return 1;
					if(ns(8,6,1,6))
						return 1;
						}
		}
		//--------------------------
			if(b[r]==4){
              if(a[6]==1){
				if(ns(8,2,8,7))
					return 1;
				if(ns(8,2,8,5))
					return 1;
				if(ns(8,2,1,2))
					return 1;
						}
			   if(a[7]==1){
				 if(ns(6,0,7,0))
					 return 1;
				if(ns(6,0,3,0))
					return 1;
				if(ns(6,0,6,7))
					return 1;
						}
		}


		}
		else if(k==0){
			if(b[0]==1){
			if(a[0]==1){
				if(ns(2,0,1,0))
					return 1;
				if(ns(2,0,5,0))
					return 1;
				if(ns(2,0,2,7))
					return 1;
						}
			if(a[1]==1){
				if(ns(0,2,0,1))
					return 1;
				if(ns(0,2,0,5))
					return 1;
				if(ns(0,2,7,2))
					return 1;
						}

		}
		//--------------------
		if(b[0]==2){
			if(a[2]==1){
				if(ns(0,6,0,7))
					return 1;
				if(ns(0,6,0,3))
					return 1;
				if(ns(0,6,7,6))
					return 1;
						}
			if(a[3]==1){
				if(ns(2,8,1,8))
					return 1;
				if(ns(2,8,5,8))
					return 1;
				if(ns(2,8,2,1))
					return 1;
						}
		}
		//--------------------------
			if(b[0]==3){
			if(a[4]==1){
				if(ns(6,8,7,8))
					return 1;
				if(ns(6,8,3,8))
					return 1;
				if(ns(6,8,6,1))
					return 1;
						}
				if(a[5]==1){
					if(ns(8,6,8,7))
						return 1;
					if(ns(8,6,8,3))
						return 1;
					if(ns(8,6,1,6))
						return 1;
						}
		}
		//--------------------------
			if(b[0]==4){
				cout<<"YYYYYYYY";
				for(int i=0;i<=7;i++)
					cout<<"a["<<i<<"]"<<a[i];
              if(a[6]==1){
				if(ns(8,2,8,7))
					return 1;
				if(ns(8,2,8,5))
					return 1;
				if(ns(8,2,1,2))
					return 1;
						}
			   if(a[7]==1){
				 if(ns(6,0,7,0))
					 return 1;
				if(ns(6,0,3,0))
					return 1;
				if(ns(6,0,6,7))
					return 1;
						}
		}
		
		}



		}//end j>1
		else if(j==1){
			for(int i=0;i<=3&&i!=-1;i++)
				if(b[i]==1){

					if(i==0&&a2==1){
						if(a[0]==1){
							if(ns(2,0,1,0))
								return 1;
							if(ns(2,0,5,0))
								return 1;
						}
						if(a[1]==1){
							if(ns(0,2,0,1))
								return 1;
							if(ns(0,2,0,5))
								return 1;
						}
					}
					//---------------------
				if(i==1&&b2==1){
						if(a[2]==1){
							if(ns(0,6,0,7))
								return 1;
							if(ns(0,6,0,3))
								return 1;
						}
						if(a[3]==1){
							if(ns(2,8,1,8))
								return 1;
							if(ns(2,8,5,8))
								return 1;
						}
					}
				//--------------------------
				if(i==2&&c2==1){
						if(a[4]==1){
							if(ns(6,8,7,8))
								return 1;
							if(ns(6,8,3,8))
								return 1;
						}
						if(a[5]==1){
							if(ns(8,6,8,7))
								return 1;
							if(ns(8,6,8,3))
								return 1;
						}
					}
				//-----------------------------
				if(i==3&&d2==1){
						if(a[6]==1){
							if(ns(8,2,8,7))
								return 1;
							if(ns(8,2,8,5))
								return 1;
						}
						if(a[7]==1){
							if(ns(6,0,7,0))
								return 1;
							if(ns(6,0,3,0))
								return 1;
						}
					}

				i=-2;
				}
		
		}//end of else if(j==1){


	}


	}//end of M[4][4]!=9
	return 0;
}

bool MB(){
static int g=0;
int a=0,b=0;
if(g==0 && M[4][4+1]==9 ){//M[4][4+1]==9
	if(M[1][7]==0&&M[7][7]!=0){//M[7][7] have manfi or sefid 
		for(int i=1;i!=-1;i++){//left search
			  if(M[1][7-i]<0&&(7-i)>=0){
			  M[1][7]=M[1][7-i];
			  x11[(M[1][7-i]+16)]+=i*1.9;
			  M[1][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[1][7] \n";
			  return 1;
			  
			  }
			  else if(M[1][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[1][7] 1\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][7]<0&&(1+i)<=8){
			 M[1][7]=M[1+i][7];
			 y11[(M[1+i][7]+16)]+=i*1.9;
			 M[1+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[1][7] 2\n";
			 return 1;
			 }
			 else if(M[1+i][7]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[1][7] 3\n";
			 }
		}

		if(M[0][7]<0){
		M[1][7]=M[0][7];
		y11[(M[0][7])]-=1.9;
		M[0][7]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[1][7] 4\n";
		return 1;
		}

		if(M[1][8]<0){
		M[1][7]=M[1][8];
		x11[(M[1][8])]-=1.9;
		M[1][8]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[1][7] 5\n";
		return 1;
		}
	}

	if(M[7][7]==0&&M[1][7]!=0){//M[1][7] have manfi or sefid 
		for(int i=1;i!=-1;i++){//left search
			  if(M[7][7-i]<0&&(7-i)>=0){
			  M[7][7]=M[7][7-i];
			  x11[(M[7][7-i]+16)]+=i*1.9;
			  M[7][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[7][7] \n";
			  return 1;
			  
			  }
			  else if(M[7][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[7][7] 1\n";
			  }
			}
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][7]<0&&(7-i)>=0){
			 M[7][7]=M[7-i][7];
			 y11[(M[7-i][7]+16)]-=i*1.9;
			 M[7-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[7][7] 2\n";
			 return 1;
			 }
			 else if(M[7-i][7]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[7][7] 3\n";
			 }
		}

		if(M[8][7]<0){
		M[7][7]=M[8][7];
		y11[(M[8][7])]+=1.9;
		M[8][7]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[7][7] 4\n";
		return 1;
		}

		if(M[7][8]<0){
		M[7][7]=M[7][8];
		x11[(M[7][8])]-=1.9;
		M[7][8]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[7][7] 5\n";
		return 1;
		}
	}//end of M[1][7] have manfi or sefid

	if(M[7][7]==0&&M[1][7]==0){//har do khali
	int i=0,j=0;
	if(M[0][6]<0)
		i++;
	if(M[2][8]<0)
		i++;
	if(M[8][6]<0)
		j++;
	if(M[6][8]<0)
		j++;
	if(i<j){
	for(int i=1;i!=-1;i++){//left search
			  if(M[1][7-i]<0&&(7-i)>=0){
			  M[1][7]=M[1][7-i];
			  x11[(M[1][7-i]+16)]+=i*1.9;
			  M[1][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[1][7] i<j\n";
			  return 1;
			  
			  }
			  else if(M[1][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[1][7] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][7]<0&&(1+i)<=8){
			 M[1][7]=M[1+i][7];
			 y11[(M[1+i][7]+16)]+=i*1.9;
			 M[1+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[1][7] 2 i<j\n";
			 return 1;
			 }
			 else if(M[1+i][7]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[1][7] 3 i<j\n";
			 }
		}

		if(M[0][7]<0){
		M[1][7]=M[0][7];
		y11[(M[0][7])]-=1.9;
		M[0][7]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[1][7] 4 i<j\n";
		return 1;
		}

		if(M[1][8]<0){
		M[1][7]=M[1][8];
		x11[(M[1][8])]-=1.9;
		M[1][8]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[1][7] 5 i<j\n";
		return 1;
		}
	
	}
	else{
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][7-i]<0&&(7-i)>=0){
			  M[7][7]=M[7][7-i];
			  x11[(M[7][7-i]+16)]+=i*1.9;
			  M[7][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[7][7] i>j\n ";
			  return 1;
			  
			  }
			  else if(M[7][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[7][7] 1 i>j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][7]<0&&(7-i)>=0){
			 M[7][7]=M[7-i][7];
			 y11[(M[7-i][7]+16)]-=i*1.9;
			 M[7-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[7][7] 2 i>j\n";
			 return 1;
			 }
			 else if(M[7-i][7]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[7][7] 3 i>j\n";
			 }
		}

		if(M[8][7]<0){
		M[7][7]=M[8][7];
		y11[(M[8][7])]+=1.9;
		M[8][7]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[7][7] 4 i>j\n";
		return 1;
		}

		if(M[7][8]<0){
		M[7][7]=M[7][8];
		x11[(M[7][8])]-=1.9;
		M[7][8]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[7][7] 5 i>j\n";
		return 1;
		}
	}
	}

	if(M[7][7]<0&&M[1][7]<0){//har do manfi
	int i=0,j=0;
	if(M[0][6]<0)
		i++;
	if(M[2][8]<0)
		i++;
	if(M[8][6]<0)
		j++;
	if(M[6][8]<0)
		j++;
	if(i<j){
		if(M[0][6]==0){
		for(int i=1;i!=-1;i++){//left search
			  if(M[0][6-i]<0&&(6-i)>=0){
			  M[0][6]=M[0][6-i];
			  x11[(M[0][6-i]+16)]+=i*1.9;
			  M[0][6-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[0][6] i<j\n";
			  return 1;
			  
			  }
			  else if(M[0][6-i]>0||(6-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[0][6] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=8){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[0][6] 2 i<j\n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[0][6] 3 i<j\n";
			 }
		}

		if(M[0][7]<0){
		M[0][6]=M[0][7];
		x11[(M[0][7])]-=1.9;
		M[0][7]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[0][6] 4 i<j\n";
		return 1;
		}
		}
		if(M[2][8]==0){
			for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=0){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[2][8] i<j\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[2][8] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[2+i][8]<0&&(2+i)<=8){
			 M[2][8]=M[2+i][8];
			 y11[(M[2+i][8]+16)]+=i*1.9;
			 M[2+i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[2][8] 2 i<j\n";
			 return 1;
			 }
			 else if(M[2+i][8]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[2][8] 3 i<j\n";
			 }
		}

		if(M[1][8]<0){
		M[2][8]=M[1][8];
		y11[(M[1][8])]-=1.9;
		M[1][8]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[2][8] 4 i<j\n";
		return 1;
		}
		
		}

	}
	else{
		if(M[8][6]==0){
		for(int i=1;i!=-1;i++){//left search
			  if(M[8][6-i]<0&&(6-i)>=0){
			  M[8][6]=M[8][6-i];
			  x11[(M[8][6-i]+16)]+=i*1.9;
			  M[8][6-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[8][6] i>j\n";
			  return 1;
			  
			  }
			  else if(M[8][6-i]>0||(6-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[8][6] 1 i>j\n";
			  }
			}

		
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=0){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[8][6] 2 i>j\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[8][6] 3 i>j\n";
			 }
		}

		if(M[8][7]<0){
		M[8][6]=M[8][7];
		x11[(M[8][7])]-=1.9;
		M[8][7]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[8][6] 4 i>j\n";
		return 1;
		}
		}
		if(M[6][8]==0){
		      for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=0){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4+1]  M[6][8] i>j\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][4+1]  M[6][8] 1 i>j\n";
			  }
			}

		
		for(int i=1;i!=-1;i++){//up search
			  if(M[6-i][8]<0&&(6-i)>=0){
			 M[6][8]=M[6-i][8];
			 y11[(M[6-i][8]+16)]-=i*1.9;
			 M[6-i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4+1]  M[6][8] 2 i>j\n";
			 return 1;
			 }
			 else if(M[6-i][8]>0||(6-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4+1]  M[6][8] 3 i>j\n";
			 }
		}

		if(M[7][8]<0){
		M[6][8]=M[7][8];
		x11[(M[6][8])]-=1.9;
		M[6][8]=0;
		flag=0;
		cout<<"\nMB king:M[4][4+1]  M[6][8] 4 i>j\n";
		return 1;
		}
		}


	}//end of else i<j
	
	}//end of manfi do taraf

}//end  of M[4][4+1]==9



else if(g==0 && M[4][4-1]==9 ){//M[4][4-1]==9
	if(M[1][1]==0&&M[7][1]!=0){//M[7][1] have manfi or sefid 
		 for(int i=1;i!=-1;i++){//right search
			  if(M[1][1+i]<0&&(1+i)<=8){
			  M[1][1]=M[1][1+i];
			  x11[(M[1][1+i]+16)]-=i*1.9;
			  M[1][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[1][1]  \n";
			  return 1;
			  }
			  else if(M[1][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[1][1] 1 \n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][1]<0&&(1+i)<=8){
			 M[1][1]=M[1+i][1];
			 y11[(M[1+i][1]+16)]+=i*1.9;
			 M[1+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[1][1] 2\n";
			 return 1;
			 }
			 else if(M[1+i][1]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[1][1] 3\n";
			 }
		}

		if(M[0][1]<0){
		M[1][1]=M[0][1];
		y11[(M[0][1])]-=1.9;
		M[0][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[1][1] 4\n";
		return 1;
		}

		if(M[1][0]<0){
		M[1][1]=M[1][0];
		x11[(M[1][0])]+=1.9;
		M[1][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[1][1] 5\n";
		return 1;
		}
	}

	if(M[7][1]==0&&M[1][1]!=0){//M[1][1] have manfi or sefid 
		 for(int i=1;i!=-1;i++){//right search
			  if(M[7][1+i]<0&&(1+i)<=8){
			  M[7][1]=M[7][1+i];
			  x11[(M[7][1+i]+16)]-=i*1.9;
			  M[7][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[7][1]  \n";
			  return 1;
			  }
			  else if(M[7][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[7][1] 1 \n";
			  }
			  }
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][1]<0&&(7-i)>=0){
			 M[7][1]=M[7-i][1];
			 y11[(M[7-i][1]+16)]-=i*1.9;
			 M[7-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[7][1] 2\n";
			 return 1;
			 }
			 else if(M[7-i][1]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[7][1] 3\n";
			 }
		}

		if(M[8][1]<0){
		M[7][1]=M[8][1];
		y11[(M[8][1])]+=1.9;
		M[8][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[7][1] 4\n";
		return 1;
		}

		if(M[7][0]<0){
		M[7][1]=M[7][0];
		x11[(M[7][0])]+=1.9;
		M[7][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[7][1] 5\n";
		return 1;
		}
	}//end of M[1][1] have manfi or sefid

	if(M[7][1]==0&&M[1][1]==0){//har do khali
	int i=0,j=0;
	if(M[0][2]<0)
		i++;
	if(M[2][0]<0)
		i++;
	if(M[8][2]<0)
		j++;
	if(M[6][0]<0)
		j++;
	if(i<j){
	for(int i=1;i!=-1;i++){//right search
			  if(M[1][1+i]<0&&(1+i)<=8){
			  M[1][1]=M[1][1+i];
			  x11[(M[1][1+i]+16)]-=i*1.9;
			  M[1][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[1][1] i<j \n";
			  return 1;
			  }
			  else if(M[1][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[1][1] 1 i<j \n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][1]<0&&(1+i)<=8){
			 M[1][1]=M[1+i][1];
			 y11[(M[1+i][1]+16)]+=i*1.9;
			 M[1+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[1][1] 2 i<j\n";
			 return 1;
			 }
			 else if(M[1+i][1]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[1][1] 3 i<j\n";
			 }
		}

		if(M[0][1]<0){
		M[1][1]=M[0][1];
		y11[(M[0][1])]-=1.9;
		M[0][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[1][1] 4 i<j\n";
		return 1;
		}

		if(M[1][0]<0){
		M[1][1]=M[1][0];
		x11[(M[1][0])]+=1.9;
		M[1][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[1][1] 5 i<j\n";
		return 1;
		}
	}
	else{
	for(int i=1;i!=-1;i++){//right search
			  if(M[7][1+i]<0&&(1+i)<=8){
			  M[7][1]=M[7][1+i];
			  x11[(M[7][1+i]+16)]-=i*1.9;
			  M[7][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[7][1] i>j \n";
			  return 1;
			  }
			  else if(M[7][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[7][1] 1 i>j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][1]<0&&(7-i)>=0){
			 M[7][1]=M[7-i][1];
			 y11[(M[7-i][1]+16)]-=i*1.9;
			 M[7-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[7][1] 2 i>j\n";
			 return 1;
			 }
			 else if(M[7-i][1]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[7][1] 3 i>j\n";
			 }
		}

		if(M[8][1]<0){
		M[7][1]=M[8][1];
		y11[(M[8][1])]+=1.9;
		M[8][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[7][1] 4 i>j\n";
		return 1;
		}

		if(M[7][0]<0){
		M[7][1]=M[7][0];
		x11[(M[7][0])]+=1.9;
		M[7][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[7][1] 5 i>j\n";
		return 1;
		}
	}
	}

	if(M[1][1]<0&&M[7][1]<0){//har do manfi 
	int i=0,j=0;
	if(M[0][2]<0)
		i++;
	if(M[2][0]<0)
		i++;
	if(M[8][2]<0)
		j++;
	if(M[6][0]<0)
		j++;
	if(i<j){
		if(M[0][2]==0){
		for(int i=1;i!=-1;i++){//right search
			  if(M[0][2+i]<0&&(2+i)<=8){
			  M[0][2]=M[0][2+i];
			  x11[(M[0][2+i]+16)]-=i*1.9;
			  M[0][2+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[0][2]  i<j\n";
			  return 1;
			  }
			  else if(M[0][2+i]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[0][2] 1 i<j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=8){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1] M[0][2] 2 i<j\n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[0][2] 3 i<j\n";
			 }
		}

		if(M[0][1]<0){
		M[0][2]=M[0][1];
		x11[(M[0][1])]+=1.9;
		M[0][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[0][2] 4 i<j\n";
		return 1;
		}
		}
		if(M[2][0]==0){
			for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=8){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[2][0]  i<j\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[2][0] 1 i<j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[2+i][0]<0&&(2+i)<=8){
			 M[2][0]=M[2+i][0];
			 y11[(M[2+i][0]+16)]+=i*1.9;
			 M[2+i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[2][0] 2 i<j\n";
			 return 1;
			 }
			 else if(M[2+i][0]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[2][0] 3 i<j\n";
			 }
		}

		if(M[1][0]<0){
		M[2][0]=M[1][0];
		y11[(M[1][0])]-=1.9;
		M[1][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[2][0] 4 i<j\n";
		return 1;
		}
		
		}

	}
	else{
		if(M[8][2]==0){
		for(int i=1;i!=-1;i++){//right search
			  if(M[8][2+i]<0&&(2+i)<=8){
			  M[8][2]=M[8][2+i];
			  x11[(M[8][2+i]+16)]-=i*1.9;
			  M[8][2+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[8][2]  i>j\n";
			  return 1;
			  }
			  else if(M[8][2+i]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[8][2] 1 i>j\n";
			  }
			  }

		
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=0){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[8][2] 2 i>j\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[8][2] 3 i>j\n";
			 }
		}

		if(M[8][1]<0){
		M[8][2]=M[8][1];
		x11[(M[8][1])]+=1.9;
		M[8][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[8][2] 4 i>j\n";
		return 1;
		}
		}
		if(M[6][0]==0){
		    for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=8){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[6][0]  i>j\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[6][0] 1 i>j\n";
			  }
			  }
		
		for(int i=1;i!=-1;i++){//up search
			  if(M[6-i][0]<0&&(6-i)>=0){
			 M[6][0]=M[6-i][0];
			 y11[(M[6-i][0]+16)]-=i*1.9;
			 M[6-i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[6][0] 2 i>j\n";
			 return 1;
			 }
			 else if(M[6-i][0]>0||(6-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[6][0] 3 i>j\n";
			}
	        }

		if(M[7][0]<0){
		M[6][0]=M[7][0];
		y11[(M[7][0])]+=1.9;
		M[7][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[6][0] 4 i>j\n";
		return 1;
		}
		}


	}//end of else i<j
	
	}//end of manfi do taraf

}//end  of M[4][4-1]==9



else if(g==0 && M[4+1][4]==9 ){//M[4+1][4]==9
	if(M[7][7]==0&&M[7][1]!=0){//M[7][1] have manfi or sefid 
		  for(int i=1;i!=-1;i++){//left search
			  if(M[7][7-i]<0&&(7-i)>=0){
			  M[7][7]=M[7][7-i];
			  x11[(M[7][7-i]+16)]+=i*1.9;
			  M[7][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4+1][4]  M[7][7] \n";
			  return 1;
			  
			  }
			  else if(M[7][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4+1][4]  M[7][7] 1 \n";
			  }
			}
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][7]<0&&(7-i)>=0){
			 M[7][7]=M[7-i][7];
			 y11[(M[7-i][7]+16)]-=i*1.9;
			 M[7-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4+1][4]  M[7][7] 2 \n";
			 return 1;
			 }
			 else if(M[7-i][7]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[7][7] 3\n";
			}
	        }

		if(M[7][8]<0){
		M[7][7]=M[7][8];
		x11[(M[7][8])]-=1.9;
		M[7][8]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][7] 4\n";
		return 1;
		}

		if(M[8][7]<0){
		M[7][7]=M[8][7];
		y11[(M[8][7])]+=1.9;
		M[8][7]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][7] 5\n";
		return 1;
		}
	}

	if(M[7][1]==0&&M[7][7]!=0){//M[7][7] have manfi or sefid 
		 for(int i=1;i!=-1;i++){//right search
			  if(M[7][1+i]<0&&(1+i)<=8){
			  M[7][1]=M[7][1+i];
			  x11[(M[7][1+i]+16)]-=i*1.9;
			  M[7][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4+1][4]  M[7][1]  \n";
			  return 1;
			  }
			  else if(M[7][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[7][1] 1 \n";
			  }
			  }
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][1]<0&&(7-i)>=0){
			 M[7][1]=M[7-i][1];
			 y11[(M[7-i][1]+16)]-=i*1.9;
			 M[7-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4+1][4]  M[7][1] 2\n";
			 return 1;
			 }
			 else if(M[7-i][1]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[7][1] 3\n";
			 }
		}

		if(M[8][1]<0){
		M[7][1]=M[8][1];
		y11[(M[8][1])]+=1.9;
		M[8][1]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][1] 4\n";
		return 1;
		}

		if(M[7][0]<0){
		M[7][1]=M[7][0];
		x11[(M[7][0])]+=1.9;
		M[7][0]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][1] 5\n";
		return 1;
		}
	}//end of M[7][7] have manfi or sefid

	if(M[7][1]==0&&M[7][7]==0){//har do khali
	int i=0,j=0;
	if(M[6][8]<0)
		i++;
	if(M[8][6]<0)
		i++;
	if(M[8][2]<0)
		j++;
	if(M[6][0]<0)
		j++;
	if(i<j){
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][7-i]<0&&(7-i)>=0){
			  M[7][7]=M[7][7-i];
			  x11[(M[7][7-i]+16)]+=i*1.9;
			  M[7][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4+1][4]  M[7][7] i<j\n";
			  return 1;
			  
			  }
			  else if(M[7][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4+1][4]  M[7][7] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][7]<0&&(7-i)>=0){
			 M[7][7]=M[7-i][7];
			 y11[(M[7-i][7]+16)]-=i*1.9;
			 M[7-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4+1][4]  M[7][7] 2 i<j\n";
			 return 1;
			 }
			 else if(M[7-i][7]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[7][7] 3 i<j\n";
			}
	        }

		if(M[7][8]<0){
		M[7][7]=M[7][8];
		x11[(M[7][8])]-=1.9;
		M[7][8]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][7] 4 i<j\n";
		return 1;
		}

		if(M[8][7]<0){
		M[7][7]=M[8][7];
		y11[(M[8][7])]+=1.9;
		M[8][7]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][7] 5 i<j\n";
		return 1;
		}
	}
	else{
	 for(int i=1;i!=-1;i++){//right search
			  if(M[7][1+i]<0&&(1+i)<=8){
			  M[7][1]=M[7][1+i];
			  x11[(M[7][1+i]+16)]-=i*1.9;
			  M[7][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4+1][4]  M[7][1]  i>j\n";
			  return 1;
			  }
			  else if(M[7][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[7][1] 1 i>j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][1]<0&&(7-i)>=0){
			 M[7][1]=M[7-i][1];
			 y11[(M[7-i][1]+16)]-=i*1.9;
			 M[7-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4+1][4]  M[7][1] 2 i>j\n";
			 return 1;
			 }
			 else if(M[7-i][1]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[7][1] 3 i>j\n";
			 }
		}

		if(M[8][1]<0){
		M[7][1]=M[8][1];
		y11[(M[8][1])]+=1.9;
		M[8][1]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][1] 4 i>j\n";
		return 1;
		}

		if(M[7][0]<0){
		M[7][1]=M[7][0];
		x11[(M[7][0])]+=1.9;
		M[7][0]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[7][1] 5 i>j\n";
		return 1;
		}
	}
	}

	if(M[7][7]<0&&M[7][1]<0){//har do manfi 
	int i=0,j=0;
	if(M[8][6]<0)
		i++;
	if(M[6][8]<0)
		i++;
	if(M[8][2]<0)
		j++;
	if(M[6][0]<0)
		j++;
	if(i<j){
		if(M[6][8]==0){
		for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=0){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4+1][4]  M[6][8] i<j\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4+1][4]  M[6][8] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//up search
			  if(M[6-i][8]<0&&(6-i)>=0){
			 M[6][8]=M[6-i][8];
			 y11[(M[6-i][8]+16)]-=i*1.9;
			 M[6-i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[4+1][4]  M[6][8] 2 i<j\n";
			 return 1;
			 }
			 else if(M[6-i][8]>0||(6-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[6][8] 3 i<j\n";
			}
	        }

		if(M[7][8]<0){
		M[6][8]=M[7][8];
		y11[(M[7][8])]+=1.9;
		M[7][8]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[6][8] 4 i<j\n";
		return 1;
		}
		}
		if(M[8][6]==0){
			for(int i=1;i!=-1;i++){//left search
			  if(M[8][6-i]<0&&(6-i)>=0){
			  M[8][6]=M[8][6-i];
			  x11[(M[8][6-i]+16)]+=i*1.9;
			  M[8][6-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4+1][4]  M[8][6] i<j\n";
			  return 1;
			  
			  }
			  else if(M[8][6-i]>0||(6-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4+1][4]  M[8][6] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=0){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[4+1][4]  M[8][6] 2 i<j\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4+1][4]  M[8][6] 3 i<j\n";
			}
	        }

		if(M[8][7]<0){
		M[8][6]=M[8][7];
		x11[(M[8][7])]-=1.9;
		M[8][7]=0;
		flag=0;
		cout<<"\nMB king:M[4+1][4]  M[8][6] 4 i<j\n";
		return 1;
		}
		
		}

	}
	else{
		if(M[8][2]==0){
		for(int i=1;i!=-1;i++){//right search
			  if(M[8][2+i]<0&&(2+i)<=8){
			  M[8][2]=M[8][2+i];
			  x11[(M[8][2+i]+16)]-=i*1.9;
			  M[8][2+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[8][2]  i>j\n";
			  return 1;
			  }
			  else if(M[8][2+i]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[8][2] 1 i>j\n";
			  }
			  }

		
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=0){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[8][2] 2 i>j\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[8][2] 3 i>j\n";
			 }
		}

		if(M[8][1]<0){
		M[8][2]=M[8][1];
		x11[(M[8][1])]+=1.9;
		M[8][1]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[8][2] 4 i>j\n";
		return 1;
		}
		}
		if(M[6][0]==0){
		    for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=8){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][4-1]  M[6][0]  i>j\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[6][0] 1 i>j\n";
			  }
			  }
		
		for(int i=1;i!=-1;i++){//up search
			  if(M[6-i][0]<0&&(6-i)>=0){
			 M[6][0]=M[6-i][0];
			 y11[(M[6-i][0]+16)]-=i*1.9;
			 M[6-i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[4][4-1]  M[6][0] 2 i>j\n";
			 return 1;
			 }
			 else if(M[6-i][0]>0||(6-i)<0){
				  i=-2;
			cout<<"\nMB king:M[4][4-1]  M[6][0] 3 i>j\n";
			 }
		}

		if(M[7][0]<0){
		M[6][0]=M[7][0];
		y11[(M[7][0])]+=1.9;
		M[7][0]=0;
		flag=0;
		cout<<"\nMB king:M[4][4-1]  M[6][0] 4 i>j\n";
		return 1;
		}
		}


	}//end of else i<j
	
	}//end of manfi do taraf

}//end  of M[4+1][4]==9





else if(g==0 && M[4-1][4]==9 ){//M[4-1][4]==9
	if(M[1][7]==0&&M[1][1]!=0){//M[1][1] have manfi or sefid 
		  for(int i=1;i!=-1;i++){//left search
			  if(M[1][7-i]<0&&(7-i)>=0){
			  M[1][7]=M[1][7-i];
			  x11[(M[1][7-i]+16)]+=i*1.9;
			  M[1][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[1][7] \n";
			  return 1;
			  
			  }
			  else if(M[1][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4-1][4]  M[1][7] 1 \n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][7]<0&&(1+i)<=8){
			 M[1][7]=M[1+i][7];
			 y11[(M[1+i][7]+16)]+=i*1.9;
			 M[1+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[1][7] 2 \n";
			 return 1;
			 }
			 else if(M[1+i][7]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[1][7] 3 \n";
			 }
		}

		if(M[1][8]<0){
		M[1][7]=M[1][8];
		x11[(M[1][8])]-=1.9;
		M[1][8]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][7] 4\n";
		return 1;
		}

		if(M[0][7]<0){
		M[1][7]=M[0][7];
		y11[(M[0][7])]-=1.9;
		M[0][7]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][7] 5\n";
		return 1;
		}
	}

	if(M[1][1]==0&&M[1][7]!=0){//M[1][7] have manfi or sefid 
		 for(int i=1;i!=-1;i++){//right search
			  if(M[1][1+i]<0&&(1+i)<=8){
			  M[1][1]=M[1][1+i];
			  x11[(M[1][1+i]+16)]-=i*1.9;
			  M[1][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[1][1]  \n";
			  return 1;
			  }
			  else if(M[1][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[1][1] 1 \n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][1]<0&&(1+i)<=8){
			 M[1][1]=M[1+i][1];
			 y11[(M[1+i][1]+16)]+=i*1.9;
			 M[1+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[1][1] 2 \n";
			 return 1;
			 }
			 else if(M[1+i][1]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[1][1] 3 \n";
			 }
		}

		if(M[1][0]<0){
		M[1][1]=M[1][0];
		x11[(M[1][0])]+=1.9;
		M[1][0]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][1] 4\n";
		return 1;
		}

		if(M[0][1]<0){
		M[1][1]=M[0][1];
		y11[(M[0][1])]-=1.9;
		M[0][1]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][1] 5\n";
		return 1;
		}
	}//end of M[1][7] have manfi or sefid

	if(M[7][1]==0&&M[7][7]==0){//har do khali
	int i=0,j=0;
	if(M[0][6]<0)
		i++;
	if(M[2][8]<0)
		i++;
	if(M[0][2]<0)
		j++;
	if(M[2][0]<0)
		j++;
	if(i<j){
	 for(int i=1;i!=-1;i++){//left search
			  if(M[1][7-i]<0&&(7-i)>=0){
			  M[1][7]=M[1][7-i];
			  x11[(M[1][7-i]+16)]+=i*1.9;
			  M[1][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[1][7] i<j\n";
			  return 1;
			  
			  }
			  else if(M[1][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4-1][4]  M[1][7] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][7]<0&&(1+i)<=8){
			 M[1][7]=M[1+i][7];
			 y11[(M[1+i][7]+16)]+=i*1.9;
			 M[1+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[1][7] 2 i<j\n";
			 return 1;
			 }
			 else if(M[1+i][7]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[1][7] 3 i<j\n";
			 }
		}

		if(M[1][8]<0){
		M[1][7]=M[1][8];
		x11[(M[1][8])]-=1.9;
		M[1][8]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][7] 4 i<j\n";
		return 1;
		}

		if(M[0][7]<0){
		M[1][7]=M[0][7];
		y11[(M[0][7])]-=1.9;
		M[0][7]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][7] 5 i<j\n";
		return 1;
		}
	}
	else{
	  for(int i=1;i!=-1;i++){//right search
			  if(M[1][1+i]<0&&(1+i)<=8){
			  M[1][1]=M[1][1+i];
			  x11[(M[1][1+i]+16)]-=i*1.9;
			  M[1][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[1][1]  i>j\n";
			  return 1;
			  }
			  else if(M[1][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[1][1] 1 i>j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][1]<0&&(1+i)<=8){
			 M[1][1]=M[1+i][1];
			 y11[(M[1+i][1]+16)]+=i*1.9;
			 M[1+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[1][1] 2 i>j\n";
			 return 1;
			 }
			 else if(M[1+i][1]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[1][1] 3 i>j\n";
			 }
		}

		if(M[1][0]<0){
		M[1][1]=M[1][0];
		x11[(M[1][0])]+=1.9;
		M[1][0]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][1] 4 i>j\n";
		return 1;
		}

		if(M[0][1]<0){
		M[1][1]=M[0][1];
		y11[(M[0][1])]-=1.9;
		M[0][1]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[1][1] 5 i>j\n";
		return 1;
		}
	}
	}

	if(M[1][7]<0&&M[1][1]<0){//har do manfi 
	int i=0,j=0;
	if(M[0][6]<0)
		i++;
	if(M[2][8]<0)
		i++;
	if(M[0][2]<0)
		j++;
	if(M[2][0]<0)
		j++;
	if(i<j){
		if(M[0][6]==0){
		for(int i=1;i!=-1;i++){//left search
			  if(M[0][6-i]<0&&(6-i)>=0){
			  M[0][6]=M[0][6-i];
			  x11[(M[0][6-i]+16)]+=i*1.9;
			  M[0][6-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[0][6] i<j\n";
			  return 1;
			  
			  }
			  else if(M[0][6-i]>0||(6-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4-1][4]  M[0][6] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=8){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[0][6] 2 i<j\n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[0][6] 3 i<j\n";
			 }
		}

		if(M[0][7]<0){
		M[0][6]=M[0][7];
		x11[(M[0][7])]-=1.9;
		M[0][7]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[0][6] 4 i<j\n";
		return 1;
		}
		}
		if(M[2][8]==0){
			for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=0){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[2][8] i<j\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4-1][4]  M[2][8] 1 i<j\n";
			  }
			}
		for(int i=1;i!=-1;i++){//down search
			  if(M[2+i][8]<0&&(2+i)<=8){
			 M[2][8]=M[2+i][8];
			 y11[(M[2+i][8]+16)]+=i*1.9;
			 M[2+i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[2][8] 2 i<j\n";
			 return 1;
			 }
			 else if(M[2+i][8]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[2][8] 3 i<j\n";
			 }
		}

		if(M[1][8]<0){
		M[2][8]=M[1][8];
		y11[(M[1][8])]-=1.9;
		M[1][8]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[2][8] 4 i<j\n";
		return 1;
		}
		
		}

	}
	else{
		if(M[0][2]==0){
		for(int i=1;i!=-1;i++){//right search
			  if(M[0][2+i]<0&&(2+i)<=8){
			  M[0][2]=M[0][2+i];
			  x11[(M[0][2+i]+16)]-=i*1.9;
			  M[0][2+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[0][2]  i>j\n";
			  return 1;
			  }
			  else if(M[0][2+i]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[0][2] 1 i>j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=8){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4] M[0][2] 2 i>j\n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[0][2] 3 i>j\n";
			 }
		}

		if(M[0][1]<0){
		M[0][2]=M[0][1];
		x11[(M[0][1])]+=1.9;
		M[0][1]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[0][2] 4 i>j\n";
		return 1;
		}
		}
		if(M[2][0]==0){
			for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=8){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4-1][4]  M[2][0]  i>j\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[2][0] 1 i>j\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//down search
			  if(M[2+i][0]<0&&(2+i)<=8){
			 M[2][0]=M[2+i][0];
			 y11[(M[2+i][0]+16)]+=i*1.9;
			 M[2+i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[4-1][4]  M[2][0] 2 i>j\n";
			 return 1;
			 }
			 else if(M[2+i][0]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4-1][4]  M[2][0] 3 i>j\n";
			 }
		}

		if(M[1][0]<0){
		M[2][0]=M[1][0];
		y11[(M[1][0])]-=1.9;
		M[1][0]=0;
		flag=0;
		cout<<"\nMB king:M[4-1][4]  M[2][0] 4 i>j\n";
		return 1;
		}
		
		}


	}//end of else i<j
	
	}//end of manfi do taraf

}//end  of M[4-1][4]==9



if(g=0 &&M[4][4]!=9)
	g=1;
if(g=1 &&M[4][4]!=9){//g=1 &&M[4][4]!=9
for(int i=0;i<=8&&i!=-1;i++)
	for(int j=0;j<=8&&j!=-1;j++)
		if(M[i][j]==9){
		a=i;
		b=j;
		i=-2;
		j=-2;
		}
		if(a==0&& b==2){//halat 3
		if(M[0][1]==0){
		for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=8){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][2]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][2]  M[0][1] 2 \n";
			 }
		     }
		}
		if(M[0][6]==0){
		int j=0;
		for(int i=1;i<=3;i++)//right search
			  if(M[0][2+i]==0)
				  j++;
			  if(j==3&&M[0][7]<0){
			  M[0][6]=M[0][7];
			  x11[(M[0][7]+16)]-=1.9;
			  M[0][7]=0;
			  flag=0;
			  cout<<"\nMB king:M[0][2]  M[0][6] 1 \n";
			  return 1;
			  }

			    if(j==3){
			  for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=8){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][2]  M[0][6] 2 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][2]  M[0][6] 3 \n";
			 }
		     }
			 }

		   if(j==3 && M[0][7]==0){
			  for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=8){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][2]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][2]  M[0][7] 2 \n";
			 }
		     }
			 }
		}

		if(M[8][2]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//down search
			  if(M[i][2]==0)
				  j++;
		if(j==7){
			if(M[8][1]<0){
			M[8][2]=M[8][1];
		    x11[(M[8][1]+16)]+=1.9;
		    M[8][1]=0;
		    flag=0;
			cout<<"\nMB king:M[0][2]  M[8][2]  \n";
			return 1;

			}

				for(int i=1;i!=-1;i++){//right search
			  if(M[8][2+i]<0&&(2+i)<=8){
			  M[8][2]=M[8][2+i];
			  x11[(M[8][2+i]+16)]-=i*1.9;
			  M[8][2+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[0][2]  M[8][2]  1\n";
			  return 1;
			  }
			  else if(M[8][2+i]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][2]  M[8][2] 2\n";
			  }
			  }

		
		}


		}//end third		



		}//end of a==0&& b==2
		else if(a==0&&b==6){//halat 3
		if(M[0][7]==0){
		for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=8){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][6]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][6]  M[0][7] 2 \n";
			 }
		     }
		}
		if(M[0][2]==0){
		int j=0;
		for(int i=1;i<=3;i++)//left search
			  if(M[0][6-i]==0)
				  j++;
			  if(j==3&&M[0][1]<0){
			  M[0][2]=M[0][1];
			  x11[(M[0][1]+16)]+=1.9;
			  M[0][1]=0;
			  flag=0;
			  cout<<"\nMB king:M[0][6]  M[0][2] 1 \n";
			  return 1;
			  }

			    if(j==3){
			  for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=8){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][6]  M[0][2] 2 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][6]  M[0][2] 3 \n";
			 }
		     }
			 }

		   if(j==3 && M[0][1]==0){
			  for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=8){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][6]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][6]  M[0][1] 2 \n";
			 }
		     }
			 }
		}

		if(M[8][6]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//down search
			  if(M[i][6]==0)
				  j++;
		if(j==7){
			if(M[8][7]<0){
			M[8][6]=M[8][7];
		    x11[(M[8][7]+16)]-=1.9;
		    M[8][7]=0;
		    flag=0;
			cout<<"\nMB king:M[0][6]  M[8][6]  \n";
			return 1;

			}

			for(int i=1;i!=-1;i++){//left search
			  if(M[8][6-i]<0&&(6-i)>=0){
			  M[8][6]=M[8][6-i];
			  x11[(M[8][6-i]+16)]+=i*1.9;
			  M[8][6-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[0][6]  M[8][6] 1\n";
			  return 1;
			  
			  }
			  else if(M[8][6-i]>0||(6-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[0][6]  M[8][6] 2\n";
			  }
			}

		
		}


		}//end third		


		
		}//end of a==0 b==6
else if(a==0&&b==3){
	if(M[0][1]==0&&M[0][2]==0){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=8){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[0][2] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[0][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=8){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[0][1] 2 \n";
			 }
		     }

	
	}//M[0][1]==0&&M[0][2]==0
	if(M[0][7]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[0][3+i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=8){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[0][6] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[0][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=8){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[0][7] 2 \n";
			 }
		     }
	
	
	}
	
	}//M[0][7]==0

	if(M[0][2]==0&&M[0][1]<0){
		 M[0][2]=M[0][1];
		 x11[(M[0][1]+16)]+=1.9;
		 M[0][1]=0;
		 flag=0;
		 cout<<"\nMB king:M[0][3]  M[0][2] por por\n";
		 return 1;
	}

	if(M[0][7]<0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[0][3+i]==0)
		  j++;
	if(j==3){
	     M[0][6]=M[0][7];
		 x11[(M[0][7]+16)]-=1.9;
		 M[0][7]=0;
		 flag=0;
		 cout<<"\nMB king:M[0][3]  M[0][6] por por\n";
		 return 1;
	
	}

	}
	
	if(M[8][3]==0){
	int j=0;
	for(int i=1;i<=7;i++)//down search
		 if(M[0+i][3]==0)
		  j++;
	if(j==7){

	if(M[8][1]==0&&M[8][2]==0){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=1){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[8][2] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<1){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[8][2] 2 \n";
			 }
		}
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=2){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[8][1] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<2){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[8][1] 2 \n";
			 }
		}

	
	}//M[8][1]==0&&M[8][2]==0
		
	if(M[8][7]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[8][3+i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=1){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[8][6] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<1){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[8][6] 2 \n";
			 }
		}
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=2){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[8][7] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<2){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[8][7] 2 \n";
			 }
		}


	
	}
	}


	}


	}

}//end of a=0 b=3

else if(a==0&&b==4){
	if(M[0][1]==0){
		int j=0;
	for(int i=1;i<=2;i++)//left search
		 if(M[0][4-i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=8){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][4]  M[0][2] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][4]  M[0][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=8){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][4]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][4]  M[0][1] 2 \n";
			 }
		     }
	}
	
	}//M[0][1]==0
	if(M[0][7]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[0][4+i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=8){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][4]  M[0][6] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][4]  M[0][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=8){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][4]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][4]  M[0][7] 2 \n";
			 }
		     }
	
	
	}
	
	}//M[0][7]==0

	if(M[0][1]<0){
	int j=0;
	for(int i=1;i<=2;i++)//left search
		 if(M[0][4-i]==0)
		  j++;
	if(j==2){
	     M[0][2]=M[0][1];
		 x11[(M[0][1]+16)]+=1.9;
		 M[0][1]=0;
		 flag=0;
		 cout<<"\nMB king:M[0][4]  M[0][2] por por\n";
		 return 1;
	
	}

	}

	if(M[0][7]<0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[0][4+i]==0)
		  j++;
	if(j==2){
	     M[0][6]=M[0][7];
		 x11[(M[0][7]+16)]-=1.9;
		 M[0][7]=0;
		 flag=0;
		 cout<<"\nMB king:M[0][4]  M[0][6] por por\n";
		 return 1;
	
	}

	}
	
	if(M[8][4]==0){
	int j=0;
	for(int i=1;i<=7;i++)//down search
		 if(M[0+i][4]==0)
		  j++;
	if(j==7){

	if(M[8][1]==0){
		int j=0;
	for(int i=1;i<=2;i++)//left search
		 if(M[8][4-i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=1){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][4]  M[8][2] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<1){
				  i=-2;
			cout<<"\nMB king:M[0][4]  M[8][2] 2 \n";
			 }
		}
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=2){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][4]  M[8][1] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<2){
				  i=-2;
			cout<<"\nMB king:M[0][4]  M[8][1] 2 \n";
			 }
		}

	}
	}//M[8][1]==0
		
	if(M[8][7]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[8][4+i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=1){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[8][6] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<1){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[8][6] 2 \n";
			 }
		}
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=2){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][3]  M[8][7] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<2){
				  i=-2;
			cout<<"\nMB king:M[0][3]  M[8][7] 2 \n";
			 }
		}


	
	}
	}


	}


	}

}//end of a=0 b=4

else if(a==0&&b==5){
	if(M[0][6]==0&&M[0][7]==0){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=8){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[0][6] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[0][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=8){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[0][7] 2 \n";
			 }
		     }

	
	}//M[0][6]==0&&M[0][7]==0
	if(M[0][1]==0){
	int j=0;
	for(int i=1;i<=3;i++)//left search
		 if(M[0][5-i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=8){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[0][2] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[0][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=8){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[0][1] 2 \n";
			 }
		     }
	
	
	}
	
	}//M[0][1]==0

	if(M[0][6]==0&&M[0][7]<0){
		 M[0][6]=M[0][7];
		 x11[(M[0][7]+16)]-=1.9;
		 M[0][7]=0;
		 flag=0;
		 cout<<"\nMB king:M[0][5]  M[0][6] por por\n";
		 return 1;
	}

	if(M[0][1]<0){
	int j=0;
	for(int i=1;i<=3;i++)//left search
		 if(M[0][5-i]==0)
		  j++;
	if(j==3){
	     M[0][2]=M[0][1];
		 x11[(M[0][1]+16)]+=1.9;
		 M[0][1]=0;
		 flag=0;
		 cout<<"\nMB king:M[0][5]  M[0][2] por por\n";
		 return 1;
	
	}

	}
	
	if(M[8][5]==0){
	int j=0;
	for(int i=1;i<=7;i++)//down search
		 if(M[0+i][5]==0)
		  j++;
	if(j==7){

	if(M[8][6]==0&&M[8][7]==0){
	for(int i=1;i!=-1;i++){//up search
			 if(M[8-i][6]<0&&(8-i)>=1){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[8][6] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<1){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[8][6] 2 \n";
			 }
		}
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=2){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[8][7] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<2){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[8][7] 2 \n";
			 }
		}

	
	}//M[8][6]==0&&M[8][7]==0
		
	if(M[8][1]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[8][5-i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=1){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[8][2] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<1){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[8][2] 2 \n";
			 }
		}
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=2){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[0][5]  M[8][1] 1 \n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<2){
				  i=-2;
			cout<<"\nMB king:M[0][5]  M[8][1] 2 \n";
			 }
		}


	
	}
	}


	}


	}

}//end of a=0 b=5


	else if(a==8&& b==2){//halat 3
		if(M[8][1]==0){
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=0){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][2]  M[8][1] 1\n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][2]  M[8][1] 2 \n";
			 }
		}
		}
		if(M[8][6]==0){
		int j=0;
		for(int i=1;i<=3;i++)//right search
			  if(M[8][2+i]==0)
				  j++;
			  if(j==3&&M[8][7]<0){
			  M[8][6]=M[8][7];
			  x11[(M[8][7]+16)]-=1.9;
			  M[8][7]=0;
			  flag=0;
			  cout<<"\nMB king:M[8][2]  M[8][6] 1 \n";
			  return 1;
			  }

			  if(j==3){
			  for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=0){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][2]  M[8][6] 1\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][2]  M[8][6] 2 \n";
			 }
		     }
			 }

		   if(j==3 && M[8][7]==0){
			 for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=0){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][2]  M[8][7] 1\n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][2]  M[8][7] 2 \n";
			 }
		     }
			 }
		}

		if(M[0][2]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//up search
			  if(M[8-i][2]==0)
				  j++;
		if(j==7){
			if(M[0][1]<0){
			M[0][2]=M[0][1];
		    x11[(M[0][1]+16)]+=1.9;
		    M[0][1]=0;
		    flag=0;
			cout<<"\nMB king:M[8][2]  M[0][2]  \n";
			return 1;

			}

				for(int i=1;i!=-1;i++){//right search
			  if(M[0][2+i]<0&&(2+i)<=8){
			  M[0][2]=M[0][2+i];
			  x11[(M[0][2+i]+16)]-=i*1.9;
			  M[0][2+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[8][2]  M[0][2]  1\n";
			  return 1;
			  }
			  else if(M[0][2+i]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[8][2]  M[0][2] 2\n";
			  }
			  }

		
		}


		}//end third		



		}//end of a==8&& b==2
		else if(a==8&&b==6){//halat 3
		if(M[8][7]==0){
		 for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=0){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][6]  M[8][7] 1\n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][6]  M[8][7] 2 \n";
			 }
		     }
		}
		if(M[8][2]==0){
		int j=0;
		for(int i=1;i<=3;i++)//left search
			  if(M[8][6-i]==0)
				  j++;
			  if(j==3&&M[8][1]<0){
			  M[8][2]=M[8][1];
			  x11[(M[8][1]+16)]+=1.9;
			  M[8][1]=0;
			  flag=0;
			  cout<<"\nMB king:M[8][6]  M[8][2] 1 \n";
			  return 1;
			  }

			    if(j==3){
			   for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=0){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][6]  M[8][2] 1\n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][6]  M[8][2] 2 \n";
			 }
		     }
			 }

		   if(j==3 && M[8][1]==0){
			   for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=0){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][6]  M[8][1] 1\n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][6]  M[8][1] 2 \n";
			 }
		     }
			 }
		}

		if(M[0][6]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//up search
			  if(M[8-i][6]==0)
				  j++;
		if(j==7){
			if(M[0][7]<0){
			M[0][6]=M[0][7];
		    x11[(M[0][7]+16)]-=1.9;
		    M[0][7]=0;
		    flag=0;
			cout<<"\nMB king:M[8][6]  M[0][6]  \n";
			return 1;

			}

			for(int i=1;i!=-1;i++){//left search
			  if(M[0][6-i]<0&&(6-i)>=0){
			  M[0][6]=M[0][6-i];
			  x11[(M[0][6-i]+16)]+=i*1.9;
			  M[0][6-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[8][6]  M[0][6] 1\n";
			  return 1;
			  
			  }
			  else if(M[0][6-i]>0||(6-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[8][6]  M[0][6] 2\n";
			  }
			}

		
		}


		}//end third		


		
		}//end of a==8 b==6
else if(a==8&&b==3){
	if(M[8][1]==0&&M[8][2]==0){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=0){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[8][2] 1\n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[8][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=0){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[8][1] 1\n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[8][1] 2 \n";
			 }
		     }

	
	}//M[8][1]==0&&M[8][2]==0
	if(M[8][7]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[8][3+i]==0)
		  j++;
	if(j==3){
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=0){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[8][6] 1\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[8][6] 2 \n";
			 }
		     }
		for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=0){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[8][7] 1\n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[8][7] 2 \n";
			 }
		     }
	
	
	}
	
	}//M[8][7]==0

	if(M[8][2]==0&&M[8][1]<0){
		 M[8][2]=M[8][1];
		 x11[(M[8][1]+16)]+=1.9;
		 M[8][1]=0;
		 flag=0;
		 cout<<"\nMB king:M[8][3]  M[8][2] por por\n";
		 return 1;
	}

	if(M[8][7]<0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[8][3+i]==0)
		  j++;
	if(j==3){
	     M[8][6]=M[8][7];
		 x11[(M[8][7]+16)]-=1.9;
		 M[8][7]=0;
		 flag=0;
		 cout<<"\nMB king:M[8][3]  M[8][6] por por\n";
		 return 1;
	
	}

	}
	
	if(M[0][3]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[8-i][3]==0)
		  j++;
	if(j==7){

	if(M[0][1]==0&&M[0][2]==0){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=7){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[0][2] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[0][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=6){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[0][1] 2 \n";
			 }
		     }

	
	}//M[0][1]==0&&M[0][2]==0
		
	if(M[0][7]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[0][3+i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=7){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[0][6] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[0][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=6){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][3]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[8][3]  M[0][7] 2 \n";
			 }
		     }


	
	}
	}


	}


	}

}//end of a=8 b=3

else if(a==8&&b==4){
	if(M[8][1]==0){
		int j=0;
	for(int i=1;i<=2;i++)//left search
		 if(M[8][4-i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=0){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[8][2] 1\n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[8][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=0){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[8][1] 1\n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[8][1] 2 \n";
			 }
		     }
	}
	
	}//M[8][1]==0
	if(M[8][7]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[8][4+i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=0){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[8][6] 1\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[8][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=0){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[8][7] 1\n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[8][7] 2 \n";
			 }
		     }
	
	
	}
	
	}//M[8][7]==0

	if(M[8][1]<0){
	int j=0;
	for(int i=1;i<=2;i++)//left search
		 if(M[8][4-i]==0)
		  j++;
	if(j==2){
	     M[8][2]=M[8][1];
		 x11[(M[8][1]+16)]+=1.9;
		 M[8][1]=0;
		 flag=0;
		 cout<<"\nMB king:M[8][4]  M[8][2] por por\n";
		 return 1;
	
	}

	}

	if(M[8][7]<0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[8][4+i]==0)
		  j++;
	if(j==2){
	     M[8][6]=M[8][7];
		 x11[(M[8][7]+16)]-=1.9;
		 M[8][7]=0;
		 flag=0;
		 cout<<"\nMB king:M[8][4]  M[8][6] por por\n";
		 return 1;
	
	}

	}
	
	if(M[0][4]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[8-i][4]==0)
		  j++;
	if(j==7){

	if(M[0][1]==0){
		int j=0;
	for(int i=1;i<=2;i++)//left search
		 if(M[0][4-i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=7){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[0][2] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[0][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=6){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[0][1] 2 \n";
			 }
		     }

	}
	}//M[0][1]==0
		
	if(M[0][7]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[0][4+i]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=7){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[0][6] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[0][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=6){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][4]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[8][4]  M[0][7] 2 \n";
			 }
		     }


	
	}
	}


	}


	}

}//end of a=8 b=4

else if(a==8&&b==5){
	if(M[8][6]==0&&M[8][7]==0){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][6]<0&&(8-i)>=0){
			 M[8][6]=M[8-i][6];
			 y11[(M[8-i][6]+16)]-=i*1.9;
			 M[8-i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[8][6] 1\n";
			 return 1;
			 }
			 else if(M[8-i][6]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[8][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][7]<0&&(8-i)>=0){
			 M[8][7]=M[8-i][7];
			 y11[(M[8-i][7]+16)]-=i*1.9;
			 M[8-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[8][7] 1\n";
			 return 1;
			 }
			 else if(M[8-i][7]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[8][7] 2 \n";
			 }
		     }

	
	}//M[8][6]==0&&M[8][7]==0
	if(M[8][1]==0){
	int j=0;
	for(int i=1;i<=3;i++)//left search
		 if(M[8][5-i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][2]<0&&(8-i)>=0){
			 M[8][2]=M[8-i][2];
			 y11[(M[8-i][2]+16)]-=i*1.9;
			 M[8-i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[8][2] 1\n";
			 return 1;
			 }
			 else if(M[8-i][2]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[8][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//up search
			  if(M[8-i][1]<0&&(8-i)>=0){
			 M[8][1]=M[8-i][1];
			 y11[(M[8-i][1]+16)]-=i*1.9;
			 M[8-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[8][1] 1\n";
			 return 1;
			 }
			 else if(M[8-i][1]>0||(8-i)<0){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[8][1] 2 \n";
			 }
		     }
	
	
	}
	
	}//M[8][1]==0

	if(M[8][6]==0&&M[8][7]<0){
		 M[8][6]=M[8][7];
		 x11[(M[8][7]+16)]-=1.9;
		 M[8][7]=0;
		 flag=0;
		 cout<<"\nMB king:M[8][5]  M[8][6] por por\n";
		 return 1;
	}

	if(M[8][1]<0){
	int j=0;
	for(int i=1;i<=3;i++)//left search
		 if(M[8][5-i]==0)
		  j++;
	if(j==3){
	     M[8][2]=M[8][1];
		 x11[(M[8][1]+16)]+=1.9;
		 M[8][1]=0;
		 flag=0;
		 cout<<"\nMB king:M[8][5]  M[8][2] por por\n";
		 return 1;
	
	}

	}
	
	if(M[0][5]==0){
	int j=0;
	for(int i=1;i<=7;i++)//down search
		 if(M[8-i][5]==0)
		  j++;
	if(j==7){

	if(M[0][6]==0&&M[0][7]==0){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][6]<0&&(0+i)<=7){
			 M[0][6]=M[0+i][6];
			 y11[(M[0+i][6]+16)]+=i*1.9;
			 M[0+i][6]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[0][6] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][6]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[0][6] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][7]<0&&(0+i)<=6){
			 M[0][7]=M[0+i][7];
			 y11[(M[0+i][7]+16)]+=i*1.9;
			 M[0+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[0][7] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][7]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[0][7] 2 \n";
			 }
		     }
	
	}//M[0][6]==0&&M[0][7]==0
		
	if(M[0][1]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[0][5-i]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][2]<0&&(0+i)<=7){
			 M[0][2]=M[0+i][2];
			 y11[(M[0+i][2]+16)]+=i*1.9;
			 M[0+i][2]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[0][2] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][2]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[0][2] 2 \n";
			 }
		     }
	for(int i=1;i!=-1;i++){//down search
			  if(M[0+i][1]<0&&(0+i)<=6){
			 M[0][1]=M[0+i][1];
			 y11[(M[0+i][1]+16)]+=i*1.9;
			 M[0+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[8][5]  M[0][1] 1 \n";
			 return 1;
			 }
			 else if(M[0+i][1]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[8][5]  M[0][1] 2 \n";
			 }
		     }


	
	}
	}


	}


	}

}//end of a=8 b=5


else if(a==2&& b==0){//halat 3
		if(M[1][0]==0){
		for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=8){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][0]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[2][0]  M[1][0] 2\n";
			  }
			  }
		}
		if(M[6][0]==0){
		int j=0;
		for(int i=1;i<=3;i++)//down search
			  if(M[2+i][0]==0)
				  j++;
			  if(j==3&&M[7][0]<0){
			  M[6][0]=M[7][0];
			  y11[(M[7][0]+16)]+=1.9;
			  M[7][0]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][0]  M[6][0] 1 \n";
			  return 1;
			  }

			  if(j==3){
			  for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=8){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][0]  M[6][0]  2\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[2][0]  M[6][0] 3\n";
			  }
			  }
			 }

		   if(j==3 && M[7][0]==0){
			for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=8){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][0]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[6][0]  M[7][0] 2\n";
			  }
			  }
			 }
		}

		if(M[2][8]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//up search
			  if(M[2][0+i]==0)
				  j++;
		if(j==7){
			if(M[1][8]<0){
			M[2][8]=M[1][8];
		    y11[(M[1][8]+16)]-=1.9;
		    M[1][8]=0;
		    flag=0;
			cout<<"\nMB king:M[2][0]  M[2][8]  \n";
			return 1;

			}

				for(int i=1;i!=-1;i++){//down search
			  if(M[2+i][8]<0&&(2+i)<=8){
			 M[2][8]=M[2+i][8];
			 y11[(M[2+i][8]+16)]+=i*1.9;
			 M[2+i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[2][0]  M[0][8] 1 \n";
			 return 1;
			 }
			 else if(M[2+i][8]>0||(2+i)>8){
				  i=-2;
			cout<<"\nMB king:M[2][0]  M[0][8] 2 \n";
			 }
		     }

		
		}


		}//end third		



		}//end of a==2&& b==0
		else if(a==6&&b==0){//halat 3
		if(M[7][0]==0){
		 for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=8){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][0]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[6][0]  M[7][0] 2\n";
			  }
			  }
		}
		if(M[2][0]==0){
		int j=0;
		for(int i=1;i<=3;i++)//up search
			  if(M[6-i][0]==0)
				  j++;
			  if(j==3&&M[1][0]<0){
			  M[2][0]=M[1][0];
			  y11[(M[1][0]+16)]-=1.9;
			  M[1][0]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][0]  M[2][0] 1 \n";
			  return 1;
			  }

			    if(j==3){
			    for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=8){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][0]  M[2][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[6][0]  M[2][0] 2\n";
			  }
			  }
			 }

		   if(j==3 && M[1][0]==0){
			   for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=8){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][0]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[6][0]  M[1][0] 2\n";
			  }
			  }
			 }
		}

		if(M[6][8]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//right search
			  if(M[6][0+i]==0)
				  j++;
		if(j==7){
			if(M[7][8]<0){
			M[6][8]=M[7][8];
		    y11[(M[7][8]+16)]+=1.9;
		    M[7][8]=0;
		    flag=0;
			cout<<"\nMB king:M[6][0]  M[6][8]  \n";
			return 1;

			}

			for(int i=1;i!=-1;i++){//up search
			 if(M[6-i][8]<0&&(6-i)>=0){
			 M[6][8]=M[6-i][8];
			 y11[(M[6-i][8]+16)]-=i*1.9;
			 M[6-i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[6][0]  M[6][8] 1\n";
			 return 1;
			 }
			 else if(M[6-i][8]>0||(6-i)<0){
				  i=-2;
			cout<<"\nMB king:M[6][0]  M[6][8] 2 \n";
			 }
		     }

		
		}


		}//end third		


		
		}//end of a==6 b==0
else if(a==3&&b==0){
	if(M[2][0]==0&&M[1][0]==0){
	for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=8){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[2][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[3][0]  M[2][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=8){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[3][0]  M[1][0] 2\n";
			  }
			  }

	
	}//M[2][0]==0&&M[1][0]==0
	if(M[7][0]==0){
	int j=0;
	for(int i=1;i<=3;i++)//down search
		 if(M[3+i][0]==0)
		  j++;
	if(j==3){
		for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=8){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[3][0]  M[6][0] 2\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=8){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[3][0]  M[7][0] 2\n";
			  }
			  }
	
	
	}
	
	}//M[7][0]==0

	if(M[2][0]==0&&M[1][0]<0){
		 M[2][0]=M[1][0];
		 y11[(M[1][0]+16)]-=1.9;
		 M[1][0]=0;
		 flag=0;
		 cout<<"\nMB king:M[3][0]  M[2][0] por por\n";
		 return 1;
	}

	if(M[7][0]<0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[3+i][0]==0)
		  j++;
	if(j==3){
	     M[6][0]=M[7][0];
		 y11[(M[7][0]+16)]+=1.9;
		 M[7][0]=0;
		 flag=0;
		 cout<<"\nMB king:M[3][0]  M[6][0] por por\n";
		 return 1;
	
	}

	}
	
	if(M[3][8]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[3][0+i]==0)
		  j++;
	if(j==7){

	if(M[1][8]==0&&M[2][8]==0){
	for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=1){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<1){
				 i=-2; 
			cout<<"\nMB king:M[3][0]  M[2][8] 2\n";
			  }
			}
	for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=2){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][6]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<2){
				 i=-2; 
			cout<<"\nMB king:M[3][0]  M[1][8] 2\n";
			  }
			}

	
	}//M[1][8]==0&&M[2][8]==0
		
	if(M[7][8]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[3+i][8]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=1){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[6][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<1){
				 i=-2; 
			cout<<"\nMB king:M[3][0]  M[6][8] 2\n";
			  }
			}
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=2){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][0]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<2){
				 i=-2; 
			cout<<"\nMB king:M[3][0]  M[7][8] 2\n";
			  }
			}


	
	}
	}


	}


	}

}//end of a=3 b=0

else if(a==4&&b==0){
	if(M[1][0]==0){
		int j=0;
	for(int i=1;i<=2;i++)//up search
		 if(M[4-i][0]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=8){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[2][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][0]  M[2][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=8){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][0]  M[1][0] 2\n";
			  }
			  }
	}
	
	}//M[1][0]==0
	if(M[7][0]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[4+i][0]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=8){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][0]  M[6][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=8){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[4][0]  M[7][0] 2\n";
			  }
			  }
	
	
	}
	
	}//M[7][0]==0

	if(M[1][0]<0){
	int j=0;
	for(int i=1;i<=2;i++)//up search
		 if(M[4-i][0]==0)
		  j++;
	if(j==2){
	     M[2][0]=M[1][0];
		 y11[(M[1][0]+16)]-=1.9;
		 M[1][0]=0;
		 flag=0;
		 cout<<"\nMB king:M[4][0]  M[2][0] por por\n";
		 return 1;
	
	}

	}

	if(M[7][0]<0){
	int j=0;
	for(int i=1;i<=2;i++)//down search
		 if(M[4+i][0]==0)
		  j++;
	if(j==2){
	     M[6][0]=M[7][0];
		 y11[(M[7][0]+16)]+=1.9;
		 M[7][0]=0;
		 flag=0;
		 cout<<"\nMB king:M[4][0]  M[6][0] por por\n";
		 return 1;
	
	}

	}
	
	if(M[4][8]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[4][0+i]==0)
		  j++;
	if(j==7){

	if(M[1][8]==0){
		int j=0;
	for(int i=1;i<=2;i++)//up search
		 if(M[4-i][8]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=1){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<1){
				 i=-2; 
			cout<<"\nMB king:M[4][0]  M[2][8] 2\n";
			  }
			}
	for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=2){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<2){
				 i=-2; 
			cout<<"\nMB king:M[4][0]  M[1][8] 2\n";
			  }
			}

	}
	}//M[1][8]==0
		
	if(M[7][8]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[4+i][8]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=1){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[6][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<1){
				 i=-2; 
			cout<<"\nMB king:M[4][0]  M[6][8] 2\n";
			  }
			}
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=2){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][0]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<2){
				 i=-2; 
			cout<<"\nMB king:M[4][0]  M[7][8] 2\n";
			  }
			}


	
	}
	}


	}


	}

}//end of a=4 b=0

else if(a==5&&b==0){
	if(M[6][0]==0&&M[7][0]==0){
	for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=8){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[5][0]  M[6][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=8){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[5][0]  M[7][0] 2\n";
			  }
			  }

	
	}//M[7][0]==0&&M[6][0]==0
	if(M[1][0]==0){
	int j=0;
	for(int i=1;i<=3;i++)//up search
		 if(M[5-i][0]==0)
		  j++;
	if(j==3){
		for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=8){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[2][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[5][0]  M[2][0] 2\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=8){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>8){
				  i=-2;
			cout<<"\nMB king:M[5][0]  M[1][0] 2\n";
			  }
			  }
	
	
	}
	
	}//M[1][0]==0

	if(M[6][0]==0&&M[7][0]<0){
		 M[6][0]=M[7][0];
		 y11[(M[7][0]+16)]+=1.9;
		 M[7][0]=0;
		 flag=0;
		 cout<<"\nMB king:M[5][0]  M[6][0] por por\n";
		 return 1;
	}

	if(M[1][0]<0){
	int j=0;
	for(int i=1;i<=3;i++)//up search
		 if(M[5-i][0]==0)
		  j++;
	if(j==3){
	     M[2][0]=M[1][0];
		 y11[(M[1][0]+16)]-=1.9;
		 M[1][0]=0;
		 flag=0;
		 cout<<"\nMB king:M[5][0]  M[2][0] por por\n";
		 return 1;
	
	}

	}
	
	if(M[5][8]==0){
	int j=0;
	for(int i=1;i<=7;i++)//right search
		 if(M[5][0+i]==0)
		  j++;
	if(j==7){

	if(M[6][8]==0&&M[7][8]==0){
	for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=1){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[6][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<1){
				 i=-2; 
			cout<<"\nMB king:M[5][0]  M[6][8] 2\n";
			  }
			}
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=2){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<2){
				 i=-2; 
			cout<<"\nMB king:M[5][0]  M[7][8] 2\n";
			  }
			}

	
	}//M[7][8]==0&&M[6][8]==0
		
	if(M[1][8]==0){
	int j=0;
	for(int i=1;i<=3;i++)//up search
		 if(M[5-i][8]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=1){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<1){
				 i=-2; 
			cout<<"\nMB king:M[5][0]  M[2][8] 2\n";
			  }
			}
	for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=2){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][0]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<2){
				 i=-2; 
			cout<<"\nMB king:M[5][0]  M[1][8] 2\n";
			  }
			}


	
	}
	}


	}


	}

}//end of a=5 b=0


///////////////////////////////////////////////////////////////////////////////////////////////////////// 4 taraf
else if(a==2&& b==8){//halat 3
		if(M[1][8]==0){
		for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=0){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][8]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[2][8]  M[1][8] 2\n";
			  }
			  }
		}
		if(M[6][8]==0){
		int j=0;
		for(int i=1;i<=3;i++)//down search
			  if(M[2+i][8]==0)
				  j++;
			  if(j==3&&M[7][8]<0){
			  M[6][8]=M[7][8];
			  y11[(M[7][8]+16)]+=1.9;
			  M[7][8]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][8]  M[6][8] 1 \n";
			  return 1;
			  }

			  if(j==3){
			  for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=0){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][8]  M[6][8] 2\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[2][8]  M[6][8] 3\n";
			  }
			  }
			 }

		   if(j==3 && M[7][8]==0){
			for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=0){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[2][8]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[2][8]  M[7][8] 2\n";
			  }
			  }
			 }
		}

		if(M[2][0]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//up search
			  if(M[2][8-i]==0)
				  j++;
		if(j==7){
			if(M[1][0]<0){
			M[2][0]=M[1][0];
		    y11[(M[1][0]+16)]-=1.9;
		    M[1][0]=0;
		    flag=0;
			cout<<"\nMB king:M[2][8]  M[2][0]  \n";
			return 1;

			}

			 for(int i=1;i!=-1;i++){//down search
			 if(M[2+i][0]<0&&(2+i)<=8){
			 M[2][0]=M[2+i][0];
			 y11[(M[2+i][0]+16)]+=i*1.9;
			 M[2+i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[2][8]  M[2][0] 1 \n";
			 return 1;
			 }
			 else if(M[2+i][0]>0||(2+i)>8){
				  i=-2;
			 cout<<"\nMB king:M[2][8]  M[2][0] 2 \n";
			 }
		     }

		
		}


		}//end third		



		}//end of a==2&& b==8
		else if(a==6&&b==8){//halat 3
		if(M[7][8]==0){
		 for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=0){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][8]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[6][8]  M[7][8] 2\n";
			  }
			  }
		}
		if(M[2][8]==0){
		int j=0;
		for(int i=1;i<=3;i++)//up search
			  if(M[6-i][8]==0)
				  j++;
			  if(j==3&&M[1][8]<0){
			  M[2][8]=M[1][8];
			  y11[(M[1][8]+16)]-=1.9;
			  M[1][8]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][8]  M[2][8] 1 \n";
			  return 1;
			  }

			    if(j==3){
			    for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=0){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][8]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[6][8]  M[2][8] 2\n";
			  }
			  }
			 }

		   if(j==3 && M[1][8]==0){
			  for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=0){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[6][8]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[6][8]  M[1][8] 2\n";
			  }
			  }
			 }
		}

		if(M[6][0]==0){//third
		int j=0;
		for(int i=1;i<=7;i++)//right search
			  if(M[6][8-i]==0)
				  j++;
		if(j==7){
			if(M[7][0]<0){
			M[6][0]=M[7][0];
		    y11[(M[7][0]+16)]+=1.9;
		    M[7][0]=0;
		    flag=0;
			cout<<"\nMB king:M[6][8]  M[6][0]  \n";
			return 1;

			}

			for(int i=1;i!=-1;i++){//up search
			 if(M[6-i][0]<0&&(6-i)>=0){
			 M[6][0]=M[6-i][0];
			 y11[(M[6-i][0]+16)]-=i*1.9;
			 M[6-i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[6][8]  M[6][0] 1\n";
			 return 1;
			 }
			 else if(M[6-i][0]>0||(6-i)<0){
				  i=-2;
			cout<<"\nMB king:M[6][8]  M[6][0] 2 \n";
			 }
		     }

		
		}


		}//end third		


		
		}//end of a==6 b==8
else if(a==3&&b==8){
	if(M[2][8]==0&&M[1][8]==0){
	for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=0){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[3][8]  M[2][8] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=0){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[3][8]  M[1][8] 2\n";
			  }
			  }

	
	}//M[2][8]==0&&M[1][8]==0
	if(M[7][8]==0){
	int j=0;
	for(int i=1;i<=3;i++)//down search
		 if(M[3+i][8]==0)
		  j++;
	if(j==3){
		for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=0){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[6][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[3][8]  M[6][8] 2\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=0){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[3][8]  M[7][8] 2\n";
			  }
			  }
	
	
	}
	
	}//M[7][8]==0

	if(M[2][8]==0&&M[1][8]<0){
		 M[2][8]=M[1][8];
		 y11[(M[1][8]+16)]-=1.9;
		 M[1][8]=0;
		 flag=0;
		 cout<<"\nMB king:M[3][8]  M[2][8] por por\n";
		 return 1;
	}

	if(M[7][8]<0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[3+i][8]==0)
		  j++;
	if(j==3){
	     M[6][8]=M[7][8];
		 y11[(M[7][8]+16)]+=1.9;
		 M[7][8]=0;
		 flag=0;
		 cout<<"\nMB king:M[3][8]  M[6][8] por por\n";
		 return 1;
	
	}

	}
	
	if(M[3][0]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[3][8-i]==0)
		  j++;
	if(j==7){

	if(M[1][0]==0&&M[2][0]==0){
	for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=7){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[2][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[3][8]  M[2][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=2){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>2){
				  i=-2;
			cout<<"\nMB king:M[3][8]  M[1][0] 2\n";
			  }
			  }

	
	}//M[1][0]==0&&M[2][0]==0
		
	if(M[7][0]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[3+i][0]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=7){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[3][8]  M[6][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=6){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[3][8]  M[7][0] 2\n";
			  }
			  }


	
	}
	}


	}


	}

}//end of a=3 b=8

else if(a==4&&b==8){
	if(M[1][8]==0){
		int j=0;
	for(int i=1;i<=2;i++)//up search
		 if(M[4-i][8]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=0){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][8]  M[2][8] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=0){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][8]  M[1][8] 2\n";
			  }
			  }
	}
	
	}//M[1][8]==0
	if(M[7][8]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[4+i][8]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=0){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[6][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][8]  M[6][8] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=0){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[4][8]  M[7][8] 2\n";
			  }
			  }
	
	
	}
	
	}//M[7][8]==0

	if(M[1][8]<0){
	int j=0;
	for(int i=1;i<=2;i++)//up search
		 if(M[4-i][8]==0)
		  j++;
	if(j==2){
	     M[2][8]=M[1][8];
		 y11[(M[1][8]+16)]-=1.9;
		 M[1][8]=0;
		 flag=0;
		 cout<<"\nMB king:M[4][8]  M[2][8] por por\n";
		 return 1;
	
	}

	}

	if(M[7][8]<0){
	int j=0;
	for(int i=1;i<=2;i++)//down search
		 if(M[4+i][8]==0)
		  j++;
	if(j==2){
	     M[6][8]=M[7][8];
		 y11[(M[7][8]+16)]+=1.9;
		 M[7][8]=0;
		 flag=0;
		 cout<<"\nMB king:M[4][8]  M[6][8] por por\n";
		 return 1;
	
	}

	}
	
	if(M[4][0]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[4][8-i]==0)
		  j++;
	if(j==7){

	if(M[1][0]==0){
		int j=0;
	for(int i=1;i<=2;i++)//up search
		 if(M[4-i][0]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=7){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[2][0+i]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[4][8]  M[2][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=6){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[3][8]  M[1][0] 2\n";
			  }
			  }

	}
	}//M[1][0]==0
		
	if(M[7][0]==0){
	int j=0;
	for(int i=1;i<=2;i++)//right search
		 if(M[4+i][0]==0)
		  j++;
	if(j==2){
	for(int i=1;i!=-1;i++){//right search
			  if(M[6][0+i]<0&&(0+i)<=7){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[4][8]  M[6][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=6){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[4][8]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[4][8]  M[7][0] 2\n";
			  }
			  }


	
	}
	}


	}


	}

}//end of a=4 b=8

else if(a==5&&b==8){
	if(M[6][8]==0&&M[7][8]==0){
	for(int i=1;i!=-1;i++){//left search
			  if(M[6][8-i]<0&&(8-i)>=0){
			  M[6][8]=M[6][8-i];
			  x11[(M[6][8-i]+16)]+=i*1.9;
			  M[6][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[6][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[6][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[5][8]  M[6][8] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//left search
			  if(M[7][8-i]<0&&(8-i)>=0){
			  M[7][8]=M[7][8-i];
			  x11[(M[7][8-i]+16)]+=i*1.9;
			  M[7][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[7][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[5][8]  M[7][8] 2\n";
			  }
			  }

	
	}//M[7][8]==0&&M[6][8]==0
	if(M[1][8]==0){
	int j=0;
	for(int i=1;i<=3;i++)//down search
		 if(M[6-i][8]==0)
		  j++;
	if(j==3){
		for(int i=1;i!=-1;i++){//left search
			  if(M[2][8-i]<0&&(8-i)>=0){
			  M[2][8]=M[2][8-i];
			  x11[(M[2][8-i]+16)]+=i*1.9;
			  M[2][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[2][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[5][8]  M[2][8] 2\n";
			  }
			  }
		for(int i=1;i!=-1;i++){//left search
			  if(M[1][8-i]<0&&(8-i)>=0){
			  M[1][8]=M[1][8-i];
			  x11[(M[1][8-i]+16)]+=i*1.9;
			  M[1][8-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[1][8] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][8-i]>0||(8-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[5][8]  M[1][8] 2\n";
			  }
			  }
	
	
	}
	
	}//M[1][8]==0

	if(M[6][8]==0&&M[7][8]<0){
		 M[6][8]=M[7][8];
		 y11[(M[7][8]+16)]+=1.9;
		 M[7][8]=0;
		 flag=0;
		 cout<<"\nMB king:M[5][8]  M[6][8] por por\n";
		 return 1;
	}

	if(M[1][8]<0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[5-i][8]==0)
		  j++;
	if(j==3){
	     M[2][8]=M[1][8];
		 y11[(M[1][8]+16)]-=1.9;
		 M[1][8]=0;
		 flag=0;
		 cout<<"\nMB king:M[5][8]  M[2][8] por por\n";
		 return 1;
	
	}

	}
	
	if(M[5][0]==0){
	int j=0;
	for(int i=1;i<=7;i++)//up search
		 if(M[5][8-i]==0)
		  j++;
	if(j==7){

	if(M[6][0]==0&&M[7][0]==0){
	for(int i=1;i!=-1;i++){//right search
			  if(M[6][6+i]<0&&(0+i)<=7){
			  M[6][0]=M[6][0+i];
			  x11[(M[6][0+i]+16)]-=i*1.9;
			  M[6][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[6][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[5][8]  M[6][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[7][0+i]<0&&(0+i)<=6){
			  M[7][0]=M[7][0+i];
			  x11[(M[7][0+i]+16)]-=i*1.9;
			  M[7][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[7][0]  1\n";
			  return 1;
			  }
			  else if(M[7][0+i]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[3][5]  M[7][0] 2\n";
			  }
			  }

	
	}//M[7][0]==0&&M[6][0]==0
		
	if(M[1][0]==0){
	int j=0;
	for(int i=1;i<=3;i++)//right search
		 if(M[5-i][0]==0)
		  j++;
	if(j==3){
	for(int i=1;i!=-1;i++){//right search
			  if(M[2][0+i]<0&&(0+i)<=7){
			  M[2][0]=M[2][0+i];
			  x11[(M[2][0+i]+16)]-=i*1.9;
			  M[2][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[5][8]  M[2][0]  1\n";
			  return 1;
			  }
			  else if(M[6][0+i]>0||(0+i)>7){
				  i=-2;
			cout<<"\nMB king:M[5][8]  M[2][0] 2\n";
			  }
			  }
	for(int i=1;i!=-1;i++){//right search
			  if(M[1][0+i]<0&&(0+i)<=6){
			  M[1][0]=M[1][0+i];
			  x11[(M[1][0+i]+16)]-=i*1.9;
			  M[1][0+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[3][8]  M[1][0]  1\n";
			  return 1;
			  }
			  else if(M[1][0+i]>0||(0+i)>6){
				  i=-2;
			cout<<"\nMB king:M[3][8]  M[1][0] 2\n";
			  }
			  }


	
	}
	}


	}


	}

}//end of a=6 b=8

//------------------------------------------------------------------------------4 goosheh
else if(a==1&&b==1){
	if(M[0][1]==0){
		for(int i=1;i!=-1;i++){//right search
			  if(M[0][1+i]<0&&(1+i)<=8){
			  M[0][1]=M[0][1+i];
			  x11[(M[0][1+i]+16)]-=i*1.9;
			  M[0][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][1]  M[0][1]  1\n";
			  return 1;
			  }
			  else if(M[0][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[0][1] 2\n";
			  }
			  }
	
	}

	if(M[1][0]==0){
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][0]<0&&(1+i)<=8){
			 M[1][0]=M[1+i][0];
			 y11[(M[1+i][0]+16)]+=i*1.9;
			 M[1+i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][1]  M[1][0] 1 \n";
			 return 1;
			 }
			 else if(M[1+i][0]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[1][0] 2 \n";
			 }
		     }
	
	}
	if(M[1][7]==0&&M[1][8]==0){
	int j=0;
	for(int i=1;i<=5;i++)//right search
		 if(M[1][1+i]==0)
		  j++;
	if(j==5){
			for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][7]<0&&(1+i)<=8){
			 M[1][7]=M[1+i][7];
			 y11[(M[1+i][7]+16)]+=i*1.9;
			 M[1+i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][1]  M[1][7] 1 \n";
			 return 1;
			 }
			 else if(M[1+i][7]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[1][7] 2 \n";
			 }
		     }

			if(M[0][7]<0){
			M[1][7]=M[0][7];
			 y11[(M[0][7]+16)]-=1.9;
			 M[0][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][1]  M[1][7] 3 \n";
			 return 1;
			
			}

			for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][8]<0&&(1+i)<=8){
			 M[1][8]=M[1+i][8];
			 y11[(M[1+i][8]+16)]+=i*1.9;
			 M[1+i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][1]  M[1][8] 1 \n";
			 return 1;
			 }
			 else if(M[1+i][8]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[1][8] 2 \n";
			 }
		     }
	
	
	}
	
	
	}//M[1][7]==0&&M[1][8]==0


	if(M[7][1]==0&&M[8][1]==0){
	int j=0;
	for(int i=1;i<=5;i++)//down search
		 if(M[1+i][1]==0)
		  j++;
	if(j==5){
				for(int i=1;i!=-1;i++){//right search
			  if(M[7][1+i]<0&&(1+i)<=8){
			  M[7][1]=M[7][1+i];
			  x11[(M[7][1+i]+16)]-=i*1.9;
			  M[7][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][1]  M[7][1]  1\n";
			  return 1;
			  }
			  else if(M[7][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[7][1] 2\n";
			  }
			  }

			if(M[7][0]<0){
			M[7][1]=M[7][0];
			 x11[(M[7][0]+16)]+=1.9;
			 M[7][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][1]  M[7][1] 3 \n";
			 return 1;
			
			}

			  for(int i=1;i!=-1;i++){//right search
			  if(M[8][1+i]<0&&(1+i)<=8){
			  M[8][1]=M[8][1+i];
			  x11[(M[8][1+i]+16)]-=i*1.9;
			  M[8][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][1]  M[8][1]  1\n";
			  return 1;
			  }
			  else if(M[8][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[8][1] 2\n";
			  }
			  }
	
	
	}
	
	
	}//M[7][1]==0&&M[7][1]==0
	if(M[1][7]==0&&M[1][8]<0){
		int j=0;
	for(int i=1;i<=5;i++)//right search
		 if(M[1][1+i]==0)
		  j++;
	if(j==5){
			 M[1][7]=M[1][8];
			  x11[(M[1][8]+16)]-=1.9;
			  M[1][8]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][1]  M[1][7]  por por\n";
			  return 1;
	}
	
	}//end of M[1][7]==0&&M[1][8]<0

	if(M[7][1]==0&&M[8][1]<0){
	int j=0;
	for(int i=1;i<=5;i++)//down search
		 if(M[1+i][1]==0)
		  j++;
	if(j==5){
			 M[7][1]=M[8][1];
			  y11[(M[8][1]+16)]+=1.9;
			  M[8][1]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][1]  M[7][1]  por por\n";
			  return 1;
	}
	
	}//end of M[7][1]==0&&M[8][1]<0



}//end of a==1&&b==1


else if(a==1&&b==7){
	if(M[0][7]==0){
		for(int i=1;i!=-1;i++){//left search
			  if(M[0][7-i]<0&&(7-i)>=0){
			  M[0][7]=M[0][7-i];
			  x11[(M[0][7-i]+16)]+=i*1.9;
			  M[0][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][7]  M[0][7] 1\n";
			  return 1;
			  
			  }
			  else if(M[2][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[1][7]  M[0][7] 2\n";
			  }
			}
	
	}

	if(M[1][8]==0){
		for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][8]<0&&(1+i)<=8){
			 M[1][8]=M[1+i][8];
			 y11[(M[1+i][8]+16)]+=i*1.9;
			 M[1+i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][7]  M[1][8] 1 \n";
			 return 1;
			 }
			 else if(M[1+i][8]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][7]  M[1][8] 2 \n";
			 }
		     }
	
	}
	if(M[1][1]==0&&M[1][0]==0){
	int j=0;
	for(int i=1;i<=5;i++)//left search
		 if(M[1][7-i]==0)
		  j++;
	if(j==5){
			for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][1]<0&&(1+i)<=8){
			 M[1][1]=M[1+i][1];
			 y11[(M[1+i][1]+16)]+=i*1.9;
			 M[1+i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][7]  M[1][1] 1 \n";
			 return 1;
			 }
			 else if(M[1+i][1]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][7]  M[1][1] 2 \n";
			 }
		     }

			if(M[0][1]<0){
			M[1][1]=M[0][1];
			 y11[(M[0][1]+16)]-=1.9;
			 M[0][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][7]  M[1][1] 3 \n";
			 return 1;
			
			}

			for(int i=1;i!=-1;i++){//down search
			  if(M[1+i][0]<0&&(1+i)<=8){
			 M[1][0]=M[1+i][0];
			 y11[(M[1+i][0]+16)]+=i*1.9;
			 M[1+i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][7]  M[1][0] 1 \n";
			 return 1;
			 }
			 else if(M[1+i][0]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][7]  M[1][0] 2 \n";
			 }
		     }
	
	
	}
	
	
	}//M[1][1]==0&&M[1][0]==0


	if(M[7][7]==0&&M[8][7]==0){
	int j=0;
	for(int i=1;i<=5;i++)//down search
		 if(M[1+i][7]==0)
		  j++;
	if(j==5){
			for(int i=1;i!=-1;i++){//left search
			  if(M[7][7-i]<0&&(7-i)>=0){
			  M[7][7]=M[7][7-i];
			  x11[(M[7][7-i]+16)]+=i*1.9;
			  M[7][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][7]  M[7][7] 1\n";
			  return 1;
			  
			  }
			  else if(M[7][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[1][7]  M[7][7] 2\n";
			  }
			}

			if(M[7][8]<0){
			M[7][7]=M[7][8];
			 x11[(M[7][8]+16)]-=1.9;
			 M[7][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[1][7]  M[7][7] 3 \n";
			 return 1;
			
			}

			 for(int i=1;i!=-1;i++){//left search
			  if(M[8][7-i]<0&&(7-i)>=0){
			  M[8][7]=M[8][7-i];
			  x11[(M[8][7-i]+16)]+=i*1.9;
			  M[8][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][7]  M[8][7] 1\n";
			  return 1;
			  
			  }
			  else if(M[8][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[1][7]  M[8][7] 2\n";
			  }
			}
	
	
	}
	
	
	}//M[7][7]==0&&M[8][7]==0
	if(M[1][1]==0&&M[1][0]<0){
		int j=0;
	for(int i=1;i<=5;i++)//left search
		 if(M[1][7-i]==0)
		  j++;
	if(j==5){
			 M[1][1]=M[1][0];
			  x11[(M[1][0]+16)]+=1.9;
			  M[1][0]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][7]  M[1][1]  por por\n";
			  return 1;
	}
	
	}//end of M[1][1]==0&&M[1][0]<0

	if(M[7][7]==0&&M[7][8]<0){
	int j=0;
	for(int i=1;i<=5;i++)//down search
		 if(M[1+i][7]==0)
		  j++;
	if(j==5){
			 M[7][7]=M[8][7];
			  y11[(M[8][7]+16)]+=1.9;
			  M[8][7]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][7]  M[7][7]  por por\n";
			  return 1;
	}
	
	}//end of M[7][7]==0&&M[7][8]<0



}//end of a==1&&b==7

else if(a==7&&b==1){
	if(M[7][0]==0){
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][0]<0&&(7-i)>=0){
			 M[7][0]=M[7-i][0];
			 y11[(M[7-i][0]+16)]-=i*1.9;
			 M[7-i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][1]  M[7][0] 1 \n";
			 return 1;
			 }
			 else if(M[7-i][0]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[7][1]  M[7][0] 2 \n";
			 }
		}
	
	}

	if(M[8][1]==0){
		 for(int i=1;i!=-1;i++){//right search
			  if(M[8][1+i]<0&&(1+i)<=8){
			  M[8][1]=M[8][1+i];
			  x11[(M[8][1+i]+16)]-=i*1.9;
			  M[8][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[1][1]  M[8][1]  1\n";
			  return 1;
			  }
			  else if(M[8][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[1][1]  M[8][1] 2\n";
			  }
			  }
	
	}
	if(M[1][1]==0&&M[0][1]==0){
	int j=0;
	for(int i=1;i<=5;i++)//up search
		 if(M[7-i][1]==0)
		  j++;
	if(j==5){
			 for(int i=1;i!=-1;i++){//right search
			  if(M[1][1+i]<0&&(1+i)<=8){
			  M[1][1]=M[1][1+i];
			  x11[(M[1][1+i]+16)]-=i*1.9;
			  M[1][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][1]  M[1][1]  1\n";
			  return 1;
			  }
			  else if(M[1][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[7][1]  M[1][1] 2\n";
			  }
			  }

			if(M[1][0]<0){
			M[1][1]=M[1][0];
			 x11[(M[1][0]+16)]+=1.9;
			 M[1][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][1]  M[1][1] 3 \n";
			 return 1;
			
			}

			 for(int i=1;i!=-1;i++){//right search
			  if(M[0][1+i]<0&&(1+i)<=8){
			  M[0][1]=M[0][1+i];
			  x11[(M[0][1+i]+16)]-=i*1.9;
			  M[0][1+i]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][1]  M[0][1]  1\n";
			  return 1;
			  }
			  else if(M[1][1+i]>0||(1+i)>8){
				  i=-2;
			cout<<"\nMB king:M[7][1]  M[0][1] 2\n";
			  }
			  }
	
	
	}
	
	
	}//M[1][1]==0&&M[0][1]==0


	if(M[7][7]==0&&M[7][8]==0){
	int j=0;
	for(int i=1;i<=5;i++)//right search
		 if(M[7][1+i]==0)
		  j++;
	if(j==5){
			for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][7]<0&&(7-i)>=0){
			 M[7][7]=M[7-i][7];
			 y11[(M[7-i][7]+16)]-=i*1.9;
			 M[7-i][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][1]  M[7][7] 1 \n";
			 return 1;
			 }
			 else if(M[7-i][7]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[7][1]  M[7][7] 2 \n";
			 }
		}

			if(M[8][7]<0){
			M[7][7]=M[8][7];
			y11[(M[8][7]+16)]+=1.9;
			 M[8][7]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][1]  M[7][7] 3 \n";
			 return 1;
			
			}

			for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][8]<0&&(7-i)>=0){
			 M[7][8]=M[7-i][8];
			 y11[(M[7-i][8]+16)]-=i*1.9;
			 M[7-i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][1]  M[7][8] 1 \n";
			 return 1;
			 }
			 else if(M[7-i][8]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[7][1]  M[7][8] 2 \n";
			 }
		}
	
	
	}
	
	
	}//M[7][7]==0&&M[7][8]==0
	if(M[7][7]==0&&M[7][8]<0){
		int j=0;
	for(int i=1;i<=5;i++)//right search
		 if(M[7][1+i]==0)
		  j++;
	if(j==5){
			 M[7][7]=M[7][8];
			  x11[(M[7][8]+16)]-=1.9;
			  M[7][8]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][1]  M[7][7]  por por\n";
			  return 1;
	}
	
	}//end of M[7][7]==0&&M[7][8]<0

	if(M[1][1]==0&&M[0][1]<0){
	int j=0;
	for(int i=1;i<=5;i++)//up search
		 if(M[7-i][1]==0)
		  j++;
	if(j==5){
			 M[1][1]=M[0][1];
			  y11[(M[0][1]+16)]-=1.9;
			  M[0][1]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][1]  M[1][1]  por por\n";
			  return 1;
	}
	
	}//end of M[1][1]==0&&M[0][1]<0


}//end of a==7&&b==1

else if(a==7&&b==7){
	if(M[7][8]==0){
		for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][8]<0&&(7-i)>=0){
			 M[7][8]=M[7-i][8];
			 y11[(M[7-i][8]+16)]-=i*1.9;
			 M[7-i][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][7]  M[7][8] 1 \n";
			 return 1;
			 }
			 else if(M[7-i][8]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[7][7]  M[7][8] 2 \n";
			 }
		}
	
	}

	if(M[8][7]==0){
		  for(int i=1;i!=-1;i++){//left search
			  if(M[8][7-i]<0&&(7-i)>=0){
			  M[8][7]=M[8][7-i];
			  x11[(M[8][7-i]+16)]+=i*1.9;
			  M[8][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][7]  M[8][7] 1\n";
			  return 1;
			  
			  }
			  else if(M[8][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[7][7]  M[8][7] 2\n";
			  }
			}
	
	}
	if(M[1][7]==0&&M[0][7]==0){
	int j=0;
	for(int i=1;i<=5;i++)//up search
		 if(M[7-i][7]==0)
		  j++;
	if(j==5){
			 for(int i=1;i!=-1;i++){//left search
			  if(M[1][7-i]<0&&(7-i)>=0){
			  M[1][7]=M[1][7-i];
			  x11[(M[1][7-i]+16)]+=i*1.9;
			  M[1][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][7]  M[1][7] 1\n";
			  return 1;
			  
			  }
			  else if(M[1][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[7][7]  M[1][7] 2\n";
			  }
			}

			if(M[1][8]<0){
			M[1][7]=M[1][8];
			 x11[(M[1][8]+16)]-=1.9;
			 M[1][8]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][7]  M[1][7] 3 \n";
			 return 1;
			
			}

			 for(int i=1;i!=-1;i++){//left search
			  if(M[0][7-i]<0&&(7-i)>=0){
			  M[0][7]=M[0][7-i];
			  x11[(M[0][7-i]+16)]+=i*1.9;
			  M[0][7-i]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][7]  M[0][7] 1\n";
			  return 1;
			  
			  }
			  else if(M[0][7-i]>0||(7-i)<0){
				 i=-2; 
			cout<<"\nMB king:M[7][7]  M[0][7] 2\n";
			  }
			}
	
	}
	
	
	}//M[1][7]==0&&M[0][7]==0


	if(M[7][1]==0&&M[7][0]==0){
	int j=0;
	for(int i=1;i<=5;i++)//left search
		 if(M[7][7-i]==0)
		  j++;
	if(j==5){
			for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][1]<0&&(7-i)>=0){
			 M[7][1]=M[7-i][1];
			 y11[(M[7-i][1]+16)]-=i*1.9;
			 M[7-i][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][7]  M[7][1] 1 \n";
			 return 1;
			 }
			 else if(M[7-i][7]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[7][7]  M[7][1] 2 \n";
			 }
		}

			if(M[8][1]<0){
			M[7][1]=M[8][1];
			y11[(M[8][1]+16)]+=1.9;
			 M[8][1]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][7]  M[7][1] 3 \n";
			 return 1;
			
			}

			for(int i=1;i!=-1;i++){//up search
			  if(M[7-i][0]<0&&(7-i)>=0){
			 M[7][0]=M[7-i][0];
			 y11[(M[7-i][0]+16)]-=i*1.9;
			 M[7-i][0]=0;
			 flag=0;
			 cout<<"\nMB king:M[7][7]  M[7][0] 1 \n";
			 return 1;
			 }
			 else if(M[7-i][8]>0||(7-i)<0){
				  i=-2;
			cout<<"\nMB king:M[7][7]  M[7][0] 2 \n";
			 }
		}
	
	
	}
	
	
	}//M[7][0]==0&&M[7][1]==0
	if(M[1][7]==0&&M[0][7]<0){
	int j=0;
	for(int i=1;i<=5;i++)//up search
		 if(M[7-i][7]==0)
		  j++;
	if(j==5){
			 M[1][7]=M[0][7];
			  y11[(M[0][7]+16)]-=1.9;
			  M[0][7]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][7]  M[1][7]  por por\n";
			  return 1;
	}
	
	}//end of M[1][7]==0&&M[0][7]<0

	if(M[7][1]==0&&M[7][0]<0){
	int j=0;
	for(int i=1;i<=5;i++)//left search
		 if(M[7][7-i]==0)
		  j++;
	if(j==5){
			 M[7][1]=M[7][0];
			  x11[(M[7][0]+16)]+=1.9;
			  M[7][0]=0;
			  flag=0;
			  cout<<"\nMB king:M[7][7]  M[7][1]  por por\n";
			  return 1;
	}
	
	}//end of M[7][1]==0&&M[7][0]<0



}//end of a==7&&b==7

//----------------------------end of 4 goosh
//ring 2
else if(a==1&&b==2){
	if(zs(1,1,1,0)){
	if(ns(1,1,0,1))
		return 1;
	if(ns(1,1,8,1))
		return 1;
	if(ns(1,0,8,1))
		return 1;
	}
	if(zs(1,3,1,8)){
	if(ns(1,7,0,7))
		return 1;
	if(ns(1,7,8,7))
		return 1;
	if(ns(1,8,8,8))
		return 1;
	}
	if(M[0][2]==0){
	if(ns(0,2,0,1))
		return 1;
	if(ns(0,2,0,8))
		return 1;
	}
	if(zs(2,2,8,2)){
	if(ns(8,2,8,1))
		return 1;
	if(ns(8,2,8,8))
		return 1;
	}
}

else if(a==1&&b==6){
	if(zs(1,7,1,8)){
	if(ns(1,7,0,7))
		return 1;
	if(ns(1,7,8,7))
		return 1;
	if(ns(1,8,8,8))
		return 1;
	}
	if(zs(1,5,1,0)){
	if(ns(1,1,0,1))
		return 1;
	if(ns(1,1,8,1))
		return 1;
	if(ns(1,0,8,0))
		return 1;
	}
	if(M[0][6]==0){
	if(ns(0,6,0,7))
		return 1;
	if(ns(0,6,0,1))
		return 1;
	}
	if(zs(2,6,8,6)){
	if(ns(8,6,8,7))
		return 1;
	if(ns(8,6,8,1))
		return 1;
	}
}


else if(a==7&&b==2){
	if(zs(7,1,7,0)){
	if(ns(7,1,8,1))
		return 1;
	if(ns(7,1,0,1))
		return 1;
	if(ns(7,0,1,0))
		return 1;
	}
	if(zs(7,3,7,8)){
	if(ns(7,7,8,7))
		return 1;
	if(ns(7,7,0,7))
		return 1;
	if(ns(7,8,1,8))
		return 1;
	}
	if(M[8][2]==0){
	if(ns(8,2,8,1))
		return 1;
	if(ns(8,2,8,7))
		return 1;
	}
	if(zs(6,2,0,2)){
	if(ns(0,2,0,1))
		return 1;
	if(ns(0,2,0,7))
		return 1;
	}
}
else if(a==7&&b==6){
	if(zs(7,7,7,8)){
	if(ns(7,7,8,7))
		return 1;
	if(ns(7,7,0,7))
		return 1;
	if(ns(7,8,1,8))
		return 1;
	}
	if(zs(7,5,7,0)){
	if(ns(7,1,8,1))
		return 1;
	if(ns(7,1,0,1))
		return 1;
	if(ns(7,0,1,0))
		return 1;
	}
	if(M[8][6]==0){
	if(ns(8,6,8,7))
		return 1;
	if(ns(8,6,8,1))
		return 1;
	}
	if(zs(6,6,0,6)){
	if(ns(0,6,0,7))
		return 1;
	if(ns(0,6,0,1))
		return 1;
	}
}

else if(a==2&&b==1){
	if(zs(1,1,0,1)){
	if(ns(1,1,1,0))
		return 1;
	if(ns(1,1,1,8))
		return 1;
	if(ns(0,1,0,7))
		return 1;
	}
	if(zs(3,1,8,1)){
	if(ns(7,1,7,0))
		return 1;
	if(ns(7,1,7,8))
		return 1;
	if(ns(8,1,8,7))
		return 1;
	}
	if(M[2][0]==0){
	if(ns(2,0,1,0))
		return 1;
	if(ns(2,0,7,0))
		return 1;
	}
	if(zs(2,2,2,8)){
	if(ns(2,8,1,8))
		return 1;
	if(ns(2,8,7,8))
		return 1;
	}
}
else if(a==6&&b==1){
	if(zs(7,1,8,1)){
	if(ns(7,1,7,0))
		return 1;
	if(ns(7,1,7,8))
		return 1;
	if(ns(8,1,8,7))
		return 1;
	}
	if(zs(5,1,0,1)){
	if(ns(1,1,1,0))
		return 1;
	if(ns(1,1,1,8))
		return 1;
	if(ns(0,1,0,7))
		return 1;
	}
	if(M[6][0]==0){
	if(ns(6,0,7,0))
		return 1;
	if(ns(6,0,1,0))
		return 1;
	}
	if(zs(6,2,6,8)){
	if(ns(6,8,7,8))
		return 1;
	if(ns(6,8,1,8))
		return 1;
	}
}


else if(a==2&&b==7){
	if(zs(1,7,0,7)){
	if(ns(1,7,1,8))
		return 1;
	if(ns(1,7,1,0))
		return 1;
	if(ns(0,7,0,1))
		return 1;
	}
	if(zs(3,7,8,7)){
	if(ns(7,7,7,8))
		return 1;
	if(ns(7,7,7,0))
		return 1;
	if(ns(8,7,8,1))
		return 1;
	}
	if(M[2][8]==0){
	if(ns(2,8,1,8))
		return 1;
	if(ns(2,8,7,8))
		return 1;
	}
	if(zs(2,6,2,0)){
	if(ns(2,0,1,0))
		return 1;
	if(ns(2,0,7,0))
		return 1;
	}
}
else if(a==6&&b==7){
	if(zs(7,7,8,7)){
	if(ns(7,7,7,8))
		return 1;
	if(ns(7,7,7,0))
		return 1;
	if(ns(8,7,8,1))
		return 1;
	}
	if(zs(5,7,0,7)){
	if(ns(1,7,1,8))
		return 1;
	if(ns(1,7,1,0))
		return 1;
	if(ns(0,7,0,1))
		return 1;
	}
	if(M[6][8]==0){
	if(ns(6,8,7,8))
		return 1;
	if(ns(6,8,1,8))
		return 1;
	}
	if(zs(6,6,6,8)){
	if(ns(6,0,7,0))
		return 1;
	if(ns(6,0,1,0))
		return 1;
	}
}
//-------------------------------
else if(a==1&&b==3){
    if(zs(1,2,1,0)){
	if(ns(1,1,0,1))
		return 1;
	if(ns(1,1,8,1))
	return 1;
	if(ns(1,0,8,1))
	return 1;
	}
	if(zs(1,4,1,8)){
	if(ns(1,7,0,7))
		return 1;
	if(ns(1,7,8,7))
	return 1;
	if(ns(1,8,8,8))
	return 1;
	}
	if(zs(0,3,0,1)){
	if(ns(0,2,0,1))
		return 1;
	if(ns(0,2,8,2))
	return 1;
	}
	if(zs(0,3,0,8)){
	if(ns(0,6,0,7))
		return 1;
	if(ns(0,6,8,6))
	return 1;
	}
	if(zs(2,3,8,3)){
		if(zs(8,2,8,1)){
		if(ns(8,2,8,1))
			return 1;
	    if(ns(8,2,2,2))
		return 1;
		}
		if(zs(8,4,8,7)){
		if(ns(8,6,8,7))
			return 1;
	    if(ns(8,6,2,6))
		return 1;
		}
	}
}
else if(a==1&&b==5){
    if(zs(1,6,1,8)){
	if(ns(1,7,0,7))
		return 1;
	if(ns(1,7,8,7))
	return 1;
	if(ns(1,8,7,8))
	return 1;
	}
	if(zs(1,4,1,0)){
	if(ns(1,1,0,1))
		return 1;
	if(ns(1,1,8,1))
	return 1;
	if(ns(1,0,7,0))
	return 1;
	}
	if(zs(0,5,0,7)){
	if(ns(0,6,0,7))
		return 1;
	if(ns(0,6,8,6))
	return 1;
	}
	if(zs(0,5,0,1)){
	if(ns(0,2,0,1))
		return 1;
	if(ns(0,2,8,2))
	return 1;
	}
	if(zs(2,5,8,5)){
		if(zs(8,6,8,7)){
		if(ns(8,6,8,7))
			return 1;
	    if(ns(8,6,2,6))
		return 1;
		}
		if(zs(8,4,8,1)){
		if(ns(8,2,8,1))
			return 1;
	    if(ns(8,2,2,2))
		return 1;
		}
	}
}
else if(a==1&&b==4){
    if(zs(1,5,1,8)){
	if(ns(1,7,0,7))
		return 1;
	if(ns(1,7,8,7))
	return 1;
	if(ns(1,8,7,8))
	return 1;
	}
	if(zs(1,3,1,0)){
	if(ns(1,1,0,1))
		return 1;
	if(ns(1,1,8,1))
	return 1;
	if(ns(1,0,7,0))
	return 1;
	}
	if(zs(0,4,0,7)){
	if(ns(0,6,0,7))
		return 1;
	if(ns(0,6,8,6))
	return 1;
	}
	if(zs(0,4,0,1)){
	if(ns(0,2,0,1))
		return 1;
	if(ns(0,2,8,2))
	return 1;
	}
	if(zs(2,4,8,4)){
		if(zs(8,5,8,7)){
		if(ns(8,6,8,7))
			return 1;
	    if(ns(8,6,2,6))
		return 1;
		}
		if(zs(8,3,8,1)){
		if(ns(8,2,8,1))
			return 1;
	    if(ns(8,2,2,2))
		return 1;
		}
	}
}

else if(a==7&&b==3){
    if(zs(7,2,7,0)){
	if(ns(7,1,8,1))
		return 1;
	if(ns(7,1,0,1))
	return 1;
	if(ns(7,0,1,0))
	return 1;
	}
	if(zs(7,4,7,8)){
	if(ns(7,7,8,7))
		return 1;
	if(ns(7,7,0,7))
	return 1;
	if(ns(7,8,1,8))
	return 1;
	}
	if(zs(8,3,8,1)){
	if(ns(8,2,8,1))
		return 1;
	if(ns(8,2,0,2))
	return 1;
	}
	if(zs(8,3,8,7)){
	if(ns(8,6,8,7))
		return 1;
	if(ns(8,6,0,6))
	return 1;
	}
	
	if(zs(6,3,0,3)){
		if(zs(0,2,0,1)){
		if(ns(0,2,0,1))
			return 1;
	    if(ns(0,2,6,2))
		return 1;
		}
		if(zs(0,4,0,7)){
		if(ns(0,6,0,7))
			return 1;
	    if(ns(0,6,6,6))
		return 1;
		}
	}
}
else if(a==7&&b==5){
    if(zs(7,6,7,8)){
	if(ns(7,7,8,7))
		return 1;
	if(ns(7,7,0,7))
		return 1;
	if(ns(7,8,1,8))
		return 1;
	}
	if(zs(7,4,7,0)){
	if(ns(7,1,8,1))
	return 1;
	if(ns(7,1,0,1))
	return 1;
	if(ns(7,0,1,0))
	return 1;
	}
	if(zs(8,5,8,7)){
	if(ns(8,6,8,7))
		return 1;
	if(ns(8,6,0,6))
	return 1;
	}
	if(zs(8,5,8,1)){
	if(ns(8,2,8,1))
		return 1;
	if(ns(8,2,0,2))
	return 1;
	}
	if(zs(6,5,0,5)){
		if(zs(0,6,0,7)){
		if(ns(0,6,0,7))
			return 1;
	    if(ns(0,6,6,6))
		return 1;
		}
		if(zs(0,4,0,1)){
		if(ns(0,2,0,1))
			return 1;
	    if(ns(0,2,6,2))
		return 1;
		}
	}
}
else if(a==7&&b==4){
    if(zs(7,5,7,8)){
	if(ns(7,7,8,7))
		return 1;
	if(ns(7,7,0,7))
	return 1;
	if(ns(7,8,1,8))
	return 1;
	}
	if(zs(7,3,7,0)){
	if(ns(7,1,8,1))
		return 1;
	if(ns(7,1,0,1))
	return 1;
	if(ns(7,0,1,0))
	return 1;
	}
	if(zs(8,4,8,7)){
	if(ns(8,6,8,7))
		return 1;
	if(ns(8,6,0,6))
	return 1;
	}
	if(zs(8,4,8,1)){
	if(ns(8,2,8,1))
		return 1;
	if(ns(8,2,0,2))
	return 1;
	}
	if(zs(6,4,0,4)){
		if(zs(0,5,0,7)){
		if(ns(0,6,0,7))
			return 1;
	    if(ns(0,6,6,6))
		return 1;
		}
		if(zs(0,3,0,1)){
		if(ns(0,2,0,1))
			return 1;
	    if(ns(0,2,6,2))
		return 1;
		}
	}
}
//--------------------------
else if(a==3&&b==1){
    if(zs(2,1,0,1)){
	if(ns(1,1,1,0))
		return 1;
	if(ns(1,1,1,8))
	return 1;
	if(ns(0,1,0,7))
	return 1;
	}
	if(zs(4,1,8,1)){
	if(ns(7,1,7,0))
		return 1;
	if(ns(7,1,7,8))
	return 1;
	if(ns(8,1,8,7))
	return 1;
	}
	if(zs(3,0,1,0)){
	if(ns(2,0,1,0))
		return 1;
	if(ns(2,0,2,8))
	return 1;
	}
	if(zs(3,0,7,0)){
	if(ns(6,0,7,0))
		return 1;
	if(ns(6,0,6,8))
	return 1;
	}
	
	if(zs(3,2,3,8)){
		if(zs(2,8,1,8)){
		if(ns(2,8,1,8))
			return 1;
	    if(ns(2,8,2,2))
		return 1;
		}
		if(zs(4,8,7,8)){
		if(ns(6,8,7,8))
			return 1;
	    if(ns(6,8,6,2))
		return 1;
		}
	}
}
else if(a==5&&b==1){
    if(zs(4,1,0,1)){
	if(ns(1,1,1,0))
		return 1;
	if(ns(1,1,1,8))
	return 1;
	if(ns(0,1,0,7))
	return 1;
	}
	if(zs(6,1,8,1)){
	if(ns(7,1,7,0))
		return 1;
	if(ns(7,1,7,8))
	return 1;
	if(ns(8,1,8,7))
	return 1;
	}
	if(zs(5,0,7,0)){
	if(ns(6,0,7,0))
		return 1;
	if(ns(6,0,6,8))
	return 1;
	}
	if(zs(5,0,1,0)){
	if(ns(2,0,1,0))
		return 1;
	if(ns(2,0,2,8))
	return 1;
	}
	
	if(zs(5,2,5,8)){
		if(zs(6,8,7,8)){
		if(ns(6,8,7,8))
			return 1;
	    if(ns(6,8,6,2))
		return 1;
		}
		if(zs(4,8,1,8)){
		if(ns(2,8,1,8))
			return 1;
	    if(ns(2,8,2,2))
		return 1;
		}
	}
}
else if(a==4&&b==1){
     if(zs(3,1,0,1)){
	if(ns(1,1,1,0))
		return 1;
	if(ns(1,1,1,8))
		return 1;
	if(ns(0,1,0,7))
		return 1;
	}
	if(zs(5,1,8,1)){
	if(ns(7,1,7,0))
		return 1;
	if(ns(7,1,7,8))
		return 1;
	if(ns(8,1,8,7))
		return 1;
	}
	if(zs(4,0,7,0)){
	if(ns(6,0,7,0))
		return 1;
	if(ns(6,0,6,8))
		return 1;
	}
	if(zs(4,0,1,0)){
	if(ns(2,0,1,0))
		return 1;
	if(ns(2,0,2,8))
		return 1;
	}
	
	if(zs(4,2,4,8)){
		if(zs(5,8,7,8)){
		if(ns(6,8,7,8))
			return 1;
	    if(ns(6,8,6,2))
			return 1;
		}
		if(zs(3,8,1,8)){
		if(ns(2,8,1,8))
			return 1;
	    if(ns(2,8,2,2))
			return 1;
		}
	}
}


else if(a==3&&b==7){
    if(zs(2,7,0,7)){
	if(ns(1,7,1,8))
		return 1;
	if(ns(1,7,1,0))
	return 1;
	if(ns(0,7,0,1))
	return 1;
	}
	if(zs(4,7,8,7)){
	if(ns(7,7,7,8))
		return 1;
	if(ns(7,7,7,0))
	return 1;
	if(ns(8,7,8,1))
	return 1;
	}
	if(zs(3,8,1,8)){
	if(ns(2,8,1,8))
		return 1;
	if(ns(2,8,2,0))
	return 1;
	}
	if(zs(3,8,7,8)){
	if(ns(6,8,7,8))
		return 1;
	if(ns(6,8,6,0))
	return 1;
	}
	
	if(zs(3,6,3,0)){
		if(zs(2,0,1,0)){
		if(ns(2,0,1,0))
			return 1;
	    if(ns(2,0,2,6))
		return 1;
		}
		if(zs(4,0,7,0)){
		if(ns(6,0,7,0))
			return 1;
	    if(ns(6,0,6,6))
		return 1;
		}
	}
}
else if(a==5&&b==7){
    if(zs(4,7,0,7)){
	if(ns(1,7,1,8))
		return 1;
	if(ns(1,7,1,0))
	return 1;
	if(ns(0,7,0,1))
	return 1;
	}
	if(zs(6,7,8,7)){
	if(ns(7,7,7,8))
		return 1;
	if(ns(7,7,7,0))
	return 1;
	if(ns(8,7,8,1))
	return 1;
	}
	if(zs(5,8,1,8)){
	if(ns(2,8,1,8))
		return 1;
	if(ns(2,8,2,0))
	return 1;
	}
	if(zs(5,8,7,8)){
	if(ns(6,8,7,8))
		return 1;
	if(ns(6,8,6,0))
	return 1;
	}
	
	if(zs(5,6,5,0)){
		if(zs(4,0,1,0)){
		if(ns(2,0,1,0))
			return 1;
	    if(ns(2,0,2,6))
		return 1;
		}
		if(zs(6,0,7,0)){
		if(ns(6,0,7,0))
			return 1;
	    if(ns(6,0,6,6))
		return 1;
		}
	}
}
else if(a==4&&b==7){
   if(zs(3,7,0,7)){
	if(ns(1,7,1,8))
		return 1;
	if(ns(1,7,1,0))
	return 1;
	if(ns(0,7,0,1))
	return 1;
	}
	if(zs(5,7,8,7)){
	if(ns(7,7,7,8))
		return 1;
	if(ns(7,7,7,0))
	return 1;
	if(ns(8,7,8,1))
	return 1;
	}
	if(zs(4,8,1,8)){
	if(ns(2,8,1,8))
		return 1;
	if(ns(2,8,2,0))
	return 1;
	}
	if(zs(4,8,7,8)){
	if(ns(6,8,7,8))
		return 1;
	if(ns(6,8,6,0))
	return 1;
	}
	
	if(zs(4,6,4,0)){
		if(zs(3,0,1,0)){
		if(ns(2,0,1,0))
			return 1;
	    if(ns(2,0,2,6))
		return 1;
		}
		if(zs(5,0,7,0)){
		if(ns(6,0,7,0))
			return 1;
	    if(ns(6,0,6,6))
		return 1;
		}
	}
}
//end of ring 2
//ring 3
else if(a==2&&b==2){
	if(zs(2,1,2,0)){
		if(ns(2,0,1,0))
			return 1;
		if(ns(2,0,7,0))
		return 1;
	}
	if(zs(1,2,0,2)){
		if(ns(0,2,0,1))
			return 1;
		if(ns(0,2,0,7))
		return 1;
	}
	if(zs(2,3,2,8)){
		if(ns(2,8,1,8))
			return 1;
		if(ns(2,8,7,8))
		return 1;
	}
	if(zs(3,2,8,2)){
		if(ns(8,2,8,1))
			return 1;
		if(ns(8,2,8,7))
		return 1;
	}
}
else if(a==2&&b==6){
	if(zs(2,7,2,8)){
		if(ns(2,8,1,8))
			return 1;
		if(ns(2,8,7,8))
		return 1;
	}
	if(zs(1,6,0,6)){
		if(ns(0,6,0,7))
			return 1;
		if(ns(0,6,0,1))
		return 1;
	}
	if(zs(2,5,2,0)){
		if(ns(2,0,1,0))
			return 1;
		if(ns(2,0,7,0))
		return 1;
	}
	if(zs(3,6,8,6)){
		if(ns(8,6,8,7))
			return 1;
		if(ns(8,6,8,1))
		return 1;
	}
}
else if(a==6&&b==2){
	if(zs(6,1,6,0)){
		if(ns(2,8,1,8))
			return 1;
		if(ns(2,8,7,8))
		return 1;
	}
	
	if(zs(7,2,8,2)){
		if(ns(8,2,8,1))
			return 1;
		if(ns(8,2,8,7))
		return 1;
	}
	if(zs(5,2,0,2)){
		if(ns(0,2,0,1))
			return 1;
		if(ns(0,2,0,7))
		return 1;
	}
	if(zs(6,3,6,8)){
		if(ns(6,8,7,8))
			return 1;
		if(ns(6,8,1,8))
		return 1;
	}
}
else if(a==6&&b==6){
	if(zs(6,7,6,8)){
		if(ns(6,8,7,8))
			return 1;
		if(ns(6,8,1,8))
		return 1;
	}
	if(zs(7,6,8,6)){
		if(ns(8,6,8,7))
			return 1;
		if(ns(8,6,8,1))
		return 1;
	}
	if(zs(5,6,0,6)){
		if(ns(0,6,0,7))
			return 1;
		if(ns(0,6,0,1))
		return 1;
	}
	if(zs(6,5,6,0)){
		if(ns(6,0,7,0))
			return 1;
		if(ns(6,0,1,0))
		return 1;
	}
}

else if(a==2&&b==3){
	if(zs(2,2,2,0)){
		if(ns(2,0,1,0))
			return 1;
		if(ns(2,0,7,0))
		return 1;
	}
	if(zs(2,4,2,8)){
		if(ns(2,8,1,8))
			return 1;
		if(ns(2,8,7,8))
		return 1;
	}
	if(zs(1,3,0,3)){
		if(zs(0,2,0,1)){
		if(ns(0,2,7,2))
			return 1;
		}
		if(zs(0,4,0,7)){
		if(ns(0,6,7,6))
			return 1;
		}
	}
	if(zs(3,3,8,3)){
		if(zs(8,2,8,1)){
		if(ns(8,2,3,2))
			return 1;
		}
		if(zs(8,4,8,7)){
		if(ns(8,6,3,6))
			return 1;
		}
	}

}
else if(a==2&&b==5){
	if(zs(2,6,2,8)){
		if(ns(2,8,1,8))
			return 1;
		if(ns(2,8,7,8))
		return 1;
	}
	if(zs(2,4,2,0)){
		if(ns(2,0,1,0))
			return 1;
		if(ns(2,0,7,0))
		return 1;
	}
	if(zs(1,5,0,5)){
		if(zs(0,6,0,7)){
		if(ns(0,6,7,6))
			return 1;
		}
		if(zs(0,4,0,1)){
		if(ns(0,2,7,2))
			return 1;
		}
	}
	if(zs(3,5,8,5)){
		if(zs(8,6,8,7)){
		if(ns(8,6,3,6))
			return 1;
		}
		if(zs(8,4,8,1)){
		if(ns(8,2,3,2))
			return 1;
		}
	}
	
}
else if(a==2&&b==4){
	if(zs(2,5,2,8)){
		if(ns(2,8,1,8))
			return 1;
		if(ns(2,8,7,8))
		return 1;
	}
	if(zs(2,3,2,0)){
		if(ns(2,0,1,0))
			return 1;
		if(ns(2,0,7,0))
		return 1;
	}
	if(zs(1,4,0,4)){
		if(zs(0,5,0,7)){
		if(ns(0,6,7,6))
			return 1;
		}
		if(zs(0,3,0,1)){
		if(ns(0,2,7,2))
			return 1;
		}
	}
	if(zs(3,4,8,4)){
		if(zs(8,5,8,7)){
		if(ns(8,6,3,6))
			return 1;
		}
		if(zs(8,3,8,1)){
		if(ns(8,2,3,2))
			return 1;
		}
	}
	
}

else if(a==6&&b==3){
	if(zs(6,2,6,0)){
		if(ns(6,0,7,0))
			return 1;
		if(ns(6,0,1,0))
		return 1;
	}
	if(zs(6,4,6,8)){
		if(ns(6,8,7,8))
			return 1;
		if(ns(6,8,1,8))
		return 1;
	}
	if(zs(7,3,8,3)){
		if(zs(8,2,8,1)){
		if(ns(8,2,1,2))
			return 1;
		}
		if(zs(8,4,8,7)){
		if(ns(8,6,1,6))
			return 1;
		}
	}
	if(zs(5,3,0,3)){
		if(zs(0,2,0,1)){
		if(ns(0,2,5,2))
			return 1;
		}
		if(zs(0,4,0,7)){
		if(ns(0,6,5,6))
			return 1;
		}
	}

}
else if(a==6&&b==5){
	if(zs(6,4,6,0)){
		if(ns(6,0,7,0))
			return 1;
		if(ns(6,0,1,0))
		return 1;
	}
	if(zs(6,6,6,8)){
		if(ns(6,8,7,8))
			return 1;
		if(ns(6,8,1,8))
		return 1;
	}
	if(zs(7,5,8,5)){
		if(zs(8,6,8,7)){
		if(ns(8,6,1,6))
			return 1;
		}
		if(zs(8,4,8,1)){
		if(ns(8,2,1,2))
			return 1;
		}
	}
	if(zs(5,5,0,5)){
		if(zs(0,6,0,7)){
		if(ns(0,6,5,6))
			return 1;
		}
		if(zs(0,4,0,1)){
		if(ns(0,2,5,2))
			return 1;
		}
	}

}
else if(a==6&&b==4){
	if(zs(6,3,6,0)){
		if(ns(6,0,7,0))
			return 1;
		if(ns(6,0,1,0))
		return 1;
	}
	if(zs(6,5,6,8)){
		if(ns(6,8,7,8))
			return 1;
		if(ns(6,8,1,8))
		return 1;
	}
	if(zs(7,4,8,4)){
		if(zs(8,3,8,1)){
		if(ns(8,2,1,2))
			return 1;
		}
		if(zs(8,5,8,7)){
		if(ns(8,6,1,6))
			return 1;
		}
	}
	if(zs(5,4,0,4)){
		if(zs(0,3,0,1)){
		if(ns(0,2,5,2))
			return 1;
		}
		if(zs(0,5,0,7)){
		if(ns(0,6,5,6))
			return 1;
		}
	}

}

else if(a==3&&b==2){
	if(zs(2,2,0,2)){
		if(ns(0,2,0,1))
			return 1;
		if(ns(0,2,0,7))
		return 1;
	}
	if(zs(4,2,8,2)){
		if(ns(8,2,8,1))
			return 1;
		if(ns(8,2,8,7))
		return 1;
	}
	if(zs(3,1,3,0)){
		if(zs(2,0,1,0)){
		if(ns(2,0,2,7))
			return 1;
		}
		if(zs(4,0,7,0)){
		if(ns(6,0,6,7))
			return 1;
		}
	}
	if(zs(3,3,3,8)){
		if(zs(2,8,2,1)){
		if(ns(2,8,2,3))
			return 1;
		}
		if(zs(4,8,7,8)){
		if(ns(6,8,6,3))
			return 1;
		}
	}

}
else if(a==5&&b==2){
	if(zs(4,2,0,2)){
		if(ns(0,2,0,1))
			return 1;
		if(ns(0,2,0,7))
			return 1;
	}
	if(zs(6,2,8,2)){
		if(ns(8,2,8,1))
			return 1;
		if(ns(8,2,8,7))
			return 1;
	}
	if(zs(5,1,5,0)){
		if(zs(5,0,1,0)){
		if(ns(2,0,2,7))
			return 1;
		}
		if(zs(6,0,7,0)){
		if(ns(6,0,6,7))
			return 1;
		}
	}
	if(zs(5,3,5,8)){
		if(zs(4,8,1,8)){
		if(ns(2,8,2,3))
			return 1;
		}
		if(zs(6,8,7,8)){
		if(ns(6,8,6,3))
			return 1;
		}
	}

}
else if(a==4&&b==2){
	if(zs(3,2,0,2)){
		if(ns(0,2,0,1))
			return 1;
		if(ns(0,2,0,7))
		return 1;
	}
	if(zs(5,2,8,2)){
		if(ns(8,2,8,1))
			return 1;
		if(ns(8,2,8,7))
		return 1;
	}
	if(zs(4,1,4,0)){
		if(zs(3,0,1,0)){
		if(ns(2,0,2,7))
			return 1;
		}
		if(zs(5,0,7,0)){
		if(ns(6,0,6,7))
			return 1;
		}
	}
	if(zs(4,3,4,8)){
		if(zs(3,8,1,8)){
		if(ns(2,8,2,3))
			return 1;
		}
		if(zs(5,8,7,8)){
		if(ns(6,8,6,3))
			return 1;
		}
	}

}

else if(a==3&&b==6){
	if(zs(2,6,0,6)){
		if(ns(0,6,0,7))
			return 1;
		if(ns(0,6,0,1))
		return 1;
	}
	if(zs(4,6,8,6)){
		if(ns(8,6,8,7))
			return 1;
		if(ns(8,6,8,1))
		return 1;
	}
	if(zs(3,7,3,8)){
		if(zs(2,8,1,8)){
		if(ns(2,8,2,1))
			return 1;
		}
		if(zs(4,8,7,8)){
		if(ns(6,8,6,1))
			return 1;
		}
	}
	if(zs(3,5,3,0)){
		if(zs(2,0,1,0)){
		if(ns(2,0,2,5))
			return 1;
		}
		if(zs(4,0,7,0)){
		if(ns(6,0,6,5))
			return 1;
		}
	}

}
else if(a==5&&b==6){
	if(zs(6,6,8,6)){
		if(ns(8,6,8,7))
			return 1;
		if(ns(8,6,8,1))
		return 1;
	}
	if(zs(4,6,0,6)){
		if(ns(0,6,0,7))
			return 1;
		if(ns(0,6,0,1))
		return 1;
	}
	if(zs(5,7,5,8)){
		if(zs(6,8,7,8)){
		if(ns(6,8,6,1))
			return 1;
		}
		if(zs(4,8,1,8)){
		if(ns(2,8,2,1))
			return 1;
		}
	}
	if(zs(5,5,5,0)){
		if(zs(6,0,7,0)){
		if(ns(6,0,6,5))
			return 1;
		}
		if(zs(4,0,1,0)){
		if(ns(2,0,2,5))
			return 1;
		}

	}

}
else if(a==4&&b==6){
	if(zs(5,6,8,6)){
		if(ns(8,6,8,7))
			return 1;
		if(ns(8,6,8,1))
		return 1;
	}
	if(zs(3,6,0,6)){
		if(ns(0,6,0,7))
			return 1;
		if(ns(0,6,0,1))
		return 1;
	}
	if(zs(4,7,4,8)){
		if(zs(5,8,7,8)){
		if(ns(6,8,6,1))
			return 1;
		}
		if(zs(3,8,1,8)){
		if(ns(2,8,2,1))
			return 1;
		}
	}
	if(zs(4,5,4,0)){
		if(zs(5,0,7,0)){
		if(ns(6,0,6,5))
			return 1;
		}
		if(zs(3,0,1,0)){
		if(ns(2,0,2,5))
			return 1;
		}

	}

}
else if(a==3&&b==3){
if(zs(2,3,0,3)){
		if(zs(0,2,0,1)){
		if(ns(0,2,7,2))
			return 1;
		}
		if(zs(0,4,0,7)){
		if(ns(0,6,7,6))
			return 1;
		}

	}
if(zs(3,2,3,0)){
		if(zs(2,0,1,0)){
		if(ns(2,0,2,7))
			return 1;
		}
		if(zs(4,0,7,0)){
		if(ns(6,0,6,7))
			return 1;
		}

	}
if(zs(3,4,3,8)){
		if(zs(2,8,1,8)){
		if(ns(2,8,2,4))
			return 1;
		}
		if(zs(4,8,7,8)){
		if(ns(6,8,6,4))
			return 1;
		}

	}
if(zs(4,3,8,3)){
		if(zs(8,2,8,1)){
		if(ns(2,2,4,2))
			return 1;
		}
		if(zs(8,4,8,7)){
		if(ns(8,6,4,6))
			return 1;
		}

	}


}
else if(a==3&&b==5){
if(zs(3,6,3,8)){
		if(zs(2,8,1,8)){
		if(ns(2,8,2,1))
			return 1;
		}
		if(zs(4,8,7,8)){
		if(ns(6,8,6,1))
			return 1;
		}

	}
if(zs(2,5,0,5)){
		if(zs(0,6,0,7)){
		if(ns(0,6,7,6))
			return 1;
		}
		if(zs(0,2,0,1)){
		if(ns(0,2,7,2))
			return 1;
		}

	}
if(zs(3,4,3,0)){
		if(zs(2,0,1,0)){
		if(ns(2,0,2,4))
			return 1;
		}
		if(zs(4,0,7,0)){
		if(ns(6,0,6,4))
			return 1;
		}

	}
if(zs(4,5,8,5)){
		if(zs(8,6,8,7)){
		if(ns(8,6,4,6))
			return 1;
		}
		if(zs(8,4,8,1)){
		if(ns(8,2,4,2))
			return 1;
		}

	}
}
else if(a==5&&b==3){
if(zs(5,2,5,0)){
		if(zs(6,0,7,0)){
		if(ns(6,0,6,7))
			return 1;
		}
		if(zs(4,0,1,0)){
		if(ns(2,0,2,7))
			return 1;
		}

	}
if(zs(6,3,8,3)){
		if(zs(8,2,8,1)){
		if(ns(8,2,1,2))
			return 1;
		}
		if(zs(8,4,8,7)){
		if(ns(8,6,1,6))
			return 1;
		}

	}
if(zs(4,3,0,3)){
		if(zs(0,2,0,1)){
		if(ns(0,2,4,2))
			return 1;
		}
		if(zs(0,4,0,7)){
		if(ns(0,6,4,6))
			return 1;
		}

	}
if(zs(5,4,5,8)){
		if(zs(6,8,7,8)){
		if(ns(6,8,6,4))
			return 1;
		}
		if(zs(4,8,1,8)){
		if(ns(2,8,2,4))
			return 1;
		}
	}
}
else if(a==5&&b==5){
if(zs(5,6,5,8)){
		if(zs(6,8,7,8)){
		if(ns(6,8,6,1))
			return 1;
		}
		if(zs(4,8,1,8)){
		if(ns(2,8,2,1))
			return 1;
		}

	}
if(zs(6,5,8,5)){
		if(zs(8,6,8,7)){
		if(ns(8,6,1,6))
			return 1;
		}
		if(zs(8,4,8,1)){
		if(ns(8,2,1,2))
			return 1;
		}

	}
if(zs(4,5,0,5)){
		if(zs(0,6,0,7)){
		if(ns(0,6,4,6))
			return 1;
		}
		if(zs(0,4,0,1)){
		if(ns(0,2,4,2))
			return 1;
		}

	}
if(zs(5,4,5,0)){
		if(zs(6,0,7,0)){
		if(ns(6,0,6,4))
			return 1;
		}
		if(zs(4,0,1,0)){
		if(ns(2,0,2,4))
			return 1;
		}

	}


}



}//end of g=1 &&M[4][4]!=9
return 0;

}
bool TM(){
	int a=0,c=0,d=0;
for(int i=0;i<=8;i++)
	for(int j=0;j<=8;j++)
		if(M[i][j]>0&&(M[i][j]!=10)&&(M[i][j]!=9)){
		if((M[i][j+1]<0||M[i][j+1]==10||(i==4&&(j+1)==4&&M[4][4]!=9))&&j!=0&&j!=8&&!(i==4&&j==5)&&M[i][j-1]==0){
			if(nst(i,j-1,0,j-1,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			if(ms(c,d,c,8,9))
				b=0;
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,0,9))
				b=0;
            }
		if(b){
		if(ns(i,j-1,0,j-1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(150,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//-----------------------
		if(nst(i,j-1,i,0,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,0,9))
				b=0;
			if(ms(c,d,8,d,9))
				b=0;
            }
		if(b){
		if(ns(i,j-1,i,0)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//-------------------------
		if(nst(i,j-1,8,j-1,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			if(ms(c,d,c,0,9))
				b=0;
			if(ms(c,d,8,d,9))
				b=0;
			if(ms(c,d,c,8,9))
				b=0;
            }
		if(b){
		if(ns(i,j-1,8,j-1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		
		}
		else if((M[i][j-1]<0||M[i][j-1]==10||(i==4&&(j-1)==4&&M[4][4]!=9))&&j!=0&&j!=8&&!(i==4&&j==3)&&M[i][j+1]==0){
		if(nst(i,j+1,0,j+1,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			if(ms(c,d,c,8,9))
				b=0;
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,0,9))
				b=0;
            }
		if(b){
		if(ns(i,j+1,0,j+1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//------------------------------------
		if(nst(i,j+1,i,8,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,8,9))
				b=0;
			if(ms(c,d,8,d,9))
				b=0;
            }
		if(b){
		if(ns(i,j+1,i,8)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//-------------------------
		if(nst(i,j+1,8,j+1,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			
			
			if(ms(c,d,c,8,9))
				b=0;
			if(ms(c,d,8,d,9))
				b=0;
			if(ms(c,d,c,0,9))
				b=0;
            }
		if(b){
		if(ns(i,j+1,8,j+1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }


		}
		if((M[i+1][j]<0||M[i+1][j]==10||(i==3&&j==4&&M[4][4]!=9))&&i!=0&&i!=8&&!(i==5&&j==4)&&M[i-1][j]==0){//up s
		if(nst(i-1,j,0,j,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){

			if(ms(c,d,c,8,9))
				b=0;
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,0,9))
				b=0;
            }
		if(b){
		if(ns(i-1,j,0,j)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//-----------------------
		if(nst(i-1,j,i-1,8,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,8,9))
				b=0;
			
			if(ms(c,d,8,d,9))
				b=0;
            }
		if(b){
		
		if(ns(i-1,j,i-1,8)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//-------------------------
		if(nst(i-1,j,i-1,0,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
			if(ms(c,d,0,d,9))
				b=0;
			if(ms(c,d,c,0,9))
				b=0;
			
			if(ms(c,d,8,d,9))
				b=0;
            }
		if(b){
		
		if(ns(i-1,j,i-1,0)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }


		}
		else if((M[i-1][j]<0||M[i-1][j]==10||(i==5&&j==4&&M[4][4]!=9))&&i!=0&&i!=8&&!(i==3&&j==4)&&M[i+1][j]==0){
		if(nst(i+1,j,8,j,c,d)){
			cout<<"c:"<<c;
			cout<<"d:"<<d;
			bool b=1,e=0;//true value
			cout<<"b"<<b<<"e"<<e;
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			cout<<"x:"<<x;
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			cout<<"E:"<<e;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			cout<<"e   :"<<e;
			if(e){
				if(ms(c,d,c,8,9))
				b=0;
			   if(ms(c,d,8,d,9))
				b=0;
		
		     	if(ms(c,d,c,0,9))
				b=0;
            }
			cout<<"b       :"<<b;
		if(b){
		
		if(ns(i+1,j,8,j)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//-----------------------
		if(nst(i+1,j,i+1,8,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
				if(ms(c,d,0,d,9))
				b=0;
				if(ms(c,d,c,8,9))
				b=0;
			   if(ms(c,d,8,d,9))
				b=0;
		
		     	
            }
		if(b){
		
		if(ns(i+1,j,i+1,8)){
		a=m_number(i,j);
		V[a][0]=1;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }
		//--------------------------
		if(nst(i+1,j,i+1,0,c,d)){
			bool b=1,e=0;//true value
			int x=0;// for comput
			for(int z=2;z>=0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=2;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=2;
			for(int z=8;z>=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=6;
			for(int z=8;z<=6&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			//----------
			x=0;
			for(int z=1;z>=0&&e==0;z--){//avalin bar
			if(c==z&&d==x)
				e=1;
			x++;
			}
			x=8;
			for(int z=1;z>=0&&e==0;z--){//dovomin bar
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=1;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x--;
			}
			x=7;
			for(int z=8;z>=7&&e==0;z--){//
			if(c==z&&d==x)
				e=1;
			x++;
			}	
			if(e){
				if(ms(c,d,0,d,9))
				b=0;
				if(ms(c,d,c,0,9))
				b=0;
			   if(ms(c,d,8,d,9))
				b=0;
		
		     	
            }
		if(b){
		
		if(ns(i+1,j,i+1,0)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
        }


		

		
		
		
		







		//
		}
		}
		return 0;
}
bool NTB(){
	if(LM2[4][4+1]>0&&LM[4][4+1]==0&&M[4][4]==9){
		if(zs(4,4+1,4,8)){
			if(zs(5,8,7,8))
				if(ns(7,7,7,0))
					return 1;
			if(zs(3,8,1,8))
				if(ns(1,7,1,0))
					return 1;
		}
		if(zs(4,4+1,0,5)){
			if(zs(0,6,0,7))
				if(ns(1,7,1,0))
					return 1;
		}
		if(zs(4,4+1,8,5)){
			if(zs(8,6,8,7))
				if(ns(7,7,7,0))
					return 1;
		}

	}
	if(LM2[4][4-1]>0&&LM[4][4-1]==0&&M[4][4]==9){
		if(zs(4,4-1,4,0)){
			if(zs(3,0,1,0))
				if(ns(1,1,1,8))
					return 1;
			if(zs(5,0,7,0))
				if(ns(7,1,7,8))
					return 1;
		}
		if(zs(3,3,0,3)){
			if(zs(0,2,0,1))
				if(ns(1,1,1,8))
					return 1;
		}
		if(zs(5,3,8,3)){
			if(zs(8,2,8,1))
				if(ns(7,1,7,8))
					return 1;
		}

	}
	if(LM2[3][4]>0&&LM[3][4]==0&&M[4][4]==9){
		if(zs(2,4,0,4)){
			if(zs(0,5,0,7))
				if(ns(1,7,8,7))
					return 1;
			if(zs(0,3,0,1))
				if(ns(1,1,8,1))
					return 1;
		}
		if(zs(3,5,3,8)){
			if(zs(2,8,1,8))
				if(ns(1,7,8,7))
					return 1;
		}
		if(zs(3,3,3,0)){
			if(zs(2,0,1,0))
				if(ns(1,1,8,1))
					return 1;
		}

	}
	if(LM2[5][4]>0&&LM[5][4]==0&&M[4][4]==9){
		if(zs(6,4,8,4)){
			if(zs(8,5,8,7))
				if(ns(7,7,0,7))
					return 1;
			if(zs(8,3,8,1))
				if(ns(7,1,0,1))
					return 1;
		}
		if(zs(5,5,5,8)){
			if(zs(6,8,7,8))
				if(ns(7,7,0,7))
					return 1;
		}
		if(zs(5,3,5,0)){
			if(zs(6,0,7,0))
				if(ns(7,1,0,1))
					return 1;
		}

	}

return 0;
}
bool FTB(){
	if(LM2[4][6]>0&&LM[4][6]==0&&M[4][4]==9){
		if(ms(4,6,0,6,LM2[4][6])){
		if(ns(1,7,1,0))
			return 1;
		if(ns(1,7,8,7))
			return 1;
	}
	if(ms(4,6,8,6,LM2[4][6])){
		if(ns(7,7,7,0))
			return 1;
		if(ns(7,7,0,7))
			return 1;
	}

	}
	if(LM2[4][2]>0&&LM[4][2]==0&&M[4][4]==9){
		if(ms(4,2,0,2,LM2[4][2])){
		if(ns(1,1,1,8))
			return 1;
		if(ns(1,1,8,1))
			return 1;
	}
	if(ms(4,2,8,2,LM2[4][2])){
		if(ns(7,1,7,8))
			return 1;
		if(ns(7,1,0,1))
			return 1;
	}

	}
	if(LM2[2][4]>0&&LM[2][4]==0&&M[4][4]==9){
		if(ms(2,4,2,0,LM2[2][4])){
		if(ns(1,1,8,1))
			return 1;
		if(ns(1,1,1,8))
			return 1;
	}
	if(ms(2,4,2,8,LM2[2][4])){
		if(ns(1,7,8,7))
			return 1;
		if(ns(1,7,1,0))
			return 1;
	}

	}
	if(LM2[6][4]>0&&LM[6][4]==0&&M[4][4]==9){
		if(ms(6,4,6,0,LM2[6][4])){
		if(ns(7,1,0,1))
			return 1;
		if(ns(7,1,7,8))
			return 1;
	}
	if(ms(6,4,6,8,LM2[6][4])){
		if(ns(7,7,0,7))
			return 1;
		if(ns(7,7,7,0))
			return 1;
	}

	}
return 0;
}
/*bool DKM(){
	a=0;
	for(int i=2,int j=0;i>=0,j<=2;i--,j++)
if(M[i][j]<0){
		if((M[i][j+1]>0)&&j!=0&&j!=8&&M[i][j-1]==0){
		if(ns(i,j-1,0,j-1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i,j-1,i,0)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i,j-1,8,j-1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
		else if((M[i][j-1]<0||M[i][j-1]==10||(i==4&&(j-1)==4&&M[4][4]!=9))&&j!=0&&j!=8&&!(i==4&&j==3)&&M[i][j+1]==0){
		if(ns(i,j+1,0,j+1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i,j+1,i,8)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i,j+1,8,j+1)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		
		}
		if((M[i+1][j]<0||M[i+1][j]==10||(i==3&&j==4&&M[4][4]!=9))&&i!=0&&i!=8&&!(i==5&&j==4)&&M[i-1][j]==0){//up s
		if(ns(i-1,j,0,j)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i-1,j,i-1,8)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i-1,j,i-1,0)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		
		}
		else if((M[i-1][j]<0||M[i-1][j]==10||(i==5&&j==4&&M[4][4]!=9))&&i!=0&&i!=8&&!(i==3&&j==4)&&M[i+1][j]==0){
		if(ns(i+1,j,8,j)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i+1,j,i+1,8)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		if(ns(i+1,j,i+1,0)){
		a=m_number(i,j);
		V[a][0]=1;;
		V[a][1]=0;
		V[a][2]=0;
		y00[M[i][j]-1]+=20;
		M[i][j]=0;
		glutTimerFunc(1000,uncolor,a);
		flag=0;
		return 1;
		}
		}
		}

}*/
bool EC(){
srand(time(0));
int a=1+rand()%4;
if(a==1){
    if(ns(1,1,1,6))
		return 1;
	if(ns(1,1,6,1))
		return 1;
	if(ns(1,7,1,2))
		return 1;
	if(ns(1,7,6,7))
		return 1;
	if(ns(7,7,2,7))
		return 1;
	if(ns(7,7,7,2))
		return 1;
	if(ns(7,1,7,6))
		return 1;
	if(ns(7,1,2,1))
		return 1;
}
if(a==2){
	if(ns(1,7,1,2))
		return 1;
	if(ns(1,7,6,7))
		return 1;
	if(ns(7,7,2,7))
		return 1;
	if(ns(7,7,7,2))
		return 1;
	if(ns(7,1,7,6))
		return 1;
	if(ns(7,1,2,1))
		return 1;
	if(ns(1,1,1,6))
		return 1;
	if(ns(1,1,6,1))
		return 1;
}
if(a==3){
  
	if(ns(7,7,2,7))
		return 1;
	if(ns(7,7,7,2))
		return 1;
	
	if(ns(7,1,7,6))
		return 1;
	if(ns(7,1,2,1))
		return 1; 
	if(ns(1,1,1,6))
		return 1;
	if(ns(1,1,6,1))
		return 1;
	
	if(ns(1,7,1,2))
		return 1;
	if(ns(1,7,6,7))
		return 1;
	
}
if(a==4){
	if(ns(7,1,7,6))
		return 1;
	if(ns(7,1,2,1))
		return 1;
	if(ns(1,1,1,6))
		return 1;
	if(ns(1,1,6,1))
		return 1;
	if(ns(1,7,1,2))
		return 1;
	if(ns(1,7,6,7))
		return 1;
	if(ns(7,7,2,7))
		return 1;
	if(ns(7,7,7,2))
		return 1;
}
if(a=1){
   if(ns(0,2,0,5))
		return 1;
	if(ns(0,2,7,2))
		return 1;
	if(ns(2,0,5,0))
		return 1;
	if(ns(2,0,2,7))
		return 1;
	//--------------
	if(ns(0,6,0,3))
		return 1;
	if(ns(0,6,7,6))
		return 1;
	if(ns(2,8,2,1))
		return 1;
	if(ns(2,8,5,8))
		return 1;
	//-------------
	if(ns(6,8,3,8))
		return 1;
	if(ns(6,8,6,1))
		return 1;
	if(ns(8,6,1,6))
		return 1;
	if(ns(8,6,8,3))
		return 1;
	//------------
	if(ns(8,2,8,5))
		return 1;
	if(ns(8,2,1,2))
		return 1;
	if(ns(6,0,6,7))
		return 1;
	if(ns(6,0,1,0))
		return 1;

}
if(a==2){

	//--------------
	if(ns(0,6,0,3))
		return 1;
	if(ns(0,6,7,6))
		return 1;
	if(ns(2,8,2,1))
		return 1;
	if(ns(2,8,5,8))
		return 1;
	//-------------
	if(ns(6,8,3,8))
		return 1;
	if(ns(6,8,6,1))
		return 1;
	if(ns(8,6,1,6))
		return 1;
	if(ns(8,6,8,3))
		return 1;
	//------------
	if(ns(8,2,8,5))
		return 1;
	if(ns(8,2,1,2))
		return 1;
	if(ns(6,0,6,7))
		return 1;
	if(ns(6,0,1,0))
		return 1;
	if(ns(0,2,0,5))
		return 1;
	if(ns(0,2,7,2))
		return 1;
	if(ns(2,0,5,0))
		return 1;
	if(ns(2,0,2,7))
		return 1;
}
if(a==3){
  
	//-------------
	if(ns(6,8,3,8))
		return 1;
	if(ns(6,8,6,1))
		return 1;
	if(ns(8,6,1,6))
		return 1;
	if(ns(8,6,8,3))
		return 1;
	//------------
	if(ns(8,2,8,5))
		return 1;
	if(ns(8,2,1,2))
		return 1;
	if(ns(6,0,6,7))
		return 1;
	if(ns(6,0,1,0))
		return 1; 
	if(ns(0,2,0,5))
		return 1;
	if(ns(0,2,7,2))
		return 1;
	if(ns(2,0,5,0))
		return 1;
	if(ns(2,0,2,7))
		return 1;
	//--------------
	if(ns(0,6,0,3))
		return 1;
	if(ns(0,6,7,6))
		return 1;
	if(ns(2,8,2,1))
		return 1;
	if(ns(2,8,5,8))
		return 1;
}
if(a==4){
   
	if(ns(8,2,8,5))
		return 1;
	if(ns(8,2,1,2))
		return 1;
	if(ns(6,0,6,7))
		return 1;
	if(ns(6,0,1,0))
		return 1;
	if(ns(0,2,0,5))
		return 1;
	if(ns(0,2,7,2))
		return 1;
	if(ns(2,0,5,0))
		return 1;
	if(ns(2,0,2,7))
		return 1;
	//--------------
	if(ns(0,6,0,3))
		return 1;
	if(ns(0,6,7,6))
		return 1;
	if(ns(2,8,2,1))
		return 1;
	if(ns(2,8,5,8))
		return 1;
	//-------------
	if(ns(6,8,3,8))
		return 1;
	if(ns(6,8,6,1))
		return 1;
	if(ns(8,6,1,6))
		return 1;
	if(ns(8,6,8,3))
		return 1;
	//------------
}
for(int i=1;i<=7;i++){//row 0
	if(M[0][i]<0){
		if(a==1||a==2){
		if(ns(0,i+1,0,i))
			return 1;
		if(ns(1,i,0,i))
			return 1;
		if(ns(0,i-1,0,i))
			return 1;
		}
		if(a==3){
		if(ns(1,i,0,i))
			return 1;
		if(ns(0,i-1,0,i))
			return 1;
		if(ns(0,i+1,0,i))
			return 1;
		}
		if(a==4){
		
		if(ns(0,i-1,0,i))
			return 1;
		if(ns(0,i+1,0,i))
			return 1;
		if(ns(1,i,0,i))
			return 1;
		}
	
	}
}
for(int i=1;i<=7;i++){//column 8
	if(M[i][8]<0){
		if(a==1){
		if(ns(i-1,8,i,8))
			return 1;
		if(ns(i+1,8,i,8))
			return 1;
		if(ns(i,7,i,8))
			return 1;
		}
		if(a==3||a==2){
		
		if(ns(i+1,8,i,8))
			return 1;
		if(ns(i,7,i,8))
			return 1;
		if(ns(i-1,8,i,8))
			return 1;
		}
		if(a==4){
		if(ns(i,7,i,8))
			return 1;
		if(ns(i-1,8,i,8))
			return 1;
		if(ns(i+1,8,i,8))
			return 1;
		}
	
	}

}

for(int i=1;i<=7;i++){//row 8
	if(M[8][i]<0){
		if(a==1){
		if(ns(7,i,8,i))
			return 1;
		if(ns(8,i+1,8,i))
			return 1;
		if(ns(8,i-1,8,i))
			return 1;
		}
		if(a==2){
		
		if(ns(8,i+1,8,i))
			return 1;
		if(ns(8,i-1,8,i))
			return 1;
		if(ns(7,i,8,i))
			return 1;
		}
		if(a==4||a==3){
		
		if(ns(8,i-1,8,i))
			return 1;
		if(ns(7,i,8,i))
			return 1;
		if(ns(8,i+1,8,i))
			return 1;
		}
	
	}
}
for(int i=1;i<=7;i++){//column 0
	if(M[i][0]<0){
		if(a==1){
		if(ns(i-1,0,i,0))
			return 1;
		if(ns(i,1,i,0))
			return 1;
		if(ns(i+1,0,i,0))
			return 1;
		}
		if(a==2){
		
		if(ns(i,1,i,0))
			return 1;
		if(ns(i+1,0,i,0))
			return 1;
		if(ns(i-1,0,i,0))
			return 1;

		}
		if(a==4||a==3){
		if(ns(i+1,0,i,0))
			return 1;
		if(ns(i-1,0,i,0))
			return 1;
		if(ns(i,1,i,0))
			return 1;
		}
	
	}
}
for(int i=1;i<=7;i++)
	for(int j=1;j<=7;j++)
		if(M[i][j]<0){
			if(a==1){
			if(!(i-1==4&&j==4)){//up
			if(ns(i-1,j,i,j))
			return 1;
			}
			if(!(i=4&&j+1==4)){//right
			if(ns(i,j+1,i,j))
			return 1;
			}
			if(!(i+1==4&&j==4)){//down
			if(ns(i+1,j,i,j))
			return 1;
			}
			if(!(i=4&&j-1==4)){//left
			if(ns(i,j-1,i,j))
			return 1;
			}
			}
			if(a==2){
			
			if(!(i=4&&j+1==4)){//right
			if(ns(i,j+1,i,j))
			return 1;
			}
			if(!(i+1==4&&j==4)){//down
			if(ns(i+1,j,i,j))
			return 1;
			}
			if(!(i=4&&j-1==4)){//left
			if(ns(i,j-1,i,j))
			return 1;
			}
			if(!(i-1==4&&j==4)){//up
			if(ns(i-1,j,i,j))
			return 1;
			}
			}
			if(a==3){
			
			if(!(i+1==4&&j==4)){//down
			if(ns(i+1,j,i,j))
			return 1;
			}
			if(!(i=4&&j-1==4)){//left
			if(ns(i,j-1,i,j))
			return 1;
			}
			if(!(i-1==4&&j==4)){//up
			if(ns(i-1,j,i,j))
			return 1;
			}
			if(!(i=4&&j+1==4)){//right
			if(ns(i,j+1,i,j))
			return 1;
			}
			}
			if(a==4){
			
			if(!(i=4&&j-1==4)){//left
			if(ns(i,j-1,i,j))
			return 1;
			}
			if(!(i-1==4&&j==4)){//up
			if(ns(i-1,j,i,j))
			return 1;
			}
			if(!(i=4&&j+1==4)){//right
			if(ns(i,j+1,i,j))
			return 1;
			}
			if(!(i+1==4&&j==4)){//down
			if(ns(i+1,j,i,j))
			return 1;
			}
			}

		}



}




void cpu_inteligence(){
srand(time(0));

if(g==0){
bool a=rand()%2;
cout<<"A"<<a;
	if(a==0){//for 4 midel random
	int b=(1+rand()%4);
	int c=(1+rand()%6);
	cout<<"b"<<b<<"c"<<c<<endl;
	switch(b){
	case 1:
		if(c<=3){
		y11[12]+=(1.9*c);
		M[4-c][1]=-4;
		M[4][1]=0;
		}
		else if(c>3){
		y11[12]+=(1.9*(c-7));
		M[4+(7-c)][1]=-4;
		M[4][1]=0;
		}
		break;
		case 2:
		if(c<=3){
		x11[8]+=(1.9*c);
		M[1][4+c]=-8;
		M[1][4]=0;
		}
		else if(c>3){
		x11[8]+=(1.9*(c-7));
		M[1][4+(c-7)]=-8;
		M[1][4]=0;
		}
		break;
	case 3:
		if(c<=3){
		y11[4]+=(1.9*c);
		M[4-c][7]=-12;
		M[4][7]=0;
		}
		else if(c>3){
		y11[4]+=(1.9*(c-7));
		M[4+(7-c)][7]=-12;
		M[4][7]=0;
		}
		break;
		case 4:
		if(c<=3){
		x11[0]+=(1.9*c);
		M[7][4+c]=-16;
		M[7][4]=0;
		}
		else if(c>3){
		x11[0]+=(1.9*(c-7));
		M[7][4+(c-7)]=-16;
		M[7][4]=0;
		}
		break;
	default:
		break;
	}
	}

	else if(a==1){//for 8 around randomaiz
	int b=(1+rand()%8);
	int c=(1+rand()%2);
	cout<<"b"<<b<<"c"<<c<<endl;
	switch(b){
	case 1:
		if(c==1){
		x11[15]+=(1.9);
		M[5][1]=-1;
		M[5][0]=0;
		}
		else if(c==2){
		y11[15]+=(-1.9);
		M[6][0]=-1;
		M[5][0]=0;
		}
		break;
	case 2:
		if(c==1){
		x11[13]+=(1.9);
		M[3][1]=-3;
		M[3][0]=0;
		}
		else if(c==2){
		y11[13]+=(1.9);
		M[2][0]=-3;
		M[3][0]=0;
		}
		break;
	case 3:
		if(c==1){
		x11[11]+=(-1.9);
		M[0][2]=-5;
		M[0][3]=0;
		}
		else if(c==2){
		y11[11]+=(-1.9);
		M[1][3]=-5;
		M[0][3]=0;
		}
		break;
	case 4:
		if(c==1){
		x11[9]+=(1.9);
		M[0][6]=-7;
		M[0][5]=0;
		}
		else if(c==2){
		y11[9]+=(-1.9);
		M[1][5]=-7;
		M[0][5]=0;
		}
		break;
	case 5:
		if(c==1){
		x11[7]+=(-1.9);
		M[3][7]=-9;
		M[3][8]=0;
		}
		else if(c==2){
		y11[7]+=(1.9);
		M[2][8]=-9;
		M[3][8]=0;
		}
		break;
	case 6:
		if(c==1){
		x11[5]+=(-1.9);
		M[5][7]=-11;
		M[5][8]=0;
		}
		else if(c==2){
		y11[5]+=(-1.9);
		M[6][8]=-11;
		M[5][8]=0;
		}
		break;
	case 7:
		if(c==1){
		x11[3]+=(1.9);
		M[8][6]=-13;
		M[8][5]=0;
		}
		else if(c==2){
		y11[3]+=(1.9);
		M[7][5]=-13;
		M[8][5]=0;
		}
		break;
	case 8:
		if(c==1){
		x11[1]+=(-1.9);
		M[8][2]=-15;
		M[8][3]=0;
		}
		else if(c==2){
		y11[1]+=(1.9);
		M[7][3]=-15;
		M[8][3]=0;
		}
		break;
		default:
		break;
	}

	}
	g=1;
	flag=0;
}
else if( g==1){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++){
			LM2[i][j]=LM[i][j];
			LM[i][j]=M[i][j];
		}
if(TB()){// teror boos
flag=4;
//V[0][0]=1;
//V[0][1]=0;
//V[0][2]=0;
V[1][0]=1;
V[1][1]=0;
V[1][2]=0;
V[9][0]=1;
V[9][1]=0;
V[9][2]=0;
V[7][0]=1;
V[7][1]=0;
V[7][2]=0;
V[17][0]=1;
V[17][1]=0;
V[17][2]=0;

V[63][0]=1;
V[63][1]=0;
V[63][2]=0;
V[73][0]=1;
V[73][1]=0;
V[73][2]=0;
V[71][0]=1;
V[71][1]=0;
V[71][2]=0;
V[79][0]=1;
V[79][1]=0;
V[79][2]=0;
cout<<"\nTB activeited\n";
}
else if(TD()){
flag=0;
cout<<"\nTD activeited\n";
}
else if(MB()){
flag=0;
cout<<"\nMB activeited\n";
}
else if(TM()){
flag=0;
cout<<"\nTM activeited\n";
}
else if(NTB()){
flag=0;
cout<<"\nNTB activeited\n";
}
//else if(FTB()){
//flag=0;
//cout<<"\nFTB activeited\n";
//}
//else if(DKM()){
//flag=0;
//cout<<"\nFTB activeited\n";
//}
else if(EC()){
flag=0;
cout<<"\nEC activeited\n";
}

}
//flag=0;
}
void Timer_A (  int a){
	//float b=0;
	//for(float b=0;b<1;b+0.1)
	//b+=.1;
	glutPostRedisplay();
	cpu_inteligence();

	
}
void h1(int &p1,int &p2,int &p3,int &p4,float &p5){//for hit sefid animated
	Timer(0);
  if(p5>=0&&p5<1.3){
	p5+=0.4;
	if(p5>=1){
		p5=-1;
		if(p1>=0){
		V[p1][0]=.685;
		V[p1][1]=.400;
		V[p1][2]=.018;
		p1=-1;
		}
		if(p2>=0){
		V[p2][0]=.685;
		V[p2][1]=.400;
		V[p2][2]=.018;
		p2=-1;
		}
		if(p3>=0){
		V[p3][0]=.685;
		V[p3][1]=.400;
		V[p3][2]=.018;
		p3=-1;
		}
		if(p4>=0){
		V[p4][0]=.685;
		V[p4][1]=.400;
		V[p4][2]=.018;
		p4=-1;
		}
	if(flag==2)
		cpu_inteligence();
   }
 }	
}
void mydisplay() {
	h1(p1,p2,p3,p4,p5);//for animated hitt (1) 
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);


	//-----------------------------
	GLfloat qaAMBIENT[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaDIFFUSE[] = {.712,.500,.200, 1.0};
	GLfloat qaSPECULAR[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat qaLowAmbient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaFullAmbient[] = {1.0, 1.0, 1.0, 1.0};

	//----------------------------------
	GLfloat qaAMBIENT1[] = {0.0, 0.0, 0.0, 1.0};
	GLfloat qaDIFFUSE1[] = {.712,.500,.200, 1.0};
	//GLfloat qaSPECULAR[] = {1.0, 1.0, 1.0, 1.0};
	//GLfloat qaLowAmbient[] = {0.2, 0.2, 0.2, 1.0};
	//GLfloat qaFullAmbient[] = {1.0, 1.0, 1.0, 1.0};
	//------------
      ///////////
	     qaAMBIENT[82] = V[0][0];
	     qaDIFFUSE[82] = V[0][0];
		 qaAMBIENT[82] = V[0][1];
	     qaDIFFUSE[82] = V[0][1];
		 qaAMBIENT[82] = V[0][2];
	     qaDIFFUSE[82] = V[0][2];
	 glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
	glTranslatef(0,0,-3.);
	glBegin(GL_POLYGON);
	glVertex2f(-8-2.5, 8+1.4);
	glVertex2f(8+5.5,8+1.4);
	glVertex2f(8+2.5, 7.4-15.2-.6-1.3);
	glVertex2f(-8-2.5,  7.4-15.2-.6-1.3);
	glEnd();
	glLoadIdentity();

	/////////

		// Draw shaps
		//row1
		
	     qaAMBIENT[0] = V[0][0];
	     qaDIFFUSE[0] = V[0][0];
		 qaAMBIENT[1] = V[0][1];
	     qaDIFFUSE[1] = V[0][1];
		 qaAMBIENT[2] = V[0][2];
	     qaDIFFUSE[2] = V[0][2];
		 GLfloat qaLightPosition1[]	= {-7.60 ,7.4, -2.0,1.0};
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.60 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90 ,8.3, 0.0);
		glVertex3f(-7.4 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3, 0.0);
		glVertex3f(-7.8 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------------2

		 qaAMBIENT[0] = V[1][0];
	     qaDIFFUSE[0] = V[1][0];
		 qaAMBIENT[1] = V[1][1];
	     qaDIFFUSE[1] = V[1][1];
		 qaAMBIENT[2] = V[1][2];
	     qaDIFFUSE[2] = V[1][2];
		qaLightPosition1[0]=-5.70+.2 ;
		qaLightPosition1[1]=7.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.70 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+1.9 ,8.3, 0.0);
		glVertex3f(-7.6+1.9 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+1.9 ,8.3, 0.0);
		glVertex3f(-7.8+1.9 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------3
		
	     qaAMBIENT[0] = V[2][0];
	     qaDIFFUSE[0] = V[2][0];
		 qaAMBIENT[1] = V[2][1];
	     qaDIFFUSE[1] = V[2][1];
		 qaAMBIENT[2] = V[2][2];
	     qaDIFFUSE[2] = V[2][2];
		 qaLightPosition1[0]=-3.80 ;
		qaLightPosition1[1]=7.4;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.80 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+3.8 ,8.3, 0.0);
		glVertex3f(-7.4+3.8 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +3.8,8.3, 0.0);
		glVertex3f(-7.8+3.8 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------4
		
		 qaAMBIENT[0] = V[3][0];
	     qaDIFFUSE[0] = V[3][0];
		 qaAMBIENT[1] = V[3][1];
	     qaDIFFUSE[1] = V[3][1];
		 qaAMBIENT[2] = V[3][2];
	     qaDIFFUSE[2] = V[3][2];
		qaLightPosition1[0]=-1.90+.2 ;
		qaLightPosition1[1]=7.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.90 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+5.7 ,8.3, 0.0);
		glVertex3f(-7.6+5.7 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+5.7 ,8.3, 0.0);
		glVertex3f(-7.8+5.7 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------5
		qaAMBIENT[0] = V[4][0];
	     qaDIFFUSE[0] = V[4][0];
		 qaAMBIENT[1] = V[4][1];
	     qaDIFFUSE[1] = V[4][1];
		 qaAMBIENT[2] = V[4][2];
	     qaDIFFUSE[2] = V[4][2];
		 qaLightPosition1[0]=0.0 ;
		qaLightPosition1[1]=7.4;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0.0 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+7.6 ,8.3, 0.0);
		glVertex3f(-7.4+7.6 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +7.6,8.3, 0.0);
		glVertex3f(-7.8+7.6 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------6
		 qaAMBIENT[0] = V[5][0];
	     qaDIFFUSE[0] = V[5][0];
		 qaAMBIENT[1] = V[5][1];
	     qaDIFFUSE[1] = V[5][1];
		 qaAMBIENT[2] = V[5][2];
	     qaDIFFUSE[2] = V[5][2];
		qaLightPosition1[0]=1.9 +.2 ;
		qaLightPosition1[1]=7.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+9.5 ,8.3, 0.0);
		glVertex3f(-7.6+9.5 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+9.5 ,8.3, 0.0);
		glVertex3f(-7.8+9.5 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------7
		qaAMBIENT[0] = V[6][0];
	     qaDIFFUSE[0] = V[6][0];
		 qaAMBIENT[1] = V[6][1];
	     qaDIFFUSE[1] = V[6][1];
		 qaAMBIENT[2] = V[6][2];
	     qaDIFFUSE[2] = V[6][2];
		 qaLightPosition1[0]=3.8 ;
		qaLightPosition1[1]=7.4;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+11.4 ,8.3, 0.0);
		glVertex3f(-7.4+11.4 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +11.4,8.3, 0.0);
		glVertex3f(-7.8+11.4 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------8
	     qaAMBIENT[0] = V[7][0];
	     qaDIFFUSE[0] = V[7][0];
		 qaAMBIENT[1] = V[7][1];
	     qaDIFFUSE[1] = V[7][1];
		 qaAMBIENT[2] = V[7][2];
	     qaDIFFUSE[2] = V[7][2];
		qaLightPosition1[0]=5.70 +.2 ;
		qaLightPosition1[1]=7.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.70 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+13.3 ,8.3, 0.0);
		glVertex3f(-7.6+13.3 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3 ,8.3, 0.0);
		glVertex3f(-7.8+13.3 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		qaAMBIENT[0] = V[8][0];
	     qaDIFFUSE[0] = V[8][0];
		 qaAMBIENT[1] = V[8][1];
	     qaDIFFUSE[1] = V[8][1];
		 qaAMBIENT[2] = V[8][2];
	     qaDIFFUSE[2] = V[8][2];
		 qaLightPosition1[0]=7.60 ;
		qaLightPosition1[1]=7.4;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.60 ,7.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+15.2 ,8.3, 0.0);
		glVertex3f(-7.4+15.2 ,7.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +15.2,8.3, 0.0);
		glVertex3f(-7.8+15.2 ,6.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//----------------------------------row2

		 qaAMBIENT[0] = V[9][0];
	     qaDIFFUSE[0] = V[9][0];
		 qaAMBIENT[1] = V[9][1];
	     qaDIFFUSE[1] = V[9][1];
		 qaAMBIENT[2] = V[9][2];
	     qaDIFFUSE[2] = V[9][2];
		qaLightPosition1[0]=-7.6+.2 ;
		qaLightPosition1[1]=7.4-1.9+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.6 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2 ,8.3-1.9, 0.0);
		glVertex3f(-7.6 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-1.9, 0.0);
		glVertex3f(-7.8 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------2
		
	     qaAMBIENT[0] = V[10][0];
	     qaDIFFUSE[0] = V[10][0];
		 qaAMBIENT[1] = V[10][1];
	     qaDIFFUSE[1] = V[10][1];
		 qaAMBIENT[2] = V[10][2];
	     qaDIFFUSE[2] = V[10][2];
		 qaLightPosition1[0]=-5.7 ;
		qaLightPosition1[1]=7.4-1.9;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.7 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+1.9 ,8.3-1.9, 0.0);
		glVertex3f(-7.4+1.9 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +1.9,8.3-1.9, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------3
		
		 qaAMBIENT[0] = V[11][0];
	     qaDIFFUSE[0] = V[11][0];
		 qaAMBIENT[1] = V[11][1];
	     qaDIFFUSE[1] = V[11][1];
		 qaAMBIENT[2] = V[11][2];
	     qaDIFFUSE[2] = V[11][2];
		qaLightPosition1[0]=-3.8+.2 ;
		qaLightPosition1[1]=7.4-1.9+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.8 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+3.8 ,8.3-1.9, 0.0);
		glVertex3f(-7.6+3.8 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+3.8 ,8.3-1.9, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------------4
		 qaAMBIENT[0] = V[12][0];
	     qaDIFFUSE[0] = V[12][0];
		 qaAMBIENT[1] = V[12][1];
	     qaDIFFUSE[1] = V[12][1];
		 qaAMBIENT[2] = V[12][2];
	     qaDIFFUSE[2] = V[12][2];
		 qaLightPosition1[0]=-1.9 ;
		qaLightPosition1[1]=7.4-1.9;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.9 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+5.7 ,8.3-1.9, 0.0);
		glVertex3f(-7.4+5.7 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +5.7,8.3-1.9, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------5
		 qaAMBIENT[0] = V[13][0];
	     qaDIFFUSE[0] = V[13][0];
		 qaAMBIENT[1] = V[13][1];
	     qaDIFFUSE[1] = V[13][1];
		 qaAMBIENT[2] = V[13][2];
	     qaDIFFUSE[2] = V[13][2];
		qaLightPosition1[0]=0 +.2 ;
		qaLightPosition1[1]=7.4-1.9+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+7.6 ,8.3-1.9, 0.0);
		glVertex3f(-7.6+7.6 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+7.6 ,8.3-1.9, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------6
		 qaAMBIENT[0] = V[14][0];
	     qaDIFFUSE[0] = V[14][0];
		 qaAMBIENT[1] = V[14][1];
	     qaDIFFUSE[1] = V[14][1];
		 qaAMBIENT[2] = V[14][2];
	     qaDIFFUSE[2] = V[14][2];
		 qaLightPosition1[0]=1.9 ;
		qaLightPosition1[1]=7.4-1.9;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+9.5 ,8.3-1.9, 0.0);
		glVertex3f(-7.4+9.5 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +9.5,8.3-1.9, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------7
	     qaAMBIENT[0] = V[15][0];
	     qaDIFFUSE[0] = V[15][0];
		 qaAMBIENT[1] = V[15][1];
	     qaDIFFUSE[1] = V[15][1];
		 qaAMBIENT[2] = V[15][2];
	     qaDIFFUSE[2] = V[15][2];
		qaLightPosition1[0]=3.8 +.2 ;
		qaLightPosition1[1]=7.4-1.9+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+11.4 ,8.3-1.9, 0.0);
		glVertex3f(-7.6+11.4 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+11.4 ,8.3-1.9, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------8
		 qaAMBIENT[0] = V[16][0];
	     qaDIFFUSE[0] = V[16][0];
		 qaAMBIENT[1] = V[16][1];
	     qaDIFFUSE[1] = V[16][1];
		 qaAMBIENT[2] = V[16][2];
	     qaDIFFUSE[2] = V[16][2];
		 qaLightPosition1[0]=5.7 ;
		 qaLightPosition1[1]=7.4-1.9;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.7 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+13.3 ,8.3-1.9, 0.0);
		glVertex3f(-7.4+13.3 ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3,8.3-1.9, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[17][0];
	     qaDIFFUSE[0] = V[17][0];
		 qaAMBIENT[1] = V[17][1];
	     qaDIFFUSE[1] = V[17][1];
		 qaAMBIENT[2] = V[17][2];
	     qaDIFFUSE[2] = V[17][2];
		qaLightPosition1[0]=7.6 +.2 ;
		qaLightPosition1[1]=7.4-1.9+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.6 ,7.4-1.9, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+15.2 ,8.3-1.9, 0.0);
		glVertex3f(-7.6+15.2  ,7.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+15.2  ,8.3-1.9, 0.0);
		glVertex3f(-7.8+15.2  ,6.8-1.9, 0.0);
	    glEnd();
	    glLoadIdentity();
		
		//----------------------------------//row3
		
	     qaAMBIENT[0] = V[18][0];
	     qaDIFFUSE[0] = V[18][0];
		 qaAMBIENT[1] = V[18][1];
	     qaDIFFUSE[1] = V[18][1];
		 qaAMBIENT[2] = V[18][2];
	     qaDIFFUSE[2] = V[18][2];
		 qaLightPosition1[0]=-7.6  ;
		 qaLightPosition1[1]=7.4-3.8;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.60 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90 ,8.3-3.8, 0.0);
		glVertex3f(-7.4 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-3.8, 0.0);
		glVertex3f(-7.8 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------------2

		 qaAMBIENT[0] = V[19][0];
	     qaDIFFUSE[0] = V[19][0];
		 qaAMBIENT[1] = V[19][1];
	     qaDIFFUSE[1] = V[19][1];
		 qaAMBIENT[2] = V[19][2];
	     qaDIFFUSE[2] = V[19][2];
		qaLightPosition1[0]=-5.70+.2 ;
		qaLightPosition1[1]=7.4-3.8+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.70 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+1.9 ,8.3-3.8, 0.0);
		glVertex3f(-7.6+1.9 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+1.9 ,8.3-3.8, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------3
		
	     qaAMBIENT[0] = V[20][0];
	     qaDIFFUSE[0] = V[20][0];
		 qaAMBIENT[1] = V[20][1];
	     qaDIFFUSE[1] = V[20][1];
		 qaAMBIENT[2] = V[20][2];
	     qaDIFFUSE[2] = V[20][2];
		 qaLightPosition1[0]=-3.80 ;
		 qaLightPosition1[1]=7.4-3.8;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.80 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+3.8 ,8.3-3.8, 0.0);
		glVertex3f(-7.4+3.8 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +3.8,8.3-3.8, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------4
		
		 qaAMBIENT[0] = V[21][0];
	     qaDIFFUSE[0] = V[21][0];
		 qaAMBIENT[1] = V[21][1];
	     qaDIFFUSE[1] = V[21][1];
		 qaAMBIENT[2] = V[21][2];
	     qaDIFFUSE[2] = V[21][2];
		qaLightPosition1[0]=-1.90+.2 ;
		qaLightPosition1[1]=7.4-3.8+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.90 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+5.7 ,8.3-3.8, 0.0);
		glVertex3f(-7.6+5.7 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+5.7 ,8.3-3.8, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------5
		 qaAMBIENT[0] = V[22][0];
	    // qaDIFFUSE[0] = V[22][0];
		 qaAMBIENT[1] = V[22][1];
	     //qaDIFFUSE[1] = V[22][1];
		 qaAMBIENT[2] = V[22][2];
	    // qaDIFFUSE[2] = V[22][2];
		 qaLightPosition1[0]=0.0 ;
		 qaLightPosition1[1]=7.4-3.8;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0.0 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+7.6 ,8.3-3.8, 0.0);
		glVertex3f(-7.4+7.6 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +7.6,8.3-3.8, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------6
		 qaAMBIENT[0] = V[23][0];
	     qaDIFFUSE[0] = V[23][0];
		 qaAMBIENT[1] = V[23][1];
	     qaDIFFUSE[1] = V[23][1];
		 qaAMBIENT[2] = V[23][2];
	     qaDIFFUSE[2] = V[23][2];
		qaLightPosition1[0]=1.9 +.2 ;
		qaLightPosition1[1]=7.4-3.8+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+9.5 ,8.3-3.8, 0.0);
		glVertex3f(-7.6+9.5 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+9.5 ,8.3-3.8, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------7
		 qaAMBIENT[0] = V[24][0];
	     qaDIFFUSE[0] = V[24][0];
		 qaAMBIENT[1] = V[24][1];
	     qaDIFFUSE[1] = V[24][1];
		 qaAMBIENT[2] = V[24][2];
	     qaDIFFUSE[2] = V[24][2];
		 qaLightPosition1[0]=3.8 ;
		 qaLightPosition1[1]=7.4-3.8;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+11.4 ,8.3-3.8, 0.0);
		glVertex3f(-7.4+11.4 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +11.4,8.3-3.8, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------8
	     qaAMBIENT[0] = V[25][0];
	     qaDIFFUSE[0] = V[25][0];
		 qaAMBIENT[1] = V[25][1];
	     qaDIFFUSE[1] = V[25][1];
		 qaAMBIENT[2] = V[25][2];
	     qaDIFFUSE[2] = V[25][2];
		qaLightPosition1[0]=5.70 +.2 ;
		qaLightPosition1[1]=7.4-3.8+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.70 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+13.3 ,8.3-3.8, 0.0);
		glVertex3f(-7.6+13.3 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3 ,8.3-3.8, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[26][0];
	     qaDIFFUSE[0] = V[26][0];
		 qaAMBIENT[1] = V[26][1];
	     qaDIFFUSE[1] = V[26][1];
		 qaAMBIENT[2] = V[26][2];
	     qaDIFFUSE[2] = V[26][2];
		 qaLightPosition1[0]=7.60 ;
		qaLightPosition1[1]=7.4-3.8;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.60 ,7.4-3.8, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+15.2 ,8.3-3.8, 0.0);
		glVertex3f(-7.4+15.2 ,7.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +15.2,8.3-3.8, 0.0);
		glVertex3f(-7.8+15.2 ,6.8-3.8, 0.0);
	    glEnd();
	    glLoadIdentity();
		//----------------------------------row4

		 qaAMBIENT[0] = V[27][0];
	     qaDIFFUSE[0] = V[27][0];
		 qaAMBIENT[1] = V[27][1];
	     qaDIFFUSE[1] = V[27][1];
		 qaAMBIENT[2] = V[27][2];
	     qaDIFFUSE[2] = V[27][2];
		qaLightPosition1[0]=-7.6+.2 ;
		qaLightPosition1[1]=7.4-5.7+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.6 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2 ,8.3-5.7, 0.0);
		glVertex3f(-7.6 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-5.7, 0.0);
		glVertex3f(-7.8 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------2
		
	     qaAMBIENT[0] = V[28][0];
	     qaDIFFUSE[0] = V[28][0];
		 qaAMBIENT[1] = V[28][1];
	     qaDIFFUSE[1] = V[28][1];
		 qaAMBIENT[2] = V[28][2];
	     qaDIFFUSE[2] = V[28][2];
		 qaLightPosition1[0]=-5.7 ;
		qaLightPosition1[1]=7.4-5.7;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.7 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+1.9 ,8.3-5.7, 0.0);
		glVertex3f(-7.4+1.9 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +1.9,8.3-5.7, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------3
		
		 qaAMBIENT[0] = V[29][0];
	     qaDIFFUSE[0] = V[29][0];
		 qaAMBIENT[1] = V[29][1];
	     qaDIFFUSE[1] = V[29][1];
		 qaAMBIENT[2] = V[29][2];
	     qaDIFFUSE[2] = V[29][2];
		qaLightPosition1[0]=-3.8+.2 ;
		qaLightPosition1[1]=7.4-5.7+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.8 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+3.8 ,8.3-5.7, 0.0);
		glVertex3f(-7.6+3.8 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+3.8 ,8.3-5.7, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------------4
		 qaAMBIENT[0] = V[30][0];
	     qaDIFFUSE[0] = V[30][0];
		 qaAMBIENT[1] = V[30][1];
	     qaDIFFUSE[1] = V[30][1];
		 qaAMBIENT[2] = V[30][2];
	     qaDIFFUSE[2] = V[30][2];
		 qaLightPosition1[0]=-1.9 ;
		qaLightPosition1[1]=7.4-5.7;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.9 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+5.7 ,8.3-5.7, 0.0);
		glVertex3f(-7.4+5.7 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +5.7,8.3-5.7, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------5
		 qaAMBIENT[0] = V[31][0];
	     qaDIFFUSE[0] = V[31][0];
		 qaAMBIENT[1] = V[31][1];
	     qaDIFFUSE[1] = V[31][1];
		 qaAMBIENT[2] = V[31][2];
	     qaDIFFUSE[2] = V[31][2];
		qaLightPosition1[0]=0 +.2 ;
		qaLightPosition1[1]=7.4-5.7+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+7.6 ,8.3-5.7, 0.0);
		glVertex3f(-7.6+7.6 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+7.6 ,8.3-5.7, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------6
		 qaAMBIENT[0] = V[32][0];
	     qaDIFFUSE[0] = V[32][0];
		 qaAMBIENT[1] = V[32][1];
	     qaDIFFUSE[1] = V[32][1];
		 qaAMBIENT[2] = V[32][2];
	     qaDIFFUSE[2] = V[32][2];
		 qaLightPosition1[0]=1.9 ;
		qaLightPosition1[1]=7.4-5.7;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+9.5 ,8.3-5.7, 0.0);
		glVertex3f(-7.4+9.5 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +9.5,8.3-5.7, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------7
	     qaAMBIENT[0] = V[33][0];
	     qaDIFFUSE[0] = V[33][0];
		 qaAMBIENT[1] = V[33][1];
	     qaDIFFUSE[1] = V[33][1];
		 qaAMBIENT[2] = V[33][2];
	     qaDIFFUSE[2] = V[33][2];
		qaLightPosition1[0]=3.8 +.2 ;
		qaLightPosition1[1]=7.4-5.7+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+11.4 ,8.3-5.7, 0.0);
		glVertex3f(-7.6+11.4 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+11.4 ,8.3-5.7, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------8
		 qaAMBIENT[0] = V[34][0];
	     qaDIFFUSE[0] = V[34][0];
		 qaAMBIENT[1] = V[34][1];
	     qaDIFFUSE[1] = V[34][1];
		 qaAMBIENT[2] = V[34][2];
	     qaDIFFUSE[2] = V[34][2];
		 qaLightPosition1[0]=5.7 ;
		 qaLightPosition1[1]=7.4-5.7;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.7 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+13.3 ,8.3-5.7, 0.0);
		glVertex3f(-7.4+13.3 ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3,8.3-5.7, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[35][0];
	     qaDIFFUSE[0] = V[35][0];
		 qaAMBIENT[1] = V[35][1];
	     qaDIFFUSE[1] = V[35][1];
		 qaAMBIENT[2] = V[35][2];
	     qaDIFFUSE[2] = V[35][2];
		qaLightPosition1[0]=7.6 +.2 ;
		qaLightPosition1[1]=7.4-5.7+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.6 ,7.4-5.7, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+15.2 ,8.3-5.7, 0.0);
		glVertex3f(-7.6+15.2  ,7.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+15.2  ,8.3-5.7, 0.0);
		glVertex3f(-7.8+15.2  ,6.8-5.7, 0.0);
	    glEnd();
	    glLoadIdentity();
		//----------------------------------//row5
		
	     qaAMBIENT[0] = V[36][0];
	     qaDIFFUSE[0] = V[36][0];
		 qaAMBIENT[1] = V[36][1];
	     qaDIFFUSE[1] = V[36][1];
		 qaAMBIENT[2] = V[36][2];
	     qaDIFFUSE[2] = V[36][2];
		 qaLightPosition1[0]=-7.6  ;
		 qaLightPosition1[1]=7.4-7.6;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.60 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90 ,8.3-7.6, 0.0);
		glVertex3f(-7.4 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-7.6, 0.0);
		glVertex3f(-7.8 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------------2

		 qaAMBIENT[0] = V[37][0];
	     qaDIFFUSE[0] = V[37][0];
		 qaAMBIENT[1] = V[37][1];
	     qaDIFFUSE[1] = V[37][1];
		 qaAMBIENT[2] = V[37][2];
	     qaDIFFUSE[2] = V[37][2];
		qaLightPosition1[0]=-5.70+.2 ;
		qaLightPosition1[1]=7.4-7.6+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.70 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+1.9 ,8.3-7.6, 0.0);
		glVertex3f(-7.6+1.9 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+1.9 ,8.3-7.6, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------3
		
	     qaAMBIENT[0] = V[38][0];
	     qaDIFFUSE[0] = V[38][0];
		 qaAMBIENT[1] = V[38][1];
	     qaDIFFUSE[1] = V[38][1];
		 qaAMBIENT[2] = V[38][2];
	     qaDIFFUSE[2] = V[38][2];
		 qaLightPosition1[0]=-3.80 ;
		 qaLightPosition1[1]=7.4-7.6;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.80 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+3.8 ,8.3-7.6, 0.0);
		glVertex3f(-7.4+3.8 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +3.8,8.3-7.6, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------4
		
		 qaAMBIENT[0] = V[39][0];
	     qaDIFFUSE[0] = V[39][0];
		 qaAMBIENT[1] = V[39][1];
	     qaDIFFUSE[1] = V[39][1];
		 qaAMBIENT[2] = V[39][2];
	     qaDIFFUSE[2] = V[39][2];
		qaLightPosition1[0]=-1.90+.2 ;
		qaLightPosition1[1]=7.4-7.6+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.90 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+5.7 ,8.3-7.6, 0.0);
		glVertex3f(-7.6+5.7 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+5.7 ,8.3-7.6, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------5
		 qaAMBIENT[0] = V[40][0];
	     qaDIFFUSE[0] = V[40][0];
		 qaAMBIENT[1] = V[40][1];
	     qaDIFFUSE[1] = V[40][1];
		 qaAMBIENT[2] = V[40][2];
	     qaDIFFUSE[2] = V[40][2];
		 qaLightPosition1[0]=0.0 ;
		 qaLightPosition1[1]=7.4-7.6;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0.0 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+7.6 ,8.3-7.6, 0.0);
		glVertex3f(-7.4+7.6 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +7.6,8.3-7.6, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------6
		 qaAMBIENT[0] = V[41][0];
	     qaDIFFUSE[0] = V[41][0];
		 qaAMBIENT[1] = V[41][1];
	     qaDIFFUSE[1] = V[41][1];
		 qaAMBIENT[2] = V[41][2];
	     qaDIFFUSE[2] = V[41][2];
		qaLightPosition1[0]=1.9 +.2 ;
		qaLightPosition1[1]=7.4-7.6+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+9.5 ,8.3-7.6, 0.0);
		glVertex3f(-7.6+9.5 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+9.5 ,8.3-7.6, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------7
		 qaAMBIENT[0] = V[42][0];
	     qaDIFFUSE[0] = V[42][0];
		 qaAMBIENT[1] = V[42][1];
	     qaDIFFUSE[1] = V[42][1];
		 qaAMBIENT[2] = V[42][2];
	     qaDIFFUSE[2] = V[42][2];
		 qaLightPosition1[0]=3.8 ;
		 qaLightPosition1[1]=7.4-7.6;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+11.4 ,8.3-7.6, 0.0);
		glVertex3f(-7.4+11.4 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +11.4,8.3-7.6, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------8
	     qaAMBIENT[0] = V[43][0];
	     qaDIFFUSE[0] = V[43][0];
		 qaAMBIENT[1] = V[43][1];
	     qaDIFFUSE[1] = V[43][1];
		 qaAMBIENT[2] = V[43][2];
	     qaDIFFUSE[2] = V[43][2];
		qaLightPosition1[0]=5.70 +.2 ;
		qaLightPosition1[1]=7.4-7.6+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.70 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+13.3 ,8.3-7.6, 0.0);
		glVertex3f(-7.6+13.3 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3 ,8.3-7.6, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[44][0];
	     qaDIFFUSE[0] = V[44][0];
		 qaAMBIENT[1] = V[44][1];
	     qaDIFFUSE[1] = V[44][1];
		 qaAMBIENT[2] = V[44][2];
	     qaDIFFUSE[2] = V[44][2];
		 qaLightPosition1[0]=7.60 ;
		qaLightPosition1[1]=7.4-7.6;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.60 ,7.4-7.6, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+15.2 ,8.3-7.6, 0.0);
		glVertex3f(-7.4+15.2 ,7.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +15.2,8.3-7.6, 0.0);
		glVertex3f(-7.8+15.2 ,6.8-7.6, 0.0);
	    glEnd();
	    glLoadIdentity();
		//----------------------------------row6

		 qaAMBIENT[0] = V[45][0];
	     qaDIFFUSE[0] = V[45][0];
		 qaAMBIENT[1] = V[45][1];
	     qaDIFFUSE[1] = V[45][1];
		 qaAMBIENT[2] = V[45][2];
	     qaDIFFUSE[2] = V[45][2];
		qaLightPosition1[0]=-7.6+.2 ;
		qaLightPosition1[1]=7.4-9.5+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.6 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2 ,8.3-9.5, 0.0);
		glVertex3f(-7.6 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-9.5, 0.0);
		glVertex3f(-7.8 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------2
		
	     qaAMBIENT[0] = V[46][0];
	     qaDIFFUSE[0] = V[46][0];
		 qaAMBIENT[1] = V[46][1];
	     qaDIFFUSE[1] = V[46][1];
		 qaAMBIENT[2] = V[46][2];
	     qaDIFFUSE[2] = V[46][2];
		 qaLightPosition1[0]=-5.7 ;
		qaLightPosition1[1]=7.4-9.5;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.7 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+1.9 ,8.3-9.5, 0.0);
		glVertex3f(-7.4+1.9 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +1.9,8.3-9.5, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------3
		
		 qaAMBIENT[0] = V[47][0];
	     qaDIFFUSE[0] = V[47][0];
		 qaAMBIENT[1] = V[47][1];
	     qaDIFFUSE[1] = V[47][1];
		 qaAMBIENT[2] = V[47][2];
	     qaDIFFUSE[2] = V[47][2];
		qaLightPosition1[0]=-3.8+.2 ;
		qaLightPosition1[1]=7.4-9.5+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.8 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+3.8 ,8.3-9.5, 0.0);
		glVertex3f(-7.6+3.8 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+3.8 ,8.3-9.5, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------------4
		 qaAMBIENT[0] = V[48][0];
	     qaDIFFUSE[0] = V[48][0];
		 qaAMBIENT[1] = V[48][1];
	     qaDIFFUSE[1] = V[48][1];
		 qaAMBIENT[2] = V[48][2];
	     qaDIFFUSE[2] = V[48][2];
		 qaLightPosition1[0]=-1.9 ;
		qaLightPosition1[1]=7.4-9.5;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.9 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+5.7 ,8.3-9.5, 0.0);
		glVertex3f(-7.4+5.7 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +5.7,8.3-9.5, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------5
		 qaAMBIENT[0] = V[49][0];
	     qaDIFFUSE[0] = V[49][0];
		 qaAMBIENT[1] = V[49][1];
	     qaDIFFUSE[1] = V[49][1];
		 qaAMBIENT[2] = V[49][2];
	     qaDIFFUSE[2] = V[49][2];
		qaLightPosition1[0]=0 +.2 ;
		qaLightPosition1[1]=7.4-9.5+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+7.6 ,8.3-9.5, 0.0);
		glVertex3f(-7.6+7.6 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+7.6 ,8.3-9.5, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------6
		 qaAMBIENT[0] = V[50][0];
	     qaDIFFUSE[0] = V[50][0];
		 qaAMBIENT[1] = V[50][1];
	     qaDIFFUSE[1] = V[50][1];
		 qaAMBIENT[2] = V[50][2];
	     qaDIFFUSE[2] = V[50][2];
		 qaLightPosition1[0]=1.9 ;
		qaLightPosition1[1]=7.4-9.5;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+9.5 ,8.3-9.5, 0.0);
		glVertex3f(-7.4+9.5 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +9.5,8.3-9.5, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------7
	     qaAMBIENT[0] = V[51][0];
	     qaDIFFUSE[0] = V[51][0];
		 qaAMBIENT[1] = V[51][1];
	     qaDIFFUSE[1] = V[51][1];
		 qaAMBIENT[2] = V[51][2];
	     qaDIFFUSE[2] = V[51][2];
		qaLightPosition1[0]=3.8 +.2 ;
		qaLightPosition1[1]=7.4-9.5+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+11.4 ,8.3-9.5, 0.0);
		glVertex3f(-7.6+11.4 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+11.4 ,8.3-9.5, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------8
		 qaAMBIENT[0] = V[52][0];
	     qaDIFFUSE[0] = V[52][0];
		 qaAMBIENT[1] = V[52][1];
	     qaDIFFUSE[1] = V[52][1];
		 qaAMBIENT[2] = V[52][2];
	     qaDIFFUSE[2] = V[52][2];
		 qaLightPosition1[0]=5.7 ;
		 qaLightPosition1[1]=7.4-9.5;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.7 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+13.3 ,8.3-9.5, 0.0);
		glVertex3f(-7.4+13.3 ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3,8.3-9.5, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[53][0];
	     qaDIFFUSE[0] = V[53][0];
		 qaAMBIENT[1] = V[53][1];
	     qaDIFFUSE[1] = V[53][1];
		 qaAMBIENT[2] = V[53][2];
	     qaDIFFUSE[2] = V[53][2];
		qaLightPosition1[0]=7.6 +.2 ;
		qaLightPosition1[1]=7.4-9.5+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.6 ,7.4-9.5, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+15.2 ,8.3-9.5, 0.0);
		glVertex3f(-7.6+15.2  ,7.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+15.2  ,8.3-9.5, 0.0);
		glVertex3f(-7.8+15.2  ,6.8-9.5, 0.0);
	    glEnd();
	    glLoadIdentity();
		//----------------------------------//row7
		
	     qaAMBIENT[0] = V[54][0];
	     qaDIFFUSE[0] = V[54][0];
		 qaAMBIENT[1] = V[54][1];
	     qaDIFFUSE[1] = V[54][1];
		 qaAMBIENT[2] = V[54][2];
	     qaDIFFUSE[2] = V[54][2];
		 qaLightPosition1[0]=-7.6  ;
		 qaLightPosition1[1]=7.4-11.4;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.60 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90 ,8.3-11.4, 0.0);
		glVertex3f(-7.4 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-11.4, 0.0);
		glVertex3f(-7.8 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------------2

		 qaAMBIENT[0] = V[55][0];
	     qaDIFFUSE[0] = V[55][0];
		 qaAMBIENT[1] = V[55][1];
	     qaDIFFUSE[1] = V[55][1];
		 qaAMBIENT[2] = V[55][2];
	     qaDIFFUSE[2] = V[55][2];
		qaLightPosition1[0]=-5.70+.2 ;
		qaLightPosition1[1]=7.4-11.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.70 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+1.9 ,8.3-11.4, 0.0);
		glVertex3f(-7.6+1.9 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+1.9 ,8.3-11.4, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------3
		
	     qaAMBIENT[0] = V[56][0];
	     qaDIFFUSE[0] = V[56][0];
		 qaAMBIENT[1] = V[56][1];
	     qaDIFFUSE[1] = V[56][1];
		 qaAMBIENT[2] = V[56][2];
	     qaDIFFUSE[2] = V[56][2];
		 qaLightPosition1[0]=-3.80 ;
		 qaLightPosition1[1]=7.4-11.4;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.80 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+3.8 ,8.3-11.4, 0.0);
		glVertex3f(-7.4+3.8 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +3.8,8.3-11.4, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------4
		
		 qaAMBIENT[0] = V[57][0];
	     qaDIFFUSE[0] = V[57][0];
		 qaAMBIENT[1] = V[57][1];
	     qaDIFFUSE[1] = V[57][1];
		 qaAMBIENT[2] = V[57][2];
	     qaDIFFUSE[2] = V[57][2];
		qaLightPosition1[0]=-1.90+.2 ;
		qaLightPosition1[1]=7.4-11.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.90 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+5.7 ,8.3-11.4, 0.0);
		glVertex3f(-7.6+5.7 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+5.7 ,8.3-11.4, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------5
		 qaAMBIENT[0] = V[58][0];
	     qaDIFFUSE[0] = V[58][0];
		 qaAMBIENT[1] = V[58][1];
	     qaDIFFUSE[1] = V[58][1];
		 qaAMBIENT[2] = V[58][2];
	     qaDIFFUSE[2] = V[58][2];
		 qaLightPosition1[0]=0.0 ;
		 qaLightPosition1[1]=7.4-11.4;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0.0 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+7.6 ,8.3-11.4, 0.0);
		glVertex3f(-7.4+7.6 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +7.6,8.3-11.4, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------6
		 qaAMBIENT[0] = V[59][0];
	     qaDIFFUSE[0] = V[59][0];
		 qaAMBIENT[1] = V[59][1];
	     qaDIFFUSE[1] = V[59][1];
		 qaAMBIENT[2] = V[59][2];
	     qaDIFFUSE[2] = V[59][2];
		qaLightPosition1[0]=1.9 +.2 ;
		qaLightPosition1[1]=7.4-11.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+9.5 ,8.3-11.4, 0.0);
		glVertex3f(-7.6+9.5 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+9.5 ,8.3-11.4, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------7
		 qaAMBIENT[0] = V[60][0];
	     qaDIFFUSE[0] = V[60][0];
		 qaAMBIENT[1] = V[60][1];
	     qaDIFFUSE[1] = V[60][1];
		 qaAMBIENT[2] = V[60][2];
	     qaDIFFUSE[2] = V[60][2];
		 qaLightPosition1[0]=3.8 ;
		 qaLightPosition1[1]=7.4-11.4;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+11.4 ,8.3-11.4, 0.0);
		glVertex3f(-7.4+11.4 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +11.4,8.3-11.4, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------8
	     qaAMBIENT[0] = V[61][0];
	     qaDIFFUSE[0] = V[61][0];
		 qaAMBIENT[1] = V[61][1];
	     qaDIFFUSE[1] = V[61][1];
		 qaAMBIENT[2] = V[61][2];
	     qaDIFFUSE[2] = V[61][2];
		qaLightPosition1[0]=5.70 +.2 ;
		qaLightPosition1[1]=7.4-11.4+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.70 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+13.3 ,8.3-11.4, 0.0);
		glVertex3f(-7.6+13.3 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3 ,8.3-11.4, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[62][0];
	     qaDIFFUSE[0] = V[62][0];
		 qaAMBIENT[1] = V[62][1];
	     qaDIFFUSE[1] = V[62][1];
		 qaAMBIENT[2] = V[62][2];
	     qaDIFFUSE[2] = V[62][2];
		 qaLightPosition1[0]=7.60 ;
		qaLightPosition1[1]=7.4-11.4;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.60 ,7.4-11.4, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+15.2 ,8.3-11.4, 0.0);
		glVertex3f(-7.4+15.2 ,7.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +15.2,8.3-11.4, 0.0);
		glVertex3f(-7.8+15.2 ,6.8-11.4, 0.0);
	    glEnd();
	    glLoadIdentity();
		//----------------------------------row8

		 qaAMBIENT[0] = V[63][0];
	     qaDIFFUSE[0] = V[63][0];
		 qaAMBIENT[1] = V[63][1];
	     qaDIFFUSE[1] = V[63][1];
		 qaAMBIENT[2] = V[63][2];
	     qaDIFFUSE[2] = V[63][2];
		qaLightPosition1[0]=-7.6+.2 ;
		qaLightPosition1[1]=7.4-13.3+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.6 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2 ,8.3-13.3, 0.0);
		glVertex3f(-7.6 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-13.3, 0.0);
		glVertex3f(-7.8 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------2
		
	     qaAMBIENT[0] = V[64][0];
	     qaDIFFUSE[0] = V[64][0];
		 qaAMBIENT[1] = V[64][1];
	     qaDIFFUSE[1] = V[64][1];
		 qaAMBIENT[2] = V[64][2];
	     qaDIFFUSE[2] = V[64][2];
		 qaLightPosition1[0]=-5.7 ;
		qaLightPosition1[1]=7.4-13.3;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.7 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+1.9 ,8.3-13.3, 0.0);
		glVertex3f(-7.4+1.9 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +1.9,8.3-13.3, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------3
		
		 qaAMBIENT[0] = V[65][0];
	     qaDIFFUSE[0] = V[65][0];
		 qaAMBIENT[1] = V[65][1];
	     qaDIFFUSE[1] = V[65][1];
		 qaAMBIENT[2] = V[65][2];
	     qaDIFFUSE[2] = V[65][2];
		qaLightPosition1[0]=-3.8+.2 ;
		qaLightPosition1[1]=7.4-13.3+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.8 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+3.8 ,8.3-13.3, 0.0);
		glVertex3f(-7.6+3.8 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+3.8 ,8.3-13.3, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------------4
		 qaAMBIENT[0] = V[66][0];
	     qaDIFFUSE[0] = V[66][0];
		 qaAMBIENT[1] = V[66][1];
	     qaDIFFUSE[1] = V[66][1];
		 qaAMBIENT[2] = V[66][2];
	     qaDIFFUSE[2] = V[66][2];
		 qaLightPosition1[0]=-1.9 ;
		qaLightPosition1[1]=7.4-13.3;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.9 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+5.7 ,8.3-13.3, 0.0);
		glVertex3f(-7.4+5.7 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +5.7,8.3-13.3, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------5
		 qaAMBIENT[0] = V[67][0];
	     qaDIFFUSE[0] = V[67][0];
		 qaAMBIENT[1] = V[67][1];
	     qaDIFFUSE[1] = V[67][1];
		 qaAMBIENT[2] = V[67][2];
	     qaDIFFUSE[2] = V[67][2];
		qaLightPosition1[0]=0 +.2 ;
		qaLightPosition1[1]=7.4-13.3+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+7.6 ,8.3-13.3, 0.0);
		glVertex3f(-7.6+7.6 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+7.6 ,8.3-13.3, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------6
		 qaAMBIENT[0] = V[68][0];
	     qaDIFFUSE[0] = V[68][0];
		 qaAMBIENT[1] = V[68][1];
	     qaDIFFUSE[1] = V[68][1];
		 qaAMBIENT[2] = V[68][2];
	     qaDIFFUSE[2] = V[68][2];
		 qaLightPosition1[0]=1.9 ;
		qaLightPosition1[1]=7.4-13.3;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+9.5 ,8.3-13.3, 0.0);
		glVertex3f(-7.4+9.5 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +9.5,8.3-13.3, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------7
	     qaAMBIENT[0] = V[69][0];
	     qaDIFFUSE[0] = V[69][0];
		 qaAMBIENT[1] = V[69][1];
	     qaDIFFUSE[1] = V[69][1];
		 qaAMBIENT[2] = V[69][2];
	     qaDIFFUSE[2] = V[69][2];
		qaLightPosition1[0]=3.8 +.2 ;
		qaLightPosition1[1]=7.4-13.3+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+11.4 ,8.3-13.3, 0.0);
		glVertex3f(-7.6+11.4 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+11.4 ,8.3-13.3, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------8
		 qaAMBIENT[0] = V[70][0];
	     qaDIFFUSE[0] = V[70][0];
		 qaAMBIENT[1] = V[70][1];
	     qaDIFFUSE[1] = V[70][1];
		 qaAMBIENT[2] = V[70][2];
	     qaDIFFUSE[2] = V[70][2];
		 qaLightPosition1[0]=5.7 ;
		 qaLightPosition1[1]=7.4-13.3;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.7 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+13.3 ,8.3-13.3, 0.0);
		glVertex3f(-7.4+13.3 ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3,8.3-13.3, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[71][0];
	     qaDIFFUSE[0] = V[71][0];
		 qaAMBIENT[1] = V[71][1];
	     qaDIFFUSE[1] = V[71][1];
		 qaAMBIENT[2] = V[71][2];
	     qaDIFFUSE[2] = V[71][2];
		qaLightPosition1[0]=7.6 +.2 ;
		qaLightPosition1[1]=7.4-13.3+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.6 ,7.4-13.3, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+15.2 ,8.3-13.3, 0.0);
		glVertex3f(-7.6+15.2  ,7.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+15.2  ,8.3-13.3, 0.0);
		glVertex3f(-7.8+15.2  ,6.8-13.3, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-------------------------------row9
		 qaAMBIENT[0] = V[72][0];
	     qaDIFFUSE[0] = V[72][0];
		 qaAMBIENT[1] = V[72][1];
	     qaDIFFUSE[1] = V[72][1];
		 qaAMBIENT[2] = V[72][2];
	     qaDIFFUSE[2] = V[72][2];
		 qaLightPosition1[0]=-7.6  ;
		 qaLightPosition1[1]=7.4-15.2;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-7.60 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90 ,8.3-15.2, 0.0);
		glVertex3f(-7.4 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 ,8.3-15.2, 0.0);
		glVertex3f(-7.8 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		//-----------------------------------2

		 qaAMBIENT[0] = V[73][0];
	     qaDIFFUSE[0] = V[73][0];
		 qaAMBIENT[1] = V[73][1];
	     qaDIFFUSE[1] = V[73][1];
		 qaAMBIENT[2] = V[73][2];
	     qaDIFFUSE[2] = V[73][2];
		qaLightPosition1[0]=-5.70+.2 ;
		qaLightPosition1[1]=7.4-15.2+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-5.70 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+1.9 ,8.3-15.2, 0.0);
		glVertex3f(-7.6+1.9 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+1.9 ,8.3-15.2, 0.0);
		glVertex3f(-7.8+1.9 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------3
		
	     qaAMBIENT[0] = V[74][0];
	     qaDIFFUSE[0] = V[74][0];
		 qaAMBIENT[1] = V[74][1];
	     qaDIFFUSE[1] = V[74][1];
		 qaAMBIENT[2] = V[74][2];
	     qaDIFFUSE[2] = V[74][2];
		 qaLightPosition1[0]=-3.80 ;
		 qaLightPosition1[1]=7.4-15.2;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-3.80 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+3.8 ,8.3-15.2, 0.0);
		glVertex3f(-7.4+3.8 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +3.8,8.3-15.2, 0.0);
		glVertex3f(-7.8+3.8 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		//------------------------4
		
		 qaAMBIENT[0] = V[75][0];
	     qaDIFFUSE[0] = V[75][0];
		 qaAMBIENT[1] = V[75][1];
	     qaDIFFUSE[1] = V[75][1];
		 qaAMBIENT[2] = V[75][2];
	     qaDIFFUSE[2] = V[75][2];
		qaLightPosition1[0]=-1.90+.2 ;
		qaLightPosition1[1]=7.4-15.2+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(-1.90 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+5.7 ,8.3-15.2, 0.0);
		glVertex3f(-7.6+5.7 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+5.7 ,8.3-15.2, 0.0);
		glVertex3f(-7.8+5.7 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();

		//---------------------5
		 qaAMBIENT[0] = V[76][0];
	     qaDIFFUSE[0] = V[76][0];
		 qaAMBIENT[1] = V[76][1];
	     qaDIFFUSE[1] = V[76][1];
		 qaAMBIENT[2] = V[76][2];
	     qaDIFFUSE[2] = V[76][2];
		 qaLightPosition1[0]=0.0 ;
		 qaLightPosition1[1]=7.4-15.2;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(0.0 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+7.6 ,8.3-15.2, 0.0);
		glVertex3f(-7.4+7.6 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +7.6,8.3-15.2, 0.0);
		glVertex3f(-7.8+7.6 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		//---------------------------6
		 qaAMBIENT[0] = V[77][0];
	     qaDIFFUSE[0] = V[77][0];
		 qaAMBIENT[1] = V[77][1];
	     qaDIFFUSE[1] = V[77][1];
		 qaAMBIENT[2] = V[77][2];
	     qaDIFFUSE[2] = V[77][2];
		qaLightPosition1[0]=1.9 +.2 ;
		qaLightPosition1[1]=7.4-15.2+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(1.9 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+9.5 ,8.3-15.2, 0.0);
		glVertex3f(-7.6+9.5 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+9.5 ,8.3-15.2, 0.0);
		glVertex3f(-7.8+9.5 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		//--------------------------7
		 qaAMBIENT[0] = V[78][0];
	     qaDIFFUSE[0] = V[78][0];
		 qaAMBIENT[1] = V[78][1];
	     qaDIFFUSE[1] = V[78][1];
		 qaAMBIENT[2] = V[78][2];
	     qaDIFFUSE[2] = V[78][2];
		 qaLightPosition1[0]=3.8 ;
		 qaLightPosition1[1]=7.4-15.2;
		 qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(3.8 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+11.4 ,8.3-15.2, 0.0);
		glVertex3f(-7.4+11.4 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +11.4,8.3-15.2, 0.0);
		glVertex3f(-7.8+11.4 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();

		//------------------------8
	     qaAMBIENT[0] = V[79][0];
	     qaDIFFUSE[0] = V[79][0];
		 qaAMBIENT[1] = V[79][1];
	     qaDIFFUSE[1] = V[79][1];
		 qaAMBIENT[2] = V[79][2];
	     qaDIFFUSE[2] = V[79][2];
		qaLightPosition1[0]=5.70 +.2 ;
		qaLightPosition1[1]=7.4-15.2+.2;
		qaLightPosition1[2]=-2.0;
	    glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(5.70 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.2+13.3 ,8.3-15.2, 0.0);
		glVertex3f(-7.6+13.3 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4+13.3 ,8.3-15.2, 0.0);
		glVertex3f(-7.8+13.3 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();

		//-----------------------9
		 qaAMBIENT[0] = V[80][0];
	     qaDIFFUSE[0] = V[80][0];
		 qaAMBIENT[1] = V[80][1];
	     qaDIFFUSE[1] = V[80][1];
		 qaAMBIENT[2] = V[80][2];
	     qaDIFFUSE[2] = V[80][2];
		 qaLightPosition1[0]=7.60 ;
		qaLightPosition1[1]=7.4-15.2;
		qaLightPosition1[2]=-2.0;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
	    glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef(180,0 ,0, 0);
		glPushMatrix();
		glTranslatef(7.60 ,7.4-15.2, -2.0);
		glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		//const GLfloat kqDelta = .01;
		for (int i = -92; i < 92; ++i) {
			for (int j = -92; j < 92; ++j) {
				glVertex3f(j*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, i*kqDelta, -.2);
				glVertex3f((j+1)*kqDelta, (i+1)*kqDelta, -.2);
				glVertex3f(j*kqDelta, (i+1)*kqDelta, -.2);
			}
		}
	glEnd();
	glPopMatrix();
	//glLoadIdentity();
	     qaAMBIENT1[0] = V[81][0];
	     qaDIFFUSE1[0] = V[81][0];
		 qaAMBIENT1[1] = V[81][1];
	     qaDIFFUSE1[1] = V[81][1];
		 qaAMBIENT1[2] = V[81][2];
	     qaDIFFUSE1[2] = V[81][2];
		// GLfloat qaLightPosition1[]	= {-7.90 ,8.4, 1.5,1.0};
	    //glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		glShadeModel(GL_FLAT);
	    glDisable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
	    glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		glMaterialf(GL_FRONT, GL_SHININESS, 1000.0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-7.90+15.2 ,8.3-15.2, 0.0);
		glVertex3f(-7.4+15.2 ,7.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();
		glBegin(GL_LINES);//�� �� �� triangle
		glVertex3f(-8.4 +15.2,8.3-15.2, 0.0);
		glVertex3f(-7.8+15.2 ,6.8-15.2, 0.0);
	    glEnd();
	    glLoadIdentity();


	//---------------------------------circle
		//****************
		/* qaAMBIENT1[0] = .22;
	     qaDIFFUSE1[0] =.22;
		 qaAMBIENT1[1] =.22;
	     qaDIFFUSE1[1] = .22;
		 qaAMBIENT1[2] = .22;
	     qaDIFFUSE1[2] = .22;
		  qaLightPosition1[0]= 0;
		qaLightPosition1[1]=0;
		qaLightPosition1[2]=4;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(1.9-5.7 ,7.4-7.6+7.6,0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();*/
		//******************
		/*qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		  qaLightPosition1[0]= 9;
		qaLightPosition1[1]=9;
		qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		  
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(1.9-5.7 ,7.4-7.6+3.8,0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();*/
		//**********
	//	GLfloat qaAmbientLight0[]	= {0.8, 0.8, 0.8, 1.0};
	 // GLfloat qaDiffuseLight0[]	= {0.2, 0.2, 0.2, 1.0};
	//  GLfloat qaSpecularLight0[]	= {1.0,1.0,1.0, 1.0};
	//  glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight0);
	//  glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight0);
	 // glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight0);


		//--------------
		//-1
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9-3.8+x11[15];
		 qaLightPosition1[1]=9-5.7+y11[15];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8-3.8+x11[15] ,3.6-5.7+y11[15],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-2
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9-3.8+x11[14];
		 qaLightPosition1[1]=9-5.7+y11[14];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8-3.8+x11[14] ,3.6-3.8+y11[14],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-3
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9-3.8+x11[13];
		 qaLightPosition1[1]=9-5.7+y11[13];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8-3.8+x11[13] ,3.6-1.9+y11[13],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-4
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9-3.8+x11[12];
		 qaLightPosition1[1]=9-5.7+y11[12];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8-1.9 +x11[12],3.6-3.8+y11[12],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-5
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+1.9+x11[11];
		 qaLightPosition1[1]=9+3.8+y11[11];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+1.9+x11[11] ,3.6+3.8+y11[11],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-6
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+1.9+x11[10];
		 qaLightPosition1[1]=9+3.8+y11[10];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8+x11[10] ,3.6+3.8+y11[10],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-7
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+3.8+x11[9];
		 qaLightPosition1[1]=9+3.8+y11[9];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+5.7 +x11[9],3.6+3.8+y11[9],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-8
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+1.9+x11[8];
		 qaLightPosition1[1]=9+3.8+y11[8];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8 +x11[8],3.6+1.9+y11[8],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-9
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaSPECULAR[0]=.2;
		 qaSPECULAR[1]=.2;
		 qaSPECULAR[2]=.2;
		 qaLightPosition1[0]= 9+11.4+x11[7];
		 qaLightPosition1[1]=9-1.9+y11[7];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+11.4+x11[7] ,3.6-1.9+y11[7],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-10
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaSPECULAR[0]=.2;
		 qaSPECULAR[1]=.2;
		 qaSPECULAR[2]=.2;
		 qaLightPosition1[0]= 9+11.4+x11[6];
		 qaLightPosition1[1]=9-1.9+y11[6];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+11.4 +x11[6],3.6-3.8+y11[6],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-11
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaSPECULAR[0]=.2;
		 qaSPECULAR[1]=.2;
		 qaSPECULAR[2]=.2;
		 qaLightPosition1[0]= 9+11.4+x11[5];
		 qaLightPosition1[1]=9-1.9+y11[5];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+11.4+x11[5] ,3.6-5.7+y11[5],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		  //--------------
		//-12
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaSPECULAR[0]=.2;
		 qaSPECULAR[1]=.2;
		 qaSPECULAR[2]=.2;
		 qaLightPosition1[0]= 9+11.4+x11[4];
		 qaLightPosition1[1]=9-1.9+y11[4];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+9.5+x11[4] ,3.6-3.8+y11[4],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		//-13
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+5.7+x11[3];
		 qaLightPosition1[1]=9-11.4+y11[3];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+5.7 +x11[3],3.6-11.4+y11[3],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		  //--------------
		//-14
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+5.7+x11[2];
		 qaLightPosition1[1]=9-11.4+y11[2];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8 +x11[2],3.6-11.4+y11[2],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		  //--------------
		//-15
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+5.7+x11[1];
		 qaLightPosition1[1]=9-11.4+y11[1];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+1.9 +x11[1],3.6-11.4+y11[1],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		 //-16
		 qaAMBIENT1[0] = .27;
	     qaDIFFUSE1[0] =.3;
		 qaAMBIENT1[1] =.27;
	     qaDIFFUSE1[1] = .3;
		 qaAMBIENT1[2] = .27;
	     qaDIFFUSE1[2] = .3;
		 qaLightPosition1[0]= 9+5.7+x11[0];
		 qaLightPosition1[1]=9-11.4+y11[0];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8 +x11[0],3.6-9.5+y11[0],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------white circle
		 
		//--------------
		// 1+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=1;
		 qaSPECULAR[1]=1;
		 qaSPECULAR[2]=1;
		 qaLightPosition1[0]= 9+x00[0];
		 qaLightPosition1[1]=9-3.8+y00[0];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8 +x00[0],3.6-3.8+y00[0],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		// 2+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaLightPosition1[0]= 9+1.9+x00[1];
		 qaLightPosition1[1]=9-3.8+y00[1];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8 +1.9+x00[1],3.6-3.8+y00[1],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		// 3+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=1;
		 qaSPECULAR[1]=1;
		 qaSPECULAR[2]=1;
		 qaLightPosition1[0]= 9+3.8+x00[2];
		 qaLightPosition1[1]=9+y00[2];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8+x00[2] ,3.6+y00[2],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		// 4+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=1;
		 qaSPECULAR[1]=1;
		 qaSPECULAR[2]=1;
		 qaLightPosition1[0]= 9+3.8+x00[3];
		 qaLightPosition1[1]=9-1.9+y00[3];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8 +x00[3],3.6-1.9+y00[3],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		  
		//--------------
		// 5+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=0.2;
		 qaSPECULAR[1]=0.2;
		 qaSPECULAR[2]=0.2;
		 qaLightPosition1[0]= 9+7.6+x00[4];
		 qaLightPosition1[1]=9-3.8+y00[4];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8 +7.6+x00[4],3.6-3.8+y00[4],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		  
		//--------------
		// 6+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] = 1;
		 qaAMBIENT1[1] = 1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=0.2;
		 qaSPECULAR[1]=0.2;
		 qaSPECULAR[2]=0.2;
		 qaLightPosition1[0]= 9+5.7+x00[5];
		 qaLightPosition1[1]=9-3.8+y00[5];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8 +5.7+x00[5],3.6-3.8+y00[5],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		// 7+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=1;
		 qaSPECULAR[1]=1;
		 qaSPECULAR[2]=1;
		 qaLightPosition1[0]= 9+3.8+x00[6];
		 qaLightPosition1[1]=9-7.6+y00[6];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8 +x00[6],3.6-7.6+y00[6],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		// 8+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 1;
	     qaDIFFUSE1[2] = 1;
		 qaSPECULAR[0]=1;
		 qaSPECULAR[1]=1;
		 qaSPECULAR[2]=1;
		 qaLightPosition1[0]= 9+3.8+x00[7];
		 qaLightPosition1[1]=9-5.7+y00[7];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8+x00[7] ,3.6-5.7+y00[7],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------
		// 9+
		 qaAMBIENT1[0] = 1;
	     qaDIFFUSE1[0] =1;
		 qaAMBIENT1[1] =1;
	     qaDIFFUSE1[1] = 1;
		 qaAMBIENT1[2] = 0;
	     qaDIFFUSE1[2] = 0;
		 qaSPECULAR[0]=1;
		 qaSPECULAR[1]=1;
		 qaSPECULAR[2]=1;
		 qaLightPosition1[0]= 9+3.8+x00[8];
		 qaLightPosition1[1]=9-3.8+y00[8];
	     qaLightPosition1[2]=5;
	     glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
		 glShadeModel(GL_FLAT);
		 glDisable(GL_LIGHT0);
	     glEnable(GL_LIGHT1);
		 glDisable(GL_LIGHT2);
	     glMaterialfv(GL_FRONT, GL_AMBIENT, qaAMBIENT1);
		 glMaterialfv(GL_FRONT, GL_DIFFUSE, qaDIFFUSE1);
		 glMaterialfv(GL_FRONT, GL_SPECULAR, qaSPECULAR);
		 glMaterialf(GL_FRONT, GL_SHININESS, 128.0);
		 glLightfv(GL_LIGHT0, GL_AMBIENT, qaLowAmbient);
		 glMatrixMode(GL_MODELVIEW);
		 //glLoadIdentity();
		 glPushMatrix();
		 glTranslatef(-3.8+3.8 +x00[8],3.6-3.8+y00[8],0.0);
		 glutSolidSphere(.9, 20, 20);
		 glPopMatrix();
		 glLoadIdentity();
		 //--------------

	glFlush();
}
void resize(int w,int h){//view setting
	//w=0;
	//h=0;
	glViewport(290,-10, 800,800);
	//cout<<h<<endl<<w<<endl;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0,10.0, -8.0,8.0);//(-2,2,-2,2) ����� ����� �� ����� 2/(-2,2,-2,2) ����� ����� �� ����� 2
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void Initialize() {
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -3.0, 3.0);

	// Lighting set up
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glDisable (GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	// Set lighting intensity and color
	GLfloat qaAmbientLight0[]	= {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight0[]	= {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight0[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight0);
	//------------
	GLfloat qaAmbientLight1[]	= {.2, .2,.2, 1.0};
	GLfloat qaDiffuseLight1[]	= {.8,.8, .8, 1.0};
	GLfloat qaSpecularLight1[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight1);
	//--------------
	GLfloat qaAmbientLight2[]	= {.500,.300,.100, 1.0};
	GLfloat qaDiffuseLight2[]	= {.212,.200,.100, 1.0};
	GLfloat qaSpecularLight2[]	= {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT2, GL_AMBIENT, qaAmbientLight2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight2);


	// Set the light position
	GLfloat qaLightPosition0[]	= {0.0, 0.0,1,0.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition0);
	//---------
	GLfloat qaLightPosition1[]	= {-0.2, 0.0,0,1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition1);
	//-----------
	GLfloat qaLightPosition2[]	= {7.60 ,7.4-15.2, -2.0,1.0};
	glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition2);
}
void hitt(int x,int y,int z){//hitt sefid
	  if((x-1)>0)//baray adam khoroj az jadval
		 if(M[x-1][y]<0&&(M[x-2][y]>0||((y==4)&&((x-2)==4)))){//harekat yek vahed bala
			p1=(z-9-1);//for m-1 khane manfi
			V[p1][0]=1;
			V[p1][1]=0;
			V[p1][2]=0;
			y11[M[x-1][y]+16]=20;//for remove negative circle 
			M[x-1][y]=0;
		 }
	  if((x+1)<8)//baray adam khoroj az jadval
		 if(M[x+1][y]<0&&(M[x+2][y]>0||((y==4)&&((x+2)==4)))){//harekat yek vahed paeen
			p2=(z+9-1);//for m-1 khane manfi
			V[p2][0]=1;
			V[p2][1]=0;
			V[p2][2]=0;
			y11[M[x+1][y]+16]=20;//for remove negative circle 
			M[x+1][y]=0;
		 }
	  if((y-1)>0)//baray adam khoroj az jadval
		 if(M[x][y-1]<0&&(M[x][y-2]>0||(((y-2)==4)&&(x==4)))){//harekat yek vahed paeen
			p3=(z-1-1);//for m-1 khane manfi
			V[p3][0]=1;
			V[p3][1]=0;
			V[p3][2]=0;
			y11[M[x][y-1]+16]=20;//for remove negative circle 
			M[x][y-1]=0;
		 }
	  if((y+1)<8)//baray adam khoroj az jadval
		 if(M[x][y+1]<0&&(M[x][y+2]>0||(((y+2)==4)&&(x==4)))){//harekat yek vahed paeen
			p4=(z+1-1);//for m-1 khane manfi
			V[p4][0]=1;
			V[p4][1]=0;
			V[p4][2]=0;
			y11[M[x][y+1]+16]=20;//for remove negative circle 
			M[x][y+1]=0;
		 }
		 if(p1!=-1||p2!=-1||p3!=-1||p4!=-1){
			 p5=0;//for begin h1
			//h1(p1,p2,p3,p4,p5);
		 }
		 else if(flag==2)
			 cpu_inteligence();

}

bool canmove(int q,int n,int m){//q:num of quad n:1 or 2(x or y) m:quad of click one
	int s=0;
	switch (q)
	{
		case 1:
		if(n==1){
			if(((m-1)/9)<0){
			for(int i=(((m-1)/9)+1);i<0;i++)
			if(M[0+i][0]==0)
			s--;
			if (s==(((m-1)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-1)/9)-1);i>0;i--)
			if(M[0+i][0]==0)
			s++;
			if (s==(((m-1)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-1)<0){
			for(int i=((m-1)+1);i<0;i++)
			if(M[0][0+i]==0)
			s--;
			if (s==((m-1)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-1)-1);i>0;i--)
			if(M[0][0+i]==0)
			s++;
			if (s==((m-1)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 2:
		if(n==1){
			if(((m-2)/9)<0){
			for(int i=(((m-2)/9)+1);i<0;i++)
			if(M[0+i][1]==0)
			s--;
			if (s==(((m-2)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-2)/9)-1);i>0;i--)
			if(M[0+i][1]==0)
			s++;
			if (s==(((m-2)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-2)<0){
			for(int i=((m-2)+1);i<0;i++)
			if(M[0][1+i]==0)
			s--;
			if (s==((m-2)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-2)-1);i>0;i--)
			if(M[0][1+i]==0)
			s++;
			if (s==((m-2)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 3:
		if(n==1){
			if(((m-3)/9)<0){
			for(int i=(((m-3)/9)+1);i<0;i++)
			if(M[0+i][2]==0)
			s--;
			if (s==(((m-3)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-3)/9)-1);i>0;i--)
			if(M[0+i][2]==0)
			s++;
			if (s==(((m-3)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-3)<0){
			for(int i=((m-3)+1);i<0;i++)
			if(M[0][2+i]==0)
			s--;
			if (s==((m-3)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-3)-1);i>0;i--)
			if(M[0][2+i]==0)
			s++;
			if (s==((m-3)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 4:
		if(n==1){
			if(((m-4)/9)<0){
			for(int i=(((m-4)/9)+1);i<0;i++)
			if(M[0+i][3]==0)
			s--;
			if (s==(((m-4)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-4)/9)-1);i>0;i--)
			if(M[0+i][3]==0)
			s++;
			if (s==(((m-4)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-4)<0){
			for(int i=((m-4)+1);i<0;i++)
			if(M[0][3+i]==0)
			s--;
			if (s==((m-4)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-4)-1);i>0;i--)
			if(M[0][3+i]==0)
			s++;
			if (s==((m-4)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 5:
		if(n==1){
			if(((m-5)/9)<0){
			for(int i=(((m-5)/9)+1);i<0;i++)
			if(M[0+i][4]==0)
			s--;
			if (s==(((m-5)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-5)/9)-1);i>0;i--)
			if(M[0+i][4]==0)
			s++;
			if (s==(((m-5)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-5)<0){
			for(int i=((m-5)+1);i<0;i++)
			if(M[0][4+i]==0)
			s--;
			if (s==((m-5)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-5)-1);i>0;i--)
			if(M[0][4+i]==0)
			s++;
			if (s==((m-5)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 6:
		if(n==1){
			if(((m-6)/9)<0){
			for(int i=(((m-6)/9)+1);i<0;i++)
			if(M[0+i][5]==0)
			s--;
			if (s==(((m-6)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-6)/9)-1);i>0;i--)
			if(M[0+i][5]==0)
			s++;
			if (s==(((m-6)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-6)<0){
			for(int i=((m-6)+1);i<0;i++)
			if(M[0][5+i]==0)
			s--;
			if (s==((m-6)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-6)-1);i>0;i--)
			if(M[0][5+i]==0)
			s++;
			if (s==((m-6)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 7:
		if(n==1){
			if(((m-7)/9)<0){
			for(int i=(((m-7)/9)+1);i<0;i++)
			if(M[0+i][6]==0)
			s--;
			if (s==(((m-7)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-7)/9)-1);i>0;i--)
			if(M[0+i][6]==0)
			s++;
			if (s==(((m-7)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-7)<0){
			for(int i=((m-7)+1);i<0;i++)
			if(M[0][6+i]==0)
			s--;
			if (s==((m-7)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-7)-1);i>0;i--)
			if(M[0][6+i]==0)
			s++;
			if (s==((m-7)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 8:
		if(n==1){
			if(((m-8)/9)<0){
			for(int i=(((m-8)/9)+1);i<0;i++)
			if(M[0+i][7]==0)
			s--;
			if (s==(((m-8)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-8)/9)-1);i>0;i--)
			if(M[0+i][7]==0)
			s++;
			if (s==(((m-8)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-8)<0){
			for(int i=((m-8)+1);i<0;i++)
			if(M[0][7+i]==0)
			s--;
			if (s==((m-8)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-8)-1);i>0;i--)
			if(M[0][7+i]==0)
			s++;
			if (s==((m-8)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 9:
		if(n==1){
			if(((m-9)/9)<0){
			for(int i=(((m-9)/9)+1);i<0;i++)
			if(M[0+i][8]==0)
			s--;
			if (s==(((m-9)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-9)/9)-1);i>0;i--)
			if(M[0+i][8]==0)
			s++;
			if (s==(((m-9)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-9)<0){
			for(int i=((m-9)+1);i<0;i++)
			if(M[0][8+i]==0)
			s--;
			if (s==((m-9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-9)-1);i>0;i--)
			if(M[0][8+i]==0)
			s++;
			if (s==((m-9)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 10:
		if(n==1){
			if(((m-10)/9)<0){
			for(int i=(((m-10)/9)+1);i<0;i++)
			if(M[1+i][0]==0)
			s--;
			if (s==(((m-10)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-10)/9)-1);i>0;i--)
			if(M[1+i][0]==0)
			s++;
			if (s==(((m-10)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-10)<0){
			for(int i=((m-10)+1);i<0;i++)
			if(M[1][0+i]==0)
			s--;
			if (s==((m-10)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-10)-1);i>0;i--)
			if(M[1][0+i]==0)
			s++;
			if (s==((m-10)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 11:
		if(n==1){
			if(((m-11)/9)<0){
			for(int i=(((m-11)/9)+1);i<0;i++)
			if(M[1+i][1]==0)
			s--;
			if (s==(((m-11)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-11)/9)-1);i>0;i--)
			if(M[1+i][1]==0)
			s++;
			if (s==(((m-11)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-11)<0){
			for(int i=((m-11)+1);i<0;i++)
			if(M[1][1+i]==0)
			s--;
			if (s==((m-11)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-11)-1);i>0;i--)
			if(M[1][1+i]==0)
			s++;
			if (s==((m-11)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 12:
		if(n==1){
			if(((m-12)/9)<0){
			for(int i=(((m-12)/9)+1);i<0;i++)
			if(M[1+i][2]==0)
			s--;
			if (s==(((m-12)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-12)/9)-1);i>0;i--)
			if(M[1+i][2]==0)
			s++;
			if (s==(((m-12)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-12)<0){
			for(int i=((m-12)+1);i<0;i++)
			if(M[1][2+i]==0)
			s--;
			if (s==((m-12)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-12)-1);i>0;i--)
			if(M[1][2+i]==0)
			s++;
			if (s==((m-12)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 13:
		if(n==1){
			if(((m-13)/9)<0){
			for(int i=(((m-13)/9)+1);i<0;i++)
			if(M[1+i][3]==0)
			s--;
			if (s==(((m-13)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-13)/9)-1);i>0;i--)
			if(M[1+i][3]==0)
			s++;
			if (s==(((m-13)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-13)<0){
			for(int i=((m-13)+1);i<0;i++)
			if(M[1][3+i]==0)
			s--;
			if (s==((m-13)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-13)-1);i>0;i--)
			if(M[1][3+i]==0)
			s++;
			if (s==((m-13)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 14:
		if(n==1){
			if(((m-14)/9)<0){
			for(int i=(((m-14)/9)+1);i<0;i++)
			if(M[1+i][4]==0)
			s--;
			if (s==(((m-14)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-14)/9)-1);i>0;i--)
			if(M[1+i][4]==0)
			s++;
			if (s==(((m-14)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-14)<0){
			for(int i=((m-14)+1);i<0;i++)
			if(M[1][4+i]==0)
			s--;
			if (s==((m-14)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-14)-1);i>0;i--)
			if(M[1][4+i]==0)
			s++;
			if (s==((m-14)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 15:
		if(n==1){
			if(((m-15)/9)<0){
			for(int i=(((m-15)/9)+1);i<0;i++)
			if(M[1+i][5]==0)
			s--;
			if (s==(((m-15)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-15)/9)-1);i>0;i--)
			if(M[1+i][5]==0)
			s++;
			if (s==(((m-15)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-15)<0){
			for(int i=((m-15)+1);i<0;i++)
			if(M[1][5+i]==0)
			s--;
			if (s==((m-15)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-15)-1);i>0;i--)
			if(M[1][5+i]==0)
			s++;
			if (s==((m-15)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 16:
		if(n==1){
			if(((m-16)/9)<0){
			for(int i=(((m-16)/9)+1);i<0;i++)
			if(M[1+i][6]==0)
			s--;
			if (s==(((m-16)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-16)/9)-1);i>0;i--)
			if(M[1+i][6]==0)
			s++;
			if (s==(((m-16)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-16)<0){
			for(int i=((m-16)+1);i<0;i++)
			if(M[1][6+i]==0)
			s--;
			if (s==((m-16)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-16)-1);i>0;i--)
			if(M[1][6+i]==0)
			s++;
			if (s==((m-16)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 17:
		if(n==1){
			if(((m-17)/9)<0){
			for(int i=(((m-17)/9)+1);i<0;i++)
			if(M[1+i][7]==0)
			s--;
			if (s==(((m-17)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-17)/9)-1);i>0;i--)
			if(M[1+i][7]==0)
			s++;
			if (s==(((m-17)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-17)<0){
			for(int i=((m-17)+1);i<0;i++)
			if(M[1][7+i]==0)
			s--;
			if (s==((m-17)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-17)-1);i>0;i--)
			if(M[1][7+i]==0)
			s++;
			if (s==((m-17)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 18:
		if(n==1){
			if(((m-18)/9)<0){
			for(int i=(((m-18)/9)+1);i<0;i++)
			if(M[1+i][8]==0)
			s--;
			if (s==(((m-18)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-18)/9)-1);i>0;i--)
			if(M[1+i][8]==0)
			s++;
			if (s==(((m-18)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-18)<0){
			for(int i=((m-18)+1);i<0;i++)
			if(M[1][8+i]==0)
			s--;
			if (s==((m-18)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-18)-1);i>0;i--)
			if(M[1][8+i]==0)
			s++;
			if (s==((m-18)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 19:
		if(n==1){
			if(((m-19)/9)<0){
			for(int i=(((m-19)/9)+1);i<0;i++)
			if(M[2+i][0]==0)
			s--;
			if (s==(((m-19)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-19)/9)-1);i>0;i--)
			if(M[2+i][0]==0)
			s++;
			if (s==(((m-19)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-19)<0){
			for(int i=((m-19)+1);i<0;i++)
			if(M[2][0+i]==0)
			s--;
			if (s==((m-19)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-19)-1);i>0;i--)
			if(M[2][0+i]==0)
			s++;
			if (s==((m-19)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 20:
		if(n==1){
			if(((m-20)/9)<0){
			for(int i=(((m-20)/9)+1);i<0;i++)
			if(M[2+i][1]==0)
			s--;
			if (s==(((m-20)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-20)/9)-1);i>0;i--)
			if(M[2+i][1]==0)
			s++;
			if (s==(((m-20)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-20)<0){
			for(int i=((m-20)+1);i<0;i++)
			if(M[2][1+i]==0)
			s--;
			if (s==((m-20)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-20)-1);i>0;i--)
			if(M[2][1+i]==0)
			s++;
			if (s==((m-20)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 21:
		if(n==1){
			if(((m-21)/9)<0){
			for(int i=(((m-21)/9)+1);i<0;i++)
			if(M[2+i][2]==0)
			s--;
			if (s==(((m-21)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-21)/9)-1);i>0;i--)
			if(M[2+i][2]==0)
			s++;
			if (s==(((m-21)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-21)<0){
			for(int i=((m-21)+1);i<0;i++)
			if(M[2][2+i]==0)
			s--;
			if (s==((m-21)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-21)-1);i>0;i--)
			if(M[2][2+i]==0)
			s++;
			if (s==((m-21)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 22:
		if(n==1){
			if(((m-22)/9)<0){
			for(int i=(((m-22)/9)+1);i<0;i++)
			if(M[2+i][3]==0)
			s--;
			if (s==(((m-22)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-22)/9)-1);i>0;i--)
			if(M[2+i][3]==0)
			s++;
			if (s==(((m-22)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-22)<0){
			for(int i=((m-22)+1);i<0;i++)
			if(M[2][3+i]==0)
			s--;
			if (s==((m-22)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-22)-1);i>0;i--)
			if(M[2][3+i]==0)
			s++;
			if (s==((m-22)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 23:
		if(n==1){
			if(((m-23)/9)<0){
			for(int i=(((m-23)/9)+1);i<0;i++)
			if(M[2+i][4]==0)
			s--;
			if (s==(((m-23)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-23)/9)-1);i>0;i--)
			if(M[2+i][4]==0)
			s++;
			if (s==(((m-23)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-23)<0){
			for(int i=((m-23)+1);i<0;i++)
			if(M[2][4+i]==0)
			s--;
			if (s==((m-23)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-23)-1);i>0;i--)
			if(M[2][4+i]==0)
			s++;
			if (s==((m-23)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 24:
		if(n==1){
			if(((m-24)/9)<0){
			for(int i=(((m-24)/9)+1);i<0;i++)
			if(M[2+i][5]==0)
			s--;
			if (s==(((m-24)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-24)/9)-1);i>0;i--)
			if(M[2+i][5]==0)
			s++;
			if (s==(((m-24)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-24)<0){
			for(int i=((m-24)+1);i<0;i++)
			if(M[2][5+i]==0)
			s--;
			if (s==((m-24)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-24)-1);i>0;i--)
			if(M[2][5+i]==0)
			s++;
			if (s==((m-24)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 25:
		if(n==1){
			if(((m-25)/9)<0){
			for(int i=(((m-25)/9)+1);i<0;i++)
			if(M[2+i][6]==0)
			s--;
			if (s==(((m-25)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-25)/9)-1);i>0;i--)
			if(M[2+i][6]==0)
			s++;
			if (s==(((m-25)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-25)<0){
			for(int i=((m-25)+1);i<0;i++)
			if(M[2][6+i]==0)
			s--;
			if (s==((m-25)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-25)-1);i>0;i--)
			if(M[2][6+i]==0)
			s++;
			if (s==((m-25)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 26:
		if(n==1){
			if(((m-26)/9)<0){
			for(int i=(((m-26)/9)+1);i<0;i++)
			if(M[2+i][7]==0)
			s--;
			if (s==(((m-26)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-26)/9)-1);i>0;i--)
			if(M[2+i][7]==0)
			s++;
			if (s==(((m-26)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-26)<0){
			for(int i=((m-26)+1);i<0;i++)
			if(M[2][7+i]==0)
			s--;
			if (s==((m-26)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-26)-1);i>0;i--)
			if(M[2][7+i]==0)
			s++;
			if (s==((m-26)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 27:
		if(n==1){
			if(((m-27)/9)<0){
			for(int i=(((m-27)/9)+1);i<0;i++)
			if(M[2+i][8]==0)
			s--;
			if (s==(((m-27)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-27)/9)-1);i>0;i--)
			if(M[2+i][8]==0)
			s++;
			if (s==(((m-27)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-27)<0){
			for(int i=((m-27)+1);i<0;i++)
			if(M[2][8+i]==0)
			s--;
			if (s==((m-27)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-27)-1);i>0;i--)
			if(M[2][8+i]==0)
			s++;
			if (s==((m-27)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 28:
		if(n==1){
			if(((m-28)/9)<0){
			for(int i=(((m-28)/9)+1);i<0;i++)
			if(M[3+i][0]==0)
			s--;
			if (s==(((m-28)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-28)/9)-1);i>0;i--)
			if(M[3+i][0]==0)
			s++;
			if (s==(((m-28)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-28)<0){
			for(int i=((m-28)+1);i<0;i++)
			if(M[3][0+i]==0)
			s--;
			if (s==((m-28)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-28)-1);i>0;i--)
			if(M[3][0+i]==0)
			s++;
			if (s==((m-28)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 29:
		if(n==1){
			if(((m-29)/9)<0){
			for(int i=(((m-29)/9)+1);i<0;i++)
			if(M[3+i][1]==0)
			s--;
			if (s==(((m-29)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-29)/9)-1);i>0;i--)
			if(M[3+i][1]==0)
			s++;
			if (s==(((m-29)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-29)<0){
			for(int i=((m-29)+1);i<0;i++)
			if(M[3][1+i]==0)
			s--;
			if (s==((m-29)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-29)-1);i>0;i--)
			if(M[3][0+i]==0)
			s++;
			if (s==((m-29)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 30:
		if(n==1){
			if(((m-30)/9)<0){
			for(int i=(((m-30)/9)+1);i<0;i++)
			if(M[3+i][2]==0)
			s--;
			if (s==(((m-30)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-30)/9)-1);i>0;i--)
			if(M[3+i][2]==0)
			s++;
			if (s==(((m-30)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-30)<0){
			for(int i=((m-30)+1);i<0;i++)
			if(M[3][2+i]==0)
			s--;
			if (s==((m-30)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-30)-1);i>0;i--)
			if(M[3][2+i]==0)
			s++;
			if (s==((m-30)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 31:
		if(n==1){
			if(((m-31)/9)<0){
			for(int i=(((m-31)/9)+1);i<0;i++)
			if(M[3+i][3]==0)
			s--;
			if (s==(((m-31)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-31)/9)-1);i>0;i--)
			if(M[3+i][3]==0)
			s++;
			if (s==(((m-31)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-31)<0){
			for(int i=((m-31)+1);i<0;i++)
			if(M[3][3+i]==0)
			s--;
			if (s==((m-31)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-31)-1);i>0;i--)
			if(M[3][3+i]==0)
			s++;
			if (s==((m-31)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 32:
		if(n==1){
			if(((m-32)/9)<0){
			for(int i=(((m-32)/9)+1);i<0;i++)
			if(M[3+i][4]==0)
			s--;
			if (s==(((m-32)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-32)/9)-1);i>0;i--)
			if(M[3+i][4]==0)
			s++;
			if (s==(((m-32)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-32)<0){
			for(int i=((m-32)+1);i<0;i++)
			if(M[3][4+i]==0)
			s--;
			if (s==((m-32)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-32)-1);i>0;i--)
			if(M[3][4+i]==0)
			s++;
			if (s==((m-32)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 33:
		if(n==1){
			if(((m-33)/9)<0){
			for(int i=(((m-33)/9)+1);i<0;i++)
			if(M[3+i][5]==0)
			s--;
			if (s==(((m-33)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-33)/9)-1);i>0;i--)
			if(M[3+i][5]==0)
			s++;
			if (s==(((m-33)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-33)<0){
			for(int i=((m-33)+1);i<0;i++)
			if(M[3][5+i]==0)
			s--;
			if (s==((m-33)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-33)-1);i>0;i--)
			if(M[3][5+i]==0)
			s++;
			if (s==((m-33)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 34:
		if(n==1){
			if(((m-34)/9)<0){
			for(int i=(((m-34)/9)+1);i<0;i++)
			if(M[3+i][6]==0)
			s--;
			if (s==(((m-34)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-34)/9)-1);i>0;i--)
			if(M[3+i][6]==0)
			s++;
			if (s==(((m-34)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-34)<0){
			for(int i=((m-34)+1);i<0;i++)
			if(M[3][6+i]==0)
			s--;
			if (s==((m-34)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-34)-1);i>0;i--)
			if(M[3][6+i]==0)
			s++;
			if (s==((m-34)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 35:
		if(n==1){
			if(((m-35)/9)<0){
			for(int i=(((m-35)/9)+1);i<0;i++)
			if(M[3+i][7]==0)
			s--;
			if (s==(((m-35)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-35)/9)-1);i>0;i--)
			if(M[3+i][7]==0)
			s++;
			if (s==(((m-35)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-35)<0){
			for(int i=((m-35)+1);i<0;i++)
			if(M[3][7+i]==0)
			s--;
			if (s==((m-35)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-35)-1);i>0;i--)
			if(M[3][7+i]==0)
			s++;
			if (s==((m-35)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 36:
		if(n==1){
			if(((m-36)/9)<0){
			for(int i=(((m-36)/9)+1);i<0;i++)
			if(M[3+i][8]==0)
			s--;
			if (s==(((m-36)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-36)/9)-1);i>0;i--)
			if(M[3+i][8]==0)
			s++;
			if (s==(((m-36)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-36)<0){
			for(int i=((m-36)+1);i<0;i++)
			if(M[3][8+i]==0)
			s--;
			if (s==((m-36)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-36)-1);i>0;i--)
			if(M[3][8+i]==0)
			s++;
			if (s==((m-36)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 37:
		if(n==1){
			if(((m-37)/9)<0){
			for(int i=(((m-37)/9)+1);i<0;i++)
			if(M[4+i][0]==0)
			s--;
			if (s==(((m-37)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-37)/9)-1);i>0;i--)
			if(M[4+i][0]==0)
			s++;
			if (s==(((m-37)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-37)<0){
			for(int i=((m-37)+1);i<0;i++)
			if(M[4][0+i]==0)
			s--;
			if (s==((m-37)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-37)-1);i>0;i--)
			if(M[4][0+i]==0)
			s++;
			if (s==((m-37)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 38:
		if(n==1){
			if(((m-38)/9)<0){
			for(int i=(((m-38)/9)+1);i<0;i++)
			if(M[4+i][1]==0)
			s--;
			if (s==(((m-38)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-38)/9)-1);i>0;i--)
			if(M[4+i][1]==0)
			s++;
			if (s==(((m-38)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-38)<0){
			for(int i=((m-38)+1);i<0;i++)
			if(M[4][1+i]==0)
			s--;
			if (s==((m-38)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-38)-1);i>0;i--)
			if(M[4][1+i]==0)
			s++;
			if (s==((m-38)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 39:
		if(n==1){
			if(((m-39)/9)<0){
			for(int i=(((m-39)/9)+1);i<0;i++)
			if(M[4+i][2]==0)
			s--;
			if (s==(((m-39)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-39)/9)-1);i>0;i--)
			if(M[4+i][2]==0)
			s++;
			if (s==(((m-39)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-39)<0){
			for(int i=((m-39)+1);i<0;i++)
			if(M[4][2+i]==0)
			s--;
			if (s==((m-39)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-39)-1);i>0;i--)
			if(M[4][2+i]==0)
			s++;
			if (s==((m-39)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 40:
		if(n==1){
			if(((m-40)/9)<0){
			for(int i=(((m-40)/9)+1);i<0;i++)
			if(M[4+i][3]==0)
			s--;
			if (s==(((m-40)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-40)/9)-1);i>0;i--)
			if(M[4+i][3]==0)
			s++;
			if (s==(((m-40)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-40)<0){
			for(int i=((m-40)+1);i<0;i++)
			if(M[4][3+i]==0)
			s--;
			if (s==((m-40)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-40)-1);i>0;i--)
			if(M[4][3+i]==0)
			s++;
			if (s==((m-40)-1))
			return 1;
			return 0;
			}	
		}
		break;
	case 41:
		if(n==1){
			if(((m-41)/9)<0){
			for(int i=(((m-41)/9)+1);i<0;i++)
			if(M[4+i][4]==0)
			s--;
			if (s==(((m-41)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-41)/9)-1);i>0;i--)
			if(M[4+i][4]==0)
			s++;
			if (s==(((m-41)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-41)<0){
			for(int i=((m-41)+1);i<0;i++)
			if(M[4][4+i]==0)
			s--;
			if (s==((m-41)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-41)-1);i>0;i--)
			if(M[4][4+i]==0)
			s++;
			if (s==((m-41)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 42:
		if(n==1){
			if(((m-42)/9)<0){
			for(int i=(((m-42)/9)+1);i<0;i++)
			if(M[4+i][5]==0)
			s--;
			if (s==(((m-42)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-42)/9)-1);i>0;i--)
			if(M[4+i][5]==0)
			s++;
			if (s==(((m-42)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-42)<0){
			for(int i=((m-42)+1);i<0;i++)
			if(M[4][5+i]==0)
			s--;
			if (s==((m-42)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-42)-1);i>0;i--)
			if(M[4][5+i]==0)
			s++;
			if (s==((m-42)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 43:
		if(n==1){
			if(((m-43)/9)<0){
			for(int i=(((m-43)/9)+1);i<0;i++)
			if(M[4+i][6]==0)
			s--;
			if (s==(((m-43)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-43)/9)-1);i>0;i--)
			if(M[4+i][6]==0)
			s++;
			if (s==(((m-43)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-43)<0){
			for(int i=((m-43)+1);i<0;i++)
			if(M[4][6+i]==0)
			s--;
			if (s==((m-43)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-43)-1);i>0;i--)
			if(M[4][6+i]==0)
			s++;
			if (s==((m-43)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 44:
		if(n==1){
			if(((m-44)/9)<0){
			for(int i=(((m-44)/9)+1);i<0;i++)
			if(M[4+i][7]==0)
			s--;
			if (s==(((m-44)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-44)/9)-1);i>0;i--)
			if(M[4+i][7]==0)
			s++;
			if (s==(((m-44)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-44)<0){
			for(int i=((m-44)+1);i<0;i++)
			if(M[4][7+i]==0)
			s--;
			if (s==((m-44)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-44)-1);i>0;i--)
			if(M[4][7+i]==0)
			s++;
			if (s==((m-44)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 45:
		if(n==1){
			if(((m-45)/9)<0){
			for(int i=(((m-45)/9)+1);i<0;i++)
			if(M[4+i][8]==0)
			s--;
			if (s==(((m-45)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-45)/9)-1);i>0;i--)
			if(M[4+i][8]==0)
			s++;
			if (s==(((m-45)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-45)<0){
			for(int i=((m-45)+1);i<0;i++)
			if(M[4][8+i]==0)
			s--;
			if (s==((m-45)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-45)-1);i>0;i--)
			if(M[4][8+i]==0)
			s++;
			if (s==((m-45)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 46:
		if(n==1){
			if(((m-46)/9)<0){
			for(int i=(((m-46)/9)+1);i<0;i++)
			if(M[5+i][0]==0)
			s--;
			if (s==(((m-46)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-46)/9)-1);i>0;i--)
			if(M[5+i][0]==0)
			s++;
			if (s==(((m-46)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-46)<0){
			for(int i=((m-46)+1);i<0;i++)
			if(M[5][0+i]==0)
			s--;
			if (s==((m-46)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-46)-1);i>0;i--)
			if(M[5][0+i]==0)
			s++;
			if (s==((m-46)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 47:
		if(n==1){
			if(((m-47)/9)<0){
			for(int i=(((m-47)/9)+1);i<0;i++)
			if(M[5+i][1]==0)
			s--;
			if (s==(((m-47)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-47)/9)-1);i>0;i--)
			if(M[5+i][1]==0)
			s++;
			if (s==(((m-47)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-47)<0){
			for(int i=((m-47)+1);i<0;i++)
			if(M[5][1+i]==0)
			s--;
			if (s==((m-47)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-47)-1);i>0;i--)
			if(M[5][1+i]==0)
			s++;
			if (s==((m-47)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 48:
		if(n==1){
			if(((m-48)/9)<0){
			for(int i=(((m-48)/9)+1);i<0;i++)
			if(M[5+i][2]==0)
			s--;
			if (s==(((m-48)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-48)/9)-1);i>0;i--)
			if(M[5+i][2]==0)
			s++;
			if (s==(((m-48)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-48)<0){
			for(int i=((m-48)+1);i<0;i++)
			if(M[5][2+i]==0)
			s--;
			if (s==((m-48)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-48)-1);i>0;i--)
			if(M[5][2+i]==0)
			s++;
			if (s==((m-48)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 49:
		if(n==1){
			if(((m-49)/9)<0){
			for(int i=(((m-49)/9)+1);i<0;i++)
			if(M[5+i][3]==0)
			s--;
			if (s==(((m-49)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-49)/9)-1);i>0;i--)
			if(M[5+i][3]==0)
			s++;
			if (s==(((m-49)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-49)<0){
			for(int i=((m-49)+1);i<0;i++)
			if(M[5][3+i]==0)
			s--;
			if (s==((m-49)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-49)-1);i>0;i--)
			if(M[5][3+i]==0)
			s++;
			if (s==((m-49)-1))
			return 1;
			return 0;
			}	
		}
		break;
	case 50:
		if(n==1){
			if(((m-50)/9)<0){
			for(int i=(((m-50)/9)+1);i<0;i++)
			if(M[5+i][4]==0)
			s--;
			if (s==(((m-50)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-50)/9)-1);i>0;i--)
			if(M[5+i][4]==0)
			s++;
			if (s==(((m-50)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-50)<0){
			for(int i=((m-50)+1);i<0;i++)
			if(M[5][4+i]==0)
			s--;
			if (s==((m-50)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-50)-1);i>0;i--)
			if(M[5][4+i]==0)
			s++;
			if (s==((m-50)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 51:
		if(n==1){
			if(((m-51)/9)<0){
			for(int i=(((m-51)/9)+1);i<0;i++)
			if(M[5+i][5]==0)
			s--;
			if (s==(((m-51)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-51)/9)-1);i>0;i--)
			if(M[5+i][5]==0)
			s++;
			if (s==(((m-51)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-51)<0){
			for(int i=((m-51)+1);i<0;i++)
			if(M[5][5+i]==0)
			s--;
			if (s==((m-51)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-51)-1);i>0;i--)
			if(M[5][5+i]==0)
			s++;
			if (s==((m-51)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 52:
		if(n==1){
			if(((m-52)/9)<0){
			for(int i=(((m-52)/9)+1);i<0;i++)
			if(M[5+i][6]==0)
			s--;
			if (s==(((m-52)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-52)/9)-1);i>0;i--)
			if(M[5+i][6]==0)
			s++;
			if (s==(((m-52)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-52)<0){
			for(int i=((m-52)+1);i<0;i++)
			if(M[5][6+i]==0)
			s--;
			if (s==((m-52)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-52)-1);i>0;i--)
			if(M[5][6+i]==0)
			s++;
			if (s==((m-52)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 53:
		if(n==1){
			if(((m-53)/9)<0){
			for(int i=(((m-53)/9)+1);i<0;i++)
			if(M[5+i][7]==0)
			s--;
			if (s==(((m-53)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-53)/9)-1);i>0;i--)
			if(M[5+i][7]==0)
			s++;
			if (s==(((m-53)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-53)<0){
			for(int i=((m-53)+1);i<0;i++)
			if(M[5][7+i]==0)
			s--;
			if (s==((m-53)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-53)-1);i>0;i--)
			if(M[5][7+i]==0)
			s++;
			if (s==((m-53)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 54:
		if(n==1){
			if(((m-54)/9)<0){
			for(int i=(((m-54)/9)+1);i<0;i++)
			if(M[5+i][8]==0)
			s--;
			if (s==(((m-54)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-54)/9)-1);i>0;i--)
			if(M[5+i][8]==0)
			s++;
			if (s==(((m-54)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-54)<0){
			for(int i=((m-54)+1);i<0;i++)
			if(M[5][8+i]==0)
			s--;
			if (s==((m-54)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-54)-1);i>0;i--)
			if(M[5][8+i]==0)
			s++;
			if (s==((m-54)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 55:
		if(n==1){
			if(((m-55)/9)<0){
			for(int i=(((m-55)/9)+1);i<0;i++)
			if(M[6+i][0]==0)
			s--;
			if (s==(((m-55)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-55)/9)-1);i>0;i--)
			if(M[6+i][0]==0)
			s++;
			if (s==(((m-55)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-55)<0){
			for(int i=((m-55)+1);i<0;i++)
			if(M[6][0+i]==0)
			s--;
			if (s==((m-55)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-55)-1);i>0;i--)
			if(M[6][0+i]==0)
			s++;
			if (s==((m-55)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 56:
		if(n==1){
			if(((m-56)/9)<0){
			for(int i=(((m-56)/9)+1);i<0;i++)
			if(M[6+i][1]==0)
			s--;
			if (s==(((m-56)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-56)/9)-1);i>0;i--)
			if(M[6+i][1]==0)
			s++;
			if (s==(((m-56)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-56)<0){
			for(int i=((m-56)+1);i<0;i++)
			if(M[6][1+i]==0)
			s--;
			if (s==((m-56)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-56)-1);i>0;i--)
			if(M[6][1+i]==0)
			s++;
			if (s==((m-56)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 57:
		if(n==1){
			if(((m-57)/9)<0){
			for(int i=(((m-57)/9)+1);i<0;i++)
			if(M[6+i][2]==0)
			s--;
			if (s==(((m-57)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-57)/9)-1);i>0;i--)
			if(M[6+i][2]==0)
			s++;
			if (s==(((m-57)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-57)<0){
			for(int i=((m-57)+1);i<0;i++)
			if(M[6][2+i]==0)
			s--;
			if (s==((m-57)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-57)-1);i>0;i--)
			if(M[6][2+i]==0)
			s++;
			if (s==((m-57)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 58:
		if(n==1){
			if(((m-58)/9)<0){
			for(int i=(((m-58)/9)+1);i<0;i++)
			if(M[6+i][3]==0)
			s--;
			if (s==(((m-58)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-58)/9)-1);i>0;i--)
			if(M[6+i][3]==0)
			s++;
			if (s==(((m-58)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-58)<0){
			for(int i=((m-58)+1);i<0;i++)
			if(M[6][3+i]==0)
			s--;
			if (s==((m-58)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-58)-1);i>0;i--)
			if(M[6][3+i]==0)
			s++;
			if (s==((m-58)-1))
			return 1;
			return 0;
			}	
		}
		break;
	case 59:
		if(n==1){
			if(((m-59)/9)<0){
			for(int i=(((m-59)/9)+1);i<0;i++)
			if(M[6+i][4]==0)
			s--;
			if (s==(((m-59)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-59)/9)-1);i>0;i--)
			if(M[6+i][4]==0)
			s++;
			if (s==(((m-59)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-59)<0){
			for(int i=((m-59)+1);i<0;i++)
			if(M[6][4+i]==0)
			s--;
			if (s==((m-59)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-59)-1);i>0;i--)
			if(M[6][4+i]==0)
			s++;
			if (s==((m-59)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 60:
		if(n==1){
			if(((m-60)/9)<0){
			for(int i=(((m-60)/9)+1);i<0;i++)
			if(M[6+i][5]==0)
			s--;
			if (s==(((m-60)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-60)/9)-1);i>0;i--)
			if(M[6+i][5]==0)
			s++;
			if (s==(((m-60)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-60)<0){
			for(int i=((m-60)+1);i<0;i++)
			if(M[6][5+i]==0)
			s--;
			if (s==((m-60)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-60)-1);i>0;i--)
			if(M[6][5+i]==0)
			s++;
			if (s==((m-60)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 61:
		if(n==1){
			if(((m-61)/9)<0){
			for(int i=(((m-61)/9)+1);i<0;i++)
			if(M[6+i][6]==0)
			s--;
			if (s==(((m-61)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-61)/9)-1);i>0;i--)
			if(M[6+i][6]==0)
			s++;
			if (s==(((m-61)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-61)<0){
			for(int i=((m-61)+1);i<0;i++)
			if(M[6][6+i]==0)
			s--;
			if (s==((m-61)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-61)-1);i>0;i--)
			if(M[6][6+i]==0)
			s++;
			if (s==((m-61)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 62:
		if(n==1){
			if(((m-62)/9)<0){
			for(int i=(((m-62)/9)+1);i<0;i++)
			if(M[6+i][7]==0)
			s--;
			if (s==(((m-62)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-62)/9)-1);i>0;i--)
			if(M[6+i][7]==0)
			s++;
			if (s==(((m-62)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-62)<0){
			for(int i=((m-62)+1);i<0;i++)
			if(M[6][7+i]==0)
			s--;
			if (s==((m-62)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-62)-1);i>0;i--)
			if(M[6][7+i]==0)
			s++;
			if (s==((m-62)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 63:
		if(n==1){
			if(((m-63)/9)<0){
			for(int i=(((m-63)/9)+1);i<0;i++)
			if(M[6+i][8]==0)
			s--;
			if (s==(((m-63)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-63)/9)-1);i>0;i--)
			if(M[6+i][8]==0)
			s++;
			if (s==(((m-63)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-63)<0){
			for(int i=((m-63)+1);i<0;i++)
			if(M[6][8+i]==0)
			s--;
			if (s==((m-63)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-63)-1);i>0;i--)
			if(M[6][8+i]==0)
			s++;
			if (s==((m-63)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 64:
		if(n==1){
			if(((m-64)/9)<0){
			for(int i=(((m-64)/9)+1);i<0;i++)
			if(M[7+i][0]==0)
			s--;
			if (s==(((m-64)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-64)/9)-1);i>0;i--)
			if(M[7+i][0]==0)
			s++;
			if (s==(((m-64)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-64)<0){
			for(int i=((m-64)+1);i<0;i++)
			if(M[7][0+i]==0)
			s--;
			if (s==((m-64)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-64)-1);i>0;i--)
			if(M[7][0+i]==0)
			s++;
			if (s==((m-64)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 65:
		if(n==1){
			if(((m-65)/9)<0){
			for(int i=(((m-65)/9)+1);i<0;i++)
			if(M[7+i][1]==0)
			s--;
			if (s==(((m-65)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-65)/9)-1);i>0;i--)
			if(M[7+i][1]==0)
			s++;
			if (s==(((m-65)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-65)<0){
			for(int i=((m-65)+1);i<0;i++)
			if(M[7][1+i]==0)
			s--;
			if (s==((m-65)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-65)-1);i>0;i--)
			if(M[7][1+i]==0)
			s++;
			if (s==((m-65)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 66:
		if(n==1){
			if(((m-66)/9)<0){
			for(int i=(((m-66)/9)+1);i<0;i++)
			if(M[7+i][2]==0)
			s--;
			if (s==(((m-66)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-66)/9)-1);i>0;i--)
			if(M[7+i][2]==0)
			s++;
			if (s==(((m-66)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-66)<0){
			for(int i=((m-66)+1);i<0;i++)
			if(M[7][2+i]==0)
			s--;
			if (s==((m-66)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-66)-1);i>0;i--)
			if(M[7][2+i]==0)
			s++;
			if (s==((m-66)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 67:
		if(n==1){
			if(((m-67)/9)<0){
			for(int i=(((m-67)/9)+1);i<0;i++)
			if(M[7+i][3]==0)
			s--;
			if (s==(((m-67)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-67)/9)-1);i>0;i--)
			if(M[7+i][3]==0)
			s++;
			if (s==(((m-67)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-67)<0){
			for(int i=((m-67)+1);i<0;i++)
			if(M[7][3+i]==0)
			s--;
			if (s==((m-67)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-67)-1);i>0;i--)
			if(M[7][3+i]==0)
			s++;
			if (s==((m-67)-1))
			return 1;
			return 0;
			}	
		}
		break;
	case 68:
		if(n==1){
			if(((m-68)/9)<0){
			for(int i=(((m-68)/9)+1);i<0;i++)
			if(M[7+i][4]==0)
			s--;
			if (s==(((m-68)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-68)/9)-1);i>0;i--)
			if(M[7+i][4]==0)
			s++;
			if (s==(((m-68)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-68)<0){
			for(int i=((m-68)+1);i<0;i++)
			if(M[7][4+i]==0)
			s--;
			if (s==((m-68)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-68)-1);i>0;i--)
			if(M[7][4+i]==0)
			s++;
			if (s==((m-68)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 69:
		if(n==1){
			if(((m-69)/9)<0){
			for(int i=(((m-69)/9)+1);i<0;i++)
			if(M[7+i][5]==0)
			s--;
			if (s==(((m-69)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-69)/9)-1);i>0;i--)
			if(M[7+i][5]==0)
			s++;
			if (s==(((m-69)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-69)<0){
			for(int i=((m-69)+1);i<0;i++)
			if(M[7][5+i]==0)
			s--;
			if (s==((m-69)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-69)-1);i>0;i--)
			if(M[7][5+i]==0)
			s++;
			if (s==((m-69)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 70:
		if(n==1){
			if(((m-70)/9)<0){
			for(int i=(((m-70)/9)+1);i<0;i++)
			if(M[7+i][6]==0)
			s--;
			if (s==(((m-70)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-70)/9)-1);i>0;i--)
			if(M[7+i][6]==0)
			s++;
			if (s==(((m-70)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-70)<0){
			for(int i=((m-70)+1);i<0;i++)
			if(M[7][6+i]==0)
			s--;
			if (s==((m-70)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-70)-1);i>0;i--)
			if(M[7][6+i]==0)
			s++;
			if (s==((m-70)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 71:
		if(n==1){
			if(((m-71)/9)<0){
			for(int i=(((m-71)/9)+1);i<0;i++)
			if(M[7+i][7]==0)
			s--;
			if (s==(((m-71)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-71)/9)-1);i>0;i--)
			if(M[7+i][7]==0)
			s++;
			if (s==(((m-71)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-71)<0){
			for(int i=((m-71)+1);i<0;i++)
			if(M[7][7+i]==0)
			s--;
			if (s==((m-71)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-71)-1);i>0;i--)
			if(M[7][7+i]==0)
			s++;
			if (s==((m-71)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 72:
		if(n==1){
			if(((m-72)/9)<0){
			for(int i=(((m-72)/9)+1);i<0;i++)
			if(M[7+i][8]==0)
			s--;
			if (s==(((m-72)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-72)/9)-1);i>0;i--)
			if(M[7+i][8]==0)
			s++;
			if (s==(((m-72)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-72)<0){
			for(int i=((m-72)+1);i<0;i++)
			if(M[7][8+i]==0)
			s--;
			if (s==((m-72)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-72)-1);i>0;i--)
			if(M[7][8+i]==0)
			s++;
			if (s==((m-72)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 73:
		if(n==1){
			if(((m-73)/9)<0){
			for(int i=(((m-73)/9)+1);i<0;i++)
			if(M[8+i][0]==0)
			s--;
			if (s==(((m-73)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-73)/9)-1);i>0;i--)
			if(M[8+i][0]==0)
			s++;
			if (s==(((m-73)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-73)<0){
			for(int i=((m-73)+1);i<0;i++)
			if(M[8][0+i]==0)
			s--;
			if (s==((m-73)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-73)-1);i>0;i--)
			if(M[8][0+i]==0)
			s++;
			if (s==((m-73)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 74:
		if(n==1){
			if(((m-74)/9)<0){
			for(int i=(((m-74)/9)+1);i<0;i++)
			if(M[8+i][1]==0)
			s--;
			if (s==(((m-74)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-74)/9)-1);i>0;i--)
			if(M[8+i][1]==0)
			s++;
			if (s==(((m-74)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-74)<0){
			for(int i=((m-74)+1);i<0;i++)
			if(M[8][1+i]==0)
			s--;
			if (s==((m-74)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-74)-1);i>0;i--)
			if(M[8][1+i]==0)
			s++;
			if (s==((m-74)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 75:
		if(n==1){
			if(((m-75)/9)<0){
			for(int i=(((m-75)/9)+1);i<0;i++)
			if(M[8+i][2]==0)
			s--;
			if (s==(((m-75)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-75)/9)-1);i>0;i--)
			if(M[8+i][2]==0)
			s++;
			if (s==(((m-75)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-75)<0){
			for(int i=((m-75)+1);i<0;i++)
			if(M[8][2+i]==0)
			s--;
			if (s==((m-75)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-75)-1);i>0;i--)
			if(M[8][2+i]==0)
			s++;
			if (s==((m-75)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 76:
		if(n==1){
			if(((m-76)/9)<0){
			for(int i=(((m-76)/9)+1);i<0;i++)
			if(M[8+i][3]==0)
			s--;
			if (s==(((m-76)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-76)/9)-1);i>0;i--)
			if(M[8+i][3]==0)
			s++;
			if (s==(((m-76)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-76)<0){
			for(int i=((m-76)+1);i<0;i++)
			if(M[8][3+i]==0)
			s--;
			if (s==((m-76)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-76)-1);i>0;i--)
			if(M[8][3+i]==0)
			s++;
			if (s==((m-76)-1))
			return 1;
			return 0;
			}	
		}
		break;
	case 77:
		if(n==1){
			if(((m-77)/9)<0){
			for(int i=(((m-77)/9)+1);i<0;i++)
			if(M[8+i][4]==0)
			s--;
			if (s==(((m-77)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-77)/9)-1);i>0;i--)
			if(M[8+i][4]==0)
			s++;
			if (s==(((m-77)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-77)<0){
			for(int i=((m-77)+1);i<0;i++)
			if(M[8][4+i]==0)
			s--;
			if (s==((m-77)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-77)-1);i>0;i--)
			if(M[8][4+i]==0)
			s++;
			if (s==((m-77)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 78:
		if(n==1){
			if(((m-78)/9)<0){
			for(int i=(((m-78)/9)+1);i<0;i++)
			if(M[8+i][5]==0)
			s--;
			if (s==(((m-78)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-78)/9)-1);i>0;i--)
			if(M[8+i][5]==0)
			s++;
			if (s==(((m-78)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-78)<0){
			for(int i=((m-78)+1);i<0;i++)
			if(M[8][5+i]==0)
			s--;
			if (s==((m-78)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-78)-1);i>0;i--)
			if(M[8][5+i]==0)
			s++;
			if (s==((m-78)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 79:
		if(n==1){
			if(((m-79)/9)<0){
			for(int i=(((m-79)/9)+1);i<0;i++)
			if(M[8+i][6]==0)
			s--;
			if (s==(((m-79)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-79)/9)-1);i>0;i--)
			if(M[8+i][6]==0)
			s++;
			if (s==(((m-79)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-79)<0){
			for(int i=((m-79)+1);i<0;i++)
			if(M[8][6+i]==0)
			s--;
			if (s==((m-79)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-79)-1);i>0;i--)
			if(M[8][6+i]==0)
			s++;
			if (s==((m-79)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 80:
		if(n==1){
			if(((m-80)/9)<0){
			for(int i=(((m-80)/9)+1);i<0;i++)
			if(M[8+i][7]==0)
			s--;
			if (s==(((m-80)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-80)/9)-1);i>0;i--)
			if(M[8+i][7]==0)
			s++;
			if (s==(((m-80)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-80)<0){
			for(int i=((m-80)+1);i<0;i++)
			if(M[8][7+i]==0)
			s--;
			if (s==((m-80)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-80)-1);i>0;i--)
			if(M[8][7+i]==0)
			s++;
			if (s==((m-80)-1))
			return 1;
			return 0;
			}	
		}
		break;
		case 81:
		if(n==1){
			if(((m-81)/9)<0){
			for(int i=(((m-81)/9)+1);i<0;i++)
			if(M[8+i][8]==0)
			s--;
			if (s==(((m-81)/9)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=(((m-81)/9)-1);i>0;i--)
			if(M[8+i][8]==0)
			s++;
			if (s==(((m-81)/9)-1))
			return 1;
			return 0;
			}	
		}
		else if(n==2){
			if((m-81)<0){
			for(int i=((m-81)+1);i<0;i++)
			if(M[8][8+i]==0)
			s--;
			if (s==((m-81)+1))
			return 1;
			return 0;
			}
			else{
			for(int i=((m-81)-1);i>0;i--)
			if(M[8][8+i]==0)
			s++;
			if (s==((m-81)-1))
			return 1;
			return 0;
			}	
		}
		break;
	default:
		break;
	}
}
void hit(int l){//not used
	
	for (int i=0;i<9;i++)
		for(int j=0;j<9;j++){
		if(l==1 &&M[i][j]>0){
		if(M[i][j+1]<0&&M[i][j+2]>0){
			
		if(M[i][j+1]==-4){
			M[i][j+1]=0;
			T[c]=2;
			///NOBAT==0;
			NOBAT=0;
			flag=3;
		}
		else if(M[i][j+1]==-1){
			M[i][j+1]=0;
			T[c]=1;
			///NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-3){
			M[i][j+1]=0;
			T[c]=3;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-5){
			M[i][j+1]=0;
			T[c]=4;
			///NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-8){
			M[i][j+1]=0;
			T[c]=5;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-7){
			M[i][j+1]=0;
			T[c]=6;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-9){
			M[i][j+1]=0;
			T[c]=7;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-12){
			M[i][j+1]=0;
			T[c]=8;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-11){
			M[i][j+1]=0;
			T[c]=9;
			//NOBAT==0;]
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-13){
			M[i][j+1]=0;
			T[c]=10;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-16){
			M[i][j+1]=0;
			T[c]=11;
			//NOBAT==0;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-15){
			M[i][j+1]=0;
			T[c]=12;
			NOBAT=0;flag=3;
			///NOBAT==0;
		}
		V[(i*9)+(j+1)][0]=1;
		V[(i*9)+(j+1)][1]=0;
		V[(i*9)+(j+1)][2]=0;
		c++;
		}
		if(M[i+1][j]<0&&M[i+2][j]>0){
			
		if(M[i+1][j]==-4){
			M[i+1][j]=0;
			T[c]=2;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-1){
			M[i][j+1]=0;
			T[c]=1;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-3){
			M[i+1][j]=0;
			T[c]=3;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-5){
			M[i+1][j]=0;
			T[c]=4;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-8){
			M[i+1][j]=0;
			T[c]=5;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-7){
			M[i+1][j]=0;
			T[c]=6;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-9){
			M[i+1][j]=0;
			T[c]=7;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-12){
			M[i+1][j]=0;
			T[c]=8;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-11){
			M[i+1][j]=0;
			T[c]=9;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-13){
			M[i+1][j]=0;
			T[c]=10;
			NOBAT=0;flag=3;
		}
		else if(M[i][j+1]==-16){
			M[i][j+1]=0;
			T[c]=11;
			NOBAT=0;flag=3;
		}
		else if(M[i+1][j]==-15){
			M[i+1][j]=0;
			T[c]=12;
			NOBAT=0;flag=3;
		}
		V[((i+1)*9)+j][0]=1;
		V[((i+1)*9)+j][1]=0;
		V[((i+1)*9)+j][2]=0;
		c++;
		}
		
		}
		if(l==0&&M[i][j]<0){
		if(M[i][j+1]>0&&M[i][j+2]<0){
			M[i][j+1]=0;
		V[(i*9)+(j+1)][0]=1;
		V[(i*9)+(j+1)][1]=0;
		V[(i*9)+(j+1)][2]=0;
			c++;
		}
		if(M[i+1][j]>0&&M[i+2][j]<0){
			M[i+1][j]=0;
			
		V[((i+1)*9)+j][0]=1;
		V[((i+1)*9)+j][1]=0;
		V[((i+1)*9)+j][2]=0;
		c++;
		}
		}

		}

			
}

void m(int b,int s,int x,int y)//mose (me)
{
	//if(b== GLUT_LEFT_BUTTON&&s==GLUT_UP){
	//for(int i=0;i<30;i++)
	//cout<<T[i]<<endl;
	//cout<<c<<endl;
	//}
	static int x1=0,y1=0,m=0;
	//if(NOBAT==1){// behinetar shavad.
	switch (b)
	{
	case GLUT_LEFT_BUTTON:
		if(flag==0){//for clik one
			if(s==GLUT_DOWN &&x<=498&&x>=424&&y<=118&&y>=44&&(M[0][1]>0)){//quad2
			V[1][0]=1;
			V[1][1]=1;
			V[1][2]=1;
			x1=424;
			y1=44;
			m=2;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500&&y<=118&&y>=44&&(M[0][2]>0)){//quad3
			V[2][0]=1;
			V[2][1]=1;
			V[2][2]=1;
			x1=500;
			y1=44;
			m=3;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576&&y<=118&&y>=44&&(M[0][3]>0)){//quad4
			V[3][0]=1;
			V[3][1]=1;
			V[3][2]=1;
			x1=576;
			y1=44;
			m=4;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652&&y<=118&&y>=44&&(M[0][4]>0)){//quad5
			V[4][0]=1;
			V[4][1]=1;
			V[4][2]=1;
			x1=652;
			y1=44;
			m=5;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728&&y<=118&&y>=44&&(M[0][5]>0)){//quad6
			V[5][0]=1;
			V[5][1]=1;
			V[5][2]=1;
			x1=728;
			y1=44;
			m=6;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804&&y<=118&&y>=44&&(M[0][6]>0)){//quad7
			V[6][0]=1;
			V[6][1]=1;
			V[6][2]=1;
			x1=804;
			y1=44;
			m=7;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880&&y<=118&&y>=44&&(M[0][7]>0)){//quad8
			V[7][0]=1;
			V[7][1]=1;
			V[7][2]=1;
			x1=880;
			y1=44;
			m=8;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}

			//rawtow
			if(s==GLUT_DOWN &&y<=194&&y>=120&&x<=422&&x>=348&&(M[1][0]>0)){//quad1
			V[9][0]=1;
			V[9][1]=1;
			V[9][2]=1;
			x1=348;
			y1=120;
			m=10;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=194&&y>=120&&(M[1][1]>0)){//quad2
			V[10][0]=1;
			V[10][1]=1;
			V[10][2]=1;
			x1=424;
			y1=120;
			m=11;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500 &&y<=194&&y>=120&&(M[1][2]>0)){//quad3
			V[11][0]=1;
			V[11][1]=1;
			V[11][2]=1;
			x1=500;
			y1=120;
			m=12;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576 &&y<=194&&y>=120&&(M[1][3]>0)){//quad4
			V[12][0]=1;
			V[12][1]=1;
			V[12][2]=1;
			x1=576;
			y1=120;
			m=13;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652 &&y<=194&&y>=120&&(M[1][4]>0)){//quad5
			V[13][0]=1;
			V[13][1]=1;
			V[13][2]=1;
			x1=652;
			y1=120;
			m=14;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728 &&y<=194&&y>=120&&(M[1][5]>0)){//quad6
			V[14][0]=1;
			V[14][1]=1;
			V[14][2]=1;
			x1=728;
			y1=120;
			m=15;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804 &&y<=194&&y>=120&&(M[1][6]>0)){//quad7
			V[15][0]=1;
			V[15][1]=1;
			V[15][2]=1;
			x1=804;
			y1=120;
			m=16;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880 &&y<=194&&y>=120&&(M[1][7]>0)){//quad8
			V[16][0]=1;
			V[16][1]=1;
			V[16][2]=1;
			x1=880;
			y1=120;
			m=17;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&y<=194&&y>=120&&x<=1030&&x>=956&&(M[1][8]>0)){//quad9
			V[17][0]=1;
			V[17][1]=1;
			V[17][2]=1;
			x1=956;
			y1=120;
			m=18;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			//raw three
			if(s==GLUT_DOWN &&y<=270&&y>=196&&x<=422&&x>=348&&(M[2][0]>0)){//quad1
			V[18][0]=1;
			V[18][1]=1;
			V[18][2]=1;
			x1=348;
			y1=196;
			m=19;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=270&&y>=196&&(M[2][1]>0)){//quad2
			V[19][0]=1;
			V[19][1]=1;
			V[19][2]=1;
			x1=424;
			y1=196;
			m=20;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500 &&y<=270&&y>=196&&(M[2][2]>0)){//quad3
			V[20][0]=1;
			V[20][1]=1;
			V[20][2]=1;
			x1=500;
			y1=196;
			m=21;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576 &&y<=270&&y>=196&&(M[2][3]>0)){//quad4
			V[21][0]=1;
			V[21][1]=1;
			V[21][2]=1;
			x1=576;
			y1=196;
			m=22;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652 &&y<=270&&y>=196&&(M[2][4]>0)){//quad5
			V[22][0]=1;
			V[22][1]=1;
			V[22][2]=1;
			x1=652;
			y1=196;
			m=23;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728 &&y<=270&&y>=196&&(M[2][5]>0)){//quad6
			V[23][0]=1;
			V[23][1]=1;
			V[23][2]=1;
			x1=728;
			y1=196;
			m=24;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804 &&y<=270&&y>=196&&(M[2][6]>0)){//quad7
			V[24][0]=1;
			V[24][1]=1;
			V[24][2]=1;
			x1=804;
			y1=196;
			m=25;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880 &&y<=270&&y>=196&&(M[2][7]>0)){//quad8
			V[25][0]=1;
			V[25][1]=1;
			V[25][2]=1;
			x1=880;
			y1=196;
			m=26;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&y<=270&&y>=196&&x<=1030&&x>=956&&(M[2][8]>0)){//quad9
			V[26][0]=1;
			V[26][1]=1;
			V[26][2]=1;
			x1=956;
			y1=196;
			m=27;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			//raw four
			if(s==GLUT_DOWN &&y<=346&&y>=272&&x<=422&&x>=348&&(M[3][0]>0)){//quad1
			V[27][0]=1;
			V[27][1]=1;
			V[27][2]=1;
			x1=348;
			y1=272;
			m=28;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424  &&y<=346&&y>=272&&(M[3][1]>0)){//quad2
			V[28][0]=1;
			V[28][1]=1;
			V[28][2]=1;
			x1=424;
			y1=272;
			m=29;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500  &&y<=346&&y>=272&&(M[3][2]>0)){//quad3
			V[29][0]=1;
			V[29][1]=1;
			V[29][2]=1;
			x1=500;
			y1=272;
			m=30;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=346&&y>=272&&(M[3][3]>0)){//quad4
			V[30][0]=1;
			V[30][1]=1;
			V[30][2]=1;
			x1=576;
			y1=272;
			m=31;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=346&&y>=272&&(M[3][4]>0)){//quad5
			V[31][0]=1;
			V[31][1]=1;
			V[31][2]=1;
			x1=652;
			y1=272;
			m=32;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=346&&y>=272&&(M[3][5]>0)){//quad6
			V[32][0]=1;
			V[32][1]=1;
			V[32][2]=1;
			x1=728;
			y1=272;
			m=33;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=346&&y>=272&&(M[3][6]>0)){//quad7
			V[33][0]=1;
			V[33][1]=1;
			V[33][2]=1;
			x1=804;
			y1=272;
			m=34;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=346&&y>=272&&(M[3][7]>0)){//quad8
			V[34][0]=1;
			V[34][1]=1;
			V[34][2]=1;
			x1=880;
			y1=272;
			m=35;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN  &&y<=346&&y>=272&&x<=1030&&x>=956&&(M[3][8]>0)){//quad9
			V[35][0]=1;
			V[35][1]=1;
			V[35][2]=1;
			x1=956;
			y1=272;
			m=36;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			//raw five
			if(s==GLUT_DOWN &&y<=422&&y>=348&&x<=422&&x>=348&&(M[4][0]>0)){//quad1
			V[36][0]=1;
			V[36][1]=1;
			V[36][2]=1;
			x1=348;
			y1=348;
			m=37;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424  &&y<=422&&y>=348&&(M[4][1]>0)){//quad2
			V[37][0]=1;
			V[37][1]=1;
			V[37][2]=1;
			x1=424;
			y1=348;
			m=38;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500  &&y<=422&&y>=348&&(M[4][2]>0)){//quad3
			V[38][0]=1;
			V[38][1]=1;
			V[38][2]=1;
			x1=500;
			y1=348;
			m=39;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=422&&y>=348&&(M[4][3]>0)){//quad4
			V[39][0]=1;
			V[39][1]=1;
			V[39][2]=1;
			x1=576;
			y1=348;
			m=40;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=422&&y>=348&&(M[4][4]>0)){//quad5
			V[40][0]=1;
			V[40][1]=1;
			V[40][2]=1;
			x1=652;
			y1=348;
			m=41;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=422&&y>=348&&(M[4][5]>0)){//quad6
			V[41][0]=1;
			V[41][1]=1;
			V[41][2]=1;
			x1=728;
			y1=348;
			m=42;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=422&&y>=348&&(M[4][6]>0)){//quad7
			V[42][0]=1;
			V[42][1]=1;
			V[42][2]=1;
			x1=804;
			y1=348;
			m=43;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=422&&y>=348&&(M[4][7]>0)){//quad8
			V[43][0]=1;
			V[43][1]=1;
			V[43][2]=1;
			x1=880;
			y1=348;
			m=44;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN  &&y<=422&&y>=348&&x<=1030&&x>=956&&(M[4][8]>0)){//quad9
			V[44][0]=1;
			V[44][1]=1;
			V[44][2]=1;
			x1=956;
			y1=348;
			m=45;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			//raw six
		if(s==GLUT_DOWN &&y<=498&&y>=424&&x<=422&&x>=348&&(M[5][0]>0)){//quad1
			V[45][0]=1;
			V[45][1]=1;
			V[45][2]=1;
			x1=348;
			y1=424;
			m=46;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424  &&y<=498&&y>=424&&(M[5][1]>0)){//quad2
			V[46][0]=1;
			V[46][1]=1;
			V[46][2]=1;
			x1=424;
			y1=424;
			m=47;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500  &&y<=498&&y>=424&&(M[5][2]>0)){//quad3
			V[47][0]=1;
			V[47][1]=1;
			V[47][2]=1;
			x1=500;
			y1=424;
			m=48;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=498&&y>=424&&(M[5][3]>0)){//quad4
			V[48][0]=1;
			V[48][1]=1;
			V[48][2]=1;
			x1=576;
			y1=424;
			m=49;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=498&&y>=424&&(M[5][4]>0)){//quad5
			V[49][0]=1;
			V[49][1]=1;
			V[49][2]=1;
			x1=652;
			y1=424;
			m=50;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=498&&y>=424&&(M[5][5]>0)){//quad6
			V[50][0]=1;
			V[50][1]=1;
			V[50][2]=1;
			x1=728;
			y1=424;
			m=51;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=498&&y>=424&&(M[5][6]>0)){//quad7
			V[51][0]=1;
			V[51][1]=1;
			V[51][2]=1;
			x1=804;
			y1=424;
			m=52;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=498&&y>=424&&(M[5][7]>0)){//quad8
			V[52][0]=1;
			V[52][1]=1;
			V[52][2]=1;
			x1=880;
			y1=424;
			m=53;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN  &&y<=498&&y>=424&&x<=1030&&x>=956&&(M[5][8]>0)){//quad9
			V[53][0]=1;
			V[53][1]=1;
			V[53][2]=1;
			x1=956;
			y1=424;
			m=54;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			//raw seven
			if(s==GLUT_DOWN &&y<=574&&y>=500&&x<=422&&x>=348&&(M[6][0]>0)){//quad1
			V[54][0]=1;
			V[54][1]=1;
			V[54][2]=1;
			x1=348;
			y1=500;
			m=55;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=574&&y>=500&&(M[6][1]>0)){//quad2
			V[55][0]=1;
			V[55][1]=1;
			V[55][2]=1;
			x1=424;
			y1=500;
			m=56;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500 &&y<=574&&y>=500&&(M[6][2]>0)){//quad3
			V[56][0]=1;
			V[56][1]=1;
			V[56][2]=1;
			x1=500;
			y1=500;
			m=57;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=574&&y>=500&&(M[6][3]>0)){//quad4
			V[57][0]=1;
			V[57][1]=1;
			V[57][2]=1;
			x1=576;
			y1=500;
			m=58;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=574&&y>=500&&(M[6][4]>0)){//quad5
			V[58][0]=1;
			V[58][1]=1;
			V[58][2]=1;
			x1=652;
			y1=500;
			m=59;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=574&&y>=500&&(M[6][5]>0)){//quad6
			V[59][0]=1;
			V[59][1]=1;
			V[59][2]=1;
			x1=728;
			y1=500;
			m=60;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=574&&y>=500&&(M[6][6]>0)){//quad7
			V[60][0]=1;
			V[60][1]=1;
			V[60][2]=1;
			x1=804;
			y1=500;
			m=61;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=574&&y>=500&&(M[6][7]>0)){//quad8
			V[61][0]=1;
			V[61][1]=1;
			V[61][2]=1;
			x1=880;
			y1=500;
			m=62;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN  &&y<=574&&y>=500&&x<=1030&&x>=956&&(M[6][8]>0)){//quad9
			V[62][0]=1;
			V[62][1]=1;
			V[62][2]=1;
			x1=956;
			y1=500;
			m=63;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			//raw eight
			if(s==GLUT_DOWN &&y<=650&&y>=576&&x<=422&&x>=348&&(M[7][0]>0)){//quad1
			V[63][0]=1;
			V[63][1]=1;
			V[63][2]=1;
			x1=348;
			y1=576;
			m=64;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=650&&y>=576&&(M[7][1]>0)){//quad2
			V[64][0]=1;
			V[64][1]=1;
			V[64][2]=1;
			x1=424;
			y1=576;
			m=65;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500 &&y<=650&&y>=576&&(M[7][2]>0)){//quad3
			V[65][0]=1;
			V[65][1]=1;
			V[65][2]=1;
			x1=500;
			y1=576;
			m=66;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=650&&y>=576&&(M[7][3]>0)){//quad4
			V[66][0]=1;
			V[66][1]=1;
			V[66][2]=1;
			x1=576;
			y1=576;
			m=67;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=650&&y>=576&&(M[7][4]>0)){//quad5
			V[67][0]=1;
			V[67][1]=1;
			V[67][2]=1;
			x1=652;
			y1=576;
			m=68;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=650&&y>=576&&(M[7][5]>0)){//quad6
			V[68][0]=1;
			V[68][1]=1;
			V[68][2]=1;
			x1=728;
			y1=576;
			m=69;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=650&&y>=576&&(M[7][6]>0)){//quad7
			V[69][0]=1;
			V[69][1]=1;
			V[69][2]=1;
			x1=804;
			y1=576;
			m=70;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=650&&y>=576&&(M[7][7]>0)){//quad8
			V[70][0]=1;
			V[70][1]=1;
			V[70][2]=1;
			x1=880;
			y1=576;
			m=71;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN  &&y<=650&&y>=576&&x<=1030&&x>=956&&(M[7][8]>0)){//quad9
			V[71][0]=1;
			V[71][1]=1;
			V[71][2]=1;
			x1=956;
			y1=576;
			m=72;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		
				//raw nine
	
			
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=726&&y>=652&&(M[8][1]>0)){//quad2
			V[73][0]=1;
			V[73][1]=1;
			V[73][2]=1;
			x1=424;
			y1=652;
			m=74;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN&&x<=574&&x>=500 &&y<=726&&y>=652&&(M[8][2]>0)){//quad3
			V[74][0]=1;
			V[74][1]=1;
			V[74][2]=1;
			x1=500;
			y1=652;
			m=75;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
		if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=726&&y>=652&&(M[8][3]>0)){//quad4
			V[75][0]=1;
			V[75][1]=1;
			V[75][2]=1;
			x1=576;
			y1=652;
			m=76;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=726&&y>=652&&(M[8][4]>0)){//quad5
			V[76][0]=1;
			V[76][1]=1;
			V[76][2]=1;
			x1=652;
			y1=652;
			m=77;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=726&&y>=652&&(M[8][5]>0)){//quad6
			V[77][0]=1;
			V[77][1]=1;
			V[77][2]=1;
			x1=728;
			y1=652;
			m=78;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=726&&y>=652&&(M[8][6]>0)){//quad7
			V[78][0]=1;
			V[78][1]=1;
			V[78][2]=1;
			x1=804;
			y1=652;
			m=79;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=726&&y>=652&&(M[8][7]>0)){//quad8
			V[79][0]=1;
			V[79][1]=1;
			V[79][2]=1;
			x1=880;
			y1=652;
			m=80;
			flag=1;
			//cout<<x1<<"  m"<<y1;
		}
			
		} 
		else if(flag==1){//for click tow
			if(s==GLUT_DOWN &&x<=422&&x>=348&&y<=118&&y>=44){//quad1
			if(x1==348&&y1!=44&&M[0+((m-1)/9)][0]==9&&canmove(1,1,m)){
			y00[M[0+((m-1)/9)][0]-1]+=(((m-1)/9)*1.9);
			M[0][0]=M[0+((m-1)/9)][0];// ��� �� ��� ����
			M[0+((m-1)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[1][0]=1;V[1][1]=.900;V[1][2]=.011;
			V[9][0]=1;V[9][1]=.900;V[9][2]=.011;
			flag=4;//etmam bazi	
			
			}
			else if(y1==44&&x1!=348&&M[0][0+(m-1)]==9&&canmove(1,2,m)){
			x00[M[0][0+(m-1)]-1]+=((1-m)*1.9);//dota niazeh -1
			M[0][0]=M[0][0+(m-1)];
			M[0][0+(m-1)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[1][0]=.3;V[1][1]=.8;V[1][2]=.3;
			V[9][0]=.3;V[9][1]=.8;V[9][2]=.3;
			flag=4;//etmam bazi	
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424&&y<=118&&y>=44&&(M[0][1]==0)){//quad2
			if(x1==498&&y1!=44&&canmove(2,1,m)){
			y00[M[0+((m-2)/9)][1]-1]+=(((m-2)/9)*1.9);
			M[0][1]=M[0+((m-2)/9)][1];// ��� �� ��� ����
			M[0+((m-2)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(0,1,2);
			}
			else if(y1==44&&x1!=498&&canmove(2,2,m)){
			x00[M[0][1+(m-2)]-1]+=((2-m)*1.9);//dota niazeh -1
			M[0][1]=M[0][1+(m-2)];
			M[0][1+(m-2)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,1,2);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500&&y<=118&&y>=44&&(M[0][2]==0)){//quad3
			if(x1==500&&y1!=44&&canmove(3,1,m)){
			y00[M[0+((m-2)/9)][2]-1]+=(((m-3)/9)*1.9);
			M[0][2]=M[0+((m-3)/9)][2];// ��� �� ��� ����
			M[0+((m-3)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(0,2,3);
			}
			else if(y1==44&&x1!=500&&canmove(3,2,m)){
			x00[M[0][2+(m-3)]-1]+=((3-m)*1.9);//dota niazeh -1
			M[0][2]=M[0][2+(m-3)];
			M[0][2+(m-3)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,2,3);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576&&y<=118&&y>=44&&(M[0][3]==0)){//quad4
			if(x1==576&&y1!=44&&canmove(4,1,m)){
			y00[M[0+((m-4)/9)][3]-1]+=(((m-4)/9)*1.9);
			M[0][3]=M[0+((m-4)/9)][3];// ��� �� ��� ����
			M[0+((m-4)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(0,3,4);
			}
			else if(y1==44&&x1!=576&&canmove(4,2,m)){
			x00[M[0][3+(m-4)]-1]+=((4-m)*1.9);//dota niazeh -1
			M[0][3]=M[0][3+(m-4)];
			M[0][3+(m-4)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,3,4);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652&&y<=118&&y>=44&&(M[0][4]==0)){//quad5
			if(x1==652&&y1!=44&&canmove(5,1,m)){
			y00[M[0+((m-5)/9)][4]-1]+=(((m-5)/9)*1.9);
			M[0][4]=M[0+((m-5)/9)][4];// ��� �� ��� ����
			M[0+((m-5)/9)][4]=0;
			if(m==41){//for king home
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;	
			hitt(0,4,5);
			}
			else if(y1==44&&x1!=652&&canmove(5,2,m)){
			x00[M[0][4+(m-5)]-1]+=((5-m)*1.9);//dota niazeh -1
			M[0][4]=M[0][4+(m-5)];
			M[0][4+(m-5)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;	
			hitt(0,4,5);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728&&y<=118&&y>=44&&(M[0][5]==0)){//quad6
			if(x1==728&&y1!=44&&canmove(6,1,m)){
			y00[M[0+((m-6)/9)][5]-1]+=(((m-6)/9)*1.9);
			M[0][5]=M[0+((m-6)/9)][5];// ��� �� ��� ����
			M[0+((m-6)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,5,6);
			}
			else if(y1==44&&x1!=728&&canmove(6,2,m)){
			x00[M[0][5+(m-6)]-1]+=((6-m)*1.9);//dota niazeh -1
			M[0][5]=M[0][5+(m-6)];
			M[0][5+(m-6)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,5,6);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804&&y<=118&&y>=44&&(M[0][6]==0)){//quad7
			if(x1==804&&y1!=44&&canmove(7,1,m)){
			y00[M[0+((m-7)/9)][6]-1]+=(((m-7)/9)*1.9);
			M[0][6]=M[0+((m-7)/9)][6];// ��� �� ��� ����
			M[0+((m-7)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(0,6,7);
			}
			else if(y1==44&&x1!=804&&canmove(7,2,m)){
			x00[M[0][6+(m-7)]-1]+=((7-m)*1.9);//dota niazeh -1
			M[0][6]=M[0][6+(m-7)];
			M[0][6+(m-7)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,6,7);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880&&y<=118&&y>=44&&(M[0][7]==0)){//quad8
			if(x1==880&&y1!=44&&canmove(8,1,m)){
			y00[M[0+((m-8)/9)][7]-1]+=(((m-8)/9)*1.9);
			M[0][7]=M[0+((m-8)/9)][7];// ��� �� ��� ����
			M[0+((m-8)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(0,7,8);
			}
			else if(y1==44&&x1!=880&&canmove(8,2,m)){
			x00[M[0][7+(m-8)]-1]+=((8-m)*1.9);//dota niazeh -1
			M[0][7]=M[0][7+(m-8)];
			M[0][7+(m-8)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(0,7,8);
			}
		}
			if(s==GLUT_DOWN &&x<=1030&&x>=956&&y<=118&&y>=44){//quad9
			if(x1==956&&y1!=44&&M[0+((m-9)/9)][8]==9&&canmove(9,1,m)){
			y00[M[0+((m-9)/9)][8]-1]+=(((m-9)/9)*1.9);
			M[0][8]=M[0+((m-9)/9)][8];// ��� �� ��� ����
			M[0+((m-9)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[7][0]=.3;V[7][1]=.8;V[7][2]=.3;
			V[17][0]=.3;V[17][1]=.8;V[17][2]=.3;
			flag=4;//etmam bazi		
			}
			else if(y1==44&&x1!=956&&M[0][8+(m-9)]==9&&canmove(9,2,m)){
			x00[M[0][8+(m-9)]-1]+=((9-m)*1.9);//dota niazeh -1
			M[0][8]=M[0][8+(m-9)];
			M[0][8+(m-9)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[7][0]=1;V[7][1]=.900;V[7][2]=.011;
			V[17][0]=1;V[17][1]=.900;V[17][2]=.011;
			flag=4;//etmam bazi	
			}
		}
			//raw two
			if(s==GLUT_DOWN &&y<=194&&y>=120&&x<=422&&x>=348&&(M[1][0]==0)){//quad1
			if(x1==348&&y1!=120&&canmove(10,1,m)){
			y00[M[1+((m-10)/9)][0]-1]+=(((m-10)/9)*1.9);
			M[1][0]=M[1+((m-10)/9)][0];// ��� �� ��� ����
			M[1+((m-10)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(1,0,10);
			}
			else if(y1==120&&x1!=348&&canmove(10,2,m)){
			x00[M[1][0+(m-10)]-1]+=((10-m)*1.9);//dota niazeh -1
			M[1][0]=M[1][0+(m-10)];
			M[1][0+(m-10)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,0,10);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=194&&y>=120&&(M[1][1]==0)){//quad2
			if(x1==424&&y1!=120&&canmove(11,1,m)){
			y00[M[1+((m-11)/9)][1]-1]+=(((m-11)/9)*1.9);
			M[1][1]=M[1+((m-11)/9)][1];// ��� �� ��� ����
			M[1+((m-11)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(1,1,11);
			}
			else if(y1==120&&x1!=424&&canmove(11,2,m)){
			x00[M[1][1+(m-11)]-1]+=((11-m)*1.9);//dota niazeh -1
			M[1][1]=M[1][1+(m-11)];
			M[1][1+(m-11)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,1,11);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500 &&y<=194&&y>=120&&(M[1][2]==0)){//quad3
			if(x1==500&&y1!=120&&canmove(12,1,m)){
			y00[M[1+((m-12)/9)][2]-1]+=(((m-12)/9)*1.9);
			M[1][2]=M[1+((m-12)/9)][2];// ��� �� ��� ����
			M[1+((m-12)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(1,2,12);
			}
			else if(y1==120&&x1!=500&&canmove(12,2,m)){
			x00[M[1][2+(m-12)]-1]+=((12-m)*1.9);//dota niazeh -1
			M[1][2]=M[1][2+(m-12)];
			M[1][2+(m-12)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,2,12);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576 &&y<=194&&y>=120&&(M[1][3]==0)){//quad4
			if(x1==576&&y1!=120&&canmove(13,1,m)){
			y00[M[1+((m-13)/9)][3]-1]+=(((m-13)/9)*1.9);
			M[1][3]=M[1+((m-13)/9)][3];// ��� �� ��� ����
			M[1+((m-13)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(1,3,13);
			}
			else if(y1==120&&x1!=576&&canmove(13,2,m)){
			x00[M[1][3+(m-13)]-1]+=((13-m)*1.9);//dota niazeh -1
			M[1][3]=M[1][3+(m-13)];
			M[1][3+(m-13)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,3,13);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652 &&y<=194&&y>=120&&(M[1][4]==0)){//quad5
			if(x1==652&&y1!=120&&canmove(14,1,m)){
			y00[M[1+((m-14)/9)][4]-1]+=(((m-14)/9)*1.9);
			M[1][4]=M[1+((m-14)/9)][4];// ��� �� ��� ����
			M[1+((m-14)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(1,4,14);
			}
			else if(y1==120&&x1!=652&&canmove(14,2,m)){
			x00[M[1][4+(m-14)]-1]+=((14-m)*1.9);//dota niazeh -1
			M[1][4]=M[1][4+(m-14)];
			M[1][4+(m-14)]=0;
			if(m==41){
			V[m-1][0]=.1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(1,4,14);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728 &&y<=194&&y>=120&&(M[1][5]==0)){//quad6
			if(x1==728&&y1!=120&&canmove(15,1,m)){
			y00[M[1+((m-15)/9)][5]-1]+=(((m-15)/9)*1.9);
			M[1][5]=M[1+((m-15)/9)][5];// ��� �� ��� ����
			M[1+((m-15)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(1,5,15);
			}
			else if(y1==120&&x1!=728&&canmove(15,2,m)){
			x00[M[1][5+(m-15)]-1]+=((15-m)*1.9);//dota niazeh -1
			M[1][5]=M[1][5+(m-15)];
			M[1][5+(m-15)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,5,15);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804 &&y<=194&&y>=120&&(M[1][6]==0)){//quad7
			if(x1==804&&y1!=120&&canmove(16,1,m)){
			y00[M[1+((m-16)/9)][6]-1]+=(((m-16)/9)*1.9);
			M[1][6]=M[1+((m-16)/9)][6];// ��� �� ��� ����
			M[1+((m-16)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,6,16);
			}
			else if(y1==120&&x1!=804&&canmove(16,2,m)){
			x00[M[1][6+(m-16)]-1]+=((16-m)*1.9);//dota niazeh -1
			M[1][6]=M[1][6+(m-16)];
			M[1][6+(m-16)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,6,16);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880 &&y<=194&&y>=120&&(M[1][7]==0)){//quad8
			if(x1==880&&y1!=120&&canmove(17,1,m)){
			y00[M[1+((m-17)/9)][7]-1]+=(((m-17)/9)*1.9);
			M[1][7]=M[1+((m-17)/9)][7];// ��� �� ��� ����
			M[1+((m-17)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(1,7,17);
			}
			else if(y1==120&&x1!=880&&canmove(17,2,m)){
			x00[M[1][7+(m-17)]-1]+=((17-m)*1.9);//dota niazeh -1
			M[1][7]=M[1][7+(m-17)];
			M[1][7+(m-17)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,7,17);
			}
		}
			if(s==GLUT_DOWN &&y<=194&&y>=120&&x<=1030&&x>=956&&(M[1][8]==0)){//quad9
			if(x1==956&&y1!=120&&canmove(18,1,m)){
			y00[M[1+((m-18)/9)][8]-1]+=(((m-18)/9)*1.9);
			M[1][8]=M[1+((m-18)/9)][8];// ��� �� ��� ����
			M[1+((m-18)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,8,18);
			}
			else if(y1==120&&x1!=956&&canmove(18,2,m)){
			x00[M[1][8+(m-18)]-1]+=((18-m)*1.9);//dota niazeh -1
			M[1][8]=M[1][8+(m-18)];
			M[1][8+(m-18)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(1,8,18);
			}
		}
			//rawthree
			if(s==GLUT_DOWN &&y<=270&&y>=196&&x<=422&&x>=348&&(M[2][0]==0)){//quad1
			if(x1==348&&y1!=196&&canmove(19,1,m)){
			y00[M[2+((m-19)/9)][0]-1]+=(((m-19)/9)*1.9);
			M[2][0]=M[2+((m-19)/9)][0];// ��� �� ��� ����
			M[2+((m-19)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,0,19);
			}
			else if(y1==196&&x1!=348&&canmove(19,2,m)){
			x00[M[2][0+(m-19)]-1]+=((19-m)*1.9);//dota niazeh -1
			M[2][0]=M[2][0+(m-19)];
			M[2][0+(m-19)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,0,19);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=270&&y>=196&&(M[2][1]==0)){//quad2
			if(x1==424&&y1!=196&&canmove(20,1,m)){
			y00[M[2+((m-20)/9)][1]-1]+=(((m-20)/9)*1.9);
			M[2][1]=M[2+((m-20)/9)][1];// ��� �� ��� ����
			M[2+((m-20)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,1,20);
			}
			else if(y1==196&&x1!=424&&canmove(20,2,m)){
			x00[M[2][1+(m-20)]-1]+=((20-m)*1.9);//dota niazeh -1
			M[2][1]=M[2][1+(m-20)];
			M[2][1+(m-20)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,1,20);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500 &&y<=270&&y>=196&&(M[2][2]==0)){//quad3
			if(x1==500&&y1!=196&&canmove(21,1,m)){
			y00[M[2+((m-21)/9)][2]-1]+=(((m-21)/9)*1.9);
			M[2][2]=M[2+((m-21)/9)][2];// ��� �� ��� ����
			M[2+((m-21)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,2,21);
			}
			else if(y1==196&&x1!=500&&canmove(21,2,m)){
			x00[M[2][2+(m-21)]-1]+=((21-m)*1.9);//dota niazeh -1
			M[2][2]=M[2][2+(m-21)];
			M[2][2+(m-21)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,2,21);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576 &&y<=270&&y>=196&&(M[2][3]==0)){//quad4
			if(x1==576&&y1!=196&&canmove(22,1,m)){
			y00[M[2+((m-22)/9)][3]-1]+=(((m-22)/9)*1.9);
			M[2][3]=M[2+((m-22)/9)][3];// ��� �� ��� ����
			M[2+((m-22)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,3,22);
			}
			else if(y1==196&&x1!=576&&canmove(22,2,m)){
			x00[M[2][3+(m-22)]-1]+=((22-m)*1.9);//dota niazeh -1
			M[2][3]=M[2][3+(m-22)];
			M[2][3+(m-22)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,3,22);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652 &&y<=270&&y>=196&&(M[2][4]==0)){//quad5
			if(x1==652&&y1!=196&&canmove(23,1,m)){
			y00[M[2+((m-23)/9)][4]-1]+=(((m-23)/9)*1.9);
			M[2][4]=M[2+((m-23)/9)][4];// ��� �� ��� ����
			M[2+((m-23)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;	
			hitt(2,4,23);
			}
			else if(y1==196&&x1!=652&&canmove(23,2,m)){
			x00[M[2][4+(m-23)]-1]+=((23-m)*1.9);//dota niazeh -1
			M[2][4]=M[2][4+(m-23)];
			M[2][4+(m-23)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(2,4,23);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728 &&y<=270&&y>=196&&(M[2][5]==0)){//quad6
			if(x1==728&&y1!=196&&canmove(24,1,m)){
			y00[M[2+((m-24)/9)][5]-1]+=(((m-24)/9)*1.9);
			M[2][5]=M[2+((m-24)/9)][5];// ��� �� ��� ����
			M[2+((m-24)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,5,24);
			}
			else if(y1==196&&x1!=728&&canmove(24,2,m)){
			x00[M[2][5+(m-24)]-1]+=((24-m)*1.9);//dota niazeh -1
			M[2][5]=M[2][5+(m-24)];
			M[2][5+(m-24)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,5,24);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804 &&y<=270&&y>=196&&(M[2][6]==0)){//quad7
			if(x1==804&&y1!=196&&canmove(25,1,m)){
			y00[M[2+((m-25)/9)][6]-1]+=(((m-25)/9)*1.9);
			M[2][6]=M[2+((m-25)/9)][6];// ��� �� ��� ����
			M[2+((m-25)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,6,25);
			}
			else if(y1==196&&x1!=804&&canmove(25,2,m)){
			x00[M[2][6+(m-25)]-1]+=((25-m)*1.9);//dota niazeh -1
			M[2][6]=M[2][6+(m-25)];
			M[2][6+(m-25)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,6,25);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880 &&y<=270&&y>=196&&(M[2][7]==0)){//quad8
			if(x1==880&&y1!=196&&canmove(26,1,m)){
			y00[M[2+((m-26)/9)][7]-1]+=(((m-26)/9)*1.9);
			M[2][7]=M[2+((m-26)/9)][7];// ��� �� ��� ����
			M[2+((m-26)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,7,26);
			}
			else if(y1==196&&x1!=880&&canmove(26,2,m)){
			x00[M[2][7+(m-26)]-1]+=((26-m)*1.9);//dota niazeh -1
			M[2][7]=M[2][7+(m-26)];
			M[2][7+(m-26)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,7,26);
			}
		}
			if(s==GLUT_DOWN &&y<=270&&y>=196&&x<=1030&&x>=956&&(M[2][8]==0)){//quad9
			if(x1==956&&y1!=196&&canmove(27,1,m)){
			y00[M[2+((m-27)/9)][8]-1]+=(((m-27)/9)*1.9);
			M[2][8]=M[2+((m-27)/9)][8];// ��� �� ��� ����
			M[2+((m-27)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,8,27);
			}
			else if(y1==196&&x1!=956&&canmove(27,2,m)){
			x00[M[2][8+(m-27)]-1]+=((27-m)*1.9);//dota niazeh -1
			M[2][8]=M[2][8+(m-27)];
			M[2][8+(m-27)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(2,8,27);
			}
		}

			//rawfour
			if(s==GLUT_DOWN &&y<=346&&y>=272&&x<=422&&x>=348&&(M[3][0]==0)){//quad1
			if(x1==348&&y1!=272&&canmove(28,1,m)){
			y00[M[3+((m-28)/9)][0]-1]+=(((m-28)/9)*1.9);
			M[3][0]=M[3+((m-28)/9)][0];// ��� �� ��� ����
			M[3+((m-28)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,0,28);
			}
			else if(y1==272&&x1!=348&&canmove(28,2,m)){
			x00[M[3][0+(m-28)]-1]+=((28-m)*1.9);//dota niazeh -1
			M[3][0]=M[3][0+(m-28)];
			M[3][0+(m-28)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,0,28);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424  &&y<=346&&y>=272&&(M[3][1]==0)){//quad2
			if(x1==424&&y1!=272&&canmove(29,1,m)){
			y00[M[3+((m-29)/9)][1]-1]+=(((m-29)/9)*1.9);
			M[3][1]=M[3+((m-29)/9)][1];// ��� �� ��� ����
			M[3+((m-29)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,1,29);
			}
			else if(y1==272&&x1!=424&&canmove(29,2,m)){
			x00[M[3][1+(m-29)]-1]+=((29-m)*1.9);//dota niazeh -1
			M[3][1]=M[3][1+(m-29)];
			M[3][1+(m-29)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,1,29);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500  &&y<=346&&y>=272&&(M[3][2]==0)){//quad3
			if(x1==500&&y1!=272&&canmove(30,1,m)){
			y00[M[3+((m-30)/9)][2]-1]+=(((m-30)/9)*1.9);
			M[3][2]=M[3+((m-30)/9)][2];// ��� �� ��� ����
			M[3+((m-30)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,2,30);
			}
			else if(y1==272&&x1!=500&&canmove(30,2,m)){
			x00[M[3][2+(m-30)]-1]+=((30-m)*1.9);//dota niazeh -1
			M[3][2]=M[3][2+(m-30)];
			M[3][2+(m-30)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,2,30);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=346&&y>=272&&(M[3][3]==0)){//quad4
			if(x1==576&&y1!=272&&canmove(31,1,m)){
			y00[M[3+((m-31)/9)][3]-1]+=(((m-31)/9)*1.9);
			M[3][3]=M[3+((m-31)/9)][3];// ��� �� ��� ����
			M[3+((m-31)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,3,31);
			}
			else if(y1==272&&x1!=576&&canmove(31,2,m)){
			x00[M[3][3+(m-31)]-1]+=((31-m)*1.9);//dota niazeh -1
			M[3][3]=M[3][3+(m-31)];
			M[3][3+(m-31)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,3,31);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=346&&y>=272&&(M[3][4]==0)){//quad5
			if(x1==652&&y1!=272&&canmove(32,1,m)){
			y00[M[3+((m-32)/9)][4]-1]+=(((m-32)/9)*1.9);
			M[3][4]=M[3+((m-32)/9)][4];// ��� �� ��� ����
			M[3+((m-32)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(3,4,32);
			}
			else if(y1==272&&x1!=652&&canmove(32,2,m)){
			x00[M[3][4+(m-32)]-1]+=((32-m)*1.9);//dota niazeh -1
			M[3][4]=M[3][4+(m-32)];
			M[3][4+(m-32)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(3,4,32);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=346&&y>=272&&(M[3][5]==0)){//quad6
			if(x1==728&&y1!=272&&canmove(33,1,m)){
			y00[M[3+((m-33)/9)][5]-1]+=(((m-33)/9)*1.9);
			M[3][5]=M[3+((m-33)/9)][5];// ��� �� ��� ����
			M[3+((m-33)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,5,33);
			}
			else if(y1==272&&x1!=728&&canmove(33,2,m)){
			x00[M[3][5+(m-33)]-1]+=((33-m)*1.9);//dota niazeh -1
			M[3][5]=M[3][5+(m-33)];
			M[3][5+(m-33)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,5,33);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=346&&y>=272&&(M[3][6]==0)){//quad7
			if(x1==804&&y1!=272&&canmove(34,1,m)){
			y00[M[3+((m-34)/9)][6]-1]+=(((m-34)/9)*1.9);
			M[3][6]=M[3+((m-34)/9)][6];// ��� �� ��� ����
			M[3+((m-34)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,6,34);
			}
			else if(y1==272&&x1!=804&&canmove(34,2,m)){
			x00[M[3][6+(m-34)]-1]+=((34-m)*1.9);//dota niazeh -1
			M[3][6]=M[3][6+(m-34)];
			M[3][6+(m-34)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,6,34);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=346&&y>=272&&(M[3][7]==0)){//quad8
			if(x1==880&&y1!=272&&canmove(35,1,m)){
			y00[M[3+((m-35)/9)][7]-1]+=(((m-35)/9)*1.9);
			M[3][7]=M[3+((m-35)/9)][7];// ��� �� ��� ����
			M[3+((m-35)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,7,35);
			}
			else if(y1==272&&x1!=880&&canmove(35,2,m)){
			x00[M[3][7+(m-35)]-1]+=((35-m)*1.9);//dota niazeh -1
			M[3][7]=M[3][7+(m-35)];
			M[3][7+(m-35)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,7,35);
			}
		}
			if(s==GLUT_DOWN &&y<=346&&y>=272&&x<=1030&&x>=956&&(M[3][8]==0)){//quad9
			if(x1==956&&y1!=272&&canmove(36,1,m)){
			y00[M[3+((m-36)/9)][8]-1]+=(((m-36)/9)*1.9);
			M[3][8]=M[3+((m-36)/9)][8];// ��� �� ��� ����
			M[3+((m-36)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,8,36);
			}
			else if(y1==272&&x1!=956&&canmove(36,2,m)){
			x00[M[3][8+(m-36)]-1]+=((36-m)*1.9);//dota niazeh -1
			M[3][8]=M[3][8+(m-36)];
			M[3][8+(m-36)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(3,8,36);
			}
		}
			//rawfive
			if(s==GLUT_DOWN &&y<=422&&y>=348&&x<=422&&x>=348&&(M[4][0]==0)){//quad1
			if(x1==348&&y1!=348&&canmove(37,1,m)){//31 to 37
			y00[M[4+((m-37)/9)][0]-1]+=(((m-37)/9)*1.9);
			M[4][0]=M[4+((m-37)/9)][0];// ��� �� ��� ����
			M[4+((m-37)/9)][0]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,0,37);
			}
			else if(y1==348&&x1!=348&&canmove(37,2,m)){
			x00[M[4][0+(m-37)]-1]+=((37-m)*1.9);//dota niazeh -1
			M[4][0]=M[4][0+(m-37)];
			M[4][0+(m-37)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,0,37);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424  &&y<=422&&y>=348&&(M[4][1]==0)){//quad2
			if(x1==424&&y1!=348&&canmove(38,1,m)){
			y00[M[4+((m-38)/9)][1]-1]+=(((m-38)/9)*1.9);
			M[4][1]=M[4+((m-38)/9)][1];// ��� �� ��� ����
			M[4+((m-38)/9)][1]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,1,38);
			}
			else if(y1==348&&x1!=424&&canmove(38,2,m)){
			x00[M[4][1+(m-38)]-1]+=((38-m)*1.9);//dota niazeh -1
			M[4][1]=M[4][1+(m-38)];
			M[4][1+(m-38)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,1,38);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500  &&y<=422&&y>=348&&(M[4][2]==0)){//quad3
			if(x1==500&&y1!=348&&canmove(39,1,m)){
			y00[M[4+((m-39)/9)][2]-1]+=(((m-39)/9)*1.9);
			M[4][2]=M[4+((m-39)/9)][2];// ��� �� ��� ����
			M[4+((m-39)/9)][2]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,2,39);
			}
			else if(y1==348&&x1!=500&&canmove(39,2,m)){
			x00[M[4][2+(m-39)]-1]+=((39-m)*1.9);//dota niazeh -1
			M[4][2]=M[4][2+(m-39)];
			M[4][2+(m-39)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,2,39);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=422&&y>=348&&(M[4][3]==0)){//quad4
			if(x1==576&&y1!=348&&canmove(40,1,m)){
			y00[M[4+((m-40)/9)][3]-1]+=(((m-40)/9)*1.9);
			M[4][3]=M[4+((m-40)/9)][3];// ��� �� ��� ����
			M[4+((m-40)/9)][3]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,3,40);
			}
			else if(y1==348&&x1!=576&&canmove(40,2,m)){
			x00[M[4][3+(m-40)]-1]+=((40-m)*1.9);//dota niazeh -1
			M[4][3]=M[4][3+(m-40)];
			M[4][3+(m-40)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,3,40);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=422&&y>=348&&(M[4][4]==0)){//quad5
			if(x1==652&&y1!=348&&M[3+((m-32)/9)][4]==9&&canmove(41,1,m)){//alon king can enter 
			y00[M[4+((m-41)/9)][4]-1]+=(((m-41)/9)*1.9);
			M[4][4]=M[4+((m-41)/9)][4];// ��� �� ��� ����
			M[4+((m-41)/9)][4]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(4,4,41);
			}
			else if(y1==348&&x1!=652&&M[4][4+(m-41)]==9&&canmove(41,2,m)){
			x00[M[4][4+(m-41)]-1]+=((41-m)*1.9);//dota niazeh -1
			M[4][4]=M[4][4+(m-41)];
			M[4][4+(m-41)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(4,4,41);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=422&&y>=348&&(M[4][5]==0)){//quad6
			if(x1==728&&y1!=348&&canmove(42,1,m)){
			y00[M[4+((m-42)/9)][5]-1]+=(((m-42)/9)*1.9);
			M[4][5]=M[4+((m-42)/9)][5];// ��� �� ��� ����
			M[4+((m-42)/9)][5]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,5,42);
			}
			else if(y1==348&&x1!=728&&canmove(42,2,m)){
			x00[M[4][5+(m-42)]-1]+=((42-m)*1.9);//dota niazeh -1
			M[4][5]=M[4][5+(m-42)];
			M[4][5+(m-42)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,5,42);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=422&&y>=348&&(M[4][6]==0)){//quad7
			if(x1==804&&y1!=348&&canmove(43,1,m)){
			y00[M[4+((m-43)/9)][6]-1]+=(((m-43)/9)*1.9);
			M[4][6]=M[4+((m-43)/9)][6];// ��� �� ��� ����
			M[4+((m-43)/9)][6]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,6,43);
			}
			else if(y1==348&&x1!=804&&canmove(43,2,m)){
			x00[M[4][6+(m-43)]-1]+=((43-m)*1.9);//dota niazeh -1
			M[4][6]=M[4][6+(m-43)];
			M[4][6+(m-43)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,6,43);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=422&&y>=348&&(M[4][7]==0)){//quad8
			if(x1==880&&y1!=348&&canmove(44,1,m)){
			y00[M[4+((m-44)/9)][7]-1]+=(((m-44)/9)*1.9);
			M[4][7]=M[4+((m-44)/9)][7];// ��� �� ��� ����
			M[4+((m-44)/9)][7]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,7,44);
			}
			else if(y1==348&&x1!=880&&canmove(44,2,m)){
			x00[M[4][7+(m-44)]-1]+=((44-m)*1.9);//dota niazeh -1
			M[4][7]=M[4][7+(m-44)];
			M[4][7+(m-44)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,7,44);
			}
		}
			if(s==GLUT_DOWN  &&y<=422&&y>=348&&x<=1030&&x>=956&&(M[4][8]==0)){//quad9
			if(x1==956&&y1!=348&&canmove(45,1,m)){
			y00[M[4+((m-45)/9)][8]-1]+=(((m-45)/9)*1.9);
			M[4][8]=M[4+((m-45)/9)][8];// ��� �� ��� ����
			M[4+((m-45)/9)][8]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,8,45);
			}
			else if(y1==348&&x1!=956&&canmove(45,2,m)){
			x00[M[4][8+(m-45)]-1]+=((45-m)*1.9);//dota niazeh -1
			M[4][8]=M[4][8+(m-45)];
			M[4][8+(m-45)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(4,8,45);
			}
		}
			//rawsix
			if(s==GLUT_DOWN &&y<=498&&y>=424&&x<=422&&x>=348&&(M[5][0]==0)){//quad1
			if(x1==348&&y1!=424&&canmove(46,1,m)){
			y00[M[5+((m-46)/9)][0]-1]+=(((m-46)/9)*1.9);
			M[5][0]=M[5+((m-46)/9)][0];// ��� �� ��� ����
			M[5+((m-46)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;	
			hitt(5,0,46);
			}
			else if(y1==424&&x1!=348&&canmove(46,2,m)){
			x00[M[5][0+(m-46)]-1]+=((46-m)*1.9);//dota niazeh -1
			M[5][0]=M[5][0+(m-46)];
			M[5][0+(m-46)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,0,46);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424  &&y<=498&&y>=424&&(M[5][1]==0)){//quad2
			if(x1==424&&y1!=424&&canmove(47,1,m)){
			y00[M[5+((m-47)/9)][1]-1]+=(((m-47)/9)*1.9);
			M[5][1]=M[5+((m-47)/9)][1];// ��� �� ��� ����
			M[5+((m-47)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,1,47);
			}
			else if(y1==424&&x1!=424&&canmove(47,2,m)){
			x00[M[5][1+(m-47)]-1]+=((47-m)*1.9);//dota niazeh -1
			M[5][1]=M[5][1+(m-47)];
			M[5][1+(m-47)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,1,47);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500  &&y<=498&&y>=424&&(M[5][2]==0)){//quad3
			if(x1==500&&y1!=424&&canmove(48,1,m)){
			y00[M[5+((m-48)/9)][2]-1]+=(((m-48)/9)*1.9);
			M[5][2]=M[5+((m-48)/9)][2];// ��� �� ��� ����
			M[5+((m-48)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,2,48);
			}
			else if(y1==424&&x1!=500&&canmove(48,2,m)){
			x00[M[5][2+(m-48)]-1]+=((48-m)*1.9);//dota niazeh -1
			M[5][2]=M[5][2+(m-48)];
			M[5][2+(m-48)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,2,48);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=498&&y>=424&&(M[5][3]==0)){//quad4
			if(x1==576&&y1!=424&&canmove(49,1,m)){
			y00[M[5+((m-49)/9)][3]-1]+=(((m-49)/9)*1.9);
			M[5][3]=M[5+((m-49)/9)][3];// ��� �� ��� ����
			M[5+((m-49)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,3,49);
			}
			else if(y1==424&&x1!=576&&canmove(49,2,m)){
			x00[M[5][3+(m-49)]-1]+=((49-m)*1.9);//dota niazeh -1
			M[5][3]=M[5][3+(m-49)];
			M[5][3+(m-49)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,3,49);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=498&&y>=424&&(M[5][4]==0)){//quad5
			if(x1==652&&y1!=424&&canmove(50,1,m)){
			y00[M[5+((m-50)/9)][4]-1]+=(((m-50)/9)*1.9);
			M[5][4]=M[5+((m-50)/9)][4];// ��� �� ��� ����
			M[5+((m-50)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(5,4,50);
			}
			else if(y1==424&&x1!=652&&canmove(50,2,m)){
			x00[M[5][4+(m-50)]-1]+=((50-m)*1.9);//dota niazeh -1
			M[5][4]=M[5][4+(m-50)];
			M[5][4+(m-50)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(5,4,50);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=498&&y>=424&&(M[5][5]==0)){//quad6
			if(x1==728&&y1!=424&&canmove(51,1,m)){
			y00[M[5+((m-51)/9)][5]-1]+=(((m-51)/9)*1.9);
			M[5][5]=M[5+((m-51)/9)][5];// ��� �� ��� ����
			M[5+((m-51)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,5,51);
			}
			else if(y1==424&&x1!=728&&canmove(51,2,m)){
			x00[M[5][5+(m-51)]-1]+=((51-m)*1.9);//dota niazeh -1
			M[5][5]=M[5][5+(m-51)];
			M[5][5+(m-51)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,5,51);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=498&&y>=424&&(M[5][6]==0)){//quad7
			if(x1==804&&y1!=424&&canmove(52,1,m)){
			y00[M[5+((m-52)/9)][6]-1]+=(((m-52)/9)*1.9);
			M[5][6]=M[5+((m-52)/9)][6];// ��� �� ��� ����
			M[5+((m-52)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,6,52);
			}
			else if(y1==424&&x1!=804&&canmove(52,2,m)){
			x00[M[5][6+(m-52)]-1]+=((52-m)*1.9);//dota niazeh -1
			M[5][6]=M[5][6+(m-52)];
			M[5][6+(m-52)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,6,52);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=498&&y>=424&&(M[5][7]==0)){//quad8
			if(x1==880&&y1!=424&&canmove(53,1,m)){
			y00[M[5+((m-53)/9)][7]-1]+=(((m-53)/9)*1.9);
			M[5][7]=M[5+((m-53)/9)][7];// ��� �� ��� ����
			M[5+((m-53)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,7,53);
			}
			else if(y1==424&&x1!=880&&canmove(53,2,m)){
			x00[M[5][7+(m-53)]-1]+=((53-m)*1.9);//dota niazeh -1
			M[5][7]=M[5][7+(m-53)];
			M[5][7+(m-53)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,7,53);
			}
		}
			if(s==GLUT_DOWN &&y<=498&&y>=424&&x<=1030&&x>=956&&(M[5][8]==0)){//quad9
			if(x1==956&&y1!=424&&canmove(54,1,m)){
			y00[M[5+((m-54)/9)][8]-1]+=(((m-54)/9)*1.9);
			M[5][8]=M[5+((m-54)/9)][8];// ��� �� ��� ����
			M[5+((m-54)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,8,54);
			}
			else if(y1==424&&x1!=956&&canmove(54,2,m)){
			x00[M[5][8+(m-54)]-1]+=((54-m)*1.9);//dota niazeh -1
			M[5][8]=M[5][8+(m-54)];
			M[5][8+(m-54)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(5,8,54);
			}
		}
			//rawseven
			if(s==GLUT_DOWN &&y<=574&&y>=500&&x<=422&&x>=348&&(M[6][0]==0)){//quad1
			if(x1==348&&y1!=500&&canmove(55,1,m)){
			y00[M[6+((m-55)/9)][0]-1]+=(((m-55)/9)*1.9);
			M[6][0]=M[6+((m-55)/9)][0];// ��� �� ��� ����
			M[6+((m-55)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,0,55);
			}
			else if(y1==500&&x1!=348&&canmove(55,2,m)){
			x00[M[6][0+(m-55)]-1]+=((55-m)*1.9);//dota niazeh -1
			M[6][0]=M[6][0+(m-55)];
			M[6][0+(m-55)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,0,55);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=574&&y>=500&&(M[6][1]==0)){//quad2
			if(x1==424&&y1!=500&&canmove(56,1,m)){
			y00[M[6+((m-56)/9)][1]-1]+=(((m-56)/9)*1.9);
			M[6][1]=M[6+((m-56)/9)][1];// ��� �� ��� ����
			M[6+((m-56)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,1,56);
			}
			else if(y1==500&&x1!=424&&canmove(56,2,m)){
			x00[M[6][1+(m-56)]-1]+=((56-m)*1.9);//dota niazeh -1
			M[6][1]=M[6][1+(m-56)];
			M[6][1+(m-56)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,1,56);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500 &&y<=574&&y>=500&&(M[6][2]==0)){//quad3
			if(x1==500&&y1!=500&&canmove(57,1,m)){
			y00[M[6+((m-57)/9)][2]-1]+=(((m-57)/9)*1.9);
			M[6][2]=M[6+((m-57)/9)][2];// ��� �� ��� ����
			M[6+((m-57)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,2,57);
			}
			else if(y1==500&&x1!=500&&canmove(57,2,m)){
			x00[M[6][2+(m-57)]-1]+=((57-m)*1.9);//dota niazeh -1
			M[6][2]=M[6][2+(m-57)];
			M[6][2+(m-57)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,2,57);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=574&&y>=500&&(M[6][3]==0)){//quad4
			if(x1==576&&y1!=500&&canmove(58,1,m)){
			y00[M[6+((m-58)/9)][3]-1]+=(((m-58)/9)*1.9);
			M[6][3]=M[6+((m-58)/9)][3];// ��� �� ��� ����
			M[6+((m-58)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,3,58);
			}
			else if(y1==500&&x1!=576&&canmove(58,2,m)){
			x00[M[6][3+(m-58)]-1]+=((58-m)*1.9);//dota niazeh -1
			M[6][3]=M[6][3+(m-58)];
			M[6][3+(m-58)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,3,58);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=574&&y>=500&&(M[6][4]==0)){//quad5
			if(x1==652&&y1!=500&&canmove(59,1,m)){
			y00[M[6+((m-59)/9)][4]-1]+=(((m-59)/9)*1.9);
			M[6][4]=M[6+((m-59)/9)][4];// ��� �� ��� ����
			M[6+((m-59)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(6,4,59);
			}
			else if(y1==500&&x1!=652&&canmove(59,2,m)){
			x00[M[6][4+(m-59)]-1]+=((59-m)*1.9);//dota niazeh -1
			M[6][4]=M[6][4+(m-59)];
			M[6][4+(m-59)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(6,4,59);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=574&&y>=500&&(M[6][5]==0)){//quad6
			if(x1==728&&y1!=500&&canmove(60,1,m)){
			y00[M[6+((m-60)/9)][5]-1]+=(((m-60)/9)*1.9);
			M[6][5]=M[6+((m-60)/9)][5];// ��� �� ��� ����
			M[6+((m-60)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,5,60);
			}
			else if(y1==500&&x1!=728&&canmove(60,2,m)){
			x00[M[6][5+(m-60)]-1]+=((60-m)*1.9);//dota niazeh -1
			M[6][5]=M[6][5+(m-60)];
			M[6][5+(m-60)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,5,60);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=574&&y>=500&&(M[6][6]==0)){//quad7
			if(x1==804&&y1!=500&&canmove(61,1,m)){
			y00[M[6+((m-61)/9)][6]-1]+=(((m-61)/9)*1.9);
			M[6][6]=M[6+((m-61)/9)][6];// ��� �� ��� ����
			M[6+((m-61)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,6,61);
			}
			else if(y1==500&&x1!=804&&canmove(61,2,m)){
			x00[M[6][6+(m-61)]-1]+=((61-m)*1.9);//dota niazeh -1
			M[6][6]=M[6][6+(m-61)];
			M[6][6+(m-61)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,6,61);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=574&&y>=500&&(M[6][7]==0)){//quad8
			if(x1==880&&y1!=500&&canmove(62,1,m)){
			y00[M[6+((m-62)/9)][7]-1]+=(((m-62)/9)*1.9);
			M[6][7]=M[6+((m-62)/9)][7];// ��� �� ��� ����
			M[6+((m-62)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,7,62);
			}
			else if(y1==500&&x1!=880&&canmove(62,2,m)){
			x00[M[6][7+(m-62)]-1]+=((62-m)*1.9);//dota niazeh -1
			M[6][7]=M[6][7+(m-62)];
			M[6][7+(m-62)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,7,62);
			}
		}
			if(s==GLUT_DOWN &&y<=574&&y>=500&&x<=1030&&x>=956&&(M[6][8]==0)){//quad9
			if(x1==956&&y1!=500&&canmove(63,1,m)){
			y00[M[6+((m-63)/9)][8]-1]+=(((m-63)/9)*1.9);
			M[6][8]=M[6+((m-63)/9)][8];// ��� �� ��� ����
			M[6+((m-63)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,8,63);
			}
			else if(y1==500&&x1!=956&&canmove(63,2,m)){
			x00[M[6][8+(m-63)]-1]+=((63-m)*1.9);//dota niazeh -1
			M[6][8]=M[6][8+(m-63)];
			M[6][8+(m-63)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(6,8,63);
			}
		}
			//raweight
			if(s==GLUT_DOWN &&y<=650&&y>=576&&x<=422&&x>=348&&(M[7][0]==0)){//quad1
			if(x1==348&&y1!=576&&canmove(64,1,m)){
			y00[M[7+((m-64)/9)][0]-1]+=(((m-64)/9)*1.9);
			M[7][0]=M[7+((m-64)/9)][0];// ��� �� ��� ����
			M[7+((m-64)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,0,64);
			}
			else if(y1==576&&x1!=348&&canmove(64,2,m)){
			x00[M[7][0+(m-64)]-1]+=((64-m)*1.9);//dota niazeh -1
			M[7][0]=M[7][0+(m-64)];
			M[7][0+(m-64)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,0,64);
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=650&&y>=576&&(M[7][1]==0)){//quad2
			if(x1==424&&y1!=576&&canmove(65,1,m)){
			y00[M[7+((m-65)/9)][1]-1]+=(((m-65)/9)*1.9);
			M[7][1]=M[7+((m-65)/9)][1];// ��� �� ��� ����
			M[7+((m-65)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,1,65);
			}
			else if(y1==576&&x1!=424&&canmove(65,2,m)){
			x00[M[7][1+(m-65)]-1]+=((65-m)*1.9);//dota niazeh -1
			M[7][1]=M[7][1+(m-65)];
			M[7][1+(m-65)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,1,65);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500 &&y<=650&&y>=576&&(M[7][2]==0)){//quad3
			if(x1==500&&y1!=576&&canmove(66,1,m)){
			y00[M[7+((m-66)/9)][2]-1]+=(((m-66)/9)*1.9);
			M[7][2]=M[7+((m-66)/9)][2];// ��� �� ��� ����
			M[7+((m-66)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,2,66);
			}
			else if(y1==576&&x1!=500&&canmove(66,2,m)){
			x00[M[7][2+(m-66)]-1]+=((66-m)*1.9);//dota niazeh -1
			M[7][2]=M[7][2+(m-66)];
			M[7][2+(m-66)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,2,66);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=650&&y>=576&&(M[7][3]==0)){//quad4
			if(x1==576&&y1!=576&&canmove(67,1,m)){
			y00[M[7+((m-67)/9)][3]-1]+=(((m-67)/9)*1.9);
			M[7][3]=M[7+((m-67)/9)][3];// ��� �� ��� ����
			M[7+((m-67)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,3,67);
			}
			else if(y1==576&&x1!=576&&canmove(67,2,m)){
			x00[M[7][3+(m-67)]-1]+=((67-m)*1.9);//dota niazeh -1
			M[7][3]=M[7][3+(m-67)];
			M[7][3+(m-67)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,3,67);
			}
		}
			if(s==GLUT_DOWN  &&x<=726&&x>=652  &&y<=650&&y>=576&&(M[7][4]==0)){//quad5
			if(x1==652&&y1!=576&&canmove(68,1,m)){
			y00[M[7+((m-68)/9)][4]-1]+=(((m-68)/9)*1.9);
			M[7][4]=M[7+((m-68)/9)][4];// ��� �� ��� ����
			M[7+((m-68)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(7,4,68);
			}
			else if(y1==576&&x1!=652&&canmove(68,2,m)){
			x00[M[7][4+(m-68)]-1]+=((68-m)*1.9);//dota niazeh -1
			M[7][4]=M[7][4+(m-68)];
			M[7][4+(m-68)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(7,4,68);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=650&&y>=576&&(M[7][5]==0)){//quad6
			if(x1==728&&y1!=576&&canmove(69,1,m)){
			y00[M[7+((m-69)/9)][5]-1]+=(((m-69)/9)*1.9);
			M[7][5]=M[7+((m-69)/9)][5];// ��� �� ��� ����
			M[7+((m-69)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,5,69);
			}
			else if(y1==576&&x1!=728&&canmove(69,2,m)){
			x00[M[7][5+(m-69)]-1]+=((69-m)*1.9);//dota niazeh -1
			M[7][5]=M[7][5+(m-69)];
			M[7][5+(m-69)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,5,69);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=650&&y>=576&&(M[7][6]==0)){//quad7
			if(x1==804&&y1!=576&&canmove(70,1,m)){
			y00[M[7+((m-70)/9)][6]-1]+=(((m-70)/9)*1.9);
			M[7][6]=M[7+((m-70)/9)][6];// ��� �� ��� ����
			M[7+((m-70)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,6,70);
			}
			else if(y1==576&&x1!=804&&canmove(70,2,m)){
			x00[M[7][6+(m-70)]-1]+=((70-m)*1.9);//dota niazeh -1
			M[7][6]=M[7][6+(m-70)];
			M[7][6+(m-70)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,6,70);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=650&&y>=576&&(M[7][7]==0)){//quad8
			if(x1==880&&y1!=576&&canmove(71,1,m)){
			y00[M[7+((m-71)/9)][7]-1]+=(((m-71)/9)*1.9);
			M[7][7]=M[7+((m-71)/9)][7];// ��� �� ��� ����
			M[7+((m-71)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,7,71);
			}
			else if(y1==576&&x1!=880&&canmove(71,2,m)){
			x00[M[7][7+(m-71)]-1]+=((71-m)*1.9);//dota niazeh -1
			M[7][7]=M[7][7+(m-71)];
			M[7][7+(m-71)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,7,71);
			}
		}
			if(s==GLUT_DOWN &&y<=650&&y>=576&&x<=1030&&x>=956&&(M[7][8]==0)){//quad9
			if(x1==956&&y1!=576&&canmove(72,1,m)){
			y00[M[7+((m-72)/9)][8]-1]+=(((m-72)/9)*1.9);
			M[7][8]=M[7+((m-72)/9)][8];// ��� �� ��� ����
			M[7+((m-72)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,8,72);
			}
			else if(y1==576&&x1!=956&&canmove(72,2,m)){
			x00[M[7][8+(m-72)]-1]+=((72-m)*1.9);//dota niazeh -1
			M[7][8]=M[7][8+(m-72)];
			M[7][8+(m-72)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(7,8,72);
			}
		}
			//rawnine
			if(s==GLUT_DOWN &&x<=422&&x>=348 &&y<=726&&y>=652){//quad1
			if(x1==348&&y1!=652&&M[8+((m-73)/9)][0]==9&&canmove(73,1,m)){
			y00[M[8+((m-73)/9)][0]-1]+=(((m-73)/9)*1.9);
			M[8][0]=M[8+((m-73)/9)][0];// ��� �� ��� ����
			M[8+((m-73)/9)][0]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[63][0]=.3;V[63][1]=.8;V[63][2]=.3;
			V[73][0]=.3;V[73][1]=.8;V[73][2]=.3;
			flag=4;//etmam bazi			
			}
			else if(y1==652&&x1!=348&&M[8][0+(m-73)]==9&&canmove(73,2,m)){
			x00[M[8][0+(m-73)]-1]+=((73-m)*1.9);//dota niazeh -1
			M[8][0]=M[8][0+(m-73)];
			M[8][0+(m-73)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[63][0]=.3;V[63][1]=.8;V[63][2]=.3;
			V[73][0]=.3;V[73][1]=.8;V[73][2]=.3;
			flag=4;//etmam bazi			
			}
		}
			if(s==GLUT_DOWN &&x<=498&&x>=424 &&y<=726&&y>=652&&(M[8][1]==0)){//quad2
			if(x1==424&&y1!=652&&canmove(74,1,m)){
			y00[M[8+((m-74)/9)][1]-1]+=(((m-74)/9)*1.9);
			M[8][1]=M[8+((m-74)/9)][1];// ��� �� ��� ����
			M[8+((m-74)/9)][1]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,1,74);
			}
			else if(y1==652&&x1!=424&&canmove(74,2,m)){
			x00[M[8][1+(m-74)]-1]+=((74-m)*1.9);//dota niazeh -1
			M[8][1]=M[8][1+(m-74)];
			M[8][1+(m-74)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,1,74);
			}
		}
			if(s==GLUT_DOWN &&x<=574&&x>=500 &&y<=726&&y>=652&&(M[8][2]==0)){//quad3
			if(x1==500&&y1!=652&&canmove(75,1,m)){
			y00[M[8+((m-75)/9)][2]-1]+=(((m-75)/9)*1.9);
			M[8][2]=M[8+((m-75)/9)][2];// ��� �� ��� ����
			M[8+((m-75)/9)][2]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,2,75);
			}
			else if(y1==652&&x1!=500&&canmove(75,2,m)){
			x00[M[8][2+(m-75)]-1]+=((75-m)*1.9);//dota niazeh -1
			M[8][2]=M[8][2+(m-75)];
			M[8][2+(m-75)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,2,75);
			}
		}
			if(s==GLUT_DOWN &&x<=650&&x>=576  &&y<=726&&y>=652&&(M[8][3]==0)){//quad4
			if(x1==576&&y1!=652&&canmove(76,1,m)){
			y00[M[8+((m-76)/9)][3]-1]+=(((m-76)/9)*1.9);
			M[8][3]=M[8+((m-76)/9)][3];//M[7+((m-76)/9)][3] to M[8+((m-76)/9)][3]// ��� �� ��� ����
			M[8+((m-76)/9)][3]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,3,76);
			}
			else if(y1==652&&x1!=576&&canmove(76,2,m)){
			x00[M[8][3+(m-76)]-1]+=((76-m)*1.9);//dota niazeh -1
			M[8][3]=M[8][3+(m-76)];
			M[8][3+(m-76)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,3,76);
			}
		}
			if(s==GLUT_DOWN &&x<=726&&x>=652  &&y<=726&&y>=652&&(M[8][4]==0)){//quad5
			if(x1==652&&y1!=652&&canmove(77,1,m)){
			y00[M[8+((m-77)/9)][4]-1]+=(((m-77)/9)*1.9);
			M[8][4]=M[8+((m-77)/9)][4];// ��� �� ��� ����
			M[8+((m-77)/9)][4]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(8,4,77);
			}
			else if(y1==652&&x1!=652&&canmove(77,2,m)){
			x00[M[8][4+(m-77)]-1]+=((77-m)*1.9);//dota niazeh -1
			M[8][4]=M[8][4+(m-77)];
			M[8][4+(m-77)]=0;
			if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			flag=2;
			hitt(8,4,77);
			}
		}
			if(s==GLUT_DOWN &&x<=802&&x>=728  &&y<=726&&y>=652&&(M[8][5]==0)){//quad6
			if(x1==728&&y1!=652&&canmove(78,1,m)){
			y00[M[8+((m-78)/9)][5]-1]+=(((m-78)/9)*1.9);
			M[8][5]=M[8+((m-78)/9)][5];// ��� �� ��� ����
			M[8+((m-78)/9)][5]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,5,78);
			}
			else if(y1==652&&x1!=728&&canmove(78,2,m)){
			x00[M[8][5+(m-78)]-1]+=((78-m)*1.9);//dota niazeh -1
			M[8][5]=M[8][5+(m-78)];
			M[8][5+(m-78)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,5,78);
			}
		}
			if(s==GLUT_DOWN &&x<=878&&x>=804  &&y<=726&&y>=652&&(M[8][6]==0)){//quad7
			if(x1==804&&y1!=652&&canmove(79,1,m)){
			y00[M[8+((m-79)/9)][6]-1]+=(((m-79)/9)*1.9);
			M[8][6]=M[8+((m-79)/9)][6];// ��� �� ��� ����
			M[8+((m-79)/9)][6]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,6,79);
			}
			else if(y1==652&&x1!=804&&canmove(79,2,m)){
			x00[M[8][6+(m-79)]-1]+=((79-m)*1.9);//dota niazeh -1
			M[8][6]=M[8][6+(m-79)];
			M[8][6+(m-79)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,6,79);
			}
		}
			if(s==GLUT_DOWN &&x<=954&&x>=880  &&y<=726&&y>=652&&(M[8][7]==0)){//quad8
			if(x1==880&&y1!=652&&canmove(80,1,m)){
			y00[M[8+((m-80)/9)][7]-1]+=(((m-80)/9)*1.9);
			M[8][7]=M[8+((m-80)/9)][7];// ��� �� ��� ����
			M[8+((m-80)/9)][7]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,7,80);
			}
			else if(y1==652&&x1!=880&&canmove(80,2,m)){
			x00[M[8][7+(m-80)]-1]+=((80-m)*1.9);//dota niazeh -1
			M[8][7]=M[8][7+(m-80)];
			M[8][7+(m-80)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			flag=2;
			hitt(8,7,80);
			}
		}
			if(s==GLUT_DOWN &&x<=1030&&x>=956  &&y<=726&&y>=652){//quad9;
			if(x1==956&&y1!=652&&M[8+((m-81)/9)][8]==9&&canmove(81,1,m)){
			y00[M[8+((m-81)/9)][8]-1]+=(((m-81)/9)*1.9);
			M[8][8]=M[8+((m-81)/9)][8];// ��� �� ��� ����
			M[8+((m-81)/9)][8]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[71][0]=.3;V[71][1]=.8;V[71][2]=.3;
			V[79][0]=.3;V[79][1]=.8;V[79][2]=.3;
			flag=4;//etmam bazi			
			}
			else if(y1==652&&x1!=956&&M[8][8+(m-81)]==9&&canmove(81,2,m)){
			x00[M[8][8+(m-81)]-1]+=((81-m)*1.9);//dota niazeh -1
			M[8][8]=M[8][8+(m-81)];
			M[8][8+(m-81)]=0;
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			V[71][0]=.3;V[71][1]=.8;V[71][2]=.3;
			V[79][0]=.3;V[79][1]=.8;V[79][2]=.3;
			flag=4;//etmam bazi			
			}
		}
			//if(flag==2)
			//flag=0;
		}
		break;
	default:
		break;
	}//switch end
	//}// nobat1 end
	//if(flag==3 &&b==GLUT_LEFT&&s==GLUT_UP)
	//	cpu_inteligence();
glutPostRedisplay();
if(b==GLUT_LEFT&&s==GLUT_UP){
	cout<<m<<endl;
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++)
		cout<<M[i][j]<<" ";
cout<<endl;
}
cout<<endl;
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++)
		cout<<LM[i][j]<<" ";
cout<<endl;
}
cout<<endl;
for(int i=0;i<9;i++){
	for(int j=0;j<9;j++)
		cout<<LM2[i][j]<<" ";
cout<<endl;
}

}
cout<<endl;
if(b==GLUT_RIGHT_BUTTON&&s==GLUT_DOWN){
if(m==41){
			V[m-1][0]=1;
			V[m-1][1]=.900;
			V[m-1][2]=.011;
			}
			else{
			V[m-1][0]=.685;
			V[m-1][1]=.400;
			V[m-1][2]=.018;
			}
			if (flag==1)
				flag=0;
}
//cout<<x<<endl;
//cout<<y<<endl;
}
void mainmenu(int i){
	switch (i)
	{
	case 0:
		
			for(int k=0;k<=8;k++){
		    x00[k]=0;
            y00[k]=0;
			}
		  for(int k=0;k<=15;k++){
         x11[k]=0;
        y11[k]=0;
		  }
       flag=2;//for click &nobatdehi
     c=0;//counter for cpu inteligence
    p1=-1,p2=-1,p3=-1,p4=-1;//for hitt animated
     p5=-1;//for begin hit animated

        V[0][0]=1.00;
		V[0][1]=.900;	
		V[0][2]=.011;
		V[8][0]=1.00;
		V[8][1]=.900;	
		V[8][2]=.011;
		V[40][0]=1.00;
		V[40][1]=.900;	
		V[40][2]=.011;
		V[72][0]=1.00;
		V[72][1]=.900;	
		V[72][2]=.011;
		V[80][0]=1.00;
		V[80][1]=.900;	
		V[80][2]=.011;
		for(int k=1;k<=7;k++){
		V[k][0]=.685;
		V[k][1]=.400;	
		V[k][2]=.018;
		}
		for(int k=9;k<=39;k++){
		V[k][0]=.685;
		V[k][1]=.400;	
		V[k][2]=.018;
		}
		for(int k=41;k<=71;k++){
		V[k][0]=.685;
		V[k][1]=.400;	
		V[k][2]=.018;
		}
		for(int k=73;k<=79;k++){
		V[k][0]=.685;
		V[k][1]=.400;	
		V[k][2]=.018;
		}

 M[0][0]=10;
 M[0][8]=10;
 M[8][0]=10;
 M[8][8]=10;
 for(int k=1;k<=7;k++){
	 int j=0;
  
  if(k==3)
	  j=-5;
  if(k==4)
	  j=-6;
  if(k==5)
	  j=-7;
 M[0][k]=j;
 }
 for(int k=0;k<=8;k++){
	 int j=0;
  if(k==4)
	  j=-8;
 M[1][k]=j;
 }
  for(int k=0;k<=8;k++){
	 int j=0;
  if(k==4)
	  j=3;
 M[2][k]=j;
 }
    for(int k=0;k<=8;k++){
	 int j=0;
  if(k==0)
	  j=-3;
  if(k==4)
	  j=4;
   if(k==8)
	  j=-9;
 M[3][k]=j;
 }
	    for(int k=0;k<=8;k++){
	 int j=0;
  if(k==0)
	  j=-2;
  if(k==1)
	  j=-4;
   if(k==2)
	  j=1;
    if(k==3)
	  j=2;
  if(k==4)
	  j=9;
   if(k==5)
	  j=6;
    if(k==6)
	  j=5;
	if(k==7)
	  j=-12;
    if(k==8)
	  j=-10;
 M[4][k]=j;
 }
	 for(int k=0;k<=8;k++){
	 int j=0;
  if(k==0)
	  j=-1;
  if(k==4)
	  j=8;
   if(k==8)
	  j=-11;
 M[5][k]=j;
 }
	 for(int k=0;k<=8;k++){
	 int j=0;

  if(k==4)
	  j=7;

 M[6][k]=j;
 }
	 for(int k=0;k<=8;k++){
	 int j=0;

  if(k==4)
	  j=-16;

 M[7][k]=j;
 }
for(int k=1;k<=7;k++){
	 int j=0;
  
  if(k==3)
	  j=-15;
  if(k==4)
	  j=-14;
  if(k==5)
	  j=-13;
 M[8][k]=j;
 }
////------
LM[0][0]=10;
 LM[0][8]=10;
 LM[8][0]=10;
 LM[8][8]=10;
 for(int k=1;k<=7;k++){
	 int j=0;
  
  if(k==3)
	  j=-5;
  if(k==4)
	  j=-6;
  if(k==5)
	  j=-7;
 LM[0][k]=j;
 }
 for(int k=0;k<=8;k++){
	 int j=0;
  if(k==4)
	  j=-8;
 LM[1][k]=j;
 }
  for(int k=0;k<=8;k++){
	 int j=0;
  if(k==4)
	  j=3;
 LM[2][k]=j;
 }
    for(int k=0;k<=8;k++){
	 int j=0;
  if(k==0)
	  j=-3;
  if(k==4)
	  j=4;
   if(k==8)
	  j=-9;
 LM[3][k]=j;
 }
	    for(int k=0;k<=8;k++){
	 int j=0;
  if(k==0)
	  j=-2;
  if(k==1)
	  j=-4;
   if(k==2)
	  j=1;
    if(k==3)
	  j=2;
  if(k==4)
	  j=9;
   if(k==5)
	  j=6;
    if(k==6)
	  j=5;
	if(k==7)
	  j=-12;
    if(k==8)
	  j=-10;
 LM[4][k]=j;
 }
	 for(int k=0;k<=8;k++){
	 int j=0;
  if(k==0)
	  j=-1;
  if(k==4)
	  j=8;
   if(k==8)
	  j=-11;
 LM[5][k]=j;
 }
	 for(int k=0;k<=8;k++){
	 int j=0;

  if(k==4)
	  j=7;

 LM[6][k]=j;
 }
	 for(int k=0;k<=8;k++){
	 int j=0;

  if(k==4)
	  j=-16;

 LM[7][k]=j;
 }
for(int k=1;k<=7;k++){
	 int j=0;
  
  if(k==3)
	  j=-15;
  if(k==4)
	  j=-14;
  if(k==5)
	  j=-13;
 LM[8][k]=j;
 }
for(int j=0;j<=8;j++)
	for(int k=0;k<=8;k++)
   LM2[j][k]=0;
    g=0;
		glutTimerFunc(1000, Timer_A,1);//Timer_A(1);
		
		break;
	case 1:
		exit(0);
	default:
		break;
	}


}
void menu(){
glutCreateMenu(mainmenu);
glutAddMenuEntry("Replay",0);
glutAddMenuEntry("Quite",1);
glutAttachMenu(GLUT_MIDDLE_BUTTON);
}
int main(int argc, char** argv)
{   
	glutTimerFunc(1000, Timer_A,1);//Timer_A(1);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,800);
	glutCreateWindow("vchess"); 
	glutDisplayFunc(mydisplay);
	glutReshapeFunc(resize);
	Initialize();
	glutMouseFunc(m);
	menu(); 
	//glutFullScreen();
	glutMainLoop();
	return 0;	
}
 