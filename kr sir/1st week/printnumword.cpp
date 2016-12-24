#include <iostream>
int k;
using namespace std;
void printd(int n,int a)
{
  if(n<10 )
{
if(a==4){
switch(n)
{case 0: break;
case 1:cout<<"one thousand ";break;
case 2:cout<<"two thousand ";break;
case 3:cout<<"three thousand ";break;
case 4:cout<<"four thousand ";break;
case 5:cout<<"five thousand ";break;
case 6:cout<<"six thousand ";break;
case 7:cout<<"seven thousand ";break;
case 8:cout<<"eight thousand ";break;
case 9:cout<<"nine thousand ";break;
}}
 if(a==3)
	   {
	   switch(n%10)
	       {
	       	case 1:cout<<"one hundred ";break;
             case 2:cout<<"two  hundred ";break;
              case 3:cout<<"three  hundred ";break;
               case 4:cout<<"four  hundred ";break;
                 case 5:cout<<"five  hundred ";break;
                    case 6:cout<<"six  hundred ";break;
                      case 7:cout<<"seven  hundred ";break;
                        case 8:cout<<"eight  hundred ";break;
                          case 9:cout<<"nine  hundred ";break;
		   }
	   }
	  if(a==2)	
	   {
	    switch(n%10)
	      {case 0: break;
		  case 1:
	      	      
					if(k%10!=0)
	      	      { switch(k%10)
	      	                 {case 1:cout<<"eleven ";break;
             case 2:cout<<"twelve  ";break;
              case 3:cout<<"thirteen ";break;
               case 4:cout<<"fourteen ";break;
                 case 5:cout<<"fifteen ";break;
                    case 6:cout<<"sixteen ";break;
                      case 7:cout<<"seventeen ";break;
                        case 8:cout<<"eighteen ";break;
                          case 9:cout<<"ninteen ";break;
	      	                 }
	      	      	
				  }
				  else cout<<"ten";
				  break;
				  case 2:cout<<"twenty  ";break;
              case 3:cout<<"thirty ";break;
               case 4:cout<<"fourty ";break;
                 case 5:cout<<"fifty ";break;
                    case 6:cout<<"sixty ";break;
                      case 7:cout<<"seventy ";break;
                        case 8:cout<<"eighty ";break;
                          case 9:cout<<"ninty ";break;}
				  
	   	 
	   }
	   if(a==1)
	      {
	      	switch(n%10)
	      	   {  case 0: break;
	      	       case 1: break;
	      	   	   case 2:cout<<"two   ";break;
                    case 3:cout<<"three  ";break;
                     case 4:cout<<"four  ";break;
                      case 5:cout<<"five  ";break;
                       case 6:cout<<"six  ";break;
                        case 7:cout<<"seven  ";break;
                         case 8:cout<<"eight  ";break;
                          case 9:cout<<"nine ";break;
				 }
	      	
}}
else {
	printd(n/10,a+1);
	
	 int p=n%10;
	    switch(a)
	    { case 3:
		
	   switch(p)
	       {case 0:break;
	       	case 1:cout<<"one hundred ";break;
             case 2:cout<<"two  hundred ";break;
              case 3:cout<<"three  hundred ";break;
               case 4:cout<<"four  hundred ";break;
                 case 5:cout<<"five  hundred ";break;
                    case 6:cout<<"six  hundred ";break;
                      case 7:cout<<"seven  hundred ";break;
                        case 8:cout<<"eight  hundred ";break;
                          case 9:cout<<"nine  hundred ";break;
		   }
	   ;break;
	  case 2:
	    switch(p)
	      {case 0: break;
		  case 1:
	      	      
					if(k%10!=0)
	      	      { switch(k%10)
	      	                 {case 1:cout<<"eleven ";break;
             case 2:cout<<"twelve  ";break;
              case 3:cout<<"thirteen ";break;
               case 4:cout<<"fourteen ";break;
                 case 5:cout<<"fifteen ";break;
                    case 6:cout<<"sixteen ";break;
                      case 7:cout<<"seventeen ";break;
                        case 8:cout<<"eighteen ";break;
                          case 9:cout<<"ninteen ";break;
	      	                 }
	      	      	
				  }
				  else cout<<"ten";
				  break;
				  case 2:cout<<"twenty  ";break;
              case 3:cout<<"thirty ";break;
               case 4:cout<<"fourty ";break;
                 case 5:cout<<"fifty ";break;
                    case 6:cout<<"sixty ";break;
                      case 7:cout<<"seventy ";break;
                        case 8:cout<<"eighty ";break;
                          case 9:cout<<"ninty ";break;}break;
				  
	   	 
	   
	   
	   case 1:
	      	switch(p)
	      	   {  case 0: break;
	      	       case 1: break;
	      	   	   case 2:cout<<"two   ";break;
                    case 3:cout<<"three  ";break;
                     case 4:cout<<"four  ";break;
                      case 5:cout<<"five  ";break;
                       case 6:cout<<"six  ";break;
                        case 7:cout<<"seven  ";break;
                         case 8:cout<<"eight  ";break;
                          case 9:cout<<"nine ";break;
				 };break;
				 case 0: break;
	      	
		  }
	}

	
}


int main()
{int n,a=0;
cout<<"enter the number";
cin>>n;k=n;
while(n!=0)
{n=n/10;
a++;
}
printd(k,1);
return 0;
	
	
	
}

