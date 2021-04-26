#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include<unistd.h>
using namespace std;
int width {72};
int height {40};
int x {15},y{40};
int i{0},j{0};
int xbullet {0}, ybullet {0};
bool istrue {false},istrue1{false},istrue2{false};
int superbullet{30};
int myi,myj;
int health{100},score{0};
int xinvader,yinvader;
int movebull;
vector<vector<int>>bulletcord{};
vector<vector<int>>superbulletcord{};
vector<vector<int>>invader{};

void randominvaders(){

    int inv_num=(rand()%16)+3;
    for(int i=0;i<inv_num;i++){
        xinvader=(rand()%(width-2))+1;
        yinvader=(rand()%5)+2;
    invader.push_back({xinvader,yinvader,4});
        
    
    }
   // if(inv_num<invader.size()){
        //clear() clear all elements of avector but erase(i) clear a spesific element
        
      //  }
    
    
    }
bool all_dead(){
    for(int i{0};i<invader.size();i++){
        if(invader[i][1]<40){
            return false;
            }
        
        }
        
    return true;
    
    
    }
bool generateinvaders(){
    for(int i=0;i<bulletcord.size();i++){
        for(int j=0;j<invader.size();j++){
        if((bulletcord[i][0]==invader[j][0])&&(bulletcord[i][1]==invader[j][1])){
            score++;
        invader[j][2]--;
        break;
        }
            }
        
        }

    for(int i=0;i<superbulletcord.size();i++){
        for(int j=0;j<invader.size();j++){
        if((superbulletcord[i][0]==invader[j][0])&&(superbulletcord[i][1]==invader[j][1])){
            score++;
        invader[j][2]--;
        break;
        }
            }
        
        }

    
        
        

        
    for(int in{0} ;in<invader.size();in++){
                    if(invader[in][0]==myj&&invader[in][1]==myi){
                        if(invader[in][2]>0)
                            return true;
                        }
    }
    return false;
    }
bool damage(){
        if(health<=0)
            return false;
        else{
        for(int j=0;j<invader.size();j++){
            if(y==invader[j][1]&&x==invader[j][0])
                health--;                
                
            /**else if(y-2==invader[j][1]&&x==invader[j][0])
                health--;
                
            else if(y-1==invader[j][1]&&x==invader[j][0])
                health--;**/
            else if(y==invader[j][1]&&x+1==invader[j][0])
                health--;
            else if(y==invader[j][1]&&x-1==invader[j][0])
                health--;
        }
        return true;
        }
        }
        
        
        
void space(){
    //int xbullet {x}, ybullet {y-3};
    
    system("cls");
    cout<<score<<endl;
    cout<<superbullet<<endl;
    
    for(int i=1;i<=width;i++){
        cout<<"-";
        }
    for(int i=1;i<=height;i++){
       
        cout<<endl;
        cout<<"|";
        for(int j=1;j<=width-2;j++){
             myi=i;
             myj=j;
            istrue=true;
            istrue2=all_dead();
            if(all_dead()){
            invader.clear();
               randominvaders();
            }
            istrue1=generateinvaders();
            if(y==i&&x==j){
             if(istrue)   
                cout<<"*";
            else
                cout<<" ";
                }
            
            else if(y-2==i&&x==j){
            if(istrue)
                cout<<"*";
            else
                cout<<" ";
                }
            else if(y-1==i&&x==j){
            if(istrue)
                cout<<"*";
            else
                cout<<" ";
                }
                
            else if(y==i&&x-1==j){
            if(istrue)
                cout<<"*";
            else
                cout<<" ";
                }
            else if(y==i&&x+1==j){
            if(istrue)
                cout<<"*";
            else
                cout<<" ";
                }
            
           else if(istrue1){
                int c ;
                c=0;
                for(int in{0};in<invader.size();in++){
                    if(invader[in][0]==j&&invader[in][1]==i){
                        cout<<"8";
                        }
                    else{
                        c++;
                        if(c==invader.size())
                            cout<<" ";
                        }
                    
                    }
                
                }        
            else if(bulletcord.size()>0||superbulletcord.size()>0){
            
                int c,d;
                c=0;
                d=0;
                
                if(bulletcord.size()>0){
                for(int k{0};k<bulletcord.size();k++){
                    
                    
                 xbullet=bulletcord[k][0];
                 ybullet=bulletcord[k][1];
                    if(xbullet==j&&ybullet==i)
                        cout<<"+";
                    else
                       c++;
                }
                }
                if(c==bulletcord.size()){
                if(superbulletcord.size()>0){
                            for(int s{0};s<superbulletcord.size();s++){
                                  xbullet=superbulletcord[s][0];
                                  ybullet=superbulletcord[s][1];
                                 if(xbullet==j&&ybullet==i)
                                     cout<<"^";
                                 else
                                     d++;
                            }
                }}
                if(c==bulletcord.size()&& d==superbulletcord.size())          
                    cout<<" ";
                            }
         
              else
                  cout<<" ";
        }
             cout<<"|";
             }

    cout<<endl;
    for(int i=1;i<=width;i++){
        cout<<"-";}
}
    
void move(){
    for(int b{0};b<bulletcord.size();b++){
     bulletcord[b][1]=bulletcord[b][1]-1;  
    } 
    for(int b{0};b<superbulletcord.size();b++){
     superbulletcord[b][1]=superbulletcord[b][1]-3;  
    }
    for(int b{0};b<invader.size();b++){
     
     invader[b][1]=invader[b][1]+1;  
    }                      
    if(_kbhit()){
        switch(_getch()){
    case('w'):
       if(y>=4){
            y--;
        }
    
     break;
    case('s'):
        if(y<=39){
            y++;
        }
    
    break;
   case('a'):
        if(x>=3){
            x--;
        }
    
    break;
   case('d'):
        if(x<=width-4){
            x++;
        }
    
    break;
   case('l'):
       bulletcord.push_back({x,y-3});
   break;
   case('o'):
       if(superbulletcord.size()<31){
       superbulletcord.push_back({x,y-3});}
    break;   
    }}
       
    
    
    }

int main(){
    int onlyone{0};
while(true){

 space(); 
 move();
 if(onlyone==0)
     sleep(3);
onlyone=1;
 }

    
}