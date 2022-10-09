#include<iostream>
#include<string.h>
#include<windows.h>
#include <stdio.h>
using namespace std;
// class mer persone 
class persone{
	protected :                            // encabsulation de donné 
string 	nom  ; 
string  prenom  ; 
string adress ; 
int age  ;	
public :
//les getter  de class personne 

string getnom() {                       
	return nom ; 
}
string getprenom() {
	 
	return prenom ;
}
string getadress() {
	 
	return adress ; 
}
int getage() {
	
	return age ;
	}
// les setter de class personne 
void setnom(string str) {
    nom = str;
    }
void setprenom(string str) {
    prenom = str;
    }	
void setadress(string str) {
    adress = str;
    }		
void setage(int str) {
    age = str;
    }
	persone() {
		
	}		
persone(string 	nom,string  prenom,string adress, int age  )	{
	setnom(nom) ;
	setprenom(prenom);
	setadress(adress);
	setage(age) ;
}
 virtual void afficher_information () {     
    // virtual c est a dire en prenne en cosiderationt l 'implimentation dans la classe fille 
	cout << "le nom de personne de compte /n "<< endl ; 
getnom() ; 
	cout << "le prenom de personne de compte /n "<< endl ; 
	getprenom() ;
	cout << "l ' adress' de personne de compte /n "<< endl ; 
	getadress() ; 
	cout << "l'age de personne de compte /n "<< endl ; 
	getage();
}

};

// class client 
class client : public persone {

protected  :
 string matricule ; 
 string agence ; 
 public: 
 //les getter de class client  
	string getmatricule() {                         

	return matricule ; 
}
string getagence() {                         
	return agence ; 
}
// les setter de class client 
void setmatricule(string str) {
    matricule = str;
    }	
void setagence(string str) {
    agence = str;
    }
client() {
}
    
client (string nom , string prenom,string adress, int age , string matricule , string agence  ) : persone (nom, prenom , adress ,age ) {
setmatricule(matricule)	 ;
setagence(agence) ; 
}

void afficher_information () {
	client client  ; 
	cout << "le nom de proprieter de compte /n "<< endl ; 
	client.getnom() ; 
	cout << "le prenom de proprieter de compte /n "<< endl ; 
    client.getprenom() ;
	cout << "l ' adress' de proprieter de compte /n "<< endl ; 
	getadress() ; 
	cout << "l'age de proprieter de compte /n "<< endl ; 
	client.getage();
	cout << "la matricule de proprieter de compte /n "<< endl ; 
	getmatricule() ; 
	cout << "l'agence de proprieter de compte /n "<< endl ; 
	client.getagence() ; 
	
}

	
};


class compte {
protected :
int  n_compte [20]	; 
client  prop[20]  ; 
int somme_totale [20] ; 
int count ; 
public :
	//les getter de class compte 
	int getn_compte(int i ) {                         
	cout<< "le numero de compte est "<< endl ; 
	return n_compte[i] ;
	}
	void setn_compte(int r ,int i )	{
		n_compte[i]=r ; 
	}
	
