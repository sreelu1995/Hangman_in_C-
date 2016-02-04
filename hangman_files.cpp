#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

inline void type_of_word(char f);


int main()
{   char c,h,ch,ch1,ch2;
    char word[25];
    char word2[25];

    int l,i,ng,n,k,x;

do{
    do{
        c=' ';
        cout<<"ntt    *********** HANGMAN IN C++ ***********nn";

        cout<<"(E) Enter a wordnn(C) Computer chooses wordnn(A)" ;
        cout<<"Add new word to listnn(Q) QuitnnnEnter your choice (E - C - Q): ";
        cin>>ch2;
       }while (ch2!='C' && ch2!='c' && ch2!='E' && ch2!= 'e' &&
                ch2!='Q' && ch2!= 'q'&& ch2!='A' && ch2!= 'a');
    if (ch2 == 'Q' || ch2=='q')  exit (0);

    if (ch2 == 'C' || ch2=='c')

    {
        ifstream fin("hangword.txt");
        if(!fin) {
        cout<<"File missing, aborting.nnYou are missing a file of name" ;
        cout<<"**hangword.txt**nnLocate it, then place it next to the" ;
        "program file.nn"; system("pause"); return 0;}
        for (i=0;!fin.eof();i++)   fin.getline(word,25);
        fin.close();

        do {
        x=rand();
        }while(x>i || x<0);

        ifstream finn("hangword.txt");
        for (i=0;!finn.eof();i++)
        {finn>>c; finn.getline(word,25); if (x==i) break;}
        finn.close();
    }

  if (ch2 == 'A' || ch2=='a')

    {
        ofstream fout("hangword.txt",ios::app);
        if(!fout) {//clrscr();
        cout<<"File missing, aborting.nnYou are missing a file of name"
        " **hangword.txt**nnLocate it, then place it next to the program"
        " file.nn"; system("pause"); return 0;}
        cin.get();
        cout<<"Choose the topic of your wordnn(M) Movienn(A) Animalnn(P)"
        " Sportnn(S) SongnnEnter your choice (A-P-S-M) : ";
        cin>>h;
        cin.get();
        //clrscr();
        cout<<"nnThe word should not exceed 25 lettersnnEnter the word : ";
        cin.getline(word,25);
        fout<<h<<word<<endl;
        fout.close();

    }


   if (ch2 == 'E' || ch2=='e')
     {// clrscr();
       cin.get();
       cout<<"ttt Type the word :  ";
       cin.getline (word, 25);
     }
 if (ch2 == 'E' || ch2=='e' || ch2 == 'C' || ch2=='c')
{
l=strlen(word);
char choosen[25]="";
n=0;k=0;

 for(i=0;i<=24;i++)
   {
    if (word[i]==' ') {word2[i]=' ';break;}
    if (word[i]==' ')  {word2[i]=' ';  n++;}
    if (word[i]!=' ')  word2[i]='-';
   }
ng=l+2-n;     //only 2 guesses extra
   do{
   there:  type_of_word(c);
     if (k!=0)  cout<<"nntttChoosen letters : "<<choosen<<"n";
     cout<<"nnnttt      "<<word2<<"nnnYou have "<<ng
     << " guesses left, choose a letter : ";
     cin>>ch; cin.get();
     for (i=0;i<25;i++) if (choosen[i]==ch) {//clrscr();
     cout<<"att     !!You have choosen "<<ch<<" already!!n";goto there;}
     ng--; choosen [k]=ch; choosen [k+1]=',';k+=2;

     for (i=0;i<=24;i++)
     if (word[i]==ch || word[i]==ch+32 || word[i]==ch-32) word2[i]=ch;
     if (strcmp(word2,word)==0) {cout<<"nttt      "<<toupper(word)
     <<"nntttCongratulations  :-()n"; break;}

    }while(ng>0 || !strcmp(word2,word));


if (strcmp(word2,word)!=0)  cout<<"nSorry, maybe next time.nnThe word was : "
<<toupper(word)<<endl;
}

cout<<"nWould you like to play again??? (Y - N) : ";
cin>>ch1;  cin.get();

}while (ch1=='y' || ch1=='Y');
      system("PAUSE");
      return 0;
}

inline void type_of_word(char f)

{    if (f=='m') cout<<"ttttMOVIE";
     if (f=='a') cout<<"ttttANIMAL";
     if (f=='p') cout<<"ttttSPORT";
     if (f=='s') cout<<"ttttSONG";
}
