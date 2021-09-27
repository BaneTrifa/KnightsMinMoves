			 ---------------------
         Knights Min Moves
       ---------------------


y-Osa	
A			
|
|
|
| 

8| | | | | | | | |
-+-+-+-+-+-+-+-+-|
7| | | | | | | | |          
-+-+-+-+-+-+-+-+-|	    
6| | | | | | | | |	    
-+-+-+-+-+-+-+-+-|
5| | | | | | | | |
-+-+-+-+-+-+-+-+-|
4| | | | | | | | |		TABLA 8x8		
-+-+-+-+-+-+-+-+-|
3| | | | | | | | |
-+-+-+-+-+-+-+-+-|
2| | | | | | | | |              
-+-+-+-+-+-+-+-+-|
1| | | | | | | | |
-+-+-+-+-+-+-+-+-|
 |1|2|3|4|5|6|7|8|       ---------------------> x-Osa



-Program koji na osnovu unetih polazinh i krajnjih koordinata konja odredjuju minimalan broj koraka
koji je potreban da stignete od polaznog polja do krajnjeg polja i ispisuje svaki polje preko kog je konj presao (putanju)

-Validne koordinate su x<=8, x>0, y<=8, y>0

PRIMER:

	Input:  
    Unesite x-koordinatu pocetnog polja konja:1 
		Unesite y-koordinatu pocetnog polja konja:4

		Unesite x-koordinatu krajnjeg polja konja:5 
		Unesite y-koordinatu krajnjeg polja konja:8
	

	Output:
		Minimalan broj poteza: 4
		
		Putanja:
		[1,4]   ---> pocetno polje
		[2,2]
		[3,4]
		[4,6]
		[5,8] 	---> krajnje polje


8| | | | |K| | | |
-+-+-+-+-+-+-+-+-|
7| | | | | | | | |          
-+-+-+-+-+-+-+-+-|	    
6| | | |X| | | | |	    
-+-+-+-+-+-+-+-+-|
5| | | | | | | | |		P - pocetna pozicija konja
-+-+-+-+-+-+-+-+-|		K - krajnja pozicija konja
4|P| |X| | | | | |		X - polja preko kojih je konj stigao do krajnje pozicije
-+-+-+-+-+-+-+-+-|
3| | | | | | | | |
-+-+-+-+-+-+-+-+-|
2| |X| | | | | | |              
-+-+-+-+-+-+-+-+-|
1| | | | | | | | |
-+-+-+-+-+-+-+-+-|
 |1|2|3|4|5|6|7|8|

