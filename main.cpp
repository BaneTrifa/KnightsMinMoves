#include <iostream>
#include <vector>

using namespace std;

class Polje {
public:
    int xKoordinata, yKoordinata, distanca; // distanca je distanca od pocetnog polja
    Polje* prethodno;

    Polje(int x, int y, int dis, Polje* pret) {
        xKoordinata = x;
        yKoordinata = y;
        distanca = dis;
        prethodno = pret;
    }


};

char tabla[17][18] = { {'8', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'}, //18x17
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'7', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'6', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'5', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'4', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'3', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'2', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {'1', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|'},
                       {'-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '-', '+', '-', '+', '-', '+', '-', '|'},
                       {' ', '|', '1', '|', '2', '|', '3', '|', '4', '|', '5', '|', '6', '|', '7', '|', '8', '|'}   };


///METODE///
void IspisiTablu();
bool uGraniciTable(int x, int y); // metod koji proveravara da li je polje izlazi iz okvira table, vraca true ako ne izlazi
Polje* NadjiMinimum(int pocetnaPozicija[2], int krajnjaPozicija[2]); //metoda koja nam vraca adresu krajnjeg polja, distancu od pocetnog polja i sve prethodne poteze
void OznaciPolje(int x, int y, char oznaka); // sluzi kako bi na odredjeno polje stavili odrdjeni znak
////////////

int main() {
    int pocetnaPozicija[2]; // pocetne koordinate konja
    int krajnjaPozicija[2]; // koordinate polja na koje konj treba da dodje

    IspisiTablu();

    cout << "\nUnesite x-koordinatu pocetnog polja konja: "; cin >> pocetnaPozicija[0];
    cout << "Unesite y-koordinatu pocetnog polja konja: "; cin >> pocetnaPozicija[1];

    if( !uGraniciTable(pocetnaPozicija[0],pocetnaPozicija[1]) ) { //Proveravamo da li su unete pocetne koordinate validne
        cout << "Uneli ste koordinate koje su nevalidne!!!";
        exit(0);
    }

    cout << "\nUnesite x-koordinatu krajnjeg polja konja: "; cin >> krajnjaPozicija[0];
    cout << "Unesite y-koordinatu krajnjeg polja konja: "; cin >> krajnjaPozicija[1];

    if( !uGraniciTable(krajnjaPozicija[0],krajnjaPozicija[1]) ) { //Proveravamo da li su unete krajnje koordinate validne
        cout << "Uneli ste koordinate koje su nevalidne!!!";
        exit(0);
    }


    Polje* minimalan = NadjiMinimum(pocetnaPozicija,krajnjaPozicija); //trazimo najkraci put i vracamo adresu krajnjeg(trazenog) polja

    system("cls");

    cout << "Minimalan broj poteza je: " << minimalan->distanca << endl;

    vector<Polje*> potezi;
    while(minimalan->prethodno != NULL) { //Posto svako polje sadrzi adresu prethodnog polja,
        potezi.push_back(minimalan);      //u vector smestamo polja od poslednjeg(krajnjeg)
        minimalan = minimalan->prethodno; //ka prvom(pocetnom) odnosno dobijamo u vector-u potezi putanju kretanja konja
    }

    //Ispisujemo celu putanju konja (od pocetnog polja do krajnjeg)
    cout << "\nPutanja: " << endl;
    cout << "[" << pocetnaPozicija[0] << "," << pocetnaPozicija[1] << "]" << endl; //Ispisemo koordinate prvog(pocetnog) polja

    while(!potezi.empty()) { //ispisujemo koordinate svih polja koja se nalaze u vector<Polje*>potezi  pocev od zadnjeg
        cout << "[" << potezi.back()->xKoordinata << "," << potezi.back()->yKoordinata << "]" << endl; //ispisemo koordinate zadnjeg
        OznaciPolje(potezi.back()->xKoordinata,potezi.back()->yKoordinata,'X'); //svako polje preko kojeg je konj presao oznacavamo sa 'X'
        potezi.pop_back();
    }

    potezi.clear();

    OznaciPolje(pocetnaPozicija[0],pocetnaPozicija[1],'P'); // Oznacavamo pocetno polje
    OznaciPolje(krajnjaPozicija[0],krajnjaPozicija[1],'K'); // Oznacavamo krajnje polje

    cout << "\n";
    IspisiTablu();
    cout << "\nP - pocetna pozicija konja" << endl;
    cout << "K - krajnja pozicija konja" << endl;
    cout << "X - polja preko kojih je konj stigao do krajnje pozicije" << endl;

    return 0;
}

Polje* NadjiMinimum(int pocetnaPozicija[2], int krajnjaPozicija[2]) {
    int xOsa[] = {-2,-1,1,2,-2,-1,1,2};
    int yOsa[] = {-1,-2,-2,-1,1,2,2,1};

    vector<Polje*> mogucePozicije; //sva polja na koja konj moze da ide
    mogucePozicije.push_back(new Polje(pocetnaPozicija[0], pocetnaPozicija[1],0,NULL));

    bool posecenaPolja[9][9]; // polja na kojima je konj vec bio

    for(int i=1;i<9;i++) { //inicijalizujemo sva polja kao neposecena
        for(int j=1;j<9;j++) {
                posecenaPolja[i][j] = false;
        }
    }

    posecenaPolja[pocetnaPozicija[0]][pocetnaPozicija[1]] = true; // startno polje oznacavamo kao poseceno

    Polje* trenutni;
    int x,y;
    while(!mogucePozicije.empty()) {
           trenutni = mogucePozicije.front();
           mogucePozicije.erase(mogucePozicije.begin());


           if(trenutni->xKoordinata == krajnjaPozicija[0] && trenutni->yKoordinata == krajnjaPozicija[1]) { //proveravamo da li smo dosli na ciljano polje
				return trenutni;
				mogucePozicije.clear(); //brisemo vektor
			}

            for(int i=0;i<8;i++) {
                x = trenutni->xKoordinata + xOsa[i];
                y = trenutni->yKoordinata + yOsa[i];

                if(uGraniciTable(x,y) && !posecenaPolja[x][y] ) {
                    posecenaPolja[x][y] = true;
                    mogucePozicije.push_back(new Polje(x,y,trenutni->distanca+1,trenutni));
                }
            }

    }

    return NULL;
}

void IspisiTablu() {
    for(int i=0;i<17;i++) {
        for(int j=0;j<18;j++) {
            cout << tabla[i][j];
        }
        cout << "\n";
    }
}

bool uGraniciTable(int x, int y) {
    if(x<=8 && x>0 && y<=8 && y>0) return true;

    return false;
}

void OznaciPolje(int x, int y, char oznaka) {

    switch(y) {
        case 1:
            y = 14;
            break;
        case 2:
            y = 12;
            break;
        case 3:
            y = 10;
            break;
        case 4:
            y = 8;
            break;
        case 5:
            y = 6;
            break;
        case 6:
            y = 4;
            break;
        case 7:
            y = 2;
            break;
        case 8:
            y = 0;
            break;
    }

    tabla[y][x*2] = oznaka;
}
