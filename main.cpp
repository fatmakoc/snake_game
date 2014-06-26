/*
	Author: Fatma Koç
	File: main.cpp
	Description: World's most prettiest Snake Game runnig on console. :)
*/

#include "stdafx.h"
#include "include.h"
#include "windows.h"


void yilanbaslangic(void);
void yilangoruntule(void);
void engelgoruntule(void);
void yilankontrol(void);
void ucluengel(void);
void yemolustur(void);
void yemgoster(void);
void yilankuyruksil(void);
void yilanyemyeme(void);
void yilankendinecarpma(void);
void yilanengelecarpma(void);
void yilankuyrukekle(void);
void yilanengelecarpma2(void);
void puan_topla(void);
void yem_sayi_kontrol(void);
void suregoster(void);
void puan_yaz();
void yilan_disari_cikma(void);
void puan_okuma(void);
void puan_siralama(void);
void puan_kaydet(void);


int yilan[2][400],yem[2][2],engel[200][400];
int basix,basiy,kuyrukx,kuyruky,k,tus,salise,saniye,dakika,saat,say1=0,puann,renk;
int ekkuyrukx,ekkuyruky,engelx1,engely1,engelx2,engely2,engelx3,engely3,puan=0,katsayi=1,engel_say,yem_say,yem_say2;
char c='r';
bool hata=false,puan_sarti=false,srt=false,engel_sarti=false;
int satir,sutun,puanlar[5];



 void yilanbaslangic(){

	basix=12;    kuyrukx=11;
	basiy=10;    kuyruky=10;

  yilan[0][0]=basix;    
  yilan[1][0]=basiy;     
  yilan[0][1]=kuyrukx;
  yilan[1][1]=kuyruky;

  k=1;

 yilangoruntule();   
 return;


}

void yilangoruntule(){

	for(int i=0; i<=k;i++){              
	                                    
		for(int j=0; j<=0; j++){
		  
			
			if(yilan[j][i]!=0 && yilan[j+1][i]!=0){
			
			     COORD koordinat;
				 koordinat.X=yilan[j][i];
				 koordinat.Y=yilan[j+1][i];
			
				 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),koordinat);
				printf("%c",176);
			
			}
		}
	
	}

   return;

}

void engelgoruntule(){

	COORD xy;                   
	                            
	for(int i=0; i<200;i++)
  {
   for(int j=0;j<400;j++)
   {
      if(engel[i][j]==1)
	  {
	 
	   xy.X=j;
	   xy.Y=i;
			  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
		     printf("%c",4);
	  }
   
   }

}
   
	return;




}

void yilankontrol(){

	switch(c){     
	
	case 'u':             
		if(basiy>0){
			basiy=basiy-1;
			yilan[1][0]=basiy;}
	        break;
	case 'd':
		if(basiy<399){         
			basiy=basiy+1;
			yilan[1][0]=basiy;}
		    break;
	case 'r':
		if(basix<399){    
		   basix=basix+1;
		   yilan[0][0]=basix;}
		   break;
	case 'l':           
		if(basix>0){
		  basix=basix-1;
		  yilan[0][0]=basix;}
	      break;
	}


	return;

}

void yilankuyruksil(){

	ekkuyrukx=yilan[0][k];  ekkuyruky=yilan[1][k];    
	                                                  

	for(int i=k; i>0; i--){                 

		for(int j=1; j>=0; j--){     

				yilan[j][i]=yilan[j][i-1];  
		     
		}
		
	}

return;

}

void ucluengel(){
	                                
    srand((unsigned) time (NULL));  
	
	                                  
	satir=rand()%150+20;          
	sutun=rand()%85+15;
	 
	
	engel[sutun][satir]=1;   
	engel[sutun][satir+1]=1;
	engel[sutun+1][satir+1]=1;

	engelx1=satir; engely1=sutun;   
	engelx2=satir+1;  engely2=sutun;
	engelx3=satir+1;  engely3=sutun+1; 

	



	engelgoruntule();   
	return; 



}

void yemolustur(){
  
	srt=false;

	srand((unsigned)time (NULL));
	
	int m,n;
	int j=0;

     basla:

       n=rand()%100+10;   
	   m=rand()%50+10;
			 yem[0][0]=n;
		     yem[1][0]=m;


		for(int i=0;i<400;i++){   

		
				if((yilan[j][i]==yem[0][0] &&  yilan[j+1][i]==yem[1][0]) || engel[yem[1][0]][yem[0][0]]==1   || (yem[0][0]==2 && yem[1][0]==47)){ 
				    
					srt=true;       
					break;
			}
	   if(srt==true)
		   goto basla;     
		}
	




	yemgoster();   
	return;



}

void yemgoster(){

	int i=0,j=0;
	COORD yemek;
	   
	
	                 
		
			if(yem[j][i]!=0 && yem[j+1][i]!=0){
			   
			
				yemek.X=yem[j][i];
				yemek.Y=yem[j+1][i];

				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),yemek);
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6); 
				
				cout<<"*";
			
			
		
		
		
		}
	
	
	


}

void yilanyemyeme(){
	                  

	if((yem[0][0]==yilan[0][0]) && (yem[1][0]==yilan[1][0])){
	
		    yem[0][0]=0;  yem[1][0]=0;      
	        k=k+1;                         
			yem_say++;      
			yem_say2++;     
			yilankuyrukekle(); puan_topla(); yemolustur(); 
	}


 return;

}

void yilankendinecarpma(){

	for(int i=k;i>=1 ;i--){     
	 
		if((yilan[0][i]==yilan[0][0]) && (yilan[1][i]==yilan[1][0])) 
			
			hata=true;

	       }
	return;
	}

