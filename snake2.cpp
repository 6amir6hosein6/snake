#include <iostream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct posi{
	int x;int y;
}arr[200];
void cp(int x, int y) {
  HANDLE hStdout;
  CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
  csbiInfo.dwCursorPosition.X=x;
  csbiInfo.dwCursorPosition.Y=y;
  SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}
typedef struct posi pos;
void welcome(){
	cout<<endl;
	cout<<"  W";
	Sleep(200);
	cout<<"E";
	Sleep(200);
	cout<<"L";
	Sleep(200);
	cout<<"C";
	Sleep(200);
	cout<<"O";
	Sleep(200);
	cout<<"M";
	Sleep(200);
	cout<<"E";
	Sleep(200);
	cout<<"!";
	Sleep(200);
	cout<<"!";
	Sleep(200);
	cout<<"!";
	Sleep(200);
}
void saved(int score){time_t t = time(0);   
    struct tm * now = localtime( & t );
	string name;
	cout<<"\n  Enter your name : ";
	cin>>name;
	ofstream outClientFile("save.txt",ios::app);
	outClientFile<<name<<"            "<<score<<"                       "<<(now->tm_year + 1900)<<"-"<<(now->tm_mon + 1) <<"-"<<now->tm_mday<<endl;
	cout<<endl<<"\n  ***your game saved***\n";
}
void draw(char s[25][30] ,int score){
	int x,y=1,i,j;
	for(i=0;i<25;i++){
		s[i][0]='#';
	}
	for(j=1;j<30;j++){
		s[0][j]='#';
	}
	for(i=1;i<25;i++){
		s[i][29]='#';
	}
	for(j=1;j<29;j++){
		s[24][j]='#';
	}
	for(i=0;i<25;i++){
		for(j=0;j<30;j++){
			cout<<s[i][j];
		}
		cout<<endl;
	}
	cp(32,2);
    cout<<"Score : "<<score;
    cp(32,5);
    cout<<"Press \'p\' to stop game ";
}
void move(char sn[25][30],int level){
	aa:
	int key ;
	int a=12,b=16,move,zz=3,k=4,score=0,asd=0,amirhosein1=0;
	int p=0;
	arr[0].x=a,arr[0].y=b;
	char snake[100]={'+','*','*','*'};
	sn[b][a]=snake[0];
	sn[b+1][a]=snake[1];
	arr[1].x=a,arr[1].y=b+1;
	sn[b+2][a]=snake[2];
	arr[2].x=a,arr[2].y=b+2;
	sn[b+3][a]=snake[3];
	arr[3].x=a,arr[3].y=b+3;
        	system("CLS");
            draw(sn,score);
	    	start:
	       	srand((unsigned)time(0)); 
            int i = (rand()%25)+2; 
    		int j = (rand()%20)+2;
            for(int asd=0;asd<100;asd++){
            	if(i==arr[asd].x&&j==arr[asd].y)
            	goto start;
			}
			sn[j][i]='@';
            p:
            system("CLS");
            draw(sn,score);
            if(key=='a')
            goto a;
            else if(key=='w')
            goto w;
            else if(key=='s')
            goto s;
            else if(key=='d')
            goto d;
            stop:
            if(amirhosein1==0){
            	goto amirhosein;
            	amirhosein1++;	
			}
	while(1<2){
		amirhosein:
		move=getch();
		if(move==119){
			w:
			while(1){
				if (_kbhit()){
      				key =_getch();
					 	if (key == 'a')
        			     goto a;
        			    else if (key == 'd')
        			     goto d;
        			     else if (key =='p'){
        			     	amirhosein1=0;
        			     	cp(13,12);
        			     	cout<<"PUASE";
        			     	goto stop;
						 }
        			     
    			}    
			sn[arr[0].y-1][arr[0].x]=snake[0];
			for(int ii=1;ii<=zz;ii++){
			sn[arr[ii-1].y][arr[ii-1].x]=snake[ii];
			}
			sn[arr[zz].y][arr[zz].x]=' ';
			for(int ii=zz;ii>=1;ii--){
			arr[ii].y=arr[ii-1].y;
			arr[ii].x=arr[ii-1].x;
			}
			(arr[0].y)=(arr[0].y)-1;
			system("CLS");
            draw(sn,score);
            if(arr[0].x==0){
            	arr[0].x=28;
            	goto p;
			}else if(arr[0].y==0){
				arr[0].y=23;
			}else if(arr[0].x==29){
				arr[0].x=1;
				goto p;
			}
			else if(arr[0].y==24){
				arr[0].y=1;
				goto p;
			}
			if(arr[0].x==i&&arr[0].y==j){
			score++;
			zz=zz+1;
			snake[k]='*';
			sn[arr[k-1].y+1][arr[k-1].x]=snake[k];
			arr[k].y=arr[k-1].y+1;
			arr[k].x=arr[k-1].x;
			k=k+1;
	     	system("CLS");
			goto start;
    	}  
    	for(int i=1;i<=zz;i++){
    		if(arr[0].x==arr[i].x&&arr[0].y==arr[i].y){
    			goto end;
			}
		}
			Sleep(level);
			
			}
		}else if(move==115){  
		s:  
			while(1){
				if (_kbhit()){
      				key =_getch();
					 	if (key == 'a')
        			     goto a;
        			    else if (key == 'd')
        			     goto d;
						 else if (key =='p'){
        			     	amirhosein1=0;
        			     	cp(13,12);
        			     	cout<<"PUASE";
        			     	goto stop;
						 }
						 }
	     	sn[arr[0].y+1][arr[0].x]=snake[0];
			for(int ii=1;ii<=zz;ii++){
			sn[arr[ii-1].y][arr[ii-1].x]=snake[ii];
			}
			sn[arr[zz].y][arr[zz].x]=' ';
			for(int ii=zz;ii>=1;ii--){
			arr[ii].y=arr[ii-1].y;
			arr[ii].x=arr[ii-1].x;
			}
			(arr[0].y)=(arr[0].y)+1;
			system("CLS");
            draw(sn,score);
            
           if(arr[0].x==0){
            	arr[0].x=28;
            	goto p;
			}else if(arr[0].y==0){
				arr[0].y=23;
				goto p;
			}else if(arr[0].x==29){
				arr[0].x=1;
				goto p;
			}
			else if(arr[0].y==24){
				arr[0].y=1;
				goto p;
			}
	    	if(arr[0].x==i&&arr[0].y==j){
			score++;
			zz=zz+1;
			snake[k]='*';
			sn[arr[k-1].y+1][arr[k-1].x]=snake[k];
			arr[k].y=arr[k-1].y+1;
			arr[k].x=arr[k-1].x;
			k=k+1;
	     	system("CLS");
			goto start;
    	}  
    	for(int i=1;i<=zz;i++){
    		if(arr[0].x==arr[i].x&&arr[0].y==arr[i].y){
    			goto end;
			}
		}
	    	Sleep(level);
		}}
		else if(move==100){
			d:
			while(1){
				if (_kbhit()){
      				key =_getch();
					 	if (key == 'w')
        			     goto w;
        			    else if (key == 's')
        			     goto s;
        			     else if (key =='p'){
        			     	amirhosein1=0;
        			     	cp(13,12);
        			     	cout<<"PUASE";
        			     	goto stop;
						 }
        			 }
	    	sn[arr[0].y][arr[0].x+1]=snake[0];
			for(int ii=1;ii<=zz;ii++){
			sn[arr[ii-1].y][arr[ii-1].x]=snake[ii];
			}
			sn[arr[zz].y][arr[zz].x]=' ';
			for(int ii=zz;ii>=1;ii--){
			arr[ii].y=arr[ii-1].y;
			arr[ii].x=arr[ii-1].x;
			}
			(arr[0].x)=(arr[0].x)+1;
			system("CLS");
            draw(sn,score);
            
            if(arr[0].x==0){
            	arr[0].x=28;
            	goto p;
			}else if(arr[0].y==0){
				arr[0].y=23;
				goto p;
			}else if(arr[0].x==29){
				arr[0].x=1;
				goto p;
			}
			else if(arr[0].y==24){
				arr[0].y=1;
				goto p;
			}
			if(arr[0].x==i&&arr[0].y==j){
			score++;
			zz=zz+1;
			snake[k]='*';
			sn[arr[k-1].y+1][arr[k-1].x]=snake[k];
			arr[k].y=arr[k-1].y+1;
			arr[k].x=arr[k-1].x;
			k=k+1;
	     	system("CLS");
			goto start;
    	}  
    	for(int i=1;i<=zz;i++){
    		if(arr[0].x==arr[i].x&&arr[0].y==arr[i].y){
    			goto end;
			}
		}
			Sleep(level);
		}}
		else if(move==97){
			a:
			while(1){
				if (_kbhit()){
      				key =_getch();
					 	if (key == 'w')
        			     goto w;
        			    else if (key == 's')
        			     goto s;
        			     else if (key =='p'){
        			     	amirhosein1=0;
        			     	cp(13,12);
        			     	cout<<"PUASE";
        			     	goto stop;
						 }
    			}    
            sn[arr[0].y][arr[0].x-1]=snake[0];
			for(int ii=1;ii<=zz;ii++){
			sn[arr[ii-1].y][arr[ii-1].x]=snake[ii];
			}
			sn[arr[zz].y][arr[zz].x]=' ';
			for(int ii=zz;ii>=1;ii--){
			arr[ii].y=arr[ii-1].y;
			arr[ii].x=arr[ii-1].x;
			}
			(arr[0].x)=(arr[0].x)-1;
			system("CLS");
            draw(sn,score);
            if(arr[0].x==0){
            	arr[0].x=28;
            	goto p;
			}else if(arr[0].y==0){
				arr[0].y=23;
				goto p;
			}else if(arr[0].x==29){
				arr[0].x=1;
				goto p;
			}
			else if(arr[0].y==24){
				arr[0].y=1;
				goto p;
			}
			if(arr[0].x==i&&arr[0].y==j){
			score++;
			zz=zz+1;
			snake[k]='*';
			sn[arr[k-1].y+1][arr[k-1].x]=snake[k];
			arr[k].y=arr[k-1].y+1;
			arr[k].x=arr[k-1].x;
			k=k+1;
	     	system("CLS");
			goto start;
    	}  
    	for(int i=1;i<=zz;i++){
    		if(arr[0].x==arr[i].x&&arr[0].y==arr[i].y){
    			goto end;
			}
		}
			Sleep(level);
		}}
	}
	end:
	system("CLS");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"          ***********\n";
	cout<<"          *Game Over*\n";
	cout<<"          ***********\n"<<endl;
	cout<<"        your score is : "<<score<<endl<<endl;
	cout<<"  Do You want to save your game ?  (y/n)"<<endl<<endl;
	int save;
	save=getch();
	if(save==121){
		system("CLS");
		saved(score);
		cout<<"\n   play again? (y/n) : ";
		int qs;
		qs=getch();
		if(qs==121){
			system("CLS");
			for(int i=1;i<24;i++)
			  for(int j=1;j<29;j++)
		   	  sn[i][j]=' ';
		   	  amirhosein1=0;
		goto aa;
		}
	}else{
		cout<<"\n   play again? (y/n) : ";
		int qs;
		qs=getch();
		if(qs==121){
			system("CLS");
			for(int i=1;i<24;i++)
			  for(int j=1;j<29;j++)
		   	  sn[i][j]=' ';
		   	  amirhosein1=0;
		goto aa;
		}
	}
}
int main(int argc, char** argv) {
	char s[25][30]={(' ',' ')};
	int level;
	welcome();
	m:
	cout<<endl<<endl<<endl;
	cout<<"             "<<"1 - Start Game"<<endl<<endl<<"             2 - Score";
	if(49==getch()){
		system("CLS");
		cout<<"    \n\nChoose The Herdness of your game  :  "<<endl<<endl;
		cout<<"             "<<"1 - Easy"<<endl<<endl<<"             2 - Medume"<<endl<<endl<<"             3 - Hard";
		level=getch();
		if(level=='1')
		move(s,500);
		if(level=='2')
		move(s,50);
		if(level=='3')
		move(s,1);	
	}else{
		system("Cls");
		ifstream inClientFile("save.txt",ios::app);
		  char str[80];
  
 			 while (!inClientFile.eof())
 			 {
  				  inClientFile.getline(str,81);
   				  cout << str << endl;
  			}
  			cout<<endl<<endl<<"     "<<"press any key to come back ...";
  			getch();
  			system("CLS");
  			goto m;
		}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	return 0;
}