	 compte(){	
	count=0 ;
	somme_totale [20] = 0  ;
	}

void ouvrir() {
	
	string n , p , ad,m, ag ;
	int a ; 
	cout<< "veuillez entrer votre nom " << endl ; 
	cin>>n;
     prop[count].setnom(n) ; 
	cout<< "veuillez entrer votre prenom " << endl ; 
	cin>>p ; 
	 prop[count].setprenom(p) ;
	cout<< "veuillez entrer votre adress " << endl ; 
	cin>>ad;
	 prop[count].setadress(ad) ; 
	cout<< "veuillez entrer votre age " << endl ; 
	cin>>a ;
	 prop[count].setage(a)  ; 
	cout<< "veuillez entrer votre matricule  " << endl ; 
	 cin>> m ; 
	 prop[count].setmatricule(m)  ;
	cout<< "veuillez entrer votre agence  " << endl ; 
	cin>> ag ; 
	 prop[count].setagence(ag)  ; 
	 count++ ; 
}	
void depot() {
	int montant,i  ; 
	string n ;
	 bool verif= false   ; 
	 int pos= 0;
	string admin_pass = "0000" ;
	string login ; 

	 
	cout << "entrer votre nom " << endl ; 
	cin >> n ;
	cout << "entrer votre mot de passe  " << endl ; 
    cin >> login; 
	
	
	for( i =0 ; i<count ;i++) {
	if ( prop[i].getnom()==n){
		pos=i ; 
		verif=true ;

	}
	}
	
		 if (verif==false) 	{
		cout<< "desoler on trouve pas votre nom " << endl ; 
		 }
		 
	
         if (admin_pass!= login)  {
        cout << "le mots de pass est incorrect " << endl ; 
		 }
         
			 
		if(verif==true&& (admin_pass== login)){
			do {
				cout <<"veuillez saisir la montant a deposer en TND :  " << endl ; 
	            cin >> montant ;
			}while (montant<0) ; 
	
	somme_totale[pos]+=montant ; 
		}
	 
	

	
}
void consulter () {
	int i ; 
	string n ;
	bool verif= false ;
	int pos=0 ; 
	string admin_pass = "0000";
	string login ; 
	
	cout << "veuillez donner votre nom " << endl ; 
	cin >> n ; 
	cout << "entrer votre mot de passe  " << endl ; 
    cin >> login; 
	for( i =0 ; i<count ;i++) {
	if (prop[i].getnom()==n){
		pos=i ; 
		verif=true ;
	}
	}
		 if (verif==false)	
		cout<< "desoler on trouve pas votre nom " << endl ; 
		  if (admin_pass!= login)  {
        cout << "le mots de pass est incorrect " << endl ; 
		 } 
		 if(verif==true&& (admin_pass== login)){
	    cout << "votre montant totale en TND est "	<< somme_totale[pos] << endl ; 
	    }

}
void retrait () {
	int m ; int i ; 
	string n ;
	bool verif= false ;
	int pos=0 ;
	string admin_pass = "0000";
	string login ; 
	
	cout << "veuillez donner votre nom " << endl ; 
	cin >> n ; 
	cout << "entrer votre mot de passe  " << endl ; 
    cin >> login; 
		for( i =0 ; i<count ;i++) {
	if (prop[i].getnom()==n){
		pos=i ; 
		verif=true ;
	}
	}
	
		 if (verif==false)	
		cout<< "desoler on trouve pas votre nom " << endl ;  
		 
		if (admin_pass!= login)  {
        cout << "le mots de pass est incorrect " << endl ; 
		 } 
	
if(verif==true&& (admin_pass== login)) {
	do {
	cout <<"veuillez saisir la montant a retirer en TND :  " << endl ; 
	cin >> m ; 
	}while(m<0) ;

	somme_totale[pos]-=m 	;
	}	

}

void affiche_tout() {
    int i ; 
	string n ;
	bool verif= false ;
	int pos=0 ;
	string admin_pass = "0000";
	string login ;
cout <<	"entrer le nom svp " << endl ; 
cin >>n ; 
cout << "entrer votre mot de passe  " << endl ; 
    cin >> login;

	for( i =0 ; i<count ;i++) {
	if (prop[i].getnom()==n){
		pos=i ; 
		verif=true ;
	}
	}
	
		 if (verif==false)	
		cout<< "desoler on trouve pas votre nom " << endl ;  
			if (admin_pass!= login)  {
        cout << "le mots de pass est incorrect " << endl ; 
		 } 
	if(verif==true&& (admin_pass== login)){
	cout <<"ci_joint vos coordonne"	<< endl ;
	cout<<prop[pos].getnom() <<endl ; 
	cout <<prop[pos].getprenom() << endl ;  
	cout << prop[pos].getage() <<endl ; 
	cout<< prop[pos].getadress()<<endl;
	cout<< prop[pos].getmatricule() << endl ; 
	 cout<< prop[pos].getmatricule() << endl ;	
	}
	

	
	
	

	
	
}

void menu () {
	int choix ; 
	cout << "************  Projet de systeme de gestion bancaire  ************  \n " << endl ; 
cout <<"si vous voulez ouvrir un copmte chez nous tapez 1 " << endl ; 
cout <<"si vous voulez deposez   une montant   tapez 2 " << endl ;
cout <<"si vous voulez consultez  copmte  tapez 3 " << endl ;
cout <<"si vous voulez retirez d argent de  copmte  tapez 4 " << endl ; 
cout <<"si vous voulez voire  les information   copmte  tapez 5 \n  " << endl ; 
cout <<" ************                                          ************ \n" << endl ; 
cin>> choix ;
switch (choix) {
	case 1 : ouvrir() ; menu () ; 
	case 2 : depot() ;  menu () ; 
	
	case 3 : consulter () ;  menu () ;
	case 4 : retrait () ; menu () ;
	case 5 : affiche_tout();  menu () ;  
	default : cout << "votre choix est invalid " << endl ;  break ; 
	
}
 	
}

friend class client ; 
	

};




int main() {
	 
 char arrshow[]={'B','I','N','E','V','E','N','U'};
	cout<<"\n\n\n\n\n\n\t\t\t";
	for(int i=0;i<8;i++)
	{
		cout<<arrshow[i];
		Sleep(200);
		
	}
	system("CLS");


compte c1 ; 
c1.menu();

 






return 1 ; 
}