void yilanengelecarpma(){
	 
	
	   
if((yilan[0][0]==engelx1 && yilan[1][0]==engely1)  || (yilan[0][0]==engelx2 && yilan[1][0]==engely2) || (yilan[0][0]==engelx3 && yilan[1][0]==engely3)){
		   
		hata=true;
}


	return;

}

void yilankuyrukekle(){
	       
	

	yilan[0][k]=ekkuyrukx;
	yilan[1][k]=ekkuyruky;


	return;
}

void puan_topla(){
	                                  
	if(yem_say>0 && yem_say<=40)      
		puan=puan + katsayi*10;


	else {                        
		yem_say=1;   
		katsayi++;    
		puan=puan+ katsayi*10;  
		                           
	}

	return;
}

void yem_sayi_kontrol(){
	
	
	if(yem_say2>=0 && yem_say2<20)     

		system("color F4");
			renk=4;

	if(yem_say2>=20 && yem_say2<40){    
		
		        for(int i=0; i<200;i++){
		                                        
		          	for(int j=0; j<400; j++){
			    
			            	if(engel[i][j]==1)
					            engel_say=engel_say+1;
			         }

		         }
		
		                  if(engel_say==0 && yem_say2==20){  
		     
							  ucluengel(); 
						  }
	  
	 system("color F1");  
		renk=1;
	   }
	engel_say=0;
	if(yem_say2>=40){    
	 
		  for(int i=0; i<200;i++){
		                                    
			  for(int j=0; j<400; j++){
			    
			            	if(engel[i][j]==1)
					            engel_say=engel_say+1;
			         }

		         }
		
		                  if(engel_say==3 && yem_say2==40){   
		     
							  ucluengel(); 
						  }
		
	   system("color F2");  
	    renk=2;
	}

	return;


}

void suregoster(){
	
	   

		 if(salise==20)
		 {
		   saniye++;    
		   salise=0;
		 }

		 if(saniye==60) {
		                    
			 dakika++;
			 saniye=0; 
		 }
	
		 if (dakika==60) {
		                    
			 saat++;
			 dakika=0;		 
		 }
		 COORD sure;
		 sure.X=2;      
		 sure.Y=47;
		 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),sure);	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		 
	     cout<<saat<<":"<<dakika<<":"<<saniye<<":"<<salise;
	     salise++;
	 
	


	return;




}

void puan_yaz(){


	cout<<"Oyunda almış olduğunuz puan **==>>"<<" " <<puan<<endl;
	cout<<"Oyunu "<<" " <<salise<<"salise "<<saniye<<"saniye  "<<dakika<<"dakika  "<<saat<<"saatte bitirdiniz...."<<endl;


}

void yilan_disari_cikma(){

	

	if(yilan[0][0]==400  ||  yilan[1][0]==400 || yilan[1][0]==0 || yilan[0][0]==0)
		hata=true;



}

void puan_okuma(){
	 
	

	FILE *dosya;

	if((dosya=fopen("puanlar.txt","a+"))==NULL)
	
		cout<<"dosya okunamadı";
	else {
	   int 	i=0;
		while(!feof(dosya)){
		       if(i<5){
				   fscanf(dosya,"%d\t",&puann);   
				   puanlar[i]=puann;}
		        i++;
		}
	
	
	}
	  

	return;

}

void puan_sirala(){
	
	


	int gecici;

	for(int i=0; i<5;i++){    
	  
		for(int j=i+1; j<5;j++){
		   
			if(puanlar[i]<puanlar[j]){
			
			     gecici=puanlar[i];
				puanlar[i]=puanlar[j];
				puanlar[j]=gecici;
			}
		        
		}

	}


	for(int k= 0; k<5;k++){

		if(puan==puanlar[k])   
			goto gec;

		if(puan>puanlar[k] ){
		
			for(int m=4; m>=k+1; m--){
			
			   
				   puanlar[m]=puanlar[m-1];
			
			}

		puanlar[k]=puan;  puan_sarti=true; 
		}
		
		if(puan_sarti==true)
			break;

	}

	gec:
	return;

}

void puan_kaydet(){

	

	FILE *puan_kaydt;

	if((puan_kaydt=fopen("puanlar.txt","w+"))==NULL)
		    cout<<"Puan kaydedilmesinde hata oluştu"<<endl;
	
	
	else {
	        int i=0;
		while(!feof(puan_kaydt)){
		     if(i<5){
				 fprintf(puan_kaydt,"%d\t",puanlar[i]);}
		       i++;	
		}	
	
	}
   return;
}


int _tmain(int argc, _TCHAR* argv[])
{

	setlocale(0,"tr");    
	system("color F4");
	srand((unsigned) time(NULL));
	yilanbaslangic();
 
	yemolustur();    
	

	while(!hata){      
	   
		

		yem_sayi_kontrol();   
		engelgoruntule();   
		suregoster();      
		yemgoster();      

		if(GetKeyState(VK_UP)<0){    
		    
			if(c!='d')   
				c='u';     
		}
		else if(GetKeyState(VK_DOWN)<0){   

			if(c!='u')    
				c='d'; 
		}
		else if(GetKeyState(VK_RIGHT)<0){   
		  
			if(c!='l')     
				c='r'; 
		}
		else if(GetKeyState(VK_LEFT)<0){   
		   
			if(c!='r')     
				c='l'; 
		
		}	
		
		yilankuyruksil(); yilankontrol();	
		
		yilankendinecarpma();    yilanengelecarpma();  
		yilan_disari_cikma();    
		yilanyemyeme();  

		system("cls");   yilangoruntule(); Sleep(18);  
	    
	}
	  

	system("cls");   
	system("color F4");
	puan_yaz();   
	puan_okuma();  
	puan_sirala();
	puan_kaydet();
	


	cin.get();


	return 0;
}

